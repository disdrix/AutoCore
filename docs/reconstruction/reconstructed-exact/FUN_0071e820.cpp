// =============================================================================
// FUN_0071e820
// -----------------------------------------------------------------------------
// Stable ID: aa_0071e820
// Address:   0x0071e820  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0071e820 @ 0x0071e820
// Stable ID: aa_0071e820
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~210 non-empty decompiler lines.
//  - Control keywords: if×31, return×8, for×4, goto×2, do×1, while×1.
//  - Notable callees: FUN_0071e6c0×2, FUN_0071e820, FUN_0071ebc0, FUN_0071fad0.
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

/* WARNING: Type propagation algorithm not settling */



int FUN_0071e820(uint8_t *param_1)



{

  int iVar1;

  int *piVar2;

  uint8_t *puVar3;

  uint8_t *puVar4;

  int unaff_ESI;

  uint uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint *puVar7;

  bool bVar8;

  uint8_t *puVar9;

  uint *puVar10;

  uint *puVar11;

  uint *puStack_34;

  uint *puStack_30;

  uint *puStack_2c;

  uint local_1c [5];

  uint local_8 [2];

  

  bVar8 = *(char *)(unaff_ESI + 0x1c4) != '\0';

  if (bVar8) {

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x230) = 0;

  }

  uVar5 = 0;

  local_1c[2] = 0;

  local_1c[1] = 0;

  local_8[0] = 0;

  local_1c[0] = 0;

  local_1c[4] = 0;

  local_8[1] = 0;

  local_1c[3] = 0;

  if (param_1 != (uint8_t *)0x0) {

    *param_1 = 0;

  }

  if (DAT_00afa9be != '\0') {

    if (*(int *)(unaff_ESI + 0x14) == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = *(int *)(*(int *)(unaff_ESI + 0x14) + 0x1c);

    }

    if (iVar1 == *(int *)(unaff_ESI + 0x238)) {

      if (bVar8) {

        puStack_2c = (uint *)0x0;

        puStack_30 = local_1c + 4;

        puStack_34 = local_8;

        puVar11 = local_1c;

        puVar10 = local_1c + 1;

        iVar1 = (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x10) + 0x2c))

                          ((int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x10),0,*(int *)(unaff_ESI + 0x238),

                           puVar10,puVar11);

        if (-1 < iVar1) {

          if (*(int *)(unaff_ESI + 0x14) == 0) {

            iVar1 = -0x7fffbffb;

          }

          else {

            iVar1 = FUN_0071ebc0(puVar10,&puStack_34);

            if (-1 < iVar1) {

              (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x10) + 0x4c))

                        ((int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x10),puVar11,puVar10,0,0);

              return 0;

            }

          }

        }

