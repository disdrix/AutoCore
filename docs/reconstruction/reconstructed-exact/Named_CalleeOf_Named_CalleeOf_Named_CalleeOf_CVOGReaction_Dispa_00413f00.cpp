// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispa_00413f00
// -----------------------------------------------------------------------------
// Stable ID: aa_00413f00
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch
// Address:   0x00413f00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00413f00.
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispa_00413f00(int param_1,short param_2)



{

  if (0x50 < param_2) {

    *(uint16_t *)(param_1 + 0xea) = 0x50;

    return;

  }

  *(short *)(param_1 + 0xea) = param_2;

  return;

}
