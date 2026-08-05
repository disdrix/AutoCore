// =============================================================================
// FUN_005ba440
// -----------------------------------------------------------------------------
// Stable ID: aa_005ba440
// Address:   0x005ba440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005ba440 @ 0x005ba440
// Stable ID: aa_005ba440
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~385 non-empty decompiler lines.
//  - Control keywords: if×27, return×5, goto×3, do×2, while×2.
//  - Notable callees: FUN_0076f5f0×5, FUN_0076e240×3, CONCAT31, CVOGReaction_RandomUnitScalar, FUN_00404c00, FUN_0040d020, FUN_004b0e90, FUN_005b83e0.
//  - Return sites: 5.

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

uint32_t /* width from decompiler */ __thiscall FUN_005ba440(int *param_1,float param_2)



{

  float *pfVar1;

  float fVar2;

  ushort uVar3;

  uint uVar4;

  int iVar5;

  int *piVar6;

  int iVar7;

  float *pfVar8;

  int *piVar9;

  int *piVar10;

  float10 fVar11;

  float10 fVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fStack_82c;

  float fStack_828;

  float fStack_824;

  float fStack_820;

  float fStack_81c;

  float fStack_818;

  float fStack_814;

  float fStack_810;

  float fStack_80c;

  float fStack_808;

  float fStack_804;

  float fStack_800;

  float fStack_7fc;

  float fStack_7f8;

  float fStack_7f4;

  float fStack_7f0;

  float fStack_7ec;

  float fStack_7e8;

  float fStack_7e4;

  float fStack_7e0;

  float fStack_7dc;

  float fStack_7d8;

  float afStack_7d4 [501];

  

  *(int *)(DAT_00d17958 + 0x158) = *(int *)(DAT_00d17958 + 0x158) + 1;

  if ((param_1[1] != 0) && ((*(byte *)(param_1[1] + 0x90e) & 1) != 0)) {

    *(byte *)((int)param_1 + 0x179) = *(byte *)((int)param_1 + 0x179) | 2;

    param_1[1] = 0;

  }

  uVar4 = param_1[0x5e];

  if ((uVar4 & 0x1000) != 0) {

    param_1[0x5e] = uVar4 & 0xffffefff;

    return 1;

  }

  if (((uVar4 & 0x200) != 0) && (param_1[0x23] != 0)) {

    param_1[0x5e] = uVar4 | 0x100;

  }

  fVar15 = g_flZero;

  if ((*(byte *)((int)param_1 + 0x179) & 1) != 0) {

    return 0;

  }

  fVar13 = (float)param_1[0xd];

  param_1[0xd] = (int)(fVar13 - param_2);

  if (fVar15 < fVar13 - param_2) {

    return 1;

  }

  iVar7 = param_1[1];

  if (iVar7 == 0) {

    if (*param_1 != 0) {

      piVar9 = *(int **)(*param_1 + 0x10);

      if ((piVar9 != (int *)0x0) && (((uint)piVar9[0x5f] >> 6 & 1) != 0)) {

        iVar7 = (**(code **)(*piVar9 + 0x1cc))();

        pfVar8 = (float *)(param_1 + 0x41);

        (**(code **)(*(int *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7) + 0x108))

                  (param_1[9],pfVar8,&fStack_81c,param_1[10]);

        fVar2 = g_flLevelUpUiBase_Inferred;

        fStack_7fc = fStack_814 * fStack_818;

        fStack_820 = fStack_810 * fStack_818;

        fVar15 = (fStack_7fc - fStack_810 * fStack_81c) * g_flLevelUpUiBase_Inferred;

        fStack_80c = fStack_81c * fStack_81c;

        fVar13 = g_flOne - (fStack_80c + fStack_818 * fStack_818) * g_flLevelUpUiBase_Inferred;

        param_1[0x38] = (int)((fStack_814 * fStack_81c + fStack_820) * g_flLevelUpUiBase_Inferred);

        param_1[0x39] = (int)fVar15;

        param_1[0x3a] = (int)fVar13;

        param_1[0x3b] = (int)(g_flOne - (fStack_814 * fStack_814 + fStack_818 * fStack_818) * fVar2)

        ;

        param_1[0x3c] = (int)((fStack_818 * fStack_81c + fStack_810 * fStack_814) * fVar2);

        param_1[0x3d] = (int)((fStack_814 * fStack_81c - fStack_820) * fVar2);

        fVar15 = (float)param_1[0x4a];

        fVar13 = (float)param_1[0x4c];

        fVar14 = g_flOne - (fStack_814 * fStack_814 + fStack_80c) * fVar2;

        param_1[0x3e] = (int)((fStack_818 * fStack_81c - fStack_810 * fStack_814) * fVar2);

        param_1[0x3f] = (int)fVar14;

        param_1[0x40] = (int)((fStack_810 * fStack_81c + fStack_7fc) * fVar2);

        fVar2 = (float)param_1[0x4b];

        fStack_818 = (float)param_1[0x3f] * fVar2;

        fStack_814 = (float)param_1[0x40] * fVar2;

        fStack_82c = fVar15 * (float)param_1[0x3b] + fVar2 * (float)param_1[0x3e] +

                     (float)param_1[0x38] * fVar13;

        param_1[0x4d] = (int)fStack_82c;

        fStack_828 = (float)param_1[0x3c] * fVar15 + fStack_818 + (float)param_1[0x39] * fVar13;

        param_1[0x4e] = (int)fStack_828;

        fStack_824 = (float)param_1[0x3d] * fVar15 + fStack_814 + (float)param_1[0x3a] * fVar13;

        param_1[0x4f] = (int)fStack_824;

        *pfVar8 = (float)param_1[0x4d] + *pfVar8;

        param_1[0x42] = (int)((float)param_1[0x4e] + (float)param_1[0x42]);

        param_1[0x43] = (int)((float)param_1[0x4f] + (float)param_1[0x43]);

      }

      goto LAB_005baa5c;

    }

  }

  else {

    if (*(int **)(iVar7 + 0x914) == (int *)0x0) {

      pfVar8 = (float *)(iVar7 + 0x824);

    }

    else {

      iVar7 = (**(code **)(**(int **)(iVar7 + 0x914) + 0xc))();

      pfVar8 = (float *)(iVar7 + 0x90);

    }

    pfVar1 = (float *)(param_1 + 0x41);

    *pfVar1 = *pfVar8;

    param_1[0x42] = (int)pfVar8[1];

    iVar7 = param_1[1];

    param_1[0x43] = (int)pfVar8[2];

    fVar15 = (float)param_1[0x4c];

    param_1[0x38] = (int)*(float *)(iVar7 + 0x830);

    param_1[0x39] = *(int *)(iVar7 + 0x834);

    param_1[0x3a] = *(int *)(iVar7 + 0x838);

    fVar13 = (float)param_1[0x4a];

    param_1[0x3b] = (int)*(float *)(iVar7 + 0x83c);

    param_1[0x3c] = *(int *)(iVar7 + 0x840);

    param_1[0x3d] = *(int *)(iVar7 + 0x844);

    iVar7 = param_1[1];

    param_1[0x3e] = *(int *)(iVar7 + 0x848);

    param_1[0x3f] = *(int *)(iVar7 + 0x84c);

    param_1[0x40] = *(int *)(iVar7 + 0x850);

    fVar2 = (float)param_1[0x4b];

    fStack_818 = (float)param_1[0x3f] * fVar2;

    fStack_814 = (float)param_1[0x40] * fVar2;

    fStack_82c = fVar13 * (float)param_1[0x3b] + (float)param_1[0x3e] * fVar2 +

                 fVar15 * (float)param_1[0x38];

    pfVar8 = (float *)(param_1 + 0x4d);

    *pfVar8 = fStack_82c;

    fStack_828 = (float)param_1[0x3c] * fVar13 + fStack_818 + (float)param_1[0x39] * fVar15;

    param_1[0x4e] = (int)fStack_828;

    fStack_824 = (float)param_1[0x3d] * fVar13 + fStack_814 + (float)param_1[0x3a] * fVar15;

    param_1[0x4f] = (int)fStack_824;

    *pfVar1 = *pfVar1 + *pfVar8;

    param_1[0x42] = (int)((float)param_1[0x4e] + (float)param_1[0x42]);

    param_1[0x43] = (int)((float)param_1[0x4f] + (float)param_1[0x43]);

    iVar7 = param_1[1];

    fVar15 = *(float *)(iVar7 + 0x828);

    fVar13 = *(float *)(iVar7 + 0x82c);

    *pfVar8 = *pfVar8 + ((*pfVar1 - *pfVar8) - *(float *)(iVar7 + 0x824));

    param_1[0x4e] =

         (int)((((float)param_1[0x42] - (float)param_1[0x4e]) - fVar15) + (float)param_1[0x4e]);

    param_1[0x4f] =

         (int)((((float)param_1[0x43] - (float)param_1[0x4f]) - fVar13) + (float)param_1[0x4f]);

    if ((param_1[0x5e] & 0x400U) == 0) {

      if (*param_1 == 0) goto LAB_005baa80;

      piVar9 = *(int **)(*param_1 + 0x10);

      if (((piVar9 != (int *)0x0) && (-1 < (char)param_1[0x5e])) &&

         (((uint)piVar9[0x5f] >> 6 & 1) != 0)) {

        iVar7 = (**(code **)(*piVar9 + 0x1cc))();

        pfVar8 = (float *)(param_1 + 0x32);

        (**(code **)(*(int *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7) + 0x108))

                  (param_1[9],pfVar8,&fStack_81c,param_1[10]);

        if ((char)param_1[0x5e] < '\0') {

          if ((param_1[0x5e] & 0x800U) != 0) {

            param_1[0x35] = (int)*pfVar8;

            param_1[0x36] = param_1[0x33];

            param_1[0x37] = param_1[0x34];

          }

          fStack_82c = *pfVar8 - (float)param_1[0x35];

          fStack_828 = (float)param_1[0x33] - (float)param_1[0x36];

          fStack_824 = (float)param_1[0x34] - (float)param_1[0x37];

          *pfVar8 = fStack_82c;

          param_1[0x33] = (int)fStack_828;

          param_1[0x34] = (int)fStack_824;

        }

      }

    }

LAB_005baa5c:

    if (*param_1 != 0) {

      param_1[0x12] = (int)((float)param_1[0x12] - *(float *)(*param_1 + 0x34) * param_2);

      goto LAB_005baa93;

    }

  }

LAB_005baa80:

  param_1[0x12] = (int)((float)param_1[0x12] - param_2);

LAB_005baa93:

  if (0.0 < (float)param_1[0x12]) {

    FUN_005b83e0();

    if ((-1 < (char)param_1[0x5e]) &&

       (fVar15 = (float)param_1[0x11], param_1[0x11] = (int)(fVar15 - param_2),

       fVar15 - param_2 <= 0.0)) {

      if (((param_1[0x5e] & 0x200U) == 0) && (param_1[0x23] < param_1[0x22])) {

        param_1[0x23] = param_1[0x23] + 1;

        piVar9 = operator_new(0x34);

        if (piVar9 == (int *)0x0) {

          piVar9 = (int *)0x0;

        }

        else {

          *(uint8_t *)((int)piVar9 + 0x2e) = 0xff;

          *(uint8_t *)((int)piVar9 + 0x2d) = 0xff;

          *(uint8_t *)(piVar9 + 0xb) = 0xff;

          *(uint8_t *)((int)piVar9 + 0x2f) = 0xff;

        }

        piVar9[2] = param_1[0x41];

        piVar9[3] = param_1[0x42];

        piVar9[4] = param_1[0x43];

        *piVar9 = param_1[0x31];

        piVar9[1] = *(int *)(param_1[0x31] + 4);

        **(uint32_t /* width from decompiler */ **)(param_1[0x31] + 4) = piVar9;

        *(int **)(param_1[0x31] + 4) = piVar9;

        param_1[0x31] = (int)piVar9;

      }

      else {

        iVar7 = *(int *)(param_1[0x31] + 4);

        *(int *)(iVar7 + 8) = param_1[0x41];

        *(int *)(iVar7 + 0xc) = param_1[0x42];

        *(int *)(iVar7 + 0x10) = param_1[0x43];

        param_1[0x31] = *(int *)(param_1[0x31] + 4);

      }

      param_1[0x11] = param_1[0x10];

    }

    if ((*(byte *)((int)param_1 + 0x179) & 8) == 0) {

      fStack_81c = (float)param_1[0x47] - (float)param_1[0x41];

      fStack_818 = (float)param_1[0x48] - (float)param_1[0x42];

      fStack_814 = (float)param_1[0x49] - (float)param_1[0x43];

      fVar11 = (float10)FUN_00404c00();

      param_1[0x47] = param_1[0x41];

      param_1[0x48] = param_1[0x42];

      param_1[0x49] = param_1[0x43];

      param_1[0x50] = (int)(float)(fVar11 / (float10)param_2);

    }

    else {

      param_1[0x13] = param_1[0x12];

      if (param_1[0x14] != 0) {

        iVar7 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar7 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar7 + 0xc) = 0;

        }

        uVar3 = *(ushort *)(*(int *)(iVar7 + 8) + *(int *)(iVar7 + 0xc) * 2);

        *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;

        param_1[0x1d] = param_1[(int)((longlong)(ulonglong)uVar3 % (longlong)param_1[0x14]) + 0x15];

      }

      pfVar8 = (float *)(param_1 + 0x1e);

      FUN_004b0e90(pfVar8,param_1[0x1d]);

      fVar13 = DAT_00a0f298;

      *pfVar8 = *pfVar8 - DAT_009cb14c * DAT_00a0f298;

      fVar15 = DAT_009cb14c;

      *(byte *)((int)param_1 + 0x179) = *(byte *)((int)param_1 + 0x179) | 0x80;

      param_1[0x47] = param_1[0x41];

      param_1[0x48] = param_1[0x42];

      param_1[0x20] = (int)(fVar15 * fVar13 + (float)param_1[0x20]);

      param_1[0x49] = param_1[0x43];

      if ((char)param_1[0x5e] < '\0') {

        FUN_005b9040();

      }

      else {

        iVar7 = param_1[0x31];

        *(int *)(iVar7 + 8) = param_1[0x41];

        *(int *)(iVar7 + 0xc) = param_1[0x42];

        *(int *)(iVar7 + 0x10) = param_1[0x43];

      }

    }

    fVar15 = fStack_820;

    uVar4 = param_1[0x5e];

    if ((char)uVar4 < '\0') {

      fStack_820 = (float)((uint)fStack_820 & 0xffffff00);

      if ((((uVar4 & 0x800) == 0) && ((uVar4 & 0x40) != 0)) &&

         (fVar13 = (float)param_1[0x11], param_1[0x11] = (int)(fVar13 - param_2),

         fVar13 - param_2 <= 0.0)) {

        fStack_820 = (float)CONCAT31(SUB43(fVar15,1),1);

        param_1[0x11] = param_1[0x10];

      }

      FUN_005b9ac0(fStack_820);

    }

    else {

      piVar9 = (int *)param_1[0x31];

      fVar11 = (float10)FUN_0040d020((float)piVar9[2] - (float)param_1[0x41],

                                     (float)piVar9[3] - (float)param_1[0x42],

                                     (float)piVar9[4] - (float)param_1[0x43]);

      afStack_7d4[0] = (float)fVar11;

      iVar7 = 0;

      if (param_1[0x23] != 1 && -1 < param_1[0x23] + -1) {

        iVar5 = param_1[0x23];

        piVar10 = piVar9;

        do {

          piVar6 = (int *)*piVar10;

          iVar7 = iVar7 + 1;

          fVar12 = SQRT(((float10)(float)piVar10[4] - (float10)(float)piVar6[4]) *

                        ((float10)(float)piVar10[4] - (float10)(float)piVar6[4]) +

                        ((float10)(float)piVar10[3] - (float10)(float)piVar6[3]) *

                        ((float10)(float)piVar10[3] - (float10)(float)piVar6[3]) +

                        ((float10)(float)piVar10[2] - (float10)(float)piVar6[2]) *

                        ((float10)(float)piVar10[2] - (float10)(float)piVar6[2]));

          afStack_7d4[iVar7] = (float)fVar12;

          fVar11 = fVar12 + fVar11;

          piVar10 = piVar6;

        } while (iVar7 < iVar5 + -1);

      }

      fStack_820 = (float)fVar11;

      fStack_828 = (float)param_1[0x42] - (float)piVar9[3];

      fStack_82c = (float)param_1[0x41] - (float)piVar9[2];

      fStack_80c = 0.0;

      fStack_824 = (float)param_1[0x43] - (float)piVar9[4];

      pfVar8 = (float *)(param_1 + 0x44);

      fStack_808 = fStack_82c;

      fStack_804 = fStack_828;

      fStack_800 = fStack_824;

      FUN_0076e240(pfVar8,DAT_00b04c70 + 0x294,&fStack_808);

      FUN_0076f5f0(pfVar8,pfVar8);

      fVar15 = (float)param_1[0xe];

      *pfVar8 = *pfVar8 * fVar15;

      param_1[0x45] = (int)(fVar15 * (float)param_1[0x45]);

      param_1[0x46] = (int)(fVar15 * (float)param_1[0x46]);

      FUN_0076f5f0(&fStack_82c,&fStack_82c);

      iVar7 = 0;

      if (param_1[0x23] != 1 && -1 < param_1[0x23] + -1) {

        fStack_7fc = g_flOne / fStack_820;

        do {

          iVar5 = *piVar9;

          fStack_80c = afStack_7d4[iVar7] + fStack_80c;

          fStack_808 = (float)piVar9[2] - *(float *)(iVar5 + 8);

          fStack_804 = (float)piVar9[3] - *(float *)(iVar5 + 0xc);

          fStack_800 = (float)piVar9[4] - *(float *)(iVar5 + 0x10);

          fStack_7f8 = fStack_808;

          fStack_7f4 = fStack_804;

          fStack_7f0 = fStack_800;

          FUN_0076f5f0(&fStack_808,&fStack_808);

          fStack_7ec = fStack_808 + fStack_82c;

          fStack_7e8 = fStack_828 + fStack_804;

          fStack_7e4 = fStack_824 + fStack_800;

          pfVar8 = (float *)(piVar9 + 5);

          *pfVar8 = fStack_7ec;

          piVar9[6] = (int)fStack_7e8;

          piVar9[7] = (int)fStack_7e4;

          fStack_82c = fStack_808;

          fStack_828 = fStack_804;

          fStack_824 = fStack_800;

          FUN_0076e240(pfVar8,DAT_00b04c70 + 0x294,pfVar8);

          FUN_0076f5f0(pfVar8,pfVar8);

          fStack_820 = fStack_7fc * fStack_80c;

          fVar13 = ((float)param_1[0xf] - (float)param_1[0xe]) * fStack_820 + (float)param_1[0xe];

          *pfVar8 = fVar13 * *pfVar8;

          fVar15 = (float)piVar9[6];

          piVar9[7] = (int)(fVar13 * (float)piVar9[7]);

          piVar9[6] = (int)(fVar13 * fVar15);

          fStack_7e0 = (float)piVar9[2] - *pfVar8;

          fStack_7dc = (float)piVar9[3] - fVar13 * fVar15;

          fStack_7d8 = (float)piVar9[4] - (float)piVar9[7];

          piVar9[8] = (int)fStack_7e0;

          piVar9[9] = (int)fStack_7dc;

          piVar9[10] = (int)fStack_7d8;

          fStack_81c = *pfVar8 + (float)piVar9[2];

          fStack_818 = (float)piVar9[6] + (float)piVar9[3];

          fStack_814 = (float)piVar9[7] + (float)piVar9[4];

          *pfVar8 = fStack_81c;

          piVar9[6] = (int)fStack_818;

          piVar9[7] = (int)fStack_814;

          FUN_00973690(fStack_820,param_1[0xb],param_1[0xc]);

          piVar9 = (int *)*piVar9;

          iVar7 = iVar7 + 1;

        } while (iVar7 < param_1[0x23] + -1);

      }

      pfVar8 = (float *)(piVar9 + 5);

      FUN_0076e240(pfVar8,DAT_00b04c70 + 0x294,&fStack_82c);

      FUN_0076f5f0(pfVar8,pfVar8);

      fVar15 = (float)param_1[0xf];

      *pfVar8 = *pfVar8 * fVar15;

      piVar9[6] = (int)((float)piVar9[6] * fVar15);

      fVar13 = (float)piVar9[7];

      piVar9[7] = (int)(fVar13 * fVar15);

      piVar9[8] = (int)((float)piVar9[2] - *pfVar8);

      piVar9[9] = (int)((float)piVar9[3] - (float)piVar9[6]);

      piVar9[10] = (int)((float)piVar9[4] - fVar13 * fVar15);

      *pfVar8 = (float)piVar9[2] + *pfVar8;

      piVar9[6] = (int)((float)piVar9[3] + (float)piVar9[6]);

      piVar9[7] = (int)((float)piVar9[4] + (float)piVar9[7]);

      piVar9[0xb] = param_1[0xc];

    }

    *(byte *)((int)param_1 + 0x179) = *(byte *)((int)param_1 + 0x179) & 0xf7;

    return 1;

  }

  param_1[0x5e] = param_1[0x5e] & 0xffff7fffU | 0x100;

  return 1;

}
