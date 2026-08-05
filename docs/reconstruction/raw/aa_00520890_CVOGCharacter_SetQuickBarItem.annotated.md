# Annotated low-level: CVOGCharacter_SetQuickBarItem

| Field | Value |
|---|---|
| Stable ID | `aa_00520890` |
| VA | `0x00520890` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00520890`.
- Prefer assembly when decompiler conflicts (not re-checked in scaffold pass).
- Integer widths: trust decompiler until spot-checked; document corrections here.
- Side-effect order: preserve call and store order from raw pseudocode.
- Uncertainty: parameter meanings and object types often Probable/Tentative until cross-function validation.

## Pseudocode (annotated copy of raw)

```c
/* CVOGCharacter_SetQuickBarItem

   

   Writes one quick-bar item COID into the local player character.

     this+0x930 + slot*8 = int64 itemCoid  (-1 = empty)

     this+0x634 |= 2       dirty bit for quick-bar state

   

   slot must be < 100; otherwise no-op.

   Called from Client_RecvCreateCharacter when applying CreateCharacterExtended offsets

   0x410 (100 x int64 item COIDs) and from QuickBar UI clear/assign paths.

   

   __thiscall: RET 0xC (slot + valueLo + valueHi).

   Verified: AutoCore QuickBarUpdate session RE (2026-07). */



void __thiscall CVOGCharacter_SetQuickBarItem(void *this,byte slot,uint valueLo,uint valueHi)



{

  if (slot < 100) {

                    /* char+0x930 + slot*8 = itemCoid int64 */

    *(uint *)((int)this + (uint)slot * 8 + 0x930) = valueLo;

    *(uint *)((int)this + (uint)slot * 8 + 0x934) = valueHi;

    *(uint *)((int)this + 0x634) = *(uint *)((int)this + 0x634) | 2;

  }

  return;

}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
- Map DAT_* globals and FUN_* callees.
