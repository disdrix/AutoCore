// =============================================================================
// FUN_00514e00
// -----------------------------------------------------------------------------
// Stable ID: aa_00514e00
// Address:   0x00514e00  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Name:      leave-FUN — product name withheld (no string/RTTI)
// Dual A/B:  docs/reconstruction/reviews/A|B_aa_00514e00_FUN_00514e00.md
// =============================================================================

// PURPOSE:
//   Null-safe decrement of active-cast/busy refcount on the optional 0x14 slot
//   at this+0x64 (same family as FUN_005169c0 lazy-get).
//   If *(block+0x10) nonzero: --; when result is 0, *(block+0xC) = 0.
//   Does NOT allocate the slot; does NOT queue a deferred skill id
//   (contrast Skill_ClearActiveCastCounterAndQueueId).
//
// CALLERS (5 sites / 3 funcs):
//   Client_RecvSkillStatusEffect @ 008111c5, 00811200, 00811482
//   Skill_ApplyStatusEffectLocal @ 0051abd4
//   FUN_00606180 @ 00606193
//
// Role note (not registry): prior residual Skill_DecActiveCastCounter (INFERRED High).

/*
 * Behavioral notes:
 * - Dual A/B decompile match 2026-07-29.
 * - Inline twin exists in Skill_ApplyStatusEffectLocal immediate-apply path
 *   on pCasterObj+0x64 (same three stores).
 * - Runtime / differential verification: OPEN.
 */

void __fastcall FUN_00514e00(int param_1)
{
  int iVar1;
  int iVar2;

  iVar1 = *(int *)(param_1 + 100); /* this+0x64 */
  if (((iVar1 != 0) && (*(int *)(iVar1 + 0x10) != 0)) &&
     (iVar2 = *(int *)(iVar1 + 0x10) + -1, *(int *)(iVar1 + 0x10) = iVar2, iVar2 == 0)) {
    *(unsigned int *)(iVar1 + 0xc) = 0;
  }
  return;
}
