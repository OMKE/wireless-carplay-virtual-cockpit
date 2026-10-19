# Firmware — Smart Box 6081

## Installed version

| Field | Value |
|---|---|
| System version | `202510170926CA` |
| Protocol version | `20251013103649` |
| Web UI build | `index.html` Last-Modified 2025-10-17 01:34:22 GMT |
| Clock | Dongle has no RTC (HTTP Date = 1970-01-01) |

## Update mechanism (from `captures/wireless/webui/static_20260927_160022/index.html`)

The dongle has no internet access; the **viewer's browser** (iPhone, which has cellular data) does the download and pushes the file to the dongle.

1. Page load: `GET /cgi-bin/getversion.cgi` on the dongle → text lines `key:value` including `system_version`, `protocol_version`, `platform`, `custom`, settings.
2. `POST http://120.79.59.57:8080/device-web/upgrade/queryDeviceVersion` with JSON `{"version", "platform", "custom"}` → `{success, data:[{version, fileName, md5Encryption}, ...]}`.
3. User picks a file → `POST http://120.79.59.57:8080/device-web/upgrade/downLoad` with the same JSON (version = chosen) → binary blob (the firmware package).
4. Browser uploads the blob to the dongle in 10 KiB chunks: `POST /cgi-bin/downfile.cgi` (multipart field `chunk`, filenames `<name>.0` first, `<name>.1` middle, `<name>:<md5>.2` last). Dongle replies `success` / `file check success|fail`.
5. `GET /cgi-bin/submition.cgi?filename=<name>&` → `success download` → `GET /cgi-bin/reboot.cgi`.

Other dongle endpoints seen (NOT to be called without a plan — they change state): `factoryreset.cgi`, `reboot.cgi`, `setprop.cgi`, `audioselect.cgi`, `showui.cgi`, `switch_p2p.cgi`, `minizip.cgi?logID=`, vendor `open/upload`, `open/addLogFile` (log upload to vendor).

## Implications

- **Stock firmware can likely be obtained from the vendor server** by repeating step 2–3 from the Mac with the *current* version — without touching the dongle. Need `platform` and `custom` from `getversion.cgi` first.
- Integrity check seen on the client side is MD5 only; whether the dongle verifies a signature is unknown until the package is analysed.
- `minizip.cgi?logID=` suggests the dongle can export a log bundle — potentially the box log with the CarPlay SETUP exchange (next research step for Hypothesis A).

## Vendor packages downloaded (2026-09-27, owner-approved)

Query `{"version":"","platform":"AX1800M","custom":"suding"}` returned two versions. The installed version (`202510170926CA`) was NOT offered, so no exact copy of the installed firmware exists yet.

| Package | Size | MD5 (server=local) | SHA-256 |
|---|---|---|---|
| `ax_202607232244` | 1822208 | `d26a375e8d44561fb2ebbdd51e7a59bc` | `3ff2ce01e4c033fbcaba952c53dc655a3d3811386f6d25b5dd527152966f6626` |
| `ax_202609051445` | 1827328 | `138c7099fab54d48bc8181c305c740dc` | `204feda04a41de8b380a32685dcbbb148b7e3b33e23960269088cfdb6c3cee06` |

Format: plain GNU tar, no encryption or signature header. Contents (both): `sdDongle` (main executable), `libSdAuto.so`, `libSdCommon.so`, `libSdSampleRate.so`, `libSdUtils.so`. All ELF 32-bit MIPS32 rel2 LE, stripped. Application-only update, no kernel/rootfs.

Files: `firmware/vendor/` (read-only originals), `firmware/extracted/<version>/`.
