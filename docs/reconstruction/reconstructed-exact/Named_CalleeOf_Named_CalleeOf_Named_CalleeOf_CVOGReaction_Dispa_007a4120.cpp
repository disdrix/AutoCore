// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispa_007a4120
// -----------------------------------------------------------------------------
// Stable ID: aa_007a4120
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch
// Address:   0x007a4120  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: CONCAT22×2, FUN_007a4120.
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispa_007a4120(int param_1,uint param_2)



{

  uint16_t uVar1;

  

  if ((int)param_2 < 0) {

    if (0xfffff < *(int *)(param_1 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

    }

    uVar1 = *(uint16_t *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0xc) * 2);

    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;

    return CONCAT22((short)((uint)*(int *)(param_1 + 8) >> 0x10),uVar1);

  }

  param_2 = param_2 & 0x800fffff;

  if ((int)param_2 < 0) {

    param_2 = (param_2 - 1 | 0xfff00000) + 1;

  }

  return CONCAT22((short)(param_2 >> 0x10),*(uint16_t *)(*(int *)(param_1 + 8) + param_2 * 2));

}
