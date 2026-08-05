// =============================================================================
// FUN_005d9020
// -----------------------------------------------------------------------------
// Stable ID: aa_005d9020
// Address:   0x005d9020  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d9020 @ 0x005d9020
// Stable ID: aa_005d9020
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005d9020, FUN_0076c4d0, FUN_0076c500.
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

uint32_t /* width from decompiler */ * __thiscall FUN_005d9020(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  *param_1 = &PTR_FUN_009db450;

  param_1[1] = 0;

  param_1[3] = 0;

  param_1[4] = 0;

  FUN_0076c500(10000);

  param_1[2] = param_2;

  FUN_0076c4d0();

  return param_1;

}
