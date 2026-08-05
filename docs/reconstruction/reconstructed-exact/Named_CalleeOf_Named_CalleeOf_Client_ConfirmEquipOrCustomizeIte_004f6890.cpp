// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_ConfirmEquipOrCustomizeIte_004f6890
// -----------------------------------------------------------------------------
// Stable ID: aa_004f6890
// Callee of Named_CalleeOf_Client_ConfirmEquipOrCustomizeItem
// Address:   0x004f6890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_ConfirmEquipOrCustomizeItem: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: return×5, if×4.
//  - Notable callees: FUN_004ce5f0, FUN_004f6890.
//  - Return sites: 5.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_ConfirmEquipOrCustomizeItem
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Client_ConfirmEquipOrCustomizeIte_004f6890(int param_1,int param_2,int *param_3)



{

  int iVar1;

  char cVar2;

  

  if (param_2 == 0) {

    return 8;

  }

  cVar2 = FUN_004ce5f0(param_1);

  if (cVar2 == '\0') {

    return 1;

  }

  if (*(char *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) +

               0x4c0) !=

      *(char *)(*(int *)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xac + param_2) + 0x3c) +

               0x4ce)) {

    return 7;

  }

  iVar1 = *(int *)(param_1 + 600);

  if (((iVar1 != 0) && (param_3 != (int *)0x0)) &&

     (iVar1 = *(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1, *param_3 = iVar1,

     iVar1 == *(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2)) {

    return 3;

  }

  return 0;

}
