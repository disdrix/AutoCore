// =============================================================================
// Named_CalleeOf_CVOGObjectiveRequirement_UseItem_MatchTarget_0060d460
// -----------------------------------------------------------------------------
// Stable ID: aa_0060d460
// Callee of CVOGObjectiveRequirement_UseItem_MatchTarget
// Address:   0x0060d460  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGObjectiveRequirement_UseItem_MatchTarget: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×4, return×4.
//  - Notable callees: FUN_00571010, FUN_005710c0, FUN_0060d460.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of CVOGObjectiveRequirement_UseItem_MatchTarget
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_CVOGObjectiveRequirement_UseItem_MatchTarget_0060d460(int param_1,int param_2,int param_3)



{

  int iVar1;

  

  if ((param_2 == 0) || (param_3 == 0)) {

    return 0;

  }

  if ((((((*(uint *)(param_1 + 0x10) & *(uint *)(param_1 + 0x14)) != 0xffffffff) &&

        (*(uint *)(param_3 + 0x160) == *(uint *)(param_1 + 0x10))) &&

       (*(uint *)(param_3 + 0x164) == *(uint *)(param_1 + 0x14))) ||

      ((*(int *)(param_1 + 0x18) != -1 &&

       (*(int *)(*(int *)(param_3 + 0xa8) + 0x34) == *(int *)(param_1 + 0x18))))) &&

     ((*(int *)(param_2 + 0x250) != 0 &&

      ((*(int *)(*(int *)(param_2 + 0x250) + 0x2b0) != 0 &&

       (iVar1 = FUN_00571010(*(uint32_t /* width from decompiler */ *)(param_3 + 0x160),*(uint32_t /* width from decompiler */ *)(param_3 + 0x164)),

       (iVar1 == 0) == (bool)*(char *)(param_1 + 0x1d))))))) {

    if ((*(int *)(param_1 + 0x2c) != -1) &&

       (iVar1 = FUN_005710c0(*(int *)(param_1 + 0x2c),0,0), iVar1 == 0)) {

      return 0;

    }

    if ((*(int *)(param_1 + 0x54) < 1) ||

       (*(int *)(param_1 + 0x54) ==

        *(int *)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xa8 + param_2) + 0xfc))) {

      return 1;

    }

  }

  return 0;

}
