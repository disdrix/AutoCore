// =============================================================================
// Named_CalleeOf_Client_RecvInventoryAddItem_00513e70
// -----------------------------------------------------------------------------
// Stable ID: aa_00513e70
// Callee of Client_RecvInventoryAddItem
// Address:   0x00513e70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_RecvInventoryAddItem: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00513e70.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Client_RecvInventoryAddItem
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

uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_Client_RecvInventoryAddItem_00513e70(int param_1)



{

  if ((((*(byte *)(*(int *)(*(int *)(param_1 + 0xa8) + 0x3c) + 0x3f2) & 0x40) == 0) ||

      ((*(uint *)(param_1 + 0x17c) >> 0x13 & 1) != 0)) &&

     (*(int *)(*(int *)(param_1 + 0xa8) + 0x38) != 4)) {

    return 0;

  }

  return 1;

}
