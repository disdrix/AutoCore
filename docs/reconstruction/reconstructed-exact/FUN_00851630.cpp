// =============================================================================
// FUN_00851630  (scaffold twin of Client_UI_MapView_DrawMarkersFovOverlay)
// -----------------------------------------------------------------------------
// Stable ID: aa_00851630
// Address:   0x00851630 – 0x00852428  (autoassault.exe, image base 0x400000)
// System:    client UI / map-view overlay
// Generated: 2026-07-23 scaffold; W23-N dual seal header 2026-07-29
// Exactness: Decompiler-mirror body below. Sealed phase contract lives in
//            Client_UI_MapView_DrawMarkersFovOverlay.cpp + raw W23-N append.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// W23-N SEALED FACTS:
//   ABI: __thiscall (ECX=this); plain ret C3; frame sub esp,0x164; align 16
//   Body: 3576 B; gate this+0x488 + config+0x4fc + world/local globals
//   Phases: markers → patrol → mission → special → squad → FOV(+cone)
//   Constants: 300.0 (aaa8a8), 2.5 (aaa6c4), 30.0 (a0f694)
//   Vtbl DATA @ 00a68204
// =============================================================================

// READABILITY (auto CF):
//  - Body size: ~364 non-empty decompiler lines.
//  - Control keywords: if×25, while×4, do×3, return×2.
//  - Notable callees: FUN_0084f4f0×5, FUN_008513d0×4, FUN_00757890×3, Client_EvalAutoPatrolWaypoint.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 * - Prefer named clean file for port contract; this file preserves decomp CF.
 */

void __fastcall FUN_00851630(int *param_1)



