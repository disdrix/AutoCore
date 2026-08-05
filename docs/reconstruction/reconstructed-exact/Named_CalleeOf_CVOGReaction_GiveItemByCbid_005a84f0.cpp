// =============================================================================
// Named_CalleeOf_CVOGReaction_GiveItemByCbid_005a84f0
// -----------------------------------------------------------------------------
// Stable ID: aa_005a84f0
// Callee of CVOGReaction_GiveItemByCbid
// Address:   0x005a84f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGReaction_GiveItemByCbid: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00518940, FUN_005a84f0, FUN_005c7f30, _eh_vector_constructor_iterator_.
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_CVOGReaction_GiveItemByCbid_005a84f0(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  if (param_2 != 0) {

    param_1[1] = &DAT_009d86f0;

    FUN_00518940();

  }

  FUN_005c7f30(0);

  *param_1 = &PTR_FUN_009d86b8;

  *(undefined ***)(*(int *)(param_1[1] + 4) + 4 + (int)param_1) = &PTR_LAB_009d83f4;

  *(int *)(*(int *)(param_1[1] + 4) + (int)param_1) = *(int *)(param_1[1] + 4) + -0x15c;

  param_1[0x49] = 0;

  param_1[0x4a] = 0;

  param_1[0x4b] = 0;

  _eh_vector_constructor_iterator_(param_1 + 0x4c,0x10,2,FUN_004565f0,FUN_00691630);

  *(uint8_t *)(param_1 + 0x2c) = 0;

  *(uint8_t *)(param_1 + 0x33) = 0;

  param_1[0x3a] = 0;

  param_1[0x3b] = 0;

  param_1[0x3c] = 0;

  *(uint8_t *)(param_1 + 0x47) = 1;

  param_1[0x3f] = 0;

  param_1[0x40] = 0;

  param_1[0x41] = 0;

  param_1[0x42] = 0;

  param_1[0x43] = 0;

  param_1[0x44] = 0;

  param_1[0x45] = 0;

  param_1[0x46] = 0;

  return param_1;

}
