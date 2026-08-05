// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryAddItem_007fe720
// -----------------------------------------------------------------------------
// Stable ID: aa_007fe720
// Callee of Named_CalleeOf_Client_RecvInventoryAddItem
// Address:   0x007fe720  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_RecvInventoryAddItem: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~76 non-empty decompiler lines.
//  - Control keywords: if×16, return×7, do×1, while×1.
//  - Notable callees: FUN_0040fd60, FUN_007fe720, FUN_0090b9c0, FUN_0090bd80.
//  - Return sites: 7.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_RecvInventoryAddItem
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

void Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryAddItem_007fe720(int param_1,int param_2,char param_3,char param_4)



{

  int *piVar1;

  bool bVar2;

  char cVar3;

  uint uVar4;

  int iVar5;

  uint uVar6;

  

  if (*(int *)(param_1 + 0xf38) == 0) {

    return;

  }

  cVar3 = (**(code **)(**(int **)(param_1 + 0xf38) + 0x3d8))();

  if (cVar3 == '\0') {

    return;

  }

  if (*(int *)(*(int *)(param_1 + 0xf38) + 0xcb4) == 0) {

    return;

  }

  cVar3 = (**(code **)(**(int **)(*(int *)(param_1 + 0xf38) + 0xcb4) + 0x3d8))();

  if (cVar3 != '\0') {

    if (param_3 != '\0') {

      piVar1 = *(int **)(*(int *)(param_1 + 0xf38) + 0xcb4);

      cVar3 = (**(code **)(*piVar1 + 0x3d8))();

      if ((cVar3 != '\0') && (cVar3 = (**(code **)(*piVar1 + 0xd0))(), cVar3 != '\0')) {

        if (piVar1[0x150] == param_2) {

          return;

        }

        uVar6 = 0;

        bVar2 = false;

        if (piVar1[0x14f] != 0) {

          do {

            uVar4 = (uint)piVar1[0x14e] >> 2;

            iVar5 = uVar4 * -4;

            if ((uint)piVar1[0x14d] <= uVar4) {

              uVar4 = uVar4 - piVar1[0x14d];

            }

            if (*(int *)(*(int *)(piVar1[0x14c] + uVar4 * 4) + (piVar1[0x14e] + iVar5) * 4) ==

                param_2) {

              bVar2 = true;

            }

            uVar4 = (uint)piVar1[0x14e] >> 2;

            iVar5 = uVar4 * -4;

            if ((uint)piVar1[0x14d] <= uVar4) {

              uVar4 = uVar4 - piVar1[0x14d];

            }

            FUN_0040fd60(*(int *)(piVar1[0x14c] + uVar4 * 4) + (piVar1[0x14e] + iVar5) * 4);

            if (piVar1[0x14f] != 0) {

              piVar1[0x14e] = piVar1[0x14e] + 1;

              if ((uint)(piVar1[0x14d] * 4) <= (uint)piVar1[0x14e]) {

                piVar1[0x14e] = 0;

              }

              iVar5 = piVar1[0x14f] + -1;

              piVar1[0x14f] = iVar5;

              if (iVar5 == 0) {

                piVar1[0x14e] = 0;

              }

            }

            uVar6 = uVar6 + 1;

          } while (uVar6 < (uint)piVar1[0x14f]);

          if (bVar2) {

            return;

          }

        }

      }

    }

    if (param_4 == '\x01') {

      FUN_0090b9c0();

    }

    else {

      FUN_0090bd80(param_2);

    }

    (**(code **)(**(int **)(*(int *)(param_1 + 0xf38) + 0xcb4) + 0x94))();

    return;

  }

  return;

}
