// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: Skill_SetRankAndReevaluate×2, Skill_ReevaluateForCurrentRank.
//  - Return sites: 1.

// =============================================================================
// Skill_SetRankAndReevaluate
// -----------------------------------------------------------------------------
// Stable ID: aa_005535a0
// Address:   0x005535a0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* Skill_SetRankAndReevaluate(pSkill, sRank)

   

   Parameters:

     pSkill - skill runtime

     sRank  - new rank stored at +0x5f6

   

   Algorithm: set rank; Skill_ReevaluateForCurrentRank.

   Returns: void */



void __thiscall Skill_SetRankAndReevaluate(void *this,void *pSkill,short sRank)



{

  *(uint16_t *)((int)this + 0x5f6) = pSkill._0_2_;

  Skill_ReevaluateForCurrentRank(this);

  return;

}
