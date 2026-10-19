#!/usr/bin/env python3
import argparse, hashlib, os, sys, time, urllib.request, uuid

HOST = "http://192.168.200.1"
CHUNK = 10240
HERE = os.path.dirname(os.path.abspath(__file__))
IMAGES = {
    "hook": (os.path.join(HERE, "firmware", "ax_hook.tar"), "ax_hook", "06349f236fb6fd15e37e9fae55c1d002"),
    "stock": (os.path.join(HERE, "firmware", "stock_ax_202609051445.tar"), "ax_202609051445", "138c7099fab54d48bc8181c305c740dc"),
}


def get(path, timeout=15):
    with urllib.request.urlopen(HOST + path, timeout=timeout) as r:
        return r.read().decode("utf-8", "replace")


def post_chunk(filename, data):
    b = uuid.uuid4().hex
    body = (
        f'--{b}\r\nContent-Disposition: form-data; name="chunk"; filename="{filename}"\r\n'
        "Content-Type: application/octet-stream\r\n\r\n"
    ).encode() + data + f"\r\n--{b}--\r\n".encode()
    req = urllib.request.Request(HOST + "/cgi-bin/downfile.cgi", data=body,
                                 headers={"Content-Type": f"multipart/form-data; boundary={b}"})
    with urllib.request.urlopen(req, timeout=30) as r:
        return r.read().decode("utf-8", "replace")


def check_dongle():
    try:
        v = get("/cgi-bin/getversion.cgi")
    except OSError as e:
        sys.exit(f"Cannot reach the dongle at {HOST} ({e}).\nConnect this computer to the dongle Wi-Fi (SmartBox_XXXX, password 12345678) and try again.")
    info = dict(l.split(":", 1) for l in v.splitlines() if ":" in l)
    platform, custom = info.get("platform", "").strip(), info.get("custom", "").strip()
    print(f"Dongle found: platform={platform} custom={custom} firmware={info.get('protocol_version', '?').strip()}")
    if (platform, custom) != ("AX1800M", "suding"):
        sys.exit("This is not the supported dongle (need platform AX1800M, custom suding). Nothing was sent.")


def main():
    ap = argparse.ArgumentParser(description="Install the Virtual Cockpit hook (or the stock firmware) on a Smart Box AX1800M dongle.")
    ap.add_argument("--stock", action="store_true", help="install the original vendor firmware (rollback)")
    ap.add_argument("--check-only", action="store_true", help="upload and let the dongle verify the image, but do not install it")
    ap.add_argument("-y", "--yes", action="store_true", help="do not ask for confirmation")
    a = ap.parse_args()

    path, name, want = IMAGES["stock" if a.stock else "hook"]
    data = open(path, "rb").read()
    md5 = hashlib.md5(data).hexdigest()
    if md5 != want:
        sys.exit(f"{os.path.basename(path)} is corrupted (md5 {md5}, expected {want}). Re-download the repo.")

    check_dongle()
    action = "upload and verify (no install)" if a.check_only else "INSTALL and reboot"
    print(f"Image: {os.path.basename(path)}  md5 {md5}  -> {action}")
    if not a.yes and input("Type 'yes' to continue: ").strip().lower() != "yes":
        sys.exit("Aborted.")

    n = (len(data) + CHUNK - 1) // CHUNK
    resp = ""
    for i in range(n):
        fn = f"{name}.0" if i == 0 else f"{name}:{md5}.2" if i == n - 1 else f"{name}.1"
        resp = post_chunk(fn, data[i * CHUNK:(i + 1) * CHUNK])
        if "success" not in resp:
            sys.exit(f"\nChunk {i} failed: {resp.strip()}\nNothing was installed. Just run the script again.")
        print(f"\rUploading {i + 1}/{n}", end="", flush=True)
    print()
    if "file check success" not in resp:
        sys.exit(f"The dongle did not confirm the checksum:\n{resp.strip()}\nNothing was installed.")
    print("Dongle verified the image (file check success).")
    if a.check_only:
        return

    print(get("/cgi-bin/submition.cgi?filename=" + name + "&", timeout=60).strip())
    time.sleep(1)
    try:
        get("/cgi-bin/reboot.cgi", timeout=10)
    except OSError:
        pass
    print("Done. The dongle is rebooting (about 30 s). Unplug/replug it in the car if CarPlay does not come back.")


if __name__ == "__main__":
    main()
