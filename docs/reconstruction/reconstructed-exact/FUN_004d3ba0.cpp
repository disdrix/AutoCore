// =============================================================================
// FUN_004d3ba0
// -----------------------------------------------------------------------------
// Stable ID: aa_004d3ba0
// Address:   0x004d3ba0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004d3ba0 @ 0x004d3ba0
// Stable ID: aa_004d3ba0
// Embedded strings (evidence for future rename):
//   - "HashError:TraversalLock, already locked for traversal"
//   - "VOG_DEBUG_STOP"
//   - "HashError:TraverseToNext, not locked for traversal"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~153 non-empty decompiler lines.
//  - Control keywords: if×23, goto×6, do×5, while×5, return×3, for×2.
//  - Notable callees: FUN_007a4480×4, CNDHash_LookupByKey, CVOGReaction_ResolveObjectTarget, FUN_00403430, FUN_0040fb90, FUN_004d3ba0, FUN_004e0eb0.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 3.

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

uint FUN_004d3ba0(int param_1,int param_2)



{

  int iVar1;

  bool bVar2;

  bool bVar3;

  char cVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int *piVar6;

  uint uVar7;

  int iVar8;

  int iVar9;

  void *pvVar10;

  uint *puVar11;

  byte local_21;

  int iStack_20;

  uint8_t local_18 [4];

  int *local_14;

  int local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a2059;

  pvStack_c = ExceptionList;

  local_21 = 0;

  ExceptionList = &pvStack_c;

  local_14 = (int *)FUN_0040fb90();

  local_10 = 0;

  puVar5 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x1d8);

  local_4 = 0;

  if ((puVar5 != (uint32_t /* width from decompiler */ *)0x0) && (*(int *)(param_1 + 0x1dc) - (int)puVar5 >> 3 != 0)) {

    if ((puVar5 == (uint32_t /* width from decompiler */ *)0x0) || (*(int *)(param_1 + 0x1dc) - (int)puVar5 >> 3 == 0)) {

      puVar5 = (uint32_t /* width from decompiler */ *)FUN_004e0eb0();

    }

    piVar6 = (int *)CVOGReaction_ResolveObjectTarget(0,*puVar5,puVar5[1]);

    if (((piVar6 != (int *)0x0) && ((**(code **)(*piVar6 + 0x124))(local_18), local_10 != 0)) &&

       (iVar1 = *(int *)(*local_14 + 8), *(int *)(*(int *)(iVar1 + 0xa8) + 0x38) == 0x12)) {

      iVar8 = *(int *)(param_2 + 0x540);

      iStack_20 = 0;

      if (*(char *)(iVar8 + 0x1d) != '\0') {

        FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      *(uint8_t *)(iVar8 + 0x1d) = 1;

LAB_004d3cb0:

      do {

        do {

          do {

            iVar8 = *(int *)(param_2 + 0x540);

            if (*(char *)(iVar8 + 0x1d) == '\0') {

              FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

              FUN_007a4480(0,"VOG_DEBUG_STOP");

            }

            if (iStack_20 == 0) {

              iStack_20 = *(int *)(iVar8 + 0x14);

              if (iStack_20 == 0) goto LAB_004d3cff;

              puVar11 = *(uint **)(iStack_20 + 8);

            }

            else {

              iStack_20 = *(int *)(iStack_20 + 0x14);

              if (iStack_20 == 0) {

LAB_004d3cff:

                puVar11 = (uint *)0x0;

              }

              else {

                puVar11 = *(uint **)(iStack_20 + 8);

              }

            }

            if (puVar11 == (uint *)0x0) {

              *(uint8_t *)(*(int *)(param_2 + 0x540) + 0x1d) = 0;

              piVar6 = (int *)*local_14;

              *local_14 = (int)local_14;

              local_14[1] = (int)local_14;

              local_10 = 0;

              if (piVar6 == local_14) {

                    /* WARNING: Subroutine does not return */

                operator_delete(local_14);

              }

                    /* WARNING: Subroutine does not return */

              operator_delete(piVar6);

            }

            iVar8 = *(int *)(*(int *)(*(int *)(*(int *)(param_2 + 0x530) + 0x10) +

                                     (*(uint *)(*(int *)(param_2 + 0x530) + 8) & *puVar11) * 4) + 4)

            ;

            if (iVar8 == 0) {

LAB_004d3d35:

              iVar8 = 0;

            }

            else {

              do {

                if (*puVar11 == *(uint *)(iVar8 + 0x10)) {

                  if (iVar8 == 0) goto LAB_004d3d35;

                  iVar8 = *(int *)(iVar8 + 8);

                  goto LAB_004d3d3c;

                }

                iVar8 = *(int *)(iVar8 + 0xc);

              } while (iVar8 != 0);

              iVar8 = 0;

            }

LAB_004d3d3c:

          } while (iVar8 == 0);

          uVar7 = *(uint *)(iVar8 + 0x20);

          if (uVar7 == 0xffffffff) {

            uVar7 = puVar11[0x22];

          }

        } while (uVar7 != *(uint *)(*(int *)(iVar1 + 0xa8) + 0x34));

        uVar7 = *(uint *)(iVar8 + 0x24);

        if (uVar7 == 0xffffffff) {

          uVar7 = puVar11[0x3f];

        }

      } while (((uVar7 != *(uint *)(*(int *)(iVar1 + 0xa4) + 0xfc)) || ((byte)puVar11[0x4c] == 0))

              || (iVar8 = *(int *)((puVar11[0x4f] - 4) + (uint)(byte)puVar11[0x4c] * 4), iVar8 == 0)

              );

      if (*(int *)(iVar8 + 0x138) == 0) {

        if (local_21 < 5) {

          local_21 = 4;

        }

        goto LAB_004d3cb0;

      }

      piVar6 = *(int **)(iVar8 + 0x158);

      bVar3 = true;

      bVar2 = true;

      if (piVar6 != *(int **)(iVar8 + 0x15c)) {

        do {

          iVar9 = (**(code **)(*(int *)*piVar6 + 0x50))();

          if ((iVar9 == 3) && (*(int *)(*piVar6 + 0x18) != *(int *)(*(int *)(iVar1 + 0xa8) + 0x34)))

          {

            bVar2 = false;

          }

          pvVar10 = CNDHash_LookupByKey(*(void **)(param_2 + 0x55c),*(uint *)(iVar8 + 0x10));

          if ((pvVar10 == (void *)0x0) ||

             (cVar4 = (**(code **)(*(int *)*piVar6 + 0xc))(param_2,pvVar10), cVar4 == '\0')) {

            bVar3 = false;

          }

          piVar6 = piVar6 + 1;

        } while (piVar6 != *(int **)(iVar8 + 0x15c));

        if ((!bVar2) || (!bVar3)) {

          if (local_21 < 6) {

            local_21 = 5;

          }

          goto LAB_004d3cb0;

        }

      }

      if (local_21 < 9) {

        local_21 = 8;

      }

      goto LAB_004d3cb0;

    }

  }

  uVar7 = FUN_00403430();

  ExceptionList = pvStack_c;

  return uVar7 & 0xffffff00;

}
