// =============================================================================
// FUN_005d6720
// -----------------------------------------------------------------------------
// Stable ID: aa_005d6720
// Address:   0x005d6720  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d6720 @ 0x005d6720
// Stable ID: aa_005d6720
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005d6720, FUN_0063f5b0.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ * __fastcall FUN_005d6720(uint32_t /* width from decompiler */ *param_1)



{

  float fVar1;

  

  FUN_0063f5b0();

  *param_1 = DAT_00a0f520;

  param_1[1] = DAT_00a0f6bc;

  param_1[2] = _DAT_009daed0;

  param_1[3] = DAT_009daecc;

  fVar1 = g_flOne;

  param_1[4] = g_flOne;

  param_1[5] = fVar1;

  param_1[6] = 0;

  param_1[7] = 0;

  param_1[8] = 0;

  param_1[9] = DAT_00aaaae8;

  return param_1;

}
