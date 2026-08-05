// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_ShowInvento_00571e10
// -----------------------------------------------------------------------------
// Stable ID: aa_00571e10
// Callee of Named_CalleeOf_Named_CalleeOf_Client_ShowInventoryFullAcceptMes
// Address:   0x00571e10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_ShowInventoryFullAcceptMes: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~91 non-empty decompiler lines.
//  - Control keywords: if×8, while×5, do×3, return×2.
//  - Notable callees: FUN_00571b80, FUN_00571e10, FUN_005731c0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_ShowInventoryFullAcceptMes
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_ShowInvento_00571e10(int param_1,int param_2,char param_3)



{

  byte bVar1;

  byte bVar2;

  char cVar3;

  int *piVar4;

  int iVar5;

  void *pvVar6;

  int *piVar7;

  uint32_t /* width from decompiler */ uVar8;

  int iVar9;

  uint uVar10;

  int iVar11;

  int *piVar12;

  uint32_t /* width from decompiler */ uVar13;

  int iStack_c;

  uint uStack_4;

  

  piVar12 = (int *)**(int **)(param_1 + 0x60);

  if (piVar12 != *(int **)(param_1 + 0x60)) {

    do {

      piVar4 = (int *)piVar12[4];

      if (((piVar4 != (int *)0x0) && (param_2 != 0)) && (param_3 != '\0')) {

        uVar13 = 1;

        uVar8 = (**(code **)(*piVar4 + 0x25c))(1);

        FUN_00571b80(piVar4,uVar8,uVar13);

      }

      (**(code **)(*piVar4 + 0x24c))((char)piVar12[5],*(uint8_t *)((int)piVar12 + 0x15));

      (**(code **)(*(int *)piVar12[4] + 0x158))(*(uint32_t /* width from decompiler */ *)(param_1 + 0x24));

      if (*(int *)(*(int *)(piVar12[4] + 0xa8) + 0x38) != 4) {

        bVar1 = *(byte *)(*(int *)(piVar4[0x2a] + 0x3c) + 0x406);

        bVar2 = *(byte *)(*(int *)(piVar4[0x2a] + 0x3c) + 0x407);

        if (bVar1 != 0) {

          uStack_4 = (uint)bVar1;

          iStack_c = 0;

          do {

            if (bVar2 != 0) {

              iVar9 = 0;

              uVar10 = (uint)bVar2;

              do {

                iVar11 = (uint)*(byte *)((int)piVar12 + 0x15) +

                         ((uint)*(byte *)(piVar12 + 5) + iStack_c) * *(int *)(param_1 + 0xc) + iVar9

                ;

                iVar5 = *(int *)(param_1 + 0x28);

                *(int *)(iVar5 + iVar11 * 8) = piVar4[0x58];

                iVar9 = iVar9 + 1;

                uVar10 = uVar10 - 1;

                *(int *)(iVar5 + 4 + iVar11 * 8) = piVar4[0x59];

              } while (uVar10 != 0);

            }

            iStack_c = iStack_c + 1;

            uStack_4 = uStack_4 - 1;

          } while (uStack_4 != 0);

        }

      }

      if (*(char *)((int)piVar12 + 0x19) == '\0') {

        piVar4 = (int *)piVar12[2];

        if (*(char *)((int)piVar4 + 0x19) == '\0') {

          cVar3 = *(char *)(*piVar4 + 0x19);

          piVar12 = piVar4;

          piVar4 = (int *)*piVar4;

          while (cVar3 == '\0') {

            cVar3 = *(char *)(*piVar4 + 0x19);

            piVar12 = piVar4;

            piVar4 = (int *)*piVar4;

          }

        }

        else {

          cVar3 = *(char *)(piVar12[1] + 0x19);

          piVar7 = (int *)piVar12[1];

          piVar4 = piVar12;

          while ((piVar12 = piVar7, cVar3 == '\0' && (piVar4 == (int *)piVar12[2]))) {

            cVar3 = *(char *)(piVar12[1] + 0x19);

            piVar7 = (int *)piVar12[1];

            piVar4 = piVar12;

          }

        }

      }

    } while (piVar12 != *(int **)(param_1 + 0x60));

  }

  pvVar6 = *(void **)(*(int *)(param_1 + 0x60) + 4);

  if (*(char *)((int)pvVar6 + 0x19) == '\0') {

    FUN_005731c0(*(uint32_t /* width from decompiler */ *)((int)pvVar6 + 8));

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar6);

  }

  *(int *)(*(int *)(param_1 + 0x60) + 4) = *(int *)(param_1 + 0x60);

  *(uint32_t /* width from decompiler */ *)(param_1 + 100) = 0;

  *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(param_1 + 0x60) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x60);

  *(int *)(*(int *)(param_1 + 0x60) + 8) = *(int *)(param_1 + 0x60);

  return;

}
