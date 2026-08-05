// =============================================================================
// FUN_0095e3e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0095e3e0
// Address:   0x0095e3e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0095e3e0 @ 0x0095e3e0
// Stable ID: aa_0095e3e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~486 non-empty decompiler lines.
//  - Control keywords: if×61, do×9, while×9, goto×6, return×2, for×1.
//  - Notable callees: CONCAT31×14, FUN_00437050×10, FUN_00768760×10, FUN_00769e40×9, stoChunkReader_EnterChunkScope×9, FUN_00436f10×6, FUN_0076a200×6, stoChunkReader_readF32Array×4.
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

uint FUN_0095e3e0(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint uVar3;

  uint uVar4;

  int *piVar5;

  void *pvVar6;

  uint uVar7;

  uint uVar8;

  uint uVar9;

  int iVar10;

  char *pcVar11;

  int iVar12;

  char *pcVar13;

  char *pcVar14;

  bool bVar15;

  uint8_t auStack_dc [44];

  uint32_t /* width from decompiler */ uStack_b0;

  int iStack_ac;

  uint uVar16;

  int local_8c;

  int *local_88;

  int local_84;

  int local_80;

  int local_7c;

  int local_78;

  char local_58;

  int local_54;

  int local_50;

  char local_44;

  int local_40;

  char local_2c;

  char local_18;

  int local_14;

  int local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b2dfd;

  local_c = ExceptionList;

  iStack_ac = 0x95e41a;

  ExceptionList = &local_c;

  stoChunkReader_EnterChunkScope();

  local_4 = 0;

  if (local_14 != 0x50594244) {

    local_4 = 0xffffffff;

    if (local_18 != '\0') {

      FUN_00769e40();

    }

    ExceptionList = local_c;

    return 0xffffffff;

  }

  if (local_10 == 0) {

    iStack_ac = 0x95e717;

    uVar16 = FUN_0095e280();

    iStack_ac = 0x95e726;

    stoChunkReader_EnterChunkScope();

    if (local_54 == 0x43504441) {

      if (local_50 == 0) {

        local_88 = (int *)0x0;

        local_4 = CONCAT31(local_4._1_3_,2);

        uVar3 = FUN_00439a00();

        uVar16 = uVar16 | uVar3;

        if (0 < local_84) {

          local_8c = local_84;

          do {

            iStack_ac = 0x95e9d7;

            pvVar6 = operator_new(0x3c);

            local_4._0_1_ = 3;

            if (pvVar6 == (void *)0x0) {

              piVar5 = (int *)0x0;

            }

            else {

              iStack_ac = 0x95e9f0;

              piVar5 = (int *)FUN_009892d0();

            }

            local_4 = CONCAT31(local_4._1_3_,2);

            if ((piVar5 != (int *)0x0) && (piVar5[1] = piVar5[1] + 1, piVar5[1] == 1)) {

              (**(code **)(*piVar5 + 4))();

            }

            if ((local_88 != (int *)0x0) && (local_88[1] = local_88[1] + -1, local_88[1] == 0)) {

              (**(code **)(*local_88 + 8))();

            }

            if (*(int *)(param_1 + 0x4044) == 0) {

              iStack_ac = 0x95ea49;

              uVar3 = FUN_00437050();

            }

            else {

              iStack_ac = 0x95ea52;

              uVar3 = FUN_00768760();

            }

            if (*(int *)(param_1 + 0x4044) == 0) {

              iStack_ac = 0x95ea6c;

              uVar4 = FUN_00437050();

            }

            else {

              iStack_ac = 0x95ea75;

              uVar4 = FUN_00768760();

            }

            iStack_ac = 0x95ea85;

            uVar7 = stoChunkReader_readF32Array();

            iStack_ac = 0x95ea97;

            uVar8 = stoChunkReader_readF32Array();

            uVar16 = uVar16 | uVar3 | uVar7 | uVar4 | uVar8;

            iStack_ac = 0x95eab1;

            FUN_0046a5e0();

            local_8c = local_8c + -1;

            local_88 = piVar5;

          } while (local_8c != 0);

          local_8c = 0;

        }

        local_4 = CONCAT31(local_4._1_3_,1);

        iStack_ac = 0x95ead7;

        FUN_00437150();

      }

      else {

        if (local_50 != 1) goto LAB_0095ead9;

        local_88 = (int *)0x0;

        local_4 = CONCAT31(local_4._1_3_,4);

        uVar3 = FUN_00439a00();

        uVar16 = uVar16 | uVar3;

        if (0 < local_84) {

          local_8c = local_84;

          do {

            iStack_ac = 0x95e77d;

            pvVar6 = operator_new(0x3c);

            local_4._0_1_ = 5;

            if (pvVar6 == (void *)0x0) {

              piVar5 = (int *)0x0;

            }

            else {

              iStack_ac = 0x95e796;

              piVar5 = (int *)FUN_009892d0();

            }

            local_4 = CONCAT31(local_4._1_3_,4);

            if ((piVar5 != (int *)0x0) && (piVar5[1] = piVar5[1] + 1, piVar5[1] == 1)) {

              (**(code **)(*piVar5 + 4))();

            }

            if ((local_88 != (int *)0x0) && (local_88[1] = local_88[1] + -1, local_88[1] == 0)) {

              (**(code **)(*local_88 + 8))();

            }

            if (*(int *)(param_1 + 0x4044) == 0) {

              iStack_ac = 0x95e7ef;

              uVar3 = FUN_00437050();

            }

            else {

              iStack_ac = 0x95e7f8;

              uVar3 = FUN_00768760();

            }

            if (*(int *)(param_1 + 0x4044) == 0) {

              iStack_ac = 0x95e812;

              uVar4 = FUN_00437050();

            }

            else {

              iStack_ac = 0x95e81b;

              uVar4 = FUN_00768760();

            }

            iStack_ac = 0x95e82b;

            uVar7 = stoChunkReader_readF32Array();

            iStack_ac = 0x95e83d;

            uVar8 = stoChunkReader_readF32Array();

            if (*(int *)(param_1 + 0x4044) == 0) {

              iStack_ac = 0x95e858;

              uVar9 = FUN_00437050();

            }

            else {

              iStack_ac = 0x95e866;

              uVar9 = FUN_00768760();

            }

            uVar16 = uVar16 | uVar3 | uVar7 | uVar4 | uVar8 | uVar9;

            FUN_004382c0(auStack_dc);

            FUN_00437e40();

            if (0 < local_7c) {

              local_78 = local_7c;

              do {

                iStack_ac = 0x95e8ab;

                stoChunkReader_EnterChunkScope();

                local_4 = CONCAT31(local_4._1_3_,6);

                if (*(int *)(param_1 + 0x4044) == 0) {

                  uVar3 = FUN_00436f10();

                }

                else {

                  uVar3 = FUN_0076a200();

                }

                if (*(int *)(param_1 + 0x4044) == 0) {

                  uVar4 = FUN_00436f10();

                }

                else {

                  uVar4 = FUN_0076a200();

                }

                uVar16 = uVar16 | uVar3 | uVar4;

                local_4 = CONCAT31(local_4._1_3_,4);

                if (local_2c != '\0') {

                  FUN_00769e40();

                }

                local_78 = local_78 + -1;

              } while (local_78 != 0);

            }

            if (*(int *)(param_2 + 100) != 0) {

              iVar12 = *(int *)(*(int *)(param_2 + 100) + 0xc);

              uStack_b0 = 0x95e959;

              iStack_ac = iVar12;

              iVar10 = FUN_0044b150();

              FUN_0043fe60();

              *(int *)(iVar12 + 4) = iVar10;

              **(int **)(iVar10 + 4) = iVar10;

            }

            local_8c = local_8c + -1;

            local_88 = piVar5;

          } while (local_8c != 0);

        }

        local_4 = CONCAT31(local_4._1_3_,1);

        iStack_ac = 0x95e98c;

        FUN_00437150();

      }

    }

    else {

LAB_0095ead9:

      uVar16 = 0xffffffff;

    }

    local_4 = local_4 & 0xffffff00;

    if (local_58 != '\0') {

      FUN_00769e40();

    }

    iStack_ac = 0x95eafe;

    stoChunkReader_EnterChunkScope();

    local_4 = CONCAT31(local_4._1_3_,7);

    if ((local_54 == 0x55534552) && (local_50 == 0)) {

      if (*(int *)(param_1 + 0x4044) == 0) {

        iStack_ac = 0x95eb34;

        uVar3 = FUN_00437050();

      }

      else {

        iStack_ac = 0x95eb42;

        uVar3 = FUN_00768760();

      }

      uVar16 = uVar16 | uVar3;

      FUN_0046a6a0();

      if (0 < local_8c) {

        local_78 = local_8c;

        do {

          local_4._0_1_ = 8;

          local_80 = -1;

          iStack_ac = 0x95eb8a;

          stoChunkReader_EnterChunkScope();

          local_4._0_1_ = 9;

          if (local_40 == 0x42445441) {

            if (*(int *)(param_1 + 0x4044) == 0) {

              iStack_ac = 0x95ebb4;

              uVar3 = FUN_00437050();

            }

            else {

              iStack_ac = 0x95ebc2;

              uVar3 = FUN_00768760();

            }

            if (*(int *)(param_1 + 0x4044) == 0) {

              iStack_ac = 0x95ebda;

              uVar4 = FUN_00437050();

            }

            else {

              iStack_ac = 0x95ebe8;

              uVar4 = FUN_00768760();

            }

            uVar16 = uVar16 | uVar3 | uVar4;

            FUN_004382c0(auStack_dc);

            FUN_00437e40();

            if (0 < local_8c) {

              pcVar13 = (char *)0x20;

              local_7c = local_8c;

              do {

                iStack_ac = 0x95ec2b;

                stoChunkReader_EnterChunkScope();

                local_4 = CONCAT31(local_4._1_3_,10);

                if (*(int *)(param_1 + 0x4044) == 0) {

                  uVar3 = FUN_00436f10();

                }

                else {

                  uVar3 = FUN_0076a200();

                }

                if (*(int *)(param_1 + 0x4044) == 0) {

                  uVar4 = FUN_00436f10();

                }

                else {

                  uVar4 = FUN_0076a200();

                }

                uVar16 = uVar16 | uVar3 | uVar4;

                if (*(uint *)(pcVar13 + -8) < 0x10) {

                  pcVar11 = pcVar13 + -0x1c;

                }

                else {

                  pcVar11 = *(char **)(pcVar13 + -0x1c);

                }

                iVar12 = 3;

                bVar15 = true;

                pcVar14 = "cp";

                do {

                  if (iVar12 == 0) break;

                  iVar12 = iVar12 + -1;

                  bVar15 = *pcVar11 == *pcVar14;

                  pcVar11 = pcVar11 + 1;

                  pcVar14 = pcVar14 + 1;

                } while (bVar15);

                if (bVar15) {

                  pcVar11 = pcVar13;

                  if (0xf < *(uint *)(pcVar13 + 0x14)) {

                    pcVar11 = *(char **)pcVar13;

                  }

                  iStack_ac = 0x95ecbc;

                  local_80 = atoi(pcVar11);

                }

                local_4._0_1_ = 9;

                if (local_2c != '\0') {

                  FUN_00769e40();

                }

                pcVar13 = pcVar13 + 0x38;

                local_7c = local_7c + -1;

              } while (local_7c != 0);

              if (local_80 != -1) {

                if (*(int *)(param_2 + 100) != 0) {

                  puVar1 = *(uint32_t /* width from decompiler */ **)(*(int *)(param_2 + 100) + 0xc);

                  for (puVar2 = (uint32_t /* width from decompiler */ *)*puVar1; puVar2 != puVar1;

                      puVar2 = (uint32_t /* width from decompiler */ *)*puVar2) {

                    if (*(int *)(puVar2[2] + 8) == local_80) {

                      piVar5 = puVar2 + 2;

                      goto LAB_0095ed20;

                    }

                  }

                }

                piVar5 = (int *)0x0;

LAB_0095ed20:

                iVar12 = *piVar5;

                *(uint32_t /* width from decompiler */ *)(iVar12 + 0x30) = 0;

                *(uint32_t /* width from decompiler */ *)(iVar12 + 0x34) = 0;

                *(uint32_t /* width from decompiler */ *)(iVar12 + 0x38) = 0;

                goto LAB_0095ed66;

              }

            }

            FUN_0046a7b0();

          }

LAB_0095ed66:

          local_4._0_1_ = 8;

          if (local_44 != '\0') {

            FUN_00769e40();

          }

          local_4 = CONCAT31(local_4._1_3_,7);

          FUN_00437f20();

          local_78 = local_78 + -1;

        } while (local_78 != 0);

      }

    }

    else {

LAB_0095ed9c:

      uVar16 = 0xffffffff;

    }

  }

  else {

    if (local_10 != 1) {

      uVar16 = 0xffffffff;

      goto LAB_0095edbc;

    }

    iStack_ac = 0x95e488;

    uVar3 = FUN_0095e280();

    iStack_ac = 0x95e49a;

    uVar4 = FUN_004372a0();

    iStack_ac = 0x95e4a6;

    stoChunkReader_EnterChunkScope();

    local_4 = CONCAT31(local_4._1_3_,0xc);

    if ((local_54 != 0x55534552) || (local_50 != 0)) goto LAB_0095ed9c;

    uVar16 = FUN_00439a00();

    uVar16 = uVar3 | uVar4 | uVar16;

    FUN_0046a6a0();

    if (0 < local_8c) {

      local_7c = local_8c;

      do {

        local_4._0_1_ = 0xd;

        local_88 = (int *)0xffffffff;

        iStack_ac = 0x95e51e;

        stoChunkReader_EnterChunkScope();

        local_4._0_1_ = 0xe;

        if (local_40 == 0x42445441) {

          if (*(int *)(param_1 + 0x4044) == 0) {

            iStack_ac = 0x95e548;

            uVar3 = FUN_00437050();

          }

          else {

            iStack_ac = 0x95e556;

            uVar3 = FUN_00768760();

          }

          if (*(int *)(param_1 + 0x4044) == 0) {

            iStack_ac = 0x95e56e;

            uVar4 = FUN_00437050();

          }

          else {

            iStack_ac = 0x95e57c;

            uVar4 = FUN_00768760();

          }

          uVar16 = uVar16 | uVar3 | uVar4;

          FUN_004382c0(auStack_dc);

          FUN_00437e40();

          if (0 < local_78) {

            pcVar13 = (char *)0x20;

            local_80 = local_78;

            do {

              iStack_ac = 0x95e5bf;

              stoChunkReader_EnterChunkScope();

              local_4 = CONCAT31(local_4._1_3_,0xf);

              if (*(int *)(param_1 + 0x4044) == 0) {

                uVar3 = FUN_00436f10();

              }

              else {

                uVar3 = FUN_0076a200();

              }

              if (*(int *)(param_1 + 0x4044) == 0) {

                uVar4 = FUN_00436f10();

              }

              else {

                uVar4 = FUN_0076a200();

              }

              uVar16 = uVar16 | uVar3 | uVar4;

              if (*(uint *)(pcVar13 + -8) < 0x10) {

                pcVar11 = pcVar13 + -0x1c;

              }

              else {

                pcVar11 = *(char **)(pcVar13 + -0x1c);

              }

              iVar12 = 3;

              bVar15 = true;

              pcVar14 = "cp";

              do {

                if (iVar12 == 0) break;

                iVar12 = iVar12 + -1;

                bVar15 = *pcVar11 == *pcVar14;

                pcVar11 = pcVar11 + 1;

                pcVar14 = pcVar14 + 1;

              } while (bVar15);

              if (bVar15) {

                pcVar11 = pcVar13;

                if (0xf < *(uint *)(pcVar13 + 0x14)) {

                  pcVar11 = *(char **)pcVar13;

                }

                iStack_ac = 0x95e650;

                local_88 = (int *)atoi(pcVar11);

              }

              local_4._0_1_ = 0xe;

              if (local_2c != '\0') {

                FUN_00769e40();

              }

              pcVar13 = pcVar13 + 0x38;

              local_80 = local_80 + -1;

            } while (local_80 != 0);

            if (local_88 != (int *)0xffffffff) {

              piVar5 = (int *)FUN_0046a620();

              iVar12 = *piVar5;

              *(uint32_t /* width from decompiler */ *)(iVar12 + 0x30) = 0;

              *(uint32_t /* width from decompiler */ *)(iVar12 + 0x34) = 0;

              *(uint32_t /* width from decompiler */ *)(iVar12 + 0x38) = 0;

              goto LAB_0095e6d0;

            }

          }

          FUN_0046a7b0();

        }

LAB_0095e6d0:

        local_4._0_1_ = 0xd;

        if (local_44 != '\0') {

          FUN_00769e40();

        }

        local_4 = CONCAT31(local_4._1_3_,0xc);

        FUN_00437f20();

        local_7c = local_7c + -1;

      } while (local_7c != 0);

    }

  }

  local_4 = local_4 & 0xffffff00;

  if (local_58 != '\0') {

    FUN_00769e40();

  }

LAB_0095edbc:

  local_4 = 0xffffffff;

  if (local_18 != '\0') {

    FUN_00769e40();

  }

  ExceptionList = local_c;

  return uVar16;

}
