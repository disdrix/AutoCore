// =============================================================================
// Named_CalleeOf_Named_CVOGFXParameterInstance_DoParameterUpdates_00973770
// -----------------------------------------------------------------------------
// Stable ID: aa_00973770
// Callee of Named_CVOGFXParameterInstance_DoParameterUpdates
// Address:   0x00973770  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CVOGFXParameterInstance_DoParameterUpdates: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~6 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00973590, FUN_00973770.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CVOGFXParameterInstance_DoParameterUpdates
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

void Named_CalleeOf_Named_CVOGFXParameterInstance_DoParameterUpdates_00973770(float *param_1)



{

  FUN_00973590(*param_1 * DAT_00aaa6f8,param_1[1] * DAT_00aaa6f8,param_1[2] * DAT_00aaa6f8,

               0x437f0000);

  return;

}
