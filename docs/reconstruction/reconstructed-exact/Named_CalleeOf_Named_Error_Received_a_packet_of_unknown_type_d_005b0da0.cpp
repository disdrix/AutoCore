// =============================================================================
// Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_005b0da0
// -----------------------------------------------------------------------------
// Stable ID: aa_005b0da0
// Callee of Named_Error_Received_a_packet_of_unknown_type_d_d
// Address:   0x005b0da0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Error_Received_a_packet_of_unknown_type_d: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_005b0da0.
//  - Return sites: 3.

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

void __fastcall Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_005b0da0(int param_1)



{

  if (*(void **)(param_1 + 0x5c) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x5c));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c) = 0;

  if (*(void **)(param_1 + 0x60) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x60));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x60) = 0;

  return;

}
