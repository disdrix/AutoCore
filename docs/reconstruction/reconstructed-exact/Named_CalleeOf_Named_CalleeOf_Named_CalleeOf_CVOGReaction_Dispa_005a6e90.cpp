// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispa_005a6e90
// -----------------------------------------------------------------------------
// Stable ID: aa_005a6e90
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch
// Address:   0x005a6e90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: return×6, switch×1.
//  - Notable callees: FUN_005a6e90.
//  - Return sites: 6.

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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispa_005a6e90(int param_1,uint8_t param_2,uint32_t /* width from decompiler */ param_3)



{

  switch(param_2) {

  case 0:

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xb4) = param_3;

    return;

  case 1:

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xb8) = param_3;

    return;

  case 2:

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xbc) = param_3;

    return;

  case 3:

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc0) = param_3;

    return;

  case 4:

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc4) = param_3;

    return;

  case 5:

    *(uint32_t /* width from decompiler */ *)(param_1 + 200) = param_3;

  }

  return;

}
