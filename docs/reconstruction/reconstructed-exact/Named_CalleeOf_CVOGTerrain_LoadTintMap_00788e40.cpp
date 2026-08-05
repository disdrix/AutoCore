// =============================================================================
// Named_CalleeOf_CVOGTerrain_LoadTintMap_00788e40
// -----------------------------------------------------------------------------
// Stable ID: aa_00788e40
// Callee of CVOGTerrain_LoadTintMap (+2 other named callers)
// Address:   0x00788e40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGTerrain_LoadTintMap: config/load helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. CVOGTerrain_LoadTintMap (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~7 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00788e40.
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_CVOGTerrain_LoadTintMap_00788e40(int param_1)



{

  if (*(int *)(param_1 + 4) != 0) {

    return *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 4) + 0x10);

  }

  return 0;

}
