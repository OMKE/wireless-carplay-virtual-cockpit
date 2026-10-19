# CarPlay Architecture — what the Audi expects

Source: MIBSI package `mibsi-p5092-7e792409480209467f17fb27-a215f63ae2304ec2-sd-bundle` (installed on the car, provided by owner). Analysed read-only with `file`/`strings`. Only config, hashes and strings are kept in `notes/audi-mibsi/`; binaries stay in `~/Downloads`.

## Head unit side (MHI2Q + MIBSI)

| Item | Value | Evidence |
|---|---|---|
| OS / arch | QNX, ARM EABI5 32-bit | `file` (`ldqnx.so.2`) |
| iAP2 stack | Cinemo, over USB FunctionFS `iap://ffs:///dev/otg-cinemo` (car is USB device after role swap) | `dio_manager.json` `iap2.device`, `usb.asi.roleSwap` |
| MFi auth chip | `i2c:///dev/i2c8:17` | `dio_manager.json` |
| CarPlay network iface | `carplay0` (mDNS direct link) | `dio_manager.json` `mdnsd` |
| AirPlay receiver | Apple `libairplay.so` (AirPlayReceiverServer/Session) | symbol names |
| iAP2 route guidance | messages `0x5200/0x5203` sent, `0x5201/0x5202/0x5204` received | `dio_manager.json` |
| Main screen max FPS | 30 | `dio_manager.json` `screen.maxFPS` |

## How MIBSI adds the cluster display (libmhi2qcarplaycluster.so)

Strings show it `dlopen`/`dlsym`s `libairplay.so` and hooks `CDIOManager::s_serverCopyPropertyCallback`. It deep-copies the receiver's `displays` array and appends a second display dictionary with keys:

`displayUUID`, `features` (`altScreen`), `widthPixels`, `heightPixels`, `widthPhysical`, `heightPhysical`, `maxFPS`, `primaryInputDevice`, `initialURL` = `maps:/car/instrumentcluster`, `initialViewArea`, `viewAreas` (`originXPixels`, `originYPixels`, `safeArea`, `drawUIOutsideSafeArea`), `viewAreaTransitionControl`, `adjacentViewAreas`, `hidDevices` (`MHI2Q_ClusterKnob`, `hidDescriptor`).

When the iPhone sends RTSP `SETUP` with a `streams` entry for that display (`streamConnectionID`, `dataPort`), MIBSI creates a **second** `AirPlayReceiverSessionScreen` instance (`_Create/_Setup/_SetSecurityInfo/_StartSession/_ProcessFrames`, key via `AirPlay_DeriveAESKeySHA512ForScreen`) and relays the decrypted H.264 (annex-b access units) over a loopback TCP socket to `/eso/bin/apps/mhi2q-aa-cluster-display --live-carplay`, which renders in the Virtual Cockpit. It also issues commands `updateViewArea`, `changeMapZoomLevel`, `forceKeyFrame`, `showUI`/`stopUI`.

Confidence: high that the capability is advertised in the AirPlay `/info` `displays` array as an `altScreen` display and delivered as a second screen stream. Exact key values (UUID, resolution) are not in the strings — they are computed at runtime.

## Consequence for the dongle path

```
iPhone ──AirPlay──> [dongle RECEIVER] ... [dongle SENDER] ──AirPlay──> MHI2Q RECEIVER (+MIBSI altScreen)
```

The Audi advertises the altScreen display **to the dongle** (the dongle is its "iPhone", see `docs/USB.md`). For the VC map to appear, the dongle must do all of:

1. Receiver side toward iPhone: include the second `displays` entry (with `altScreen` feature) in its own `/info`.
2. Accept the iPhone's `SETUP` for a second screen stream and decrypt it (per-stream key).
3. Sender side toward Audi: `SETUP` a second screen stream bound to the Audi's altScreen `displayUUID`, re-encrypt and forward the H.264.
4. Forward alt-screen commands/view-area changes and the cluster HID knob in both directions.

Any single missing step reproduces the observed symptom. Which one is missing is the target of the firmware analysis.
