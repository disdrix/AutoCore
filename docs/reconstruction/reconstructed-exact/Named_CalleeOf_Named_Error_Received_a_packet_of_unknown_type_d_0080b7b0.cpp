// =============================================================================
// Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_0080b7b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0080b7b0
// Callee of Named_Error_Received_a_packet_of_unknown_type_d_d
// Address:   0x0080b7b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Error_Received_a_packet_of_unknown_type_d: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_0080b7b0, FUN_00869f10, FUN_0086a210.
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

void Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_0080b7b0(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  int in_EAX;

  int iVar2;

  int iVar3;

  

  uVar1 = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x10d0);

  FUN_0086a210();

  iVar3 = 0;

  if (0 < *(short *)(param_1 + 4)) {

    iVar2 = param_1 + 8;

    do {

      FUN_00869f10(uVar1,iVar2);

      iVar3 = iVar3 + 1;

      iVar2 = iVar2 + 0x338;

    } while (iVar3 < *(short *)(param_1 + 4));

  }

  return;

}
