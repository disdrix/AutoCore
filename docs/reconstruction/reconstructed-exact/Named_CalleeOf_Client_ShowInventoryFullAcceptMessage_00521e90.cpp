// =============================================================================
// Named_CalleeOf_Client_ShowInventoryFullAcceptMessage_00521e90
// -----------------------------------------------------------------------------
// Stable ID: aa_00521e90
// Callee of Client_ShowInventoryFullAcceptMessage
// Address:   0x00521e90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_ShowInventoryFullAcceptMessage: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~6 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00521e90, FUN_00572360.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_ShowInventoryFullAcceptMessage
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

bool __fastcall Named_CalleeOf_Client_ShowInventoryFullAcceptMessage_00521e90(int param_1)



{

  char cVar1;

  

  cVar1 = FUN_00572360(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x250) + 0x2b0),1);

  return cVar1 != '\0';

}
