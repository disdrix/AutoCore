# Annotated low-level: FUN_007f6db0 / ActionMap_FindSlotByKeyMod_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_007f6db0` |
| VA | `0x007f6db0`–`0x007f6fa3` |
| System | input-drive-control |
| Date | 2026-08-05 (MEGA-018 refresh) |
| Named | `ActionMap_FindSlotByKeyMod_Inferred` |
| Ghidra | `FUN_007f6db0` |
| Parent | `Client_Input_OnKeyDown_MatchAction` `0x00911030` |

---

## Machine-level notes

- **Leaf** ActionMap scanner: four mode groups, dual bind lanes (primary/alt), key+mod match with override-flag escape.
- Prefer **assembly** over decompiler for ABI: real formals live in **EAX/EDI/SI/DX**, not the decompiler `__fastcall` phantoms.
- Jump table @ `0x007f6fa4` selects mode case; mode>3 → NULL.
- Stride **0x34** sealed by LEA index math and `ADD reg,0x34` loop step.
- Same layout family as dualed `ActionMap_TrySetSlotBind` (`0x007f72e0`).
- Sole live caller only ever passes **mode=0** + global base `0x00d1b9ac`; modes 1–3 still present in body for other (currently unseen) consumers or completeness with the setter.

## Register ABI (sealed)

```
in:  EAX = mode (0..3)
     EDI = ActionMap*
     SI  = keyCode (u16)
     DX  = modState (u16; 0 = no-mod, nonzero e.g. 0x2A = require mod)
out: EAX = &slot.key0  or  NULL
     RET (C3)
```

## Control flow

```
if mode > 3: return NULL
jt[mode]:
  i = 0; cursor = base + mod0_off[mode]
  while i < max[mode]:
    // primary lane
    if word[cursor-0x2A] == key:
      if (modState==0) == (word[cursor]==0): return base + key0_off[mode] + i*0x34
      if byte[cursor+6] != 0: return same
    // alt lane
    if word[cursor-0x28] == key:
      if (modState==0) == (word[cursor+2]==0): return same
      if byte[cursor+6] != 0: return same
    i++; cursor += 0x34
  return NULL
```

## Mode offset table

| Mode | Max | key0 base | mod0 cursor | flag (cursor+6) |
|---|---|---|---|---|
| 0 | 5 | +0x06 | +0x30 | +0x36 (slot0) |
| 1 | 6 | +0x10A | +0x134 | |
| 2 | 0x78 | +0x242 | +0x26C | |
| 3 | 0x14 | +0x1AA2 | +0x1ACC | |

Relative to returned key0 pointer: key1@+2, held@+4, edge@+5, mod0@+0x2A, mod1@+0x2C, override@+0x30.

## Caller contract (OnKeyDown)

1. Resolve shift: any of VK_SHIFT / VK_LSHIFT / VK_RSHIFT down → `modState=0x2A` else 0.
2. Call this with mode 0 / ActionMap `0x00d1b9ac` / SI=key / DX=modState.
3. On non-NULL: if held@+4 clear → set held@+4=1, edge@+5=1, `FUN_0093a5c0(1)`.
4. On NULL: optional fallback inline scan of mode-2 region (`DAT_00d1bc18` ≡ base+0x26c) when session globals match.

## Pseudocode (annotated; decompiler shape preserved)

```c
// Decompiler shape — registers renamed in clean:
//   in_EAX → mode, unaff_EDI → actionMap, unaff_SI → keyCode, param_2 → modState (DX)
int __fastcall FUN_007f6db0(undefined4 param_1, short param_2)
{
  undefined4 in_EAX;   // mode
  short *psVar1;       // mod0 cursor
  int iVar2;           // slot index
  short unaff_SI;      // keyCode
  int unaff_EDI;       // actionMap

  switch(in_EAX) {
  case 0:
    iVar2 = 0;
    psVar1 = (short *)(unaff_EDI + 0x30);
    do {
      if (psVar1[-0x15] == unaff_SI) {           // key0
        if (param_2 == 0) {
          if (*psVar1 == 0) goto LAB_007f6dd2;  // mod0 unbound
        }
        else if (*psVar1 != 0) goto LAB_007f6dd2;
        if ((char)psVar1[3] != '\0') {          // override flag
LAB_007f6dd2:
          return unaff_EDI + 6 + iVar2 * 0x34;
        }
      }
      if (psVar1[-0x14] == unaff_SI) {           // key1
        if (param_2 == 0) {
          if (psVar1[1] == 0) goto LAB_007f6e02;
        }
        else if (psVar1[1] != 0) goto LAB_007f6e02;
        if ((char)psVar1[3] != '\0') {
LAB_007f6e02:
          return unaff_EDI + 6 + iVar2 * 0x34;
        }
      }
      iVar2 = iVar2 + 1;
      psVar1 = psVar1 + 0x1a;                    // +0x34 bytes
    } while (iVar2 < 5);
    break;
  case 1: /* max 6;  key0 +0x10A; mod0 +0x134  — same predicate */ /* ... */
  case 2: /* max 0x78; key0 +0x242; mod0 +0x26C — same predicate */ /* ... */
  case 3: /* max 0x14; key0 +0x1AA2; mod0 +0x1ACC — same predicate */ /* ... */
  }
  return 0;
}
```

## Open questions / gaps

- Product English for mode groups 0..3.
- Product name for override flag (key0+0x30).
- Who calls modes 1–3 (if anyone).
- Runtime / differential verification.
