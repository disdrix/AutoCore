// =============================================================================
// Named_CalleeOf_Client_RecvInventoryUsePaint_004faaf0
// -----------------------------------------------------------------------------
// Stable ID: aa_004faaf0
// Callee of Client_RecvInventoryUsePaint
// Address:   0x004faaf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_RecvInventoryUsePaint: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_004faaf0, FUN_00519a30.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Client_RecvInventoryUsePaint
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

void __thiscall Named_CalleeOf_Client_RecvInventoryUsePaint_004faaf0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1a8) = param_2;

  if (DAT_00b042b8 < 1) {

    FUN_00519a30();

  }

  if (*(int *)(param_1 + 0x1a8) < 0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x1a8) = 0;

    return;

  }

  if (DAT_00b042b8 <= *(int *)(param_1 + 0x1a8)) {

    *(int *)(param_1 + 0x1a8) = DAT_00b042b8;

  }

  return;

}
