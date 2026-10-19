# Initial Research Plan — Smart Box 6081 CarPlay Secondary Display

## Goal

Make wireless CarPlay through the Smart Box 6081 deliver the native CarPlay secondary (instrument-cluster / AltScreen) display to the Audi MHI2Q Virtual Cockpit, exactly as wired CarPlay already does.

## Fixed facts

| Fact | Status |
|---|---|
| Vehicle: Audi A5 F5/B9 2017, MHI2Q `MHI2Q_ER_AUG22_P5092`, MU 1329, Virtual Cockpit | given |
| Audi AltScreen patch installed | given |
| Wired iPhone → MHI2Q: Google Maps in VC, independent of MMI | verified by owner |
| Wireless iPhone → Smart Box 6081 → MHI2Q: MMI CarPlay works, VC falls back to OEM map | verified by owner |
| Audi side is out of scope — no writes to MHI2Q | rule |

## Working model (to be confirmed, not assumed)

Dongles in this class are believed to be a CarPlay man-in-the-middle:

```
iPhone ──(Wi-Fi AirPlay/CarPlay + BT iAP2)──> dongle: acts as CarPlay RECEIVER (car) toward phone
                                              dongle: acts as CarPlay SENDER (iPhone) toward car
dongle ──(USB: iAP2 + NCM Ethernet, AirPlay/RTSP/RTP)──> MHI2Q
```

If that is right, the dongle builds its own capability description (displays, features) toward the iPhone. The iPhone only creates an alt-screen stream if the receiver it talks to advertises a second display. **This model is unverified for Smart Box 6081** and must be confirmed from USB descriptors and firmware.

## Hypotheses (tested in order)

| ID | Hypothesis | Primary evidence source |
|---|---|---|
| A | Dongle advertises only one display to iPhone | firmware strings/plist templates, dongle logs |
| B | Dongle receives car's second display but filters it | binary analysis of capability parser |
| C | iPhone opens second stream, dongle drops it | dongle socket/process inspection during session |
| D | Single hard-coded video pipeline | binary analysis |
| E | Dongle's emulated iPhone side never accepts car's alt-screen | USB/RTSP traces toward car, binary analysis |

A and E are the cheapest to confirm/refute because they are visible in static firmware.

## Phases and gates

| Step | Action | Risk | Gate to proceed |
|---|---|---|---|
| 1 | Network identity from Mac (IP, MAC, OUI, open ports, web UI) | none (read-only, dongle's own Wi-Fi) | — |
| 2 | USB identity (plug dongle into Mac, read descriptors) | none | — |
| 3 | Match to known platform (Carlinkit/CPC200 etc.), find firmware | none | identifiers from 1–2 |
| 4 | Obtain stock firmware image (vendor update file) + SHA-256 | none | — |
| 5 | Offline extraction and static analysis | none | stock image |
| 6 | Runtime read-only inspection (shell if one exists legitimately) | low | known recovery path |
| 7 | Reversible prototype (RAM/tmpfs/LD_PRELOAD/config) | medium | RECOVERY.md complete, stock image verified |
| 8 | Persistent firmware change | high | prototype works + tested recovery |

No step from 6 onward runs without an explicit written note of: what is modified, why, how it is restored, what could brick.

## Session 1 (now)

1. Join the Smart Box Wi-Fi from the Mac.
2. Run `scripts/collect_network.sh` → `captures/wireless/session1/`.
3. Install `nmap` (Homebrew) and run the scan against the dongle IP only.
4. Plug the dongle into the Mac by USB, run `scripts/collect_usb.sh`.
5. Photograph the case label and the web UI "About/Version" page.
6. Summarize in `docs/DEVICE_IDENTITY.md`, choose next step.

## Tooling needed

| Tool | Purpose | Status on Mac |
|---|---|---|
| nmap | port scan | installed (brew) |
| binwalk | firmware extraction | installed (brew) |
| Wireshark/tshark | packet captures | tshark installed (brew); capture needs ChmodBPF or sudo |
| Ghidra 12.1.4, rizin | static RE | installed (brew) |
| python3, curl | scripts | installed |
| libusb + pyusb | USB descriptor dump | installed (brew, tools/venv) |
