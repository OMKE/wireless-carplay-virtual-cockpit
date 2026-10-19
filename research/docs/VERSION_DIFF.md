# Version Diff: ax_202607232244 → ax_202609051445 (sdDongle)

Comparison of the two stock firmware `sdDongle` binaries we hold. Method: size/md5,
human-readable string diff, then targeted MIPS disassembly of changed regions.
Ledger tags: **[OBS]** observed in binary, **[INF]** inference, **[UNK]** unknown / needs runtime proof.

## Binaries

| | old | new (on device) |
|---|---|---|
| version | 202607232244 (Jul 23) | 202609051445 (Sep 5) |
| size | 1421168 | 1422096 (+928) |
| md5 | 5a758ea4… | e28e0ae7… |
| arch | MIPS32 rel2 LE, stripped | same |

gp = 0x570c30 (.got 0x568c40 + 0x7ff0). String base = 0x520000 (GOT slot 0x568c5c → 0x51fff8+8).

## [OBS] New human-readable strings (new only; nothing removed)

```
[Suding-%s] wlcp add viewAreas
[Suding-%s] iap2_wifi_start:%d
insmod/rmmod /usr/lib/cdc_ether.ko   (USB-ether driver)
```

## [OBS] New CarPlay display-capability subsystem in airPlayGetProperty (0x43e968–0x43f6ec)

The new firmware added a block (≈0x43f440–0x43f6ec) that builds a mutable CFArray and
appends AirPlay secondary/zone-display capability keys, each gated by a `.bss` flag byte:

Keys (CFL strings, base+off):
```
0x3370 uiContext          0x3398 cornerMasks       0x33c4 uiContextLastOnDisplayURLs
0x3384 viewAreas          0x33ac focusTransfer
URL schemes: 0x33e8 maps:  0x33f8 mobilephone:  0x3410 messages:  0x3424 nowplaying:
```

Helpers resolved via GOT: `-0x7e04` = CFArrayCreateMutable (0x492748),
`-0x7f5c` = CFArrayAppendValue (0x4929b4), `-0x7e08` = array callbacks (0x5630e4).

Flag bytes (.bss), read in airPlayGetProperty:
```
0x56b484  (-0x7888 gp)  gates uiContext
0x56b481  (-0x75ac gp)  gates viewAreas       ← "wlcp add viewAreas" log
0x56b480  (-0x75a8 gp)  gates cornerMasks
0x56b483  (-0x75b0 gp)  gates focusTransfer / URL block
```

## [OBS] Only one writer of a flag

`0x429198` (in `AirplayClientSendCmdRecord`, 0x428420): sets flag `0x56b484` = 1
unconditionally, but only reached after a preceding call at `-0x7f34($gp)` returns
nonzero (`$19 != 0`) at 0x42918c. No byte-store to 0x56b480/481/483 was found in a
direct `sb` scan — [UNK] how those three are set.

## [INF] Interpretation

- The new firmware already **knows how** to advertise the exact multi-display
  capabilities an instrument-cluster / AltScreen needs (viewAreas, uiContext,
  cornerMasks, focusTransfer). The old firmware does not.
- These keys are emitted **conditionally**, behind flags that appear tied to a
  capability negotiation (the `-0x7f34` call result), not to a simple config toggle.
- This reframes the goal: forcing a 2nd display through (nostrip) may be insufficient
  if these per-display capability keys are not also present/enabled.

## [UNK] Open questions (need runtime proof — do not assume)

1. What property key does the airPlayGetProperty capability-array branch serve, and
   does its output reach the phone-facing `/info`?  [UNK]
2. What sets flags 0x56b480/481/483, and under what negotiation?  [UNK]
3. Are these flags OFF in our failing session? (Would explain why VC gets no usable
   cluster surface.)  [UNK] — target of the diagnostic build.
4. Does the capability-array feed the `displays[*]` entries or a separate top-level
   capability?  [UNK]

## Next

- **Diagnostic build**: log, at airPlayGetPropertyFromNativeHU read-site and at the
  flag reads, the display count from nativeDict.plist and the 4 flag byte values.
  Flash → reproduce → pull log → resolve UNK #2/#3 with evidence, not inference.
