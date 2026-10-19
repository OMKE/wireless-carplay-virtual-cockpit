# Runtime log analysis — 2026-09-27 (in-car, live Audi session)

Source: `captures/wireless/log_20260927_162423/extracted/usr/data/log/` (pulled read-only via `/cgi-bin/minizip.cgi`). Dongle log files: `sdDongle_1.log`, `sdDongle_2.log`, `sdsdk_2.log`, `kernel_*.log`. Dongle has no RTC (timestamps are uptime `[Suding-hh:mm:ss:ms]`).

## Topology confirmed
- Real phone: `<owner's iPhone>`, AirPlay over Wi-Fi (`wlan0`), MAC `xx:xx:xx:xx:xx:xx`.
- Dongle ↔ car link (IPv6 link-local): HU (Audi) `fe80::22ff:fe44:6688`, dongle "FakeIphone" `fe80::38e6:22ff:fe44:6689`.
- Dongle identity to car: name `SmartBox_6081`, BT `XX:XX:XX:XX:60:81`, device UUID `68fe8feb-1bbf-40d3-bb69-8bd7f50a771a`, AirPlay `320.17.6`.

## Key facts
- `IAP2_MANUFACTURER:HARMAN` → `add AltScreen` fires. The Audi MMI is Harman-made, not LG, so the LG exclusion does NOT block Audi. The dongle **does tell the car it supports altScreen** (client/FakeIphone side, `AirplayClientSendCmdSetupScreen`).
- Main screen: `videoWidth:1024 videoHeight:480`, `mainScreen uuid:e5f7a68d-7b0f-4305-984b-974f677a150b`, forwarded to car as `HU video data port:6030 type:110`.
- Audio: `type:101` / `type:4` on port 7071.
- **No `type:111` (altScreen stream) anywhere in the logs.** No second display negotiated with the iPhone, no second stream set up toward the car.

## Interpretation (Hypothesis A confirmed, refined)
The altScreen path is only half-wired:
1. Toward the car: dongle announces altScreen capability (flag) — works.
2. Toward the iPhone: dongle advertises only ONE display (main, 1024×480) — matches static analysis (`_getScreenDisplays` → one `AirPlayInfoArrayAddScreenDisplay`).
3. So the iPhone produces only the main video stream; the dongle forwards only type 110 to the car; the VC has no CarPlay source and shows the OEM map.

## Still missing for a fix
- The Audi's own altScreen display descriptor (UUID / dimensions / viewAreas) is NOT in this log — the dongle never negotiated the second display, so it was never printed. To get it we'd need the car's `/info` response (the displays array the MIBSI patch adds), captured while the dongle queries the car, or a Wi-Fi/reverse-link capture.
