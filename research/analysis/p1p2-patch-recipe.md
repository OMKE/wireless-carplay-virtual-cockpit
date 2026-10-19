# sdDongle P1+P2 — Concrete Binary-Patch Recipe (static RE)

Target: `firmware/extracted/ax_202609051445/sdDongle`
ELF32 MIPS32r2 LE, **ET_EXEC** (fixed base 0x400000 → absolute lui/ori addressing is safe), dynamically linked, stripped.
Canonical `_gp` = **0x570c30** for every function (verified: 0x570c30 − 0x7fd4 = 0x568c5c, the GOT slot holding 0x520000).
Method: llvm-objdump full disasm + a gp-relative xref resolver (reads GOT page-bases, tracks `lw reg,-X($gp)` + `addiu`/`move` chains; validated against the known "displays" ref at 0x43f174). Read-only on originals; candidate written only to `firmware/modified/`.

CFL constant string object = 8-byte header `56 07 01 00 ff ff ff 7f` immediately followed by the NUL-terminated C-string; the pointer passed to CF APIs is the **header address** (e.g. main uuid object @ 0x5230d8, its text @ 0x5230e0).

---

## Part 1 — RECEIVER-side references / gate hunt (deliverable 1)

I resolved every gp-relative reference to the requested strings. Result: **there is NO receiver-side (phone-facing) altScreen or enabledFeatures path — gated or otherwise.** Every altScreen reference is CLIENT-side (dongle→car).

| String | Addr | Referenced by (code) | Side | Notes |
|--------|------|----------------------|------|-------|
| `altScreen` | 0x51f36c | **none** | — | unreferenced in sdDongle |
| `altScreenURLs` | 0x51f3d4 | **none** | — | unreferenced |
| `altScreen` | 0x51e1f8 | 0x428238 | client→car | `CFArrayAppendCString($18,"altScreen")` |
| `altScreenUrlArray` | 0x51dc2c | 0x425984 | client→car | InfoExt, paired with maps URL @0x425994 |
| `enabledFeatures` | 0x51f7f0 | **none** | — | dead string |
| `enabledFeatures` | 0x523360 | **none** | — | dead string |
| `enabledFeatures` | 0x52bb60 | **none** | — | dead string |

