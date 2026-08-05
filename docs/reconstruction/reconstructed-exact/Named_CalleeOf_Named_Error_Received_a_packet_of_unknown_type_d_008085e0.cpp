// =============================================================================
// Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_008085e0
// -----------------------------------------------------------------------------
// Stable ID: aa_008085e0
// Callee of Named_Error_Received_a_packet_of_unknown_type_d_d
// Address:   0x008085e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Error_Received_a_packet_of_unknown_type_d: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, for×1, while×1, return×1.
//  - Notable callees: FUN_00573dc0, FUN_00574270, FUN_008085e0.
//  - Return sites: 1.

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

void Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_008085e0(int param_1,int param_2)



{

  int *piVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  

  piVar1 = *(int **)(param_1 + 0x1038);

  FUN_00573dc0();

  iVar4 = 0;

  if (0 < *(int *)(param_2 + 4)) {

    puVar5 = (uint32_t /* width from decompiler */ *)(param_2 + 8);

    do {

      puVar2 = operator_new(0x38);

      puVar6 = puVar5;

      puVar7 = puVar2;

      for (iVar3 = 0xe; iVar3 != 0; iVar3 = iVar3 + -1) {

        *puVar7 = *puVar6;

        puVar6 = puVar6 + 1;

        puVar7 = puVar7 + 1;

      }

      FUN_00574270(puVar2);

      iVar4 = iVar4 + 1;

      puVar5 = puVar5 + 0xe;

    } while (iVar4 < *(int *)(param_2 + 4));

  }

  (**(code **)(*piVar1 + 0x448))();

  *(uint8_t *)(param_1 + 0x31e9) = 0;

  return;

}
