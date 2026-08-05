// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_ConfirmEquipOrCustomizeIte_004f6560
// -----------------------------------------------------------------------------
// Stable ID: aa_004f6560
// Callee of Named_CalleeOf_Client_ConfirmEquipOrCustomizeItem
// Address:   0x004f6560  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_ConfirmEquipOrCustomizeItem: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, do×1, goto×1, while×1.
//  - Notable callees: CONCAT31×2, FUN_004f6560.
//  - Return sites: 3.

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

uint __fastcall Named_CalleeOf_Named_CalleeOf_Client_ConfirmEquipOrCustomizeIte_004f6560(int param_1)



{

  uint uVar1;

  int iVar2;

  int *piVar3;

  

  uVar1 = *(uint *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1);

  if (*(char *)(uVar1 + 0x7e) != '\0') {

    return uVar1 & 0xffffff00;

  }

  piVar3 = *(int **)(param_1 + 0x260);

  iVar2 = 0;

  do {

    if (*piVar3 != 0) goto LAB_004f65d2;

    iVar2 = iVar2 + 1;

    piVar3 = piVar3 + 1;

  } while (iVar2 < 3);

  if (((*(int *)(param_1 + 0x264) == 0) &&

      (((iVar2 = *(int *)(param_1 + 600), iVar2 == 0 || (*(char *)(iVar2 + 0xcc) != '\0')) &&

       (*(int *)(param_1 + 0x254) == 0)))) &&

     ((*(int *)(param_1 + 0x268) == 0 && (*(int *)(param_1 + 0x270) == 0)))) {

    return CONCAT31((int3)((uint)iVar2 >> 8),*(int *)(param_1 + 0x26c) != 0);

  }

LAB_004f65d2:

  return CONCAT31((int3)((uint)iVar2 >> 8),1);

}
