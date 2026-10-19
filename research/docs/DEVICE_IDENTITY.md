# Device Identity — Smart Box 6081

| Field | Value | Source |
|---|---|---|
| Case label / branding | Smart Box 6081 | owner |
| Wi-Fi SSID | `SmartBox_6081`, WPA2, password `12345678` (from iPhone) | owner |
| Dongle IP | `192.168.200.1` (DHCP pool 192.168.200.0/24, no router option) | nmap sweep + ARP |
| Subnet | 192.168.200.0/24 | DHCP |
| Wi-Fi MAC / OUI | `xx:xx:xx:xx:xx:xx` (OUI vendor not identified yet) | ARP |
| Open TCP ports | 80 (lighttpd 1.4.76), top-1000 only | nmap -sV |
| Web UI | http://192.168.200.1/ (lighttpd), config + factory reset + online update | web UI screenshot |
| Firmware version (UI) | System `202510170926CA`, Protocol `20251013103649` | web UI screenshot |
| USB VID:PID | `05ac:12a8` (spoofed Apple iPhone) | `captures/usb_20260927_145559/descriptors_all_configs.txt` |
| USB manufacturer / product | `Apple Inc.` / `iPhone`, serial `<device-uuid>`, bcdDevice `0x1001` | same |
| USB interfaces | 4 configs: PTP; iPod USB Interface (Audio+HID); PTP+usbmux; PTP+usbmux+Apple USB Ethernet | same, see `docs/USB.md` |
| Bluetooth | `SmartBox_6081`, `XX:XX:XX:XX:60:81`, HFP | Mac `system_profiler SPBluetoothDataType` |
| Platform (vendor) | `platform:AX1800M`, `custom:suding` | `getversion.cgi` |
| Device UUID | `<device-uuid>` (= USB serial) | `getversion.cgi` |
| Not Carlinkit | Carlinkit is ARM on 192.168.50.x; this is MIPS on 192.168.200.x | comparison with `notes/upstream-research.md` |
| SoC | unknown; userland is MIPS32 rel2 little-endian, glibc `/lib/ld.so.1` | `file` on `sdDongle` |
