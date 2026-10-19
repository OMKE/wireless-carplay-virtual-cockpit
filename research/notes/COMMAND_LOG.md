# Command Log

## 2026-09-27

- `route -n get default`, `networksetup -getinfo Wi-Fi`, `arp -a` — Mac was on the home network (gateway 192.168.0.1), NOT the Smart Box Wi-Fi. No scan performed.
- Created workspace skeleton, `scripts/collect_network.sh`, `scripts/collect_usb.sh`.
- `brew install nmap binwalk rizin wireshark libusb` — tools installed (wireshark = CLI/tshark only).
- `scripts/collect_usb.sh` with dongle plugged into Mac → `captures/usb_20260927_145559/`.
- `tools/venv` with pyusb; `scripts/dump_usb_descriptors.py 05ac 12a8` → `descriptors_all_configs.txt` (GET_DESCRIPTOR only, no SET_CONFIGURATION, no role-switch request).
- `system_profiler SPAirPortDataType` — SSIDs redacted in output; Smart Box SSID not identified yet.
- `brew install ghidra` (12.1.4, pulls openjdk@21).
- Read-only analysis of Audi MIBSI bundle in ~/Downloads (file, strings, dio_manager.json). Saved hashes/strings/config to notes/audi-mibsi/.
- Owner: no dongle SSID when plugged into Mac; SSID visible when plugged into Audi. Network collection must be done in the car.
- 15:18 launched scripts/smartbox_wifi_session.sh SmartBox_6081 <pass> <home-wifi> (detached, 30s delay)
- 15:21 v1 session: joined SmartBox_6081 but no DHCP lease within 30s; rejoin <home-wifi> via networksetup failed (-3900, keychain not used). Rewrote script v2: user switches Wi-Fi manually, script detects, waits 90s for DHCP, logs link data.
- v2 session invalid: Mac auto-returned to <home-wifi> during wait; captured home network data (captures/wireless/smartbox_link_20260927_152152 = home network, ignore). BT scan found SmartBox_6081 XX:XX:XX:XX:60:81.
- 15:27 v3 session launched; iPhone connected to dongle via BT + Wi-Fi, Mac BT disconnected from dongle.
- 15:37 v3 session: never triggered — on SmartBox the Mac got no IPv4/gateway even with iPhone connected. v4 script: detects absence of home gateway, collects IPv6 link-local/ndp/mDNS, nmap -6 on peers. Launched.
- 15:44 v5 session launched (nmap -n, ARP sweep 192.168.200.0/24, target dongle MAC dc:84:3:eb:8:cb). Upstream research agent finished → notes/upstream-research.md.
- v5 session: dongle 192.168.200.1, only port 80 (lighttpd 1.4.76) in top 1000; full scan broke when Wi-Fi switched back. Stopped leftover nmap.
- Web UI screenshot from iPhone saved. Mac Chrome showed ERR_INTERNET_DISCONNECTED (no gateway). Launched scripts/grab_webui_static.sh (GET index + referenced .js/.css only).
- Fetched index.html + jszip.min.js from dongle (GET only). Documented update flow in docs/FIRMWARE.md. Launched scripts/grab_getversion.sh (GET getversion.cgi + language.json, same calls the page makes on load).
- Owner-approved: downloaded ax_202607232244 + ax_202609051445 from vendor (MD5 verified). Extracted: MIPS32 LE, sdDongle + 4 libs. Updated FIRMWARE/DEVICE_IDENTITY/FINDINGS docs.
- rizin static analysis of sdDongle: confirmed single-display advertisement to iPhone (Hyp A). Wrote docs/CARPLAY_BINARY_ANALYSIS.md, saved analysis/*.asm.
- 16:24 launched pull_dongle_log.sh (1h wait) for in-car log capture.
- Pulled in-car dongle log via minizip.cgi; carved zip, extracted sdDongle logs. Confirmed Hyp A at runtime (no type 111). Wrote notes/runtime-log-20260927.md.
- Feasibility verdict recorded (substantial rewrite; config-only impossible). Wrote docs/STATUS.md.
- Mined LIVI (GPLv3) cp stack for exact altScreen /info spec (type 111 designator, enabledFeatures altScreen). Saved reference to analysis/reference/. Wrote docs/PATCH_DESIGN.md.
- Built scripts/repack_firmware.sh (reproduces vendor tar byte-identically) and scripts/flash_dongle.sh (chunked upload, dry-run/commit). Wrote docs/RECOVERY.md. rz-asm assembles MIPS for patches.
- 17:25 Phase T tooling ready; nothing flashed to device.
- Dry-run flash of ax_202609051445 succeeded: 'file check success', dongle reassembles to /tmp/<name>, md5-only check, no signature. No install.
- --commit flash of stock Sep succeeded. Install = tar -xvf to /usr/data/lib/. Awaiting user confirm dongle rebooted, AP back, version now Sep.
- Recovery proven. protocol_version now Sep; system_version = OS partition (unchanged). App flash replaces only /usr/data/lib. Now checking for hidden config gates before binary surgery.
- Agent produced P1 candidate (2-region patch, verified). Built ax_p1p2.tar (md5 1f391f9b). No cheap gate-flip; type-vs-features field for cluster is unresolved → need Audi /info ground truth. Next: flash P1 at desk to validate pipeline + observe phone reaction.
- P1 in-car test: patched fw runs, CarPlay main OK, no type-111 stream. Car /info features 0x144440b80 (AUDI, srcvers 210.81); dongle->phone features 0x6104040280. Need instrumentation patch to dump full /info displays arrays (car-received + phone-sent) for ground truth.
- Built carinfo-dump patch: detour @0x4287dc→cave@0x52fe00 dumps car /info buffer ([$18+0x49c],len[$18+0x4a0]) via raw open/write syscall to /usr/data/log/carinfo.bin. Verified in llvm-objdump. Built ax_carinfo.tar.
- carinfo dump SUCCESS: captured Audi /info bplist (21588B). displays=2, cluster display[1] type=111 uuid b7e6c5a0-2222 1440x540@60 initialURL maps:/car/instrumentcluster. Saved to analysis/carinfo/. This is the spec for the real fix.
- Recorded exact cluster spec + remaining P1-P4 plan in docs/PATCH_DESIGN.md.
- P1-cluster v1 verified by disasm. Ready to flash: firmware/modified/ax_p1cluster.tar (md5 a6870d1a). Test: does phone request a type-111 stream.
- Built p1va (P1 cluster + full viewAreas incl safeArea 720x297@(360,87), matching Audi). 3 code caves + data cave, custom MIPS encoder, verified by llvm-objdump (detour, inter-cave jumps, 22 CF calls, return all correct). enabledFeatures NOT included (receiver has no build site). Built ax_p1va.tar.
- p1va (viewAreas) test: phone STILL opens only 1 screen (1 ScreenRecord main, no 1440x540/type111). viewAreas NOT the blocker. Points to session-level altScreen capability negotiation (enabledFeatures) as the real gate.
- Launched Ghidra headless decompile of sdDongle (key AirPlay/FakeCarplay functions) -> analysis/ghidra/decomp.c
- BREAKTHROUGH: phone /info from /tmp/nativeDict.plist via airPlayGetPropertyFromNativeHU; strip-to-1-display loop @0x43e4a4 is the filter. Built 1-byte nostrip patch (ax_nostrip.tar) to disable stripping.

## 2026-10-18 — C hook library (step 1: answer stream 111)

- Mechanism decided: the single caller of `AirPlayReceiverSessionSetup` is one `bal` @0x46c2fc (t9 pre-loaded from GOT word 0x568f38 @0x46c2f0). Library symbol interposition is impossible (executable wins lookup), so: patch the `bal` to `jalr t9` (0x0320f809) and have a loaded library overwrite GOT[0x568f38] from its constructor. If the library fails to load/install, GOT keeps 0x477fd4 → `jalr t9` calls the original → central CarPlay unaffected (automatic fallback).
- `shim/altscreen.c`: `shim_session_setup` filters the type-111 entry out of `streams`, calls the original Setup (abs 0x477fd4) with the rest, then opens a loopback TCP sink and appends `{type:111, dataPort}` to the response via `_AddResponseStream` (0x472ba4). All CF funcs + CFL callbacks + key strings referenced by absolute VA (abs addressing proven by prior in-car code caves). Sink thread drains and discards the video, logging the byte count to /usr/data/log/altscreen.log.
- Built with `zig cc -target mipsel-linux-gnueabihf.2.17 -mcpu=mips32r2 -shared -nostdlib`. Verified: e_flags 0x70001007 (= vendor libs), abiflags o32/mips32r2/hard-float (fp_abi=1), INIT_ARRAY present, SONAME libSdH.so, imports only standard libc/pthread.
- `scripts/build_hook.py`: builds shim, patches sdDongle (bal→jalr; inject DT_NEEDED `libSdH.so` + DT_RUNPATH `$ORIGIN` into two DT_NULL slots, name strings placed in .rodata zero padding @0x52fe02), repacks 6-file GNU tar. Output firmware/modified/ax_202609051445_hook/ (sdDongle md5 bd0d37ed, ax_hook.tar md5 5e75b818).
- Static verify OK: exactly 4 edit regions in sdDongle (2 dyn slots, the bal word, 2 strings), terminating DT_NULL preserved, dynamic re-parses with libSdH.so NEEDED + $ORIGIN RUNPATH. NOT flashed — awaiting owner confirmation.
- First flash (hook only, on stock /info): shim loaded + GOT installed (`altscreen shim installed`), but phone never sent 111 — stock advertises 1 display / no altScreen. Added the 5 `patch_altscreen.py` word-patches (nostrip + enabledFeatures→altScreen CFL) into build_hook.py; they don't overlap the hook edits.
- Iterated in-car to make the phone actually stream 111 (each a flash + pull_dongle_log altscreen):
  1. combined build → phone sends `type 111` (separate SETUP, before 110), we answer dataPort, but no connect.
  2. loopback bind was wrong → `INADDR_ANY`: still no connect.
  3. root cause: CarPlay data link is IPv6; the raw AF_INET socket never saw it. Switched to the dongle's own `ServerSocketOpen` (0x4cbf54) with the family from `session+0x8c` (same as main screen). → `accept fail` (ServerSocketOpen returns a non-blocking fd).
  4. clear O_NONBLOCK before blocking accept → `alt connected`.
  5. periodic logging → phone streams the cluster video: running total climbs steadily past 5.5 MB (`alt first read 496`, then continuous).
- STEP 1 COMPLETE & CONFIRMED in-car: central CarPlay works, phone sets up both 110 and 111, and pushes 1440x540 cluster video to our sink (discarded). Build firmware/modified/ax_202609051445_hook/ (ax_hook.tar). Fallback intact (GOT guard → original Setup if shim absent).
- Next: STEP 2 (P3+P4) — send a type-111 client SETUP to the car (cluster uuid b7e6c5a0-2222-4000-8000-000000000002) and bridge the decrypted frames from the phone's 111 stream to the car's 111 stream.
- Known shortcut to revisit: a new sink socket + detached thread is opened per 111 SETUP; old threads leak across re-setups (fine for test, revisit for step 2).

## 2026-10-18 — P3 (send type-111 client SETUP to the car)

- Used `analysis/p4-client-screen-map.md` (client screen path map). Confirmed via decomp + rizin that `AirplayClientSendCmdSetupScreen @0x4317a0` differs from a cluster variant in exactly 3 spots: type immediate `0x6e` (@0x431adc), `gMainScreenUUID` (@0x431af8), and the response callback `0x430b18` (filters type 0x6e only). Everything else (bplist build, connect, AES, timer) takes ctx as an arg and is reusable.
- Decision: reimplement the SETUP in the shim (additive, main path left byte-identical → fallback intact) rather than patch the shared function. Resolved every helper + global + CFL-key VA from the disassembly (rizin), so no guessed addresses.
- Added to `shim/altscreen.c`: `cluster_setup_to_car()` (malloc 0x288 ctx like `carplay_reverse_video_start`; builds a SETUP request with `streamConnectionID` from UUIDGet, `type=0x6f`, `uuid="b7e6c5a0-2222-4000-8000-000000000002"`, `latencyMs=25`; sends via `HTTPClientSendMessage(*gAirPlayClient)`; waits on a dispatch semaphore; connects to `gPeerAddr`:carDataPort with 21×100 ms retry; derives AES-CTR keys via `simAirPlayDeriveAESKeySHA512`+`AES_CTR_Init`; stores ctx in `g_cluster_ctx` for P4) and `cluster_response_cb()` (parses the car's bplist reply, finds the `type==0x6f` stream, stores its dataPort, signals the semaphore). Triggered once from `sink_thread` right after `alt connected`, in its own detached thread so the 111 drain is not blocked.
- Key derivation args verified from disasm: `simAirPlayDeriveAESKeySHA512(sessionAesKey, 16, "AirPlayStreamKey<connID>", keyLen, "AirPlayStreamIV<connID>", ivLen, ctx+0x10, ctx+0x20)`; connID (lo=BE32(uuid[4..7]), hi=BE32(uuid[0..3])) written to globals 0x56b378/0x56b37c and into the dict, matching the car's derivation.
- Built OK (`scripts/build_hook.py`): libSdH.so e_flags 0x70001007, imports only libc/pthread, cluster funcs static. **sdDongle md5 8fc49040… = identical to the confirmed step-1 build** — only libSdH.so changed. ax_hook.tar md5 95ef7138.
- NOT flashed — awaiting owner confirm. Test markers in `/usr/data/log/altscreen.log`: `cluster SETUP sent` → `cluster car dataPort <n>` → `cluster SETUP replied` → `cluster connected to car <n>` → `cluster ctx ready`. Failure markers: `cluster homekit mode unsupported`, `cluster http/dict/plist/setbody fail`, `cluster no dataPort`, `cluster socket/connect fail`. If only `cluster SETUP sent` appears, the car rejected 111 (semaphore hang in the detached thread; central CarPlay + step-1 sink unaffected).
- Known shortcut: req/stream/array/body CF objects and the HTTP msg are not released in the success path (one-shot per session leak); revisit after P4 works.

## 2026-10-18 — P3 CONFIRMED + P4 (bridge frames to the car)

- P3 confirmed in-car: `altscreen.log` shows `cluster SETUP sent`/`cluster car dataPort 6100`/`cluster SETUP replied`/`cluster connected to car 6100`/`cluster ctx ready`. Car accepts type 111, dongle holds an AES-CTR socket to the car's cluster port. VC still on Audi maps (frames still discarded).
- Mapped the receiver decrypt path from the binary (rizin): phone's 111 frames on our sink are AES-CTR encrypted; the receiver derives keys with `AirPlay_DeriveAESKeySHA512ForScreen(session+0x200, 16, connID_lo, connID_hi, key16, iv16)` @0x481af0 (connID from the stream dict's `streamConnectionID`), then `AES_CTR_Init(ctx, key, iv)` @0x48b780 and continuous `AES_CTR_Update(ctx+0xb8, body, len, body)` @0x48b804 (verified: continuous stream, not per-frame counter). Frame wire format (ProcessFrames @0x47ef54): 128-byte plaintext header then body; `size = hdr[0]` (u32), `type = hdr[4]` (0 video, non-0 config/metadata). Config type-1 carries dims/viewArea in the header and the avcC in the body (`ScreenStreamSetAVCC`).
- P4 in `shim/altscreen.c`: capture `session` + the 111 `streamConnectionID` in `shim_session_setup`/`filter_streams`; moved the cluster-setup trigger there (earlier, so P3 finishes before frames flow). `sink_thread` rewritten to be frame-aligned (`readn` 128-byte header + body), derive the receiver key once and `AES_CTR_Init` a decrypt ctx, then per frame: `AES_CTR_Update` in-place; for video (type 0) convert internal NAL length-prefixes to `00 00 00 01` (leaving offset 0 for push_frame, matching `ScreenStreamProcessData`) and `carplay_reverse_video_push_frame(g_cluster_ctx, body, len, 0)` @0x431698; for config (type 1) log the first bytes (`dbg_hex`) and push with isConfig=1. Early frames (before `g_cluster_ctx` ready) are decrypted-but-dropped to keep the CTR counter synced.
- Built OK; sdDongle md5 8fc49040… (still identical to the confirmed build — only libSdH.so changed). ax_hook.tar md5 98ff5b60.
- NOT flashed — awaiting owner. Markers: `alt connID lo`/`alt decrypt ready`/`alt first frame type`/`alt frames pushed <n>` (climbing = pushing to car). `alt config bytes <hex>` = captured avcC/config format. Failure: `alt no connID`, `alt bad bodylen <n>` (header-format wrong), `alt body malloc fail`.
- First-try risk flagged: the config (type-1) push format is the least certain part — if `push_frame` config expects Annex-B SPS/PPS but the phone body is avcC, the car may not decode; the `alt config bytes` hex capture gives the exact format to fix next without a dedicated diagnostic drive.

### P4 first flash result + fixes (2026-10-18)

- First P4 flash: P3 chain still OK (`cluster ctx ready`, car dataPort 6100). Two bugs found from `altscreen.log`:
  1. `alt bad bodylen 0` then bail — but reading ProcessFrames @0x47ef54 shows a **128-byte header with `size==0` is a valid frame** (`beqz fp` path), not an error. My bail killed the session that actually had a valid connID (1188840381).
  2. `alt config bytes` were garbage (not avcC `01…`). Reading the type!=0 branch @0x47f6c4: config frames are passed to `ScreenStreamSetAVCC(stream, body, size)` **without AES/chacha decryption** — only type==0 (video) bodies are decrypted (AES_CTR @0x47f604). So config is **plaintext avcC**; decrypting it produced garbage.
- Fixes in `shim/altscreen.c`: (a) `size==0` → count frame, skip body, continue (don't bail); (b) decrypt + NAL-convert + push only for type==0 (video); (c) type!=0 (config) pushed raw (no decrypt) with isConfig=1, raw bytes logged (`alt config raw`) to confirm avcC; (d) derive the decrypt key only when connID!=0 (`alt no connID <lo>` otherwise); log connID hi too.
- Built; sdDongle still 8fc49040… (unchanged). ax_hook.tar md5 dbf7e19e. NOT flashed — awaiting owner. Check: `alt config raw` should start with `01` (valid avcC) → confirms the plaintext-config theory; `alt frames pushed` should climb.

### P4 second flash: CRASH LOOP — cause found + config fix (2026-10-18)

- Flash of dbf7e19e crash-looped sdDongle (dongle showed CarPlay then "please connect bluetooth" repeatedly; `altscreen.log` = repeated `altscreen shim installed` with a crash right after the config frame each session).
- Confirmed from log: `alt config raw 01 64 00 20 ff e1 00 15 27 64 00 20 ac 13 14 50 16 81 17 ee 6e 02 1a 0c 0d a0 88 46 58 01 00 04 28 ee 3c b0` = **valid avcC** (01 ver, 64 High, 1 SPS len 0x15 @0x27, 1 PPS len 4 @0x28) → plaintext-config theory confirmed, framing+config correct.
- Crash cause: `video_fake_push_frame_cb` config path (0x431308) calls `h264_convert_AnnexBHeader2AVCC` @0x42cbdc — it expects **Annex-B SPS/PPS**, but I fed it raw avcC → overrun → whole sdDongle crashes (fallback can't help a post-load crash). (The main path's config sender `video_fake_video_conifig_notify_impl` @0x430704 writes `[128B hdr][raw avcC]` unencrypted, a separate mechanism.)
- Fix: added `g_push_enabled` gate; first built a SAFE recovery (push off, md5 75e8a9cb) to stop the loop. Then added `avcc_to_annexb()` (parse avcC SPS/PPS → `00 00 00 01`+NAL) and push config as Annex-B via `push_frame(…,1)`; re-enabled push. Built md5 babc94e7, sdDongle still 8fc49040.
- Open item: connID logging was inconsistent across sessions (`connID lo 1868645005 / hi 0` vs `lo 0 / hi 970316197`) — if the decrypt key is wrong, video decrypts to garbage (no crash). This flash (no config crash) will give a clean capture to confirm whether video decodes + `frames pushed` climbs, and the real connID.
- Escape hatch if it crashes again: `firmware/vendor/ax_202609051445.bin` (pure stock, stable, no cluster).

### P4: ChaCha20-Poly1305 video decrypt path (2026-10-18 23:30)

- RE (rizin): `AirPlayReceiverSessionSetup` @0x47a6d0 branches on `session+0x3ec` (`pairVerifySession`, HomeKit pair-verify). If set → `GetStreamSecurityKeys` @0x474254 (`&session->pvs, pad, connID lo, hi, 0, 0, outKey32`; HKDF salt `DataStream-Salt%llu`, info `DataStream-Output-Encryption-Key`) → `SetChaChaSecurityInfo` (key @screen+0x2c4, 8B nonce @screen+0x2e4 zeroed). AES-CTR (`DeriveAESKeySHA512ForScreen`) is used only when pvs==NULL.
- ProcessFrames ChaCha branch @0x47f4b4 (flag screen+0x1d4): per video frame `chacha20_poly1305_init_64x64(ctx, key, nonce)` @0x4aa770, `add_aad(ctx, hdr128, 0x80)` @0x4aad3c, `decrypt(ctx, body, size-16, body)` @0x4aaec0, `verify(ctx, body+n, body+size-16, &err)` @0x4ab124, plaintext len = size-16, nonce++ (64-bit LE). Config (type!=0) bypasses decrypt (matches the plaintext avcC seen).
- Shim: `sink_thread` logs `alt pairVerifySession set <0|1>`; if 1 uses the ChaCha path (`alt chacha keys rc`, `alt chacha verify err` for the first 2 frames, `alt chacha fail <n>` on tag mismatch), else the old AES path.
- Built ax_hook.tar md5 7205e9ed (sdDongle 8fc49040 unchanged). The previous diagnostic build is kept as `ax_hook_diag_2315.tar` (md5 db5908ac). NOT flashed.

### P4: bypass push_frame, forward the phone's frames to the car (2026-10-18)

- RE `carplay_reverse_video_push_frame` @0x431698 / `video_fake_push_frame_cb` @0x43108c: push_frame builds its own zeroed 128B header with `+0x10/+0x14 = gVideoWidth/Height` (main screen); for config the cb overwrites the viewArea `+0x20..+0x2c` from `gInViewAreas[gActiveViewArea]` (main) and writes hdr + avcC **unencrypted**; for video it writes `len-4` into `buf[0..3]` (treats the whole frame as one NAL → broken for multi-NAL frames), AES_CTR_Update(ctx+0x168) (or chacha if ctx+0x50), writes hdr + body.
- Shim no longer uses push_frame or Annex-B conversion. `send_to_car()` locks `*(ctx+0x4c)`, sets `hdr[0]=len`, AES-CTR encrypts the video body with the car ctx (`ctx+0x168`), and writes the phone's own 128B header + body to `ctx[0]` fd. Config: phone header (+0x10/+0x14 forced to 1440.0/540.0, viewArea left as the phone set it) + raw avcC, plaintext; cached and sent before the first video frame if it arrived before the car ctx was ready.
- Log: `alt config hdr <hex hdr+0x10..0x2f>` (phone's dims/viewArea), `alt config sent <len>` / `alt config sent late <len>`, `alt frames pushed <n>`.
- Built ax_hook.tar md5 35c6522d (sdDongle 8fc49040 unchanged). libSdH imports libc/pthread only. NOT flashed.

### P4 follow-ups: viewArea, IDR gate, CF release (2026-10-18)

- Config header viewArea semantics confirmed (gInViewAreas fill @writer.c:311 uses CFString keys widthPixels/heightPixels/originXPixels/originYPixels; push_frame_cb maps them; receiver ProcessFrames passes them to ScreenStreamSetViewArea): `+0x10` width, `+0x14` height, `+0x20` originX, `+0x24` originY, `+0x28` viewArea width, `+0x2c` viewArea height (floats). It is the viewArea rect, not the safeArea. Shim now writes 1440/540 and viewArea (0,0,1440,540) for cluster viewArea[0] from audi_displays.json; the safeArea 720×297@(360,87) reaches the phone via /info.
- IDR gate: after the config reaches the car, video is held until a frame containing an IDR NAL (type 5); while waiting, `AirPlayReceiverSessionForceKeyFrame(g_session, 0, 0)` @0x47d1b4 (same call as zjkeyFrameTimerProc @0x4373a4) every 120 frames. Log: `alt force keyframe <n>`, `alt idr after frames <n>`. Uncertain: the forceKeyFrame request has no stream id, so the phone may only refresh the main stream.
- `cluster_setup_to_car`: release `arr`/`sd`/`req` after the plist body is built (body data and HTTP msg left alone, ownership unknown).
- Built ax_hook.tar md5 a6349695 (sdDongle 8fc49040 unchanged). NOT flashed.

### Pre-drive verification pass (2026-10-18)

- Verified: chacha20_poly1305 init/aad/decrypt/verify arg order and ctx size (~0xec, fits 0x200); `s0 == a0` in AirPlayReceiverSessionSetup (our `session` is the receiver's session, so `+0x3ec`/`+0x200` are right); SendCommand @0x474fd0 = `(session, request, completion, ctx)` dispatch_sync on the session queue, NULL completion is what the firmware itself passes.
- Header risk removed: ProcessFrames uses `hdr+6` bit 1 to treat `hdr+8` as a sender-clock timestamp (0x47f374..). The phone's timestamps are in the phone↔dongle clock, so forwarding the phone header to the car was risky. `send_to_car(type, body, len)` now builds a zeroed header like push_frame does (len, type, and for config 1440/540 + viewArea 0,0,1440,540).
- SIGPIPE: socket writes now use `send(..., MSG_NOSIGNAL)`; first failure logged `alt send to car fail <pushed>`.
- showUI: LIVI cpStack.ts:1280-1285 activates the cluster by sending the phone `showUI {uuid: ALT_UUID, url: "maps:/car/instrumentcluster/map"}` + `forceKeyFrame {params:{uuid: ALT_UUID}}`. sdDongle has no showUI, and its ForceKeyFrame @0x47d1b4 sends no params (main only). Shim `send_phone_cmd()` builds `{type, params:{uuid, url?}}` (keys: type 0x52e300, params 0x52e490, uuid 0x5210ac, url 0x52e558 — same layout as AirPlayReceiverSessionRequestUI @0x47d4fc) and calls SendCommand from the sink thread: showUI right after the phone's 111 connection, forceKeyFrame{uuid} while waiting for an IDR. Log: `alt showUI err <0=ok>`, `alt force keyframe err <0=ok>`.
- Car side (MIBSI libmhi2qcarplaycluster strings): renderer waits for codec config then a complete IDR ("waiting for complete IDR access unit", "cannot prime viewer without codec configuration") — matches the config-then-IDR gate.
- Built ax_hook.tar md5 06349f23 (sdDongle 8fc49040 unchanged). NOT flashed.

## 2026-10-19 — CONFIRMED IN CAR: CarPlay maps on the Virtual Cockpit

- Owner flashed ax_hook.tar md5 06349f23. Google Maps shows on the VC, quality the same as wired, steering-wheel zoom in/out works.
- Log `captures/wireless/log_20261019_115910/clusterp4e.bin` (zip after a text header; extracted to `x/`): `alt showUI err0`, `pairVerifySession set1` (ChaCha path was required, the AES path was the bug), `chacha verify err0`, decrypted video `00 00 04 65` = AVCC IDR, `idr after frames0` (no keyframe request needed), `config sent40`, ~3800 frames pushed, no `send to car fail`.
- The phone's config header has +0x10/+0x14 and +0x28/+0x2c = 1440.0/540.0 (same values we write). Byte 6 = 0x16/0x56 (timestamp bit set), so rebuilding a zeroed header for the car was justified.
- Also seen: a phone stream SETUP with type 101 (passes through untouched).
