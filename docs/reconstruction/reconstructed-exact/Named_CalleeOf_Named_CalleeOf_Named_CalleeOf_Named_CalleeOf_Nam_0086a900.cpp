// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0086a900
// -----------------------------------------------------------------------------
// Stable ID: aa_0086a900
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli
// Address:   0x0086a900  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli: callee helper. Evidence string: "Min level". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Min level"
//   - "Max level"
//   - "Min team size"
//   - "Max team size"
//   - "Min value"
//   - "Max value"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~313 non-empty decompiler lines.
//  - Control keywords: if×31, do×4, while×4, return×2.
//  - Notable callees: FUN_007a6de0×8, sprintf×4, CVOGReaction_GiveItemByCbid×2, FUN_004ce940×2, FUN_00508e20×2, strncat×2, strncpy×2, FUN_007a69d0.
//  - Strings: "%s (%d)"; "Min level"; "%s: %d "; "Max level".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli
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

/* WARNING: Removing unreachable block (ram,0x0086afc0) */



void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0086a900(int param_1,int param_2,int param_3)



{

  int *piVar1;

  uint32_t /* width from decompiler */ uVar2;

  int *piVar3;

  char *pcVar4;

  int iVar5;

  uint *puVar6;

  uint *puVar7;

  int iVar8;

  uint *puVar9;

  int unaff_EBP;

  code *pcVar10;

  int unaff_ESI;

  code *pcVar11;

  uint uVar12;

  uint32_t /* width from decompiler */ *puVar13;

  uint32_t /* width from decompiler */ *puVar14;

  int unaff_EDI;

  size_t sVar15;

  uint uStack_d40;

  uint local_d28;

  uint *puStack_d24;

  uint uStack_d1c;

  int iStack_d14;

  char acStack_d10 [4];

  char acStack_d0c [268];

  char acStack_c00 [1024];

  char local_800 [2048];

  

  uStack_d40 = 0x86a911;

  FUN_007a69d0();

  piVar3 = (int *)**(int **)(param_1 + 0x564);

  if (piVar3 != *(int **)(param_1 + 0x564)) {

    do {

      if ((*(int *)piVar3[2] == param_2) && (*(int *)piVar3[2] >> 0x1f == param_3)) {

        puVar9 = (uint *)piVar3[2];

        if (puVar9 != (uint *)0x0) {

          *(int *)(param_1 + 0x548) = param_2;

          *(int *)(param_1 + 0x54c) = param_3;

          if (*(int **)(param_1 + 0x598) != (int *)0x0) {

            uStack_d40 = 1;

            (**(code **)(**(int **)(param_1 + 0x598) + 0x1d8))(puVar9 + 2,1);

            (**(code **)(**(int **)(param_1 + 0x598) + 0xcc))(1);

            (**(code **)(**(int **)(param_1 + 0x598) + 0x34c))();

          }

          pcVar11 = sprintf_exref;

          if (*(int **)(param_1 + 0x624) != (int *)0x0) {

            if ((DAT_00d1b6d8 == 0) || (*(int *)(DAT_00d1b6d8 + 0x6b4) < 1)) {

              uStack_d40 = 1;

              (**(code **)(**(int **)(param_1 + 0x624) + 0x1d8))((int)puVar9 + 0x89,1);

              pcVar11 = sprintf_exref;

            }

            else {

              uStack_d40 = *puVar9;

              sprintf(local_800,"%s (%d)",(int)puVar9 + 0x89);

              uStack_d40 = 1;

              (**(code **)(**(int **)(param_1 + 0x624) + 0x1d8))(local_800,1);

            }

            (**(code **)(**(int **)(param_1 + 0x624) + 0xcc))(1);

            (**(code **)(**(int **)(param_1 + 0x624) + 0x34c))();

          }

          pcVar10 = strncat_exref;

          if (*(int *)(param_1 + 0x628) != 0) {

            uStack_d40 = puVar9[0xb1];

            local_800[0] = '\0';

            if (uStack_d40 != 0) {

              uVar2 = FUN_007a6de0("Min level",0xffffffff);

              (*pcVar11)(acStack_c00,"%s: %d ",uVar2);

              pcVar10 = strncat_exref;

              strncat(local_800,acStack_c00,0x3ff);

            }

            uStack_d40 = puVar9[0xb2];

            if (uStack_d40 != 0) {

              uVar2 = FUN_007a6de0("Max level",0xffffffff);

              (*pcVar11)(acStack_c00,"%s: %d ",uVar2);

              (*pcVar10)(local_800,acStack_c00,0x3ff);

            }

            uStack_d40 = puVar9[0xa9];

            if (uStack_d40 != 0) {

              uVar2 = FUN_007a6de0("Min team size",0xffffffff);

              (*pcVar11)(acStack_c00,"%s: %d ",uVar2);

              (*pcVar10)(local_800,acStack_c00,0x3ff);

            }

            uStack_d40 = puVar9[0xaa];

            if (uStack_d40 != 0) {

              uVar2 = FUN_007a6de0("Max team size",0xffffffff);

              (*pcVar11)(acStack_c00,"%s: %d ",uVar2);

              (*pcVar10)(local_800,acStack_c00,0x3ff);

            }

            uVar12 = puVar9[0xb6];

            uStack_d40 = puVar9[0xb7];

            if (uVar12 != 0 || uStack_d40 != 0) {

              uVar2 = FUN_007a6de0("Min value",0xffffffff);

              (*pcVar11)(acStack_c00,"%s: %I64d ",uVar2,uVar12);

              (*pcVar10)(local_800,acStack_c00,0x3ff);

            }

            uVar12 = puVar9[0xb8];

            uStack_d40 = puVar9[0xb9];

            if (uVar12 != 0 || uStack_d40 != 0) {

              uVar2 = FUN_007a6de0("Max value",0xffffffff);

              (*pcVar11)(acStack_c00,"%s: %I64d ",uVar2,uVar12);

              (*pcVar10)(local_800,acStack_c00,0x3ff);

            }

            uStack_d40 = puVar9[0xa8];

            if (uStack_d40 != 0) {

              uVar2 = FUN_007a6de0("Max teams",0xffffffff);

              (*pcVar11)(acStack_c00,"%s: %d ",uVar2);

              (*pcVar10)(local_800,acStack_c00,0x3ff);

            }

            uStack_d40 = 1;

            (**(code **)(**(int **)(param_1 + 0x628) + 0x1d8))(local_800,1);

            (**(code **)(**(int **)(param_1 + 0x628) + 0xcc))(1);

            (**(code **)(**(int **)(param_1 + 0x628) + 0x34c))();

          }

          uVar12 = puVar9[0xc2];

          uStack_d1c = uStack_d1c & 0xffffff00;

          if (uVar12 != 0xffffffff) {

            puStack_d24 = (uint *)0x0;

            if ((char)puVar9[0xc0] == '\0') {

              *(uint8_t *)(param_1 + 0x580) = 0;

            }

            else {

              *(uint8_t *)(param_1 + 0x580) = 1;

              uStack_d40 = puVar9[0xc2];

              FUN_004ce940();

              puStack_d24 = (uint *)FUN_00508e20();

              if (puStack_d24 != (uint *)0x0) {

                uVar12 = puStack_d24[0x21];

              }

            }

            uStack_d40 = 0;

            piVar3 = (int *)CVOGReaction_GiveItemByCbid(uVar12);

            if (piVar3 != (int *)0x0) {

              uStack_d40 = 1;

              iVar8 = (**(code **)(*piVar3 + 8))(uVar12,DAT_00d1b644);

              if (-1 < iVar8) {

                sVar15 = 0x80;

                pcVar4 = (char *)(**(code **)(*piVar3 + 0x1c4))();

                strncpy(acStack_d0c,pcVar4,sVar15);

                (*pcVar10)(acStack_d0c,&DAT_00a2c53c,0x80);

                piVar1 = *(int **)(param_1 + 0x5f0);

                iVar8 = *piVar1;

                uVar2 = (**(code **)(iVar8 + 0x2d8))();

                iVar5 = (**(code **)(*piVar1 + 0x2c8))(uVar2);

                (**(code **)(iVar8 + 0x50))(acStack_d0c);

                if (unaff_EDI == 0) {

                  iVar8 = (**(code **)(*piVar3 + 0x15c))();

                }

                else {

                  iVar8 = unaff_EDI + 4;

                }

                (**(code **)(**(int **)(param_1 + 0x604) + 0x1d8))(iVar8,1,1);

                (**(code **)(**(int **)(param_1 + 0x604) + 0x34c))();

                *(int *)(param_1 + 0x56c) = iVar5;

                (**(code **)(**(int **)(param_1 + 0x604) + 4))(1);

                (**(code **)(**(int **)(param_1 + 0x5dc) + 4))(1);

                (**(code **)(**(int **)(param_1 + 0x5f0) + 4))(1);

                if (*(int *)(iVar5 + 0x31c) < 2) {

                  (**(code **)(**(int **)(param_1 + 0x5f0) + 0x1d8))(0,1,1);

                }

                else {

                  sprintf(&stack0xfffff2c4,"%d",*(int *)(iVar5 + 0x31c));

                  (**(code **)(**(int **)(param_1 + 0x5f0) + 0x1d8))(&stack0xfffff2c4,1,1);

                }

                (**(code **)(**(int **)(param_1 + 0x5f0) + 0x34c))();

              }

              (**(code **)*piVar3)(1);

            }

          }

          *(uint8_t *)(param_1 + 0x580) = 0;

          *(uint32_t /* width from decompiler */ *)(param_1 + 0x56c) = 0xffffffff;

          uStack_d40 = 0;

          (**(code **)(**(int **)(param_1 + 0x604) + 4))();

          (**(code **)(**(int **)(param_1 + 0x604) + 0x1d8))(0,1,1);

          (**(code **)(**(int **)(param_1 + 0x604) + 0x34c))();

          (**(code **)(**(int **)(param_1 + 0x5dc) + 4))(0);

          (**(code **)(**(int **)(param_1 + 0x5f0) + 4))(0);

          (**(code **)(**(int **)(param_1 + 0x5f0) + 0x1d8))(0,1,1);

          (**(code **)(**(int **)(param_1 + 0x5f0) + 0x34c))();

          uStack_d40 = uStack_d1c;

          (**(code **)(**(int **)(param_1 + 0x5d4) + 4))();

          puVar7 = puVar9 + 0xc3;

          iStack_d14 = 1;

          puVar13 = (uint32_t /* width from decompiler */ *)(param_1 + 0x5f4);

          do {

            local_d28 = *puVar7;

            if (local_d28 != 0xffffffff) {

              if (*(char *)(iStack_d14 + 0x300 + (int)puVar9) == '\0') {

                *(uint8_t *)(param_1 + 0x581) = 0;

              }

              else {

                *(uint8_t *)(param_1 + 0x581) = 1;

                uVar12 = *puVar7;

                FUN_004ce940(uVar12);

                iVar8 = FUN_00508e20(uVar12);

                if (iVar8 != 0) {

                  local_d28 = *(uint *)(iVar8 + 0x84);

                }

              }

              puVar6 = (uint *)CVOGReaction_GiveItemByCbid(local_d28);

              puVar9 = puStack_d24;

              if (puVar6 != (uint *)0x0) {

                iVar8 = (**(code **)(*puVar6 + 8))(local_d28,DAT_00d1b644,1);

                if (-1 < iVar8) {

                  sVar15 = 0x80;

                  pcVar4 = (char *)(**(code **)(*puVar6 + 0x1c4))();

                  strncpy(acStack_d10,pcVar4,sVar15);

                  strncat(acStack_d10,".dds",0x80);

                  piVar3 = (int *)*puVar13;

                  iVar8 = *piVar3;

                  uVar2 = (**(code **)(iVar8 + 0x2d8))();

                  uVar2 = (**(code **)(*piVar3 + 0x2c8))(uVar2);

                  (**(code **)(iVar8 + 0x50))(acStack_d10,uVar2);

                  if (unaff_ESI == 0) {

                    iVar8 = (**(code **)(iRam00000001 + 0x15c))();

                  }

                  else {

                    iVar8 = unaff_ESI + 4;

                  }

                  (**(code **)(*(int *)puVar13[5] + 0x1d8))(iVar8,1,1);

                  (**(code **)(*(int *)puVar13[5] + 0x34c))();

                  puVar13[-0x21] = local_d28;

                  (**(code **)(*(int *)puVar13[5] + 4))(1);

                  (**(code **)(*(int *)puVar13[-5] + 4))(1);

                  (**(code **)(*(int *)*puVar13 + 4))(1);

                  if (*(int *)(local_d28 + 0x14) < 2) {

                    (**(code **)(*(int *)*puVar13 + 0x1d8))(0,1,1);

                  }

                  else {

                    sprintf((char *)&uStack_d40,"%d",*(int *)(local_d28 + 0x14));

                    (**(code **)(*(int *)*puVar13 + 0x1d8))(&uStack_d40,1,1);

                  }

                  (**(code **)(*(int *)*puVar13 + 0x34c))();

                  puVar13 = puVar13 + 1;

                  puVar6 = puStack_d24;

                }

                (**(code **)*puVar6)(1);

              }

            }

            iVar8 = 1;

            iStack_d14 = iStack_d14 + 1;

            puVar7 = puVar7 + 1;

          } while (iStack_d14 < 5);

          puVar13 = (uint32_t /* width from decompiler */ *)(param_1 + 0x604);

          do {

            puVar14 = puVar13 + 1;

            *(uint8_t *)(param_1 + 0x580 + iVar8) = 0;

            puVar13[-0x25] = 0xffffffff;

            (**(code **)(*(int *)*puVar14 + 4))(0);

            (**(code **)(*(int *)*puVar14 + 0x1d8))(0,1,1);

            (**(code **)(*(int *)*puVar14 + 0x34c))();

            (**(code **)(*(int *)puVar13[-9] + 4))(0);

            (**(code **)(*(int *)puVar13[-4] + 4))(0);

            (**(code **)(*(int *)puVar13[-4] + 0x1d8))(0,1,1);

            (**(code **)(*(int *)puVar13[-4] + 0x34c))();

            iVar8 = iVar8 + 1;

            puVar13 = puVar14;

          } while (iVar8 < 5);

          (**(code **)(**(int **)(param_1 + 0x5d8) + 4))(*(int *)(param_1 + 0x570) != -1);

          if (*(int **)(param_1 + 0x5cc) != (int *)0x0) {

            (**(code **)(**(int **)(param_1 + 0x5cc) + 0x1d8))(0,1,1);

            if (*(int *)(unaff_EBP + 0x2f8) != 0) {

              uVar2 = FUN_007a6de0(&DAT_00a43258,0xffffffff);

              sprintf((char *)&iStack_d14,"%d %s\n",*(uint32_t /* width from decompiler */ *)(unaff_EBP + 0x2f8),uVar2);

              (**(code **)(**(int **)(param_1 + 0x5cc) + 0x250))(&iStack_d14);

            }

            if ((*(int *)(unaff_EBP + 0x2f0) != 0 || *(int *)(unaff_EBP + 0x2f4) != 0) &&

               (DAT_00d1ad30 != 0)) {

              FUN_00977a30(DAT_00d1ad30,*(int *)(unaff_EBP + 0x2f0),*(int *)(unaff_EBP + 0x2f4));

              (**(code **)(**(int **)(param_1 + 0x5cc) + 0x250))(&DAT_00a15104);

            }

            (**(code **)(**(int **)(param_1 + 0x5cc) + 0xcc))(1);

            (**(code **)(**(int **)(param_1 + 0x5cc) + 0x34c))();

          }

          (**(code **)(**(int **)(param_1 + 0x5c8) + 4))(1);

          (**(code **)(**(int **)(param_1 + 0x5d0) + 4))(1);

          (**(code **)(**(int **)(param_1 + 0x618) + 4))(1);

          (**(code **)(**(int **)(param_1 + 0x61c) + 4))(1);

          (**(code **)(**(int **)(param_1 + 0x620) + 4))(1);

          return;

        }

        break;

      }

      piVar3 = (int *)*piVar3;

    } while (piVar3 != (int *)*(int *)(param_1 + 0x564));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x548) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x54c) = 0xffffffff;

  uStack_d40 = 0;

  (**(code **)(**(int **)(param_1 + 0x598) + 4))();

  (**(code **)(**(int **)(param_1 + 0x5c8) + 4))(0);

  (**(code **)(**(int **)(param_1 + 0x5cc) + 4))(0);

  (**(code **)(**(int **)(param_1 + 0x5d0) + 4))(0);

  puVar13 = (uint32_t /* width from decompiler */ *)(param_1 + 0x5dc);

  iVar8 = 5;

  do {

    puVar13[-0x1c] = 0xffffffff;

    (**(code **)(*(int *)*puVar13 + 4))(0);

    (**(code **)(*(int *)puVar13[10] + 4))(0);

    (**(code **)(*(int *)puVar13[5] + 4))(0);

    puVar13 = puVar13 + 1;

    iVar8 = iVar8 + -1;

  } while (iVar8 != 0);

  (**(code **)(**(int **)(param_1 + 0x5d4) + 4))(0);

  (**(code **)(**(int **)(param_1 + 0x5d8) + 4))(0);

  (**(code **)(**(int **)(param_1 + 0x618) + 4))(0);

  (**(code **)(**(int **)(param_1 + 0x61c) + 4))(0);

  (**(code **)(**(int **)(param_1 + 0x620) + 4))(0);

  (**(code **)(**(int **)(param_1 + 0x624) + 4))(0);

  (**(code **)(**(int **)(param_1 + 0x628) + 4))(0);

  return;

}
