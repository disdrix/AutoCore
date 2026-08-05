// =============================================================================
// FUN_00609e60
// -----------------------------------------------------------------------------
// Stable ID: aa_00609e60
// Address:   0x00609e60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00609e60 @ 0x00609e60
// Stable ID: aa_00609e60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005b2520, FUN_00609e60.
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

uint32_t /* width from decompiler */ * __fastcall FUN_00609e60(uint32_t /* width from decompiler */ *param_1)



{

  float fVar1;

  

  FUN_005b2520();

  fVar1 = g_flOne;

  *param_1 = &PTR_LAB_009df5c4;

  param_1[0x1e] = 0;

  param_1[0x20] = 0xffffffff;

  param_1[0x16] = fVar1;

  return param_1;

}
