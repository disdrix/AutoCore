// =============================================================================
// Named_CalleeOf_CVOGReaction_GiveItemByCbid_00566c10
// -----------------------------------------------------------------------------
// Stable ID: aa_00566c10
// Callee of CVOGReaction_GiveItemByCbid
// Address:   0x00566c10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGReaction_GiveItemByCbid: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~90 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: CONCAT31, FUN_00518940, FUN_00565640, FUN_00566c10, FUN_00581330, InitializeCriticalSection.
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_CVOGReaction_GiveItemByCbid_00566c10(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  byte *pbVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a4bda;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  if (param_2 != 0) {

    ExceptionList = &local_c;

    param_1[1] = &DAT_009d2f14;

    FUN_00518940();

    local_4 = 0;

  }

  FUN_00581330(0);

  uVar2 = DAT_00a110ac;

  *param_1 = &PTR_LAB_009d2d34;

  *(undefined ***)(*(int *)(param_1[1] + 4) + 4 + (int)param_1) = &PTR_LAB_009d2a6c;

  *(int *)(*(int *)(param_1[1] + 4) + (int)param_1) = *(int *)(param_1[1] + 4) + -0x1dc;

  param_1[0x1f] = uVar2;

  param_1[0x20] = DAT_00aaa884;

  param_1[0x21] = DAT_00aaa668;

  param_1[0x27] = g_flOne;

  *(uint8_t *)(param_1 + 0x2a) = 1;

  *(uint8_t *)((int)param_1 + 0xa9) = 1;

  *(uint8_t *)((int)param_1 + 0xaa) = 0;

  param_1[0x2b] = 0;

  *(uint8_t *)(param_1 + 0x2c) = 0;

  *(uint8_t *)((int)param_1 + 0xb1) = 0x32;

  *(uint8_t *)((int)param_1 + 0xb2) = 100;

  *(uint8_t *)((int)param_1 + 0xb3) = 0;

  param_1[0x28] = 0xffffffff;

  param_1[0x29] = 0xffffffff;

  local_4 = 1;

  param_1[0x2d] = &PTR_FUN_009cb334;

  param_1[0x35] = 0;

  param_1[0x34] = 0;

  param_1[0x36] = 0;

  *(uint8_t *)(param_1 + 0x37) = 0;

  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x2e));

  param_1[0x2d] = &PTR_FUN_009cb378;

  param_1[0x38] = 0;

  param_1[0x39] = 0;

  param_1[0x3a] = 0;

  param_1[0x61] = 0;

  param_1[0x62] = 0;

  param_1[99] = 0;

  param_1[0x65] = 0;

  param_1[0x66] = 0;

  param_1[0x67] = 0;

  uVar2 = DAT_00aaa668;

  param_1[0x68] = 0xffffffff;

  param_1[0x69] = 0;

  *(uint8_t *)(param_1 + 0x6a) = 0;

  *(uint8_t *)((int)param_1 + 0x1a9) = 1;

  param_1[0x6e] = uVar2;

  param_1[0x70] = 0;

  param_1[0x71] = 0;

  puVar3 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1[1] + 4) + 0x84 + (int)param_1);

  *puVar3 = 0;

  puVar3[1] = 0;

  puVar3[2] = 0;

  puVar3[3] = 0;

  local_4 = CONCAT31(local_4._1_3_,4);

  iVar4 = 0;

  puVar3 = param_1 + 0x3b;

  do {

    *(uint8_t *)(puVar3 + 2) = 0;

    *(uint8_t *)puVar3 = 0;

    *(uint8_t *)((int)puVar3 + 1) = 0;

    puVar3[1] = 0xffffffff;

    *(uint8_t *)((int)puVar3 + 9) = 0;

    *(uint8_t *)((int)param_1 + iVar4 + 0x1aa) = 0;

    iVar4 = iVar4 + 1;

    puVar3 = puVar3 + 3;

  } while (iVar4 < 0xc);

  pbVar1 = (byte *)(*(int *)(param_1[1] + 4) + 0x181 + (int)param_1);

  *pbVar1 = *pbVar1 | 2;

  if (DAT_00b04780 == '\0') {

    FUN_00565640();

    DAT_00b04780 = '\x01';

  }

  ExceptionList = local_c;

  return param_1;

}
