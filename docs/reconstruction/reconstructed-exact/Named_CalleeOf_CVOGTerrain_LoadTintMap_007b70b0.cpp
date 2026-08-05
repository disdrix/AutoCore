// =============================================================================
// Named_CalleeOf_CVOGTerrain_LoadTintMap_007b70b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007b70b0
// Callee of CVOGTerrain_LoadTintMap (+2 other named callers)
// Address:   0x007b70b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGTerrain_LoadTintMap: config/load helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. CVOGTerrain_LoadTintMap (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~6 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0075e2d0, FUN_007b70b0, FUN_00989e00.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGTerrain_LoadTintMap (+2 other named callers)
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

uint32_t /* width from decompiler */ Named_CalleeOf_CVOGTerrain_LoadTintMap_007b70b0(uint32_t /* width from decompiler */ param_1)



{

  FUN_00989e00(&param_1,param_1);

  FUN_0075e2d0(&param_1);

  return 1;

}
