# Patch design — add CarPlay altScreen (instrument cluster) to Smart Box 6081

Reference implementation: LIVI (GPLv3) `analysis/reference/LIVI-cp-stack/` — a working CarPlay receiver that drives a cluster display. Use it as the protocol spec.

## Resolved: what marks a display as the cluster (was the open unknown)

There is NO separate "cluster feature bit". The **display `type` field is the designator**: `110` = main screen, `111` = alt/instrument-cluster screen (`STREAM_TYPE_MAIN_SCREEN=110`, `STREAM_TYPE_ALT_SCREEN=111`). The display `features` field only carries touch/knob caps (`HIGH_FIDELITY_TOUCH=0x08 | KNOBS=0x02`). Two extra requirements:
- Session setup response must include `'altScreen'` in `enabledFeatures` (LIVI `cpStack.ts` ~L742: `if cfg.cluster feats.push('altScreen')`).
- The alt display entry carries `initialURL = maps:/car/instrumentcluster/map`.

### Reference alt-display entry (from LIVI `getInfo.ts::displayEntry`)
```
{ uuid: <ALT_UUID>, type: 111, maxFPS, widthPixels, heightPixels, widthPhysical, heightPhysical,
  features: 0x0A, primaryInputDevice: 3 (knobs), viewAreas:[{...}], initialViewArea:0,
  initialURL: "maps:/car/instrumentcluster/map" }
```

## Proxy data flow required (both sides + bridge)

```
phone --110--> dongle-receiver --110--> car    (works today)
phone --111--> dongle-receiver --111--> car    (must be built end-to-end)
```

## Four parts to patch in sdDongle (MIPS32, Apple AirPlay receiver 320.17 + vendor "Suding")

| # | Where | Current | Needed |
|---|---|---|---|
| P1 | `_getScreenDisplays` 0x43dcfc → `AirPlayInfoArrayAddScreenDisplay` 0x47e910 | one display (type 110, uuid e5f7a68d…) | append a 2nd display: type 111, distinct uuid, cluster dims, initialURL cluster map |
| P2 | session setup / enabledFeatures + `AirPlayReceiverSessionScreen_*` 0x47ec30… (singleton, calloc(1,0x2f8), `screenInitialized` bool) | single screen session; no `altScreen` echoed | echo `altScreen` in enabledFeatures; accept a 2nd inbound screen stream (type 111) → 2nd screen receiver instance |
| P3 | client `AirplayClientSendCmdSetupScreen` 0x4317a0 (type hardcoded 110 at 0x431adc, targets gMainScreenUUID) | only main setup to car | send a 2nd SETUP type 111 to the car bound to the car's cluster display uuid |
| P4 | frame plumbing between P2 (inbound 111 from phone) and P3 (outbound 111 to car) | none | bridge decrypted/framed AUs from phone's alt stream to the car's alt stream |

## Prerequisites (must do before writing P1–P4)
- **Phase D (dynamic):** confirm the Audi offers a 2nd display to the dongle and capture the car's cluster display uuid + dimensions (the dongle stores only the main uuid today; P3 needs the cluster uuid). Source: verbose dongle log or Wi-Fi capture of the car↔dongle `/info`.
- **Phase T (toolchain):** MIPS32 LE cross-toolchain; ability to add a code cave + detour in `sdDongle` and repack the tar. Validate the build→flash→run→recover loop with a trivial reversible change FIRST (this also proves recovery).

## Risk / recovery
Flashing is via the dongle's own web updater (plain tar, MD5 only, no signature). Recovery = reflash a stock vendor package in `firmware/vendor/`. Recovery-through-webserver is assumed but unproven; the Wi-Fi AP owner (system vs sdDongle) is the main brick risk. The build/flash/recover loop must be proven before iterating on real patches.

## GROUND TRUTH (captured 2026-09-27 from Audi /info, analysis/carinfo/)

The Audi advertises 2 displays to the dongle. The dongle must present the SAME cluster display to the phone.

Cluster display (display[1]) exact values:
```
type: 111
uuid: b7e6c5a0-2222-4000-8000-000000000002   (Audi's cluster uuid; also the client-side setup target)
widthPixels: 1440, heightPixels: 540, maxFPS: 60
widthPhysical: 320, heightPhysical: 120
features: 2 (knobs)
primaryInputDevice: 3 (knobs)
initialURL: "maps:/car/instrumentcluster"
viewAreas[0]: full 1440x540, safeArea 720x297 @ (360,87)
hidDevice: "MHI2Q_ClusterKnob" uuid dc17795d-f04e-40df-99dc-70da4e917a2d, displayUUID = cluster uuid
```
Main display[0]: uuid e5f7a68d-…, 1024x480@30, NO type key (⇒ 110), features 2.

## Remaining implementation (all values now known)
- P1 (receiver→phone /info): add display[1] with `type:111` + initialURL + primaryInputDevice + dims + viewAreas. AddScreenDisplay does NOT emit `type`; cave must also CFDictionarySetInt64(dict,"type",111) and set initialURL — need "type"/"initialURL"/URL/uuid strings (embed in cave). Cleanest: mirror the car's parsed display[1].
- P2 (receiver): accept phone's 2nd screen stream (session screen is singleton → needs a 2nd AirPlayReceiverSessionScreen instance).
- P3 (client→car): send SETUP for stream type 111 bound to car cluster uuid b7e6c5a0-2222… (client currently hardcodes 110 to gMainScreenUUID).
- P4: bridge decrypted H264 AUs: phone's 111 stream → car's 111 stream.
- Cluster knob (optional first): forward MHI2Q_ClusterKnob HID.
