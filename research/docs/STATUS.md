# Status update — 2026-10-19: GOAL REACHED (CarPlay maps on the Virtual Cockpit, wireless)

- **Confirmed in-car (owner, 2026-10-19):** Google Maps (CarPlay) shows on the Audi Virtual Cockpit through the Smart Box. Picture quality is the same as with a cable, and steering-wheel zoom in/out works. Build `firmware/modified/ax_202609051445_hook/ax_hook.tar` md5 `06349f236fb6fd15e37e9fae55c1d002` (sdDongle md5 `8fc49040…`, only `libSdH.so` differs from the step-1 build). Log: `captures/wireless/log_20261019_115910/` (`altscreen.log` extracted under `x/`).
- **What it took (P4 final):**
  - The phone→dongle 111 stream is **ChaCha20-Poly1305 per frame** (`pairVerifySession` set), not AES-CTR: key `GetStreamSecurityKeys`@0x474254 (DataStream-Salt<connID> / DataStream-Output-Encryption-Key), AAD = 128B header, 16B tag, 64-bit LE nonce. Config frames are plaintext avcC.
  - The shim sends frames to the car itself (`send_to_car`) instead of `carplay_reverse_video_push_frame`. It builds a zeroed 128B header (len, type; config gets 1440/540 + viewArea 0,0,1440,540), uses AES-CTR on video with the car ctx (`ctx+0x168`), and keeps the AVCC body unchanged.
  - It sends the phone `showUI {uuid cluster, url maps:/car/instrumentcluster/map}` (LIVI flow) when the 111 stream connects. It holds video until config + IDR are sent.
- **Log evidence:** `alt showUI err0`, `alt pairVerifySession set1`, `alt chacha verify err0`, `alt vid dec 00 00 04 65…` (IDR), `alt config sent40`, `alt idr after frames0`, `alt frames pushed` climbing to 3779+, no send failures.
- **Open / next:** behaviour across reconnects and VC view changes is not yet characterised. The car→dongle cluster commands (updateViewArea/forceKeyFrame/stopUI) are not relayed. The leftover leak (HTTP msg/body per cluster SETUP) is still there.

# Status update — 2026-10-18 (step 1 complete)

- **Step 1 DONE, confirmed in-car.** The `hook` build (`firmware/modified/ax_202609051445_hook/`, `scripts/build_hook.py`) makes central CarPlay work AND the phone set up and stream the cluster video (type 111), which the dongle currently receives and discards. Verified: `altscreen.log` shows `alt connected` then a running total climbing past 5.5 MB of 1440×540 cluster video.
- **How it works (new mechanism — a real C library, not instruction patches):**
  - `shim/altscreen.c` built with `zig cc -target mipsel-linux-gnueabihf.2.17 -mcpu=mips32r2` → `libSdH.so` (o32/mips32r2/hard-float, matches vendor libs).
  - sdDongle edits (all in `build_hook.py`): the 5 `patch_altscreen.py` word-patches (nostrip + enabledFeatures→altScreen, so the phone requests 111); redirect the single Setup caller `bal`@0x46c2fc → `jalr t9`; inject `DT_NEEDED libSdH.so` + `DT_RUNPATH $ORIGIN`.
  - The shim's constructor overwrites GOT[0x568f38] (Setup) with its own `shim_session_setup`, guarded by a check that the slot still holds 0x477fd4 — so if the library ever fails to load, `jalr t9` calls the original and central CarPlay is unaffected (automatic fallback, no reflash needed).
  - `shim_session_setup` strips the 111 entry from `streams`, calls the original Setup with the rest, then opens a sink via the dongle's own `ServerSocketOpen` (same address family as the main screen — the data link is IPv6) and appends `{type:111, dataPort}` to the response. A detached thread drains/discards the video.
