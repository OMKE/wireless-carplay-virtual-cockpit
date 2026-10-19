import sys
import usb.core
import usb.util

VID = int(sys.argv[1], 16) if len(sys.argv) > 1 else 0x05AC
PID = int(sys.argv[2], 16) if len(sys.argv) > 2 else 0x12A8

dev = usb.core.find(idVendor=VID, idProduct=PID)
if dev is None:
    sys.exit("device not found")

def s(i):
    if not i:
        return ""
    try:
        return usb.util.get_string(dev, i)
    except Exception as e:
        return f"<{e}>"

print(f"Device {VID:04x}:{PID:04x} bcdUSB={dev.bcdUSB:04x} bcdDevice={dev.bcdDevice:04x} class={dev.bDeviceClass:02x}/{dev.bDeviceSubClass:02x}/{dev.bDeviceProtocol:02x} numConfigs={dev.bNumConfigurations}")
print(f"  manufacturer={s(dev.iManufacturer)!r} product={s(dev.iProduct)!r} serial={s(dev.iSerialNumber)!r}")
for ci in range(dev.bNumConfigurations):
    raw = dev.ctrl_transfer(0x80, 6, (2 << 8) | ci, 0, 9)
    total = raw[2] | (raw[3] << 8)
    raw = bytes(dev.ctrl_transfer(0x80, 6, (2 << 8) | ci, 0, total))
    print(f"\nConfig index {ci}: value={raw[5]} iConfiguration={s(raw[6])!r} attrs={raw[7]:02x} maxPower={raw[8]*2}mA len={total}")
    print("  raw:", raw.hex())
    p = 0
    while p < len(raw):
        l, t = raw[p], raw[p + 1]
        d = raw[p:p + l]
        if t == 4:
            print(f"  IF {d[2]} alt {d[3]} eps={d[4]} class={d[5]:02x}/{d[6]:02x}/{d[7]:02x} name={s(d[8])!r}")
        elif t == 5:
            print(f"     EP {d[2]:02x} attr={d[3]:02x} maxpkt={d[4] | (d[5] << 8)}")
        elif t == 0x0B:
            print(f"  IAD first={d[2]} count={d[3]} class={d[4]:02x}/{d[5]:02x}/{d[6]:02x} name={s(d[7])!r}")
        elif t == 0x24:
            print(f"     CS_INTERFACE {d.hex()}")
        elif t != 2:
            print(f"     desc type {t:02x} {d.hex()}")
        p += l
