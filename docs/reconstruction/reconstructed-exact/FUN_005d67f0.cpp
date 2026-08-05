// =============================================================================
// FUN_005d67f0
// -----------------------------------------------------------------------------
// Stable ID: aa_005d67f0
// Address:   0x005d67f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d67f0 @ 0x005d67f0
// Stable ID: aa_005d67f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005d67f0, FUN_0063f5b0.
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



void FUN_005d67f0(uint32_t /* width from decompiler */ *param_1)



{

  float fVar1;

  

  if (param_1 != (uint32_t /* width from decompiler */ *)0x0) {

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

  }

  return;

}