- **P3 DONE, confirmed in-car (2026-10-18).** `altscreen.log`: `cluster SETUP sent`→`cluster car dataPort 6100`→`cluster SETUP replied`→`cluster connected to car 6100`→`cluster ctx ready`. The car accepts type 111, returns its cluster dataPort, and the dongle holds an open AES-CTR socket + fully-initialised client ctx (`g_cluster_ctx`). The phone keeps streaming 111 into our sink (still discarded), so the VC still shows Audi maps until P4.
- **P3 build detail:** the shim sends a type-111 client SETUP to the car (reimplemented `AirplayClientSendCmdSetupScreen` with `type=0x6f`, cluster uuid `b7e6c5a0-2222-4000-8000-000000000002`, own response callback), connects an AES-CTR socket to the car's cluster dataPort, and stores the cluster ctx in `g_cluster_ctx` for P4. Additive-only: sdDongle is byte-identical to the confirmed step-1 build; only `libSdH.so` changed, so the fallback is intact. Test markers in `altscreen.log`: `cluster SETUP sent`→`cluster car dataPort`→`cluster connected to car`→`cluster ctx ready`. Payoff test: does the car accept 111 and does the VC react (leave Audi maps / go blank-waiting).
- **P4 BUILT (not yet flashed):** `sink_thread` now decrypts the phone's 111 frames (receiver AES-CTR key via `AirPlay_DeriveAESKeySHA512ForScreen(session+0x200,…,connID111)` + continuous `AES_CTR_Update`) and forwards them to the car via `carplay_reverse_video_push_frame(g_cluster_ctx, body, len, isConfig)` @0x431698 (video NAL length-prefixes converted to Annex-B start codes to match the main-screen path). sdDongle still byte-identical; only `libSdH.so`. Markers: `alt decrypt ready`/`alt frames pushed <n>`; `alt config bytes <hex>` captures the config format. **Open risk:** config (type-1) push format uncertain — may need one iteration using the captured hex.
- **Daily-use state:** the `hook` build keeps central CarPlay fully working, so it is safe to leave installed. The VC just doesn't yet show CarPlay. For pure stock, reflash `firmware/vendor/`.

# Status & verdict — 2026-09-27

## Root cause (confirmed, static + runtime)
Wireless CarPlay through the Smart Box 6081 does not drive the Audi Virtual Cockpit because the dongle advertises only ONE display (main, 1024×480) to the iPhone. The iPhone therefore never produces the instrument-cluster (altScreen, stream type 111) video. The dongle forwards only stream type 110 to the car. The car (MHI2Q + MIBSI) is ready and works with a wired iPhone.

## Feasibility of a dongle firmware fix
- Not achievable by configuration (`/etc/config.ini` / ark_get_info) — no cluster/second-display key exists.
- Achievable only by a substantial binary rewrite of `sdDongle` (MIPS32, stripped): add 2nd display to receiver `/info`, make the receiver screen session non-singleton to accept a 2nd inbound stream, add a client type-111 SETUP path bound to a cluster UUID (not currently stored), and plumb frames. High effort, meaningful brick risk, uncertain payoff. Key unknown: the display `features` value that makes the phone open a type-111 stream.

## Update/flash mechanism (understood, not yet exercised with a custom image)
Plain GNU tar (`sdDongle` + 4 `libSd*.so`), no signature. Installed via dongle web server: chunked `POST /cgi-bin/downfile.cgi` (10 KiB, last chunk carries our own MD5), then `submition.cgi`, then `reboot.cgi`. Integrity = caller-supplied MD5 only (no authenticity). Stock vendor packages held in `firmware/vendor/` for recovery. Recovery-through-webserver is assumed (lighttpd separate from sdDongle) but NOT proven; the Wi-Fi AP owner (system vs sdDongle) is the main brick risk if a bad sdDongle is flashed.

## Options
1. Vendor route (most promising, lowest risk): the code already advertises the instrument-cluster URL + altScreen to the car, so cluster support is partially built. Ask vendor/reseller for a build/config with cluster for Audi MHI2Q.
2. Dynamic analysis before any patch: capture a real multi-display `/info` and confirm whether the Audi even offers a 2nd display to the dongle; resolve the type-111 feature-bit question.
3. Non-dongle fallback: MMI-Mirror-style mirroring of the center screen to the VC (different approach, not native secondary nav).
4. Attempt the full binary rewrite (highest effort/risk).
