// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00694a70
// -----------------------------------------------------------------------------
// Stable ID: aa_00694a70
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00694a70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~366 non-empty decompiler lines.
//  - Control keywords: if×22, return×7, while×5, for×4, do×4.
//  - Notable callees: FUN_004490a0×3, SQRT×3, FUN_0068bac0×2, FUN_0068c910×2, FUN_0068eba0×2, CONCAT31, FUN_0068bad0, FUN_0068c650.
//  - Return sites: 7.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00694a70(int *param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  float fVar4;

  int *piVar5;

  short sVar6;

  int iVar7;

  float *pfVar8;

  float *pfVar9;

  uint uVar10;

  float *pfVar11;

  int iVar12;

  uint uVar13;

  float *pfVar14;

  uint32_t /* width from decompiler */ *puVar15;

  float *local_144;

  int *local_140;

  uint local_13c;

  uint local_138;

  float local_134;

  float local_130;

  float local_12c;

  float local_128;

  int *local_124;

  float local_120;

  float local_11c;

  float local_118;

  float local_114;

  float local_110;

  void *local_10c;

  uint32_t /* width from decompiler */ *local_108;

  int local_104;

  uint8_t local_100 [4];

  uint32_t /* width from decompiler */ *local_fc;

  uint32_t /* width from decompiler */ *local_f8;

  int local_f4;

  float local_f0;

  float local_ec;

  void *local_e8;

  uint32_t /* width from decompiler */ *local_e4;

  int local_e0;

  float local_dc;

  float local_d8;

  float local_d4;

  float local_d0;

  float local_cc;

  float local_c4;

  float local_c0;

  float local_bc [4];

  float local_ac;

  float local_a8;

  float local_a4;

  float local_a0;

  float local_9c;

  float local_98 [4];

  float local_88;

  float local_84;

  float local_80;

  float local_7c;

  float local_78;

  float *local_74;

  uint8_t local_70 [4];

  void *local_6c;

  int local_68;

  uint32_t /* width from decompiler */ local_64;

  float local_60;

  float local_5c;

  float local_58;

  float local_54;

  uint8_t local_50 [4];

  float *local_4c;

  uint32_t /* width from decompiler */ local_48;

  uint32_t /* width from decompiler */ local_44;

  float local_3c;

  float local_38;

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  uint8_t local_1c [16];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009aa881;

  local_c = ExceptionList;

  if ((*param_1 != 0) && (param_1[1] != 0)) {

    local_6c = (void *)0x0;

    local_68 = 0;

    local_64 = 0;

    local_4c = (float *)0x0;

    local_48 = 0;

    local_44 = 0;

    local_4 = 1;

    ExceptionList = &local_c;

    local_124 = param_1;

    FUN_00693020(param_2,local_70,local_50);

    if (local_6c == (void *)0x0) {

      iVar7 = 0;

    }

    else {

      iVar7 = (local_68 - (int)local_6c) / 0xc;

    }

    *(int *)(param_2 + 0x2c) = iVar7;

    *(uint *)(param_2 + 0x28) = (uint)*(ushort *)(*param_1 + 0x1a);

    for (local_138 = 0;

        (*(int *)(param_2 + 4) != 0 &&

        (uVar10 = (*(int *)(param_2 + 8) - *(int *)(param_2 + 4)) / 0x38, local_138 < uVar10));

        local_138 = local_138 + 1) {

      local_128 = (float)(int)local_138;

      if ((int)local_138 < 0) {

        local_128 = local_128 + _DAT_00aaa5dc;

      }

      fVar4 = (float)(int)uVar10;

      if ((int)uVar10 < 0) {

        fVar4 = fVar4 + _DAT_00aaa5dc;

      }

      local_140 = (int *)0x0;

      local_128 = local_128 / (fVar4 - g_flOne);

      local_13c = uVar10;

      if (*(int *)(param_2 + 0x2c) != 0) {

        local_120 = (float)(local_138 * 0x38);

        local_144 = local_4c;

        local_13c = (int)local_4c - (int)local_6c;

        pfVar9 = (float *)((int)local_6c + 8);

        do {

          local_f0 = (float)(int)local_140;

          if ((int)local_140 < 0) {

            local_f0 = local_f0 + _DAT_00aaa5dc;

          }

          fVar4 = (float)*(int *)(param_2 + 0x2c);

          if (*(int *)(param_2 + 0x2c) < 0) {

            fVar4 = fVar4 + _DAT_00aaa5dc;

          }

          pfVar8 = (float *)((int)local_120 + *(int *)(param_2 + 4));

          local_f0 = local_f0 / (fVar4 - g_flOne);

          pfVar11 = pfVar8 + 3;

          pfVar14 = local_bc;

          for (iVar7 = 9; iVar7 != 0; iVar7 = iVar7 + -1) {

            *pfVar14 = *pfVar11;

            pfVar11 = pfVar11 + 1;

            pfVar14 = pfVar14 + 1;

          }

          local_74 = pfVar8;

          pfVar8 = pfVar8 + -0xb;

          if (local_138 == 0) {

            pfVar8 = local_bc;

          }

          uVar2 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x1c);

          pfVar11 = local_98;

          for (iVar7 = 9; iVar7 != 0; iVar7 = iVar7 + -1) {

            *pfVar11 = *pfVar8;

            pfVar8 = pfVar8 + 1;

            pfVar11 = pfVar11 + 1;

          }

          FUN_0068eba0(uVar2);

          FUN_0068eba0(*(uint32_t /* width from decompiler */ *)(param_2 + 0x1c));

          piVar5 = local_124;

          local_30 = local_a0 * *pfVar9 + local_ac * pfVar9[-1] + local_bc[1] * pfVar9[-2];

          local_2c = local_9c * *pfVar9 + local_a8 * pfVar9[-1] + local_bc[2] * pfVar9[-2];

          local_3c = local_7c * *pfVar9 + local_88 * pfVar9[-1] + local_98[1] * pfVar9[-2];

          local_38 = local_78 * *pfVar9 + local_84 * pfVar9[-1] + local_98[2] * pfVar9[-2];

          local_ec = local_80 * *pfVar9 + local_98[3] * pfVar9[-1] + local_98[0] * pfVar9[-2] +

                     local_a4 * *pfVar9 + local_bc[3] * pfVar9[-1] + local_bc[0] * pfVar9[-2];

          local_118 = local_3c + local_30;

          local_60 = local_38 + local_2c;

          local_28 = local_ec * DAT_00a0f298;

          local_24 = local_118 * DAT_00a0f298;

          local_54 = local_60 * DAT_00a0f298 + local_74[2];

          local_58 = local_24 + local_74[1];

          local_5c = local_28 + *local_74;

          local_114 = g_flOne / SQRT(local_118 * local_118 +

                                     local_60 * local_60 + local_ec * local_ec);

          local_11c = local_ec * local_114;

          local_118 = local_118 * local_114;

          local_114 = local_60 * local_114;

          FUN_0068c6f0(&local_5c);

          local_dc = local_f0;

          local_d8 = local_128;

          FUN_0068c910(&local_dc,*(uint8_t *)(param_2 + 0x18));

          pfVar8 = local_144;

          local_f8 = (uint32_t /* width from decompiler */ *)

                     (local_9c * *(float *)(local_13c + (int)pfVar9) +

                     local_bc[2] * *local_144 + local_a8 * local_144[1]);

          local_c4 = local_7c * *(float *)(local_13c + (int)pfVar9) +

                     local_98[1] * *local_144 + local_88 * local_144[1];

          local_c0 = local_78 * *(float *)(local_13c + (int)pfVar9) +

                     local_98[2] * *local_144 + local_84 * local_144[1];

          local_110 = local_98[0] * *local_144 +

                      local_80 * *(float *)(local_13c + (int)pfVar9) + local_98[3] * local_144[1] +

                      local_bc[0] * *local_144 +

                      local_a4 * *(float *)(local_13c + (int)pfVar9) + local_bc[3] * local_144[1];

          local_134 = local_110 * DAT_00a0f298;

          local_130 = (local_c4 +

                      local_a0 * *(float *)(local_13c + (int)pfVar9) +

                      local_bc[1] * *local_144 + local_ac * local_144[1]) * DAT_00a0f298;

          local_12c = (local_c0 + (float)local_f8) * DAT_00a0f298;

          fVar4 = g_flOne / SQRT(local_134 * local_134 +

                                 local_130 * local_130 + local_12c * local_12c);

          local_134 = local_134 * fVar4;

          local_130 = local_130 * fVar4;

          local_12c = local_12c * fVar4;

          if (*(int *)(piVar5[1] + 0x78) == 1) {

            FUN_0069ddf0(&local_134,&local_5c,local_1c,2);

            FUN_0068c650(local_1c);

          }

          else {

            FUN_0068c830(&local_134);

            FUN_0068cb80(&local_11c);

            local_d4 = local_130 * local_114 - local_12c * local_118;

            local_d0 = local_12c * local_11c - local_114 * local_134;

            local_cc = local_118 * local_134 - local_130 * local_11c;

            local_144 = (float *)(g_flOne /

                                 SQRT(local_d4 * local_d4 +

                                      local_d0 * local_d0 + local_cc * local_cc));

            local_d4 = local_d4 * (float)local_144;

            local_d0 = local_d0 * (float)local_144;

            local_cc = local_cc * (float)local_144;

            FUN_0068cc90(&local_d4);

          }

          if (*(char *)(*piVar5 + 8) != '\0') {

            iVar7 = (int)local_120 + *(int *)(param_2 + 4);

            FUN_0068cac0(*(uint32_t /* width from decompiler */ *)(iVar7 + 0x30),*(uint8_t *)(iVar7 + 0x34));

          }

          *(short *)(*piVar5 + 0x1a) = *(short *)(*piVar5 + 0x1a) + 1;

          local_140 = (int *)((int)local_140 + 1);

          local_144 = pfVar8 + 3;

          pfVar9 = pfVar9 + 3;

          param_1 = local_124;

        } while (local_140 < *(int **)(param_2 + 0x2c));

      }

    }

    local_e8 = (void *)0x0;

    local_e4 = (uint32_t /* width from decompiler */ *)0x0;

    local_e0 = 0;

    local_fc = (uint32_t /* width from decompiler */ *)0x0;

    local_f8 = (uint32_t /* width from decompiler */ *)0x0;

    local_f4 = 0;

    local_138 = 0;

    if (*(int *)(param_2 + 0x2c) != 0) {

      local_13c = 0;

      do {

        uVar10 = local_138;

        local_144 = (float *)0x0;

        local_10c = (void *)0x0;

        local_108 = (uint32_t /* width from decompiler */ *)0x0;

        local_104 = 0;

        local_4 = CONCAT31(local_4._1_3_,4);

        FUN_004490a0(0,1,&local_13c);

        local_140 = (int *)0x1;

        while ((puVar15 = local_f8, *(int *)(param_2 + 4) != 0 &&

               (local_140 < (int *)((*(int *)(param_2 + 8) - *(int *)(param_2 + 4)) / 0x38)))) {

          iVar7 = *(int *)(param_2 + 0x2c);

          iVar3 = *(int *)(param_2 + 0x28);

          iVar12 = (int)local_140 + -1;

          pfVar9 = (float *)FUN_0068bac0(iVar7 * (int)local_140 + iVar3 + uVar10);

          pfVar8 = (float *)FUN_0068bac0(iVar12 * iVar7 + iVar3 + uVar10);

          local_c4 = pfVar8[1];

          local_c0 = pfVar8[2];

          local_120 = *pfVar8 - *pfVar9;

          local_124 = (int *)(local_c0 - pfVar9[2]);

          local_128 = (float)(((int)(local_120 * local_120 +

                                    (float)local_124 * (float)local_124 +

                                    (local_c4 - pfVar9[1]) * (local_c4 - pfVar9[1])) >> 1) +

                             0x1fc00000);

          local_144 = (float *)(local_128 + (float)local_144);

          if ((local_10c == (void *)0x0) ||

             ((uint)(local_104 - (int)local_10c >> 2) <=

              (uint)((int)local_108 - (int)local_10c >> 2))) {

            FUN_004490a0(local_108,1,&local_144);

            local_140 = (int *)((int)local_140 + 1);

            uVar10 = local_138;

          }

          else {

            *local_108 = local_144;

            local_108 = local_108 + 1;

            local_140 = (int *)((int)local_140 + 1);

            uVar10 = local_138;

          }

        }

        if ((local_fc == (uint32_t /* width from decompiler */ *)0x0) ||

           ((uint)(local_f4 - (int)local_fc >> 4) <= (uint)((int)local_f8 - (int)local_fc >> 4))) {

          FUN_00694220(local_f8,1,&local_110);

        }

        else {

          FUN_00693510(local_f8,1,&local_110,local_100,local_13c);

          local_f8 = puVar15 + 4;

        }

        if ((local_e8 == (void *)0x0) ||

           ((uint)(local_e0 - (int)local_e8 >> 2) <= (uint)((int)local_e4 - (int)local_e8 >> 2))) {

          FUN_004490a0(local_e4,1,&local_144);

        }

        else {

          *local_e4 = local_144;

          local_e4 = local_e4 + 1;

        }

        local_4._0_1_ = 3;

        if (local_10c != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(local_10c);

        }

        local_138 = uVar10 + 1;

        local_10c = (void *)0x0;

        local_108 = (uint32_t /* width from decompiler */ *)0x0;

        local_104 = 0;

      } while (local_138 < *(uint *)(param_2 + 0x2c));

    }

    local_4._0_1_ = 3;

    uVar10 = 0;

    if (*(int *)(param_2 + 0x2c) != 0) {

      local_140 = local_fc + 1;

      do {

        for (uVar13 = 1;

            (*(int *)(param_2 + 4) != 0 &&

            (uVar13 < (uint)((*(int *)(param_2 + 8) - *(int *)(param_2 + 4)) / 0x38)));

            uVar13 = uVar13 + 1) {

          sVar6 = *(short *)(param_2 + 0x2c) * (short)uVar13 + (short)uVar10 +

                  *(short *)(param_2 + 0x28);

          *(short *)(*param_1 + 0x1a) = sVar6;

          pfVar9 = (float *)FUN_0068bad0(sVar6);

          local_dc = *pfVar9;

          local_d8 = (*(float *)(*local_140 + uVar13 * 4) / *(float *)((int)local_e8 + uVar10 * 4))

                     * _DAT_009eb1b4;

          FUN_0068c910(&local_dc,*(uint8_t *)(param_2 + 0x18));

          *(short *)(*param_1 + 0x1a) = *(short *)(*param_1 + 0x1a) + 1;

        }

        uVar10 = uVar10 + 1;

        local_140 = local_140 + 4;

      } while (uVar10 < *(uint *)(param_2 + 0x2c));

    }

    if (local_fc != (uint32_t /* width from decompiler */ *)0x0) {

      if (local_fc != local_f8) {

        puVar15 = local_fc + 1;

        do {

          if ((void *)*puVar15 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

            operator_delete((void *)*puVar15);

          }

          *puVar15 = 0;

          puVar15[1] = 0;

          puVar15[2] = 0;

          puVar1 = puVar15 + 3;

          puVar15 = puVar15 + 4;

        } while (puVar1 != local_f8);

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(local_fc);

    }

    if (local_e8 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(local_e8);

    }

    if (local_4c != (float *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(local_4c);

    }

    if (local_6c != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(local_6c);

    }

  }

  ExceptionList = local_c;

  return;

}
