// =============================================================================
// FUN_00707080
// -----------------------------------------------------------------------------
// Stable ID: aa_00707080
// Address:   0x00707080  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00707080 @ 0x00707080
// Stable ID: aa_00707080
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_00702cb0×5, FUN_00707080.
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



void FUN_00707080(float *param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  int local_4;

  

  local_4 = 0;

  if (0 < param_2) {

    do {

      iVar1 = local_4 + 1;

      param_1[local_4] = ((float)local_4 + (float)_DAT_00aaa5f8) * (float)_DAT_00a0f1e8;

      local_4 = iVar1;

    } while (iVar1 < param_2);

  }

  iVar1 = FUN_00702cb0(param_3,6);

  iVar1 = iVar1 * 10;

  *param_1 = (float)(int)(char)(&DAT_00af7e38)[iVar1] * (float)_DAT_00a0f1f8 + *param_1;

  param_1[1] = (float)(int)(char)(&DAT_00af7e39)[iVar1] * (float)_DAT_00a0f1f8 + param_1[1];

  param_1[2] = (float)(int)(char)(&DAT_00af7e3a)[iVar1] * (float)_DAT_00a0f1f8 + param_1[2];

  param_1[3] = (float)(int)(char)(&DAT_00af7e3b)[iVar1] * (float)_DAT_00a0f1f8 + param_1[3];

  param_1[4] = (float)(int)(char)(&DAT_00af7e3c)[iVar1] * (float)_DAT_00a0f1f8 + param_1[4];

  param_1[5] = (float)(int)(char)(&DAT_00af7e3d)[iVar1] * (float)_DAT_00a0f1f8 + param_1[5];

  param_1[6] = (float)(int)(char)(&DAT_00af7e3e)[iVar1] * (float)_DAT_00a0f1f8 + param_1[6];

  param_1[7] = (float)(int)(char)(&DAT_00af7e3f)[iVar1] * (float)_DAT_00a0f1f8 + param_1[7];

  param_1[8] = (float)(int)(char)(&DAT_00af7e40)[iVar1] * (float)_DAT_00a0f1f8 + param_1[8];

  param_1[9] = (float)(int)(char)(&DAT_00af7e41)[iVar1] * (float)_DAT_00a0f1f8 + param_1[9];

  iVar1 = FUN_00702cb0(param_3,6);

  *param_1 = (float)(int)(char)(&DAT_00af80b8)[iVar1 * 5] * (float)_DAT_00a0f1f0 + *param_1;

  param_1[1] = (float)(int)(char)(&DAT_00af80b9)[iVar1 * 5] * (float)_DAT_00a0f1f0 + param_1[1];

  param_1[2] = (float)(int)(char)(&DAT_00af80ba)[iVar1 * 5] * (float)_DAT_00a0f1f0 + param_1[2];

  param_1[3] = (float)(int)(char)(&DAT_00af80bb)[iVar1 * 5] * (float)_DAT_00a0f1f0 + param_1[3];

  param_1[4] = (float)(int)(char)(&DAT_00af80bc)[iVar1 * 5] * (float)_DAT_00a0f1f0 + param_1[4];

  iVar1 = FUN_00702cb0(param_3,6);

  *param_1 = (float)(int)(char)(&DAT_00af81f8)[iVar1 * 5] * (float)_DAT_00a0f1e0 + *param_1;

  param_1[1] = (float)(int)(char)(&DAT_00af81f9)[iVar1 * 5] * (float)_DAT_00a0f1e0 + param_1[1];

  param_1[2] = (float)(int)(char)(&DAT_00af81fa)[iVar1 * 5] * (float)_DAT_00a0f1e0 + param_1[2];

  param_1[3] = (float)(int)(char)(&DAT_00af81fb)[iVar1 * 5] * (float)_DAT_00a0f1e0 + param_1[3];

  param_1[4] = (float)(int)(char)(&DAT_00af81fc)[iVar1 * 5] * (float)_DAT_00a0f1e0 + param_1[4];

  iVar1 = FUN_00702cb0(param_3,6);

  param_1[5] = (float)(int)(char)(&DAT_00af8338)[iVar1 * 5] * (float)_DAT_00a0f1f0 + param_1[5];

  param_1[6] = (float)(int)(char)(&DAT_00af8339)[iVar1 * 5] * (float)_DAT_00a0f1f0 + param_1[6];

  param_1[7] = (float)(int)(char)(&DAT_00af833a)[iVar1 * 5] * (float)_DAT_00a0f1f0 + param_1[7];

  param_1[8] = (float)(int)(char)(&DAT_00af833b)[iVar1 * 5] * (float)_DAT_00a0f1f0 + param_1[8];

  param_1[9] = (float)(int)(char)(&DAT_00af833c)[iVar1 * 5] * (float)_DAT_00a0f1f0 + param_1[9];

  iVar1 = FUN_00702cb0(param_3,6);

  param_1[5] = (float)(int)(char)(&DAT_00af8478)[iVar1 * 5] * (float)_DAT_00a0f1e0 + param_1[5];

  param_1[6] = (float)(int)(char)(&DAT_00af8479)[iVar1 * 5] * (float)_DAT_00a0f1e0 + param_1[6];

  param_1[7] = (float)(int)(char)(&DAT_00af847a)[iVar1 * 5] * (float)_DAT_00a0f1e0 + param_1[7];

  param_1[8] = (float)(int)(char)(&DAT_00af847b)[iVar1 * 5] * (float)_DAT_00a0f1e0 + param_1[8];

  param_1[9] = (float)(int)(char)(&DAT_00af847c)[iVar1 * 5] * (float)_DAT_00a0f1e0 + param_1[9];

  return;

}
