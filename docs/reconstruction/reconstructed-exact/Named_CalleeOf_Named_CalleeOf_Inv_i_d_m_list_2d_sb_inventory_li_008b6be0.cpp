// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Inv_i_d_m_list_2d_sb_inventory_li_008b6be0
// -----------------------------------------------------------------------------
// Stable ID: aa_008b6be0
// Callee of Named_CalleeOf_Inv_i_d_m_list_2d_sb_inventory_list_xml
// Address:   0x008b6be0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Inv_i_d_m_list_2d_sb_inventory_list_xml: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: if×13, do×1, while×1, return×1.
//  - Notable callees: FUN_008b6590, FUN_008b6be0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Inv_i_d_m_list_2d_sb_inventory_list_xml
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

void Named_CalleeOf_Named_CalleeOf_Inv_i_d_m_list_2d_sb_inventory_li_008b6be0(uint param_1,uint param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int in_EAX;

  uint uVar4;

  uint uVar5;

  int iVar6;

  

  iVar3 = DAT_00d1ad2c;

  iVar6 = 0;

  if (0 < *(int *)(in_EAX + 0x520)) {

    do {

      iVar1 = *(int *)(iVar3 + 8);

      if (iVar1 == 0) {

        uVar4 = 0;

      }

      else {

        uVar4 = *(int *)(iVar3 + 0xc) - iVar1 >> 2;

      }

      uVar5 = *(int *)(in_EAX + 0x52c) + iVar6;

      if (uVar5 < uVar4) {

        if (((param_1 & param_2) == 0xffffffff) ||

           ((iVar2 = *(int *)(iVar1 + uVar5 * 4), *(uint *)(iVar2 + 0x1f0) == param_1 &&

            (*(uint *)(iVar2 + 500) == param_2)))) {

          FUN_008b6590(iVar6,*(uint32_t /* width from decompiler */ *)(iVar1 + uVar5 * 4));

        }

      }

      else {

        if (*(int *)(*(int *)(in_EAX + 0x53c) + iVar6 * 4) != 0) {

          (**(code **)(**(int **)(*(int *)(in_EAX + 0x53c) + iVar6 * 4) + 4))(0);

        }

        if (*(int *)(*(int *)(in_EAX + 0x540) + iVar6 * 4) != 0) {

          (**(code **)(**(int **)(*(int *)(in_EAX + 0x540) + iVar6 * 4) + 4))(0);

        }

        if (*(int *)(*(int *)(in_EAX + 0x544) + iVar6 * 4) != 0) {

          (**(code **)(**(int **)(*(int *)(in_EAX + 0x544) + iVar6 * 4) + 4))(0);

        }

        if (*(int *)(*(int *)(in_EAX + 0x54c) + iVar6 * 4) != 0) {

          (**(code **)(**(int **)(*(int *)(in_EAX + 0x54c) + iVar6 * 4) + 4))(0);

        }

        if (*(int *)(*(int *)(in_EAX + 0x550) + iVar6 * 4) != 0) {

          (**(code **)(**(int **)(*(int *)(in_EAX + 0x550) + iVar6 * 4) + 4))(0);

        }

        if (*(int *)(*(int *)(in_EAX + 0x554) + iVar6 * 4) != 0) {

          (**(code **)(**(int **)(*(int *)(in_EAX + 0x554) + iVar6 * 4) + 4))(0);

        }

        if (*(int *)(*(int *)(in_EAX + 0x55c) + iVar6 * 4) != 0) {

          (**(code **)(**(int **)(*(int *)(in_EAX + 0x55c) + iVar6 * 4) + 4))(0);

        }

        if (*(int *)(*(int *)(in_EAX + 0x548) + iVar6 * 4) != 0) {

          (**(code **)(**(int **)(*(int *)(in_EAX + 0x548) + iVar6 * 4) + 4))(0);

        }

        if (*(int *)(*(int *)(in_EAX + 0x558) + iVar6 * 4) != 0) {

          (**(code **)(**(int **)(*(int *)(in_EAX + 0x558) + iVar6 * 4) + 4))(0);

        }

      }

      iVar6 = iVar6 + 1;

    } while (iVar6 < *(int *)(in_EAX + 0x520));

  }

  return;

}
