// =============================================================================
// Named_CalleeOf_Client_RecvInventoryEquip_0092f120
// -----------------------------------------------------------------------------
// Stable ID: aa_0092f120
// Callee of Client_RecvInventoryEquip (+1 other named callers)
// Address:   0x0092f120  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_RecvInventoryEquip: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Client_RecvInventoryEquip (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_004962b0, FUN_0092f120.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Client_RecvInventoryEquip (+1 other named callers)
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

void Named_CalleeOf_Client_RecvInventoryEquip_0092f120(void)



{

  int in_EAX;

  

  if ((*(int *)(in_EAX + 0xe04) != 0) && (*(int *)(*(int *)(in_EAX + 0xe04) + 0xe898) != 0)) {

    FUN_004962b0();

    return;

  }

  return;

}
