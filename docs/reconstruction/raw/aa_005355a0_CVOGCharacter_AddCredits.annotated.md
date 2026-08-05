# Annotated low-level: CVOGCharacter_AddCredits

| Field | Value |
|---|---|
| Stable ID | `aa_005355a0` |
| VA | `0x005355a0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005355a0`.
- Prefer assembly when decompiler conflicts (not re-checked in scaffold pass).
- Integer widths: trust decompiler until spot-checked; document corrections here.
- Side-effect order: preserve call and store order from raw pseudocode.
- Uncertainty: parameter meanings and object types often Probable/Tentative until cross-function validation.

## Pseudocode (annotated copy of raw)

```c
/* CVOGCharacter_AddCredits — add signed int64 delta into character money.

   

   Algorithm:

     *(longlong*)(this+0x720) += nAmountDelta

     CVOGCharacter_EvaluatePendingObjectives(this, MONEY=5, (float)delta, 0, 0)

     return new absolute money

   

   Parameters:

     this — CVOGCharacter*

     nAmountDelta — signed int64 credit delta (additive)

   Returns: longlong new absolute money at this+0x720.

   

   Verified offsets: money @ +0x720/+0x724. Money field is Globes/Bars/Scrip/Clink base-1000. */



longlong __thiscall CVOGCharacter_AddCredits(void *this,longlong nAmountDelta)



{

  uint *puVar1;

  uint uVar2;

  

                    /* char+0x720 = absolute money (int64) */

  puVar1 = (uint *)((int)this + 0x720);

  uVar2 = *puVar1;

  *puVar1 = *puVar1 + (uint)nAmountDelta;

  *(int *)((int)this + 0x724) =

       *(int *)((int)this + 0x724) + nAmountDelta._4_4_ + (uint)CARRY4(uVar2,(uint)nAmountDelta);

                    /* PendingObjectiveEvalType_Inferred.Money (5) */

  CVOGCharacter_EvaluatePendingObjectives(this,5,(float)nAmountDelta,0,0);

  return *(longlong *)((int)this + 0x720);

}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
- Map DAT_* globals and FUN_* callees.
