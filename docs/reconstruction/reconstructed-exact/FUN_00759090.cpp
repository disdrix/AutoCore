// =============================================================================
// FUN_00759090
// -----------------------------------------------------------------------------
// Stable ID: aa_00759090
// Address:   0x00759090  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00759090 @ 0x00759090
// Stable ID: aa_00759090
// Embedded strings (evidence for future rename):
//   - "UIMap0"
//   - "AlphaRef"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~377 non-empty decompiler lines.
//  - Control keywords: if×60, while×8, do×3, goto×2, return×1.
//  - Notable callees: FUN_00442760×3, FUN_00442640×2, FUN_0073df30×2, FUN_007528f0×2, FUN_0076c3c0×2, FUN_00440110, FUN_00440380, FUN_00440d20.
//  - Strings: "UIMap0"; "AlphaRef".
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

uint32_t /* width from decompiler */ __fastcall FUN_00759090(int param_1)



{

  int *piVar1;

  char cVar2;

  int *piVar3;

  bool bVar4;

  int iVar5;

  int *piVar6;

  int extraout_ECX;

  int iVar7;

  int iVar8;

  int extraout_ECX_00;

  int *piVar9;

  int iVar10;

  int *piVar11;

  int *piVar12;

  int *local_2c;

  int iStack_24;

  int iStack_20;

  int iStack_1c;

  int local_18;

  int local_14;

  uint32_t /* width from decompiler */ local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b2499;

  pvStack_c = ExceptionList;

  local_10 = *(uint32_t /* width from decompiler */ *)(DAT_00d1f614 + 0xc4);

  local_14 = DAT_00d1f614;

  ExceptionList = &pvStack_c;

  if (*(char *)(DAT_00d1f614 + 200) == '\0') {

    ExceptionList = &pvStack_c;

    iVar5 = FUN_0076c3c0();

    piVar9 = (int *)(extraout_ECX + 0x34 + *(int *)(extraout_ECX + 0xc4) * 4);

    *piVar9 = *piVar9 + (iVar5 - *(int *)(extraout_ECX + 0x30));

    *(int *)(extraout_ECX + 0x30) = iVar5;

    *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0xc4) = 1;

  }

  local_4 = 0;

  FUN_00440380();

  FUN_00440d20(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xa8) + 4));

  *(int *)(*(int *)(param_1 + 0xa8) + 4) = *(int *)(param_1 + 0xa8);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xac) = 0;

  *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(param_1 + 0xa8) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xa8);

  *(int *)(*(int *)(param_1 + 0xa8) + 8) = *(int *)(param_1 + 0xa8);

  piVar9 = *(int **)(param_1 + 8);

  piVar3 = (int *)*piVar9;

  while (piVar3 != piVar9) {

    piVar6 = (int *)piVar3[3];

    piVar9 = piVar3 + 9;

    if ((piVar6 != (int *)0x0) && (piVar6[1] = piVar6[1] + 1, piVar6[1] == 1)) {

      (**(code **)(*piVar6 + 4))();

    }

    piVar12 = (int *)*piVar9;

    if (piVar12 != (int *)0x0) {

      piVar11 = piVar12 + 1;

      *piVar11 = *piVar11 + -1;

      if (*piVar11 == 0) {

        (**(code **)(*piVar12 + 8))();

      }

    }

    *piVar9 = (int)piVar6;

    *(uint8_t *)(piVar3 + 10) = *(uint8_t *)(piVar3 + 4);

    *(uint8_t *)((int)piVar3 + 0x29) = *(uint8_t *)((int)piVar3 + 0x11);

    *(uint8_t *)((int)piVar3 + 0x2a) = *(uint8_t *)((int)piVar3 + 0x12);

    if (piVar6 == (int *)0x0) {

      iStack_24 = -1;

      piVar6 = &iStack_24;

    }

    else {

      piVar6 = (int *)FUN_00752310(&local_18,"UIMap0");

    }

    iVar5 = *piVar6;

    iStack_20 = iVar5;

    if (-1 < iVar5) {

      iVar10 = *piVar9;

      iStack_1c = piVar3[5];

      if (((iVar10 == 0) || (*(int *)(iVar10 + 4) < 2)) ||

         (piVar6 = (int *)FUN_0073df30(DAT_00d1f61c,iVar10), piVar6 == (int *)0x0)) {

        bVar4 = false;

      }

      else {

        piVar12 = (int *)*piVar9;

        piVar11 = (int *)piVar12[6];

        if ((((int *)piVar12[6] != (int *)0x0) || (piVar11 = piVar12, piVar12 != (int *)0x0)) &&

           (piVar11[1] = piVar11[1] + 1, piVar11[1] == 1)) {

          (**(code **)(*piVar11 + 4))();

        }

        piVar12 = (int *)piVar6[6];

        if (piVar12 != (int *)0x0) {

          piVar1 = piVar12 + 1;

          *piVar1 = *piVar1 + -1;

          if (*piVar1 == 0) {

            (**(code **)(*piVar12 + 8))();

          }

        }

        piVar6[6] = (int)piVar11;

        piVar6[1] = piVar6[1] + 1;

        if (piVar6[1] == 1) {

          (**(code **)(*piVar6 + 4))();

        }

        piVar12 = (int *)*piVar9;

        if (piVar12 != (int *)0x0) {

          piVar11 = piVar12 + 1;

          *piVar11 = *piVar11 + -1;

          if (*piVar11 == 0) {

            (**(code **)(*piVar12 + 8))();

          }

        }

        *piVar9 = (int)piVar6;

        bVar4 = true;

        iVar5 = iStack_20;

      }

      iVar5 = FUN_007528f0(iVar5,iStack_1c);

      if (((iVar5 == -1) && (bVar4)) && (iVar5 = *piVar9, iVar5 != 0)) {

        iVar10 = *(int *)(iVar5 + 0x18);

        if (*(int *)(iVar5 + 0x18) == 0) {

          iVar10 = iVar5;

        }

        if (iVar10 != iVar5) {

          FUN_00448fc0(iVar10);

        }

      }

    }

    FUN_00442640("AlphaRef",piVar3 + 6);

    iVar5 = 0;

    if (*(int *)(param_1 + 0x3c) != 0) {

      iVar5 = (*(int *)(param_1 + 0x40) - *(int *)(param_1 + 0x3c)) / 0x18;

    }

    piVar3[7] = iVar5;

    FUN_00442760(*(uint32_t /* width from decompiler */ *)(param_1 + 0x40),piVar3[0xc],piVar3[0xd],local_18);

    FUN_00441a80();

    piVar9 = *(int **)(param_1 + 8);

  }

  if (*(int *)(param_1 + 0x20) != 0) {

    local_18 = (*(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x20)) / 0x18;

    if (local_18 != 0) {

      iVar5 = 0;

      if (*(int *)(param_1 + 0x3c) != 0) {

        iVar5 = (*(int *)(param_1 + 0x40) - *(int *)(param_1 + 0x3c)) / 0x18;

      }

      *(int *)(param_1 + 0x2c) = iVar5;

      FUN_00442760(*(uint32_t /* width from decompiler */ *)(param_1 + 0x40),*(uint32_t /* width from decompiler */ *)(param_1 + 0x20),

                   *(uint32_t /* width from decompiler */ *)(param_1 + 0x24),local_18);

    }

  }

  local_2c = (int *)**(int **)(param_1 + 0x14);

  if (local_2c != *(int **)(param_1 + 0x14)) {

    do {

      piVar9 = *(int **)local_2c[5];

      if (piVar9 != (int *)local_2c[5]) {

        do {

          piVar6 = (int *)piVar9[3];

          piVar3 = piVar9 + 9;

          if ((piVar6 != (int *)0x0) && (piVar6[1] = piVar6[1] + 1, piVar6[1] == 1)) {

            (**(code **)(*piVar6 + 4))();

          }

          piVar12 = (int *)*piVar3;

          if (piVar12 != (int *)0x0) {

            piVar11 = piVar12 + 1;

            *piVar11 = *piVar11 + -1;

            if (*piVar11 == 0) {

              (**(code **)(*piVar12 + 8))();

            }

          }

          *piVar3 = (int)piVar6;

          *(char *)(piVar9 + 10) = (char)piVar9[4];

          *(uint8_t *)((int)piVar9 + 0x29) = *(uint8_t *)((int)piVar9 + 0x11);

          *(uint8_t *)((int)piVar9 + 0x2a) = *(uint8_t *)((int)piVar9 + 0x12);

          if (piVar6 == (int *)0x0) {

            iStack_20 = -1;

            piVar6 = &iStack_20;

          }

          else {

            iVar5 = piVar6[2];

            iVar10 = -1;

            if (((iVar5 != 0) && (*(int *)(iVar5 + 0xc) != 0)) &&

               (iVar5 = (**(code **)(**(int **)(iVar5 + 0xc) + 0x28))

                                  (*(int **)(iVar5 + 0xc),0,"UIMap0"), iVar5 != 0)) {

              iVar8 = *(int *)(piVar6[2] + 0x18);

              iVar7 = 0;

              if (0 < iVar8) {

                do {

                  iVar10 = iVar7;

                  if (*(int *)(*(int *)(piVar6[2] + 0x10) + iVar7 * 8) == iVar5) goto LAB_00759408;

                  iVar7 = iVar7 + 1;

                } while (iVar7 < iVar8);

                iStack_1c = -1;

                piVar6 = &iStack_1c;

                goto LAB_0075941e;

              }

            }

LAB_00759408:

            iStack_1c = iVar10;

            piVar6 = &iStack_1c;

          }

LAB_0075941e:

          iVar5 = *piVar6;

          iStack_24 = iVar5;

          if (-1 < iVar5) {

            iVar10 = *piVar3;

            local_18 = piVar9[5];

            if (((iVar10 == 0) || (*(int *)(iVar10 + 4) < 2)) ||

               (piVar6 = (int *)FUN_0073df30(DAT_00d1f61c,iVar10), piVar6 == (int *)0x0)) {

              bVar4 = false;

            }

            else {

              piVar12 = (int *)*piVar3;

              piVar11 = (int *)piVar12[6];

              if ((((int *)piVar12[6] != (int *)0x0) || (piVar11 = piVar12, piVar12 != (int *)0x0))

                 && (piVar11[1] = piVar11[1] + 1, piVar11[1] == 1)) {

                (**(code **)(*piVar11 + 4))();

              }

              piVar12 = (int *)piVar6[6];

              if (piVar12 != (int *)0x0) {

                piVar1 = piVar12 + 1;

                *piVar1 = *piVar1 + -1;

                if (*piVar1 == 0) {

                  (**(code **)(*piVar12 + 8))();

                }

              }

              piVar6[6] = (int)piVar11;

              piVar6[1] = piVar6[1] + 1;

              if (piVar6[1] == 1) {

                (**(code **)(*piVar6 + 4))();

              }

              piVar12 = (int *)*piVar3;

              if (piVar12 != (int *)0x0) {

                piVar11 = piVar12 + 1;

                *piVar11 = *piVar11 + -1;

                if (*piVar11 == 0) {

                  (**(code **)(*piVar12 + 8))();

                }

              }

              *piVar3 = (int)piVar6;

              bVar4 = true;

              iVar5 = iStack_24;

            }

            iVar5 = FUN_007528f0(iVar5,local_18);

            if (((iVar5 == -1) && (bVar4)) && (piVar6 = (int *)*piVar3, piVar6 != (int *)0x0)) {

              piVar12 = (int *)piVar6[6];

              if ((int *)piVar6[6] == (int *)0x0) {

                piVar12 = piVar6;

              }

              if (piVar12 != piVar6) {

                if ((piVar12 != (int *)0x0) && (piVar12[1] = piVar12[1] + 1, piVar12[1] == 1)) {

                  (**(code **)(*piVar12 + 4))();

                }

                piVar6 = (int *)*piVar3;

                if (piVar6 != (int *)0x0) {

                  piVar11 = piVar6 + 1;

                  *piVar11 = *piVar11 + -1;

                  if (*piVar11 == 0) {

                    (**(code **)(*piVar6 + 8))();

                  }

                }

                *piVar3 = (int)piVar12;

              }

            }

          }

          FUN_00442640("AlphaRef",piVar9 + 6);

          piVar6 = (int *)FUN_0073d940(*piVar3);

          if (piVar6 != (int *)0x0) {

            piVar6[1] = piVar6[1] + 1;

            if (piVar6[1] == 1) {

              (**(code **)(*piVar6 + 4))();

            }

            piVar12 = (int *)*piVar3;

            if (piVar12 != (int *)0x0) {

              piVar11 = piVar12 + 1;

              *piVar11 = *piVar11 + -1;

              if (*piVar11 == 0) {

                (**(code **)(*piVar12 + 8))();

              }

            }

            *piVar3 = (int)piVar6;

          }

          iVar5 = 0;

          if (*(int *)(param_1 + 0x3c) != 0) {

            iVar5 = (*(int *)(param_1 + 0x40) - *(int *)(param_1 + 0x3c)) / 0x18;

          }

          piVar9[7] = iVar5;

          FUN_00442760(*(uint32_t /* width from decompiler */ *)(param_1 + 0x40),piVar9[0xc],piVar9[0xd],local_18);

          if (*(char *)((int)piVar9 + 0x3d) == '\0') {

            piVar3 = (int *)piVar9[2];

            if (*(char *)((int)piVar3 + 0x3d) == '\0') {

              cVar2 = *(char *)(*piVar3 + 0x3d);

              piVar9 = piVar3;

              piVar3 = (int *)*piVar3;

              while (cVar2 == '\0') {

                cVar2 = *(char *)(*piVar3 + 0x3d);

                piVar9 = piVar3;

                piVar3 = (int *)*piVar3;

              }

            }

            else {

              cVar2 = *(char *)(piVar9[1] + 0x3d);

              piVar6 = (int *)piVar9[1];

              piVar3 = piVar9;

              while ((piVar9 = piVar6, cVar2 == '\0' && (piVar3 == (int *)piVar9[2]))) {

                cVar2 = *(char *)(piVar9[1] + 0x3d);

                piVar6 = (int *)piVar9[1];

                piVar3 = piVar9;

              }

            }

          }

        } while (piVar9 != (int *)local_2c[5]);

      }

      if (*(char *)((int)local_2c + 0x1d) == '\0') {

        piVar9 = (int *)local_2c[2];

        if (*(char *)((int)piVar9 + 0x1d) == '\0') {

          cVar2 = *(char *)(*piVar9 + 0x1d);

          local_2c = piVar9;

          piVar9 = (int *)*piVar9;

          while (cVar2 == '\0') {

            cVar2 = *(char *)(*piVar9 + 0x1d);

            local_2c = piVar9;

            piVar9 = (int *)*piVar9;

          }

        }

        else {

          cVar2 = *(char *)(local_2c[1] + 0x1d);

          piVar3 = (int *)local_2c[1];

          piVar9 = local_2c;

          while ((local_2c = piVar3, cVar2 == '\0' && (piVar9 == (int *)local_2c[2]))) {

            cVar2 = *(char *)(local_2c[1] + 0x1d);

            piVar3 = (int *)local_2c[1];

            piVar9 = local_2c;

          }

        }

      }

    } while (local_2c != *(int **)(param_1 + 0x14));

  }

  if (*(int *)(param_1 + 0x3c) != 0) {

    iVar10 = *(int *)(param_1 + 0x40) - *(int *)(param_1 + 0x3c);

    iVar5 = iVar10 >> 0x1f;

    iVar10 = iVar10 / 0x18 + iVar5;

    if (iVar10 != iVar5) {

      if (*(int *)(param_1 + 0x34) == 0) {

        iVar8 = 0;

      }

      else {

        iVar8 = *(int *)(*(int *)(param_1 + 0x34) + 0x18);

      }

      if (iVar8 < iVar10 - iVar5) {

        piVar9 = *(int **)(param_1 + 0x34);

        if (piVar9 != (int *)0x0) {

          piVar3 = piVar9 + 1;

          *piVar3 = *piVar3 + -1;

          if (*piVar3 == 0) {

            (**(code **)(*piVar9 + 8))();

          }

          *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = 0;

        }

        FUN_00758f60(param_1);

      }

      else {

        iVar5 = 0;

        if (*(int *)(param_1 + 0x3c) != 0) {

          iVar5 = (*(int *)(param_1 + 0x40) - *(int *)(param_1 + 0x3c)) / 0x18;

        }

        FUN_00440110(*(uint32_t /* width from decompiler */ *)(param_1 + 0x3c),iVar5,0);

      }

    }

  }

  if (*(char *)(local_14 + 200) == '\0') {

    iVar5 = FUN_0076c3c0();

    piVar9 = (int *)(extraout_ECX_00 + 0x34 + *(int *)(extraout_ECX_00 + 0xc4) * 4);

    *piVar9 = *piVar9 + (iVar5 - *(int *)(extraout_ECX_00 + 0x30));

    *(int *)(extraout_ECX_00 + 0x30) = iVar5;

    *(uint32_t /* width from decompiler */ *)(extraout_ECX_00 + 0xc4) = local_10;

  }

  ExceptionList = pvStack_c;

  return 0;

}
