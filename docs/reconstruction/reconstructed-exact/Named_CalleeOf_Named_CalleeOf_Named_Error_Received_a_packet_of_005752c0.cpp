// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Error_Received_a_packet_of_005752c0
// -----------------------------------------------------------------------------
// Stable ID: aa_005752c0
// Callee of Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d
// Address:   0x005752c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: Client_LookupObjectByTfid_Inferred, FUN_00512160, FUN_00520330, FUN_00575200, FUN_005752c0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_Error_Received_a_packet_of_005752c0(int param_1,int param_2)



{

  void *pvVar1;

  int iVar2;

  uint *puVar3;

  uint *puVar4;

  

  FUN_00575200();

  FUN_00512160(*(uint32_t /* width from decompiler */ *)(param_2 + 8),*(uint32_t /* width from decompiler */ *)(param_2 + 0xc),1);

  *(int *)(param_1 + 0x194) = (int)*(char *)(param_2 + 0x30);

  puVar4 = (uint *)(param_1 + 0x198);

  puVar3 = (uint *)(param_2 + 0x10);

  iVar2 = 4;

  do {

    *puVar4 = *puVar3;

    puVar4[1] = puVar3[1];

    pvVar1 = Client_LookupObjectByTfid_Inferred(1,*puVar3,puVar3[1]);

    puVar4[2] = (uint)pvVar1;

    if (pvVar1 != (void *)0x0) {

      FUN_00520330(param_1);

    }

    if ((*puVar4 & puVar4[1]) != 0xffffffff) {

      *(char *)(param_1 + 0x1d8) = *(char *)(param_1 + 0x1d8) + '\x01';

    }

    puVar3 = puVar3 + 2;

    puVar4 = puVar4 + 4;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  return;

}
