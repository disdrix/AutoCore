// =============================================================================
// FUN_005b4bc0
// -----------------------------------------------------------------------------
// Stable ID: aa_005b4bc0
// Address:   0x005b4bc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b4bc0 @ 0x005b4bc0
// Stable ID: aa_005b4bc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005b4bc0, FUN_00748960.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * __fastcall FUN_005b4bc0(uint32_t /* width from decompiler */ *param_1)



{

  FUN_00748960();

  *param_1 = &PTR_FUN_009d9924;

  param_1[1] = &PTR_LAB_009d9914;

  param_1[0x34] = 0xffffffff;

  param_1[0x35] = 0xffffffff;

  param_1[0x36] = 0xffffffff;

  *(uint8_t *)(param_1 + 0x33) = 0;

  param_1[0x31] = 0;

  param_1[0x32] = 0;

  return param_1;

}
