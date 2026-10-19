#!/usr/bin/env python3
import hashlib, os, struct, subprocess, sys, tarfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC = os.path.join(ROOT, "firmware/extracted/ax_202609051445")
DST = os.path.join(ROOT, "firmware/modified/ax_202609051445_hook")
SHIM_C = os.path.join(ROOT, "shim/altscreen.c")
SHIM_SO = "libSdH.so"
LIBS = ["libSdAuto.so", "libSdCommon.so", "libSdSampleRate.so", "libSdUtils.so"]

BAL_VA, BAL_OLD, BAL_NEW = 0x46c2fc, 0x04112f35, 0x0320f809

ALTSCREEN_PATCHES = [
    (0x43e4a4, 0x12000005, 0x10000005, "nostrip: keep all displays in /info"),
    (0x43f46c, 0x1040fdaf, 0x00000000, "enabledFeatures: always create array"),
    (0x43f4d0, 0x1040001a, 0x00000000, "enabledFeatures: always append viewAreas"),
    (0x43f540, 0x10400008, 0x00000000, "enabledFeatures: always take cornerMasks slot"),
    (0x43f558, 0x24a53398, 0x24a5f364, "cornerMasks slot -> altScreen CFL"),
]

def build_shim(out):
    subprocess.run([
        "zig", "cc", "-target", "mipsel-linux-gnueabihf.2.17", "-mcpu=mips32r2",
        "-shared", "-fPIC", "-Os", "-nostdlib", "-Wl,-soname," + SHIM_SO,
        "-o", out, SHIM_C, "-lc", "-lpthread",
    ], check=True)

def elf_sections(d):
    shoff = struct.unpack_from("<I", d, 0x20)[0]
    she, shn, shstr = struct.unpack_from("<HHH", d, 0x2e)
    base = struct.unpack_from("<IIIIII", d, shoff + shstr * she)[4]
    out = {}
    for i in range(shn):
        nm, ty, fl, ad, off, sz = struct.unpack_from("<IIIIII", d, shoff + i * she)
        name = d[base + nm:d.index(b"\0", base + nm)].decode()
        out[name] = (ad, off, sz)
    return out

def va2off(d, va):
    phoff = struct.unpack_from("<I", d, 0x1c)[0]
    n = struct.unpack_from("<H", d, 0x2c)[0]
    for i in range(n):
        t, o, vb, pa, fs, ms, fl, al = struct.unpack_from("<8I", d, phoff + i * 32)
        if t == 1 and vb <= va < vb + fs:
            return o + (va - vb)
    raise SystemExit("va2off failed %x" % va)

def dyn_offsets(d):
    phoff = struct.unpack_from("<I", d, 0x1c)[0]
    n = struct.unpack_from("<H", d, 0x2c)[0]
    for i in range(n):
        t, o, va, pa, fs, ms, fl, al = struct.unpack_from("<8I", d, phoff + i * 32)
        if t == 2:
            return o, fs
    raise SystemExit("no PT_DYNAMIC")

def find_zero_gap(d, secs, need):
    ad, off, sz = secs[".rodata"]
    run = 0
    start = 0
    for i in range(sz):
        if d[off + i] == 0:
            if run == 0:
                start = i
            run += 1
            if run >= need + 4:
                gva = ad + start + 2
                return gva, off + (gva - ad)
        else:
            run = 0
    raise SystemExit("no zero gap in .rodata")

def patch_sddongle(src, dst):
    d = bytearray(open(src, "rb").read())
    o = BAL_VA - 0x400000
    cur = struct.unpack_from("<I", d, o)[0]
    if cur == BAL_NEW:
        print("bal already patched")
    elif cur == BAL_OLD:
        struct.pack_into("<I", d, o, BAL_NEW)
        print("patched bal->jalr t9 @%#x" % BAL_VA)
    else:
        raise SystemExit("unexpected word @%#x: %#x" % (BAL_VA, cur))

    for va, old, new, what in ALTSCREEN_PATCHES:
        po = va - 0x400000
        w = struct.unpack_from("<I", d, po)[0]
        if w == new:
            print("already patched @%#x (%s)" % (va, what))
        elif w == old:
            struct.pack_into("<I", d, po, new)
            print("patched @%#x %#010x->%#010x (%s)" % (va, old, new, what))
        else:
            raise SystemExit("unexpected word @%#x: %#x (%s)" % (va, w, what))
    cfl = bytes(d[0x11f364:0x11f364 + 18])
    if cfl != b"\x56\x07\x01\x00\xff\xff\xff\x7faltScreen\x00":
        raise SystemExit("altScreen CFL not at file 0x11f364: %r" % cfl)

    secs = elf_sections(d)
    dynstr_va = secs[".dynstr"][0]
    s = b"libSdH.so\x00$ORIGIN\x00"
    gva, goff = find_zero_gap(d, secs, len(s))
    d[goff:goff + len(s)] = s
    off_needed = gva - dynstr_va
    off_runpath = (gva + len(b"libSdH.so\x00")) - dynstr_va
    print("strings @%#x  NEEDED off=%#x RUNPATH off=%#x" % (gva, off_needed, off_runpath))

    dynoff, dynsz = dyn_offsets(d)
    ents = [list(struct.unpack_from("<iI", d, dynoff + j * 8)) for j in range(dynsz // 8)]
    nulls = [j for j, e in enumerate(ents) if e[0] == 0]
    if len(nulls) < 3:
        raise SystemExit("not enough DT_NULL slots")
    struct.pack_into("<iI", d, dynoff + nulls[0] * 8, 1, off_needed)
    struct.pack_into("<iI", d, dynoff + nulls[1] * 8, 29, off_runpath)
    print("injected DT_NEEDED + DT_RUNPATH into slots %d,%d" % (nulls[0], nulls[1]))

    open(dst, "wb").write(d)
    print("sdDongle md5", hashlib.md5(d).hexdigest())

def make_tar(outdir):
    tar = os.path.join(outdir, "ax_hook.tar")
    order = LIBS + ["sdDongle", SHIM_SO]
    with tarfile.open(tar, "w", format=tarfile.GNU_FORMAT) as t:
        for f in order:
            p = os.path.join(outdir, f)
            os.chmod(p, 0o777)
            ti = t.gettarinfo(p, arcname=f)
            ti.uid = ti.gid = 0
            ti.uname = ti.gname = ""
            with open(p, "rb") as fh:
                t.addfile(ti, fh)
    print("wrote", tar, os.path.getsize(tar), "md5", hashlib.md5(open(tar, "rb").read()).hexdigest())

def main():
    os.makedirs(DST, exist_ok=True)
    for f in LIBS:
        open(os.path.join(DST, f), "wb").write(open(os.path.join(SRC, f), "rb").read())
    build_shim(os.path.join(DST, SHIM_SO))
    patch_sddongle(os.path.join(SRC, "sdDongle"), os.path.join(DST, "sdDongle"))
    make_tar(DST)

main()
