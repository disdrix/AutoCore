// =============================================================================
// Named_CalleeOf_CVOGReaction_GiveItemByCbid_0051ea10
// -----------------------------------------------------------------------------
// Stable ID: aa_0051ea10
// Callee of CVOGReaction_GiveItemByCbid
// Address:   0x0051ea10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGReaction_GiveItemByCbid: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00518940, FUN_0051ea10, FUN_005c82a0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGReaction_GiveItemByCbid
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_CVOGReaction_GiveItemByCbid_0051ea10(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a379f;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  if (param_2 != 0) {

    ExceptionList = &local_c;

    param_1[1] = &DAT_009da754;

    param_1[0x11] = &DAT_009de778;

    FUN_00518940();

    local_4 = 0;

  }

  FUN_005c82a0(0);

  *param_1 = &PTR_LAB_009ce814;

  param_1[0x10] = &PTR_FUN_009ce7d8;

  *(undefined ***)(*(int *)(param_1[1] + 4) + 4 + (int)param_1) = &PTR_LAB_009ce514;

  *(int *)(*(int *)(param_1[1] + 4) + (int)param_1) = *(int *)(param_1[1] + 4) + -0x10c;

  ExceptionList = local_c;

  return param_1;

}
