// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Error_Receiv_0066e8a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0066e8a0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_Error_Received_a_packet_of
// Address:   0x0066e8a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_Error_Received_a_packet_of: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0066e8a0, FUN_0066fb10.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_Error_Received_a_packet_of
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

uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Error_Receiv_0066e8a0(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  

  if (*(int *)(param_1 + 4) == 0) {

    return 0xffffffff;

  }

  uVar1 = FUN_0066fb10();

  return uVar1;

}
