// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_008e5120
// -----------------------------------------------------------------------------
// Stable ID: aa_008e5120
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RefreshOpen
// Address:   0x008e5120  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RefreshOpen: callee helper. Evidence string: "allocatenewobjectfromcbid failed %d Get a programmer". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "allocatenewobjectfromcbid failed %d Get a programmer"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: if×10, do×3, while×3, return×3, goto×2.
//  - Notable callees: CVOGReaction_GiveItemByCbid, FUN_004f1e20, FUN_007a4480, FUN_008e5120.
//  - Strings: "allocatenewobjectfromcbid failed %d Get a programmer".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RefreshOpen
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_008e5120(uint *param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint uVar2;

  int in_EAX;

  int *piVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  

  iVar4 = 0;

  do {

    puVar1 = *(uint32_t /* width from decompiler */ **)(in_EAX + iVar4 * 4);

    if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)*puVar1)(1);

    }

    *(uint32_t /* width from decompiler */ *)(in_EAX + iVar4 * 4) = 0;

    iVar4 = iVar4 + 1;

  } while (iVar4 < 5);

  iVar4 = 0;

  if (param_2 < 1) {

    return;

  }

  iVar6 = in_EAX - (int)param_1;

  do {

    uVar2 = *param_1;

    if (uVar2 != 0xffffffff) {

      iVar5 = *(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b570 + 0xf10) + 0x10) +

                               (*(uint *)(*(int *)(DAT_00d1b570 + 0xf10) + 8) & uVar2) * 4) + 4);

      if (iVar5 == 0) {

LAB_008e5199:

        iVar5 = 0;

      }

      else {

        do {

          if (uVar2 == *(uint *)(iVar5 + 0x10)) {

            if (iVar5 == 0) goto LAB_008e5199;

            iVar5 = *(int *)(iVar5 + 8);

            goto LAB_008e51a0;

          }

          iVar5 = *(int *)(iVar5 + 0xc);

        } while (iVar5 != 0);

        iVar5 = 0;

      }

LAB_008e51a0:

      if ((iVar5 != 0) && (iVar4 < 5)) {

        if (*(int *)(iVar5 + 0x3c) == 0) {

          FUN_004f1e20(1,1);

        }

        piVar3 = (int *)CVOGReaction_GiveItemByCbid(*(int *)(iVar5 + 0x34));

        *(int **)(iVar6 + (int)param_1) = piVar3;

        if (piVar3 == (int *)0x0) {

          FUN_007a4480(1,"allocatenewobjectfromcbid failed %d Get a programmer",

                       *(uint32_t /* width from decompiler */ *)(iVar5 + 0x34));

          return;

        }

        (**(code **)(*piVar3 + 8))(*(uint32_t /* width from decompiler */ *)(iVar5 + 0x34),DAT_00d1b644,1);

      }

    }

    iVar4 = iVar4 + 1;

    param_1 = param_1 + 1;

    if (param_2 <= iVar4) {

      return;

    }

  } while( true );

}
