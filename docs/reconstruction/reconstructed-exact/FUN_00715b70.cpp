// =============================================================================
// FUN_00715b70
// -----------------------------------------------------------------------------
// Stable ID: aa_00715b70
// Address:   0x00715b70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00715b70 @ 0x00715b70
// Stable ID: aa_00715b70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~205 non-empty decompiler lines.
//  - Control keywords: do×13, while×13, if×6, return×2.
//  - Notable callees: FUN_00714450, FUN_00715b70, FUN_00717920, ROUND, ftol.
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



void FUN_00715b70(float *param_1,float param_2,float *param_3,float param_4,short param_5,

                 short param_6,int param_7,uint32_t /* width from decompiler */ *param_8)



{

  float fVar1;

  float fVar2;

  float10 fVar3;

  float *pfVar4;

  float *pfVar5;

  float *pfVar6;

  float *pfVar7;

  float *pfVar8;

  float *pfVar9;

  float *pfVar10;

  float *pfVar11;

  int iVar12;

  int iVar13;

  float10 fVar14;

  float10 fVar15;

  float10 extraout_ST0;

  float10 extraout_ST1;

  float local_24c [13];

  float local_218 [62];

  float local_120 [66];

  float local_18 [2];

  float *local_10;

  float *local_c;

  float local_8;

  

  pfVar4 = param_3;

  local_c = param_3 + 0x243;

  (*(code *)PTR_memset_00af8a50)(param_3,0,0x90c);

  iVar13 = 0xc;

  pfVar8 = param_3;

  do {

    fVar1 = *param_1;

    param_1 = param_1 + 1;

    iVar13 = iVar13 + -1;

    *pfVar8 = *(float *)(&DAT_00a12864 + ((int)ROUND(_DAT_00a12d68 * fVar1) & 0xffU) * 4);

    pfVar8 = pfVar8 + 1;

  } while (iVar13 != 0);

  param_1 = (float *)0x0;

  iVar13 = 4;

  param_3[0x38] = 1.0;

  local_10 = local_24c;

  pfVar8 = param_3 + 0x38;

  do {

    pfVar6 = local_10;

    local_8 = *(float *)((int)param_3 + iVar13 + -4);

    *(float *)(iVar13 + (int)pfVar6) = -local_8;

    local_10 = pfVar8;

    if (7 < iVar13) {

      pfVar9 = (float *)(iVar13 + -4 + (int)pfVar8);

      pfVar5 = pfVar6 + 1;

      iVar12 = (int)param_1;

      do {

        fVar1 = *pfVar9;

        pfVar9 = pfVar9 + -1;

        iVar12 = iVar12 + -1;

        *pfVar5 = *(float *)((int)pfVar8 + (-4 - (int)pfVar6) + (int)(pfVar5 + 1)) - local_8 * fVar1

        ;

        pfVar5 = pfVar5 + 1;

      } while (iVar12 != 0);

    }

    iVar13 = iVar13 + 4;

    param_1 = (float *)((int)param_1 + 1);

    pfVar8 = pfVar6;

  } while (iVar13 < 0x34);

  iVar13 = (int)param_3 + (0xe0 - (int)param_8);

  iVar12 = (int)param_3 - (int)param_8;

  param_7 = param_7 - (int)param_8;

  param_3 = (float *)0xc;

  do {

    *param_8 = *(uint32_t /* width from decompiler */ *)(iVar13 + (int)param_8);

    *(uint32_t /* width from decompiler */ *)(param_7 + (int)param_8) = *(uint32_t /* width from decompiler */ *)(iVar12 + (int)param_8);

    param_8 = param_8 + 1;

    param_3 = (float *)((int)param_3 + -1);

  } while (param_3 != (float *)0x0);

  pfVar4[0xc] = param_2;

  pfVar8 = pfVar4 + 0xd;

  param_3 = (float *)0x1;

  pfVar6 = pfVar8;

  iVar13 = (int)param_3;

  do {

    param_3 = (float *)iVar13;

    fVar1 = -((float)(int)param_3 *

             *(float *)((int)pfVar4 + (0xe0 - (int)(pfVar4 + 0xc)) + (int)pfVar6));

    if (1 < (int)param_3) {

      pfVar9 = pfVar4 + 0x39;

      iVar13 = (int)param_3 + -1;

      pfVar5 = pfVar6;

      do {

        pfVar5 = pfVar5 + -1;

        fVar2 = *pfVar9;

        pfVar9 = pfVar9 + 1;

        iVar13 = iVar13 + -1;

        fVar1 = fVar1 - fVar2 * *pfVar5;

      } while (iVar13 != 0);

    }

    *pfVar6 = fVar1;

    iVar13 = (int)param_3 + 1;

    pfVar6 = pfVar6 + 1;

  } while (iVar13 < 0xd);

  if (iVar13 < 0x2c) {

    iVar13 = 0x2c - iVar13;

    pfVar6 = pfVar4 + (int)param_3 + 0xd;

    do {

      pfVar9 = pfVar4 + 0x39;

      iVar12 = 0xc;

      pfVar5 = pfVar6;

      fVar1 = g_flZero;

      do {

        pfVar5 = pfVar5 + -1;

        fVar2 = *pfVar9;

        pfVar9 = pfVar9 + 1;

        iVar12 = iVar12 + -1;

        fVar1 = fVar1 - fVar2 * *pfVar5;

      } while (iVar12 != 0);

      *pfVar6 = fVar1;

      pfVar6 = pfVar6 + 1;

      iVar13 = iVar13 + -1;

    } while (iVar13 != 0);

  }

  iVar13 = 0x2b;

  pfVar6 = pfVar8;

  do {

    iVar13 = iVar13 + -1;

    *pfVar6 = *(float *)(((int)&DAT_00a111b4 - (int)(pfVar4 + 0xc)) + (int)pfVar6) * *pfVar6;

    pfVar6 = pfVar6 + 1;

  } while (iVar13 != 0);

  (*(code *)PTR_memset_00af8a50)(local_120 + 3,0,0x104);

  (*(code *)PTR_memset_00af8a50)(local_218,0,0x104);

  local_120[3] = pfVar4[0xc];

  param_1 = (float *)0x15;

  pfVar6 = local_218;

  pfVar9 = local_120 + 1;

  pfVar5 = local_120 + 4;

  param_3 = local_18;

  do {

    pfVar10 = pfVar6 + 1;

    pfVar11 = pfVar9 + -1;

    *pfVar6 = *pfVar8 * _DAT_00a1126c;

    pfVar7 = pfVar8 + 2;

    *pfVar9 = *pfVar8 * _DAT_00a11268;

    *pfVar5 = pfVar8[1] * _DAT_00a1126c;

    *param_3 = pfVar8[1] * _DAT_00a11268;

    param_1 = (float *)((int)param_1 + -1);

    pfVar8 = pfVar7;

    pfVar6 = pfVar10;

    pfVar9 = pfVar11;

    pfVar5 = pfVar5 + 1;

    param_3 = param_3 + -1;

  } while (param_1 != (float *)0x0);

  *pfVar10 = *pfVar7 * _DAT_00a1126c;

  *pfVar11 = *pfVar7 * _DAT_00a11268;

  FUN_00714450(local_120 + 3,local_218,0x80);

  iVar13 = 0x41;

  pfVar8 = local_c;

  do {

    *(uint32_t /* width from decompiler */ *)((int)pfVar4 + (0x808 - (int)local_c) + (int)pfVar8) =

         *(uint32_t /* width from decompiler */ *)((int)pfVar8 + (int)local_120 + -(int)local_c + 0xc);

    iVar13 = iVar13 + -1;

    *pfVar8 = *(float *)((int)pfVar8 + (int)local_218 + -(int)local_c);

    pfVar8 = pfVar8 + 1;

  } while (iVar13 != 0);

  FUN_00717920(pfVar4 + 0x202,param_2,pfVar4);

  fVar14 = (float10)g_flZero;

  fVar15 = (float10)g_flZero;

  if (((param_4 == g_flOne) && (param_5 == 0)) && (param_6 == 0)) {

    return;

  }

  iVar13 = 0;

  pfVar8 = pfVar4;

  do {

    if (iVar13 < param_6) {

      *pfVar8 = pfVar8[0x202];

    }

    else {

      iVar12 = ftol();

      iVar12 = iVar12 + param_5;

      *pfVar8 = pfVar4[iVar12 + 0x202];

      fVar15 = extraout_ST0;

      fVar14 = extraout_ST1;

      if (iVar12 < 0x41) {

        *pfVar8 = pfVar4[iVar12 + 0x202];

      }

      else {

        *pfVar8 = pfVar4[0x242];

      }

    }

    fVar14 = fVar14 + (float10)pfVar8[0x202];

    fVar15 = fVar15 + (float10)*pfVar8;

    iVar13 = iVar13 + 1;

    pfVar8 = pfVar8 + 1;

  } while (iVar13 < 0x41);

  iVar13 = 0x41;

  fVar3 = (float10)_DAT_00a11264;

  pfVar8 = pfVar4 + 0x202;

  do {

    iVar13 = iVar13 + -1;

    *pfVar8 = (float)((fVar14 - fVar15) * fVar3 +

                     (float10)*(float *)(((int)pfVar4 - (int)(pfVar4 + 0x202)) + (int)pfVar8));

    pfVar8 = pfVar8 + 1;

  } while (iVar13 != 0);

  return;

}