LAB_0071e8e6:

        (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x10) + 0x4c))

                  ((int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x10),puVar11,puVar10,0,0);

        return iVar1;

      }

    }

    else {

      if (*(int **)(unaff_ESI + 0x10) == (int *)0x0) {

        puStack_34 = (uint *)0x0;

      }

      else if (*(int *)(unaff_ESI + 0x1c) == 0) {

        puStack_34 = (uint *)0x0;

      }

      else {

        puStack_34 = (uint *)**(int **)(unaff_ESI + 0x10);

      }

      puStack_2c = local_8 + 1;

      puStack_30 = local_1c + 3;

      (**(code **)(*puStack_34 + 0x10))();

      if (((*(int *)(unaff_ESI + 0x240) == 0) && (local_1c[0] < *(uint *)(unaff_ESI + 0x238) >> 1))

         && ((char)local_8[0] == '\0')) {

        *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x240) = 1;

      }

      else {

        if (((*(int *)(unaff_ESI + 0x240) != 1) ||

            (local_1c[0] <= *(uint *)(unaff_ESI + 0x238) >> 1)) && ((char)local_8[0] == '\0')) {

          return 0;

        }

        *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x240) = 0;

      }

      if (DAT_00afa9bd != '\0') {

        if (param_1 != (uint8_t *)0x0) {

          *param_1 = 1;

        }

        if (*(int *)(unaff_ESI + 0x240) == 1) {

          uVar5 = *(uint *)(unaff_ESI + 0x238) >> 1;

        }

        else if (*(int *)(unaff_ESI + 0x240) == 0) {

          uVar5 = 0;

        }

        if ((*(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x10) == (uint32_t /* width from decompiler */ *)0x0) ||

           (*(int *)(unaff_ESI + 0x14) == 0)) {

          return -0x7ffbfe10;

        }

        piVar2 = (int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x10);

        puVar11 = (uint *)0x0;

        puVar10 = local_1c + 1;

        puVar3 = &stack0xffffffd8;

        puVar9 = &stack0xffffffdc;

        iVar1 = (**(code **)(*piVar2 + 0x2c))

                          (piVar2,uVar5,*(uint *)(unaff_ESI + 0x238) >> 1,puVar9,puVar3,local_1c + 2

                          );

        if (-1 < iVar1) {

          if (*(int *)(unaff_ESI + 0x228) == 0) {

            iVar1 = FUN_0071e6c0(puVar11);

            if (iVar1 < 0) {

              (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x10) + 0x4c))

                        ((int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x10),puVar11,puVar10,0,0);

              return iVar1;

            }

            if (puStack_34 < puVar10) {

              puVar7 = puStack_34;

              if (*(char *)(unaff_ESI + 0x36) == '\0') {

                puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar11 + (int)puStack_34);

                for (uVar5 = (uint)((int)puVar10 - (int)puStack_34) >> 2; uVar5 != 0;

                    uVar5 = uVar5 - 1) {

                  *puVar6 = 0;

                  puVar6 = puVar6 + 1;

                }

                for (uVar5 = (int)puVar10 - (int)puStack_34 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

                  *(uint8_t *)puVar6 = 0;

                  puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

                }

                if ((char)local_1c[0] == '\0') {

                  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x228) = 1;

                }

              }

              else {

                do {

                  if ((puStack_34 == (uint *)0x0) && (iVar1 = FUN_0071fad0(), iVar1 < 0)) {

                    piVar2 = (int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x10);

LAB_0071eb43:

                    (**(code **)(*piVar2 + 0x4c))(piVar2,puVar11,puVar10,0,0);

                    return iVar1;

                  }

                  iVar1 = FUN_0071e6c0((uint8_t *)((int)puVar7 + (int)puVar11));

                  if (iVar1 < 0) {

                    piVar2 = (int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x10);

                    goto LAB_0071eb43;

                  }

                  if (*(int *)(unaff_ESI + 0x14) == 0) {

                    iVar1 = 0;

                  }

                  else {

                    iVar1 = *(int *)(*(int *)(unaff_ESI + 0x14) + 0x1c);

                  }

                  puVar7 = (uint *)((int)puVar7 + (int)puStack_34);

                  *(int *)(unaff_ESI + 0x24) = iVar1 - (int)puStack_34;

                } while (puVar7 < puVar10);

              }

            }

          }

          else {

            puVar7 = puVar11;

            for (uVar5 = (uint)puVar10 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

              *puVar7 = 0;

              puVar7 = puVar7 + 1;

            }

            for (uVar5 = (uint)puVar10 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

              *(uint8_t *)puVar7 = 0;

              puVar7 = (uint *)((int)puVar7 + 1);

            }

          }

          iVar1 = 0;

          (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x10) + 0x4c))

                    ((int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x10),puVar11,puVar10,0,0);

          puVar4 = puVar3;

          if (puVar3 < *(uint8_t **)(unaff_ESI + 0x230)) {

            puVar4 = (uint8_t *)(iVar1 * 2);

          }

          *(int *)(unaff_ESI + 0x218) =

               (int)(puVar4 + (*(int *)(unaff_ESI + 0x218) -

                              (int)*(uint8_t **)(unaff_ESI + 0x230)));

          if (*(int *)(unaff_ESI + 0x228) != 0) {

            if (*(int *)(unaff_ESI + 0x14) == 0) {

              uVar5 = 0;

            }

            else {

              uVar5 = *(uint *)(*(int *)(unaff_ESI + 0x14) + 0x1c);

            }

            if (uVar5 <= *(uint *)(unaff_ESI + 0x218)) {

              puVar3 = puVar9;

              (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x10) + 0x48))

                        ((int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x10));

            }

          }

          *(uint8_t **)(unaff_ESI + 0x230) = puVar3;

          return 0;

        }

        goto LAB_0071e8e6;

      }

    }

  }

  return 0;

}
