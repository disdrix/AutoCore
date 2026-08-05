// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: Skill_ReevaluateForCurrentRank×2, FUN_00627be0, Skill_EvaluateRankedElements.
//  - Return sites: 2.

// =============================================================================
// Skill_ReevaluateForCurrentRank
// -----------------------------------------------------------------------------
// Stable ID: aa_00553390
// Address:   0x00553390  (autoassault.exe, image base 0x400000)
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

/* Skill_ReevaluateForCurrentRank(pSkill)

   

   Parameters:

     pSkill - skill runtime

   

   Algorithm: Skill_EvaluateRankedElements(id, rank+offset, pSkill, offset);

   updates targeting flags +0x624.

   

   VERIFIED calls Evaluate with skill+0x5fc id and +0x5f6 rank. */



void __fastcall Skill_ReevaluateForCurrentRank(void *pSkill)



{

  uint uVar1;

  

  Skill_EvaluateRankedElements

            (*(uint32_t /* width from decompiler */ *)((int)pSkill + 0x5fc),

             *(short *)((int)pSkill + 0x5f6) + *(short *)((int)pSkill + 0x174),pSkill,

             *(short *)((int)pSkill + 0x174));

  uVar1 = FUN_00627be0();

  if (*(uint *)((int)pSkill + 0x620) == 0) {

    *(uint *)((int)pSkill + 0x624) = uVar1;

  }

  else {

    *(uint *)((int)pSkill + 0x624) = uVar1 | 4;

    if (*(char *)((int)pSkill + 0x148) == '\0') {

      *(uint *)((int)pSkill + 0x620) = *(uint *)((int)pSkill + 0x620) | 0x100000;

      return;

    }

  }

  return;

}
