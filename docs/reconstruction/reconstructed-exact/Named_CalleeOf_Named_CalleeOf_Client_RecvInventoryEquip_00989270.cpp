// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryEquip_00989270
// -----------------------------------------------------------------------------
// Stable ID: aa_00989270
// Callee of Named_CalleeOf_Client_RecvInventoryEquip (+1 other named callers)
// Address:   0x00989270  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_RecvInventoryEquip: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Client_RecvInventoryEquip (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, while×1.
//  - Notable callees: FUN_00989270.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_RecvInventoryEquip (+1 other named callers)
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryEquip_00989270(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  

  puVar1 = (uint32_t /* width from decompiler */ *)**(uint32_t /* width from decompiler */ **)(param_1 + 0xc);

  while( true ) {

    if (puVar1 == *(uint32_t /* width from decompiler */ **)(param_1 + 0xc)) {

      return (uint32_t /* width from decompiler */ *)0x0;

    }

    if (*(int *)(puVar1[2] + 8) == param_2) break;

    puVar1 = (uint32_t /* width from decompiler */ *)*puVar1;

  }

  return puVar1 + 2;

}
