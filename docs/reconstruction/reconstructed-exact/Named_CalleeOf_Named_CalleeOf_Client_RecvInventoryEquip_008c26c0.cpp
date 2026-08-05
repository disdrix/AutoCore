// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryEquip_008c26c0
// -----------------------------------------------------------------------------
// Stable ID: aa_008c26c0
// Callee of Named_CalleeOf_Client_RecvInventoryEquip
// Address:   0x008c26c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_RecvInventoryEquip: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_008c26c0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_RecvInventoryEquip
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

void Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryEquip_008c26c0(void)



{

  int *piVar1;

  int iVar2;

  int in_EAX;

  

  piVar1 = *(int **)(in_EAX + 0x580);

  if (((piVar1 != (int *)0x0) && (iVar2 = piVar1[0x15d], iVar2 != 0)) &&

     (*(int *)(iVar2 + 0x2b0) != 0)) {

    (**(code **)(*piVar1 + 0xb0))(iVar2);

  }

  return;

}
