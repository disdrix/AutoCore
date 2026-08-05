// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×5, return×3.
//  - Notable callees: Skill_EnsureLoadedInTree×2, CNDHash_LookupByKey, CVOGReaction_ResolveSkillTargets, FUN_0051e6d0, FUN_007a4480, Skill_SetRankAndReevaluate.
//  - Strings: "AddSkillToTree, unable to find skill #%d, level %d".
//  - Return sites: 3.

// =============================================================================
// Skill_EnsureLoadedInTree
// -----------------------------------------------------------------------------
// Stable ID: aa_0051a980
// Address:   0x0051a980  (autoassault.exe, image base 0x400000)
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

/* Skill_EnsureLoadedInTree(skillId, rank)

   

   Looks up skill in character/object skill tree hash. If missing, ResolveSkillTargets

   and insert; if present but lower rank, Skill_SetRankAndReevaluate. */



void __thiscall Skill_EnsureLoadedInTree(void *this,int nSkillId,short sRank)



{

  void *this_00;

  uint32_t /* width from decompiler */ *puVar1;

  short unaff_DI;

  uint16_t in_stack_0000000a;

  

  if (0 < nSkillId) {

    this_00 = CNDHash_LookupByKey(*(void **)((int)this + 0x70),nSkillId);

    if (this_00 == (void *)0x0) {

      puVar1 = CVOGReaction_ResolveSkillTargets((void *)nSkillId,_sRank);

      if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

        FUN_0051e6d0(nSkillId,puVar1,0);

        return;

      }

      FUN_007a4480(0,"AddSkillToTree, unable to find skill #%d, level %d",nSkillId,(int)sRank);

    }

    else if (*(short *)((int)this_00 + 0x5f6) < sRank) {

      Skill_SetRankAndReevaluate(this_00,_sRank,unaff_DI);

      return;

    }

  }

  return;

}
