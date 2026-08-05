// =============================================================================
// FUN_009168d0
// -----------------------------------------------------------------------------
// Stable ID: aa_009168d0
// Address:   0x009168d0  (autoassault.exe, image base 0x400000)
// Body:      009168d0–00917603 (3379 B / 0xD33)
// System:    client camera / default mode update
// Dual A/B:  2026-07-29 accept-with-gaps (W24-D)
// Named twin: Client_Camera_DefaultModeUpdate_Inferred.cpp
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: Default camera-mode update (sole caller FUN_0091ce80 default switch arm).
//   Orbit aim from focus + yaw + ranges; optional look-yaw; build look basis;
//   8-way map segment collision pull-in via FUN_00916090; commit eye to
//   DAT_00d17944+0x228..; optional ground/gamepad/look writeback.
// ABI: stdcall RET 0x14 (5 stack dwords).
//
// Sealed callees: 004e88e0, 004e8a40, 004e8ad0, 0076f5f0, 00915ad0, 00916090.
//
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_009168d0(int param_1,float *param_2,float param_3,float param_4,float param_5)



{

  bool bVar1;

  char cVar2;

  float *pfVar3;

  int iVar4;

  int iVar5;

  float10 fVar6;

  float10 fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float *pfStack_108;

  float *pfStack_104;

  float *pfStack_100;

  float *pfStack_fc;

  float *pfStack_f8;

  float *pfStack_f4;

  float fStack_dc;

  float fStack_d8;

  float fStack_d4;

  float fStack_d0;

  int iStack_cc;

  float local_c8;

  float local_c4;

  float fStack_c0;

  float fStack_bc;

  float fStack_b8;

  float local_b4;

  float fStack_b0;

  float fStack_ac;

  float fStack_a8;

  uint8_t *puStack_94;

  float fStack_90;

  float fStack_8c;

  float fStack_88;

  float fStack_84;

  float fStack_80;

  int iStack_7c;

  float fStack_78;

  float *local_74;

  float *local_70;

  float local_6c;

  float fStack_68;

  float fStack_64;

  float fStack_60;

  float fStack_5c;

  float local_58;

  float local_54;

  float local_50;

  float fStack_4c;

  float fStack_48;

  float fStack_34;

  float fStack_30;

  float fStack_2c;

  float fStack_28;

  float fStack_24;

  void *pvStack_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  uStack_14 = 0xffffffff;

  puStack_18 = &LAB_009ad312;

  pvStack_1c = ExceptionList;

  fVar6 = (float10)fcos((float10)*(float *)(param_1 + 0xcc8));

  cVar2 = '\x01';

  local_58 = (float)(fVar6 * (float10)param_3 * (float10)*(float *)(param_1 + 0x5ac) +

                    (float10)*param_2);

  local_b4 = (float)(fVar6 * (float10)param_3 * (float10)*(float *)(param_1 + 0x5b4) +

                    (float10)param_2[2]);

  fVar6 = (float10)fsin((float10)*(float *)(param_1 + 0xcc8));

  local_54 = (float)(fVar6 * (float10)param_4 + (float10)param_2[1]);

  if ((*(char *)(DAT_00d1b644 + 0xf5) != '\0') && (DAT_00d1b212 != '\0')) {

    cVar2 = *(char *)(param_1 + 0xa86);

  }

  if (((*(char *)(param_1 + 0x493) == '\0') || (*(char *)(param_1 + 0xa83) == '\0')) ||

     (cVar2 == '\0')) {

    fVar11 = 0.0;

    ExceptionList = &pvStack_1c;

  }

  else {

    local_c4 = DAT_00aaa68c;

    if (DAT_00d1b26d == '\0') {

      local_c4 = _DAT_009da8a4;

    }

    pfStack_f4 = (float *)0x9169b0;

    ExceptionList = &pvStack_1c;

    pfVar3 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 +

                                           DAT_00d1b6d8) + 0x1a4))();

    fStack_90 = *pfVar3;

    fStack_8c = pfVar3[1];

    fStack_88 = pfVar3[2];

    pfStack_f4 = &fStack_b0;

    pfStack_f8 = &fStack_90;

    fStack_84 = pfVar3[3];

    pfStack_fc = (float *)0x9169ea;

    FUN_004e8a40();

    pfStack_fc = &local_50;

    pfStack_100 = &fStack_90;

    pfStack_104 = (float *)0x9169fc;

    FUN_004e8ad0();

    pfStack_104 = &fStack_b0;

    pfStack_108 = &fStack_2c;

    FUN_004e88e0();

    pfVar3 = (float *)FUN_004e88e0(&fStack_2c,&local_50);

    fStack_c0 = *pfVar3;

    fStack_b8 = pfVar3[2];

    fVar11 = 0.0;

    fStack_d0 = *(float *)(DAT_00d17944 + 0x224);

    fStack_d8 = *(float *)(DAT_00d17944 + 0x21c);

    fStack_bc = 0.0;

    fStack_d4 = 0.0;

    FUN_0076f5f0(&fStack_c0,&fStack_c0);

    FUN_0076f5f0(&fStack_d8,&fStack_d8);

    fVar8 = fStack_d8 * fStack_c0 + fStack_b8 * fStack_d0 + fStack_d4 * fStack_bc;

    fVar9 = ABS(fVar8);

    if ((*(char *)(DAT_00d1b644 + 0xf5) != '\0') && (DAT_00d1b212 != '\0')) {

      fVar9 = param_5 * _DAT_00a2f8d8;

    }

    local_c4 = DAT_00afe264 * fVar9 * local_c4;

    if (DAT_00d1f0a8 < fVar8) {

      if (DAT_00d1f0a8 <= fVar8) {

        *(float *)(param_1 + 0x538) = *(float *)(param_1 + 0x538) + local_c4;

      }

    }

    else {

      *(float *)(param_1 + 0x538) = *(float *)(param_1 + 0x538) - local_c4;

    }

  }

  local_70 = (float *)param_2[1];

  local_6c = param_2[2];

  local_74 = (float *)*param_2;

  pfStack_f8 = &local_50;

  local_c4 = DAT_00aaa9a4;

  fStack_80 = local_6c - local_b4;

  fStack_78 = (float)local_70 - local_54;

  fVar10 = (float)local_74 - local_58;

  iStack_cc = 0;

  fStack_d8 = local_58;

  fStack_d4 = local_54;

  fStack_d0 = local_b4;

  pfStack_fc = (float *)0x916bfb;

  fVar9 = local_58;

  fVar8 = local_54;

  fVar12 = local_b4;

  pfStack_f4 = pfStack_f8;

  local_c8 = fVar11;

  local_50 = fVar10;

  fStack_4c = fStack_78;

  fStack_48 = fStack_80;

  FUN_0076f5f0();

  pfStack_100 = &fStack_c0;

  fStack_b8 = param_2[2] - fVar12;

  fStack_bc = param_2[1] - fVar8;

  fStack_c0 = *param_2 - fVar9;

  pfStack_104 = (float *)0x916c34;

  pfStack_fc = pfStack_100;

  FUN_0076f5f0();

  fStack_b0 = DAT_00afdfcc * fStack_b8 - DAT_00afdfd0 * fStack_bc;

  fStack_ac = DAT_00afdfd0 * fStack_c0 - fStack_b8 * DAT_00afdfc8;

  pfStack_108 = &fStack_68;

  fStack_a8 = fStack_bc * DAT_00afdfc8 - DAT_00afdfcc * fStack_c0;

  fVar11 = fStack_b8;

  fVar9 = fStack_bc;

  fVar8 = fStack_c0;

  pfStack_104 = pfStack_108;

  fStack_68 = fStack_b0;

  fStack_64 = fStack_ac;

  fStack_60 = fStack_a8;

  FUN_0076f5f0();

  fStack_b0 = fStack_60 * fVar9 - fStack_64 * fVar11;

  fStack_ac = fVar11 * fStack_68 - fStack_60 * fVar8;

  fStack_a8 = fStack_64 * fVar8 - fVar9 * fStack_68;

  fStack_90 = fStack_b0;

  fStack_8c = fStack_ac;

  fStack_88 = fStack_a8;

  FUN_0076f5f0(&fStack_90,&fStack_90);

  fVar6 = (float10)fcos((float10)*(float *)(param_1 + 0xcc8));

  fVar6 = fVar6 * (float10)*(float *)(param_1 + 0x530);

  fStack_2c = (float)(fVar6 * (float10)*(float *)(param_1 + 0x5ac) + (float10)*param_2);

  fStack_24 = (float)(fVar6 * (float10)*(float *)(param_1 + 0x5b4) + (float10)param_2[2]);

  fVar6 = (float10)fsin((float10)*(float *)(param_1 + 0xcc8));

  fStack_28 = (float)(fVar6 * (float10)*(float *)(param_1 + 0x530) + (float10)param_2[1]);

  while( true ) {

    bVar1 = false;

    iStack_7c = 0;

    do {

      pfStack_f4 = (float *)iStack_7c;

      pfStack_f8 = &fStack_2c;

      pfStack_fc = (float *)param_1;

      pfStack_100 = (float *)0x916dd6;

      FUN_00915ad0();

      pfStack_fc = (float *)fStack_b0;

      pfStack_f8 = (float *)fStack_ac;

      pfStack_f4 = (float *)fStack_a8;

      puStack_94 = (uint8_t *)&pfStack_108;

      pfStack_108 = local_74;

      pfStack_104 = local_70;

      pfStack_100 = (float *)local_6c;

      fVar6 = (float10)FUN_00916090();

      puStack_94 = (uint8_t *)(float)fVar6;

      if (DAT_00a0f70c < (float)puStack_94) {

        fVar8 = (float)local_70 - fStack_ac;

        fVar11 = (float)local_74 - fStack_b0;

        fVar9 = local_6c - fStack_a8;

        fStack_34 = fVar11 * fVar11 + fVar8 * fVar8 + fVar9 * fVar9;

        fStack_5c = SQRT(fStack_34);

        if ((_DAT_00a240ec <= fStack_5c) || (fStack_5c <= DAT_00aaa640)) {

          fVar12 = g_flOne / fStack_5c;

          fVar11 = fVar11 * fVar12;

          fVar8 = fVar12 * fVar8;

          fVar9 = fVar12 * fVar9;

        }

        fVar11 = fVar11 * local_50 + fVar9 * fStack_48 + fVar8 * fStack_4c;

        if ((0.0 <= fVar11) && (fVar11 = fVar11 * (float)puStack_94, fVar11 < local_c4)) {

          bVar1 = true;

          iStack_cc = 0;

          local_c8 = fVar11;

          local_c4 = fVar11;

        }

      }

      iStack_7c = iStack_7c + 1;

    } while (iStack_7c < 8);

    if (!bVar1) break;

    fStack_30 = ((float)local_74 - fStack_d8) * ((float)local_74 - fStack_d8) +

                ((float)local_70 - fStack_d4) * ((float)local_70 - fStack_d4) +

                (local_6c - fStack_d0) * (local_6c - fStack_d0);

    fVar11 = SQRT(fStack_30) - (local_c4 - DAT_00a10e78);

    if (fVar11 < DAT_00a10e78) break;

    fStack_d8 = fStack_c0 * fVar11 + fStack_d8;

    fStack_d4 = fStack_bc * fVar11 + fStack_d4;

    fStack_d0 = fStack_b8 * fVar11 + fStack_d0;

  }

  if ((DAT_00a0f70c < local_c8) && (local_c8 = local_c8 - _DAT_00d1f0a4, local_c8 <= DAT_00a0f70c))

  {

    local_c8 = DAT_00a0f70c;

  }

  fStack_dc = 0.0;

  if (local_c8 <= DAT_00a0f70c) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xcd4) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xcdc) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x528);

  }

  else {

    fVar11 = SQRT(fVar10 * fVar10 + fStack_78 * fStack_78 + fStack_80 * fStack_80);

    fVar9 = fVar11 - local_c8;

    if (fVar9 <= 0.0) {

      fVar9 = 0.0;

    }

    if (0.0 < fVar11) {

      fStack_dc = fVar9 / fVar11;

    }

    *(float *)(param_1 + 0x52c) = local_c8;

    *(float *)(param_1 + 0xcdc) = local_c8;

  }

  iVar4 = DAT_00d17944;

  if ((DAT_00d206b8 & 1) == 0) {

    DAT_00d206b8 = DAT_00d206b8 | 1;

    _DAT_00d206ac = 0;

    _DAT_00d206b0 = 0;

    _DAT_00d206b4 = 0;

    uStack_14 = 0xffffffff;

  }

  fStack_d8 = local_58 - *(float *)(DAT_00d17944 + 0x228);

  fStack_d4 = local_54 - *(float *)(DAT_00d17944 + 0x22c);

  fStack_d0 = local_b4 - *(float *)(DAT_00d17944 + 0x230);

  fVar11 = SQRT(fStack_d8 * fStack_d8 + fStack_d4 * fStack_d4 + fStack_d0 * fStack_d0);

  if ((_DAT_00a240ec <= fVar11) ||

     (fVar9 = fStack_d8, fVar8 = fStack_d4, fVar12 = fStack_d0, fVar11 <= DAT_00aaa640)) {

    fVar12 = g_flOne / fVar11;

    fVar9 = fVar12 * fStack_d8;

    fVar8 = fVar12 * fStack_d4;

    fVar12 = fVar12 * fStack_d0;

  }

  fVar10 = SQRT(fStack_d4 * fStack_d4 + fStack_d0 * fStack_d0 + fStack_d8 * fStack_d8);

  if (DAT_00d1f0a0 == '\0') {

    *(float *)(DAT_00d17944 + 0x228) = fVar9 * fVar10 + *(float *)(DAT_00d17944 + 0x228);

    *(float *)(iVar4 + 0x22c) = fVar8 * fVar10 + *(float *)(iVar4 + 0x22c);

    *(float *)(iVar4 + 0x230) = fVar12 * fVar10 + *(float *)(iVar4 + 0x230);

  }

  else {

    *(float *)(DAT_00d17944 + 0x228) = local_58;

    *(float *)(iVar4 + 0x22c) = local_54;

    *(float *)(iVar4 + 0x230) = local_b4;

  }

  if ((((DAT_00d1b26e != '\0') && (iStack_cc != 0)) && (DAT_00d1b644 != 0)) &&

     ((*(int *)(DAT_00d1b644 + 0xe4e4) != 0 && (*(int *)(DAT_00d1b644 + 0xe4e4) + 0xc == iStack_cc))

     )) {

    fVar9 = *(float *)(iVar4 + 0x22c) - param_2[1];

    if (fVar9 <= 0.0) {

      if (fVar9 < DAT_00aaa9a0) {

        fVar9 = DAT_00aaa9a0;

      }

    }

    else {

      fVar9 = 0.0;

    }

    param_2[1] = (g_flOne - (fVar9 - DAT_00aaa9a0) * DAT_00a0f704) * fStack_dc * DAT_00a110d8 +

                 param_2[1];

  }

  if ((DAT_00d1b20f != '\0') && (DAT_00d1b618 != (code *)0x0)) {

    pfStack_f4 = (float *)0x91734e;

    local_b4 = fVar11;

    fStack_80 = fStack_d0;

    fStack_78 = fStack_d4;

    cVar2 = (*DAT_00d1b618)();

    if (cVar2 != '\0') {

      pfStack_f4 = (float *)0xe;

      pfStack_f8 = (float *)0x91735e;

      fVar6 = (float10)(*DAT_00d1b620)();

      pfStack_f8 = (float *)0xd;

      pfStack_fc = (float *)0x91736a;

      fVar7 = (float10)(*DAT_00d1b620)();

      pfStack_fc = (float *)0xc;

      fStack_90 = (float)((float10)(float)fVar6 - fVar7);

      pfStack_100 = (float *)0x91737a;

      fVar6 = (float10)(*DAT_00d1b620)();

      pfStack_100 = (float *)0xb;

      pfStack_104 = (float *)0x917386;

      fVar7 = (float10)(*DAT_00d1b620)();

      fVar11 = (float)((float10)(float)fVar6 - fVar7);

      if ((fStack_90 != g_flZero) || (fVar11 != g_flZero)) {

        if (DAT_00d1b644 == 0) {

          iVar4 = 0;

        }

        else {

          iVar4 = *(int *)(DAT_00d1b644 + 0xe890);

        }

        iVar4 = *(int *)(iVar4 + 8);

        if (DAT_00d1b644 == 0) {

          iVar5 = 0;

        }

        else {

          iVar5 = *(int *)(DAT_00d1b644 + 0xe890);

        }

        iVar5 = *(int *)(iVar5 + 8);

        fVar9 = *(float *)(iVar5 + 0x88);

        fVar8 = (*(float *)(iVar4 + 0x88) * *(float *)(iVar4 + 0x80) +

                *(float *)(iVar4 + 0x8c) * *(float *)(iVar4 + 0x84)) * g_flLevelUpUiBase_Inferred *

                fVar11 + (g_flOne -

                         (*(float *)(iVar5 + 0x84) * *(float *)(iVar5 + 0x84) + fVar9 * fVar9) *

                         g_flLevelUpUiBase_Inferred) * fStack_90;

        fVar9 = (g_flOne -

                (*(float *)(iVar4 + 0x80) * *(float *)(iVar4 + 0x80) +

                *(float *)(iVar4 + 0x84) * *(float *)(iVar4 + 0x84)) * g_flLevelUpUiBase_Inferred) *

                fVar11 + (fVar9 * *(float *)(iVar5 + 0x80) -

                         *(float *)(iVar5 + 0x8c) * *(float *)(iVar5 + 0x84)) *

                         g_flLevelUpUiBase_Inferred * fStack_90;

        fVar11 = fVar8 * fVar8 + fVar9 * fVar9;

        if (fVar11 == 0.0) {

          fVar11 = 0.0;

        }

        else {

          fVar11 = g_flOne / SQRT(fVar11);

        }

        iVar4 = *(int *)(DAT_00d1b6d8 + 0x250);

        if (iVar4 == 0) {

          ExceptionList = pvStack_1c;

          return;

        }

        *(float *)(iVar4 + 0x170) = fVar11 * fVar8;

        *(float *)(iVar4 + 0x174) = fVar11 * 0.0;

        *(float *)(iVar4 + 0x178) = fVar9 * fVar11;

        fVar11 = fVar11 * 0.0;

        goto LAB_009175e5;

      }

    }

  }

  if ((*(char *)(param_1 + 0x493) == '\0') &&

     (*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xa4 + DAT_00d1b6d8) == 0)) {

    iVar4 = *(int *)(DAT_00d1b6d8 + 0x250);

    fVar11 = *(float *)(param_1 + 0x5b0) * DAT_00aaa668;

    fVar9 = *(float *)(param_1 + 0x5b4) * DAT_00aaa668;

    if (iVar4 == 0) {

      ExceptionList = pvStack_1c;

      return;

    }

    *(float *)(iVar4 + 0x170) = *(float *)(param_1 + 0x5ac) * DAT_00aaa668;

    *(float *)(iVar4 + 0x174) = fVar11;

    *(float *)(iVar4 + 0x178) = fVar9;

    fVar11 = 0.0;

  }

  else {

    iVar4 = *(int *)(DAT_00d1b6d8 + 0x250);

    if (iVar4 == 0) {

      ExceptionList = pvStack_1c;

      return;

    }

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x170) = DAT_00d1a640;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x174) = DAT_00d1a644;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x178) = DAT_00d1a648;

    fVar11 = DAT_00d1a64c;

  }

LAB_009175e5:

  *(float *)(iVar4 + 0x17c) = fVar11;

  ExceptionList = pvStack_1c;

  return;

}
