// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryAddItem_008bf070
// -----------------------------------------------------------------------------
// Stable ID: aa_008bf070
// Callee of Named_CalleeOf_Client_RecvInventoryAddItem
// Address:   0x008bf070  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_RecvInventoryAddItem: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004104f0, FUN_008bee80, FUN_008bf070.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_RecvInventoryAddItem
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

void Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryAddItem_008bf070(void)



{

  int in_EAX;

  int unaff_ESI;

  

  if ((((DAT_00d1a8f0 != '\0') && (in_EAX != 0)) && (*(int *)(*(int *)(in_EAX + 0xa8) + 0x38) != 4))

     && (DAT_00d1a8dd == '\0')) {

    FUN_004104f0(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x510));

    FUN_008bee80();

  }

  return;

}
