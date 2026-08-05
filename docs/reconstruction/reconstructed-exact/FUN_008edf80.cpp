// =============================================================================
// FUN_008edf80
// -----------------------------------------------------------------------------
// Stable ID: aa_008edf80
// Address:   0x008edf80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008edf80 @ 0x008edf80
// Stable ID: aa_008edf80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~587 non-empty decompiler lines.
//  - Control keywords: if×54, do×20, while×20, goto×13, return×10, for×9.
//  - Notable callees: PathFileExistsA×6, FUN_0096efd0×4, FUN_00403450×3, FUN_007b6420×3, FUN_007b66c0×3, FUN_007b6a20×3, FUN_0096f3e0×3, FUN_00989e00×3.
//  - Return sites: 10.

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

void FUN_008edf80(int param_1,char *param_2)



{

  int iVar1;

  int iVar2;

  char cVar3;

  uchar uVar4;

  void *pvVar5;

  void *pvVar6;

  uint32_t /* width from decompiler */ uVar7;

  char *pcVar8;

  BOOL BVar9;

  int *piVar10;

  uint uVar11;

  char *pcVar12;

  uint32_t /* width from decompiler */ *puVar13;

  int iVar14;

  char *pcVar15;

  uint uVar16;

  char **ppcVar17;

  int *piVar18;

  float *pfVar19;

  uint32_t /* width from decompiler */ *puVar20;

  bool bVar21;

  int *piStack_494;

  char *local_490;

  int *local_48c;

  char cStack_485;

  float fStack_484;

  int *piStack_480;

  int iStack_47c;

  int iStack_478;

  uint32_t /* width from decompiler */ uStack_474;

  int iStack_470;

  float *pfStack_46c;

  int iStack_468;

  int iStack_464;

  int iStack_460;

  int iStack_45c;

  int iStack_458;

  uchar uStack_454;

  undefined3 uStack_453;

  float fStack_450;

  float fStack_44c;

  uint32_t /* width from decompiler */ *puStack_448;

  uint8_t auStack_444 [8];

  uint8_t auStack_43c [3];

  char cStack_439;

  char *local_438;

  char local_434 [259];

  uint8_t auStack_331 [3];

  uint32_t /* width from decompiler */ uStack_32e;

  char cStack_229;

  char acStack_228 [2];

  uint32_t /* width from decompiler */ auStack_226 [65];

  char cStack_121;

  char local_120 [2];

  uint32_t /* width from decompiler */ local_11e [66];

  void *local_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  

  uStack_c = 0xffffffff;

  puStack_10 = &LAB_009b16b0;

  local_14 = ExceptionList;

  pvVar5 = *(void **)(param_1 + 0x680);

  if (pvVar5 != (void *)0x0) {

    ExceptionList = &local_14;

    FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar5);

  }

  ExceptionList = &local_14;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x680) = 0;

  pcVar8 = param_2;

  pvVar5 = (void *)FUN_00541a80();

  pvVar5 = CNDHash_LookupByKey(pvVar5,(uint)pcVar8);

  if (pvVar5 == (void *)0x0) {

    ExceptionList = local_14;

    return;

  }

  bVar21 = *(char **)(DAT_00d1b644 + 0xfc) == param_2;

  if (((DAT_00d1b6d8 != (void *)0x0) &&

      (pvVar6 = CNDHash_LookupByKey(*(void **)((int)DAT_00d1b6d8 + 0x534),(uint)param_2),

      pvVar6 != (void *)0x0)) && (*(char *)((int)pvVar6 + 4) == '\x02')) {

    bVar21 = true;

  }

  local_120[0] = '\0';

  local_120[1] = '\0';

  puVar13 = local_11e;

  for (iVar14 = 0x40; iVar14 != 0; iVar14 = iVar14 + -1) {

    *puVar13 = 0;

    puVar13 = puVar13 + 1;

  }

  *(uint16_t *)puVar13 = 0;

  local_438 = local_434;

  local_48c = (int *)0x0;

  local_490 = (char *)((int)pvVar5 + 0x1c);

  uVar7 = (*(code *)PTR_FUN_00af8c9c)();

  FUN_00403450((char *)((int)pvVar5 + 0x1c),uVar7);

  pcVar8 = local_438;

  do {

    cVar3 = *pcVar8;

    pcVar8[(int)local_11e + (-2 - (int)local_438)] = cVar3;

    pcVar8 = pcVar8 + 1;

  } while (cVar3 != '\0');

  uStack_c = 0xffffffff;

  if (local_438 != local_434) {

    free(local_438);

  }

  pcVar8 = &cStack_121;

  do {

    pcVar15 = pcVar8;

    pcVar8 = pcVar15 + 1;

  } while (pcVar15[1] != '\0');

  *(uint32_t /* width from decompiler */ *)(pcVar15 + 1) = s__hidden_dds_00a395d0._0_4_;

  *(uint32_t /* width from decompiler */ *)(pcVar15 + 5) = s__hidden_dds_00a395d0._4_4_;

  *(uint32_t /* width from decompiler */ *)(pcVar15 + 9) = s__hidden_dds_00a395d0._8_4_;

  _strlwr(local_120);

  fStack_484 = (float)FUN_007b6a20();

  if ((*(byte *)((int)fStack_484 + 4) & 1) == 0) {

LAB_008ee19c:

    cVar3 = FUN_007b66c0(fStack_484);

    if (cVar3 != '\0') goto LAB_008ee1b7;

  }

  else {

    BVar9 = PathFileExistsA(local_120);

    if (BVar9 == 0) {

      piStack_494 = (int *)FUN_007b6420();

      pcVar8 = (char *)&DAT_00d1e574;

      do {

        pcVar15 = pcVar8;

        if (0xf < *(uint *)(pcVar8 + 0x14)) {

          pcVar15 = *(char **)pcVar8;

        }

        pcVar12 = auStack_331;

        do {

          pcVar12 = pcVar12 + 1;

          cVar3 = *pcVar15;

          *pcVar12 = cVar3;

          pcVar15 = pcVar15 + 1;

          piVar10 = piStack_494;

        } while (cVar3 != '\0');

        do {

          iVar14 = *piVar10;

          piVar10 = (int *)((int)piVar10 + 1);

        } while ((char)iVar14 != '\0');

        uVar11 = (int)piVar10 - (int)piStack_494;

        piVar10 = (int *)auStack_331;

        do {

          pcVar15 = (char *)((int)piVar10 + 1);

          piVar10 = (int *)((int)piVar10 + 1);

        } while (*pcVar15 != '\0');

        piVar18 = piStack_494;

        for (uVar16 = uVar11 >> 2; uVar16 != 0; uVar16 = uVar16 - 1) {

          *piVar10 = *piVar18;

          piVar18 = piVar18 + 1;

          piVar10 = piVar10 + 1;

        }

        for (uVar11 = uVar11 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {

          *(char *)piVar10 = (char)*piVar18;

          piVar18 = (int *)((int)piVar18 + 1);

          piVar10 = (int *)((int)piVar10 + 1);

        }

        BVar9 = PathFileExistsA(auStack_331 + 1);

        if (BVar9 != 0) goto LAB_008ee1b7;

        pcVar8 = pcVar8 + 0x1c;

      } while ((int)pcVar8 < 0xd1e7a4);

      goto LAB_008ee19c;

    }

LAB_008ee1b7:

    piStack_494 = operator_new(4);

    if (piStack_494 == (int *)0x0) {

      piVar10 = (int *)0x0;

    }

    else {

      *piStack_494 = 0;

      piVar10 = piStack_494;

    }

    uStack_c = 0xffffffff;

    local_48c = piVar10;

    FUN_00989e00(&piStack_494,local_120);

    FUN_0096f3e0(&piStack_494,0);

    if ((piVar10 != (int *)0x0) && (!bVar21)) {

      *(int **)(param_1 + 0x680) = piVar10;

      ExceptionList = local_14;

      return;

    }

  }

  acStack_228[0] = '\0';

  acStack_228[1] = '\0';

  puVar13 = auStack_226;

  for (iVar14 = 0x40; iVar14 != 0; iVar14 = iVar14 + -1) {

    *puVar13 = 0;

    puVar13 = puVar13 + 1;

  }

  local_438 = local_434;

  *(uint16_t *)puVar13 = 0;

  uVar7 = (*(code *)PTR_FUN_00af8c9c)();

  FUN_00403450(local_490,uVar7);

  pcVar8 = local_438;

  do {

    cVar3 = *pcVar8;

    pcVar8[(int)auStack_226 + (-2 - (int)local_438)] = cVar3;

    pcVar8 = pcVar8 + 1;

  } while (cVar3 != '\0');

  uStack_c = 0xffffffff;

  if (local_438 != local_434) {

    free(local_438);

  }

  pcVar8 = &cStack_229;

  do {

    pcVar15 = pcVar8;

    pcVar8 = pcVar15 + 1;

  } while (pcVar15[1] != '\0');

  *(uint32_t /* width from decompiler */ *)(pcVar15 + 1) = s__revealed_dds_00a395c0._0_4_;

  *(uint32_t /* width from decompiler */ *)(pcVar15 + 5) = s__revealed_dds_00a395c0._4_4_;

  *(uint32_t /* width from decompiler */ *)(pcVar15 + 9) = s__revealed_dds_00a395c0._8_4_;

  *(uint16_t *)(pcVar15 + 0xd) = s__revealed_dds_00a395c0._12_2_;

  _strlwr(acStack_228);

  fStack_484 = (float)FUN_007b6a20();

  if ((*(byte *)((int)fStack_484 + 4) & 1) == 0) {

LAB_008ee3bc:

    cVar3 = FUN_007b66c0(fStack_484);

    if (cVar3 != '\0') goto LAB_008ee3d1;

  }

  else {

    BVar9 = PathFileExistsA(acStack_228);

    if (BVar9 == 0) {

      piStack_494 = (int *)FUN_007b6420();

      pcVar8 = (char *)&DAT_00d1e574;

      do {

        pcVar15 = pcVar8;

        if (0xf < *(uint *)(pcVar8 + 0x14)) {

          pcVar15 = *(char **)pcVar8;

        }

        pcVar12 = auStack_331;

        do {

          pcVar12 = pcVar12 + 1;

          cVar3 = *pcVar15;

          *pcVar12 = cVar3;

          pcVar15 = pcVar15 + 1;

          piVar10 = piStack_494;

        } while (cVar3 != '\0');

        do {

          iVar14 = *piVar10;

          piVar10 = (int *)((int)piVar10 + 1);

        } while ((char)iVar14 != '\0');

        uVar11 = (int)piVar10 - (int)piStack_494;

        piVar10 = (int *)auStack_331;

        do {

          pcVar15 = (char *)((int)piVar10 + 1);

          piVar10 = (int *)((int)piVar10 + 1);

        } while (*pcVar15 != '\0');

        piVar18 = piStack_494;

        for (uVar16 = uVar11 >> 2; uVar16 != 0; uVar16 = uVar16 - 1) {

          *piVar10 = *piVar18;

          piVar18 = piVar18 + 1;

          piVar10 = piVar10 + 1;

        }

        for (uVar11 = uVar11 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {

          *(char *)piVar10 = (char)*piVar18;

          piVar18 = (int *)((int)piVar18 + 1);

          piVar10 = (int *)((int)piVar10 + 1);

        }

        BVar9 = PathFileExistsA(auStack_331 + 1);

        if (BVar9 != 0) goto LAB_008ee3d1;

        pcVar8 = pcVar8 + 0x1c;

      } while ((int)pcVar8 < 0xd1e7a4);

      goto LAB_008ee3bc;

    }

LAB_008ee3d1:

    piStack_494 = operator_new(4);

    if (piStack_494 == (int *)0x0) {

      piStack_480 = (int *)0x0;

    }

    else {

      *piStack_494 = 0;

      piStack_480 = piStack_494;

    }

    piVar10 = piStack_480;

    uStack_c = 0xffffffff;

    FUN_00989e00(&piStack_494,acStack_228);

    FUN_0096f3e0(&piStack_494,0);

    if (piVar10 != (int *)0x0) {

      if (local_48c == (int *)0x0) {

        *(int **)(param_1 + 0x680) = piVar10;

        ExceptionList = local_14;

        return;

      }

      if ((*(int *)(*piVar10 + 0x1c) != *(int *)(*local_48c + 0x1c)) ||

         (*(int *)(*piVar10 + 0x20) != *(int *)(*local_48c + 0x20))) {

        FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

        operator_delete(piVar10);

      }

      local_490 = operator_new(4);

      if (local_490 == (char *)0x0) {

        pcVar8 = (char *)0x0;

      }

      else {

        local_490[0] = '\0';

        local_490[1] = '\0';

        local_490[2] = '\0';

        local_490[3] = '\0';

        pcVar8 = local_490;

      }

      uStack_c = 0xffffffff;

      *(char **)(param_1 + 0x680) = pcVar8;

      iVar14 = FUN_0096f0e0(0x15,*piVar10 + 0x1c,1,1,1,0);

      if (iVar14 < 0) {

        FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

        operator_delete(piVar10);

      }

      iVar14 = *piVar10;

      cVar3 = FUN_0040ec00();

      cStack_485 = FUN_0040ec00();

      iStack_45c = *(int *)(iVar14 + 0x1c);

      iStack_458 = *(int *)(iVar14 + 0x20);

      pfStack_46c = (float *)0x0;

      if (*(char **)(DAT_00d1b644 + 0xfc) != param_2) {

        local_490 = param_2;

        FUN_0040e180();

        piVar10 = piStack_494;

        if (piStack_494 == *(int **)(param_1 + 0x560)) {

          FUN_008ed6d0(param_1,param_2);

          local_490 = param_2;

          puVar13 = (uint32_t /* width from decompiler */ *)FUN_0040e180();

          piVar10 = (int *)*puVar13;

          if (piVar10 == *(int **)(param_1 + 0x560)) goto LAB_008ee5d9;

        }

        pfStack_46c = (float *)(piVar10 + 4);

      }

LAB_008ee5d9:

      iStack_460 = FUN_0040ebd0(0,0);

      iStack_464 = FUN_0040ebd0(0,0);

      iStack_468 = FUN_0040eba0(0,0);

      if (((iStack_468 != 0) && (iStack_460 != 0)) && (iStack_464 != 0)) {

        iStack_478 = 0;

        iStack_47c = 0;

        if (0 < iStack_45c) {

          do {

            iStack_470 = iStack_458 + -1;

            iStack_478 = 0;

            if (0 < iStack_458) {

              fStack_484 = (float)iStack_47c;

              piStack_494 = (int *)(float)iStack_45c;

              local_490 = (char *)(float)iStack_458;

              pfVar19 = pfStack_46c;

              iVar14 = iStack_468;

              do {

                iVar2 = iStack_478;

                if (pfVar19 == (float *)0x0) {

                  pvVar5 = *(void **)(DAT_00d1b644 + 0xe4f8);

                  fStack_450 = ((float)*(int *)((int)pvVar5 + 0x10) * *(float *)((int)pvVar5 + 0x18)

                               * fStack_484) / (float)piStack_494;

                  fStack_44c = ((float)*(int *)((int)pvVar5 + 0x14) * *(float *)((int)pvVar5 + 0x18)

                               * (float)iStack_470) / (float)local_490;

                  uVar4 = CVOGTerrain_SampleExploredAreaId(pvVar5,fStack_450,fStack_44c);

                  _uStack_454 = CONCAT31(uStack_453,uVar4);

                }

                else {

                  _uStack_454 = CONCAT31(uStack_453,

                                         *(uint8_t *)

                                          ((int)((((float)(int)pfVar19[2] * *pfVar19 * fStack_484) /

                                                  (float)piStack_494 - *pfVar19 * DAT_00a0f298) /

                                                *pfVar19) * (int)pfVar19[1] +

                                           (int)((((float)(int)pfVar19[1] * *pfVar19 *

                                                  (float)iStack_470) / (float)local_490 -

                                                 *pfVar19 * DAT_00a0f298) / *pfVar19) +

                                          (int)pfVar19[3]));

                }

                bVar21 = false;

                if (DAT_00d1b6d8 != (void *)0x0) {

                  bVar21 = CVOGCharacter_IsAreaExplored(DAT_00d1b6d8,(int)param_2,(char)_uStack_454)

                  ;

                }

                if ((uStack_454 == '\0') || (bVar21 != false)) {

                  if (cVar3 == '\0') {

                    FUN_0040ead0(*(uint32_t /* width from decompiler */ *)(*piStack_480 + 0x24));

                    goto LAB_008ee804;

                  }

                  puVar13 = (uint32_t /* width from decompiler */ *)

                            FUN_0099b230(auStack_444,*(uint32_t /* width from decompiler */ *)(*piStack_480 + 0x24),

                                         &iStack_47c,iStack_460,*(uint32_t /* width from decompiler */ *)(*piStack_480 + 0x40)

                                        );

                }

                else if (cStack_485 == '\0') {

                  FUN_0040ead0(*(uint32_t /* width from decompiler */ *)(*local_48c + 0x24));

LAB_008ee804:

                  puVar13 = (uint32_t /* width from decompiler */ *)FUN_0099b010();

                  pfVar19 = pfStack_46c;

                  iVar14 = iStack_468;

                }

                else {

                  puVar13 = (uint32_t /* width from decompiler */ *)

                            FUN_0099b230(auStack_43c,*(uint32_t /* width from decompiler */ *)(*local_48c + 0x24),&iStack_47c,

                                         iStack_464,*(uint32_t /* width from decompiler */ *)(*local_48c + 0x40));

                }

                uStack_474 = *puVar13;

                iVar1 = iStack_47c * 4;

                *(char *)(*(int *)(**(int **)(param_1 + 0x680) + 0x40) * iVar2 + iVar1 + iVar14) =

                     (char)uStack_474;

                *(char *)(*(int *)(**(int **)(param_1 + 0x680) + 0x40) * iVar2 + iVar1 + 1 + iVar14)

                     = (char)((uint)uStack_474 >> 8);

                iStack_470 = iStack_470 + -1;

                *(char *)(*(int *)(**(int **)(param_1 + 0x680) + 0x40) * iVar2 + iVar1 + 2 + iVar14)

                     = (char)((uint)uStack_474 >> 0x10);

                iStack_478 = iVar2 + 1;

                *(uint8_t *)

                 (*(int *)(**(int **)(param_1 + 0x680) + 0x40) * iVar2 + iVar1 + 3 + iVar14) = 0xff;

              } while (iStack_478 < iStack_458);

            }

            iStack_47c = iStack_47c + 1;

          } while (iStack_47c < iStack_45c);

        }

      }

      iVar14 = **(int **)(param_1 + 0x680);

      if (iVar14 == 0) goto LAB_008ee935;

      uVar11 = *(uint *)(iVar14 + 0x2c) & 0xf;

      if (uVar11 == 1) {

        (**(code **)(**(int **)(iVar14 + 0x10) + 0x50))(*(int **)(iVar14 + 0x10),0);

      }

      else {

        if (uVar11 == 2) {

          (**(code **)(**(int **)(iVar14 + 0x10) + 0x50))

                    (*(int **)(iVar14 + 0x10),*(uint32_t /* width from decompiler */ *)(iVar14 + 0x3c),0);

          *(uint32_t /* width from decompiler */ *)(iVar14 + 0x38) = 0xffffffff;

          *(uint32_t /* width from decompiler */ *)(iVar14 + 0x3c) = 0xffffffff;

          *(uint32_t /* width from decompiler */ *)(iVar14 + 0x40) = 0;

          *(uint32_t /* width from decompiler */ *)(iVar14 + 0x44) = 0;

          goto LAB_008ee935;

        }

        if (uVar11 == 4) {

          (**(code **)(**(int **)(iVar14 + 0x10) + 0x50))(*(int **)(iVar14 + 0x10),0);

          *(uint32_t /* width from decompiler */ *)(iVar14 + 0x38) = 0xffffffff;

          *(uint32_t /* width from decompiler */ *)(iVar14 + 0x3c) = 0xffffffff;

          *(uint32_t /* width from decompiler */ *)(iVar14 + 0x40) = 0;

          *(uint32_t /* width from decompiler */ *)(iVar14 + 0x44) = 0;

          goto LAB_008ee935;

        }

      }

      *(uint32_t /* width from decompiler */ *)(iVar14 + 0x38) = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(iVar14 + 0x3c) = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(iVar14 + 0x40) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar14 + 0x44) = 0;

LAB_008ee935:

      iVar14 = *local_48c;

      if (iVar14 != 0) {

        uVar11 = *(uint *)(iVar14 + 0x2c) & 0xf;

        if (uVar11 == 1) {

          (**(code **)(**(int **)(iVar14 + 0x10) + 0x50))(*(int **)(iVar14 + 0x10),0);

        }

        else if (uVar11 == 2) {

          (**(code **)(**(int **)(iVar14 + 0x10) + 0x50))

                    (*(int **)(iVar14 + 0x10),*(uint32_t /* width from decompiler */ *)(iVar14 + 0x3c),0);

        }

        else if (uVar11 == 4) {

          (**(code **)(**(int **)(iVar14 + 0x10) + 0x50))(*(int **)(iVar14 + 0x10),0);

        }

        *(uint32_t /* width from decompiler */ *)(iVar14 + 0x38) = 0xffffffff;

        *(uint32_t /* width from decompiler */ *)(iVar14 + 0x3c) = 0xffffffff;

        *(uint32_t /* width from decompiler */ *)(iVar14 + 0x40) = 0;

        *(uint32_t /* width from decompiler */ *)(iVar14 + 0x44) = 0;

      }

      piVar10 = piStack_480;

      iVar14 = *piStack_480;

      if (iVar14 != 0) {

        uVar11 = *(uint *)(iVar14 + 0x2c) & 0xf;

        if (uVar11 == 1) {

          (**(code **)(**(int **)(iVar14 + 0x10) + 0x50))(*(int **)(iVar14 + 0x10),0);

        }

        else if (uVar11 == 2) {

          (**(code **)(**(int **)(iVar14 + 0x10) + 0x50))

                    (*(int **)(iVar14 + 0x10),*(uint32_t /* width from decompiler */ *)(iVar14 + 0x3c),0);

        }

        else if (uVar11 == 4) {

          (**(code **)(**(int **)(iVar14 + 0x10) + 0x50))(*(int **)(iVar14 + 0x10),0);

        }

        *(uint32_t /* width from decompiler */ *)(iVar14 + 0x38) = 0xffffffff;

        *(uint32_t /* width from decompiler */ *)(iVar14 + 0x3c) = 0xffffffff;

        *(uint32_t /* width from decompiler */ *)(iVar14 + 0x40) = 0;

        *(uint32_t /* width from decompiler */ *)(iVar14 + 0x44) = 0;

      }

      FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

      operator_delete(piVar10);

    }

  }

  if (local_48c != (int *)0x0) {

    *(int **)(param_1 + 0x680) = local_48c;

    ExceptionList = local_14;

    return;

  }

  auStack_331._1_2_ = 0;

  puVar13 = &uStack_32e;

  for (iVar14 = 0x40; iVar14 != 0; iVar14 = iVar14 + -1) {

    *puVar13 = 0;

    puVar13 = puVar13 + 1;

  }

  *(uint16_t *)puVar13 = 0;

  local_438 = local_434;

  uVar7 = (*(code *)PTR_FUN_00af8c9c)();

  FUN_00403450(local_490,uVar7);

  pcVar8 = local_438;

  do {

    cVar3 = *pcVar8;

    pcVar8[(int)(auStack_331 + (1 - (int)local_438))] = cVar3;

    pcVar8 = pcVar8 + 1;

  } while (cVar3 != '\0');

  uStack_c = 0xffffffff;

  if (local_438 != local_434) {

    free(local_438);

  }

  puVar13 = (uint32_t /* width from decompiler */ *)auStack_331;

  do {

    puVar20 = puVar13;

    puVar13 = (uint32_t /* width from decompiler */ *)((int)puVar20 + 1);

  } while (*(char *)((int)puVar20 + 1) != '\0');

  *(uint32_t /* width from decompiler */ *)((int)puVar20 + 1) = DAT_00a2c53c;

  *(uint8_t *)((int)puVar20 + 5) = DAT_00a2c540;

  _strlwr(auStack_331 + 1);

  piStack_494 = (int *)FUN_007b6a20();

  if ((*(byte *)(piStack_494 + 1) & 1) != 0) {

    BVar9 = PathFileExistsA(auStack_331 + 1);

    if (BVar9 != 0) goto LAB_008eebaf;

    local_490 = (char *)FUN_007b6420();

    pcVar8 = (char *)&DAT_00d1e574;

    do {

      pcVar15 = pcVar8;

      if (0xf < *(uint *)(pcVar8 + 0x14)) {

        pcVar15 = *(char **)pcVar8;

      }

      ppcVar17 = &local_438;

      do {

        cVar3 = *pcVar15;

        *(char *)ppcVar17 = cVar3;

        pcVar15 = pcVar15 + 1;

        ppcVar17 = (char **)((int)ppcVar17 + 1);

        pcVar12 = local_490;

      } while (cVar3 != '\0');

      do {

        cVar3 = *pcVar12;

        pcVar12 = pcVar12 + 1;

      } while (cVar3 != '\0');

      uVar11 = (int)pcVar12 - (int)local_490;

      pcVar15 = &cStack_439;

      do {

        pcVar12 = pcVar15 + 1;

        pcVar15 = pcVar15 + 1;

      } while (*pcVar12 != '\0');

      pcVar12 = local_490;

      for (uVar16 = uVar11 >> 2; uVar16 != 0; uVar16 = uVar16 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar15 = *(uint32_t /* width from decompiler */ *)pcVar12;

        pcVar12 = pcVar12 + 4;

        pcVar15 = pcVar15 + 4;

      }

      for (uVar11 = uVar11 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {

        *pcVar15 = *pcVar12;

        pcVar12 = pcVar12 + 1;

        pcVar15 = pcVar15 + 1;

      }

      BVar9 = PathFileExistsA((LPCSTR)&local_438);

      if (BVar9 != 0) goto LAB_008eebaf;

      pcVar8 = pcVar8 + 0x1c;

    } while ((int)pcVar8 < 0xd1e7a4);

  }

  cVar3 = FUN_007b66c0(piStack_494);

  if (cVar3 == '\0') {

    ExceptionList = local_14;

    return;

  }

LAB_008eebaf:

  puStack_448 = operator_new(4);

  if (puStack_448 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar13 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *puStack_448 = 0;

    puVar13 = puStack_448;

  }

  uStack_c = 0xffffffff;

  *(uint32_t /* width from decompiler */ **)(param_1 + 0x680) = puVar13;

  FUN_00989e00(&local_490,auStack_331 + 1);

  FUN_0096f3e0(&local_490,0);

  ExceptionList = local_14;

  return;

}
