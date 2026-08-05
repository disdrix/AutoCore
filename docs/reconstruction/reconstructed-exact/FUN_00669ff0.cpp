// =============================================================================
// FUN_00669ff0
// -----------------------------------------------------------------------------
// Stable ID: aa_00669ff0
// Address:   0x00669ff0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00669ff0 @ 0x00669ff0
// Stable ID: aa_00669ff0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~111 non-empty decompiler lines.
//  - Control keywords: if×9, return×1.
//  - Notable callees: SQRT×5, FUN_00646a60, FUN_00669ff0.
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

void __thiscall FUN_00669ff0(int param_1,float param_2,float *param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  

  fVar13 = *(float *)(param_1 + 8);

  fVar6 = g_flOne / fVar13;

  iVar2 = FUN_00646a60(param_2);

  iVar1 = *(int *)(param_1 + 0x14);

  iVar4 = iVar2 + 1;

  if (iVar4 < iVar1) {

    if (iVar2 < 0) {

      iVar2 = 0;

      iVar4 = 1;

    }

  }

  else {

    iVar4 = iVar1 + -1;

    iVar2 = iVar1 + -2;

  }

  iVar1 = *(int *)(param_1 + 0x10);

  iVar3 = iVar4 * 0x10;

  iVar5 = iVar2 * 0x10;

  *param_3 = *(float *)(iVar3 + iVar1) - *(float *)(iVar1 + iVar5);

  param_3[1] = *(float *)(iVar3 + 4 + iVar1) - *(float *)(iVar1 + 4 + iVar5);

  param_3[2] = *(float *)(iVar3 + 8 + iVar1) - *(float *)(iVar1 + 8 + iVar5);

  param_3[3] = *(float *)(iVar3 + 0xc + iVar1) - *(float *)(iVar1 + 0xc + iVar5);

  fVar7 = *param_3 * *param_3 + param_3[1] * param_3[1] + param_3[2] * param_3[2];

  if (fVar7 == 0.0) {

    fVar7 = 0.0;

  }

  else {

    fVar7 = g_flOne / SQRT(fVar7);

  }

  *param_3 = *param_3 * fVar7;

  param_3[1] = fVar7 * param_3[1];

  param_3[2] = param_3[2] * fVar7;

  param_3[3] = param_3[3] * fVar7;

  if ((param_2 - (float)iVar2 < fVar13) && (0 < iVar2)) {

    iVar5 = (iVar2 + -1) * 0x10;

    iVar1 = *(int *)(param_1 + 0x10);

    iVar4 = iVar4 + -1;

    iVar3 = iVar4 * 0x10;

    fVar12 = *(float *)(iVar1 + 4 + iVar3) - *(float *)(iVar1 + 4 + iVar5);

    fVar8 = *(float *)(iVar1 + 8 + iVar3) - *(float *)(iVar1 + 8 + iVar5);

    fVar15 = *(float *)(iVar1 + iVar3) - *(float *)(iVar1 + iVar5);

    fVar7 = *(float *)(iVar1 + 0xc + iVar3);

    fVar9 = *(float *)(iVar1 + 0xc + iVar5);

    fVar14 = fVar8 * fVar8 + fVar12 * fVar12 + fVar15 * fVar15;

    fVar10 = 0.0;

    if (fVar14 != 0.0) {

      fVar10 = g_flOne / SQRT(fVar14);

    }

    fVar14 = (fVar13 - (param_2 - (float)iVar2)) * fVar6 * DAT_00a0f298;

    fVar11 = g_flOne - fVar14;

    *param_3 = *param_3 * fVar11 + fVar14 * fVar10 * fVar15;

    param_3[1] = fVar12 * fVar10 * fVar14 + fVar11 * param_3[1];

    param_3[2] = param_3[2] * fVar11 + fVar8 * fVar10 * fVar14;

    param_3[3] = param_3[3] * fVar11 + (fVar7 - fVar9) * fVar10 * fVar14;

    fVar7 = 0.0;

    fVar9 = *param_3 * *param_3 + param_3[1] * param_3[1] + param_3[2] * param_3[2];

    if (fVar9 != 0.0) {

      fVar7 = g_flOne / SQRT(fVar9);

    }

    *param_3 = *param_3 * fVar7;

    param_3[1] = fVar7 * param_3[1];

    param_3[2] = param_3[2] * fVar7;

    param_3[3] = param_3[3] * fVar7;

  }

  if (((float)iVar4 - param_2 < fVar13) && (iVar4 < *(int *)(param_1 + 0x14) + -1)) {

    iVar2 = *(int *)(param_1 + 0x10);

    fVar12 = *(float *)(iVar2 + 0x14 + iVar3) - *(float *)(iVar2 + 0x14 + iVar5);

    fVar15 = *(float *)(iVar2 + 0x18 + iVar3) - *(float *)(iVar2 + 0x18 + iVar5);

    fVar8 = *(float *)(iVar2 + 0x10 + iVar3) - *(float *)(iVar2 + 0x10 + iVar5);

    fVar7 = *(float *)(iVar2 + 0x1c + iVar3);

    fVar9 = *(float *)(iVar2 + 0x1c + iVar5);

    fVar14 = fVar15 * fVar15 + fVar12 * fVar12 + fVar8 * fVar8;

    fVar10 = 0.0;

    if (fVar14 != 0.0) {

      fVar10 = g_flOne / SQRT(fVar14);

    }

    fVar13 = (fVar13 - ((float)iVar4 - param_2)) * fVar6 * DAT_00a0f298;

    fVar6 = g_flOne - fVar13;

    *param_3 = *param_3 * fVar6 + fVar13 * fVar10 * fVar8;

    param_3[1] = fVar10 * fVar12 * fVar13 + fVar6 * param_3[1];

    param_3[2] = param_3[2] * fVar6 + fVar10 * fVar15 * fVar13;

    param_3[3] = param_3[3] * fVar6 + fVar10 * (fVar7 - fVar9) * fVar13;

    fVar13 = 0.0;

    fVar6 = *param_3 * *param_3 + param_3[1] * param_3[1] + param_3[2] * param_3[2];

    if (fVar6 != 0.0) {

      fVar13 = g_flOne / SQRT(fVar6);

    }

    *param_3 = *param_3 * fVar13;

    param_3[1] = fVar13 * param_3[1];

    param_3[2] = param_3[2] * fVar13;

    param_3[3] = param_3[3] * fVar13;

  }

  return;

}
