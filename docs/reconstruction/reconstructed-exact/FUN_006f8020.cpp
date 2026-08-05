// =============================================================================
// FUN_006f8020
// -----------------------------------------------------------------------------
// Stable ID: aa_006f8020
// Address:   0x006f8020  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f8020 @ 0x006f8020
// Stable ID: aa_006f8020
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: SQRT×3, FUN_006f8020.
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



void FUN_006f8020(float *param_1)



{

  *param_1 = g_flOne / SQRT(*param_1 + _DAT_00a0f000);

  param_1[1] = g_flOne / SQRT(param_1[1] + _DAT_00a0f000);

  param_1[2] = g_flOne / SQRT(param_1[2] + _DAT_00a0f000);

  param_1[3] = 0.0;

  return;

}
