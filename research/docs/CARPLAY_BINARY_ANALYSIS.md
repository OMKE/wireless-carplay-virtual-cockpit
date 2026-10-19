# CarPlay binary analysis — sdDongle (Smart Box 6081)

Binary: `firmware/extracted/ax_202609051445/sdDongle` (also present in `ax_202607232244`). ELF 32-bit MIPS32 rel2 LE, stripped, but many symbols recovered (Apple AirPlay/CarPlay source names are in the binary).
Build path in binary: `/home/cxt/project/sdDongle_linux/reverseLink/carplay-32017` → based on Apple CarPlay/AirPlay reference receiver **320.17** (`carplay-32017`). Vendor tag: `Suding`.
Tool: rizin (`bin.relocs.apply=true`, `aa;aac;aar`). Raw disassembly in `analysis/`.

NOTE: analysis is on the Sept-2025 build (`ax_202609051445`), not the exact installed build (`202510170926CA`). Logic is expected identical but should be re-confirmed on the installed binary if obtained.

## Two sides of the proxy

| Side | Role | Key functions |
|---|---|---|
| Toward real iPhone | AirPlay **receiver** (fake car) | `AirPlayCopyServerInfo` 0x468afc, `airPlayGetProperty` 0x43f194, `_getScreenDisplays` 0x43dcfc, `AirPlayInfoArrayAddScreenDisplay` 0x47e910, `AirPlayReceiverSessionScreen_*` 0x47e…, `ScreenStream*` 0x50c… |
| Toward real car | AirPlay **client** (fake iPhone, `FakeCarplay`/`carplay_wl_proxy_client.c`) | client SETUP builder @ **0x427c34**, `AirplayClientSendCmdSetupScreen` 0x4317a0, `AirplayClientSendCmdTearDownScreen` |

## Finding 1 — receiver advertises exactly ONE display to the iPhone (Hypothesis A confirmed)

`_getScreenDisplays` (0x43dcfc), called only from `airPlayGetProperty` (0x43f194, i.e. when the iPhone requests `/info`):
- reads config via `ark_get_info_int`: `HAVE_KNOB`, `HIFI_TOUCH`, `LOFI_TOUCH`, `HAVE_TOUCHPAD`, `VIDEO_FPS` (0x320), `VIDEO_WIDTH` (default 0x320 = 800), `VIDEO_HEIGHT` (default 0x1e0 = 480);
- calls `AirPlayInfoArrayAddScreenDisplay` **exactly once** (0x43de64).

`AirPlayInfoArrayAddScreenDisplay` (0x47e910) has exactly one caller in the whole binary (`_getScreenDisplays`). There is no second/cluster display key anywhere (`izq` shows only `VIDEO_WIDTH/VIDEO_HEIGHT/HAVE_KNOB`, no SECOND/CLUSTER/DISPLAY2/EXT_DISP).

⇒ The dongle's `/info` to the iPhone contains a single display (main screen). The iPhone therefore never sets up a second (instrument-cluster, stream type 111) video stream. This matches the observed symptom.

## Finding 2 — client side already advertises altScreen to the car (Hypothesis E refuted for Audi)

Client SETUP builder at 0x427c34 (in `carplay_wl_proxy_client.c`, builds an RTSP/HTTP message via `HTTPMessageCreate`) constructs a display dict with keys `uiContext`, `viewAreas`, `cornerMasks`, `focusTransfer`, and a `features` array. At 0x428184:
```
strncasecmp(manufacturer, "LG_Electronics", 5)
  != 0  → log "add AltScreen",  CFArrayAppendCString(features, "altScreen")
  == 0  → log "LG no AltScreen", skip
```
`manufacturer` comes from config (`IAP2_MANUFACTURER` / `Default_MODEL`, `cfg_get_string`). Audi is not LG ⇒ the dongle tells the car it supports `altScreen`. So the car-facing side is not the blocker for Audi.

## Conclusion

The dongle is altScreen-aware toward the car but advertises only one display toward the iPhone. The missing piece is on the receiver side: `_getScreenDisplays` must add a **second** display (cluster/altScreen), mirroring the display the car offers, so the iPhone produces the type-111 stream that the client side is already prepared to forward.

## Candidate fix locations (for later, no changes yet)

- `_getScreenDisplays` (0x43dcfc): add a second `AirPlayInfoArrayAddScreenDisplay` call describing the cluster display (UUID/size/features incl. `altScreen`, viewAreas). Requires the receiver session to then accept a second `AirPlayReceiverSessionScreen` and route its frames to the client SETUP already built at 0x427c34.
- Simplest experiment first: confirm at runtime (box log) that only one display is advertised during a live Audi session, before any patching.

## Open questions

- Where does the cluster display's geometry/UUID come from — is the car's offered display cached anywhere the receiver side can read? (needed to fill a correct second display entry)
- Does `AirPlayReceiverSessionScreen_*` already support a second concurrent screen instance, or is it single-instance?
- Exact installed build (202510170926CA) not yet analysed.