Verification of the negatives: byte-pattern grep for the exact `addiu reg,reg,imm` that each string needs from base 0x520000 (`-0x810` for 0x51f7f0, `+0x3360` for 0x523360, `-0xc94` for 0x51f36c, `-0xc2c` for 0x51f3d4) → **zero hits**, while the control ("displays" 0x52320c, `+0x320c`) → 4 hits. rizin `/r` also found nothing (it can't resolve gp-relative, so it only corroborates the absence of absolute refs).

### The one real altScreen decision point (client→car, NOT phone-facing)
`AirplayClientSendCmdInfoExt` builds a feature array `$18` = `["viewAreas","cornerMasks","focusTransfer", …]` (0x428080–0x428114, all `CFArrayAppendCString`). Then at **0x428184–0x4281a8**:
```
0x428184 move  $4,$20                 ; a0 = manufacturer string
0x428188 li    $6,5
0x42818c/90/98 lw/jalr strncasecmp($4,"LG Electronics"@0x51e1ac,5)
0x4281a8 bnez  $2, 0x4281ec           ; if NOT "LG"  -> "add AltScreen" (append "altScreen")
                                       ; if  "LG"    -> log "LG no AltScreen", skip
```
So altScreen is advertised **to the car** unless the car reports as *LG Electronics*. For any non-LG car it is **already on**.

**Bonus gate-flip (car-facing, cheap, optional):** force altScreen regardless of car brand.
- file offset **0x281a8**: orig `10 00 40 14` (`bnez $2,+0x10`) → new `10 00 00 10` (`b +0x10`).

This is **not** the phone-facing P1/P2 jackpot the brief hoped for — it changes what the dongle tells the *car*, not what the phone sees. There is no equivalent phone-facing gate to flip.

---

## Part 2 — Code-cave patch

### P1 — make the receiver advertise a 2nd display  (BUILT & VERIFIED)

`_getScreenDisplays` @ 0x43dcfc calls `AirPlayInfoArrayAddScreenDisplay` @ 0x47e910 exactly once (jalr @ 0x43de64). Registers/stack at that call, all callee-saved and still live/present after it returns:
- a0 = `&array` (sp+0x30); a1 = uuid obj 0x5230d8; a2 = s0=features; a3 = 0;
- 0x10(sp)=maxFPS=s2(VIDEO_FPS), 0x14(sp)=widthPixels=s3(VIDEO_WIDTH), 0x18(sp)=heightPixels=s4(VIDEO_HEIGHT), 0x1c(sp)=widthPhysical=s5(SCREEN_WIDTH_MM), 0x20(sp)=heightPhysical=(SCREEN_HEIGHT_MM).

Because `*a0` is now non-NULL, a 2nd call **appends** a 2nd dict to the same array. AddScreenDisplay recomputes its own `$gp` from `$t9`, so the cave needs no valid `$gp`; ET_EXEC means absolute `lui/ori` for the uuid and callee address are safe. s0/s2–s5 and the 0x10–0x20(sp) slots survive the 1st call, so the 2nd call **reuses main dims** and only swaps the uuid.

**Code cave:** vaddr **0x52fe00** / file **0x12fe00**, a 92-byte (0x5c) zero gap inside the rodata C-string pool (between `…ecaa\0` and `supo_RTPJitterBuffer…`) — genuine string-alignment padding, NOT a referenced data table (the 0x53xxxx zero runs were rejected as they sit inside a live 16-bit lookup table). The whole first LOAD segment is R+X, so rodata is executable at runtime.

**Edit A — hijack (the single primary edit), 1 instruction:**
| file_off | orig bytes | new bytes | meaning |
|----------|-----------|-----------|---------|
| **0x3de6c** | `54 00 bf 8f` (`lw $ra,0x54($sp)`) | `80 bf 14 08` (`j 0x52fe00`) | jump into cave; the untouched delay slot 0x43de70 `lw $2,0x30($sp)` runs harmlessly |

**Edit B — cave body @ file 0x12fe00 (44 bytes code + 45-byte uuid obj = 89 bytes; orig = 92 zero bytes):**
```
0x52fe00 27 a4 30 00 -> LE 30 00 a4 27  addiu $4,$sp,0x30      ; a0=&array
0x52fe04 3c 05 00 52 -> LE 52 00 05 3c  lui   $5,0x52          ; a1 hi
0x52fe08 34 a5 fe 2c -> LE 2c fe a5 34  ori   $5,$5,0xfe2c      ; a1=0x52fe2c (alt uuid obj)
0x52fe0c 02 00 30 25 -> LE 25 30 00 02  move  $6,$16           ; a2=features (reuse main s0)
0x52fe10 3c 19 00 47 -> LE 47 00 19 3c  lui   $25,0x47          ; t9 hi
0x52fe14 37 39 e9 10 -> LE 10 e9 39 37  ori   $25,$25,0xe910    ; t9=0x47e910 AddScreenDisplay
0x52fe18 03 20 f8 09 -> LE 09 f8 20 03  jalr  $25
0x52fe1c 00 00 38 25 -> LE 25 38 00 00  move  $7,$zero         ; (delay) a3=0
0x52fe20 8f bf 00 54 -> LE 54 00 bf 8f  lw    $ra,0x54($sp)    ; restore ra clobbered by call
0x52fe24 08 10 f7 9d -> LE 9d f7 10 08  j     0x43de74          ; back to epilogue
0x52fe28 8f a2 00 30 -> LE 30 00 a2 8f  lw    $2,0x30($sp)      ; (delay) v0=array (return value)
0x52fe2c  56 07 01 00 ff ff ff 7f  "b7e6c5a0-2222-4000-8000-000000000002\0"   ; alt uuid CFL obj
```
Raw new bytes at 0x12fe00 (89 bytes):
`3000a427 5200053c 2cfea534 25300002 4700193c 10e93937 09f82003 25380000 5400bf8f 9df71008 3000a28f` + `56070100ffffff7f 62376536633561302d323232322d343030302d383030302d30303030303030303030303200`

Both edits disassemble correctly (llvm-objdump `-D`) in the candidate. Candidate written to
`firmware/modified/ax_202609051445_p1p2/sdDongle`.

Optional variant: to mark the 2nd display as a touch+knob cluster (LIVI features 0x0A) instead of reusing main features, replace `move $6,$16` (0x52fe0c) with `addiu $6,$zero,0x0a` = LE `0a 00 06 24`.

**Caveat that limits P1:** `AirPlayInfoArrayAddScreenDisplay` sets only uuid / features / primaryInputDevice / maxFPS / widthPixels / heightPixels / widthPhysical / heightPhysical. It emits **no `type` key** (and the strings `type`/`initialURL` for a display dict do not exist in this binary). So the patch produces a 2nd display entry that is structurally valid but **cannot carry `type`=111 or an initialURL**. Whether the phone treats a 2nd type-less display as an instrument cluster is unproven (LIVI distinguishes main/alt by `type`=110/111). Making it a true cluster would require extending AddScreenDisplay to set a `type` key — beyond this cave.

### P2 — add `altScreen` to enabledFeatures on the setup response  (NO cheap patch)

There is **no receiver-side code that references `enabledFeatures`** (all three literals are dead) and no receiver code that builds a phone-facing enabledFeatures array. Consequently:
- P2 as literally specified (inject `altScreen` into the receiver's session-setup *response* enabledFeatures) has **no existing instruction site to patch**. It would require new code in the receiver setup-response builder (around `AirPlayReceiverSessionSetup` @ 0x47a634 / `AirPlayReceiverSessionScreen_Setup` @ 0x47eee8): create/find an enabledFeatures CFArray, `CFArrayAppendCString(arr,"altScreen"@0x51f36c)`, attach it under the `enabledFeatures` key — a second, larger cave. LOW confidence it is even consumed by this firmware.
- The **operative** altScreen advertisement that DOES exist is the car-facing one above; it is already active for non-LG cars, and can be forced with the 1-byte gate-flip at file 0x281a8.

---

## Part 3 — Feasibility / confidence

| Part | Verdict | Confidence |
|------|---------|-----------|
| Locating refs / "no phone-facing gate" | firm negative | HIGH (byte-pattern + resolver + control validated) |
| P1 cave assembles & is control-flow correct | verified via `llvm-objdump -D` | HIGH |
| P1 makes `/info` list 2 displays | very likely (append is length-driven, consumed by `AirPlayCopyServerInfo`) | MED-HIGH |
| P1 makes phone open a type-111 cluster stream | unproven — no `type` key emitted | LOW |
| P2 via small patch | not feasible; needs new code | HIGH (that it's not cheap) |
| Car-facing altScreen gate-flip (bonus) | 1-byte, correct | HIGH (but not the phone-facing goal) |

## Part 4 — Exact on-hardware check after flashing (do NOT flash from here)
Pull the dongle log (`/usr/data/log`, via `minizip.cgi`) and look for, per AirPlay session:
1. **P1 confirmation** — the AddScreenDisplay log `[Suding-%s] AirPlayInfoArrayAddScreenDisplay inMaxFPS=%d` (fmt @ 0x52e1b0) should now print **twice** (once per display) instead of once. Equivalent: the `/info` `displays` array length = 2, second uuid = `b7e6c5a0-2222-4000-8000-000000000002`.
2. **Cluster/alt stream** — watch for a second `send screen setup msg!` (@0x520d2c) / `send screen setup msg finished!` (@0x520d50); absence = phone did not open a 2nd stream (expected given the missing `type` field).
3. **altScreen (car-facing)** — `[Suding-%s] add AltScreen` (@0x51e1dc) vs `[Suding-%s] LG no AltScreen` (@0x51e1bc) shows which branch the LG gate took.
4. Confirm no crash: the 2nd AddScreenDisplay reuses live regs/stack; a hang right after the first `inMaxFPS` log would indicate a bad cave return.

## Key addresses
- Cave: vaddr 0x52fe00 / file 0x12fe00 (92-byte rodata pad); alt uuid obj 0x52fe2c.
- Primary edit: file 0x3de6c (`_getScreenDisplays`+0x170).
- `AddScreenDisplay` 0x47e910; `_getScreenDisplays` 0x43dcfc (call @0x43de64, epilogue @0x43de74).
- LG gate: strncasecmp @0x428194, branch @0x4281a8 (file 0x281a8); feature array append via CFArrayAppendCString GOT -0x7950($gp).
- Log fmts: AddScreenDisplay 0x52e1b0; add/LG AltScreen 0x51e1dc/0x51e1bc; screen setup 0x520d2c/0x520d50.
