// =============================================================================
// Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_00808c80
// -----------------------------------------------------------------------------
// Stable ID: aa_00808c80
// Callee of Named_Error_Received_a_packet_of_unknown_type_d_d
// Address:   0x00808c80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Error_Received_a_packet_of_unknown_type_d: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, for×1.
//  - Notable callees: FUN_00573b50, FUN_00808c80.
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

void Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_00808c80(void)



{

  int in_EAX;

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int unaff_EBX;

  uint32_t /* width from decompiler */ *puVar3;

  

  puVar1 = (uint32_t /* width from decompiler */ *)FUN_00573b50(*(uint32_t /* width from decompiler */ *)(in_EAX + 0x10),*(uint32_t /* width from decompiler */ *)(in_EAX + 0x14))

  ;

  if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar3 = (uint32_t /* width from decompiler */ *)(in_EAX + 8);

    for (iVar2 = 0xe; iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar1 = *puVar3;

      puVar3 = puVar3 + 1;

      puVar1 = puVar1 + 1;

    }

    if (*(int **)(unaff_EBX + 0x1038) != (int *)0x0) {

                    /* WARNING: Could not recover jumptable at 0x00808cb5. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(**(int **)(unaff_EBX + 0x1038) + 0x448))();

      return;

    }

  }

  return;

}
