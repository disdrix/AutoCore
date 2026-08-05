// =============================================================================
// FUN_006ccaa0
// -----------------------------------------------------------------------------
// Stable ID: aa_006ccaa0
// Address:   0x006ccaa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006ccaa0 @ 0x006ccaa0
// Stable ID: aa_006ccaa0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_006ccaa0, FUN_00718350.
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

uint32_t /* width from decompiler */ * __thiscall FUN_006ccaa0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float10 fVar6;

  

  *param_1 = &PTR_FUN_009e5fdc;

  *(uint16_t *)((int)param_1 + 6) = 1;

  param_1[2] = *param_2;

  *param_1 = &PTR_FUN_00a0d97c;

  param_1[3] = param_2[8];

  param_1[4] = param_2[9];

  fVar4 = (float)(int)param_2[9] - g_flOne;

  fVar2 = (float)param_2[0xb];

  fVar3 = (float)param_2[10];

  iVar1 = param_2[8];

  param_1[0x17] = 0;

  param_1[0x14] = (float)iVar1 - g_flOne;

  param_1[0x15] = fVar2 - fVar3;

  param_1[0x16] = fVar4;

  param_1[0x14] = (float)param_2[4] * (float)param_1[0x14];

  param_1[0x15] = (float)param_2[5] * (float)param_1[0x15];

  param_1[0x16] = (float)param_2[6] * (float)param_1[0x16];

  param_1[0x17] = (float)param_2[7] * (float)param_1[0x17];

  if ((float)param_2[10] <= (float)param_2[0xb]) {

    param_1[6] = ((float)param_2[0xb] + (float)param_2[10]) * DAT_00a0f298;

  }

  else {

    param_1[6] = 0xbf800000;

    param_1[0x15] = 0xbf800000;

  }

  fVar5 = g_flOne;

  param_1[8] = param_2[4];

  param_1[9] = param_2[5];

  param_1[10] = param_2[6];

  param_1[0xb] = param_2[7];

  fVar2 = (float)param_2[6];

  fVar3 = g_flOne / (float)param_2[5];

  fVar4 = g_flOne / (float)param_2[4];

  param_1[0xf] = 0;

  param_1[0xc] = fVar4;

  param_1[0xd] = fVar3;

  param_1[0xe] = fVar5 / fVar2;

  fVar6 = (float10)FUN_00718350();

  param_1[0x11] = 0;

  param_1[0x13] = (float)(fVar6 * (float10)(float)param_1[0xb]);

  param_1[0x10] = (float)(fVar6 * (float10)(float)param_1[8]);

  param_1[0x12] = (float)(fVar6 * (float10)(float)param_1[10]);

  return param_1;

}
