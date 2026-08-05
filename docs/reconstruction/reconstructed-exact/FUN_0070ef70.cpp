// =============================================================================
// FUN_0070ef70
// -----------------------------------------------------------------------------
// Stable ID: aa_0070ef70
// Address:   0x0070ef70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0070ef70 @ 0x0070ef70
// Stable ID: aa_0070ef70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~173 non-empty decompiler lines.
//  - Control keywords: if×14, do×4, while×4, return×2.
//  - Notable callees: FUN_0070e520×2, FUN_0070ef70.
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



void FUN_0070ef70(int param_1,int param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,int param_5,

                 int param_6,float *param_7,float param_8,float *param_9)



{

  float *pfVar1;

  float *pfVar2;

  float *pfVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  int *piVar10;

  float *pfVar11;

  float *pfVar12;

  int iVar13;

  int iVar14;

  float10 fVar15;

  float10 fVar16;

  float10 fVar17;

  

  piVar10 = (int *)param_9;

  fVar15 = (float10)FUN_0070e520(param_1,param_5);

  fVar4 = param_7[1];

  if (param_7[1] < g_flZero) {

    fVar4 = -fVar4;

  }

  fVar5 = *param_7;

  if (*param_7 <= g_flZero) {

    fVar5 = fVar5 * (float)_DAT_00a0f170;

  }

  fVar6 = param_7[2];

  if (param_7[2] <= g_flZero) {

    fVar6 = fVar6 * (float)_DAT_00a0f170;

  }

  fVar7 = (float)((int *)param_9)[2];

  if ((float)((int *)param_9)[2] < g_flZero) {

    fVar7 = -fVar7;

  }

  fVar8 = (float)((int *)param_9)[1];

  if ((float)((int *)param_9)[1] <= g_flZero) {

    fVar8 = fVar8 * (float)_DAT_00a0f170;

  }

  fVar9 = (float)((int *)param_9)[3];

  if ((float)((int *)param_9)[3] <= g_flZero) {

    fVar9 = fVar9 * (float)_DAT_00a0f170;

  }

  fVar4 = (fVar7 + fVar9 + fVar8 + fVar4 + fVar6 + fVar5) * (float)_DAT_00aaa5e0;

  if ((float)_DAT_00a0f280 < fVar4) {

    param_8 = (param_8 / fVar4) * (float)_DAT_00a0f280;

  }

  fVar5 = param_8;

  if (fVar4 < (float)_DAT_00aaa5e0) {

    fVar5 = fVar4 * param_8 + fVar4 * param_8;

  }

  iVar13 = 0;

  fVar4 = (float)_DAT_00aaa5f8 / (float)param_5;

  param_8 = 0.0;

  if (3 < param_5) {

    param_8 = 0.0;

    pfVar11 = (float *)(param_1 + param_6 * -4 + 4);

    pfVar12 = (float *)(param_2 + 4);

    param_9 = (float *)(param_1 + 0xc);

    do {

      param_8 = param_8 + fVar4;

      pfVar3 = (float *)(param_1 + (iVar13 - *piVar10) * 4);

      pfVar12[-1] = ((*pfVar11 * *param_7 + pfVar11[-1] * param_7[1] + pfVar11[-2] * param_7[2]) *

                     param_8 +

                    ((float)_DAT_00aaa5f8 - param_8) *

                    (*pfVar3 * (float)piVar10[2] +

                    pfVar3[1] * (float)piVar10[1] +

                    *(float *)(param_1 + -4 + (iVar13 - *piVar10) * 4) * (float)piVar10[3])) * fVar5

                    + param_9[-3];

      iVar14 = iVar13 - *piVar10;

      param_8 = param_8 + fVar4;

      *pfVar12 = ((pfVar11[1] * *param_7 + *pfVar11 * param_7[1] + param_7[2] * pfVar11[-1]) *

                  param_8 +

                 ((float)_DAT_00aaa5f8 - param_8) *

                 (*(float *)(param_1 + iVar14 * 4) * (float)piVar10[3] +

                 *(float *)(param_1 + 4 + iVar14 * 4) * (float)piVar10[2] +

                 *(float *)(param_1 + 8 + iVar14 * 4) * (float)piVar10[1])) * fVar5 +

                 *(float *)((int)pfVar12 + (param_1 - param_2));

      iVar14 = iVar13 - *piVar10;

      param_8 = param_8 + fVar4;

      pfVar12[1] = ((pfVar11[2] * *param_7 + *pfVar11 * param_7[2] + pfVar11[1] * param_7[1]) *

                    param_8 +

                   ((float)_DAT_00aaa5f8 - param_8) *

                   (*(float *)(param_1 + 4 + iVar14 * 4) * (float)piVar10[3] +

                   *(float *)(param_1 + 8 + iVar14 * 4) * (float)piVar10[2] +

                   *(float *)(param_1 + 0xc + iVar14 * 4) * (float)piVar10[1])) * fVar5 +

                   param_9[-1];

      iVar14 = iVar13 - *piVar10;

      param_8 = param_8 + fVar4;

      pfVar3 = pfVar11 + 3;

      pfVar1 = pfVar11 + 1;

      pfVar2 = pfVar11 + 2;

      iVar13 = iVar13 + 4;

      pfVar11 = pfVar11 + 4;

      pfVar12[2] = ((*pfVar2 * param_7[1] + param_7[2] * *pfVar1 + *pfVar3 * *param_7) * param_8 +

                   ((float)_DAT_00aaa5f8 - param_8) *

                   (*(float *)(param_1 + 8 + iVar14 * 4) * (float)piVar10[3] +

                   *(float *)(param_1 + 0xc + iVar14 * 4) * (float)piVar10[2] +

                   *(float *)(param_1 + 0x10 + iVar14 * 4) * (float)piVar10[1])) * fVar5 + *param_9;

      pfVar12 = pfVar12 + 4;

      param_9 = param_9 + 4;

    } while (iVar13 < param_5 + -3);

  }

  if (iVar13 < param_5) {

    pfVar12 = (float *)(param_1 + 4 + (iVar13 - param_6) * 4);

    pfVar11 = (float *)(param_2 + iVar13 * 4);

    do {

      param_8 = param_8 + fVar4;

      iVar14 = iVar13 - *piVar10;

      iVar13 = iVar13 + 1;

      pfVar3 = (float *)(param_1 + iVar14 * 4);

      *pfVar11 = ((*pfVar12 * *param_7 + pfVar12[-1] * param_7[1] + pfVar12[-2] * param_7[2]) *

                  param_8 +

                 ((float)_DAT_00aaa5f8 - param_8) *

                 (*pfVar3 * (float)piVar10[2] +

                 pfVar3[1] * (float)piVar10[1] + pfVar3[-1] * (float)piVar10[3])) * fVar5 +

                 *(float *)((param_1 - param_2) + -4 + (int)(pfVar11 + 1));

      pfVar12 = pfVar12 + 1;

      pfVar11 = pfVar11 + 1;

    } while (iVar13 < param_5);

  }

  piVar10[1] = (int)*param_7;

  piVar10[2] = (int)param_7[1];

  piVar10[3] = (int)param_7[2];

  *piVar10 = param_6;

  fVar16 = (float10)FUN_0070e520(param_2,param_5);

  fVar15 = (float10)(float)fVar15 / (fVar16 + (float10)_DAT_00aaa6e0);

  if (fVar15 < (float10)_DAT_00aaa5e0) {

    fVar15 = (float10)DAT_00a0f298;

  }

  if ((float10)_DAT_00aaa6f0 < fVar15) {

    fVar15 = (float10)DAT_00aaa660;

  }

  iVar13 = 0;

  if (3 < param_5) {

    fVar16 = (float10)_DAT_00a0f1d8 * fVar15;

    iVar14 = (param_5 - 4U >> 2) + 1;

    iVar13 = iVar14 * 4;

    pfVar12 = (float *)(param_2 + 8);

    do {

      iVar14 = iVar14 + -1;

      fVar17 = (float10)(float)piVar10[4] * (float10)_DAT_00a0f278 + fVar16;

      piVar10[4] = (int)(float)fVar17;

      pfVar12[-2] = (float)(fVar17 * (float10)pfVar12[-2]);

      fVar17 = (float10)(float)piVar10[4] * (float10)_DAT_00a0f278 + fVar16;

      piVar10[4] = (int)(float)fVar17;

      pfVar12[-1] = (float)(fVar17 * (float10)pfVar12[-1]);

      fVar17 = (float10)(float)piVar10[4] * (float10)_DAT_00a0f278 + fVar16;

      piVar10[4] = (int)(float)fVar17;

      *pfVar12 = (float)(fVar17 * (float10)*pfVar12);

      fVar17 = (float10)(float)piVar10[4] * (float10)_DAT_00a0f278 + fVar16;

      piVar10[4] = (int)(float)fVar17;

      pfVar12[1] = (float)(fVar17 * (float10)pfVar12[1]);

      pfVar12 = pfVar12 + 4;

    } while (iVar14 != 0);

  }

  if (param_5 <= iVar13) {

    return;

  }

  fVar16 = (float10)_DAT_00a0f1d8;

  do {

    iVar13 = iVar13 + 1;

    fVar17 = (float10)(float)piVar10[4] * (float10)_DAT_00a0f278 + fVar15 * fVar16;

    piVar10[4] = (int)(float)fVar17;

    *(float *)(param_2 + -4 + iVar13 * 4) =

         (float)(fVar17 * (float10)*(float *)(param_2 + -4 + iVar13 * 4));

  } while (iVar13 < param_5);

  return;

}
