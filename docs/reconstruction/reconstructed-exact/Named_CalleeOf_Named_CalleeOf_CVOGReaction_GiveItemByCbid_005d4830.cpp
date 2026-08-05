// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGReaction_GiveItemByCbid_005d4830
// -----------------------------------------------------------------------------
// Stable ID: aa_005d4830
// Callee of Named_CalleeOf_CVOGReaction_GiveItemByCbid
// Address:   0x005d4830  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGReaction_GiveItemByCbid: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00518940, FUN_0053cdc0, FUN_00581330, FUN_005d4830.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGReaction_GiveItemByCbid
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

int __thiscall Named_CalleeOf_Named_CalleeOf_CVOGReaction_GiveItemByCbid_005d4830(int param_1,int param_2)



{

  uint *puVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a709a;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  if (param_2 != 0) {

    ExceptionList = &local_c;

    *(undefined **)(param_1 + 4) = &DAT_009dd760;

    *(undefined **)(param_1 + 0x44) = &DAT_009dac4c;

    FUN_00518940();

    local_4 = 0;

  }

  FUN_0053cdc0(0);

  local_4 = 1;

  FUN_00581330(0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xbc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc0) = 0;

  puVar1 = (uint *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x180 + param_1);

  *puVar1 = *puVar1 | 0x40;

  puVar1 = (uint *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x180 + param_1);

  *puVar1 = *puVar1 | 0x20;

  ExceptionList = local_c;

  return param_1;

}
