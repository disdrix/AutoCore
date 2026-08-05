// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvInvento_005c6720
// -----------------------------------------------------------------------------
// Stable ID: aa_005c6720
// Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryAddItem
// Address:   0x005c6720  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryAddItem: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_005c6720.
//  - Return sites: 3.

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

bool __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvInvento_005c6720(int param_1,int param_2)



{

  int *piVar1;

  int iVar2;

  

  if (((*(uint *)(param_1 + 0x18) & *(uint *)(param_1 + 0x1c)) == 0xffffffff) &&

     (iVar2 = *(int *)(*(int *)(param_2 + 4) + 4),

     (*(uint *)(iVar2 + 0x164 + param_2) & *(uint *)(iVar2 + 0x168 + param_2)) == 0xffffffff)) {

    return *(int *)(param_1 + 0x10) == param_2;

  }

  piVar1 = (int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0x164 + param_2);

  if ((*piVar1 == *(int *)(param_1 + 0x18)) &&

     ((piVar1[1] == *(int *)(param_1 + 0x1c) && ((char)piVar1[2] == *(char *)(param_1 + 0x20))))) {

    return true;

  }

  return false;

}
