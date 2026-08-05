// READABILITY (auto CF):
//  - Body size: ~420 non-empty decompiler lines.
//  - Control keywords: if×62, while×19, do×12, goto×9, for×4, return×1.
//  - Notable callees: FUN_00423f40×8, FUN_007a4480×8, FUN_004294f0×5, LeaveCriticalSection×5, __RTDynamicCast×4, isalpha×4, FUN_0041c7e0×3, FUN_00424060×2.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 1.

// =============================================================================
// Named_VOG_DEBUG_STOP_0078a6a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0078a6a0
// Address:   0x0078a6a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_VOG_DEBUG_STOP_0078a6a0(int param_1,char param_2,int param_3,char param_4,char param_5)



{

  char *pcVar1;

  byte bVar2;

  char cVar3;

  int *piVar4;

  int *piVar5;

  int *piVar6;

  int iVar7;

  byte *pbVar8;

  char *pcVar9;

  int iVar10;

  int iVar11;

  int iVar12;

  byte *pbVar13;

  bool bVar14;

  int *local_54;

  int *local_50;

  uint32_t /* width from decompiler */ local_4c;

  int local_48;

  int local_44;

  int local_40;

  int local_3c;

  undefined **local_38;

  _RTL_CRITICAL_SECTION local_34;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  int local_14;

  char local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b0003;

  local_c = ExceptionList;

  if ((param_2 != '\0') || ((param_3 < 3 && (-1 < param_3)))) {

    ExceptionList = &local_c;

    *(uint8_t *)(param_1 + 0x566) = 1;

    *(char *)(param_1 + 0x567) = param_4;

    local_38 = &PTR_FUN_00a9a3fc;

    local_18 = 0;

    local_1c = 0;

    local_14 = 0;

    local_10 = '\0';

    local_48 = param_1;

    InitializeCriticalSection(&local_34);

    local_38 = &PTR_FUN_00a9a408;

    local_44 = param_1 + 0x50c;

    local_4 = 0;

    local_4c = 0;

    FUN_004294f0();

    iVar7 = FUN_00423f40(&local_54);

    while (iVar7 == 0) {

      FUN_0041c7e0(&local_38,local_54);

      iVar7 = FUN_00423f40(&local_54);

    }

    if (*(char *)(param_1 + 0x534) != '\0') {

      *(uint8_t *)(param_1 + 0x534) = 0;

      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x510));

    }

    FUN_00427f10();

    local_4c = 0;

    while (local_14 != 0) {

      local_50 = (int *)0x0;

      FUN_004294f0();

      iVar7 = FUN_00423f40(&local_54);

      piVar4 = (int *)0x0;

      while (iVar7 == 0) {

        piVar6 = local_54;

        if (piVar4 != (int *)0x0) {

          piVar6 = local_50;

          if (param_4 == '\0') {

            if (param_2 == '\0') {

              if (local_54[param_3 + 8] < piVar4[param_3 + 8]) {

LAB_0078aa71:

                piVar6 = local_54;

              }

            }

            else {

              pbVar8 = (byte *)piVar4[2];

              if (param_5 == '\0') {

                pbVar13 = (byte *)local_54[2];

                do {

                  bVar2 = *pbVar8;

                  bVar14 = bVar2 < *pbVar13;

                  if (bVar2 != *pbVar13) {

LAB_0078a905:

                    iVar7 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);

                    goto LAB_0078a90a;

                  }

                  if (bVar2 == 0) break;

                  bVar2 = pbVar8[1];

                  bVar14 = bVar2 < pbVar13[1];

                  if (bVar2 != pbVar13[1]) goto LAB_0078a905;

                  pbVar8 = pbVar8 + 2;

                  pbVar13 = pbVar13 + 2;

                } while (bVar2 != 0);

                iVar7 = 0;

LAB_0078a90a:

                if (0 < iVar7) {

                  piVar6 = local_54;

                }

              }

              else {

                local_3c = 0;

                local_40 = 0;

                if (pbVar8 != (byte *)0x0) {

                  pbVar13 = pbVar8 + 1;

                  do {

                    bVar2 = *pbVar8;

                    pbVar8 = pbVar8 + 1;

                  } while (bVar2 != 0);

                  iVar7 = (int)pbVar8 - (int)pbVar13;

                  iVar11 = 0;

                  if (0 < iVar7) {

                    do {

                      iVar10 = isalpha((int)*(char *)(piVar4[2] + iVar11));

                      if (iVar10 != 0) {

                        if (iVar11 < iVar7) {

                          local_3c = iVar11;

                        }

                        break;

                      }

                      iVar11 = iVar11 + 1;

                    } while (iVar11 < iVar7);

                  }

                }

                piVar5 = local_54;

                pcVar9 = (char *)local_54[2];

                if (pcVar9 != (char *)0x0) {

                  pcVar1 = pcVar9 + 1;

                  do {

                    cVar3 = *pcVar9;

                    pcVar9 = pcVar9 + 1;

                  } while (cVar3 != '\0');

                  iVar7 = (int)pcVar9 - (int)pcVar1;

                  iVar11 = 0;

                  if (0 < iVar7) {

                    do {

                      iVar10 = isalpha((int)*(char *)(piVar5[2] + iVar11));

                      if (iVar10 != 0) {

                        if (iVar11 < iVar7) {

                          local_40 = iVar11;

                        }

                        break;

                      }

                      iVar11 = iVar11 + 1;

                    } while (iVar11 < iVar7);

                  }

                }

                pbVar13 = (byte *)(piVar5[2] + local_40);

                pbVar8 = (byte *)(piVar4[2] + local_3c);

                do {

                  bVar2 = *pbVar8;

                  bVar14 = bVar2 < *pbVar13;

                  if (bVar2 != *pbVar13) {

LAB_0078a8c4:

                    iVar7 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);

                    goto LAB_0078a8c9;

                  }

                  if (bVar2 == 0) break;

                  bVar2 = pbVar8[1];

                  bVar14 = bVar2 < pbVar13[1];

                  if (bVar2 != pbVar13[1]) goto LAB_0078a8c4;

                  pbVar8 = pbVar8 + 2;

                  pbVar13 = pbVar13 + 2;

                } while (bVar2 != 0);

                iVar7 = 0;

LAB_0078a8c9:

                piVar6 = local_50;

                if (0 < iVar7) {

                  local_50 = piVar5;

                  piVar6 = local_50;

                }

              }

            }

          }

          else if (param_2 == '\0') {

            if (piVar4[param_3 + 8] < local_54[param_3 + 8]) goto LAB_0078aa71;

          }

          else if (param_5 == '\0') {

            pbVar8 = (byte *)local_54[2];

            pbVar13 = (byte *)piVar4[2];

            do {

              bVar2 = *pbVar13;

              bVar14 = bVar2 < *pbVar8;

              if (bVar2 != *pbVar8) {

LAB_0078aa54:

                iVar7 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);

                goto LAB_0078aa59;

              }

              if (bVar2 == 0) break;

              bVar2 = pbVar13[1];

              bVar14 = bVar2 < pbVar8[1];

              if (bVar2 != pbVar8[1]) goto LAB_0078aa54;

              pbVar13 = pbVar13 + 2;

              pbVar8 = pbVar8 + 2;

            } while (bVar2 != 0);

            iVar7 = 0;

LAB_0078aa59:

            if (iVar7 < 0) {

              piVar6 = local_54;

            }

          }

          else {

            pcVar9 = (char *)local_50[2];

            iVar11 = 0;

            iVar7 = 0;

            local_3c = 0;

            if (pcVar9 != (char *)0x0) {

              pcVar1 = pcVar9 + 1;

              do {

                cVar3 = *pcVar9;

                pcVar9 = pcVar9 + 1;

              } while (cVar3 != '\0');

              iVar10 = (int)pcVar9 - (int)pcVar1;

              if (0 < iVar10) {

                do {

                  iVar12 = isalpha((int)*(char *)(local_50[2] + iVar11));

                  if (iVar12 != 0) {

                    if (iVar11 < iVar10) {

                      local_3c = iVar11;

                    }

                    break;

                  }

                  iVar11 = iVar11 + 1;

                } while (iVar11 < iVar10);

              }

            }

            piVar4 = local_54;

            pcVar9 = (char *)local_54[2];

            if (pcVar9 != (char *)0x0) {

              pcVar1 = pcVar9 + 1;

              do {

                cVar3 = *pcVar9;

                pcVar9 = pcVar9 + 1;

              } while (cVar3 != '\0');

              iVar11 = (int)pcVar9 - (int)pcVar1;

              iVar10 = 0;

              if (0 < iVar11) {

                do {

                  iVar12 = isalpha((int)*(char *)(piVar4[2] + iVar10));

                  if (iVar12 != 0) {

                    if (iVar10 < iVar11) {

                      iVar7 = iVar10;

                    }

                    break;

                  }

                  iVar10 = iVar10 + 1;

                } while (iVar10 < iVar11);

              }

            }

            pbVar13 = (byte *)(piVar4[2] + iVar7);

            pbVar8 = (byte *)(local_50[2] + local_3c);

            do {

              bVar2 = *pbVar8;

              bVar14 = bVar2 < *pbVar13;

              if (bVar2 != *pbVar13) {

LAB_0078aa14:

                iVar7 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);

                goto LAB_0078aa19;

              }

              if (bVar2 == 0) break;

              bVar2 = pbVar8[1];

              bVar14 = bVar2 < pbVar13[1];

              if (bVar2 != pbVar13[1]) goto LAB_0078aa14;

              pbVar8 = pbVar8 + 2;

              pbVar13 = pbVar13 + 2;

            } while (bVar2 != 0);

            iVar7 = 0;

