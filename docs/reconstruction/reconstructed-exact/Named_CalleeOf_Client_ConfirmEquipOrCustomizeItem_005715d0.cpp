// =============================================================================
// Named_CalleeOf_Client_ConfirmEquipOrCustomizeItem_005715d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005715d0
// Callee of Client_ConfirmEquipOrCustomizeItem
// Address:   0x005715d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_ConfirmEquipOrCustomizeItem: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00570840, FUN_005715d0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Client_ConfirmEquipOrCustomizeItem
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

uint32_t /* width from decompiler */ Named_CalleeOf_Client_ConfirmEquipOrCustomizeItem_005715d0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  if (param_1 == 0) {

    return 0;

  }

  iVar1 = *(int *)(*(int *)(param_1 + 0xa8) + 0x3c);

  uVar2 = FUN_00570840(*(uint8_t *)(iVar1 + 0x406),*(uint8_t *)(iVar1 + 0x407),param_2,param_3

                       ,param_4);

  return uVar2;

}
