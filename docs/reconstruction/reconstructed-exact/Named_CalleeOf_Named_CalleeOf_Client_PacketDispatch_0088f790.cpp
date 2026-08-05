// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch_0088f790
// -----------------------------------------------------------------------------
// Stable ID: aa_0088f790
// Callee of Named_CalleeOf_Client_PacketDispatch
// Address:   0x0088f790  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_PacketDispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00860700, FUN_0088f790, FUN_008c0d10.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_PacketDispatch
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

void Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch_0088f790(void)



{

  int unaff_EDI;

  

  if (*(int *)(unaff_EDI + 0x5ac) != 0) {

    FUN_00860700();

  }

  if (*(int *)(unaff_EDI + 0x5b0) != 0) {

    FUN_008c0d10();

    return;

  }

  return;

}
