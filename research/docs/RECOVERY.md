# Recovery — Smart Box 6081

## Flash mechanism (proven tooling)
- Firmware = plain GNU tar (`libSdAuto.so libSdCommon.so libSdSampleRate.so libSdUtils.so sdDongle`, mode 0777, GNU format). `scripts/repack_firmware.sh` reproduces the vendor tar **byte-identically** (verified: repacked extracted files == vendor MD5 `138c7099…` for ax_202609051445).
- Install path = dongle web server at `http://192.168.200.1`: chunked `POST /cgi-bin/downfile.cgi` (10 KiB parts; names `<name>.0`, `<name>.1`, `<name>:<md5>.2`), then `GET /cgi-bin/submition.cgi?filename=<name>&`, then `GET /cgi-bin/reboot.cgi`. Integrity = caller-supplied MD5 only; no signature observed.
- `scripts/flash_dongle.sh <tar> [name] [--commit]`: without `--commit` it uploads + triggers the dongle's MD5 check but does NOT install (dry-run). With `--commit` it installs and reboots.

## Reaching the dongle without the car
The Wi-Fi AP (`SmartBox_6081`, `192.168.200.1`) comes up when an iPhone connects to the dongle over Bluetooth (observed at the desk). So flashing can be done at the desk: power the dongle, connect iPhone via BT to bring up the AP, join `SmartBox_6081` on the Mac, run the flash script.

## Recovery images
- `firmware/vendor/ax_202609051445.bin` (Sep 2025) and `ax_202607232244.bin` (Jul 2025), MD5-verified, read-only. Re-flash either with `--commit` to restore a known-good stock build.
- IMPORTANT: the vendor server does NOT offer the currently-installed build `202510170926CA`. Once we flash anything, we cannot return to the exact Oct build — only to Jul/Sep. Functionally equivalent for our work; patched builds will be based on Sep (`ax_202609051445`).

## Brick risk / unknowns
- Recovery-through-webserver assumes lighttpd + CGI keep running independent of `sdDongle`. If the Wi-Fi AP is brought up by `sdDongle` and a bad `sdDongle` fails to start, the AP may not appear and the web updater becomes unreachable. NOT yet proven.
- First real flash should be a known-good stock image (or a byte-identical repack) to prove: flash → reboot → AP returns → web UI reachable. Only then iterate on modified `sdDongle`.
- Install = `tar -xvf /tmp/<name> -C /usr/data/lib/` (confirmed). Firmware runs from writable /usr/data/lib; base system separate → web recovery very likely survives a bad sdDongle. No hardware (UART/JTAG) path investigated yet.
