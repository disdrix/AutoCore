// =============================================================================
// Named_CalleeOf_CVOGCharacter_ApplyCreateFromPacket_005304a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005304a0
// Callee of CVOGCharacter_ApplyCreateFromPacket
// Address:   0x005304a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGCharacter_ApplyCreateFromPacket: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, while×1.
//  - Notable callees: FUN_00514e70×2, CVOGReaction_ResolveSkillTargets, FUN_005304a0, FUN_0053aea0, Skill_SetRankAndReevaluate.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of CVOGCharacter_ApplyCreateFromPacket
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_CalleeOf_CVOGCharacter_ApplyCreateFromPacket_005304a0(int param_1,void *param_2,void *param_3,int param_4)



{

  int *piVar1;

  short unaff_DI;

  uint32_t /* width from decompiler */ *local_c;

  int local_8;

  uint8_t local_4;

  

  piVar1 = *(int **)(param_1 + 0x550);

  while( true ) {

    if (piVar1 == *(int **)(param_1 + 0x554)) {

      local_c = CVOGReaction_ResolveSkillTargets(param_2,param_3);

      if (local_c != (uint32_t /* width from decompiler */ *)0x0) {

        local_8 = param_4;

        local_4 = 1;

        FUN_0053aea0(&local_c);

        FUN_00514e70(param_2);

      }

      return;

    }

    if (*(void **)(*piVar1 + 0x5fc) == param_2) break;

    piVar1 = piVar1 + 3;

  }

  Skill_SetRankAndReevaluate((void *)*piVar1,param_3,unaff_DI);

  piVar1[1] = param_4;

  FUN_00514e70(param_2);

  return;

}
