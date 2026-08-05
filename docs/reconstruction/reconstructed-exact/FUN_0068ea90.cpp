// =============================================================================
// FUN_0068ea90
// -----------------------------------------------------------------------------
// Stable ID: aa_0068ea90
// Address:   0x0068ea90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0068ea90 @ 0x0068ea90
// Stable ID: aa_0068ea90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_0068ea90.
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

void __thiscall FUN_0068ea90(float *param_1,float *param_2,float *param_3)



{

  int iVar1;

  float *pfVar2;

  float local_24 [4];

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  local_24[0] = param_1[2] * param_3[6] + *param_3 * *param_1 + param_3[3] * param_1[1];

  local_24[1] = param_3[4] * param_1[1] + param_3[1] * *param_1 + param_3[7] * param_1[2];

  local_24[2] = *param_1 * param_3[2] + param_3[8] * param_1[2] + param_3[5] * param_1[1];

  local_24[3] = param_1[3] * *param_3 + param_3[3] * param_1[4] + param_1[5] * param_3[6];

  local_14 = param_3[1] * param_1[3] + param_3[4] * param_1[4] + param_3[7] * param_1[5];

  local_10 = param_3[5] * param_1[4] + param_3[8] * param_1[5] + param_1[3] * param_3[2];

  local_c = param_1[6] * *param_3 + param_1[8] * param_3[6] + param_3[3] * param_1[7];

  local_8 = param_1[6] * param_3[1] + param_3[4] * param_1[7] + param_3[7] * param_1[8];

  local_4 = param_3[5] * param_1[7] + param_3[8] * param_1[8] + param_1[6] * param_3[2];

  pfVar2 = local_24;

  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {

    *param_2 = *pfVar2;

    pfVar2 = pfVar2 + 1;

    param_2 = param_2 + 1;

  }

  return;

}
