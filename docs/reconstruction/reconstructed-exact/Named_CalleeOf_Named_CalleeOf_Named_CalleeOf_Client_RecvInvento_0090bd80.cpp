// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvInvento_0090bd80
// -----------------------------------------------------------------------------
// Stable ID: aa_0090bd80
// Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryAddItem
// Address:   0x0090bd80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryAddItem: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0040fd60, FUN_0090b9c0, FUN_0090bd80.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryAddItem
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvInvento_0090bd80(void)



{

  char cVar1;

  int *unaff_ESI;

  

  if (unaff_ESI[0x14f] == 0) {

    cVar1 = (**(code **)(*unaff_ESI + 0xd0))();

    if (cVar1 != '\x01') {

      FUN_0090b9c0();

      return;

    }

  }

  FUN_0040fd60(&stack0x00000004);

  return;

}
