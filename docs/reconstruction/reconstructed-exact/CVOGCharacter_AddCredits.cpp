// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: return×2.
//  - Notable callees: CVOGCharacter_EvaluatePendingObjectives×2, CARRY4, CVOGCharacter_AddCredits, Money, delta, money.
//  - Return sites: 2.

// =============================================================================
// CVOGCharacter_AddCredits
// -----------------------------------------------------------------------------
// Stable ID: aa_005355a0
// Address:   0x005355a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 */

/* CVOGCharacter_AddCredits - add signed int64 delta into character money.

   

   Algorithm:

     *(longlong*)(this+0x720) += nAmountDelta

     CVOGCharacter_EvaluatePendingObjectives(this, MONEY=5, (float)delta, 0, 0)

     return new absolute money

   

   Parameters:

     this - CVOGCharacter*

     nAmountDelta - signed int64 credit delta (additive)

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
