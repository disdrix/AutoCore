// =============================================================================
// FUN_00788be0
// -----------------------------------------------------------------------------
// Stable ID: aa_00788be0
// Address:   0x00788be0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00788be0 @ 0x00788be0
// Stable ID: aa_00788be0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0076f5f0, FUN_00788be0.
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

void FUN_00788be0(float *param_1,float *param_2,float *param_3)



{

  float local_24;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  local_18 = param_3[2] * param_2[1] - param_3[1] * param_2[2];

  local_14 = *param_3 * param_2[2] - param_3[2] * *param_2;

  local_10 = param_3[1] * *param_2 - *param_3 * param_2[1];

  local_24 = param_3[1] * local_10 - param_3[2] * local_14;

  local_20 = param_3[2] * local_18 - *param_3 * local_10;

  local_1c = *param_3 * local_14 - param_3[1] * local_18;

  local_c = local_24;

  local_8 = local_20;

  local_4 = local_1c;

  FUN_0076f5f0(&local_24,&local_24);

  *param_1 = local_24;

  param_1[1] = local_20;

  param_1[2] = local_1c;

  return;

}
