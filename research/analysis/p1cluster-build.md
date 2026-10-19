# P1-cluster: advertise Audi instrument cluster as 2nd CarPlay display

Base (stock): `firmware/extracted/ax_202609051445/sdDongle` (ELF32 MIPS32r2 LE, ET_EXEC, 1422096 bytes)
Output: `firmware/modified/ax_202609051445_p1cluster/sdDongle` (same size, 1422096)
Tar: `firmware/modified/ax_p1cluster.tar` (sha256 0042223b227a9fef46b163c03325eafc890279e96564d5bc267216f1bf26944d)

## Derived ABI: `AirPlayInfoArrayAddScreenDisplay` @0x47e910

Verified from disasm of the function and the main call site (0x43de3c-0x43de68):

```
AirPlayInfoArrayAddScreenDisplay(
    a0 = int** array,          ; ptr to slot; *a0==0 => creates CFLMutableArray, else appends
    a1 = uuid,                 ; CFL string OBJECT (not C-string)
    a2 = features,             ; -> key "features"
    a3 = primaryInputDevice,   ; -> key "primaryInputDevice"
    [sp+0x10] = maxFPS,         ; -> key "maxFPS"
    [sp+0x14] = widthPixels,    ; -> key "widthPixels"
    [sp+0x18] = heightPixels,   ; -> key "heightPixels"
    [sp+0x1c] = widthPhysical,  ; -> key "widthPhysical"
    [sp+0x20] = heightPhysical) ; -> key "heightPhysical"
```

- Callee frame is 0x68, so caller stack args land at callee sp+0x78..+0x88 (confirmed).
- It builds a CFLMutableDictionary, sets uuid via CFDictionarySetValue and the numerics via CFDictionarySetInt64, appends to the array, `CFRelease`s the dict, and **returns 0 (not the dict)**. The dict survives (array retains it) so it must be fetched back with CFArrayGetValueAtIndex(array, count-1).
- The main call passes a3=0 (primaryInputDevice) and the numeric stack args come from config-override helper calls; for the cluster we pass the literal ground-truth values directly.

## CFL constant-string object layout (verified from uuid obj @0x5230d8 and all key objs)

`{ uint32 w0=0x00010756 ; uint32 w1=0x7fffffff ; inline NUL-terminated ASCII at +8 }`
`0x5230d8` inlines `"e5f7a68d-..."` (= audi_displays.json display[0].uuid). Cluster uuid objects are crafted in the cave with the identical header.

## CF function addresses (from .dynsym, statically linked, ET_EXEC absolute)

- AirPlayInfoArrayAddScreenDisplay 0x47e910
- CFArrayGetCount 0x4927c0  (a0=array -> count in $2)
- CFArrayGetValueAtIndex 0x492814  (a0=array, a1=index)
- CFDictionarySetInt64 0x4a77d0  (a0=dict, a1=key CFLstr, a2=val_lo, a3=val_hi)
- CFDictionarySetCString 0x4a49dc  (a0=dict, a1=key CFLstr, a2=cstr value, a3=len; -1 => strlen)

Keys are CFL string OBJECTS. Reused existing "type" CFL obj @0x51f240. "initialURL" CFL obj does not exist in the binary, so one is crafted in the cave. Value "maps:/car/instrumentcluster" is embedded as a C-string in the cave (passed to CFDictionarySetCString with len=-1).

## Code cave

Chosen: **vaddr 0x53ed78 (file 0x13ed78)**, a 404-byte run of zero padding inside .rodata (which is inside the R+E LOAD segment [0x400000..0x552c10], so it is executable). The 88-byte gap at 0x52fe00 was too small. Used: code 0x13ed78..0x13ee58 (224 bytes) + data 0x13ee58..0x13eeb6 (uuid obj, initialURL key obj, maps cstr); ends 0x13eeb6, well under the pad limit 0x13ef0c.

gp is not needed in the cave (function addresses loaded absolutely via lui/ori; each callee recomputes its own gp from $25). gp is caller-saved so trashing it is safe.

## Detour

