// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvInvento_0085f150
// -----------------------------------------------------------------------------
// Stable ID: aa_0085f150
// Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryEquip
// Address:   0x0085f150  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryEquip: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0085f150.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryEquip
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvInvento_0085f150(int *param_1)



{

  int in_EAX;

  int local_10;

  int local_c;

  int local_8;

  

  if (param_1 != (int *)0x0) {

    local_8 = param_1[0x126];

    local_10 = *(int *)(in_EAX + 0x50c) * local_8 + *(int *)(in_EAX + 0x504);

    local_c = *(int *)(in_EAX + 0x510) * param_1[0x127] + *(int *)(in_EAX + 0x508);

    (**(code **)(*param_1 + 0x118))(&local_10);

  }

  return;

}
