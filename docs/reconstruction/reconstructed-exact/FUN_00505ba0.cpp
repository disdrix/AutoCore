// =============================================================================
// FUN_00505ba0
// -----------------------------------------------------------------------------
// Stable ID: aa_00505ba0
// Address:   0x00505ba0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00505ba0 @ 0x00505ba0
// Stable ID: aa_00505ba0
// Embedded strings (evidence for future rename):
//   - "Scale_%i"
//   - "%S%s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~255 non-empty decompiler lines.
//  - Control keywords: if×30, do×2, goto×2, while×2, return×1.
//  - Notable callees: _snprintf×7, FUN_00764030×5, FUN_00989e00×5, FUN_00504d40×2, FUN_004f4870, FUN_004f5cb0, FUN_004fcd80, FUN_00505830.
//  - Strings: "Scale_%i"; "%S%s".
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

uint8_t __thiscall FUN_00505ba0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int *piVar1;

  char cVar2;

  uint8_t uVar3;

  void *pvVar4;

  int *piVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint8_t *puVar8;

  int iVar9;

  int iVar10;

  float10 fVar11;

  char local_a4 [72];

  char acStack_5c [4];

  char local_58 [76];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a3108;

  local_c = ExceptionList;

  iVar10 = 0;

  ExceptionList = &local_c;

  *(uint8_t *)(param_1 + 0xd) = 0;

  cVar2 = FUN_005d4d70(param_2);

  uVar3 = 0;

  if (cVar2 != '\0') {

    if (*(char *)(param_1 + 0x26c) == '\0') {

      if (*(int *)(param_1 + 0x218) != 0) {

        iVar9 = *(int *)(*(int *)(param_1 + 8) + 100);

        if ((iVar9 != 0) && (0 < *(int *)(iVar9 + 0x10))) {

          pvVar4 = operator_new(0x10);

          if (pvVar4 == (void *)0x0) {

            pvVar4 = (void *)0x0;

          }

          else {

            *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 4) = 0;

            *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 8) = 0;

            *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0xc) = 0;

          }

          local_4 = 0xffffffff;

          *(void **)(param_1 + 0x378) = pvVar4;

LAB_00505caf:

          do {

            iVar9 = *(int *)(*(int *)(param_1 + 8) + 100);

            if (iVar9 == 0) {

              iVar9 = 0;

            }

            else {

              iVar9 = *(int *)(iVar9 + 0x10);

            }

            if (iVar9 <= iVar10) break;

            iVar9 = *(int *)(*(int *)(param_1 + 8) + 100);

            if (iVar9 != 0) {

              piVar1 = *(int **)(iVar9 + 0xc);

              piVar5 = (int *)*piVar1;

              iVar9 = iVar10;

              if (piVar5 != piVar1) {

                do {

                  if (iVar9 == 0) {

                    piVar5 = piVar5 + 2;

                    if (((piVar5 != (int *)0x0) && (999 < *(int *)(*piVar5 + 8))) &&

                       (*(int *)(*piVar5 + 8) < 0x409)) {

                      puVar6 = operator_new(0x24);

                      *puVar6 = 0;

                      iVar9 = *piVar5;

                      puVar6[1] = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x20);

                      puVar6[2] = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x24);

                      puVar6[3] = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x28);

                      iVar9 = *piVar5;

                      puVar6[4] = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x10);

                      puVar6[5] = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x14);

                      puVar6[6] = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x18);

                      puVar6[7] = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x1c);

                      sprintf(local_a4,"Scale_%i");

                      fVar11 = (float10)FUN_00505830();

                      puVar6[8] = (float)fVar11;

                      FUN_00597230();

                    }

                    goto LAB_00505da5;

                  }

                  piVar5 = (int *)*piVar5;

                  iVar9 = iVar9 + -1;

                } while (piVar5 != piVar1);

                iVar10 = iVar10 + 1;

                goto LAB_00505caf;

              }

            }

