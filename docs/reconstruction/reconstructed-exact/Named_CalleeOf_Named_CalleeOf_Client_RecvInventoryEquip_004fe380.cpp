// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryEquip_004fe380
// -----------------------------------------------------------------------------
// Stable ID: aa_004fe380
// Callee of Named_CalleeOf_Client_RecvInventoryEquip
// Address:   0x004fe380  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_RecvInventoryEquip: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~103 non-empty decompiler lines.
//  - Control keywords: if×14, do×3, while×3, goto×2, return×1.
//  - Notable callees: CONCAT31×4, FUN_00508c00×2, FUN_00508c50×2, FUN_004ce940, FUN_004f1e20, FUN_004fe380.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_RecvInventoryEquip
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryEquip_004fe380(int param_1,int *param_2)



{

  uint16_t uVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint uVar6;

  uint uVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint unaff_retaddr;

  uint uStack_4;

  

  piVar3 = *(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1);

  if (((piVar3 != (int *)0x0) && (iVar2 = (**(code **)(*piVar3 + 0x1dc))(), iVar2 != 0)) &&

     (param_2 != (int *)0x0)) {

    FUN_004ce940();

    iVar2 = (**(code **)(*param_2 + 0x60))();

    if (iVar2 != 0) {

      do {

        uVar1 = (**(code **)(*param_2 + 0x5c))(0);

        piVar3 = (int *)FUN_00508c00(uVar1);

        uVar1 = (**(code **)(*param_2 + 0x5c))(0);

        piVar4 = (int *)FUN_00508c50(uVar1);

        if (((piVar3 != (int *)0x0) && (*(int *)(param_2[0x2a] + 0x3c) != 0)) &&

           (*(short *)(*(int *)(param_2[0x2a] + 0x3c) + 0x3f4) == 0xb)) {

          iVar2 = *piVar3;

          uVar5 = (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1) +

                              0x1dc))(CONCAT31((int3)((uint)*(int *)(param_1 + 4) >> 8),

                                               (char)unaff_retaddr == '\0'),1);

          (**(code **)(iVar2 + 4))(param_2,uVar5);

        }

        if (((piVar4 != (int *)0x0) && (*(int *)(param_2[0x2a] + 0x3c) != 0)) &&

           (*(short *)(*(int *)(param_2[0x2a] + 0x3c) + 0x3f4) == 10)) {

          iVar2 = *piVar4;

          uVar5 = (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1) +

                              0x1dc))(CONCAT31((int3)((uint)*(int *)(param_1 + 4) >> 8),

                                               (char)unaff_retaddr == '\0'),1);

          (**(code **)(iVar2 + 4))(param_2,uVar5);

        }

        uStack_4 = uStack_4 + 1;

        uVar6 = (**(code **)(*param_2 + 0x60))();

      } while (uStack_4 < uVar6);

    }

    uVar6 = 0;

    iVar2 = (**(code **)(*param_2 + 0x80))();

    if (iVar2 != 0) {

      do {

        iVar2 = DAT_00b041fc;

        uVar6 = (**(code **)(*param_2 + 0x7c))(uVar6);

        iVar2 = *(int *)(*(int *)(*(int *)(*(int *)(iVar2 + 0xf10) + 0x10) +

                                 (*(uint *)(*(int *)(iVar2 + 0xf10) + 8) & uVar6 & 0xffff) * 4) + 4)

        ;

        if (iVar2 == 0) {

LAB_004fe514:

          iVar2 = 0;

        }

        else {

          do {

            if ((uVar6 & 0xffff) == *(uint *)(iVar2 + 0x10)) {

              if (iVar2 == 0) goto LAB_004fe514;

              iVar2 = *(int *)(iVar2 + 8);

              goto LAB_004fe51b;

            }

            iVar2 = *(int *)(iVar2 + 0xc);

          } while (iVar2 != 0);

          iVar2 = 0;

        }

LAB_004fe51b:

        if (iVar2 != 0) {

          if (*(int *)(iVar2 + 0x3c) == 0) {

            FUN_004f1e20(1,1);

          }

          puVar8 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar2 + 0x3c) + 0x4c0);

          if (puVar8 != (uint32_t /* width from decompiler */ *)0x0) {

            piVar3 = (int *)FUN_00508c00(*puVar8);

            piVar4 = (int *)FUN_00508c50(*puVar8);

            if (piVar3 != (int *)0x0) {

              iVar2 = *(int *)(param_2[0x2a] + 0x3c);

              if ((iVar2 != 0) && (*(short *)(iVar2 + 0x3f4) == 0xb)) {

                iVar2 = *piVar3;

                uVar5 = (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1

                                               ) + 0x1dc))

                                  (CONCAT31((int3)((uint)param_2[0x2a] >> 8),1),1);

                (**(code **)(iVar2 + 4))(param_2,uVar5);

              }

            }

            if (((piVar4 != (int *)0x0) && (*(int *)(param_2[0x2a] + 0x3c) != 0)) &&

               (*(short *)(*(int *)(param_2[0x2a] + 0x3c) + 0x3f4) == 10)) {

              iVar2 = *piVar4;

              uVar5 = (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1)

                                  + 0x1dc))(CONCAT31((int3)((uint)*(int *)(param_1 + 4) >> 8),1),1);

              (**(code **)(iVar2 + 4))(param_2,uVar5);

            }

          }

        }

        uVar6 = unaff_retaddr + 1;

        uVar7 = (**(code **)(*param_2 + 0x80))();

        unaff_retaddr = uVar6;

      } while (uVar6 < uVar7);

    }

  }

  return;

}
