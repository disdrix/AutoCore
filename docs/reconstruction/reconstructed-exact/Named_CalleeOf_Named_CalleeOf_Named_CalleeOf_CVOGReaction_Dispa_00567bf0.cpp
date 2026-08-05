// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispa_00567bf0
// -----------------------------------------------------------------------------
// Stable ID: aa_00567bf0
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch
// Address:   0x00567bf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00567420, FUN_00567950, FUN_00567bf0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispa_00567bf0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 4);

  if ((iVar1 != 0) &&

     ((uint)(*(int *)(param_1 + 8) - iVar1 >> 3) < (uint)(*(int *)(param_1 + 0xc) - iVar1 >> 3))) {

    iVar1 = *(int *)(param_1 + 8);

    FUN_00567420(iVar1,1,param_2,param_1,param_2);

    *(int *)(param_1 + 8) = iVar1 + 8;

    return;

  }

  FUN_00567950(*(uint32_t /* width from decompiler */ *)(param_1 + 8),1,param_2);

  return;

}
