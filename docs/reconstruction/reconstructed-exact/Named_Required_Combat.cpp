// READABILITY (auto CF):
//  - Body size: ~350 non-empty decompiler lines.
//  - Control keywords: if×44, goto×7, do×5, while×5, return×4.
//  - Notable callees: FUN_007a6de0×15, sprintf×10, FUN_00403450×3, free×3, FUN_004f1e20×2, CONCAT13, Character_GetTechForPoolCalcs, FUN_004c4070.
//  - Strings: "\nINGREDIENTS\n"; " %i"; "\nENHANCEMENT INGREDIENTS\n"; "Discipline: ".
//  - Return sites: 4.

// =============================================================================
// Named_Required_Combat
// -----------------------------------------------------------------------------
// Stable ID: aa_00846820
// Address:   0x00846820  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Required Combat"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int Named_Required_Combat(int *param_1)



{

  short sVar1;

  int iVar2;

  uint16_t uVar3;

  short sVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *_Memory;

  uint32_t /* width from decompiler */ uVar6;

  void *pvVar7;

  uint uVar8;

  int unaff_EBX;

  int iVar9;

  uint8_t *puVar10;

  int unaff_EBP;

  int *piVar11;

  int *unaff_ESI;

  int iVar12;

  int unaff_retaddr;

  uint32_t /* width from decompiler */ uVar13;

  uint32_t /* width from decompiler */ local_1a8;

  int iStack_1a4;

  uint32_t /* width from decompiler */ local_19c;

  uint8_t **ppuStack_198;

  uint8_t *local_194;

  uint8_t auStack_190 [116];

  char acStack_11c [4];

  char acStack_118 [4];

  char acStack_114 [4];

  char acStack_110 [252];

  uint32_t /* width from decompiler */ uStack_14;

  void *pvStack_10;

  void *local_c;

  uint8_t *puStack_8;

  int *piStack_4;

  

  piStack_4 = (int *)0xffffffff;

  puStack_8 = &LAB_009ac516;

  local_c = ExceptionList;

  if (DAT_00d1b6d8 == (void *)0x0) {

    return 0;

  }

  ExceptionList = &local_c;

  iVar5 = FUN_00599dd0();

  local_19c = (uint8_t ***)FUN_007a69d0();

  _Memory = (uint32_t /* width from decompiler */ *)FUN_004ce940();

  piVar11 = param_1;

  if (0 < iVar5) {

    local_194 = (uint8_t *)*unaff_ESI;

    uVar13 = 0xff20ff20;

    uVar6 = FUN_007a6de0("\nINGREDIENTS\n",0xffffffff);

    (**(code **)(local_194 + 0x224))(uVar6,uVar13);

    unaff_EBX = 1;

    if (0 < iVar5) {

      iVar9 = 0x498;

      do {

        uVar8 = *(uint *)(iVar9 + *(int *)(piVar11[0x2a] + 0x3c));

        iVar12 = *(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b570 + 0xf10) + 0x10) +

                                  (*(uint *)(*(int *)(DAT_00d1b570 + 0xf10) + 8) & uVar8) * 4) + 4);

        if (iVar12 == 0) {

LAB_00846924:

          iVar12 = 0;

        }

        else {

          do {

            if (uVar8 == *(uint *)(iVar12 + 0x10)) {

              if (iVar12 == 0) goto LAB_00846924;

              iVar12 = *(int *)(iVar12 + 8);

              goto LAB_0084692b;

            }

            iVar12 = *(int *)(iVar12 + 0xc);

          } while (iVar12 != 0);

          iVar12 = 0;

        }

LAB_0084692b:

        if (iVar12 != 0) {

          if (*(int *)(iVar12 + 0x3c) == 0) {

            FUN_004f1e20(1,1);

          }

          (**(code **)(*unaff_ESI + 0x250))(&DAT_00a5a66c);

          iVar2 = *(int *)(iVar12 + 0x3c);

          local_19c = &ppuStack_198;

          uVar6 = (*(code *)PTR_FUN_00af8c9c)();

          FUN_00403450(iVar2 + 0x92,uVar6);

          pvStack_10 = (void *)0x0;

          iVar2 = *unaff_ESI;

          uVar6 = FUN_007a6de0(local_19c,0xffffffff);

          (**(code **)(iVar2 + 0x250))(uVar6);

          uStack_14 = 0xffffffff;

          if (_Memory != &local_19c) {

            free(_Memory);

          }

          if (0 < *(int *)((int)DAT_00d1b6d8 + 0x6b4)) {

            sprintf(acStack_11c," %i",*(uint32_t /* width from decompiler */ *)(iVar12 + 0x34));

            (**(code **)(*unaff_ESI + 0x250))(acStack_11c);

          }

          (**(code **)(*unaff_ESI + 0x250))(&DAT_00a15104);

          unaff_EBX = unaff_EBX + 1;

          piVar11 = piStack_4;

        }

        iVar9 = iVar9 + 4;

        iVar5 = iVar5 + -1;

        unaff_EBP = 0;

      } while (iVar5 != 0);

    }

    iVar5 = (**(code **)(*piVar11 + 0x60))();

    if (iVar5 != 0) {

      iVar5 = *unaff_ESI;

      uVar13 = 0xff20ff20;

      uVar6 = FUN_007a6de0("\nENHANCEMENT INGREDIENTS\n",0xffffffff);

      (**(code **)(iVar5 + 0x224))(uVar6,uVar13);

      unaff_EBX = unaff_EBX + 1;

      puVar10 = (uint8_t *)0x0;

      local_19c = (uint8_t ***)0x0;

      iVar5 = (**(code **)(*piVar11 + 0x60))();

      if (0 < iVar5) {

        do {

          iStack_1a4 = 0;

          do {

            uVar3 = (**(code **)(*piVar11 + 0x5c))(puVar10);

            iVar5 = FUN_005097b0(uVar3);

            uVar8 = *(uint *)(iVar5 + iStack_1a4);

            if (uVar8 != 0xffffffff) {

              iVar5 = *(int *)(*(int *)(*(int *)(*(int *)(DAT_00b041fc + 0xf10) + 0x10) +

                                       (*(uint *)(*(int *)(DAT_00b041fc + 0xf10) + 8) & uVar8) * 4)

                              + 4);

              if (iVar5 == 0) {

LAB_00846aca:

                iVar5 = 0;

              }

              else {

                do {

                  if (uVar8 == *(uint *)(iVar5 + 0x10)) {

                    if (iVar5 == 0) goto LAB_00846aca;

                    iVar5 = *(int *)(iVar5 + 8);

                    goto LAB_00846ad1;

                  }

                  iVar5 = *(int *)(iVar5 + 0xc);

                } while (iVar5 != 0);

                iVar5 = 0;

              }

LAB_00846ad1:

              if (iVar5 != 0) {

                if (*(int *)(iVar5 + 0x3c) == 0) {

                  FUN_004f1e20(1,1);

                }

                (**(code **)(*unaff_ESI + 0x250))(&DAT_00a5a66c);

                iVar9 = *(int *)(iVar5 + 0x3c);

                local_194 = auStack_190;

                uVar6 = (*(code *)PTR_FUN_00af8c9c)();

                FUN_00403450(iVar9 + 0x92,uVar6);

                puStack_8 = (uint8_t *)0x1;

                iVar9 = *unaff_ESI;

                uVar6 = FUN_007a6de0(local_194,0xffffffff);

                (**(code **)(iVar9 + 0x250))(uVar6);

                local_c = (void *)0xffffffff;

                if (ppuStack_198 != &local_194) {

                  free(ppuStack_198);

                }

                if (0 < *(int *)((int)DAT_00d1b6d8 + 0x6b4)) {

                  sprintf(acStack_114," %i",*(uint32_t /* width from decompiler */ *)(iVar5 + 0x34));

                  (**(code **)(*unaff_ESI + 0x250))(acStack_114);

                }

                (**(code **)(*unaff_ESI + 0x250))(&DAT_00a15104);

                puVar10 = local_194;

                piVar11 = param_1;

              }

            }

            iStack_1a4 = iStack_1a4 + 4;

          } while (iStack_1a4 < 0x14);

          puVar10 = puVar10 + 1;

          local_194 = puVar10;

          iVar5 = (**(code **)(*piVar11 + 0x60))();

        } while ((int)puVar10 < iVar5);

      }

    }

  }

  (**(code **)(*unaff_ESI + 0x250))(&DAT_00a15104);

  iVar5 = unaff_EBP + 1;

  if (-1 < *(int *)(*(int *)(piVar11[0x2a] + 0x3c) + 0x4ac)) {

    pvVar7 = operator_new(0x1fc);

    uVar6 = *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(unaff_retaddr + 0xa8) + 0x3c) + 0x4ac);

    FUN_0052b040(uVar6,pvVar7);

    iVar9 = *(int *)(*(int *)(*(int *)(unaff_retaddr + 0xa8) + 0x3c) + 0x4b0);

    iVar12 = FUN_0052ada0(uVar6);

    if ((int)pvVar7 + 0x2a != 0) {

      if (iVar12 < iVar9) {

        local_1a8 = 0xffff0000;

      }

      else {

        local_1a8 = 0xffffffff;

      }

      iVar9 = *unaff_ESI;

      uVar6 = FUN_007a6de0("Discipline: ",0xffffffff);

      (**(code **)(iVar9 + 0x22c))(uVar6,local_1a8);

      local_19c = &ppuStack_198;

      uVar6 = (*(code *)PTR_FUN_00af8c9c)();

      FUN_00403450((int)pvVar7 + 0x2a,uVar6);

      pvStack_10 = (void *)0x2;

      uVar6 = FUN_007a6de0(local_19c,0xffffffff);

      sprintf(acStack_118,"%s - %i\n",uVar6,iVar5);

      pvStack_10 = (void *)0xffffffff;

      if (local_19c != &ppuStack_198) {

        free(local_19c);

      }

      (**(code **)(*unaff_ESI + 0x22c))(acStack_118,unaff_EBX);

      iVar5 = unaff_EBP + 2;

    }

    if (pvVar7 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar7);

    }

  }

  iVar9 = (**(code **)(**(int **)(*(int *)(unaff_retaddr + 0xa8) + 0x3c) + 0x14))();

  if (iVar9 != -1) {

    uVar13 = 0xffffffff;

    uVar6 = (**(code **)(**(int **)(*(int *)(unaff_retaddr + 0xa8) + 0x3c) + 0x14))(0xffffffff);

    uVar6 = FUN_0051f8e0(uVar6);

    uVar6 = FUN_007a6de0(uVar6,uVar13);

    uVar13 = FUN_007a6de0("Required Faction",0xffffffff);

    sprintf(acStack_110,"%s: %s\n",uVar13,uVar6);

    if (DAT_00d1b6d8 == (void *)0x0) {

LAB_00846e11:

      (**(code **)(*unaff_ESI + 0x250))(acStack_110);

    }

    else {

      local_19c = (uint8_t ***)

                  CONCAT13(*(uint8_t *)

                            (*(int *)(*(int *)(*(int *)(*(int *)((int)DAT_00d1b6d8 + 4) + 4) + 0xac

                                              + (int)DAT_00d1b6d8) + 0x3c) + 0x532),

                           (undefined3)local_19c);

      uVar8 = (**(code **)(**(int **)(*(int *)(unaff_retaddr + 0xa8) + 0x3c) + 0x14))();

      if ((uint)local_19c >> 0x18 == uVar8) goto LAB_00846e11;

      (**(code **)(*unaff_ESI + 0x224))(acStack_110,0xffff2020);

    }

    iVar5 = iVar5 + 1;

  }

  iVar9 = *(int *)(*(int *)(*(int *)(unaff_retaddr + 0xa8) + 0x3c) + 0x3e0);

  if (iVar9 != -1) {

    uVar13 = 0xffffffff;

    uVar6 = FUN_0051f940(iVar9,*(uint8_t *)

                                (*(int *)(*(int *)(*(int *)(*(int *)((int)DAT_00d1b6d8 + 4) + 4) +

                                                   0xac + (int)DAT_00d1b6d8) + 0x3c) + 0x532),

                         0xffffffff);

    uVar6 = FUN_007a6de0(uVar6,uVar13);

    uVar13 = FUN_007a6de0("Required Class",0xffffffff);

    sprintf(acStack_110,"%s: %s\n",uVar13,uVar6);

    if ((DAT_00d1b6d8 == (void *)0x0) ||

       ((uint)*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)((int)DAT_00d1b6d8 + 4) + 4) + 0xac +

                                         (int)DAT_00d1b6d8) + 0x3c) + 0x531) ==

        *(uint *)(*(int *)(*(int *)(unaff_retaddr + 0xa8) + 0x3c) + 0x3e0))) {

      (**(code **)(*unaff_ESI + 0x250))(acStack_110);

    }

    else {

      (**(code **)(*unaff_ESI + 0x224))(acStack_110,0xffff2020);

    }

    iVar5 = iVar5 + 1;

  }

  sVar1 = *(short *)(*(int *)(*(int *)(unaff_retaddr + 0xa8) + 0x3c) + 0x3fe);

  if (0 < sVar1) {

    iVar9 = (int)sVar1;

    uVar6 = FUN_007a6de0("Required Combat",0xffffffff);

    sprintf(acStack_110,"%s: %i\n",uVar6,iVar9);

    if ((DAT_00d1b6d8 == (void *)0x0) ||

       (sVar1 = *(short *)(*(int *)(*(int *)(unaff_retaddr + 0xa8) + 0x3c) + 0x3fe),

       sVar4 = FUN_004c4070(), sVar1 <= sVar4)) {

      (**(code **)(*unaff_ESI + 0x250))(acStack_110);

    }

    else {

      (**(code **)(*unaff_ESI + 0x224))(acStack_110,0xffff2020);

    }

    iVar5 = iVar5 + 1;

  }

  sVar1 = *(short *)(*(int *)(*(int *)(unaff_retaddr + 0xa8) + 0x3c) + 0x400);

  if (0 < sVar1) {

    iVar9 = (int)sVar1;

    uVar6 = FUN_007a6de0("Required Perception",0xffffffff);

    sprintf(acStack_110,"%s: %i\n",uVar6,iVar9);

    if ((DAT_00d1b6d8 == (void *)0x0) ||

       (sVar1 = *(short *)(*(int *)(*(int *)(unaff_retaddr + 0xa8) + 0x3c) + 0x400),

       sVar4 = FUN_004c41c0(), sVar1 <= sVar4)) {

      (**(code **)(*unaff_ESI + 0x250))(acStack_110);

    }

    else {

      (**(code **)(*unaff_ESI + 0x224))(acStack_110,0xffff2020);

    }

    iVar5 = iVar5 + 1;

  }

  sVar1 = *(short *)(*(int *)(*(int *)(unaff_retaddr + 0xa8) + 0x3c) + 0x402);

  if (0 < sVar1) {

    iVar9 = (int)sVar1;

    uVar6 = FUN_007a6de0("Required Tech",0xffffffff);

    sprintf(acStack_110,"%s: %i\n",uVar6,iVar9);

    if ((DAT_00d1b6d8 == (void *)0x0) ||

       (sVar1 = *(short *)(*(int *)(*(int *)(unaff_retaddr + 0xa8) + 0x3c) + 0x402),

       iVar9 = Character_GetTechForPoolCalcs(DAT_00d1b6d8), sVar1 <= (short)iVar9)) {

      (**(code **)(*unaff_ESI + 0x250))(acStack_110);

    }

    else {

      (**(code **)(*unaff_ESI + 0x224))(acStack_110,0xffff2020);

    }

    iVar5 = iVar5 + 1;

  }

  sVar1 = *(short *)(*(int *)(*(int *)(unaff_retaddr + 0xa8) + 0x3c) + 0x404);

  if (0 < sVar1) {

    iVar9 = (int)sVar1;

    uVar6 = FUN_007a6de0("Required Theory",0xffffffff);

    sprintf(acStack_110,"%s: %i\n",uVar6,iVar9);

    if ((DAT_00d1b6d8 == (void *)0x0) ||

       (sVar1 = *(short *)(*(int *)(*(int *)(unaff_retaddr + 0xa8) + 0x3c) + 0x404),

       sVar4 = FUN_004c4140(), sVar1 <= sVar4)) {

      (**(code **)(*unaff_ESI + 0x250))(acStack_110);

    }

    else {

      (**(code **)(*unaff_ESI + 0x224))(acStack_110,0xffff2020);

    }

    iVar5 = iVar5 + 1;

  }

  iVar9 = (int)*(short *)(unaff_retaddr + 0xea) + (int)*(short *)(unaff_retaddr + 0xe8);

  if (iVar9 < 0x51) {

    if ((short)iVar9 < 1) {

      ExceptionList = pvStack_10;

      return iVar5;

    }

    if (0x50 < iVar9) goto LAB_0084717d;

  }

  else {

LAB_0084717d:

    iVar9 = 0x50;

  }

  iVar9 = (int)(short)iVar9;

  uVar6 = FUN_007a6de0("Required Level",0xffffffff);

  sprintf(acStack_110,"%s: %i\n",uVar6,iVar9);

  if (DAT_00d1b6d8 != (void *)0x0) {

    iVar12 = (int)*(short *)(unaff_retaddr + 0xe8) + (int)*(short *)(unaff_retaddr + 0xea);

    iVar9 = 0x50;

    if (iVar12 < 0x51) {

      iVar9 = iVar12;

    }

    iVar12 = (**(code **)(*(int *)(*(int *)(*(int *)((int)DAT_00d1b6d8 + 4) + 4) + 4 +

                                  (int)DAT_00d1b6d8) + 0x27c))();

    if (iVar12 < (short)iVar9) {

      (**(code **)(*unaff_ESI + 0x224))(acStack_110,0xffff2020);

      goto LAB_00847212;

    }

  }

  (**(code **)(*unaff_ESI + 0x250))(acStack_110);

LAB_00847212:

  ExceptionList = pvStack_10;

  return iVar5 + 1;

}
