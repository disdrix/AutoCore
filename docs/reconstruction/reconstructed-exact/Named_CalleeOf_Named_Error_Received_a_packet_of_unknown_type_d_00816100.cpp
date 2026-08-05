// =============================================================================
// Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_00816100
// -----------------------------------------------------------------------------
// Stable ID: aa_00816100
// Callee of Named_Error_Received_a_packet_of_unknown_type_d_d
// Address:   0x00816100  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Error_Received_a_packet_of_unknown_type_d: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_007fc360, FUN_00816100, FUN_0092d900, FUN_009301b0, FUN_009492d0, FUN_0094c6d0.
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

void Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_00816100(void)



{

  int unaff_ESI;

  int unaff_EDI;

  

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc68) = 0;

  if (*(void **)(unaff_ESI + 0xc6c) != (void *)0x0) {

    operator_delete__(*(void **)(unaff_ESI + 0xc6c));

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc6c) = 0;

  FUN_0094c6d0();

  *(uint8_t *)(unaff_ESI + 0x9e) = 1;

  FUN_007fc360();

  FUN_009301b0();

  FUN_0092d900(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 4),unaff_ESI + 0x618);

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x71c) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 8);

  FUN_009492d0();

  return;

}
