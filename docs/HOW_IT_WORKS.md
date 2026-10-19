# How it works

## The problem

```
iPhone ──AirPlay (Wi-Fi)──> dongle [receiver | sender] ──AirPlay (USB)──> Audi MHI2Q + MIBSI ──> Virtual Cockpit
```

With a cable, the MIBSI mod on the MHI2Q adds a second display (`altScreen`, 1440×540, uuid `b7e6c5a0-2222-4000-8000-000000000002`) to the car's AirPlay `/info`. iOS sees it and sends a second H.264 stream (type 111) with the cluster map.

The dongle sits in the middle. It is an AirPlay **receiver** toward the iPhone and an AirPlay **sender** toward the car. The stock `sdDongle` dropped every display except the main one from the `/info` it gives the iPhone. It only knew how to forward stream type 110 (main screen). So the iPhone never rendered the cluster map.

## The dongle

- SoC/platform `AX1800M`, vendor build `custom:suding`, MIPS32r2 little-endian Linux.
- CarPlay is one stripped binary `sdDongle` plus `libSdAuto/Common/SampleRate/Utils.so` in `/usr/data/lib`.
- Update = plain GNU tar, uploaded through the web UI (`downfile.cgi` in 10 KiB chunks, the last chunk name carries the md5, then `submition.cgi` → `tar -xvf … -C /usr/data/lib/`, then `reboot.cgi`). No signature.

## The modification

### sdDongle (5 instruction words + loader)

| VA | Change | Why |
|---|---|---|
| `0x43e4a4` | `beqz` → `b` | keep all displays from the car in the receiver `/info` |
| `0x43f46c`, `0x43f4d0`, `0x43f540` | branch → `nop` | always build the `enabledFeatures`/viewAreas entries |
| `0x43f558` | string pointer → `altScreen` | advertise the feature that makes iOS open stream 111 |
| `0x46c2fc` | `bal Setup` → `jalr t9` | route the screen-SETUP call through the GOT so it can be hooked |
| dynamic section | + `DT_NEEDED libSdH.so`, `DT_RUNPATH $ORIGIN` | load the add-on |

The add-on's constructor swaps GOT entry `0x568f38` (Setup, `0x477fd4`) for its own function, but only if the slot still holds the original value. If `libSdH.so` doesn't load, `jalr t9` calls the original and CarPlay behaves like stock.

### libSdH.so (`src/altscreen.c`)

1. **Phone SETUP hook.** Takes the type-111 entry out of `streams`, lets the original Setup handle the main screen, opens its own data socket with the dongle's `ServerSocketOpen`, and returns `{type:111, dataPort}` to the iPhone.
2. **Car SETUP.** Sends a type-111 client SETUP to the car with the cluster uuid, connects to the car's cluster data port, and sets up an AES-CTR client context (`ctx+0x168`) the same way as the main screen.
3. **Activation.** When the iPhone connects to the 111 socket, it sends `showUI {uuid, url:"maps:/car/instrumentcluster/map"}` through `AirPlayReceiverSessionSendCommand`. Until the first IDR it sends `forceKeyFrame` every 120 frames.
4. **Frame relay.** Each frame is a 128-byte header (`[0]` size, `[4]` type: 0 video, 1 avcC config) plus a body.
   - Phone side: the body is **ChaCha20-Poly1305** when the session has a pair-verify session. Key from `GetStreamSecurityKeys` (`DataStream-Salt<connID>` / `DataStream-Output-Encryption-Key`), AAD = header, nonce = 64-bit LE frame counter, 16-byte tag at the end. Without pair-verify the stock AES-CTR key (`DeriveAESKeySHA512ForScreen`) is used.
   - Car side: a fresh, zeroed header. Config frames carry width/height and viewArea `0,0,1440,540`. Video is AES-CTR encrypted with the car context and sent under the context's mutex. The config is held back until the car socket is ready, and video waits until config + an IDR have been sent.

## Findings that mattered

- The 111 stream is ChaCha20-Poly1305, not AES-CTR. Decrypting with AES gave garbage until this was found.
- The dongle's own `carplay_reverse_video_push_frame` hard-codes main-screen size and view area, so the add-on writes to the car socket itself.
- `AirPlayReceiverSessionSendCommand` does a `dispatch_sync`, so it must not be called from inside the SETUP hook (deadlock). It is called from the sink thread.

Everything else, including dead ends, is in `research/` (`research/notes/COMMAND_LOG.md` is the chronological log, `research/docs/STATUS.md` the summary).
