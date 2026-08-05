// =============================================================================
// Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_0080b910
// -----------------------------------------------------------------------------
// Stable ID: aa_0080b910
// Callee of Named_Error_Received_a_packet_of_unknown_type_d_d
// Address:   0x0080b910  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Error_Received_a_packet_of_unknown_type_d: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×7, return×2, while×1.
//  - Notable callees: Client_GetMissionCompleteAudioTable, FUN_0066e8d0, FUN_0066e9c0, FUN_0080b910, FUN_00821570, FUN_00821940.
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_0080b910(void)



{

  int *piVar1;

  char cVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  int iVar6;

  int unaff_EBX;

  int unaff_EDI;

  uint32_t /* width from decompiler */ uVar7;

  

  if (*(int *)(unaff_EDI + 0xe98) == 0) {

    return 0;

  }

  iVar6 = *(int *)(unaff_EDI + 0xe98);

  iVar5 = *(int *)(*(int *)(iVar6 + 4) + 4);

  if ((*(int *)(iVar5 + 0x164 + iVar6) == *(int *)(unaff_EBX + 8)) &&

     (*(int *)(iVar5 + 0x168 + iVar6) == *(int *)(unaff_EBX + 0xc))) {

    cVar2 = FUN_0066e9c0();

    if (cVar2 != '\0') {

      FUN_0066e8d0();

    }

    puVar3 = (uint32_t /* width from decompiler */ *)Client_GetMissionCompleteAudioTable();

    FUN_00821940(*puVar3,unaff_EBX + 0x1c,*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xe04));

    uVar7 = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x10);

    uVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(unaff_EDI + 0xe98) + 4) + 4) + 4 +

                                 *(int *)(unaff_EDI + 0xe98)) + 0x160))(uVar7);

    FUN_00821570(*(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x18),*(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x14),uVar4,uVar7);

  }

  iVar6 = 0;

  while( true ) {

    if (*(int *)(unaff_EDI + 0xdf4) == 0) {

      iVar5 = 0;

    }

    else {

      iVar5 = *(int *)(unaff_EDI + 0xdf8) - *(int *)(unaff_EDI + 0xdf4) >> 2;

    }

    if (iVar5 <= iVar6) break;

    piVar1 = *(int **)(*(int *)(unaff_EDI + 0xdf4) + iVar6 * 4);

    if ((*piVar1 == *(int *)(unaff_EBX + 8)) && (piVar1[1] == *(int *)(unaff_EBX + 0xc))) {

      piVar1[2] = *(int *)(unaff_EBX + 0x18);

    }

    iVar6 = iVar6 + 1;

  }

  if (*(int *)(unaff_EDI + 0x10a0) != 0) {

    (**(code **)(**(int **)(unaff_EDI + 0x10a0) + 0x448))();

    (**(code **)(**(int **)(unaff_EDI + 0x10a0) + 0x34c))();

  }

  return 1;

}
