// =============================================================================
// Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_00808550
// -----------------------------------------------------------------------------
// Stable ID: aa_00808550
// Callee of Named_Error_Received_a_packet_of_unknown_type_d_d
// Address:   0x00808550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Error_Received_a_packet_of_unknown_type_d: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_007a47c0, FUN_00808550.
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

void __thiscall Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_00808550(int param_1,int param_2)



{

  *(int *)(param_1 + 0x10) = param_1 + 0x18;

  if (*(int *)(param_2 + 0x4ec) != 0) {

    FUN_007a47c0();

  }

  return;

}
