# Upstream research: CarPlay altScreen (instrument cluster) through a wireless dongle to Audi MHI2Q

Research date: 2026-09-27. Read-only. Local clones (full history) are in
`<scratch>/repos/`:
`wireless-carplay-dongle-reverse-engineering` (ludwig-v, 248 commits), `MHI2Q-CarPlay-AltScreen` (yuedizhibo, 9 commits),
`MHI2Q-CarPlay-MMI-Mirror` (Lanye-z, 35 commits; the `MHI2Q-CarPlay-RGI-MMI-Mirror` dir is the same repo via the old name/redirect),
`mib2q-carplay-rgi` (luka-dev, 246 commits), `LIVI` (f-io, 1322 commits), `catplay` (catplay-labs, 31 commits),
`CPC200-CCPA_resources` (lvalen91, 87 commits).

Confidence scale: **High** = read directly in source/binary/log; **Medium** = stated by a credible RE project but not re-verified here; **Low** = forum/review/snippet or inference.

---

## Summary: top 10 facts

1. **On the wire, altScreen is: `/info` `displays[]` holds a second entry with `type: 111` plus its own `uuid`, and `/info` `features` has bit 26 set. The iPhone proposes `"altScreen"` in the session-level RTSP SETUP `features` array. The receiver must echo `"altScreen"` in the SETUP response's `enabledFeatures`. The iPhone then sets up a second screen stream with `type: 111` (main screen is 110), and the receiver sends `showUI` with `uuid: <alt uuid>, url: maps:/car/instrumentcluster/map`.** Confidence: High. Sources: LIVI `src/main/services/projection/driver/cp/stack/getInfo.ts` (STREAM_TYPE_ALT_SCREEN=111, ALT_UUID, `displays.push(...)`) and `cpStack.ts` lines ~741-743 (`feats.push('altScreen'); resp.enabledFeatures = feats`), lines ~1280-1285 (showUI/forceKeyFrame to ALT_UUID). https://github.com/f-io/LIVI
2. **Stock Audi MHI2Q (libairplay 210.81) does not support altScreen at all.** `AirPlayReceiverSessionSetup` handles stream types 100, 101 and 110 only. Type 111 falls into "Unsupported stream type". There are no `enabledFeatures`, `altScreen` or `viewAreas` strings and no alt-display helpers. So the working wired setup is **necessarily a modified head unit** (almost certainly yuedizhibo's AltScreen mod), not stock behaviour. Confidence: High that stock lacks it (two independent RE sources). Sources: luka-dev/mib2q-carplay-rgi `docs/hook/integration-seam.md` ("type 111 hits the unsupported branch") and commit `e9c2b9a` `docs/altscreen_gate_analysis.md`. The yuedizhibo mod hooks exactly these gates (fact 3).
3. **The yuedizhibo MHI2Q AltScreen mod patches the car's own AirPlay receiver.** Its `libcarplay_altscreen.so` (injected into libairplay/dio_manager) does the following:
   - appends a type-111 display dict to `/info` `displays` (`ALTINFO built type=%u %ux%u@%u uuid=%s features=0x%x`)
   - sets `/info` features bit 26 (`FEATURES 0x%llx -> 0x%llx altScreen_bit26=1`)
   - patches the SETUP response `enabledFeatures` (adds `altScreen`, `viewAreas`)
   - implements a private type-111 stream (`carplay111_h264` shared memory) rendered to the Virtual Cockpit
   - opens a pf firewall hole for the 111 data port on `carplay0`

   The alt UUID is `b7e6c5a0-2222-4000-8000-000000000002`, identical to LIVI's ALT_UUID. Main type 110 is left untouched. Confidence: High (strings in the shipped binary, plus the controller script). Sources: `Toolbox/carplay_alt_screen/universal/libcarplay_altscreen.so`, `Toolbox/scripts/altscreen_chain_test_known.sh` lines 170-171, 841-863, `mirror_display/release/BUILD_INFO.txt`. https://github.com/yuedizhibo/MHI2Q-CarPlay-AltScreen
4. **Captured logs from a real Carlinkit U2W dongle (fw 2023.12.28.1212) and U2AC (2024.07.20.0937) show the dongle never enables altScreen toward the iPhone.**
   - The iPhone's session SETUP proposes `features: ["uiContext","viewAreas","cornerMasks","focusTransfer","altScreen","enhancedSiri"]`.
   - The dongle (`AppleCarPlay`, "AirPlay starting version 320.17") answers with only `{eventPort, timingPort}`. There is no `enabledFeatures`.
   - It registers exactly one screen (`Registered screen e5f7a68d-... 800 x 480, 30 FPS`), and only `Setup stream type: 110` follows.

   Confidence: High for these firmware builds. Unknown for the Smart Box. Sources: `Extracted/U2W_2023.12.28.1212/var/log/box_last_reboot.log` lines ~1392-1399, 1560-1590, 1849-1915; `Extracted/U2AC_2024.07.20.0937/var/log/box_last_reboot.log` lines 1199-1203, 1606-1630, 1896-1930 (commit `2f41256`, `56ed510`/`1aa5633`).
5. **The dongle is two cooperating CarPlay endpoints.**
   - **iPhone-facing receiver:** `AppleCarPlay`, built from Apple's CarPlay reference receiver ("CarPlayDemoApp", AirPlay 320.17), plus `ARMiPhoneIAP2` for iAP2.
   - **Car-facing emulated iPhone:** `fakeiOSDevice`, an AirPlay *sender* over USB NCM toward the car. In the same log it requested only `streams: [{type: 110}]` from the car.
   - **USB/host glue:** `ARMadb-driver`. It also owns the host protocol for Autokit models.

   The car's `/info` is cached by the dongle as `HUDinfo.plist` and fed into AppleCarPlay (`_getHUDinfo_*`). Confidence: High (process list and log tags). Source: same U2W log lines 473, 891, 1395, 1420-1425, 866-878.
6. **Newer Carlinkit firmware DOES contain altScreen receive logic, but only in the "Autokit/host" product mode (CPC200-CCPA / A15W, firmware 2025.10.15.1127).** In that mode the dongle is the CarPlay receiver for an Android or Linux host app, not a bridge to an OEM CarPlay car.
   - It has `_AltScreenSetup/_AltScreenStart/_AltScreenThread`, `AirPlayAltScreenReceiver` and `g_bSupportNaviScreen`.
   - The type-111 stream is re-framed to the host as USB message `0x2C` (NaviVideoData/AltVideoFrame).
   - It is gated by a persistent `AdvancedFeatures=1` unlock (writes `/etc/RiddleBoxData/HU_NAVISCREEN_INFO`), plus `naviScreenInfo{width,height,fps}` in BoxSettings (USB 0x19), plus the command 508 handshake.
   - Log evidence from that project: `[AirPlay] ### Setup stream type: 111`, `Alt screen receiver set up on port 49281`.

   Confidence: Medium-High (documented RE by lvalen91, and independently used by LIVI's former dongle driver). Sources: lvalen91/CPC200-CCPA_resources `documentation/02_Protocol_Reference/video_protocol.md` lines 129-300, 745-812; `documentation/01_Firmware_Architecture/configuration.md` 760-1050; `documentation/06_Reference/firmware_internals.md` 83-110. LIVI commit parent of `72f26277`, `src/main/services/projection/driver/dongle/protocol/wire.ts` (`ClusterVideoData = 0x2c`, `ClusterFocusRequest = 0x6e`) and `sendables.ts` (`naviScreenInfo`, `HU_NAVISCREEN_*_INFO`).
7. **No evidence was found that any Carlinkit OEM-bridge firmware (U2W/U2AW/U2AC) forwards a type-111 stream to an OEM car.**
   - The only plaintext (decrypted) set in ludwig-v's repo is U2AW Autokit 2024.01.10.0953. Its `AppleCarPlay`, `fakeiOSDevice`, `ARMiPhoneIAP2` and `ARMadb-driver` contain no `altScreen`, `AltScreen`, `NaviScreen` or `NAVISCREEN` strings.
   - `fakeiOSDevice` only knows `kAirPlayStreamType_MainAudio/AltAudio` plus a single screen.
   - The other extracted binaries are packed (UPX/AES), so later builds could not be string-checked.

   Confidence: High for 2024.01.10 Autokit; not determinable for newer or packed builds. Source: `Firmware/U2AW/_AUTOKIT/2024.01.10.0953/Decrypted/*` (commit `4d9c6fb`).
8. **The open-source replacement firmware CatPlay (Carlinkit Mini Ultra, Ingenic X1600) passes the car's `/info` `displays` and `features` through to the iPhone unchanged. However:**
   - it has `AltScreen = 111` **commented out** in its StreamType enum (under "Modern CarPlay");
   - it returns an empty `enabledFeatures`;
   - its C2A car manager uses only `info.displays.first()`.

   So it does not support altScreen yet, but it is the most plausible codebase to add it to. It lists "Audi/Porsche ~2020 HARMAN MIB2/MHI2" as **not compatible** (the car resets dongle power after role switch). Confidence: High (source). Sources: catplay `carplay/catplay_carplay/src/msg/streams.rs` lines 13-24, `carplay_rx/sink/receiver.rs` ~884, `c2a/catplay_c2a/src/proxy_rpc/car_manager.rs` lines 85, 400-432, README compatibility table. https://github.com/catplay-labs/catplay
9. **luka-dev (mib2q-carplay-rgi) concluded in April 2026 that "no wireless dongle, present or future, will unlock AltScreen on this generation of HU".** The reasoning is that the car's Cinemo iAP2 SDK cannot emit Identification Param 21/sub 17 (ThemeAssets), and libairplay 210.81 lacks the 111 path. That conclusion concerns a *stock* HU. The yuedizhibo mod later made wired work by patching the HU. Its script states that ThemeAssets injection is "observed only", because LIVI works without ThemeAssets 21/17. Also, the U2W dongle log shows an iOS 15.2 iPhone *proposing* `altScreen` to the dongle anyway. So the "iAP2 ThemeAssets gate" is at least not universally required. Confidence: Medium (conflicting RE claims; the empirical evidence favours "not required"). Sources: mib2q-carplay-rgi commit `e9c2b9a` (README + `docs/altscreen_gate_analysis.md`); MHI2Q-CarPlay-AltScreen `altscreen_chain_test_known.sh` lines 841-845; U2W log line ~1566-1573.
10. **"Smart Box 6081": no public identification was found.** No model, SoC or firmware string was found for "6081". Retail "SmartBox" 2-in-1 adapters advertise a BT name `smartBox-7xx`, 5 GHz Wi-Fi and OTA updates, but the hardware was not identified. Carlinkit-derived firmware now ships on several SoCs:
    - i.MX6UL (classic Carlinkit)
    - Ingenic X1600/"AX1800" (Mini Ultra)
    - Allwinner V851SE/V821 with AIC8800
    - Anyka AK3918 ("VehiConn"/"yunlian" builds; web UI at 192.168.50.100 with `/cgi-bin/getversion.cgi`)

    Confidence: Low for Smart Box, High for the variant list. Sources: https://manuals.plus/smartbox/wireless-carplay-android-auto-usb-dongle-smart-adapter-manual; ludwig-v issues #229, #233; discussions #216, #230.

---

## 1. ludwig-v/wireless-carplay-dongle-reverse-engineering

Repo: https://github.com/ludwig-v/wireless-carplay-dongle-reverse-engineering (about 1.9 GB, 248 commits, last push 2026-07-23). Cloned in full.

### Hardware (README.md)
- SoC: Freescale/NXP **i.MX6 UltraLite** (Cortex-A7, fake "AT91SAM9260" marking).
- Flash: Macronix MX25L12835F 16 MB SPI NOR.
- RAM: 1 Gb.
- Wi-Fi/BT over SDIO: RTL8822BS/CS, RTL8733BS, Fn-Link L287B-SR (Marvell), LGX4358/LGX8354S (Broadcom), IW416 (NXP).
- Product lines:

  | Line | Hardware | Role |
  |--|--|--|
  | U2W | V1/V2/V3 | wired OEM CarPlay → wireless CarPlay |
  | U2AW | V4 | + wireless AA |
  | U2AC | V5 | CarPlay or AA OEM |
  | A15W | CPC200-CCPA | Android/Linux host "Autokit" mode, needs host app |

  Source: `README.md`, `Firmware/README.md`.
- New variants in the issues/discussions:
  - Carlinkit **Mini Ultra**: Ingenic X1600 + AIC8800 (discussion #216).
  - "VehiConn"/"yunlian" builds on Anyka AK3918AV130 with AIC8800D80 (issue #233).
  - Allwinner V851S/V821 builds (discussion #230).
- USB VID/PID: **not found in the repo.** Only the Ingenic recovery ID `a108:eaef` appears (discussion #230).
- Dongle OEM mode enumerates toward the car as an iPhone with CDC-NCM (`cdc_ncm 2-1:1.1 usb0`, U2W log lines ~330-333). The exact VID/PID is not logged there.

### Network / UI
- Web UI at **192.168.50.2** (`Updater-App.md`; SSH `root@192.168.50.2` in `Custom_Firmware/Scripts/Dropbear/README.md`).
- Newer VehiConn/Ultra firmware uses **192.168.50.100** (issues #229, #233; discussion #230).
- The iPhone got 192.168.50.101 in the U2W log.
- SSIDs: set from the car brand at runtime, e.g. `VOLKSWAGEN9A`, pwd `12345678` (U2W log line ~1388). The VehiConn builds use `VehiConn-xxxx` with pwd `88888888` (issue #229).
- Settings live in `/etc/riddle.conf` (`riddleConf --info`, `riddleBoxCfg`), with a key table in `Updater-App.md`.
- Relevant settings:
  - `iAP2TransMode` ("instrument panel sync compatible with some old cars")
  - `HudGPSSwitch`
  - `VideoResolutionWidth/Height`
  - `CarLinkType`
- There is **no altScreen/cluster setting** in that table.

### Partition layout (README.md)
- `mtdparts=21e0000.qspi:256k(uboot),3328K(kernel),12800K(rootfs)`
- rootfs is jffs2 on `/dev/mtdblock2`
- USB stick mounted at `/mnt/UPAN`
- Mini Ultra/AK3918 layouts differ (issue #233 lists UBOOT/ENV/DTB/KERNEL/ROOTFS/DATA).

### Firmware update format and encryption
- `.img` is a tarball.
- Before 2021.03.06 it was obfuscated with a dictionary (`Firmware_Tools/U2W_Decrypt.php` / `U2W_Crypt.php`).
- From 2021.03.06 it is an **AES-encrypted tarball**, with a per-product key: `Firmware_Tools/Firmware{U2W,U2AW,U2AC,HWFS}.sh` using openssl.
- Keys were recovered from UPX-obfuscated binaries that decrypt through `/dev/hwaes` (commits `e836b2a`, `60ab3f6`; README "now pwned in 2025").
- Newer builds use `.hwfs` (`Custom_Firmware/U2AC/README.md`).
- Update procedure: put `<TYPE>_Update.img` / `U2AC_AUTOKIT_Update.img` on a FAT32 USB stick. The web UI also accepts `upload.cgi` (commit `523da87`).
- Device activation is tied to `/etc/uuid_sign`, checked by `fakeiOSDevice` via `/dev/hwaes`. "Nulled" binaries bypass it (`Nulled/README.md`, commit `3630cc3`).

### Root/SSH
- Custom firmware with Dropbear (empty root password) for U2W 2023.12.28.1212, U2AW 2024.01.10.0953 and U2AC (commits `2cac40d`, `3c83500`, `b0e397d`).
- It can run `U2W.sh` from USB.
- Hardware route: SPI flash dump or reflash (`Flash_Dump/README.md`).
- Kernel hardened against strace; a strace-compatible kernel is provided (commit `926576c`).

### Binaries (`/usr/sbin`)
- `ARMadb-driver`, `ARMiPhoneIAP2`, `AppleCarPlay`, `fakeiOSDevice`
- `ARMAndroidAuto`, `ARMandroid_Mirror`, `ARMHiCar`
- `bluetoothDaemon`, `boa`, `hwSecret`, `hwfsTools`, `riddleBoxCfg`, `mdnsd`, `usbmuxd`
- Decrypted set: `Firmware/U2AW/_AUTOKIT/2024.01.10.0953/Decrypted/`.

### Recovery and bricking
- Reflash via SPI programmer (`Flash_Dump/`).
- Cross-flashing matrix in `README.md`: some combinations "Not booting", and activation is lost without the original `uuid_sign`.
- Issue #221 "Bricked CPC200-CCPA" after flashing a vendor-supplied A15W_Update.img (red LED, no Wi-Fi/BT).
- `https://github.com/Quikeramos1/Unbrik-Carlinkit-V3` is linked.

### Requested git history searches
- `git log --oneline | head -100`: done. Latest commit is `b437135` (2026-07-23). Nothing about cluster/altScreen appears in commit messages.
- `git log -S iAP2` / `-S CarPlay` / `-G "display|cluster|secondary|altScreen"`: every hit is a firmware/extraction dump commit (e.g. `2f41256`, `56ed510`, `1aa5633`, `4d9c6fb`, `250f6b3`, `24f87c8`). There is no code or doc commit about secondary displays.
- `git log -S altScreen`: only `2f41256` (U2W 2023.12.28.1212 extraction) and `56ed510` (U2AW/U2AC extraction). Both hits are in `var/log/box_last_reboot.log`, i.e. the logged iPhone feature proposal, not in any binary.

### Issues and discussions
- 71 issues and 96 discussions were listed via `gh`.
- **#149 "Navigation HUD support"**: asks for CarPlay navigation on a secondary display (BMW cluster). ludwig-v: *"Carlinkit only provides a binary file and everything is inside, we can't add new functionalities without reinventing the wheel."* Closed.
- #23: Peugeot 3008 dashboard needs the nav app running and shows nothing via Carlinkit. Moved to discussions, unresolved.
- Discussion #230 (CatPlay release): ludwig-v reports CatPlay does not work on a Stellantis NAC. The CatPlay author mentions an Audi issue ("the same issue you are reporting for Audi").
- No issue or discussion mentions altScreen, Virtual Cockpit or instrument-cluster *video* working through any dongle. Searches for cluster/cockpit/instrument/altScreen/second screen/dashboard/HUD/Audi/Smart Box/navigation returned nothing relevant.

### Mentions of cluster / secondary display / altScreen / "displays" / navigation metadata
- Binaries (decrypted 2024.01.10):
  - `AppleCarPlay` has `displays`, `displayUUID`, `viewAreas`, `add viewAreasArray: %@`, `_getHUDinfo_ScreenSize`, `HU_VIEWAREA_INFO`, `HU_SAFEAREA_INFO`. There is no altScreen or 111.
  - `fakeiOSDevice` has `/info`, `displays`, `uiContext`, `viewAreas`, `_processScreenSetup`, `kAirPlayStreamType_MainAudio/AltAudio`.
- Navigation metadata: `DashboardInfo`/`DashboardData (0x10)`, and the `0x2A` JSON "Navi*" fields exist in the host protocol (LIVI/lvalen91). The OEM route-guidance forwarding path was not examined in detail.

---

## 2. Forks, related projects, and "Smart Box 6081"

- **CatPlay** (https://github.com/catplay-labs/catplay): an open Rust CarPlay transmitter/receiver and a complete C2A firmware for the Carlinkit Mini Ultra (legacy i.MX6UL port being sunset).
  - Altscreen status: see fact 8.
  - Notable commits: `d708fba` ("workaround bug in MIB2/MHI2 that crashes on KeepAlive packets with empty payload"), `1e787d3`/`abaf72c` (CarPlay 210.81 fixes).
  - MHI2 listed as not compatible (power reset after role switch).
- **LIVI** (https://github.com/f-io/LIVI): an open head-unit implementation with native CarPlay, including a cluster.
  - Until commit `72f26277` (2026-09-06) it also drove Carlinkit CPC200-CCPA dongles through the Carlinkit USB protocol.
  - That driver included cluster video (`ClusterVideoData 0x2c`, `naviScreenInfo`).
  - LIVI "Link" now uses a CPC200-CCPA / V821+AIC8800 dongle as a radio/MFi peripheral (commits `f988f566`, `df2854ff`).
- **lvalen91/CPC200-CCPA_resources**: extensive A15W firmware RE, including altScreen gating (fact 6). It also documents firmware AES keys per product; they are not reproduced here.
- Other related repos:
  - lvalen91/carlink: Android host app, forwards 0x2C to a cluster display.
  - abuharsky/carplay: docs mirror.
  - segfly/carlinkit-modding.
  - Henkru/cplay2air-wifi-passphrase-patch.
  - th1efx/AutoKit-CarPlay (themes).
- **Ottocast / Carlinkit convergence:** "Now ottocast and carlinkit have same firmware" (Zubastic, issue #229). The "cpbox-abroad" OTA host is described as pseudo-official Carlinkit (issue #229 → discussion #216). Confidence: Low-Medium.
- **Smart Box 6081:**
  - Not found as a model or firmware identifier.
  - Retail "SmartBox" 2-in-1 manual: BT name `smartBox-7xx`, 5 GHz Wi-Fi, BT 5.0, OTA (https://manuals.plus/smartbox/wireless-carplay-android-auto-usb-dongle-smart-adapter-manual; https://manuals.plus/m/208bea91d0cdb675277a97dc68ed25883a090e8b9de2958091722e9635432fa9).
  - A Kickstarter "Smart-Box" exists (https://www.kickstarter.com/projects/1442262461/smart-box-wireless-carplay-and-android-auto-adapter); its relation to this device is unknown.
  - Suggestion (not verified for this device): try `http://192.168.50.2/` and `http://192.168.50.100/cgi-bin/getversion.cgi` over the dongle's Wi-Fi. That CGI reports `product_Model`, `platform` and `system_version` on VehiConn-family builds (issue #233).

---

## 3. Audi MHI2Q projects

### yuedizhibo/MHI2Q-CarPlay-AltScreen (V2.1, 2026-09-26/27)
- Scope: native CarPlay AltScreen on the Virtual Cockpit for **MHI2Q, CN-region AUG22 firmware** only (README_EN.md).
- Installed via the jilleb/mib2-toolbox green menu. Runtime components:
  - `libcarplay_altscreen.so` (hook)
  - `carplay_hook-basevideo3.jar`, which contains luka-dev's `com/luka/carplay/cluster/*` plus Audi `DisplayManagerMIB2High`/`CombiMapController` replacements
  - `carplay-alt111-mirror-display` (renders decoded 111 frames at 1440x455 into cluster context 80)
  - pf firewall patch
- Wire behaviour, from hook strings (High confidence):
  - `/info` gets a second display dict with keys `uuid, type(111), widthPixels, heightPixels, maxFPS, widthPhysical, heightPhysical, features, primaryInputDevice, viewAreas[ {…, safeArea}], initialViewArea`. UUID `b7e6c5a0-2222-4000-8000-000000000002`.
  - `/info` `features` gets bit 26 (`altScreen_bit26`).
  - The SETUP response `enabledFeatures` gets `altScreen` + `viewAreas`. The array is copied, or the int form is OR-ed. Log: `PHASE=SETUP_ALT_ACCEPTED ALT_FEATURE_NEGOTIATED=YES proof=enabledFeatures_intersection`.
  - It logs `PHONE_REQUESTED altScreen bit in SETUP request`.
  - A stream-level SETUP with type 111 is handled by a private screen stream: `AirPlayReceiverSessionScreen_*` reused, keys derived via `AirPlay_DeriveAESKeySHA512ForScreen`.
  - A string `showUI-alt-uuid-cluster-map-response-status0` is present.
- iAP2: optional ThemeAssets (Param 21/sub 17) synthesis exists (`ARMED_IAP2`, `altscreen_iap2_add_theme_assets`, profile `usbhost_16_5`). The shipping START path sets `IAP2_PROFILE=observe` (no iAP2 mutation). Reason given: *"current LIVI uses USBHost=16 / WirelessCarPlay=24 / VehicleStatus=21 and carries no ThemeAssets 21/17"* (`altscreen_chain_test_known.sh` lines 841-845).
- Wireless adapters are not mentioned. The chain script's version tag is `AUG22_LIVI_TYPE111_...` (LIVI was the protocol reference).

### luka-dev/mib2q-carplay-rgi
- Current branch: route guidance (iAP2 0x5200-series RGD → BAP → cluster maneuver overlay) and HUD. It **does not** implement altScreen (`docs/deploy/session-lifecycle.md` lines 29-35).
- Requires adding `0x5200/0x5203` and `0x5201/0x5202/0x5204` to `dio_manager.json` (README).
- AltScreen history: commit `e9c2b9a` (2026-04-28), `docs/altscreen_gate_analysis.md`, "Branch closed". It compares MHI2Q with MHI3:
  - MHI3 libairplay 450.14.2 has `AirPlayAltScreenDictCreate`, `AirPlayInfoArrayAddScreen`, `AirPlayScreenDictSetViewAreas`, and `enabledFeatures = [altScreen, viewAreas, uiContext, cornerMasks, focusTransfer]`.
  - MHI2Q's 210.81 has none of these.
  - It claims dongles cannot help (see Summary fact 9 for the counter-evidence).
- `docs/re/ios/carkitd-bonjour.md`: iOS 26 vs 27 display-config differences. iOS 27 uses `zoomFactorByDisplayIndex` and a lookup keyed by MFi cert serial + `clusterAssetIdentifier`. It also corrects the advertised cluster physical size to 292x110 mm.

### Lanye-z/MHI2Q-CarPlay-MMI-Mirror (V2.4.1)
- Mirrors the **whole MMI centre display** into the VC map area, independent of the CarPlay altScreen protocol.
- By construction this does not depend on what the dongle negotiates. That is an inference; wireless use is not documented.

### VcMOSTRenderMqb
- Not found (not searched on GitHub beyond the above; no hit came up in these repos).

---

## 4. CarPlay protocol for the secondary/alt screen

Confirmed by source:
- Stream types:

  | Type | Stream |
  |--|--|
  | 100 | main audio |
  | 101 | alt audio |
  | 102 | main high audio |
  | 110 | main screen |
  | 111 | alt screen |

  Sources: LIVI getInfo.ts/cpStack.ts, catplay streams.rs (111 commented), luka-dev gate analysis, and Carlinkit logs showing "Setup stream type: 110".
- `/info` `displays[]` entries: `uuid, type, maxFPS, widthPixels, heightPixels, widthPhysical, heightPhysical, features, primaryInputDevice, viewAreas, initialViewArea, initialURL`. LIVI uses display `features = 0x0A` (hi-fi touch + knobs). Source: LIVI getInfo.ts.
- LIVI's `/info` `features` constant `0x615653aee2` has bit 26 set. The VW HU in the U2W log advertises `features 417758184320` (= `0x6144540380`), which also has bit 26 set. Whether bit 26 alone means altScreen comes from the yuedizhibo strings and the luka-dev RE. Treat the bit-26 = altScreen mapping as **Medium** confidence.
- Session SETUP: the iPhone sends `features` (array of strings). The receiver responds with `enabledFeatures`, and altScreen is active only if echoed. Sources: LIVI cpStack.ts; yuedizhibo strings; luka-dev (`Activate.mm CFArrayContainsValue(..., "altScreen")`, RE-derived).
- Alt-screen control: `showUI {uuid: ALT_UUID, url: "maps:/car/instrumentcluster/map"}`, `stopUI {uuid}`, `forceKeyFrame {uuid}`. Other URLs: `maps:/car/instrumentcluster`, `maps:/car/instrumentcluster/instructioncard` (lvalen91 video_protocol.md).
- Per-stream encryption key: `HKDF-SHA512(pairVerifyShared, "DataStream-Salt"+streamConnectionID, "DataStream-Output-Encryption-Key")` (LIVI cpStack.ts `_setupScreen`).
- Carlinkit A15W log sequence: `Setup stream type: 111` appears before `110` (lvalen91).

Public knowledge (Low-Medium):
- iOS 13 introduced multiple H.264 streams for the instrument cluster (WWDC19 session 252: https://developer.apple.com/videos/play/wwdc2019/252).
- `CPTemplateApplicationInstrumentClusterScene` (iOS 15.4+) lets third-party navigation apps (e.g. Google Maps, Waze) draw on the cluster (https://developer.apple.com/documentation/bundleresources/information-property-list/uiapplicationscenemanifest/cpsupportsinstrumentclusternavigationscene). This fits the user's Google Maps observation.
- "Turn-by-turn passthrough" in adapter reviews means iAP2 route-guidance metadata, **not** map video (https://www.carplaylife.com/review/the-best-multi-user-wireless-carplay-android-auto-adapters-tested-2026/).

Speculation, not confirmed:
- Whether iOS additionally requires iAP2 ThemeAssets (Param 21/sub 17) or a `clusterAssetIdentifier` for altScreen on newer iOS (26/27) is disputed; see fact 9.

---

## 5. Field reports: dongles and the instrument cluster

- **carplaylife (2026):** tested turn-by-turn metadata passthrough, not map video. Results:
  - CarlinKit 4.0: none.
  - Ottocast Pico / AAWireless Two+: AA only.
  - Ottocast Mini and most others: CarPlay metadata works.
- **VW Atlas forum** (search snippet only; page behind a paywall redirect): "Wireless adapters won't show … in the main gauge cluster screen like the native plug-in CarPlay does… with newer Ottocast adapters, the map does not show in the driver cluster." Confidence: Low. URL: https://www.vwatlasforum.com/threads/carplay-mirroring-to-digital-cockpit.6685/
- **Polestar forum** thread titled "Seeing CarPlay on the instrument panel through wireless connection IS possible" (https://www.polestar-forum.com/threads/seeing-carplay-on-the-instrument-panel-through-wireless-connection-is-possible.15028/). Content not retrievable (paywall redirect), so it is unknown whether a dongle was involved.
- BMW iDrive 8: CarPlay map in the cluster (Apple Maps) on native CarPlay, from a bimmerpost thread snippet (https://g05.bimmerpost.com/forums/showthread/2062634/is-carplay-map-available-in-instrument-cluster). No dongle data.
- drive2.ru: generic threads about CarPlay maps on the dashboard (Range Rover Evoque, Haval). No dongle-specific confirmation (https://www.drive2.ru/l/727660644626615783/).
- **No dongle firmware version was found that adds map video to an OEM car's cluster.** The only confirmed Carlinkit altScreen support is the A15W host mode (fact 6).
- Not searched in depth: 4pda, rennlist, audizine. No results surfaced for those sites in these searches.

---

## Implications for Hypotheses A–E

- **A: dongle doesn't advertise the secondary display to the iPhone. Strongly supported for Carlinkit U2W/U2AC builds.** Evidence:
  - one registered screen (800x480);
  - the SETUP response has no `enabledFeatures`, although the iPhone proposed `altScreen`;
  - no altScreen strings in decrypted 2024.01 AppleCarPlay.

  Newer AppleCarPlay builds *do* contain alt-screen code, gated by `g_bSupportNaviScreen` from `/etc/RiddleBoxData/HU_NAVISCREEN_INFO` (lvalen91). In an OEM-bridge build it is unknown whether anything populates that gate from the car's `/info`. First thing to check on the Smart Box: does its iPhone-facing SETUP response contain `enabledFeatures: [... "altScreen"]`, and does `/info` to the iPhone contain a type-111 display?
- **B: dongle filters it. Plausible/overlapping with A.**
  - `fakeiOSDevice` reads the car's `/info` into `HUDinfo.plist`, and AppleCarPlay consumes selected parts (`_getHUDinfo_ScreenSize/InputFeatures/HardWareAudioLatencies`). This suggests re-synthesis of a single-screen description rather than pass-through (inference, Medium).
  - Contrast: CatPlay copies `displays` and `features` wholesale but still does not echo `enabledFeatures`.
- **C: iPhone creates a second stream and the dongle drops it. Unlikely for Carlinkit-type firmware.** Without `altScreen` in `enabledFeatures` the iPhone never issues SETUP type 111 (no 111 appears in the U2W/U2AC logs). It becomes relevant only if a Smart Box build does negotiate altScreen. The A15W host build shows the receive side can exist ("Alt screen receiver set up on port ...").
- **D: single video pipeline hardcoded. Supported on the car-facing side.**
  - `fakeiOSDevice` has only main-screen setup (`_processScreenSetup`, `streams: [{type:110}]`) and no alt-screen transmitter strings.
  - CatPlay's C2A manager also assumes `displays.first()`.
  - A15W re-frames 111 to USB 0x2C for Autokit hosts; that is not an AirPlay stream to an OEM car.
- **E: USB side doesn't expose the capability to the car. Partly reframed.**
  - The car (with the AltScreen mod) advertises the type-111 display in its `/info`. The dongle, acting as iPhone/sender, has to *request* it: session SETUP with `altScreen` in `features`, then stream SETUP type 111, then `showUI` for the alt UUID.
  - No evidence was found that `fakeiOSDevice` sends any of that.
  - The mod also opens a firewall port for 111 on `carplay0` only when its own 111 path is armed. A dongle-initiated 111 setup would presumably go through the same hook (not verified).
  - The USB transport itself (NCM + iAP2) carries no resolution or display info (lvalen91: "iAP2 carries no resolution").

Net: for Carlinkit-lineage firmware, the failure is on both sides of the dongle (A/B toward the iPhone, D/E toward the car). A fix needs a receiver that advertises and echoes altScreen and accepts 111, **and** a sender that requests 111 from the car and relays frames. Possible routes:
- **CatPlay:** open source, but lacks 111 and MHI2 compatibility.
- **Binary patching** `AppleCarPlay` / `fakeiOSDevice`.
- **MMI-Mirror:** mirror the main screen instead, bypassing the protocol.

---

## Open questions

1. What hardware and firmware is the Smart Box 6081? Identify the SoC, Wi-Fi chip, web UI IP and `getversion.cgi` output. Is it Carlinkit/HeWei lineage (`ARMadb-driver`/`fakeiOSDevice`), VehiConn/yunlian, or something else?
2. Does its iPhone-facing receiver ever put `altScreen` in `enabledFeatures`, or expose a type-111 display in `/info`? This needs a log (Carlinkit keeps `/var/log/box_last_reboot.log`) or a pcap on the dongle's Wi-Fi.
3. Does its car-facing sender forward the car's full `/info` `displays` array, and does it ever issue stream SETUP type 111 or `showUI` on the alt UUID?
4. Do newer OEM-bridge Carlinkit builds (U2W/U2AC after 2024.01, packed binaries) include `_AltScreenSetup` / `g_bSupportNaviScreen` like A15W 2025.10.15.1127? If so, what populates `HU_NAVISCREEN_INFO` in OEM mode?
5. Is iAP2 ThemeAssets (Param 21/sub 17) or `clusterAssetIdentifier` needed for newer iOS (26/27)? The dongle's own iAP2 identification (ARMiPhoneIAP2) is what the iPhone sees in wireless mode.
6. With the dongle, does the car's CarPlay stack apply the AltScreen mod's hooks identically? The mod keys on AirPlay sessions and the `carplay0` interface, so an NCM-connected dongle should look like a wired iPhone. Not verified.
7. VcMOSTRenderMqb: not located. 4pda, rennlist and audizine: not searched in depth.
