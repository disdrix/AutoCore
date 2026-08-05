// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006bc990
// -----------------------------------------------------------------------------
// Stable ID: aa_006bc990
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x006bc990  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~360 non-empty decompiler lines.
//  - Control keywords: if×28, do×10, while×10, goto×1, return×1.
//  - Notable callees: FUN_005b3370×3, rsqrtss×2, FUN_005b3300, FUN_006bc990.
//  - Return sites: 1.

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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006bc990(int *param_1,float param_2,int param_3,char *param_4,uint8_t *param_5)



{

  ushort uVar1;

  uint8_t auVar2 [16];

  float *pfVar3;

  int iVar4;

  int iVar5;

  float *pfVar6;

  uint uVar7;

  uint uVar8;

  float *pfVar9;

  float *pfVar10;

  ushort *puVar11;

  int iVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  float fVar20;

  uint8_t auVar18 [16];

  uint8_t auVar19 [16];

  uint8_t auVar21 [16];

  uint8_t auVar22 [16];

  uint8_t auVar23 [16];

  float *local_c0;

  uint local_bc;

  uint local_b8;

  float local_b4;

  float *local_b0;

  float local_ac;

  float local_a8;

  ushort *local_a4;

  float *local_a0;

  float local_9c;

  ushort *local_98;

  float local_94;

  ushort *local_90;

  ushort *local_8c;

  float local_88;

  int local_84;

  float local_80;

  float fStack_7c;

  float fStack_78;

  float fStack_74;

  int local_64;

  float local_60;

  float fStack_5c;

  float fStack_58;

  float fStack_54;

  float local_50;

  float fStack_4c;

  float fStack_48;

  float fStack_44;

  float local_40;

  float fStack_3c;

  float fStack_38;

  float fStack_34;

  float local_30;

  uint32_t /* width from decompiler */ uStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  float local_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  *param_5 = 0;

  if (*param_4 != '\0') {

    iVar5 = param_1[1];

    iVar12 = *param_1;

    iVar4 = 0;

    if (0 < param_1[2]) {

      do {

        *(uint16_t *)(param_1[1] + 6 + iVar4 * 8) = 0;

        iVar4 = iVar4 + 1;

      } while (iVar4 < param_1[2]);

    }

    local_b4 = 0.0;

    local_84 = iVar5;

    local_64 = iVar12;

    if (0 < param_1[2]) {

      do {

        puVar11 = (ushort *)(param_1[1] + (int)local_b4 * 8);

        if (puVar11[3] != 1) {

          uVar1 = puVar11[1];

          puVar11[3] = 1;

          *(uint16_t *)(iVar5 + 6 + (uint)uVar1 * 8) = 1;

          local_b0 = (float *)(uint)*puVar11;

          local_ac = (float)(uint)*(ushort *)(iVar5 + (uint)uVar1 * 8);

          pfVar6 = (float *)((int)local_ac * 0x10 + iVar12);

          pfVar10 = (float *)((int)local_b0 * 0x10 + iVar12);

          fVar15 = *pfVar6 - *pfVar10;

          uVar8 = 0;

          local_98 = (ushort *)0x358637bd;

          fVar17 = pfVar6[1] - pfVar10[1];

          fVar20 = pfVar6[2] - pfVar10[2];

          fStack_74 = pfVar6[3] - pfVar10[3];

          local_c0 = (float *)0x0;

          local_b8 = 0x80000000;

          local_bc = 0;

          local_90 = (ushort *)(fVar20 * fVar20 + fVar17 * fVar17 + fVar15 * fVar15);

          local_9c = local_ac;

          local_94 = (float)local_b0;

          local_8c = local_90;

          local_80 = fVar15;

          fStack_7c = fVar17;

          fStack_78 = fVar20;

          if (((((float *)local_ac != local_b0) && (pfVar10[3] == g_flZero)) &&

              (pfVar6[3] == g_flZero)) && (local_a8 = param_2, (int)param_2 < param_3 + 1)) {

            local_a0 = (float *)((int)param_2 * 0x10 + 0xc + iVar12);

            do {

              if (((local_94 != local_a8) && (local_9c != local_a8)) && (*local_a0 == g_flZero)) {

                local_60 = local_a0[-3] - *pfVar10;

                fStack_5c = local_a0[-2] - pfVar10[1];

                fStack_58 = local_a0[-1] - pfVar10[2];

                fStack_54 = *local_a0 - pfVar10[3];

                local_a4 = (ushort *)(fVar20 * fStack_58 + fVar17 * fStack_5c + fVar15 * local_60);

                fVar13 = fVar17 * fStack_58 - fVar20 * fStack_5c;

                fVar14 = fVar20 * local_60 - fVar15 * fStack_58;

                fVar16 = fVar15 * fStack_5c - fVar17 * local_60;

                local_88 = fVar16 * fVar16 + fVar14 * fVar14 + fVar13 * fVar13;

                if (local_88 < *(float *)(param_4 + 8)) {

                  if ((float)local_98 <= (float)local_a4) {

                    if ((float)local_a4 <= (float)local_90) {

                      if (uVar8 == (local_b8 & 0x7fffffff)) {

                        FUN_005b3370(&local_c0,4);

                        uVar8 = local_bc;

                        fVar15 = local_80;

                        fVar17 = fStack_7c;

                        fVar20 = fStack_78;

                      }

                      local_c0[uVar8] = local_a8;

                    }

                    else {

                      if (uVar8 == (local_b8 & 0x7fffffff)) {

                        FUN_005b3370(&local_c0,4);

                        uVar8 = local_bc;

                        fVar15 = local_80;

                        fVar17 = fStack_7c;

                        fVar20 = fStack_78;

                      }

                      local_c0[uVar8] = local_ac;

                      local_ac = local_a8;

                      local_90 = local_a4;

                    }

                  }

                  else {

                    if (uVar8 == (local_b8 & 0x7fffffff)) {

                      FUN_005b3370(&local_c0,4);

                      uVar8 = local_bc;

                      fVar15 = local_80;

                      fVar17 = fStack_7c;

                      fVar20 = fStack_78;

                    }

                    local_c0[uVar8] = (float)local_b0;

                    local_b0 = (float *)local_a8;

                    local_98 = local_a4;

                  }

                  uVar8 = local_bc + 1;

                  local_bc = uVar8;

                }

              }

              local_a0 = local_a0 + 4;

              local_a8 = (float)((int)local_a8 + 1);

            } while ((int)local_a8 < param_3 + 1);

          }

          iVar4 = 0;

          if (0 < (int)uVar8) {

            do {

              fVar15 = local_c0[iVar4];

              if (((float *)fVar15 != local_b0) && (fVar15 != local_ac)) {

                *(uint32_t /* width from decompiler */ *)((int)fVar15 * 0x10 + 0xc + iVar12) = 0x3f800000;

                *param_5 = 1;

                uVar8 = local_bc;

              }

              iVar4 = iVar4 + 1;

            } while (iVar4 < (int)uVar8);

          }

          if (-1 < (int)local_b8) {

            (**(code **)(*DAT_00b05060 + 0x14))(local_c0,local_b8 << 2,0x12);

          }

        }

        local_b4 = (float)((int)local_b4 + 1);

      } while ((int)local_b4 < param_1[2]);

    }

    iVar4 = 0;

    if (0 < param_1[2]) {

      do {

        *(uint16_t *)(param_1[1] + 6 + iVar4 * 8) = 0;

        iVar4 = iVar4 + 1;

      } while (iVar4 < param_1[2]);

    }

    if ((2 < param_3 - (int)param_2) && (2 < param_1[2])) {

      local_a4 = (ushort *)(param_3 + 1);

      local_ac = param_2;

      if ((int)param_2 < (int)local_a4) {

        local_b0 = (float *)((int)param_2 * 0x10 + 0xc + iVar12);

        do {

          if (*local_b0 == g_flZero) {

            uVar8 = 0x80000000;

            local_c0 = (float *)0x0;

            local_bc = 0;

            local_b8 = 0x80000000;

            local_b4 = 0.0;

            if (0 < param_1[2]) {

              do {

                if ((*(short *)(param_1[1] + 6 + (int)local_b4 * 8) != 1) &&

                   ((float)(uint)*(ushort *)(param_1[1] + (int)local_b4 * 8) == local_ac)) {

                  *(uint16_t *)(param_1[1] + 6 + (int)local_b4 * 8) = 1;

                  local_88 = 3.0;

                  puVar11 = (ushort *)

                            (iVar5 + (uint)*(ushort *)(param_1[1] + 2 + (int)local_b4 * 8) * 8);

                  local_30 = 3.0;

                  uStack_2c = 0;

                  uStack_28 = 0;

                  uStack_24 = 0;

                  local_8c = (ushort *)0x3f000000;

                  local_20 = 0.5;

                  uStack_1c = 0;

                  uStack_18 = 0;

                  uStack_14 = 0;

                  local_90 = puVar11;

                  do {

                    uVar8 = local_bc;

                    *(uint16_t *)(iVar5 + 6 + (uint)puVar11[2] * 8) = 1;

                    pfVar10 = (float *)((uint)*puVar11 * 0x10 + iVar12);

                    pfVar6 = (float *)((uint)*(ushort *)(iVar5 + (uint)puVar11[2] * 8) * 0x10 +

                                      iVar12);

                    pfVar9 = (float *)((uint)*(ushort *)

                                              (iVar5 + (uint)*(ushort *)

                                                              (iVar5 + (uint)puVar11[2] * 8 + 4) * 8

                                              ) * 0x10 + iVar12);

                    local_40 = *pfVar10 - *pfVar6;

                    iVar4 = local_bc + 1;

                    fStack_3c = pfVar10[1] - pfVar6[1];

                    fStack_38 = pfVar10[2] - pfVar6[2];

                    fStack_34 = pfVar10[3] - pfVar6[3];

                    local_60 = *pfVar9 - *pfVar6;

                    fStack_5c = pfVar9[1] - pfVar6[1];

                    fStack_58 = pfVar9[2] - pfVar6[2];

                    fStack_54 = pfVar9[3] - pfVar6[3];

                    if ((int)(local_b8 & 0x7fffffff) < iVar4) {

                      iVar5 = (local_b8 & 0x7fffffff) * 2;

                      if (iVar5 <= iVar4) {

                        iVar5 = iVar4;

                      }

                      FUN_005b3300(&local_c0,iVar5,0x10);

                    }

                    fVar17 = fStack_3c * fStack_58 - fStack_38 * fStack_5c;

                    fVar20 = fStack_38 * local_60 - local_40 * fStack_58;

                    fVar13 = local_40 * fStack_5c - fStack_3c * local_60;

                    fVar15 = fVar20 * fVar20;

                    fStack_4c = fVar13 * fVar13;

                    auVar21._4_4_ = fVar15;

                    auVar21._0_4_ = fVar15;

                    auVar21._8_4_ = fVar15;

                    auVar21._12_4_ = fVar15;

                    auVar22._4_12_ = auVar21._4_12_;

                    auVar22._0_4_ = fVar15 + fVar17 * fVar17;

                    auVar23._4_4_ = fStack_4c;

                    auVar23._0_4_ = fStack_4c + auVar22._0_4_;

                    auVar23._8_4_ = fStack_4c;

                    auVar23._12_4_ = fStack_4c;

                    auVar23 = rsqrtss(auVar22,auVar23);

                    local_50 = auVar23._0_4_;

                    pfVar6 = local_c0 + uVar8 * 4;

                    fVar15 = local_20 * local_50 *

                             (local_30 - (fStack_4c + auVar22._0_4_) * local_50 * local_50);

                    *pfVar6 = fVar15 * fVar17;

                    pfVar6[1] = fVar15 * fVar20;

                    pfVar6[2] = fVar15 * fVar13;

                    pfVar6[3] = fVar15 * (fStack_34 * fStack_54 - fStack_34 * fStack_54);

                    puVar11 = (ushort *)

                              (local_84 + (uint)*(ushort *)(local_84 + 2 + (uint)puVar11[2] * 8) * 8

                              );

                    uVar8 = local_b8;

                    iVar5 = local_84;

                    iVar12 = local_64;

                    local_bc = iVar4;

                    fStack_48 = fStack_4c;

                    fStack_44 = fStack_4c;

                  } while (puVar11 != local_90);

                }

                local_b4 = (float)((int)local_b4 + 1);

              } while ((int)local_b4 < param_1[2]);

              if (0 < (int)local_bc) {

                local_80 = 0.0;

                fStack_7c = 0.0;

                fStack_78 = 0.0;

                fStack_74 = 0.0;

                pfVar6 = local_c0;

                uVar7 = local_bc;

                do {

                  fVar15 = *pfVar6;

                  pfVar10 = pfVar6 + 1;

                  pfVar9 = pfVar6 + 2;

                  pfVar3 = pfVar6 + 3;

                  pfVar6 = pfVar6 + 4;

                  uVar7 = uVar7 + -1;

                  local_80 = local_80 + fVar15;

                  fStack_7c = fStack_7c + *pfVar10;

                  fStack_78 = fStack_78 + *pfVar9;

                  fStack_74 = fStack_74 + *pfVar3;

                } while (uVar7 != 0);

                fVar15 = fStack_7c * fStack_7c;

                fVar17 = fStack_78 * fStack_78;

                local_98 = (ushort *)(fVar17 + fVar15 + local_80 * local_80);

                if (*(float *)(param_4 + 0xc) < (float)local_98) {

                  auVar18._4_4_ = fVar15;

                  auVar18._0_4_ = fVar15;

                  auVar18._8_4_ = fVar15;

                  auVar18._12_4_ = fVar15;

                  auVar19._4_12_ = auVar18._4_12_;

                  auVar19._0_4_ = fVar15 + local_80 * local_80;

                  auVar2._4_4_ = fVar17;

                  auVar2._0_4_ = fVar17 + auVar19._0_4_;

                  auVar2._8_4_ = fVar17;

                  auVar2._12_4_ = fVar17;

                  auVar23 = rsqrtss(auVar19,auVar2);

                  local_50 = auVar23._0_4_;

                  local_94 = 3.0;

                  local_a0 = (float *)0x3f000000;

                  fVar15 = local_50 * 0.5 * (3.0 - (fVar17 + auVar19._0_4_) * local_50 * local_50);

                  iVar4 = 0;

                  local_80 = fVar15 * local_80;

                  fStack_7c = fVar15 * fStack_7c;

                  fStack_78 = fVar15 * fStack_78;

                  fStack_74 = fVar15 * fStack_74;

                  fStack_4c = fVar17;

                  fStack_48 = fVar17;

                  fStack_44 = fVar17;

                  if (0 < (int)local_bc) {

                    local_b4 = g_flOne - *(float *)(param_4 + 0xc);

                    pfVar6 = local_c0;

                    do {

                      local_9c = pfVar6[2] * fStack_78 + pfVar6[1] * fStack_7c + *pfVar6 * local_80;

                      uVar8 = local_b8;

                      if (local_9c < local_b4) goto LAB_006bd16e;

                      iVar4 = iVar4 + 1;

                      pfVar6 = pfVar6 + 4;

                    } while (iVar4 < (int)local_bc);

                  }

                  *local_b0 = 1.0;

                  *param_5 = 1;

                }

              }

            }

LAB_006bd16e:

            if (-1 < (int)uVar8) {

              (**(code **)(*DAT_00b05060 + 0x14))(local_c0,uVar8 << 4,0x12);

            }

          }

          local_ac = (float)((int)local_ac + 1);

          local_b0 = local_b0 + 4;

        } while ((int)local_ac < (int)local_a4);

      }

    }

  }

  return;

}
