// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryEquip_00569d50
// -----------------------------------------------------------------------------
// Stable ID: aa_00569d50
// Callee of Named_CalleeOf_Client_RecvInventoryEquip
// Address:   0x00569d50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_RecvInventoryEquip: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00569d50.
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryEquip_00569d50(int param_1)



{

  if (*(char *)(param_1 + 0xc5) != '\0') {

    *(uint8_t *)(param_1 + 0xc5) = 0;

    (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x104))(0);

    if (*(uint32_t /* width from decompiler */ **)(param_1 + 0xc0) != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0xc0))(1);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc0) = 0;

  }

  return;

}
