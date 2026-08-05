// =============================================================================
// Named_CalleeOf_CVOGReaction_GiveItemByCbid_005dbfa0
// -----------------------------------------------------------------------------
// Stable ID: aa_005dbfa0
// Callee of CVOGReaction_GiveItemByCbid
// Address:   0x005dbfa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGReaction_GiveItemByCbid: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00518940, FUN_005d4830, FUN_005dbfa0.
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_CVOGReaction_GiveItemByCbid_005dbfa0(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a72e5;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  if (param_2 != 0) {

    ExceptionList = &local_c;

    param_1[1] = &DAT_009db9ac;

    param_1[0x11] = &DAT_009db9a4;

    FUN_00518940();

    local_4 = 0;

  }

  FUN_005d4830(0);

  *param_1 = &PTR_LAB_009db924;

  param_1[0x10] = &PTR_FUN_009db8e8;

  *(undefined ***)(*(int *)(param_1[1] + 4) + 4 + (int)param_1) = &PTR_LAB_009db624;

  *(int *)(*(int *)(param_1[1] + 4) + (int)param_1) = *(int *)(param_1[1] + 4) + -0x1bc;

  param_1[0x34] = 0;

  param_1[0x35] = 0;

  param_1[0x36] = 0;

  *(uint8_t *)(param_1 + 0x37) = 0;

  *(uint8_t *)((int)param_1 + 0xdd) = 1;

  *(uint8_t *)((int)param_1 + 0xde) = 0;

  *(uint8_t *)((int)param_1 + 0xdf) = 0;

  *(uint8_t *)(param_1 + 0x38) = 0;

  *(uint8_t *)((int)param_1 + 0xe1) = 1;

  *(uint8_t *)((int)param_1 + 0xe2) = 1;

  param_1[0x4a] = 0;

  param_1[0x4b] = 0;

  param_1[0x4c] = 0;

  param_1[0x4e] = 0;

  param_1[0x4f] = 0;

  param_1[0x50] = 0;

  param_1[0x52] = 0;

  param_1[0x53] = 0;

  param_1[0x54] = 0;

  param_1[0x55] = 0;

  param_1[0x56] = 0;

  param_1[0x57] = 0xffffffff;

  *(uint8_t *)(param_1 + 0x58) = 1;

  param_1[0x5a] = 0;

  param_1[0x5b] = 0;

  param_1[0x5c] = 0;

  param_1[0x5e] = 0xffffffff;

  param_1[0x5f] = 0xffffffff;

  param_1[0x60] = 0xffffffff;

  param_1[0x61] = 0xffffffff;

  param_1[99] = 0xffffffff;

  *(uint8_t *)((int)param_1 + 0x18a) = 0;

  *(uint8_t *)((int)param_1 + 0x18b) = 0;

  param_1[100] = 0;

  param_1[0x65] = 0;

  param_1[0x66] = 0;

  *(uint8_t *)(param_1 + 0x62) = 1;

  *(uint8_t *)((int)param_1 + 0x189) = 1;

  param_1[0x68] = 0;

  param_1[0x69] = 0;

  param_1[0x6a] = 0;

  *(uint8_t *)((int)param_1 + 0xe3) = 0;

  puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1[1] + 4) + 0x84 + (int)param_1);

  *puVar1 = 0;

  puVar1[1] = 0;

  puVar1[2] = 0;

  puVar1[3] = 0;

  ExceptionList = local_c;

  return param_1;

}
