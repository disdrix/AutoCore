// =============================================================================
// Named_CalleeOf_Client_ConfirmEquipOrCustomizeItem_00522020
// -----------------------------------------------------------------------------
// Stable ID: aa_00522020
// Callee of Client_ConfirmEquipOrCustomizeItem
// Address:   0x00522020  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_ConfirmEquipOrCustomizeItem: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×4, return×4.
//  - Notable callees: FUN_00522020.
//  - Return sites: 4.

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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Client_ConfirmEquipOrCustomizeItem_00522020(int param_1,int param_2)



{

  if (param_2 == 1) {

    if (*(int *)(param_1 + 0x250) != 0) {

      return *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x250) + 0x2b0);

    }

  }

  else {

    if (param_2 == 3) {

      return *(uint32_t /* width from decompiler */ *)(param_1 + 0xcbc);

    }

    if (param_2 == 5) {

      return *(uint32_t /* width from decompiler */ *)(param_1 + 0xce0);

    }

  }

  return 0;

}
