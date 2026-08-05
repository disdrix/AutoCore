// =============================================================================
// FUN_007128b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007128b0
// Address:   0x007128b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007128b0 @ 0x007128b0
// Stable ID: aa_007128b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_007128b0.
//  - Return sites: 2.

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



void FUN_007128b0(float param_1,float *param_2)



{

  float fVar1;

  

  if (*param_2 <= DAT_00a0f6f4) {

    fVar1 = (_DAT_00a0f6e0 - *param_2 * _DAT_00a0f6e4) * *param_2 + _DAT_00a0f6dc;

  }

  else {

    fVar1 = (_DAT_00a0f6ec - *param_2 * _DAT_00a0f6f0) * *param_2 + _DAT_00a0f6e8;

  }

  param_2[1] = fVar1;

  if (fVar1 < param_1) {

    *(uint8_t *)((int)param_2 + 0x13) = 1;

    return;

  }

  *(uint8_t *)((int)param_2 + 0x13) = 0;

  return;

}
