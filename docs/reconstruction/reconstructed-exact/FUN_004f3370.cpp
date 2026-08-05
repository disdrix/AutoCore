// =============================================================================
// FUN_004f3370
// -----------------------------------------------------------------------------
// Stable ID: aa_004f3370
// Address:   0x004f3370  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004f3370 @ 0x004f3370
// Stable ID: aa_004f3370
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_004f3370.
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

float * __thiscall FUN_004f3370(float *param_1,uint8_t param_2)



{

  float fVar1;

  int iVar2;

  float *pfVar3;

  

  fVar1 = g_flOne;

  param_1[0xb] = 0.0;

  param_1[10] = 0.0;

  param_1[9] = 0.0;

  param_1[0x14] = 0.0;

  param_1[0x15] = 0.0;

  param_1[0x16] = 0.0;

  pfVar3 = param_1;

  for (iVar2 = 0x18; iVar2 != 0; iVar2 = iVar2 + -1) {

    *pfVar3 = 0.0;

    pfVar3 = pfVar3 + 1;

  }

  param_1[0xc] = 0.0;

  param_1[0xd] = 0.0;

  *param_1 = fVar1;

  param_1[1] = 0.0;

  param_1[2] = 0.0;

  param_1[3] = 0.0;

  param_1[4] = fVar1;

  param_1[5] = 0.0;

  param_1[6] = 0.0;

  param_1[7] = 0.0;

  param_1[8] = fVar1;

  param_1[0xb] = 0.0;

  param_1[10] = 0.0;

  param_1[9] = 0.0;

  param_1[0xe] = 0.0;

  param_1[0x10] = 0.0;

  param_1[0x11] = 0.0;

  *(uint16_t *)(param_1 + 0xf) = 0;

  param_1[0x12] = 0.0;

  param_1[0x15] = param_1[0x14];

  param_1[0x13] = 1.4013e-45;

  *(uint8_t *)(param_1 + 0x18) = param_2;

  return param_1;

}
