// =============================================================================
// Named_CalleeOf_Client_RecvInventoryEquip_004bafe0
// -----------------------------------------------------------------------------
// Stable ID: aa_004bafe0
// Callee of Client_RecvInventoryEquip (+3 other named callers)
// Address:   0x004bafe0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_RecvInventoryEquip: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Client_RecvInventoryEquip (+3 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: CVOGReaction_ResolveObjectTarget, FUN_004bafe0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Client_RecvInventoryEquip (+3 other named callers)
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

uint32_t /* width from decompiler */ Named_CalleeOf_Client_RecvInventoryEquip_004bafe0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int *piVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  piVar1 = (int *)CVOGReaction_ResolveObjectTarget(param_1,param_2,param_3);

  if (piVar1 != (int *)0x0) {

    uVar2 = (**(code **)(*piVar1 + 0x1d4))();

    return uVar2;

  }

  return 0;

}
