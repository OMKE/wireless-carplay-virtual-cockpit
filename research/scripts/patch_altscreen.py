import hashlib, os, shutil, struct, sys

SRC = sys.argv[1]
DST = sys.argv[2]

TEXT_FILE_OFF = 0x16f00
TEXT_VA = 0x416f00
NOP = 0x00000000

PATCHES = [
    (0x43e4a4, 0x12000005, None, "nostrip: beqz $16 -> b (keep all displays)"),
    (0x43f46c, 0x1040fdaf, NOP, "enabledFeatures: always create array"),
    (0x43f4d0, 0x1040001a, NOP, "enabledFeatures: always append viewAreas"),
    (0x43f540, 0x10400008, NOP, "enabledFeatures: always take cornerMasks slot"),
    (0x43f558, 0x24a53398, 0x24a5f364, "cornerMasks slot -> altScreen CFL @0x51f364"),
]

data = bytearray(open(os.path.join(SRC, "sdDongle"), "rb").read())

for va, old, new, what in PATCHES:
    off = va - TEXT_VA + TEXT_FILE_OFF
    cur = struct.unpack_from("<I", data, off)[0]
    if new is None:
        if cur == old:
            sys.exit(f"0x{va:x} {what}: base is not nostrip (found 0x{cur:08x})")
        print(f"0x{va:x} ok (already patched 0x{cur:08x}) {what}")
        continue
    if cur != old:
        sys.exit(f"0x{va:x} {what}: expected 0x{old:08x}, found 0x{cur:08x}")
    struct.pack_into("<I", data, off, new)
    print(f"0x{va:x} 0x{old:08x} -> 0x{new:08x} {what}")

cfl = bytes(data[0x11f364:0x11f364 + 18])
if cfl != b"\x56\x07\x01\x00\xff\xff\xff\x7faltScreen\x00":
    sys.exit(f"altScreen CFL not at file 0x11f364: {cfl!r}")

os.makedirs(DST, exist_ok=True)
for f in ["libSdAuto.so", "libSdCommon.so", "libSdSampleRate.so", "libSdUtils.so"]:
    shutil.copy2(os.path.join(SRC, f), os.path.join(DST, f))
open(os.path.join(DST, "sdDongle"), "wb").write(data)
print("sdDongle md5", hashlib.md5(data).hexdigest())
