// =============================================================================
// FUN_005a75f0
// -----------------------------------------------------------------------------
// Stable ID: aa_005a75f0
// Address:   0x005a75f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a75f0 @ 0x005a75f0
// Stable ID: aa_005a75f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~212 non-empty decompiler lines.
//  - Control keywords: if×6, do×1, while×1, return×1.
//  - Notable callees: FUN_0044b440×2, FUN_0076f5f0×2, FUN_00972580×2, FUN_0099b8a0×2, FUN_00404c00, FUN_004249f0, FUN_004e88e0, FUN_004e9530.
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

void __thiscall FUN_005a75f0(float param_1,int param_2,int param_3,float *param_4)



{

  float fVar1;

  float fVar2;

  int iVar3;

  int iVar4;

  float *pfVar5;

  float **ppfVar6;

  uint uVar7;

  int *piVar8;

  uint8_t *puVar9;

  float10 fVar10;

  float fVar11;

  uint32_t /* width from decompiler */ uVar12;

  uint8_t *puStack_11c;

  float *pfStack_118;

  float *pfStack_114;

  uint8_t **ppuStack_110;

  float **ppfStack_10c;

  float **ppfStack_108;

  float *pfStack_104;

  float fStack_f0;

  float fStack_ec;

  float *pfStack_e8;

  uint8_t *puStack_e4;

  float *pfStack_e0;

  uint8_t *puStack_dc;

  float fStack_d8;

  float fStack_d4;

  uint8_t *puStack_d0;

  float *pfStack_cc;

  uint8_t *puStack_c8;

  float local_c4;

  float fStack_c0;

  float fStack_bc;

  float fStack_b8;

  float fStack_b4;

  float fStack_b0;

  float *pfStack_ac;

  uint8_t *puStack_a8;

  int *piStack_a4;

  int aiStack_a0 [2];

  uint uStack_98;

  uint32_t /* width from decompiler */ uStack_94;

  float fStack_90;

  float fStack_8c;

  float fStack_88;

  float fStack_84;

  uint8_t auStack_80 [20];

  uint8_t auStack_6c [16];

  uint8_t auStack_5c [4];

  uint8_t auStack_58 [84];

  

  if ((((*(int *)((int)param_1 + 0xec) != 0) && (param_2 < *(int *)((int)param_1 + 0xf0))) &&

      (-1 < param_2)) &&

     (piVar8 = *(int **)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0xb0 + (int)param_1),

     piVar8 != (int *)0x0)) {

    pfStack_104 = (float *)0x5a7646;

    local_c4 = param_1;

    iVar3 = (**(code **)(*piVar8 + 0x1cc))();

    if (iVar3 != 0) {

      pfStack_104 = (float *)0x5a7663;

      iVar3 = (**(code **)(**(int **)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0xb0 + (int)param_1

                                     ) + 0x1cc))();

      if (*(int *)(iVar3 + 8) != 0) {

        pfStack_104 = (float *)0x5a7682;

        iVar3 = (**(code **)(**(int **)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0xb0 +

                                       (int)param_1) + 0x1cc))();

        uStack_94 = *(uint32_t /* width from decompiler */ *)(iVar3 + 8);

        fStack_d4 = (float)(param_2 * 0x3e4);

        fStack_8c = (param_4[1] * *param_4 - param_4[3] * param_4[2]) * g_flLevelUpUiBase_Inferred;

        piVar8 = (int *)(*(int *)((int)param_1 + 0xec) + (int)fStack_d4);

        uStack_98 = param_2 * 2;

        fStack_88 = g_flOne - (param_4[2] * param_4[2] + *param_4 * *param_4) *

                              g_flLevelUpUiBase_Inferred;

        iVar3 = param_2 * 0x298;

        fStack_84 = (param_4[1] * param_4[2] + param_4[3] * *param_4) * g_flLevelUpUiBase_Inferred;

        pfStack_104 = (float *)0x5a7750;

        iVar4 = (**(code **)(*(int *)(iVar3 + *(int *)((int)local_c4 + 0xe8)) + 0xc))();

        puStack_d0 = *(uint8_t **)(iVar4 + 0x90);

        pfStack_cc = *(float **)(iVar4 + 0x94);

        puStack_c8 = *(uint8_t **)(iVar4 + 0x98);

        pfStack_104 = (float *)0x5a778f;

        iVar4 = (**(code **)(*(int *)(iVar3 + 0x14c + *(int *)((int)local_c4 + 0xe8)) + 0xc))();

        fStack_bc = *(float *)(iVar4 + 0x90);

        fStack_b8 = *(float *)(iVar4 + 0x94);

        fStack_b0 = fStack_bc - (float)puStack_d0;

        fStack_b4 = *(float *)(iVar4 + 0x98);

        pfStack_ac = (float *)(fStack_b8 - (float)pfStack_cc);

        puStack_a8 = (uint8_t *)(fStack_b4 - (float)puStack_c8);

        pfStack_104 = (float *)0x5a77e5;

        fVar10 = (float10)FUN_00404c00();

        fStack_d8 = (float)fVar10;

        puStack_e4 = (uint8_t *)fStack_b0;

        pfStack_e0 = pfStack_ac;

        puStack_dc = puStack_a8;

        fStack_b0 = fStack_b0 * DAT_00a0f298 + (float)puStack_d0;

        pfStack_ac = (float *)((float)pfStack_ac * DAT_00a0f298 + (float)pfStack_cc);

        puStack_a8 = (uint8_t *)((float)puStack_a8 * DAT_00a0f298 + (float)puStack_c8);

        pfStack_104 = &fStack_b0;

        ppfStack_108 = (float **)0x5a7851;

        (**(code **)(*piVar8 + 0x18))();

        ppfStack_10c = &pfStack_e8;

        ppuStack_110 = (uint8_t **)0x5a785e;

        ppfStack_108 = ppfStack_10c;

        FUN_0076f5f0();

        ppfStack_108 = (float **)&fStack_90;

        ppfStack_10c = &pfStack_e8;

        ppuStack_110 = (uint8_t **)0x5a7877;

        FUN_00972580();

        ppfStack_108 = (float **)0x3;

        ppfStack_10c = (float **)0x5a7880;

        iVar4 = (**(code **)(*piVar8 + 0x10))();

        ppfStack_10c = (float **)auStack_58;

        *(uint32_t /* width from decompiler */ *)(iVar4 + 0xbc) = 0xffffffff;

        *(int *)(iVar4 + 0xb4) = *(int *)(iVar4 + 0xb4) + 1;

        ppuStack_110 = (uint8_t **)0x5a78a4;

        FUN_0099b8a0();

        uStack_98 = (uint)('\0' < (char)param_2);

        puStack_c8 = (uint8_t *)&pfStack_114;

        ppuStack_110 = *(uint8_t ***)(param_3 + 0x684 + uStack_98 * 4);

        pfStack_114 = pfStack_e0;

        pfStack_118 = (float *)0x3;

        puStack_11c = (uint8_t *)0x5a78e6;

        ppfStack_10c = (float **)ppuStack_110;

        (**(code **)(*piVar8 + 0x10))();

        puStack_11c = (uint8_t *)0x5a78ed;

        FUN_0044b440();

        puVar9 = puStack_d0;

        ppuStack_110 = (uint8_t **)0x5a7901;

        iVar3 = (**(code **)(*(int *)(iVar3 + *(int *)(puStack_d0 + 0xe8)) + 0x48))();

        fVar11 = (*(float *)(iVar3 + 0x20) - *(float *)(iVar3 + 0x14)) * DAT_00a0f298;

        pfStack_e8 = (float *)((float)pfStack_e8 * fVar11);

        puStack_dc = (uint8_t *)(fVar11 * fStack_f0 + (float)puStack_dc);

        fStack_d8 = fStack_ec * fVar11 + fStack_d8;

        fStack_d4 = (float)pfStack_e8 + fStack_d4;

        puStack_c8 = (uint8_t *)((float)puStack_c8 - fVar11 * fStack_f0);

        local_c4 = local_c4 - fStack_ec * fVar11;

        puStack_e4 = puVar9 + param_2 * 8 + 0xfc;

        fStack_c0 = fStack_c0 - (float)pfStack_e8;

        uVar7 = 0;

        do {

          piVar8 = (int *)((int)pfStack_e0 + *(int *)(puVar9 + 0xec) + 0x14c);

          pfStack_cc = (float *)(uVar7 & 0x80000001);

          if ((int)pfStack_cc < 0) {

            pfStack_cc = (float *)(((int)pfStack_cc - 1U | 0xfffffffe) + 1);

          }

          ppuStack_110 = &puStack_c8;

          if (pfStack_cc == (float *)0x0) {

            ppuStack_110 = &puStack_dc;

          }

          pfStack_114 = (float *)0x5a79f5;

          (**(code **)(*piVar8 + 0x18))();

          pfStack_118 = (float *)auStack_80;

          pfStack_114 = param_4;

          puStack_11c = (uint8_t *)0x5a7a3e;

          FUN_004e96e0();

          puStack_11c = &stack0xffffff00;

          FUN_004e9530(&fStack_90);

          pfStack_114 = &fStack_90;

          pfStack_118 = (float *)auStack_80;

          puStack_11c = (uint8_t *)0x5a7a6f;

          FUN_004249f0();

          pfStack_114 = &fStack_90;

          pfStack_118 = (float *)auStack_6c;

          puStack_11c = (uint8_t *)0x5a7a84;

          pfVar5 = (float *)FUN_004e88e0();

          fVar11 = *pfVar5;

          fVar1 = pfVar5[1];

          fVar2 = pfVar5[2];

          pfStack_114 = (float *)0x5a7aa4;

          iVar3 = (**(code **)(*piStack_a4 + 0xc))();

          ppfVar6 = &pfStack_cc;

          if (puStack_d0 == (uint8_t *)0x0) {

            ppfVar6 = &pfStack_e0;

          }

          fStack_b4 = (float)*ppfVar6 - (*(float *)(iVar3 + 0x90) + fVar11);

          fStack_b0 = (float)ppfVar6[1] - (*(float *)(iVar3 + 0x94) + fVar1);

          pfStack_ac = (float *)((float)ppfVar6[2] - (*(float *)(iVar3 + 0x98) + fVar2));

          puStack_d0 = (uint8_t *)&puStack_11c;

          puStack_11c = (uint8_t *)

                        SQRT(fStack_b4 * fStack_b4 +

                             fStack_b0 * fStack_b0 + (float)pfStack_ac * (float)pfStack_ac);

          *pfStack_e8 = (float)puStack_11c;

          pfStack_118 = *(float **)(param_3 + 0x68c + aiStack_a0[0] * 4);

          uVar12 = 3;

          pfStack_114 = pfStack_118;

          (**(code **)(*piVar8 + 0x10))(3);

          FUN_0044b440(uVar12);

          puStack_11c = &stack0xffffff08;

          pfStack_118 = (float *)puStack_11c;

          FUN_0076f5f0();

          pfStack_118 = (float *)aiStack_a0;

          puStack_11c = &stack0xffffff08;

          FUN_00972580();

          pfStack_118 = (float *)0x3;

          puStack_11c = (uint8_t *)0x5a7bd1;

          iVar3 = (**(code **)(*piVar8 + 0x10))();

          ppuStack_110 = (uint8_t **)auStack_5c;

          *(uint32_t /* width from decompiler */ *)(iVar3 + 0xbc) = 0xffffffff;

          *(int *)(iVar3 + 0xb4) = *(int *)(iVar3 + 0xb4) + 1;

          pfStack_114 = (float *)0x5a7bf5;

          FUN_0099b8a0();

          pfStack_e0 = pfStack_e0 + 0x53;

          puStack_e4 = puStack_e4 + 4;

          uVar7 = uVar7 + 1;

          puVar9 = puStack_d0;

        } while ((int)uVar7 < 2);

      }

    }

  }

  return;

}
