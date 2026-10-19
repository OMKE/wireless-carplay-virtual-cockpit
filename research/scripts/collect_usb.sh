#!/usr/bin/env bash
set -u
OUT="captures/usb_$(date +%Y%m%d_%H%M%S)"
mkdir -p "$OUT"
system_profiler SPUSBDataType >"$OUT/system_profiler_usb.txt" 2>&1
system_profiler SPUSBHostDataType >"$OUT/system_profiler_usbhost.txt" 2>&1
ioreg -p IOUSB -l -w 0 >"$OUT/ioreg_iousb.txt" 2>&1
ioreg -r -c IOUSBHostDevice -l -w 0 >"$OUT/ioreg_hostdevice.txt" 2>&1
ioreg -r -c IOUSBHostInterface -l -w 0 >"$OUT/ioreg_interfaces.txt" 2>&1
ifconfig >"$OUT/ifconfig.txt" 2>&1
networksetup -listallhardwareports >"$OUT/hwports.txt" 2>&1
log show --last 2m --predicate 'subsystem CONTAINS "usb" OR process == "kernel"' --style compact 2>/dev/null | grep -iE "usb|ncm|ecm|rndis|attach" | tail -200 >"$OUT/kernel_log.txt"
echo "Output in $OUT"
grep -E '"(idVendor|idProduct|USB Product Name|USB Vendor Name|kUSBSerialNumberString|bInterfaceClass|bInterfaceSubClass|bInterfaceProtocol|bcdDevice)"' "$OUT/ioreg_iousb.txt" "$OUT/ioreg_interfaces.txt" | sort -u | head -80
