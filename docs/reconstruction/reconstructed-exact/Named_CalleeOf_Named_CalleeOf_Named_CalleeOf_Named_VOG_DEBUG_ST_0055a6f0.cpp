// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_0055a6f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0055a6f0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x0055a6f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~203 non-empty decompiler lines.
//  - Control keywords: if×16, do×2, while×2, return×2, for×1.
//  - Notable callees: SQRT×8, FUN_0055c710×3, CONCAT22×2, ROUND×2, FUN_00559c70, FUN_00559f90, FUN_0055a6f0, FUN_0055c150.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
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



void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_0055a6f0(int param_1,float *param_2,float *param_3,float *param_4)



{

  void *pvVar1;

  void *pvVar2;

  int iVar3;

  uint uVar4;

  int iVar5;

  void *pvVar6;

  uint uVar7;

  uint16_t in_FPUControlWord;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float local_c4;

  float local_c0;

  float local_bc;

  uint32_t /* width from decompiler */ local_b8;

  float local_b4;

  float local_b0;

  float local_ac;

  float local_a8;

  float local_a4;

  float local_a0;

  float local_9c;

  float local_98;

  float local_94;

  float local_90;

  float local_8c;

  float local_88;

  float local_84;

  float local_80;

  float local_7c;

  float local_78;

  float local_74;

  float local_70;

  float local_6c;

  uint8_t local_68 [4];

  void *local_64;

  void *local_60;

  uint32_t /* width from decompiler */ local_5c;

  float local_58;

  float local_54;

  float local_50;

  float local_4c;

  float local_48;

  float local_44;

  float local_30;

  float local_24;

  uint8_t local_18 [12];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a48c1;

  local_c = ExceptionList;

  local_24 = *param_3 - *param_2;

  local_ac = param_3[1] - param_2[1];

  local_74 = param_3[2] - param_2[2];

  local_58 = *param_4 - *param_3;

  local_b4 = SQRT(local_24 * local_24 + local_ac * local_ac + local_74 * local_74);

  local_6c = param_4[1] - param_2[1];

  local_30 = *param_4 - *param_2;

  local_70 = param_4[2] - param_2[2];

  local_b0 = SQRT(local_30 * local_30 + local_6c * local_6c + local_70 * local_70);

  local_9c = SQRT(local_58 * local_58 + (param_4[1] - param_3[1]) * (param_4[1] - param_3[1]) +

                  (param_4[2] - param_3[2]) * (param_4[2] - param_3[2]));

  if (((g_flZero < local_b4) && (0.0 < local_b0)) && (0.0 < local_9c)) {

    fVar10 = (local_9c + local_b0 + local_b4) * DAT_00a0f298;

    fVar10 = SQRT((fVar10 - local_b4) * (fVar10 - local_b0) * (fVar10 - local_9c) * fVar10);

    if (g_flZero < fVar10) {

      fVar8 = *(float *)(param_1 + 0x10) * fVar10;

      if (0.0 <= fVar8) {

        fVar8 = fVar8 + g_flMissionXpRoundBias;

      }

      else {

        fVar8 = fVar8 - g_flMissionXpRoundBias;

      }

      local_b8._2_2_ = (uint16_t)((uint)fVar8 >> 0x10);

      local_b8 = CONCAT22(local_b8._2_2_,in_FPUControlWord);

      iVar5 = (int)ROUND(fVar8);

      if (iVar5 != 0) {

        local_64 = (void *)0x0;

        local_60 = (void *)0x0;

        local_5c = 0;

        local_4 = 0;

        if (iVar5 == 1) {

          local_4c = (*param_4 + *param_2 + *param_3) * g_flDisplayRateScaleOneThird;

          local_48 = (param_4[1] + param_3[1] + param_2[1]) * g_flDisplayRateScaleOneThird;

          local_44 = (param_4[2] + param_2[2] + param_3[2]) * g_flDisplayRateScaleOneThird;

          ExceptionList = &local_c;

          FUN_0055c710(&local_4c);

        }

        else {

          fVar8 = (float)iVar5;

          if (iVar5 < 0) {

            fVar8 = fVar8 + _DAT_00aaa5dc;

          }

          fVar8 = SQRT(fVar10 / fVar8);

          ExceptionList = &local_c;

          FUN_00559c70(param_2,param_3,param_4,local_b4,local_b0,local_9c,&local_98,local_18,

                       &local_c4,&local_a8,&local_58,&local_80,&local_8c);

          fVar10 = SQRT(local_c0 * local_c0 + local_bc * local_bc + local_c4 * local_c4);

          fVar9 = local_80 * local_a8 + local_78 * local_a0 + local_7c * local_a4;

          if (fVar10 != g_flZero) {

            fVar10 = g_flOne / fVar10;

            local_c4 = local_c4 * fVar10;

            local_c0 = local_c0 * fVar10;

            local_bc = local_bc * fVar10;

          }

          fVar10 = local_c4 * local_a8 + local_bc * local_a0 + local_c0 * local_a4;

          fVar12 = local_c4 * fVar10;

          fVar11 = local_c0 * fVar10;

          fVar10 = local_bc * fVar10;

          local_c4 = local_a8 * fVar8;

          local_b0 = g_flOne / fVar8;

          local_80 = local_80 * fVar9 * fVar8;

          local_7c = local_7c * fVar9 * fVar8;

          local_c0 = local_a4 * fVar8;

          local_bc = local_a0 * fVar8;

          local_78 = local_78 * fVar9 * fVar8;

          local_a8 = fVar12 * fVar8;

          local_a4 = fVar11 * fVar8;

          local_a0 = fVar10 * fVar8;

          do {

            local_b4 = SQRT(local_94 * local_94 + local_90 * local_90 + local_98 * local_98) *

                       local_b0;

            if (g_flZero <= local_b4) {

              local_b4 = local_b4 + g_flMissionXpRoundBias;

            }

            else {

              local_b4 = local_b4 - g_flMissionXpRoundBias;

            }

            local_b8 = CONCAT22(local_b8._2_2_,in_FPUControlWord);

            uVar7 = (int)ROUND(local_b4) - 1;

            if (uVar7 == 0) {

              uVar7 = 1;

            }

            uVar4 = 0;

            if (uVar7 != 0) {

              do {

                if (iVar5 == 0) break;

                fVar10 = (float)(int)uVar4;

                if ((int)uVar4 < 0) {

                  fVar10 = fVar10 + _DAT_00aaa5dc;

                }

                fVar10 = (fVar10 + DAT_00a0f298) * fVar8;

                local_4c = local_8c + local_58 * fVar10 + local_c4;

                local_48 = local_88 + local_54 * fVar10 + local_c0;

                local_44 = local_84 + local_50 * fVar10 + local_bc;

                FUN_0055c710(&local_4c);

                uVar4 = uVar4 + 1;

                iVar5 = iVar5 + -1;

              } while (uVar4 < uVar7);

            }

            local_8c = local_80 + local_8c;

            local_88 = local_7c + local_88;

            local_84 = local_78 + local_84;

            local_98 = (local_a8 + local_8c + local_98) - local_8c;

            local_94 = (local_a4 + local_88 + local_94) - local_88;

            local_90 = (local_a0 + local_84 + local_90) - local_84;

          } while (iVar5 != 0);

        }

        local_c4 = local_70 * local_ac - local_6c * local_74;

        local_c0 = local_30 * local_74 - local_70 * local_24;

        local_bc = local_6c * local_24 - local_30 * local_ac;

        local_ac = SQRT(local_c4 * local_c4 + local_c0 * local_c0 + local_bc * local_bc);

        if (local_ac != g_flZero) {

          fVar10 = g_flOne / local_ac;

          local_c4 = local_c4 * fVar10;

          local_c0 = local_c0 * fVar10;

          local_bc = local_bc * fVar10;

        }

        FUN_00559f90(&local_c4,local_68);

        pvVar2 = local_60;

        pvVar1 = local_64;

        if (*(int *)(param_1 + 0x18) == 0) {

          iVar5 = 0;

        }

        else {

          iVar5 = (*(int *)(param_1 + 0x1c) - *(int *)(param_1 + 0x18)) / 0x1c;

        }

        if (local_64 == (void *)0x0) {

          iVar3 = 0;

        }

        else {

          iVar3 = ((int)local_60 - (int)local_64) / 0x1c;

        }

        FUN_0055c150(iVar3 + iVar5);

        for (pvVar6 = pvVar1; pvVar6 != pvVar2; pvVar6 = (void *)((int)pvVar6 + 0x1c)) {

          FUN_0055c710(pvVar6);

        }

        if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(pvVar1);

        }

      }

    }

  }

  ExceptionList = local_c;

  return;

}
