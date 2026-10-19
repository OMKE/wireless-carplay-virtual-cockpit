# sdDongle — Secondary/Cluster Display Patch Feasibility (static RE)

Target: `firmware/extracted/ax_202609051445/sdDongle`
ELF 32-bit MIPS32r2 LE, dynamically linked, stripped-but-symbol-rich (AirPlay/CarPlay 320.17 source names).
Method: rizin 0.9.1, `bin.relocs.apply=true`, `scr.color=0`, `aa;aac;aar`; PIC-aware reading of `lui/addiu`/gp-GOT literal loads and `pdf`/`pd`. Read-only. No binary was modified.

All addresses are virtual. CFL constant strings are an 8-byte header (`56 07 01 00 ff ff ff 7f`) followed by the C-string, so a "key" pointer + 8 = the ASCII text.

---

## Q1 — `AirPlayInfoArrayAddScreenDisplay` (0x47e910) and `_getScreenDisplays` (0x43dcfc)

### Exact signature of AddScreenDisplay (o32, 9 args)
Disassembled 0x47e910–0x47eb9c. It builds one display **dictionary**, sets 8 keys, then appends the dict to the array:

| Arg | Reg/slot | CF call | Key (addr → text) | Value from `_getScreenDisplays` |
|-----|----------|---------|-------------------|----------------------------------|
| arg1 | a0 | in/out `CFArray**`. If `*a0==0` → `CFArrayCreateMutable` and `*a0 = array` (0x47e95c–0x47e978) | — | `&local` at `sp+0x30` (fresh array, returned in v0) |
| arg2 | a1 | `CFDictionarySetValue` | 0x52e704 → **uuid** | `0x5230d8` = CFL string **"e5f7a68d-7b0f-4305-984b-974f677a150b"** (HARD-CODED) |
| arg3 | a2 | `CFDictionarySetInt64` | 0x52e844 → **features** | `s0` = bitmask: base 2, `|8` HIFI_TOUCH, `|4` LOFI_TOUCH, `|0x10` HAVE_TOUCHPAD, HAVE_KNOB gate |
| arg4 | a3 | `CFDictionarySetInt64` | 0x52e858 → **primaryInputDevice** | `0` |
| arg5 | 16(sp) | `CFDictionarySetInt64` (only if `!=0`) + logs `inMaxFPS=%d` | 0x52e874 → **maxFPS** | `VIDEO_FPS` (default 0x14=20) |
| arg6 | 20(sp) | `CFDictionarySetInt64` | 0x52e884 → **widthPixels** | `VIDEO_WIDTH` (default 0x320=800; runtime 1024) |
| arg7 | 24(sp) | `CFDictionarySetInt64` | 0x52e898 → **heightPixels** | `VIDEO_HEIGHT` (default 0x1e0=480) |
| arg8 | 28(sp) | `CFDictionarySetInt64` | 0x52e8b0 → **widthPhysical** | `SCREEN_WIDTH_MM` (default 0x9a=154) |
| arg9 | 32(sp) | `CFDictionarySetInt64` | 0x52e8c8 → **heightPhysical** | `SCREEN_HEIGHT_MM` (default 0x57=87) |

Then `CFArrayAppendValue(*inArray, dict)` (0x47eb64) and `CFRelease(dict)`. Returns 0 on success.

Note: there is **no `viewAreas` and no display-index parameter** in this function. The display is identified only by the `uuid` CFString value. All config values are read in `_getScreenDisplays` via `ark_get_info_int` (0x51a0d0).

### Would a 2nd call append a valid 2nd display? — YES (structurally)
Every call allocates a fresh dict and does `CFArrayAppendValue` onto `*inArray`. A second call with the same `arg1` pointer and a different `uuid` (and different `features`) appends a second display dict. `_getScreenDisplays` calls it **exactly once** (single `bal` at 0x43de64), so today the array has length 1.

### Where the array comes from / how it is consumed
- `_getScreenDisplays` creates the array on its stack (`a0 = sp+0x30`, zeroed), AddScreenDisplay fills it, and it is returned in `v0`.
- `airPlayGetProperty` (call site 0x43f190–0x43f1a8) matches the requested property against CFL string 0x52320c = **"displays"** (via `CFEqual` 0x43f16c). On match it lazily fills the global cache `gScreenDisplays` (OBJ 0x56ac34, GOT slot 0x56965c): `sw v0,(s0)` at 0x43f1a8, then returns that array.
- `AirPlayCopyServerInfo` (0x468afc) assembles `/info` via repeated `AirPlayReceiverServerPlatformCopyProperty` (0x48aaf0) calls (0x468ca8, 0x468d40, 0x468e74, …), which route to `airPlayGetProperty`; the `displays` array is embedded verbatim.
- **Display count = CFArray length, not a fixed constant.** The phone reads the `displays` array and counts entries. HIGH confidence.