LAB_0078aa19:

            piVar6 = local_50;

            if (iVar7 < 0) {

              local_50 = piVar4;

              piVar6 = local_50;

            }

          }

        }

        local_50 = piVar6;

        iVar7 = FUN_00423f40(&local_54);

        piVar4 = local_50;

      }

      if (local_10 != '\0') {

        local_10 = '\0';

        LeaveCriticalSection(&local_34);

      }

      if (piVar4 != (int *)0x0) {

        FUN_0041c7e0(local_44,piVar4);

        FUN_00424260();

      }

      if ((((-1 < *(int *)(local_48 + 0x9a0)) && (*(int *)(local_48 + 0x2b0) != 0)) &&

          (local_40 = __RTDynamicCast(*(int *)(local_48 + 0x2b0),0,

                                      &CNDUIWindow::RTTI_Type_Descriptor,

                                      &CNDUIDialog::RTTI_Type_Descriptor,0), local_40 != 0)) &&

         (iVar7 = *(int *)(local_40 + 0x4c0), iVar7 != 0)) {

        iVar11 = 0;

        if (*(char *)(iVar7 + 0x1d) != '\0') {

          FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

          FUN_007a4480(0,"VOG_DEBUG_STOP");

        }

        *(uint8_t *)(iVar7 + 0x1d) = 1;

        while( true ) {

          iVar10 = local_40;

          iVar7 = *(int *)(local_40 + 0x4c0);

          if (*(char *)(iVar7 + 0x1d) == '\0') {

            FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

            FUN_007a4480(0,"VOG_DEBUG_STOP");

          }

          if (iVar11 == 0) {

            iVar11 = *(int *)(iVar7 + 0x14);

          }

          else {

            iVar11 = *(int *)(iVar11 + 0x14);

          }

          if (iVar11 == 0) {

            iVar7 = 0;

          }

          else {

            iVar7 = *(int *)(iVar11 + 8);

          }

          if (iVar7 == 0) break;

          iVar7 = __RTDynamicCast(iVar7,0,&CNDUIWindow::RTTI_Type_Descriptor,

                                  &CNDUICtrlListBox::RTTI_Type_Descriptor,0);

          if (((iVar7 != 0) && (*(int *)(iVar7 + 0x9a0) == *(int *)(local_48 + 0x9a0))) &&

             (iVar7 != local_48)) {

            local_3c = 0;

            local_50 = (int *)0x0;

            FUN_004294f0();

            iVar10 = FUN_00423f40(&local_50);

            piVar6 = local_50;

            while ((iVar10 == 0 && ((*piVar6 != *piVar4 || (piVar6[1] != piVar4[1]))))) {

              local_50 = (int *)0x0;

              iVar10 = FUN_00423f40(&local_50);

              piVar6 = local_50;

            }

            local_50 = piVar6;

            if (*(char *)(iVar7 + 0x534) != '\0') {

              *(uint8_t *)(iVar7 + 0x534) = 0;

              LeaveCriticalSection((LPCRITICAL_SECTION)(iVar7 + 0x510));

            }

            if (piVar6 != (int *)0x0) {

              FUN_00424260();

              FUN_0041c7e0(iVar7 + 0x50c,piVar6);

            }

          }

        }

        *(uint8_t *)(*(int *)(iVar10 + 0x4c0) + 0x1d) = 0;

      }

    }

    iVar7 = -*(int *)(local_48 + 0x568);

    local_4c = 0;

    FUN_004294f0();

    iVar10 = FUN_00423f40(&local_54);

    piVar4 = local_54;

    iVar11 = local_48;

    while (local_48 = iVar11, iVar10 == 0) {

      local_54 = piVar4;

      FUN_00789ad0(iVar11,*piVar4,piVar4[1],iVar7);

      if ((((-1 < *(int *)(iVar11 + 0x9a0)) && (*(int *)(iVar11 + 0x2b0) != 0)) &&

          (iVar11 = __RTDynamicCast(*(int *)(iVar11 + 0x2b0),0,&CNDUIWindow::RTTI_Type_Descriptor,

                                    &CNDUIDialog::RTTI_Type_Descriptor,0), iVar11 != 0)) &&

         (iVar10 = *(int *)(iVar11 + 0x4c0), iVar10 != 0)) {

        iVar12 = 0;

        if (*(char *)(iVar10 + 0x1d) != '\0') {

          FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

          FUN_007a4480(0,"VOG_DEBUG_STOP");

        }

        *(uint8_t *)(iVar10 + 0x1d) = 1;

        while( true ) {

          iVar10 = *(int *)(iVar11 + 0x4c0);

          if (*(char *)(iVar10 + 0x1d) == '\0') {

            FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

            FUN_007a4480(0,"VOG_DEBUG_STOP");

          }

          if (iVar12 == 0) {

            iVar12 = *(int *)(iVar10 + 0x14);

          }

          else {

            iVar12 = *(int *)(iVar12 + 0x14);

          }

          if (iVar12 == 0) {

            iVar10 = 0;

          }

          else {

            iVar10 = *(int *)(iVar12 + 8);

          }

          if (iVar10 == 0) break;

          iVar10 = __RTDynamicCast(iVar10,0,&CNDUIWindow::RTTI_Type_Descriptor,

                                   &CNDUICtrlListBox::RTTI_Type_Descriptor,0);

          if (((iVar10 != 0) && (*(int *)(iVar10 + 0x9a0) == *(int *)(local_48 + 0x9a0))) &&

             (iVar10 != local_48)) {

            FUN_004294f0();

            FUN_00789ad0(iVar10,*piVar4,piVar4[1],iVar7);

            if (*(char *)(iVar10 + 0x534) != '\0') {

              *(uint8_t *)(iVar10 + 0x534) = 0;

              LeaveCriticalSection((LPCRITICAL_SECTION)(iVar10 + 0x510));

            }

            *(uint8_t *)(iVar10 + 0x566) = 0;

          }

        }

        *(uint8_t *)(*(int *)(iVar11 + 0x4c0) + 0x1d) = 0;

      }

      iVar7 = iVar7 + 1;

      iVar10 = FUN_00423f40(&local_54);

      piVar4 = local_54;

      iVar11 = local_48;

    }

    if (*(char *)(local_44 + 0x28) != '\0') {

      *(uint8_t *)(local_44 + 0x28) = 0;

      LeaveCriticalSection((LPCRITICAL_SECTION)(local_44 + 4));

    }

    local_38 = &PTR_FUN_00a9a408;

    FUN_00424060();

    local_38 = &PTR_FUN_00a9a3fc;

    FUN_00424060();

    DeleteCriticalSection(&local_34);

  }

  ExceptionList = local_c;

  return;

}
