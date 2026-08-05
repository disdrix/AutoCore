// =============================================================================
// Named_CalleeOf_CVOGReaction_GiveItemByCbid_0056e730
// -----------------------------------------------------------------------------
// Stable ID: aa_0056e730
// Callee of CVOGReaction_GiveItemByCbid
// Address:   0x0056e730  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGReaction_GiveItemByCbid: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~82 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00518940, FUN_0056e4e0, FUN_0056e730, FUN_005c7f30, InitializeCriticalSection.
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_CVOGReaction_GiveItemByCbid_0056e730(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  float fVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a4e59;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  if (param_2 != 0) {

    ExceptionList = &local_c;

    param_1[1] = &DAT_009dde20;

    FUN_00518940();

    local_4 = 0;

  }

  FUN_005c7f30(0);

  uVar2 = DAT_00aaa668;

  fVar1 = g_flOne;

  *param_1 = &PTR_LAB_009d32d4;

  *(undefined ***)(*(int *)(param_1[1] + 4) + 4 + (int)param_1) = &PTR_LAB_009d300c;

  *(int *)(*(int *)(param_1[1] + 4) + (int)param_1) = *(int *)(param_1[1] + 4) + -0x14c;

  param_1[0x37] = uVar2;

  local_4 = 1;

  *(uint8_t *)((int)param_1 + 0xc5) = 0;

  *(uint8_t *)((int)param_1 + 0xc6) = 0;

  *(uint8_t *)((int)param_1 + 199) = 0;

  *(uint8_t *)(param_1 + 0x32) = 0;

  *(uint8_t *)((int)param_1 + 0xc9) = 0;

  *(uint8_t *)((int)param_1 + 0xca) = 0;

  *(uint8_t *)((int)param_1 + 0xcb) = 0;

  *(uint8_t *)(param_1 + 0x33) = 0;

  param_1[0x34] = 0;

  *(uint16_t *)(param_1 + 0x35) = 0;

  *(uint16_t *)((int)param_1 + 0xd6) = 0;

  param_1[0x38] = 0;

  param_1[0x39] = 0;

  param_1[0x3a] = 0;

  param_1[0x3b] = fVar1;

  param_1[0x3f] = 0;

  param_1[0x40] = 0;

  param_1[0x41] = 0;

  param_1[0x42] = 0;

  *(uint16_t *)(param_1 + 0x43) = 0;

  param_1[0x44] = 0;

  param_1[0x45] = 0;

  *(uint16_t *)(param_1 + 0x46) = 0;

  param_1[0x47] = 0;

  param_1[0x48] = 0;

  param_1[0x4f] = 0;

  param_1[0x3c] = 0;

  param_1[0x3d] = 0;

  param_1[0x3e] = 0;

  puVar3 = operator_new(0x2c);

  if (puVar3 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar3 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *puVar3 = &PTR_FUN_009d2f90;

    puVar3[8] = 0;

    puVar3[7] = 0;

    puVar3[9] = 0;

    *(uint8_t *)(puVar3 + 10) = 0;

    InitializeCriticalSection((LPCRITICAL_SECTION)(puVar3 + 1));

    *puVar3 = &PTR_FUN_009d3344;

  }

  param_1[0x4f] = puVar3;

  if (DAT_00b047b0 == '\0') {

    FUN_0056e4e0();

  }

  *(uint8_t *)(param_1 + 0x2c) = 0;

  *(uint8_t *)((int)param_1 + 0xb1) = 0;

  *(uint8_t *)((int)param_1 + 0xb2) = 0;

  *(uint16_t *)(param_1 + 0x2d) = 0;

  param_1[0x2f] = 0;

  param_1[0x2e] = 0;

  param_1[0x30] = 0;

  ExceptionList = local_c;

  return param_1;

}
