// =============================================================================
// Named_CalleeOf_Client_RecvInventoryDropResponse_0085e890
// -----------------------------------------------------------------------------
// Stable ID: aa_0085e890
// Callee of Client_RecvInventoryDropResponse
// Address:   0x0085e890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_RecvInventoryDropResponse: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0085e890.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_RecvInventoryDropResponse
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

void __fastcall Named_CalleeOf_Client_RecvInventoryDropResponse_0085e890(int *param_1)



{

  int iVar1;

  

  iVar1 = param_1[0x15d];

  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x2b0) != 0)) {

    (**(code **)(*param_1 + 0xb0))(iVar1);

  }

  return;

}
