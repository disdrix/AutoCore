// =============================================================================
// FUN_0089b090
// -----------------------------------------------------------------------------
// Stable ID: aa_0089b090
// Address:   0x0089b090  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0089b090 @ 0x0089b090
// Stable ID: aa_0089b090
// Embedded strings (evidence for future rename):
//   - ");

// READABILITY (auto CF):
//  - Body size: ~378 non-empty decompiler lines.
//  - Control keywords: if×57, do×7, while×7, return×3.
//  - Notable callees: sprintf×9, CNDHash_LookupByKey×4, FUN_005711c0×4, FUN_00599dd0×3, __RTDynamicCast×3, FUN_007a6de0×2, FUN_00403450, FUN_004eb240.
//  - Strings: "%S: %i"; "%i/%i"; "%i/1"; "%s_key_i.dds".
//  - Return sites: 3.

              }

              else {

                sprintf(acStack_10c,"
//   - "%i/%i"
//   - ");

                }

                else {

                  sprintf(acStack_10c,"
//   - "%i/1"
//   - "%s_key_i.dds"
//   - "%s_i.dds"
// Readability: control flow preserved from Ghidra decompile; types tentative.

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

void FUN_0089b090(int *param_1)



{

  uint uVar1;

  uint32_t /* width from decompiler */ *puVar2;

  char cVar3;

  int iVar4;

  int iVar5;

  void *pvVar6;

  int iVar7;

  int *piVar8;

  uint32_t /* width from decompiler */ *puVar9;

  longlong lVar10;

  char *pcVar11;

  int iStack_230;

  int iStack_22c;

  uint *puStack_228;

  void *pvStack_224;

  int iStack_220;

  int iStack_21c;

  uint *puStack_218;

  uint uStack_214;

  uint8_t auStack_20d [5];

  uint8_t auStack_208 [2];

  uint8_t auStack_206 [4];

  uint8_t auStack_202 [246];

  char acStack_10c [252];

  uint32_t /* width from decompiler */ uStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009ad239;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  cVar3 = (**(code **)(*param_1 + 0x3d8))();

  if ((cVar3 != '\0') && (DAT_00d1b6d8 != 0)) {

    puStack_218 = (uint *)FUN_007a69d0();

    if ((int *)param_1[0x183] != (int *)0x0) {

      (**(code **)(*(int *)param_1[0x183] + 4))();

    }

    if ((int *)param_1[0x184] != (int *)0x0) {

      (**(code **)(*(int *)param_1[0x184] + 4))();

    }

    *(uint8_t *)(param_1 + 0x14a) = 0;

    lVar10 = (**(code **)(*(int *)param_1[0x15a] + 0x44c))();

    uStack_214 = (uint)lVar10;

    if (lVar10 == -1) {

      lVar10 = (**(code **)(*(int *)param_1[0x15b] + 0x44c))();

      uStack_214 = (uint)lVar10;

      if (lVar10 == -1) {

        piVar8 = param_1 + 0x169;

        iVar7 = 5;

        uStack_214 = 0xffffffff;

        do {

          if ((int *)piVar8[-5] != (int *)0x0) {

            (**(code **)(*(int *)piVar8[-5] + 4))();

          }

          if ((int *)*piVar8 != (int *)0x0) {

            (**(code **)(*(int *)*piVar8 + 4))();

          }

          if ((int *)piVar8[5] != (int *)0x0) {

            (**(code **)(*(int *)piVar8[5] + 4))();

          }

          piVar8[10] = -1;

          piVar8 = piVar8 + 1;

          iVar7 = iVar7 + -1;

        } while (iVar7 != 0);

        if ((int *)param_1[0x160] != (int *)0x0) {

          (**(code **)(*(int *)param_1[0x160] + 4))();

        }

        if ((int *)param_1[0x17a] != (int *)0x0) {

          (**(code **)(*(int *)param_1[0x17a] + 4))();

        }

        if ((int *)param_1[0x178] != (int *)0x0) {

          (**(code **)(*(int *)param_1[0x178] + 4))();

        }

        if ((int *)param_1[0x179] != (int *)0x0) {

          (**(code **)(*(int *)param_1[0x179] + 4))();

        }

        param_1[0x17b] = -1;

        if (((int *)param_1[0x15f] != (int *)0x0) &&

           (iVar7 = (**(code **)(*(int *)param_1[0x15f] + 0x1dc))(), iVar7 != 0)) {

          (**(code **)(*(int *)param_1[0x15f] + 0x1d8))();

          (**(code **)(*(int *)param_1[0x15f] + 0x34c))();

        }

        if (((int *)param_1[0x15e] != (int *)0x0) &&

           (iVar7 = (**(code **)(*(int *)param_1[0x15e] + 0x1dc))(), iVar7 != 0)) {

          (**(code **)(*(int *)param_1[0x15e] + 0x1d8))();

          (**(code **)(*(int *)param_1[0x15e] + 0x34c))();

        }

        if (((int *)param_1[0x155] != (int *)0x0) &&

           (cVar3 = (**(code **)(*(int *)param_1[0x155] + 0xd8))(), cVar3 != '\0')) {

          (**(code **)(*(int *)param_1[0x155] + 0xd4))();

          (**(code **)(*(int *)param_1[0x155] + 0x34c))();

        }

        if ((int *)param_1[0x161] == (int *)0x0) {

          ExceptionList = pvStack_c;

          return;

        }

        (**(code **)(*(int *)param_1[0x161] + 0x1d8))();

        (**(code **)(*(int *)param_1[0x161] + 0xcc))(0);

        (**(code **)(*(int *)param_1[0x161] + 0x34c))();

        ExceptionList = pvStack_c;

        return;

      }

    }

    pvStack_224 = CNDHash_LookupByKey(*(void **)(DAT_00d1b570 + 0xf10),uStack_214);

    if ((pvStack_224 == (void *)0x0) || (iVar7 = *(int *)((int)pvStack_224 + 0x3c), iVar7 == 0)) {

      FUN_007a4480();

    }

    else {

      iVar4 = __RTDynamicCast(iVar7,0);

      if ((char)param_1[0x14e] != '\0') {

        pvStack_224 = CNDHash_LookupByKey(*(void **)(DAT_00d1b570 + 0xf10),*(uint *)(iVar4 + 0x4d0))

        ;

        if (pvStack_224 == (void *)0x0) {

          param_1[0x17b] = -1;

        }

        else {

          if (*(int *)((int)pvStack_224 + 0x3c) == 0) {

            FUN_004f1e20();

          }

          iVar4 = __RTDynamicCast(*(uint32_t /* width from decompiler */ *)((int)pvStack_224 + 0x3c),0);

          param_1[0x17b] = *(int *)((int)pvStack_224 + 0x34);

        }

      }

      iVar4 = *(int *)(iVar4 + 0x4d0);

      if (((((char)param_1[0x14e] == '\0') && (iVar4 != -1)) && (iVar5 = FUN_00599dd0(), 0 < iVar5))

         && (((int *)param_1[0x183] != (int *)0x0 && (param_1[0x184] != 0)))) {

        (**(code **)(*(int *)param_1[0x183] + 4))();

        (**(code **)(*(int *)param_1[0x184] + 4))();

      }

      iVar5 = FUN_00599dd0();

      if ((iVar5 < 1) ||

         ((iVar4 != -1 &&

          (((int *)param_1[0x183] == (int *)0x0 ||

           (cVar3 = (**(code **)(*(int *)param_1[0x183] + 0x3bc))(), cVar3 == '\0')))))) {

        *(uint8_t *)(param_1 + 0x14a) = 2;

        iVar7 = __RTDynamicCast(*(uint32_t /* width from decompiler */ *)((int)pvStack_224 + 0x3c),0);

        uVar1 = *(uint *)(iVar7 + 0x4d0);

        if (uVar1 == 0xffffffff) {

          iStack_22c = 0;

        }

        else {

          iStack_22c = 1;

          pvVar6 = CNDHash_LookupByKey(*(void **)(DAT_00d1b570 + 0xf10),uVar1);

          iVar7 = *(int *)((int)pvVar6 + 0x3c);

          if (iVar7 != 0) {

            iVar4 = 0;

            iStack_230 = -0x10000;

            if (((DAT_00d1b6d8 != 0) && (*(int *)(DAT_00d1b6d8 + 0x250) != 0)) &&

               (*(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x2b0) != 0)) {

              iVar4 = FUN_005711c0();

              iVar5 = FUN_005711c0();

              iVar4 = iVar4 + iVar5;

              if ((int)(uint)*(byte *)(iVar7 + 0x4c9) <= iVar4) {

                iStack_230 = -1;

              }

            }

            param_1[0x173] = uVar1;

            if ((int *)param_1[0x164] != (int *)0x0) {

              (**(code **)(*(int *)param_1[0x164] + 4))();

            }

            if (param_1[0x169] != 0) {

              if (*(int *)(DAT_00d1b6d8 + 0x6b4) < 1) {

                sprintf(acStack_10c,"%S");

              }

              else {

                sprintf(acStack_10c,"%S: %i");

              }

              (**(code **)(*(int *)param_1[0x169] + 0x1d8))();

              (**(code **)(*(int *)param_1[0x169] + 0x15c))(1,&stack0xfffffdc4);

              (**(code **)(*(int *)param_1[0x169] + 0xcc))(1);

              (**(code **)(*(int *)param_1[0x169] + 0x34c))();

            }

            if (param_1[0x16e] != 0) {

              sprintf(auStack_20d + 1,"%s");

              puVar2 = (uint32_t /* width from decompiler */ *)auStack_20d;

              if (*(int *)((int)pvVar6 + 0x38) == 0xe) {

                do {

                  puVar9 = puVar2;

                  puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

                } while (*(char *)((int)puVar9 + 1) != '\0');

                *(uint32_t /* width from decompiler */ *)((int)puVar9 + 1) = DAT_00a4e304;

                *(uint32_t /* width from decompiler */ *)((int)puVar9 + 5) = DAT_00a4e308;

                *(uint16_t *)((int)puVar9 + 9) = DAT_00a4e30c;

                *(uint8_t *)((int)puVar9 + 0xb) = DAT_00a4e30e;

              }

              else {

                do {

                  puVar9 = puVar2;

                  puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

                } while (*(char *)((int)puVar9 + 1) != '\0');

                *(uint32_t /* width from decompiler */ *)((int)puVar9 + 1) = DAT_00a2c534;

                *(uint16_t *)((int)puVar9 + 5) = DAT_00a2c538;

                *(uint8_t *)((int)puVar9 + 7) = DAT_00a2c53a;

              }

              (**(code **)(*(int *)param_1[0x16e] + 0x50))();

              (**(code **)(*(int *)param_1[0x16e] + 0x2c4))();

              (**(code **)(*(int *)param_1[0x16e] + 0xcc))(1);

              sprintf((char *)&iStack_21c,"%i/%i",iVar4,(uint)*(byte *)(iStack_230 + 0x4c9));

              (**(code **)(*(int *)param_1[0x16e] + 0x1d8))(&iStack_21c,1,1);

              (**(code **)(*(int *)param_1[0x16e] + 0x34c))();

              (**(code **)(*(int *)param_1[0x16e] + 0x15c))(0,&stack0xfffffdb4);

            }

          }

        }

      }

      else {

        iStack_22c = FUN_00599dd0();

        *(uint8_t *)(param_1 + 0x14a) = 1;

        if (0 < iStack_22c) {

          puStack_228 = (uint *)(iVar7 + 0x498);

          piVar8 = param_1 + 0x169;

          iStack_220 = iStack_22c;

          do {

            uVar1 = *puStack_228;

            piVar8[10] = uVar1;

            pvVar6 = CNDHash_LookupByKey(*(void **)(DAT_00d1b570 + 0xf10),uVar1);

            if (pvVar6 != (void *)0x0) {

              iStack_21c = 0;

              if (((DAT_00d1b6d8 != 0) && (*(int *)(DAT_00d1b6d8 + 0x250) != 0)) &&

                 ((*(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x2b0) != 0 &&

                  (*(int *)(DAT_00d1b6d8 + 0xcbc) != 0)))) {

                iVar7 = FUN_005711c0();

                iStack_21c = FUN_005711c0();

                iStack_21c = iVar7 + iStack_21c;

              }

              if ((int *)piVar8[-5] != (int *)0x0) {

                (**(code **)(*(int *)piVar8[-5] + 4))();

              }

              if (*piVar8 != 0) {

                if (*(int *)(DAT_00d1b6d8 + 0x6b4) < 1) {

                  sprintf(acStack_10c,"%S");

                }

                else {

                  sprintf(acStack_10c,"%S: %i");

                }

                (**(code **)(*(int *)*piVar8 + 0x1d8))();

                (**(code **)(*(int *)*piVar8 + 0x15c))(1,&stack0xfffffdc4);

                (**(code **)(*(int *)*piVar8 + 0xcc))(1);

                (**(code **)(*(int *)*piVar8 + 0x34c))();

              }

              if (piVar8[5] != 0) {

                sprintf(auStack_20d + 1,"%s");

                puVar2 = (uint32_t /* width from decompiler */ *)auStack_20d;

                if (*(int *)((int)pvVar6 + 0x38) == 0xe) {

                  do {

                    puVar9 = puVar2;

                    puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

                  } while (*(char *)((int)puVar9 + 1) != '\0');

                  *(uint32_t /* width from decompiler */ *)((int)puVar9 + 1) = DAT_00a4e304;

                  *(uint32_t /* width from decompiler */ *)((int)puVar9 + 5) = DAT_00a4e308;

                  *(uint16_t *)((int)puVar9 + 9) = DAT_00a4e30c;

                  *(uint8_t *)((int)puVar9 + 0xb) = DAT_00a4e30e;

                }

                else {

                  do {

                    puVar9 = puVar2;

                    puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

                  } while (*(char *)((int)puVar9 + 1) != '\0');

                  *(uint32_t /* width from decompiler */ *)((int)puVar9 + 1) = DAT_00a2c534;

                  *(uint16_t *)((int)puVar9 + 5) = DAT_00a2c538;

                  *(uint8_t *)((int)puVar9 + 7) = DAT_00a2c53a;

                }

                (**(code **)(*(int *)piVar8[5] + 0x50))();

                (**(code **)(*(int *)piVar8[5] + 0x2c4))();

                (**(code **)(*(int *)piVar8[5] + 0xcc))(1);

                sprintf((char *)&iStack_21c,"%i/1",iStack_22c);

                (**(code **)(*(int *)piVar8[5] + 0x1d8))(&iStack_21c,1,1);

                (**(code **)(*(int *)piVar8[5] + 0x34c))();

                (**(code **)(*(int *)piVar8[5] + 0x15c))(0,&stack0xfffffdb4);

              }

            }

            puStack_228 = puStack_228 + 1;

            piVar8 = piVar8 + 1;

            iStack_220 = iStack_220 + -1;

          } while (iStack_220 != 0);

        }

      }

      if ((char)param_1[0x14e] != '\0') {

        iStack_22c = 0;

      }

      if (iStack_22c < 5) {

        piVar8 = param_1 + iStack_22c + 0x169;

        iStack_22c = 5 - iStack_22c;

        do {

          if ((int *)piVar8[-5] != (int *)0x0) {

            (**(code **)(*(int *)piVar8[-5] + 4))();

          }

          if ((int *)*piVar8 != (int *)0x0) {

            (**(code **)(*(int *)*piVar8 + 4))();

          }

          if ((int *)piVar8[5] != (int *)0x0) {

            (**(code **)(*(int *)piVar8[5] + 4))();

          }

          piVar8[10] = -1;

          piVar8 = piVar8 + 1;

          iStack_22c = iStack_22c + -1;

        } while (iStack_22c != 0);

      }

      if ((int *)param_1[0x160] != (int *)0x0) {

        (**(code **)(*(int *)param_1[0x160] + 4))();

      }

      if ((int *)param_1[0x17a] != (int *)0x0) {

        if (pvStack_224 == (void *)0x0) {

          (**(code **)(*(int *)param_1[0x17a] + 0xcc))();

        }

        else {

          if (*(int *)((int)pvStack_224 + 0x38) == 0xe) {

            pcVar11 = "%s_key_i.dds";

          }

          else {

            pcVar11 = "%s_i.dds";

          }

          sprintf(acStack_10c,pcVar11);

          (**(code **)(*(int *)param_1[0x17a] + 0x50))();

          (**(code **)(*(int *)param_1[0x17a] + 0x2c4))();

          (**(code **)(*(int *)param_1[0x17a] + 0xcc))(1);

          (**(code **)(*(int *)param_1[0x17a] + 0x34c))();

        }

      }

      if ((int *)param_1[0x178] != (int *)0x0) {

        (**(code **)(*(int *)param_1[0x178] + 0xcc))();

        (**(code **)(*(int *)param_1[0x178] + 0x34c))();

      }

      if (param_1[0x179] != 0) {

        if (pvStack_224 != (void *)0x0) {

          FUN_004eb240();

          auStack_20d._1_4_ = auStack_208;

          (*(code *)PTR_FUN_00af8c9c)();

          FUN_00403450();

          uStack_4 = 0;

          (**(code **)(*(int *)param_1[0x179] + 0x1d8))();

          uStack_10 = 0xffffffff;

          if (puStack_218 != &uStack_214) {

            free(puStack_218);

          }

          (**(code **)(*(int *)param_1[0x179] + 0x15c))(1,&stack0xfffffdc8);

        }

        (**(code **)(*(int *)param_1[0x179] + 0xcc))();

        (**(code **)(*(int *)param_1[0x179] + 0x34c))();

      }

      if ((char)param_1[0x14e] == '\0') {

        param_1[0x17b] = uStack_214;

      }

      if ((((int *)param_1[0x15f] != (int *)0x0) &&

          (iVar7 = (**(code **)(*(int *)param_1[0x15f] + 0x1dc))(), iVar7 == 0)) &&

         ((char)param_1[0x14e] == '\0')) {

        iVar7 = *(int *)param_1[0x15f];

        FUN_007a6de0("Recipe:");

        (**(code **)(iVar7 + 0x1d8))();

        (**(code **)(*(int *)param_1[0x15f] + 0x34c))();

      }

      piVar8 = (int *)param_1[0x15e];

      if (piVar8 != (int *)0x0) {

        if ((char)param_1[0x14e] == '\0') {

          iVar7 = *piVar8;

          pcVar11 = "Refines Into:";

        }

        else {

          iVar7 = *piVar8;

          if (pvStack_224 == (void *)0x0) {

            pcVar11 = "Cannot Reverse Refine";

          }

          else {

            pcVar11 = "Reverse Refines Into:";

          }

        }

        FUN_007a6de0(pcVar11);

        (**(code **)(iVar7 + 0x1d8))();

        (**(code **)(*(int *)param_1[0x15e] + 0x34c))();

      }

    }

  }

  ExceptionList = pvStack_c;

  return;

}
