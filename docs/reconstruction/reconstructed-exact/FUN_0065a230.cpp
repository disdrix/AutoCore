// =============================================================================
// FUN_0065a230
// -----------------------------------------------------------------------------
// Stable ID: aa_0065a230
// Address:   0x0065a230  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0065a230 @ 0x0065a230
// Stable ID: aa_0065a230
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~339 non-empty decompiler lines.
//  - Control keywords: if×55, return×8, while×6, do×5, goto×5.
//  - Notable callees: FUN_00638180×10, FUN_005f3160×8, FUN_00638060×4, FUN_006380a0×4, FUN_006381a0×4, FUN_00659f60×3, FUN_005b3370×2, FUN_00659b50×2.
//  - Strings: "!--".
//  - Return sites: 8.

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

uint32_t /* width from decompiler */ __thiscall FUN_0065a230(int param_1,uint *param_2)



{

  int *piVar1;

  int *piVar2;

  char cVar3;

  char *pcVar4;

  int iVar5;

  int iVar6;

  uint32_t /* width from decompiler */ *puVar7;

  int iVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint uVar10;

  undefined *puVar11;

  uint8_t local_61;

  undefined *puStack_60;

  int local_5c;

  uint uStack_58;

  uint local_54;

  int local_50;

  uint local_4c;

  uint local_48;

  int iStack_44;

  int iStack_40;

  uint uStack_3c;

  int iStack_38;

  int iStack_34;

  int iStack_30;

  char local_2c;

  char acStack_2b [7];

  int *local_24 [9];

  

  local_54 = 0;

  local_5c = param_1;

  FUN_005f30d0(*(uint32_t /* width from decompiler */ *)(param_1 + 8));

  if (*(uint *)(param_1 + 0xc) != 0) {

    *param_2 = *(uint *)(param_1 + 0xc);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

    FUN_005f3160();

    return 0;

  }

  *param_2 = 0;

  pcVar4 = (char *)FUN_005f2d40(&local_61);

  if (*pcVar4 != '\0') {

    local_50 = 0;

    local_4c = 0;

    local_48 = 0x80000000;

    (**(code **)(*local_24[0] + 0x14))(0x20);

    iVar5 = (**(code **)(*local_24[0] + 8))(local_24,0x20);

    do {

      if (iVar5 == 0) {

        if (-1 < (int)local_54) {

          (**(code **)(*DAT_00b05060 + 0x14))(local_5c,local_54 & 0x7fffffff,0x12);

        }

        FUN_005f3160();

        return 1;

      }

      if (local_2c == '<') {

        if (iVar5 < 2) {

          if (-1 < (int)local_54) {

            (**(code **)(*DAT_00b05060 + 0x14))(local_5c,local_54 & 0x7fffffff,0x12);

          }

          FUN_005f3160();

          return 1;

        }

        if ((iVar5 < 4) || (iVar6 = strncmp("!--",acStack_2b,3), iVar6 != 0)) {

          if (uStack_58 == 0) {

            if (acStack_2b[0] != '?') {

              local_50 = 0;

              local_4c = 0;

              local_48 = 0x80000000;

              FUN_00659f60(iVar5,0x20,local_24[0],&local_50);

              if (local_4c == 0) {

                if (-1 < (int)local_48) {

                  (**(code **)(*DAT_00b05060 + 0x14))(local_50,local_48 & 0x7fffffff,0x12);

                }

                if (-1 < (int)local_54) {

                  (**(code **)(*DAT_00b05060 + 0x14))(local_5c,local_54 & 0x7fffffff,0x12);

                }

                FUN_005f3160();

                return 1;

              }

              if (local_4c == (local_48 & 0x7fffffff)) {

                FUN_005b3370(&local_50,1);

              }

              *(uint8_t *)(local_4c + local_50) = 0;

              local_4c = local_4c + 1;

              iVar5 = FUN_006599f0(local_50,local_50,1);

              if (iVar5 == -1) {

                if (-1 < (int)local_48) {

                  (**(code **)(*DAT_00b05060 + 0x14))(local_50,local_48 & 0x7fffffff,0x12);

                }

                if (-1 < (int)local_54) {

                  (**(code **)(*DAT_00b05060 + 0x14))(local_5c,local_54 & 0x7fffffff,0x12);

                }

                FUN_005f3160();

                return 1;

              }

              if (*(char *)(local_50 + 1) == '/') {

                iVar6 = local_50 + 2;

                local_4c = iVar5;

                if (iVar6 == 0) {

                  DAT_00d02c6c = DAT_00d02c6c + 1;

                  puVar11 = &DAT_00d02c70;

                }

                else {

                  iVar5 = FUN_00638060(iVar6);

                  iVar8 = FUN_006381a0(iVar5);

                  puVar11 = (undefined *)(iVar8 + 0xc);

                  FUN_006380a0(puVar11,iVar6,iVar5 + 1);

                }

                iVar5 = (**(code **)(*DAT_00b05060 + 0x10))(0x10,1);

                *(uint16_t *)(iVar5 + 4) = 0x10;

                uVar10 = FUN_00659b50(&puStack_60);

                *param_2 = uVar10;

                piVar1 = (int *)(puVar11 + -4);

                *piVar1 = *piVar1 + -1;

                if (*piVar1 < 0) {

                  FUN_00638180();

                }

                goto LAB_0065a9d5;

              }

              if (*(char *)(iVar5 + -1 + local_50) == '/') {

                iVar5 = iVar5 + -1;

              }

              iVar8 = 0;

              iVar6 = 0;

              if (iVar5 < 1) goto LAB_0065a6ac;

              goto LAB_0065a6a0;

            }

            FUN_00659f60(iVar5,0x20,local_24[0],0);

          }

          else {

            (**(code **)(*local_24[0] + 0x18))();

            uVar10 = 0;

            if (0 < (int)uStack_58) {

              do {

                cVar3 = *(char *)(uVar10 + local_5c);

                if ((((cVar3 != ' ') && (cVar3 != '\t')) && (cVar3 != '\n')) && (cVar3 != '\r'))

                break;

                uVar10 = uVar10 + 1;

              } while ((int)uVar10 < (int)uStack_58);

            }

            if (uVar10 != uStack_58) {

              if (uStack_58 == (local_54 & 0x7fffffff)) {

                FUN_005b3370(&local_5c,1);

              }

              *(uint8_t *)(uStack_58 + local_5c) = 0;

              uStack_58 = uStack_58 + 1;

              puVar7 = (uint32_t /* width from decompiler */ *)(**(code **)(*DAT_00b05060 + 0x10))(0x10,1);

              iVar5 = local_50;

              *(uint16_t *)(puVar7 + 1) = 0x10;

              if (local_50 == 0) {

                DAT_00d02c6c = DAT_00d02c6c + 1;

                puVar11 = &DAT_00d02c70;

              }

              else {

                iVar6 = FUN_00638060(local_50);

                iVar8 = FUN_006381a0(iVar6);

                puVar11 = (undefined *)(iVar8 + 0xc);

                FUN_006380a0(puVar11,iVar5,iVar6 + 1);

              }

              puVar7[2] = 3;

              *puVar7 = &PTR_FUN_009e5ed4;

              *(int *)(puVar11 + -4) = *(int *)(puVar11 + -4) + 1;

              puVar7[3] = puVar11;

              *param_2 = (uint)puVar7;

              piVar1 = (int *)(puVar11 + -4);

              *piVar1 = *piVar1 + -1;

              if (*piVar1 < 0) {

                FUN_00638180();

              }

              goto LAB_0065a9f5;

            }

            uStack_58 = 0;

          }

        }

        else {

          FUN_00659f60(iVar5,0x20,local_24[0],0);

        }

      }

      else {

        FUN_0065a000(&local_2c,0x20,local_24[0],&local_5c);

      }

      (**(code **)(*local_24[0] + 0x14))(0x20);

      iVar5 = (**(code **)(*local_24[0] + 8))(&iStack_30,0x20);

    } while( true );

  }

LAB_0065a8d6:

  FUN_005f3160();

  return 1;

  while (iVar6 = iVar6 + 1, iVar6 < iVar5) {

LAB_0065a6a0:

    if (*(char *)(iVar6 + local_50) == ' ') break;

  }

LAB_0065a6ac:

  iStack_44 = 0;

  iStack_40 = 0;

  uStack_3c = 0x80000000;

  local_4c = iVar5;

  if (iVar6 != iVar5) {

    iVar5 = FUN_00659d90(&iStack_44);

    if (iVar5 == 1) {

      if (0 < iStack_40) {

        do {

          piVar2 = (int *)(iStack_44 + iVar8 * 8);

          piVar1 = (int *)(*(int *)(iStack_44 + 4 + iVar8 * 8) + -4);

          *piVar1 = *piVar1 + -1;

          if (*piVar1 < 0) {

            FUN_00638180();

          }

          piVar1 = (int *)(*piVar2 + -4);

          *piVar1 = *piVar1 + -1;

          if (*piVar1 < 0) {

            FUN_00638180();

          }

          iVar8 = iVar8 + 1;

        } while (iVar8 < iStack_40);

      }

      if (-1 < (int)uStack_3c) {

        (**(code **)(*DAT_00b05060 + 0x14))(iStack_44,uStack_3c * 8,0x12);

      }

      if (-1 < (int)local_48) {

        (**(code **)(*DAT_00b05060 + 0x14))(local_50,local_48 & 0x7fffffff,0x12);

      }

      if (-1 < (int)local_54) {

        (**(code **)(*DAT_00b05060 + 0x14))(local_5c,local_54 & 0x7fffffff,0x12);

      }

      FUN_005f3160();

      return 1;

    }

    *(uint8_t *)(iVar6 + local_50) = 0;

    local_4c = iVar6;

  }

  iVar5 = (**(code **)(*DAT_00b05060 + 0x10))(0x1c,1);

  *(uint16_t *)(iVar5 + 4) = 0x1c;

  iVar5 = iStack_44 + 1;

  if (iVar5 == 0) {

    DAT_00d02c6c = DAT_00d02c6c + 1;

    puVar11 = &DAT_00d02c70;

    puStack_60 = &DAT_00d02c70;

  }

  else {

    iVar6 = FUN_00638060(iVar5);

    iVar8 = FUN_006381a0(iVar6);

    puVar11 = (undefined *)(iVar8 + 0xc);

    puStack_60 = puVar11;

    FUN_006380a0(puVar11,iVar5,iVar6 + 1);

  }

  local_54 = FUN_0065a100(&puStack_60);

  piVar1 = (int *)(puVar11 + -4);

  *piVar1 = *piVar1 + -1;

  if (*piVar1 < 0) {

    FUN_00638180();

  }

  FUN_00659c10(&iStack_38);

  if ((char)uStack_58 != '\0') {

    if (*(int *)(local_5c + 0xc) != 0) {

      iVar5 = 0;

      if (0 < iStack_34) {

        do {

          piVar2 = (int *)(iStack_38 + iVar5 * 8);

          piVar1 = (int *)(*(int *)(iStack_38 + 4 + iVar5 * 8) + -4);

          *piVar1 = *piVar1 + -1;

          if (*piVar1 < 0) {

            FUN_00638180();

          }

          piVar1 = (int *)(*piVar2 + -4);

          *piVar1 = *piVar1 + -1;

          if (*piVar1 < 0) {

            FUN_00638180();

          }

          iVar5 = iVar5 + 1;

        } while (iVar5 < iStack_34);

      }

      if (-1 < iStack_30) {

        (**(code **)(*DAT_00b05060 + 0x14))(iStack_38,iStack_30 * 8,0x12);

      }

      if (-1 < (int)uStack_3c) {

        (**(code **)(*DAT_00b05060 + 0x14))(iStack_44,uStack_3c & 0x7fffffff,0x12);

      }

      if (-1 < (int)local_48) {

        (**(code **)(*DAT_00b05060 + 0x14))(local_50,local_48 & 0x7fffffff,0x12);

      }

      goto LAB_0065a8d6;

    }

    iVar6 = (**(code **)(*DAT_00b05060 + 0x10))(0x10,1);

    iVar5 = iStack_44;

    *(uint16_t *)(iVar6 + 4) = 0x10;

    if (iStack_44 == 0) {

      DAT_00d02c6c = DAT_00d02c6c + 1;

      puVar11 = &DAT_00d02c70;

      puStack_60 = &DAT_00d02c70;

    }

    else {

      iVar6 = FUN_00638060(iStack_44);

      iVar8 = FUN_006381a0(iVar6);

      puVar11 = (undefined *)(iVar8 + 0xc);

      puStack_60 = puVar11;

      FUN_006380a0(puVar11,iVar5,iVar6 + 1);

    }

    uVar9 = FUN_00659b50(&puStack_60);

    *(uint32_t /* width from decompiler */ *)(local_5c + 0xc) = uVar9;

    piVar1 = (int *)(puVar11 + -4);

    *piVar1 = *piVar1 + -1;

    if (*piVar1 < 0) {

      FUN_00638180();

    }

  }

  iVar5 = 0;

  *param_2 = local_54;

  if (0 < iStack_34) {

    do {

      piVar2 = (int *)(iStack_38 + iVar5 * 8);

      piVar1 = (int *)(piVar2[1] + -4);

      *piVar1 = *piVar1 + -1;

      if (*piVar1 < 0) {

        FUN_00638180();

      }

      piVar1 = (int *)(*piVar2 + -4);

      *piVar1 = *piVar1 + -1;

      if (*piVar1 < 0) {

        FUN_00638180();

      }

      iVar5 = iVar5 + 1;

    } while (iVar5 < iStack_34);

  }

  if (-1 < iStack_30) {

    (**(code **)(*DAT_00b05060 + 0x14))(iStack_38,iStack_30 * 8,0x12);

  }

LAB_0065a9d5:

  if (-1 < (int)uStack_3c) {

    (**(code **)(*DAT_00b05060 + 0x14))(iStack_44,uStack_3c & 0x7fffffff,0x12);

  }

LAB_0065a9f5:

  if (-1 < (int)local_48) {

    (**(code **)(*DAT_00b05060 + 0x14))(local_50,local_48 & 0x7fffffff,0x12);

  }

  FUN_005f3160();

  return 0;

}
