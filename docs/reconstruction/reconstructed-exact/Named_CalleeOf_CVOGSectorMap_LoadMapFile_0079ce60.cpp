// =============================================================================
// Named_CalleeOf_CVOGSectorMap_LoadMapFile_0079ce60
// -----------------------------------------------------------------------------
// Stable ID: aa_0079ce60
// Callee of CVOGSectorMap_LoadMapFile
// Address:   0x0079ce60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGSectorMap_LoadMapFile: config/load helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0079ce60.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGSectorMap_LoadMapFile
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

void __fastcall Named_CalleeOf_CVOGSectorMap_LoadMapFile_0079ce60(uint32_t /* width from decompiler */ *param_1)



{

  *param_1 = &PTR_LAB_009cbf98;

  *(uint8_t *)(param_1 + 1) = 0;

  *(uint8_t *)((int)param_1 + 5) = 0;

  *(uint8_t *)((int)param_1 + 7) = 0;

  *(uint8_t *)(param_1 + 2) = 0;

  param_1[0x1a3] = 0;

  param_1[3] = 0;

  param_1[4] = 0;

  param_1[5] = 0;

  param_1[6] = 0;

  param_1[7] = 0;

  param_1[8] = 0;

  param_1[9] = 0;

  param_1[10] = 0;

  param_1[0xb] = 0;

  param_1[0xc] = 0;

  param_1[0xd] = 0;

  param_1[0xe] = 0;

  param_1[0xf] = 0;

  param_1[0x10] = 0;

  param_1[0x11] = 0;

  param_1[0x12] = 0;

  param_1[0x1a4] = 0;

  return;

}