Conclusion Q1: adding a second `AddScreenDisplay` call (distinct uuid, appropriate features) would make `/info` advertise two displays to the phone.

---

## Q2 — `AirPlayReceiverSessionScreen_*`: single-instance

- `_Create` (0x47ece8, 152 B): `calloc(1, 0x2f8)` — one screen-session object; called **once** from `AirPlayReceiverSessionCreate` (0x474a20).
- `_Setup` (0x47eee8, 108 B): called once from `AirPlayReceiverSessionSetup` (0x47a634); reads key "latencyMs" (0x52f620). No display-index argument.
- `_StartSession` (0x47fe40) from 0x46ffcc; `_ProcessFrames` (0x47ef54).
- Assert string `!inSession->screenInitialized` (a boolean, not an array) confirms **one screen per AirPlay session**. There is no array/indexed set of screen sessions and no per-display selector.

Conclusion Q2: the receiver screen path is a **singleton per session**. A second inbound screen stream (type 111) from the phone cannot be handled by existing code — it would collide with the single screen object. Handling a 2nd stream requires new code. HIGH confidence.

---

## Q3 — Client side: stream type selection

- `AirplayClientSendCmdSetupScreen` (0x4317a0): builds the stream descriptor and hard-codes **type = 0x6e = 110**: `addiu a2, zero, 0x6e` (0x431adc) → `CFDictionarySetInt64(dict, "type"(0x52106c), 110, 0)` (0x431ae0–0x431af0). It then uses `gMainScreenUUID` (GOT 0x56939c) as the stream `uuid` (0x431af8, `CFStringGetCStringPtr`), logs `mainScreen uuid:%s` / `mainScreen streamID:%llx`. Also sets `streamConnectionID` (key 0x521090).
- The builder at 0x427c34 (carplay_wl_proxy_client.c) creates the RTSP `SETUP` via `HTTPMessageCreate`/`HTTPHeader_InitRequest` and packs `setupInfo`/`screenSetupInfo`/`screenInfo` dicts + AES-KEY/AES-IV.
- **No type 111 / second-screen SETUP path exists.** Search for `addiu aX, zero, 0x6f` (111) → none. The client sends exactly one main screen stream, type 110, targeting `gMainScreenUUID` (the car's main display uuid).
- Target display identity = **`gMainScreenUUID`** (copied from the car's info; see Q4).

Separate but related: the client **advertises the altScreen capability** to the car in the info exchange (see Q4), but advertising ≠ setting up a stream. HIGH confidence.

---

## Q4 — Does the client parse/store the car's `/info` displays?

Yes — the client reads the car's server info. In the CarPlay-info handler (~0x428e00–0x429178, "video stream count:%d", "retry send info cmd"):
- `CFDictionaryGetValue(dict, "uuid"(0x51f3fc))` → `CFStringCreateCopy` → stored into **`gMainScreenUUID`** (0x4290b8–0x4290e8). So the car's main display UUID is captured and later used for the type-110 SETUP.
- `fcn.0042c44c` iterates an array (`CFArrayGetCount`, `CFArrayGetTypedValueAtIndex` 0x4a433c), reads `hidType`/`getTouchScreenPointsNum`, logs `Touchscreen %d uuid = %s` (0x51fecc) — parses the car's touchscreen/HID descriptors.
- Client-declared altScreen data (toward the car): `AirplayClientSendCmdInfoExt` (helper at 0x425708) builds `altScreenUrlArray` (0x51dc2c) with **"maps:/car/instrumentcluster/map"** (0x51dc40) and **"maps:/car/instrumentcluster"** (0x51dc60), plus `uiContextUrlArray`.

What is NOT clearly present: capturing/storing a **second (instrument-cluster / altScreen) display descriptor's UUID and size** from the car. Only a single `uuid` → `gMainScreenUUID` was observed; there is no evidence of a stored cluster-display uuid usable to target a type-111 SETUP. MEDIUM confidence (the loop shape suggests it *could* be extended, but no current storage was found).

---

## Q5 — Feasibility verdict

### (b) Config change — NOT possible alone
Config keys read via `ark_get_info_int`/`ark_get_info_string`/`cfg_get_*` (file `/etc/config.ini`): `VIDEO_WIDTH`, `VIDEO_HEIGHT`, `VIDEO_FPS`, `SCREEN_WIDTH`, `SCREEN_HEIGHT`, `SCREEN_WIDTH_MM`, `SCREEN_HEIGHT_MM`, `HAVE_KNOB`, `HIFI_TOUCH`, `LOFI_TOUCH`, `HAVE_TOUCHPAD`, `IAP2_MANUFACTURER`, `IAP2_MODEL`, `CP_INFO_MODEL`, `VIDEO_MODE_WITH_CAR`. **No key for a second/cluster/alt display** (searched SCREEN/DISPLAY/CLUSTER/ALT/SECOND/NAVI/DUAL/EXT). These keys parameterize the *single* display only; a config edit cannot add a display advertisement.

### (a) Binary patch — the only route, but multi-part (not a one-liner)
Smallest change to make the **phone emit a 2nd stream**: patch `_getScreenDisplays` (0x43dcfc) to call `AirPlayInfoArrayAddScreenDisplay` a **second time** on the same array pointer with a distinct `uuid` and cluster-appropriate `features`/dimensions. The function is register-tight and ends immediately after the single call, so this needs a code cave / detour (there is room to hook: it just stores results and returns).

For that 2nd stream to actually reach the car as type 111, ALL of the following must also change — none exist today:
1. **Receiver**: create/handle a *second* concurrent screen session. The screen session is a singleton (`calloc(1,0x2f8)`, one `_Create`, `screenInitialized` bool). Requires new allocation + stream demux by streamType/uuid. (Substantial.)
2. **Client**: issue a *second* RTSP SETUP toward the car with `type = 111` for the cluster display uuid. `AirplayClientSendCmdSetupScreen` hard-codes 110 and only sources `gMainScreenUUID`; no cluster uuid is stored (Q4). Requires a new setup path + a stored cluster-display uuid from the car's `/info`.
3. **Frame plumbing**: route frames of the phone's 2nd screen stream (`_ProcessFrames`) to the new client stream to the car.

### Verdict: (c) — not feasible as a small/localized patch; requires a substantial rewrite.
The single easiest, high-confidence patch (2nd `AddScreenDisplay`) is necessary but far from sufficient; steps 1–3 are the bulk of the work and touch singleton receiver state, the client setup path, and frame routing.

### Unknowns / confidence
- **Which `features` bit (or field) marks a display as instrument-cluster/altScreen** so the phone opens a type-111 stream: NOT identified. The display dict has only uuid/features/primaryInputDevice/maxFPS/width/heightPixels/width/heightPhysical — no explicit "type"=111 or cluster flag. This is the biggest open question. LOW confidence; needs dynamic capture of a genuine multi-display `/info` or the AirPlay 320.17 header for the display "features" bit semantics.
- Whether `AirPlayCopyServerInfo` imposes any max display count: not exhaustively traced; length-driven consumption assumed. HIGH-ish confidence.
- Whether the car actually advertises a cluster display uuid the dongle could mirror (Q4): the parse loop exists but current storage of a 2nd uuid was not found. MEDIUM.

## Key addresses
- `_getScreenDisplays` 0x43dcfc; single `AddScreenDisplay` call 0x43de64
- `AirPlayInfoArrayAddScreenDisplay` 0x47e910 (append at 0x47eb64); keys 0x52e704/844/858/874/884/898/8b0/8c8
- hard-coded display uuid CFL string 0x5230d8 = "e5f7a68d-7b0f-4305-984b-974f677a150b"
- `airPlayGetProperty` "displays" match 0x43f16c–0x43f1a8; `gScreenDisplays` OBJ 0x56ac34 / GOT 0x56965c
- `AirPlayCopyServerInfo` 0x468afc; `AirPlayReceiverServerPlatformCopyProperty` 0x48aaf0
- Screen session: `_Create` 0x47ece8 (calloc 1×0x2f8), `_Setup` 0x47eee8, `_StartSession` 0x47fe40, `_ProcessFrames` 0x47ef54, `_Delete` 0x47ec30; callers `AirPlayReceiverSessionCreate` 0x474a20, `AirPlayReceiverSessionSetup` 0x47a634
- `AirplayClientSendCmdSetupScreen` 0x4317a0; type=110 at 0x431adc; `gMainScreenUUID` OBJ 0x56ada0 / GOT 0x56939c
- Client altScreen: LG check `strncasecmp "LG Electronics"` 0x428194; "LG no AltScreen" 0x4281d0; "add AltScreen"/`CFArrayAppendCString("altScreen")` into features 0x428208–0x428238
- `AirplayClientSendCmdInfoExt` altScreenUrlArray + instrument-cluster URLs 0x425984/0x425994/0x4259b8
- Car-info parse → `gMainScreenUUID`: 0x4290b8 (`CFDictionaryGetValue "uuid"`) → 0x4290e8; touchscreen parse `fcn.0042c44c` (logs 0x51fecc)
