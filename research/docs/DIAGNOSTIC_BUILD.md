# Diagnostic Logging Build — spec (ready to build)

Goal: replace guessing with runtime evidence. Answer the open [UNK] from
`docs/VERSION_DIFF.md` and the nostrip failure, with log lines, not inference.

## Cheapest evidence FIRST (no new build)

The nostrip image is already flashed. Pull the plain log of the failing session
before building anything:

```
cd <repo> && scripts/pull_dongle_log.sh nostrip_fail
```

Look for: where the CarPlay session tears down (assert / err code), whether the
phone issues a 2nd-stream (type 111) setup, and any `wlcp add viewAreas` line
(proves the capability flags were ON). If that answers it, the build below is
unnecessary.

## Diagnostic patch (only if the plain log is insufficient)

Two cheap probes, logged via the existing `fprintf(stderr, "[Suding-%s] …")`
infrastructure (timestamp_ext @0x51a380, fprintf GOT -0x6208, fflush -0x62ac):

1. **Display count in nativeDict.plist**, at the read site in
   `airPlayGetPropertyFromNativeHU` (0x43e208), right after the displays array is
   fetched and BEFORE the strip loop (0x43e4a4). Log `CFArrayGetCount(displays)`.
   → Proves whether the plist actually carries 2 displays at read time. [resolves UNK #3 partial]

2. **The 4 capability flag bytes**: log the byte values at 0x56b484 / 0x56b481 /
   0x56b483 / 0x56b480 (uiContext/viewAreas/focusTransfer/cornerMasks gates).
   → Proves whether the capability subsystem is enabled in our session. [resolves UNK #2/#3]

### Mechanics (same pattern as the proven carinfo dump)

- Detour one instruction in the target to a code cave (4-byte aligned, in rodata
  pad near 0x53e000 region used before), run the probe, replay the overwritten
  instruction, jump back.
- Cave body: `timestamp_ext(buf,0x20)`; `fprintf(stderr, fmt, buf, count/flags…)`;
  `fflush(stderr)`; restore $a-regs/$gp as the proven p1cluster cave does.
- Format strings go in a second small cave or reuse existing ones; add a new CFL
  C-string only if needed.
- Build on CLEAN STOCK (not on nostrip) so the probe and the fix stay separable,
  OR layer onto nostrip if we want to see counts in the failing path specifically.

### Validation before flash

- `llvm-objdump` the cave + detour; confirm the detour target is word-aligned and
  the replayed instruction is byte-identical to the original.
- Exactly the intended bytes differ from the base image (diff check).

### After flash

Flash → reproduce → `pull_dongle_log.sh diag` → read the two probe lines →
update `docs/VERSION_DIFF.md` [UNK] items with [OBS] evidence.