Overwrite the one instruction at file 0x3de6c (vaddr 0x43de6c), originally `lw $ra,0x54($sp)` (`54 00 bf 8f`), with `j 0x53ed78` (`5e fb 14 08`). Its delay slot (0x43de70 `lw $2,0x30($sp)`) is left intact and runs harmlessly. The cave re-executes the displaced `lw $ra,0x54($sp)` and `lw $2,0x30($sp)` before rejoining the epilogue at 0x43de74. $17 (needed by `sw $zero,0($17)` at 0x43de88) is never touched in the cave; $16/$18 are reloaded by the epilogue; $sp is balanced.

## Verification (llvm-objdump on the patched binary)

Detour:
```
43de6c: 5e fb 14 08   j     0x53ed78
43de70: 30 00 a2 8f   lw    $2, 0x30($sp)     ; delay slot (unchanged)
43de74: 50 00 b5 8f   lw    $21, 0x50($sp)    ; rejoin point
```

Cave (0x53ed78):
```
addiu $sp,$sp,-0x40
addiu $4,$sp,0x70              ; a0 = &array (orig sp+0x30)
lui/ori $5,0x53ee58            ; a1 = cluster uuid CFL obj
li $6,2 ; li $7,3              ; features=2, primaryInputDevice=3
li $8,0x3c ; sw ->0x10(sp)     ; maxFPS=60
li $8,0x5a0; sw ->0x14(sp)     ; widthPixels=1440
li $8,0x21c; sw ->0x18(sp)     ; heightPixels=540
li $8,0x140; sw ->0x1c(sp)     ; widthPhysical=320
li $8,0x78 ; sw ->0x20(sp)     ; heightPhysical=120
lui/ori $25,0x47e910; jalr     ; AddScreenDisplay
lw $16,0x70(sp)                ; s0 = array
move $4,$16; lui/ori $25,0x4927c0; jalr   ; CFArrayGetCount
addiu $5,$2,-1                 ; index = count-1
move $4,$16; lui/ori $25,0x492814; jalr   ; CFArrayGetValueAtIndex
move $18,$2                    ; s2 = cluster dict
move $4,$18; lui/ori $5,0x51f240; li $6,0x6f; move $7,$0
  lui/ori $25,0x4a77d0; jalr   ; CFDictionarySetInt64(dict,"type",111)
move $4,$18; lui/ori $5,0x53ee88; lui/ori $6,0x53ee9c; li $7,-1
  lui/ori $25,0x4a49dc; jalr   ; CFDictionarySetCString(dict,"initialURL","maps:/car/instrumentcluster")
addiu $sp,$sp,0x40
lw $ra,0x54(sp)                ; displaced insn
j 0x43de74
lw $2,0x30(sp)                 ; delay = displaced insn (return value = array)
```

Byte-diff vs stock: only file 0x3de6c (4 bytes, detour) and 0x13ed78..0x13eeb6 (cave, all inside padding). Patched size == stock size (1422096). Repack: the 4 libSd*.so are byte-identical to stock; only sdDongle differs.

## Fields advertised for the cluster (display[1])

type=111, uuid=b7e6c5a0-2222-4000-8000-000000000002, widthPixels=1440, heightPixels=540, maxFPS=60, widthPhysical=320, heightPhysical=120, features=2, primaryInputDevice=3, initialURL=maps:/car/instrumentcluster. **viewAreas omitted (v1).**

## On-hardware test (do NOT run from here)

1. Flash `ax_p1cluster.tar` to the dongle (`scripts/flash_dongle.sh`).
2. Connect iPhone (CarPlay) + the Audi head unit.
3. Pull the dongle log: `scripts/pull_dongle_log.sh` (or `/usr/data/log` via minizip.cgi).
4. Look for: the phone enumerating TWO displays in /info; a second "send screen setup msg" / receiver screen-setup for the cluster; and the phone opening a **type-111 video stream**. Success = phone SEES and requests the cluster display.

## Risks / notes

- **uuid form**: cluster uuid is a crafted CFL const-string obj matching the exact header of stock objects; if CFL string accessors read anything beyond {w0,w1,inline chars} this could misbehave (low risk; layout matched byte-for-byte against 0x5230d8).
- **missing viewAreas**: the phone MAY require a viewAreas array; v1 omits it. If the phone rejects the display, a v2 with viewAreas is the next step (separate output dir).
- **downstream (not this patch)**: even if the phone opens type-111, the dongle's receiver screen session is a singleton and the client only sets up 110 to the car — later patches.