LAB_00505da5:

            iVar10 = iVar10 + 1;

          } while( true );

        }

        if ((*(int *)(param_1 + 0x218) != 0) && (*(int *)(*(int *)(param_1 + 0x218) + 0xe8) != 0)) {

          FUN_005a7180();

        }

        cVar2 = *(char *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x218) + 4) + 4) +

                                            0xac + *(int *)(param_1 + 0x218)) + 0x3c) + 0x4ce);

        if (cVar2 == '\x02') {

          _snprintf(local_58,0x4b,"%S%s");

          pvVar4 = operator_new(0x14c);

          local_4 = 1;

          if (pvVar4 == (void *)0x0) {

            uVar7 = 0;

          }

          else {

            uVar7 = FUN_00764030();

          }

          *(uint32_t /* width from decompiler */ *)(param_1 + 0x300) = uVar7;

          local_4 = 0xffffffff;

          FUN_00989e00();

          (**(code **)(**(int **)(param_1 + 0x300) + 0x5c))();

          puVar8 = operator_new(0xc);

          *puVar8 = 1;

          if (param_1 == 0x40) {

            iVar10 = 0;

          }

          else {

            iVar10 = *(int *)(*(int *)(param_1 + -0x3c) + 4) + -0x3c + param_1;

          }

          *(int *)(puVar8 + 4) = iVar10;

          *(uint8_t **)(*(int *)(param_1 + 0x300) + 0x78) = puVar8;

          _snprintf(acStack_5c,0x4b,"%S%s");

          pvVar4 = operator_new(0x14c);

          puStack_8 = (uint8_t *)0x2;

          if (pvVar4 == (void *)0x0) {

            uVar7 = 0;

          }

          else {

            uVar7 = FUN_00764030();

          }

          puStack_8 = (uint8_t *)0xffffffff;

          *(uint32_t /* width from decompiler */ *)(param_1 + 0x304) = uVar7;

          FUN_00989e00();

          (**(code **)(**(int **)(param_1 + 0x304) + 0x5c))();

          puVar8 = operator_new(0xc);

          *puVar8 = 1;

          if (param_1 == 0x40) {

            iVar10 = 0;

          }

          else {

            iVar10 = *(int *)(*(int *)(param_1 + -0x3c) + 4) + -0x3c + param_1;

          }

          *(int *)(puVar8 + 4) = iVar10;

          *(uint8_t **)(*(int *)(param_1 + 0x304) + 0x78) = puVar8;

        }

        else if (cVar2 == '\x04') {

          _snprintf(local_a4,0x4b,"%S%s");

          pvVar4 = operator_new(0x14c);

          local_4 = 3;

          if (pvVar4 == (void *)0x0) {

            uVar7 = 0;

          }

          else {

            uVar7 = FUN_00764030();

          }

          *(uint32_t /* width from decompiler */ *)(param_1 + 0x300) = uVar7;

          local_4 = 0xffffffff;

          FUN_00989e00();

          iVar10 = (**(code **)(**(int **)(param_1 + 0x300) + 0x5c))();

          if (iVar10 < 0) {

            if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x300) != (uint32_t /* width from decompiler */ *)0x0) {

              (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x300))();

            }

            *(uint32_t /* width from decompiler */ *)(param_1 + 0x300) = 0;

          }

          else {

            puVar8 = operator_new(0xc);

            *puVar8 = 1;

            if (param_1 == 0x40) {

              iVar10 = 0;

            }

            else {

              iVar10 = *(int *)(*(int *)(param_1 + -0x3c) + 4) + -0x3c + param_1;

            }

            *(int *)(puVar8 + 4) = iVar10;

            *(uint8_t **)(*(int *)(param_1 + 0x300) + 0x78) = puVar8;

            _snprintf(local_a4,0x4b,"%S%s");

            FUN_00504d40();

            _snprintf(local_a4,0x4b,"%S%s");

            pvVar4 = operator_new(0x14c);

            local_4 = 4;

            if (pvVar4 == (void *)0x0) {

              uVar7 = 0;

            }

            else {

              uVar7 = FUN_00764030();

            }

            *(uint32_t /* width from decompiler */ *)(param_1 + 0x304) = uVar7;

            local_4 = 0xffffffff;

            FUN_00989e00();

            iVar10 = (**(code **)(**(int **)(param_1 + 0x304) + 0x5c))();

            if (iVar10 < 0) {

              if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x300) != (uint32_t /* width from decompiler */ *)0x0) {

                (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x300))();

              }

              *(uint32_t /* width from decompiler */ *)(param_1 + 0x300) = 0;

              if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x304) != (uint32_t /* width from decompiler */ *)0x0) {

                (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x304))();

              }

              *(uint32_t /* width from decompiler */ *)(param_1 + 0x304) = 0;

            }

            else {

              puVar8 = operator_new(0xc);

              *puVar8 = 1;

              if (param_1 == 0x40) {

                iVar10 = 0;

              }

              else {

                iVar10 = *(int *)(*(int *)(param_1 + -0x3c) + 4) + -0x3c + param_1;

              }

              *(int *)(puVar8 + 4) = iVar10;

              *(uint8_t **)(*(int *)(param_1 + 0x304) + 0x78) = puVar8;

              _snprintf(local_a4,0x4b,"%S%s");

              FUN_00504d40();

            }

          }

        }

        _snprintf(local_58,0x4b,"%S%s");

        pvVar4 = operator_new(0x14c);

        local_4 = 5;

        if (pvVar4 == (void *)0x0) {

          uVar7 = 0;

        }

        else {

          uVar7 = FUN_00764030();

        }

        local_4 = 0xffffffff;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x360) = uVar7;

        FUN_00989e00();

        (**(code **)(**(int **)(param_1 + 0x360) + 0x5c))();

        puVar8 = operator_new(0xc);

        *puVar8 = 1;

        iVar10 = 0;

        if (param_1 != 0x40) {

          iVar10 = *(int *)(*(int *)(param_1 + -0x3c) + 4) + -0x3c + param_1;

        }

        *(int *)(puVar8 + 4) = iVar10;

        *(uint8_t **)(*(int *)(param_1 + 0x360) + 0x78) = puVar8;

        if (*(int *)(param_1 + 8) != 0) {

          *(uint8_t *)(*(int *)(param_1 + 8) + 0x13a) = 1;

        }

        FUN_004fcd80();

        FUN_004f5cb0();

      }

    }

    else {

      FUN_004f4870();

      FUN_00584330();

    }

    uVar3 = 1;

  }

  ExceptionList = local_c;

  return uVar3;

}
