# USB — Smart Box 6081 as seen by a USB host (Mac)

Capture: `captures/usb_20260927_145559/` (`descriptors_all_configs.txt` = all configurations via GET_DESCRIPTOR, read-only).

## Device descriptor

| Field | Value |
|---|---|
| VID:PID | `05ac:12a8` (Apple, iPhone) |
| Manufacturer / Product | `Apple Inc.` / `iPhone` |
| Serial | `<device-uuid>` (24 hex, no dash — does not match real iPhone UDID formats: 40 hex or `XXXXXXXX-XXXXXXXXXXXXXXXX`) |
| bcdUSB / bcdDevice | 2.00 / `0x1001` |
| Speed | High-speed 480 Mb/s |
| Configurations | 4 |

## Configurations

| # | Name | Interfaces |
|---|---|---|
| 1 | PTP | IF0 06/01/01 Still Image (PTP) |
| 2 | iPod USB Interface | IF0 01/01 Audio Control, IF1 01/02 Audio Streaming (PCM, 8–48 kHz), IF2 03/00/00 HID (report desc 208 bytes — iAP over HID) |
| 3 | PTP + Apple Mobile Device | PTP + IF1 ff/fe/02 Apple USB Multiplexor (usbmux) |
| 4 | PTP + Apple Mobile Device + Apple USB Ethernet | PTP + usbmux + IF2 ff/fd/01 Apple USB Ethernet (alt 0/1/2) |

## Interpretation

- The dongle does **not** use a vendor-specific transport toward the car. It impersonates an iPhone at the USB level with the same configuration layout as a real iPhone. (confidence: high — descriptors)
- The dongle presents no Carlinkit-style `1314:152x` identity to a generic host. (confidence: high for Mac host; the car may trigger a different mode)
- Real wired CarPlay on most head units uses Apple's USB role-switch: the car sends a vendor request, the iPhone becomes USB host and the car exposes iAP2 + CDC-NCM. The dongle therefore almost certainly also supports role switching toward the Audi. **Not observed yet** — the Mac never issues that request, and we did not send it.
- Consequence: toward the Audi the dongle acts as the "iPhone" in the CarPlay session. The Audi will advertise its displays (including the AltScreen) to the dongle, not to the real phone. The dongle decides what it tells the real iPhone. This supports investigating Hypotheses A/E first.