{

  int iVar1;

  int *piVar2;

  byte *pbVar3;

  uint8_t uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int *piVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  float *pfVar9;

  uint uVar10;

  int iVar11;

  int iVar12;

  float10 fVar13;

  undefined *puVar14;

  uint32_t /* width from decompiler */ uVar15;

  uint32_t /* width from decompiler */ uVar16;

  uint32_t /* width from decompiler */ uVar17;

  float fVar18;

  uint32_t /* width from decompiler */ uVar19;

  uint *puVar20;

  uint32_t /* width from decompiler */ uVar21;

  undefined3 uVar22;

  float fStack_170;

  float fStack_16c;

  uint32_t /* width from decompiler */ uStack_168;

  float fStack_160;

  float fStack_15c;

  uint32_t /* width from decompiler */ uStack_158;

  uint32_t /* width from decompiler */ uStack_154;

  float fStack_150;

  uint32_t /* width from decompiler */ uStack_14c;

  uint32_t /* width from decompiler */ uStack_148;

  uint32_t /* width from decompiler */ uStack_144;

  float fStack_140;

  float fStack_13c;

  uint auStack_138 [2];

  float fStack_130;

  float fStack_12c;

  uint8_t auStack_124 [4];

  uint8_t auStack_120 [8];

  uint8_t auStack_118 [8];

  uint8_t auStack_110 [4];

  float fStack_10c;

  float fStack_108;

  float fStack_104;

  uint uStack_100;

  uint uStack_fc;

  uint32_t /* width from decompiler */ uStack_f8;

  uint32_t /* width from decompiler */ uStack_f4;

  uint32_t /* width from decompiler */ uStack_f0;

  uint32_t /* width from decompiler */ uStack_ec;

  uint32_t /* width from decompiler */ uStack_e8;

  uint32_t /* width from decompiler */ uStack_e4;

  float fStack_e0;

  uint32_t /* width from decompiler */ uStack_dc;

  uint32_t /* width from decompiler */ uStack_d8;

  uint32_t /* width from decompiler */ uStack_d4;

  uint32_t /* width from decompiler */ uStack_d0;

  uint32_t /* width from decompiler */ uStack_cc;

  float fStack_c8;

  float fStack_c4;

  uint32_t /* width from decompiler */ uStack_c0;

  uint32_t /* width from decompiler */ uStack_bc;

  uint32_t /* width from decompiler */ uStack_b8;

  uint32_t /* width from decompiler */ uStack_b4;

  uint32_t /* width from decompiler */ uStack_b0;

  float fStack_ac;

  uint32_t /* width from decompiler */ uStack_a0;

  uint8_t uStack_9c;

  uint8_t uStack_9b;

  uint8_t uStack_9a;

  uint8_t uStack_99;

  uint32_t /* width from decompiler */ uStack_90;

  uint32_t /* width from decompiler */ uStack_8c;

  float fStack_88;

  float fStack_84;

  uint32_t /* width from decompiler */ uStack_80;

  uint32_t /* width from decompiler */ uStack_7c;

  uint uStack_78;

  uint32_t /* width from decompiler */ uStack_74;

  float fStack_70;

  float fStack_6c;

  uint32_t /* width from decompiler */ uStack_68;

  uint32_t /* width from decompiler */ uStack_64;

  float fStack_60;

  uint32_t /* width from decompiler */ uStack_5c;

  float fStack_58;

  float fStack_54;

  uint32_t /* width from decompiler */ uStack_50;

  uint32_t /* width from decompiler */ uStack_4c;

  float fStack_48;

  float fStack_44;

  float fStack_40;

  float fStack_3c;

  uint32_t /* width from decompiler */ uStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  uint32_t /* width from decompiler */ uStack_30;

  float fStack_2c;

  

  if ((((param_1[0x122] != 0) && (DAT_00d1b644 != 0)) && (*(int *)(DAT_00d1b644 + 0xe4e8) != 0)) &&

     ((DAT_00d1b6d8 != 0 && (*(char *)(param_1[0x122] + 0x4fc) != '\0')))) {

    puVar5 = (uint32_t /* width from decompiler */ *)

             (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) +

                         0x1a0))();

    fStack_150 = (float)*puVar5;

    uStack_14c = puVar5[1];

    uStack_148 = puVar5[2];

    uStack_144 = puVar5[3];

    uStack_168 = (int *)*DAT_00d1d964;

    if (uStack_168 != DAT_00d1d964) {

      do {

        if (*(int **)(uStack_168[2] + 0x20) == (int *)0x0) {

          puVar20 = &uStack_78;

        }

        else {

          (**(code **)(**(int **)(uStack_168[2] + 0x20) + 0x144))();

          puVar20 = auStack_138;

        }

        piVar6 = (int *)FUN_0084f610(puVar20);

        iVar11 = param_1[0x122];

        fStack_170 = (float)(*piVar6 - *(int *)(iVar11 + 0x538) / 2);

        fStack_16c = (float)(piVar6[1] - *(int *)(param_1[0x122] + 0x53c) / 2);

        if ((int)fStack_170 < 0) {

          fStack_170 = 0.0;

        }

        if ((int)fStack_16c < 0) {

          fStack_16c = 0.0;

        }

        iVar12 = uStack_168[2];

        iVar1 = *(int *)(iVar12 + 8);

        if (((iVar1 < 0) || (8 < iVar1)) || (*(int *)(param_1[0x122] + 0x600 + iVar1 * 4) == 0)) {

          FUN_00758460((float)(int)fStack_170,(float)(int)fStack_16c,

                       (float)(*(int *)(iVar11 + 0x538) + (int)fStack_170),

                       (float)(*(int *)(iVar11 + 0x53c) + (int)fStack_16c),&DAT_00d1ec78,0,

                       *(uint32_t /* width from decompiler */ *)(iVar12 + 0xc),0,0,0,&DAT_00d1ecac);

        }

        else {

          uVar8 = *(uint32_t /* width from decompiler */ *)(iVar12 + 0xc);

          uVar21 = *(uint32_t /* width from decompiler */ *)(param_1[0x122] + 0x600 + *(int *)(iVar12 + 8) * 4);

          puVar5 = &DAT_00d1ecac;

          uVar19 = 0;

          uVar17 = 0;

          uVar16 = 0;

          uVar15 = 0;

          uVar7 = FUN_00413f50(&fStack_170,(int *)(iVar11 + 0x538));

          FUN_00413680(uVar7,uVar21,uVar15,uVar8,uVar16,uVar17,uVar19,puVar5);

        }

        uStack_168 = (int *)*uStack_168;

      } while (uStack_168 != DAT_00d1d964);

    }

    param_1[0x1a] = param_1[0x1a] + 1;

    iVar11 = param_1[0x1a];

    param_1[0x1d] = (int)(float)-iVar11;

    if (param_1[0x1c] < iVar11) {

      param_1[0x1c] = iVar11;

    }

    if (((*(int *)((int)DAT_00d1ad10 + 0x11c) != 0) &&

        (iVar11 = *(int *)((int)DAT_00d1ad10 + 0x120) - *(int *)((int)DAT_00d1ad10 + 0x11c) >> 2,

        iVar11 != 0)) && (iVar12 = 0, 0 < iVar11)) {

      do {

        Client_EvalAutoPatrolWaypoint(DAT_00d1ad10,&uStack_100,&fStack_10c);

        if (((uStack_100 & uStack_fc) != 0xffffffff) || ((char)uStack_f8 != '\0')) {

          fStack_160 = fStack_10c;

          fStack_15c = fStack_108;

          uStack_158 = fStack_104;

          auStack_138[0] =

               CONCAT31(auStack_138[0]._1_3_,-(*(char *)((int)DAT_00d1ad10 + 8) != '\0')) &

               0xffffff02;

          uStack_154 = 0;

          FUN_008513d0(param_1,&fStack_160,auStack_138[0]);

        }

        iVar12 = iVar12 + 1;

      } while (iVar12 < iVar11);

    }

    iVar11 = DAT_00d1b938;

    if (DAT_00d1b938 != 0) {

      piVar6 = *(int **)(DAT_00d1b938 + 0x524);

      piVar2 = (int *)*piVar6;

      while (piVar2 != piVar6) {

        piVar6 = (int *)piVar2[4];

        if (piVar6 != (int *)0x0) {

          uVar21 = 0x65;

          uVar8 = (**(code **)(*piVar6 + 0x1a0))(0x65);

          FUN_008513d0(param_1,uVar8,uVar21);

        }

        FUN_0046f100();

        piVar6 = *(int **)(iVar11 + 0x524);

      }

    }

    param_1[0x1a] = param_1[0x1a] + 1;

    iVar11 = param_1[0x1a];

    param_1[0x1d] = (int)(float)-iVar11;

    if (param_1[0x1c] < iVar11) {

      param_1[0x1c] = iVar11;

    }

    if (DAT_00d1ad1c != '\0') {

      fStack_10c = DAT_00d1ad20;

      fStack_108 = DAT_00d1ad24;

      fStack_104 = (float)DAT_00d1ad28;

      FUN_004e9530(&uStack_100,&fStack_10c);

      FUN_008513d0(param_1,&uStack_100,100);

    }

    param_1[0x1a] = param_1[0x1a] + 1;

    iVar11 = param_1[0x1a];

    param_1[0x1d] = (int)(float)-iVar11;

    if (param_1[0x1c] < iVar11) {

      param_1[0x1c] = iVar11;

    }

    if (*(int *)(DAT_00d1b6d8 + 0xcb0) != 0) {

      iVar11 = 0;

      do {

        iVar12 = FUN_00574760(iVar11);

        if ((iVar12 != 0) && (iVar12 != DAT_00d1b6d8)) {

          uVar21 = 1;

          uVar8 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar12 + 4) + 4) + 4 + iVar12) + 0x1a0))

                            (1);

          FUN_008513d0(param_1,uVar8,uVar21);

        }

        iVar11 = iVar11 + 1;

      } while (iVar11 < 4);

    }

    param_1[0x1a] = param_1[0x1a] + 1;

    iVar11 = param_1[0x1a];

    param_1[0x1d] = (int)(float)-iVar11;

    if (param_1[0x1c] < iVar11) {

      param_1[0x1c] = iVar11;

    }

    uStack_e4 = 0xffffffff;

    uStack_cc = 0xffffffff;

    uStack_b4 = 0xffffffff;

    uStack_9a = 0xff;

    uStack_9b = 0xff;

    uStack_9c = 0xff;

    uStack_99 = 0xff;

    uStack_e8 = 0;

    uStack_d0 = 0;

    uStack_b8 = 0;

    uStack_a0 = 0;

    if ((DAT_00d1b780 != (int *)0x0) && (*DAT_00d1b780 == DAT_00d1b778)) {

      puVar5 = (uint32_t /* width from decompiler */ *)

               (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) +

                           0x1a4))();

      uStack_90 = *puVar5;

      uStack_8c = puVar5[1];

      fStack_88 = (float)puVar5[2];

      fStack_84 = (float)puVar5[3];

      FUN_004e8a40(&uStack_90,auStack_120);

      FUN_004e8ad0(&uStack_90,&fStack_130);

      pbVar3 = (byte *)param_1[0x89];

      uStack_168 = (int *)0xff32ff32;

      if (pbVar3 != (byte *)0x0) {

        uStack_168 = (int *)CONCAT13((char)(((uint)pbVar3[3] * 0xff) / 0xff),

                                     CONCAT21(CONCAT11((char)(((uint)pbVar3[2] * 0x32) / 0xff),

                                                       (char)(((uint)pbVar3[1] * 0xff) / 0xff)),

                                              (char)(((uint)*pbVar3 * 0x32) / 0xff)));

      }

      iVar11 = (**(code **)(*param_1 + 0x140))(&uStack_78,1);

      iVar11 = *(int *)(iVar11 + 4);

      fVar18 = 1.4013e-45;

      piVar6 = (int *)(**(code **)(*param_1 + 0x140))(&stack0xfffffe88,1);

      if (iVar11 < *piVar6) {

        piVar6 = (int *)(**(code **)(*param_1 + 0x140))(&uStack_148);

        iVar11 = *piVar6;

      }

      else {

        iVar11 = (**(code **)(*param_1 + 0x140))(auStack_110,1);

        iVar11 = *(int *)(iVar11 + 4);

      }

      fVar18 = (fVar18 / (float)iVar11) * DAT_00aaa8a8;

      fStack_150 = 0.0 - fVar18;

      fStack_170 = fStack_140 * fStack_150 + fStack_130 * fVar18 + fStack_160;

      fStack_16c = fStack_13c * fStack_150 + fStack_12c * fVar18 + fStack_15c;

      pfVar9 = (float *)FUN_0084f4f0(auStack_118);

      fStack_108 = *pfVar9;

      fStack_104 = pfVar9[1];

      uStack_f8 = 0;

      uStack_f4 = 0;

      fStack_170 = fStack_140 * fVar18 + fStack_130 * fVar18 + fStack_160;

      fStack_16c = fStack_13c * fVar18 + fStack_12c * fVar18 + fStack_15c;

      puVar5 = (uint32_t /* width from decompiler */ *)FUN_0084f4f0(&uStack_90);

      uStack_f0 = *puVar5;

      uStack_ec = puVar5[1];

      fStack_e0 = g_flOne;

      uStack_dc = 0;

      fStack_170 = fStack_140 * fVar18 + fStack_130 * fStack_150 + fStack_160;

      fStack_16c = fStack_13c * fVar18 + fStack_12c * fStack_150 + fStack_15c;

      puVar5 = (uint32_t /* width from decompiler */ *)FUN_0084f4f0(&stack0xfffffe80);

      uStack_d8 = *puVar5;

      uStack_d4 = puVar5[1];

      fStack_c8 = g_flOne;

      fStack_c4 = g_flOne;

      fStack_170 = fStack_140 * fStack_150 + fStack_130 * fStack_150 + fStack_160;

      fStack_16c = fStack_13c * fStack_150 + fStack_12c * fStack_150 + fStack_15c;

      puVar5 = (uint32_t /* width from decompiler */ *)FUN_0084f4f0(auStack_124);

      uStack_c0 = *puVar5;

      uStack_bc = puVar5[1];

      fVar13 = (float10)fsin((float10)*(float *)(param_1[0x122] + 0x514) * (float10)DAT_00aaa6c4);

      uStack_b0 = 0;

      fStack_ac = g_flOne;

      fVar18 = (float)fVar13;

      if (g_flZero < fVar18) {

        pbVar3 = (byte *)param_1[0x89];

        uVar10 = 0xff;

        uStack_80 = 0;

        uStack_68 = 0;

        uStack_50 = 0;

        uStack_38 = 0;

        uVar22 = 0xffffc8;

        if (pbVar3 != (byte *)0x0) {

          uVar22 = CONCAT21(CONCAT11((char)(((uint)pbVar3[2] * 0xff) / 0xff),

                                     (char)(((uint)pbVar3[1] * 0xff) / 0xff)),

                            (char)(((uint)*pbVar3 * 200) / 0xff));

          uVar10 = ((uint)pbVar3[3] * 0xff) / 0xff;

        }

        fStack_150 = (float)(uVar10 & 0xff);

        uVar4 = FUN_006a3db0();

        uVar8 = CONCAT13(uVar4,uVar22);

        pfVar9 = (float *)FUN_0084f4f0(auStack_124);

        fStack_54 = (float)(int)((float)(int)(fVar18 * DAT_00a0f694) * (float)DAT_00d1e81c *

                                DAT_00aaa678);

        puVar14 = *(undefined **)(param_1[0x122] + 0x5a4);

        fStack_70 = (float)(int)((float)(int)(fVar18 * DAT_00a0f694) * (float)DAT_00d1e818 *

                                DAT_00aaa67c);

        fStack_84 = pfVar9[1] - fStack_54;

        fStack_88 = *pfVar9 - fStack_70;

        fStack_70 = fStack_70 + *pfVar9;

        fStack_54 = fStack_54 + pfVar9[1];

        uStack_78 = 0;

        uStack_74 = 0;

        fStack_60 = g_flOne;

        uStack_5c = 0;

        fStack_48 = g_flOne;

        fStack_44 = g_flOne;

        uStack_30 = 0;

        fStack_2c = g_flOne;

        if (puVar14 == (undefined *)0x0) {

          puVar14 = &DAT_00d1ec78;

        }

        uStack_7c = uVar8;

        fStack_6c = fStack_84;

        uStack_64 = uVar8;

        fStack_58 = fStack_70;

        uStack_4c = uVar8;

        fStack_40 = fStack_88;

        fStack_3c = fStack_54;

        uStack_34 = uVar8;

        FUN_00757890(&fStack_88,4,puVar14,1,&DAT_00d1ecac);

        param_1[0x1a] = param_1[0x1a] + 1;

        iVar11 = param_1[0x1a];

        param_1[0x1d] = (int)(float)-iVar11;

        if (param_1[0x1c] < iVar11) {

          param_1[0x1c] = iVar11;

        }

      }

      if (*(int *)(param_1[0x122] + 0x5a0) != 0) {

        FUN_00757890(&fStack_108,4,*(int *)(param_1[0x122] + 0x5a0),1,&DAT_00d1ecac);

        return;

      }

      FUN_00757890(&fStack_108,4,&DAT_00d1ec78,1,&DAT_00d1ecac);

    }

  }

  return;

}
