// READABILITY (auto CF):
//  - Body size: ~246 non-empty decompiler lines.
//  - Control keywords: if×40, do×4, goto×4, while×4, return×2.
//  - Notable callees: FUN_0074fca0×2, FUN_00729e80, FUN_0074f200, FUN_0074f360, FUN_0074fba0, FUN_0075b6a0, FUN_0075b720, FUN_00967710.
//  - Strings: "

                                 ,0x189,3,".
//  - Return sites: 2.

// =============================================================================
// Named_gfxSubPhaseLegacy_00729e80
// -----------------------------------------------------------------------------
// Stable ID: aa_00729e80
// Address:   0x00729e80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxSubPhaseLegacy"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __fastcall Named_gfxSubPhaseLegacy_00729e80(int param_1)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  bool bVar4;

  char cVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint uVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  int iVar11;

  int iVar12;

  int iStack_54;

  int iStack_50;

  uint uStack_48;

  float fStack_44;

  float fStack_40;

  int iStack_3c;

  int *piStack_38;

  int iStack_34;

  int iStack_30;

  int iStack_2c;

  int iStack_28;

  int local_24;

  int local_20;

  int iStack_1c;

  int iStack_18;

  int iStack_14;

  uint uStack_10;

  int *piStack_c;

  int local_4;

  

  if ((*(int *)(param_1 + 0xc) == 0) ||

     (local_4 = *(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc) >> 2, local_4 == 0)) {

    return 1;

  }

  iVar10 = *(int *)(*(int *)(*(int *)(param_1 + 0x18) + 0x20) + 8);

  local_24 = iVar10;

  local_20 = param_1;

  FUN_0074fca0(2);

  iVar8 = *(int *)(iVar10 + 0x28);

  if (-1 < *(int *)(&DAT_00afe00c + iVar8 * 0xc)) {

    (**(code **)(**(int **)(iVar10 + 0xc) + 0x108))(*(int **)(iVar10 + 0xc));

  }

  (**(code **)(**(int **)(iVar10 + 0xc) + 0x100))(*(int **)(iVar10 + 0xc),0);

  *(uint32_t /* width from decompiler */ *)(&DAT_00afe00c + iVar8 * 0xc) = 0;

  FUN_0075b6a0(&fStack_40,&fStack_44);

  iVar10 = *(int *)(*(int *)(param_1 + 0x18) + 0x2c);

  if (iVar10 == 0) {

    uStack_10 = 0;

  }

  else {

    uStack_10 = *(int *)(*(int *)(param_1 + 0x18) + 0x30) - iVar10 >> 4;

  }

  uStack_48 = 0;

  if (uStack_10 != 0) {

    iStack_30 = 0;

    do {

      iVar10 = *(int *)(*(int *)(iStack_28 + 0x18) + 0x2c) + iStack_30;

      if ((*(float *)(iVar10 + 8) != fStack_40) || (*(float *)(iVar10 + 0xc) != fStack_44)) {

        fStack_40 = *(float *)(iVar10 + 8);

        fStack_44 = *(float *)(iVar10 + 0xc);

        FUN_0075b720(fStack_40,fStack_44);

      }

      iVar12 = iStack_2c;

      iVar8 = *(int *)(iStack_2c + 0x28);

      if (-1 < (int)*(uint *)(&DAT_00afe00c + iVar8 * 0xc)) {

        (**(code **)(**(int **)(iStack_2c + 0xc) + 0x108))(*(int **)(iStack_2c + 0xc));

      }

      (**(code **)(**(int **)(iVar12 + 0xc) + 0x100))(*(int **)(iVar12 + 0xc),uStack_48);

      iVar12 = DAT_00d1f048;

      *(uint *)(&DAT_00afe00c + iVar8 * 0xc) = uStack_48;

      local_24 = 0;

      local_20 = 0;

      iStack_34 = 0;

      if ((*(char *)(iVar12 + 0xf) == '\0') || (bVar4 = true, *(int *)(iVar10 + 4) != 0)) {

        bVar4 = false;

      }

      piStack_38 = *(int **)(iStack_28 + 0xc);

      piStack_c = *(int **)(iStack_28 + 0x10);

      iStack_50 = -1;

      if (piStack_38 != piStack_c) {

        do {

          iVar8 = iStack_2c;

          piVar2 = (int *)*piStack_38;

          iVar10 = piVar2[2];

          if (((iVar10 != 0) && (*(int *)(iVar10 + 200) != 0)) &&

             (iStack_14 = (*(int *)(iVar10 + 0xcc) - *(int *)(iVar10 + 200)) / 0x24, 0 < iStack_14))

          {

            iVar12 = piVar2[1];

            if (iVar12 == 0) {

              iVar9 = 0;

            }

            else {

              iVar9 = *(int *)(iVar12 + 8);

            }

            if (0 < iStack_50) {

              iVar3 = *(int *)(iStack_2c + 0x28);

              if (-1 < *(int *)(&DAT_00afe00c + iVar3 * 0xc)) {

                (**(code **)(**(int **)(iStack_2c + 0xc) + 0x108))(*(int **)(iStack_2c + 0xc));

              }

              (**(code **)(**(int **)(iVar8 + 0xc) + 0x100))(*(int **)(iVar8 + 0xc),uStack_48);

              *(uint *)(&DAT_00afe00c + iVar3 * 0xc) = uStack_48;

              iStack_50 = -1;

            }

            if ((iVar9 != iStack_34) || (piVar2[2] != local_24)) {

              local_24 = piVar2[2];

              iStack_34 = iVar9;

              if (iVar9 != 0) {

                FUN_0074fba0(local_24);

                FUN_0074fca0(2);

              }

              iStack_50 = -1;

            }

            iVar8 = DAT_00d1f614;

            if (DAT_00d1f614 != 0) {

              piVar1 = (int *)(DAT_00d1f614 + 0xd8 + *(int *)(DAT_00d1f614 + 0xc4) * 0x4c);

              *piVar1 = *piVar1 + 1;

            }

            if (local_20 != iVar12) {

              if (iVar12 != 0) {

                FUN_0074f200(*(uint32_t /* width from decompiler */ *)(iVar12 + 0xc));

                iVar8 = DAT_00d1f614;

              }

              local_20 = iVar12;

              if (iVar8 != 0) {

                piVar1 = (int *)(iVar8 + 0xd4 + *(int *)(iVar8 + 0xc4) * 0x4c);

                *piVar1 = *piVar1 + 1;

              }

            }

            iStack_54 = -1;

            iVar8 = piVar2[3];

            iStack_1c = iVar8;

            if (iVar8 != 0) {

              if ((int *)*piVar2 == (int *)0x0) {

                cVar5 = '\0';

              }

              else {

                cVar5 = (**(code **)(*(int *)*piVar2 + 0x1c))();

              }

              if ((bVar4) && (cVar5 != '\0')) {

                uVar6 = 1;

              }

              else {

                uVar6 = 0;

              }

              FUN_00967710(iVar10,uVar6);

            }

            if ((int *)*piVar2 != (int *)0x0) {

              (**(code **)(*(int *)*piVar2 + 0xc))(piVar2);

            }

            iVar12 = 0;

            if (0 < iStack_14) {

              iStack_3c = 0;

              do {

                iVar11 = *(int *)(iVar10 + 200) + iStack_3c;

                iVar3 = iStack_54;

                if ((-1 < (char)(*(uint *)(iVar11 + 0x20) >> 8)) &&

                   (iVar3 = iVar12, (*(uint *)(iVar11 + 0x20) & 2) == 0)) {

                  iStack_18 = 0;

                  do {

                    uVar7 = 0;

                    if ((iVar8 != 0) && ((*(uint *)(iVar11 + 0x20) & 0x1000) != 0)) {

                      iVar3 = iStack_54;

                      if (((*(uint *)(iVar11 + 0x20) & 1) == 0) && (*(int *)(iVar8 + 0x48) == 0))

                      goto LAB_0072a331;

                      if (*(char *)(iVar10 + 0x11) == '\0') {

                        uVar7 = FUN_00967790(iVar8,iVar11);

                      }

                      else {

                        uVar7 = FUN_009679d0(iVar8,iVar11);

                      }

                      if (uVar7 == 0) goto LAB_0072a331;

                    }

                    if (iStack_50 < iVar12) {

                      if (-1 < iStack_54) {

                        if (iVar9 != 0) {

                          iVar8 = *(int *)(iVar9 + 0x28);

                          if (-1 < *(int *)(&DAT_00afe00c + iVar8 * 0xc)) {

                            (**(code **)(**(int **)(iVar9 + 0xc) + 0x108))(*(int **)(iVar9 + 0xc));

                          }

                          (**(code **)(**(int **)(iVar9 + 0xc) + 0x100))

                                    (*(int **)(iVar9 + 0xc),iStack_54);

                          *(int *)(&DAT_00afe00c + iVar8 * 0xc) = iStack_54;

                          iVar8 = iStack_1c;

                        }

                        iStack_54 = -1;

                      }

                      iStack_50 = iVar12;

                      if (iVar9 != 0) {

                        iVar8 = *(int *)(iVar9 + 0x28);

                        if (-1 < *(int *)(&DAT_00afe00c + iVar8 * 0xc)) {

                          (**(code **)(**(int **)(iVar9 + 0xc) + 0x108))(*(int **)(iVar9 + 0xc));

                        }

                        (**(code **)(**(int **)(iVar9 + 0xc) + 0x100))

                                  (*(int **)(iVar9 + 0xc),iVar12);

                        *(int *)(&DAT_00afe00c + iVar8 * 0xc) = iVar12;

                        iVar8 = iStack_1c;

                      }

                    }

                    if ((int *)*piVar2 != (int *)0x0) {

                      (**(code **)(*(int *)*piVar2 + 8))(piVar2);

                    }

                    iVar3 = iStack_54;

                    if ((uVar7 & 2) == 0) goto LAB_0072a331;

                    iStack_18 = iStack_18 + 1;

                  } while (iStack_18 < 100);

                  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxSubPhaseLegacy.cpp"

                                 ,0x189,3,"Excess pass looping detected. Aborting pass.");

                }

LAB_0072a331:

                iStack_54 = iVar3;

                iStack_3c = iStack_3c + 0x24;

                iVar12 = iVar12 + 1;

              } while (iVar12 < iStack_14);

            }

          }

          iVar10 = iStack_34;

          piStack_38 = piStack_38 + 1;

        } while (piStack_38 != piStack_c);

        if (iStack_34 != 0) {

          iVar8 = *(int *)(iStack_34 + 0x28);

          if (*(int *)(&DAT_00afe00c + iVar8 * 0xc) < 0) {

LAB_0072a391:

            if (*(int *)(iVar10 + 0xc) != 0) {

              piVar2 = *(int **)(iVar10 + 0xc);

              (**(code **)(*piVar2 + 0x10c))(piVar2);

            }

          }

          else if (*(int *)(iStack_34 + 0xc) != 0) {

            (**(code **)(**(int **)(iStack_34 + 0xc) + 0x108))(*(int **)(iStack_34 + 0xc));

            goto LAB_0072a391;

          }

          *(uint32_t /* width from decompiler */ *)(&DAT_00afe00c + iVar8 * 0xc) = 0xffffffff;

          (&DAT_00afe010)[iVar8 * 3] = 0;

          *(uint32_t /* width from decompiler */ *)(&DAT_00afe014 + iVar8 * 0xc) = 0;

        }

      }

      iStack_30 = iStack_30 + 0x10;

      uStack_48 = uStack_48 + 1;

    } while (uStack_48 < uStack_10);

  }

  FUN_0074f360();

  return 0;

}
