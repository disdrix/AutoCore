// =============================================================================
// Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_008119c0
// -----------------------------------------------------------------------------
// Stable ID: aa_008119c0
// Callee of Named_Error_Received_a_packet_of_unknown_type_d_d
// Address:   0x008119c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Error_Received_a_packet_of_unknown_type_d: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~85 non-empty decompiler lines.
//  - Control keywords: if×10, return×2, do×2, while×2, for×1, goto×1.
//  - Notable callees: FUN_00419880, FUN_004bb280, FUN_00574760, FUN_00574810, FUN_005752c0, FUN_008119c0, FUN_008e8c00, FUN_008ea880.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_Error_Received_a_packet_of_unknown_type_d_d
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_008119c0(int param_1,int param_2)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  char cVar4;

  int iVar5;

  uint uVar6;

  uint *puVar7;

  bool bVar8;

  uint32_t /* width from decompiler */ *local_c;

  int local_8;

  uint32_t /* width from decompiler */ *local_4;

  

  if (*(int *)(param_1 + 0xe98) == 0) {

    return 0;

  }

  iVar5 = FUN_004bb280(1,*(uint32_t /* width from decompiler */ *)(param_2 + 8),*(uint32_t /* width from decompiler */ *)(param_2 + 0xc));

  bVar8 = iVar5 == 0;

  if (bVar8) {

    FUN_0094bed0(*(uint32_t /* width from decompiler */ *)(param_2 + 8),*(uint32_t /* width from decompiler */ *)(param_2 + 0xc));

  }

  iVar5 = 0;

  puVar7 = (uint *)(param_2 + 0x10);

  do {

    if (bVar8) break;

    if (((*puVar7 & puVar7[1]) != 0xffffffff) &&

       (cVar4 = FUN_00574810(*puVar7,puVar7[1]), cVar4 == '\0')) {

      bVar8 = true;

    }

    iVar5 = iVar5 + 1;

    puVar7 = puVar7 + 2;

  } while (iVar5 < 4);

  FUN_005752c0(param_2);

  local_c = (uint32_t /* width from decompiler */ *)(param_2 + 0x344);

  local_8 = 0;

  do {

    iVar5 = FUN_00574760(local_8);

    if (iVar5 != 0) {

      for (uVar6 = 0;

          (*(int *)(param_1 + 0xdf4) != 0 &&

          (uVar6 < (uint)(*(int *)(param_1 + 0xdf8) - *(int *)(param_1 + 0xdf4) >> 2)));

          uVar6 = uVar6 + 1) {

        piVar1 = *(int **)(*(int *)(param_1 + 0xdf4) + uVar6 * 4);

        iVar2 = *(int *)(*(int *)(iVar5 + 4) + 4);

        if ((*piVar1 == *(int *)(iVar2 + 0x164 + iVar5)) &&

           (piVar1[1] == *(int *)(iVar2 + 0x168 + iVar5))) goto LAB_00811b65;

      }

      local_4 = operator_new(0x10);

      iVar2 = *(int *)(*(int *)(iVar5 + 4) + 4);

      *local_4 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x164 + iVar5);

      local_4[1] = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x168 + iVar5);

      *(uint8_t *)(local_4 + 3) = 0;

      local_4[2] = *local_c;

      *(uint8_t *)((int)local_4 + 0xd) = 1;

      iVar5 = *(int *)(param_1 + 0xdf4);

      if ((iVar5 == 0) ||

         ((uint)(*(int *)(param_1 + 0xdfc) - iVar5 >> 2) <=

          (uint)(*(int *)(param_1 + 0xdf8) - iVar5 >> 2))) {

        FUN_00419880(param_1 + 0xdf0,*(uint32_t /* width from decompiler */ *)(param_1 + 0xdf8),&local_4);

        bVar8 = true;

      }

      else {

        puVar3 = *(uint32_t /* width from decompiler */ **)(param_1 + 0xdf8);

        *puVar3 = local_4;

        *(uint32_t /* width from decompiler */ **)(param_1 + 0xdf8) = puVar3 + 1;

        bVar8 = true;

      }

    }

LAB_00811b65:

    local_c = local_c + 1;

    local_8 = local_8 + 1;

    if (3 < local_8) {

      if (bVar8) {

        FUN_0094cc00();

      }

      if (*(int *)(param_1 + 0x10a0) != 0) {

        FUN_008e8c00();

        FUN_008ea880();

        (**(code **)(**(int **)(param_1 + 0x10a0) + 0x448))();

        (**(code **)(**(int **)(param_1 + 0x10a0) + 0x34c))();

      }

      return 1;

    }

  } while( true );

}
