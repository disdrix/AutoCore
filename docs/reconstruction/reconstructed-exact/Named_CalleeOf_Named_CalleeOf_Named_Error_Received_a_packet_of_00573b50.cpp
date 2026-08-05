// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Error_Received_a_packet_of_00573b50
// -----------------------------------------------------------------------------
// Stable ID: aa_00573b50
// Callee of Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d
// Address:   0x00573b50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, while×1.
//  - Notable callees: FUN_00573b50.
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Named_Error_Received_a_packet_of_00573b50(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  

  iVar2 = 0;

  while( true ) {

    if (*(int *)(param_1 + 0x28) == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = *(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x28) >> 2;

    }

    if (iVar1 <= iVar2) break;

    iVar1 = *(int *)(*(int *)(param_1 + 0x28) + iVar2 * 4);

    if ((*(int *)(iVar1 + 8) == param_2) && (*(int *)(iVar1 + 0xc) == param_3)) {

      return *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x28) + iVar2 * 4);

    }

    iVar2 = iVar2 + 1;

  }

  return 0;

}
