# Raw capture: CVOGCharacter_AddCredits

| Field | Value |
|---|---|
| **Stable ID** | `aa_005355a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005355a0` |
| **Canonical name** | `CVOGCharacter_AddCredits` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

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
