// =============================================================================
// FUN_006936b0
// -----------------------------------------------------------------------------
// Stable ID: aa_006936b0
// Address:   0x006936b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006936b0 @ 0x006936b0
// Stable ID: aa_006936b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, while×1.
//  - Notable callees: FUN_00691d80×2, FUN_006936b0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void FUN_006936b0(int param_1,int param_2,int param_3,uint32_t /* width from decompiler */ param_4,void *param_5,

                 uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7,uint32_t /* width from decompiler */ param_8,uint32_t /* width from decompiler */ param_9,

                 uint8_t param_10,uint32_t /* width from decompiler */ param_11,uint32_t /* width from decompiler */ param_12,float param_13,

                 uint32_t /* width from decompiler */ param_14,uint32_t /* width from decompiler */ param_15)



{

  int iVar1;

  int iVar2;

  int iVar3;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009aa7b8;

  local_4 = 0;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  while (param_3 < param_2) {

    iVar3 = (param_2 + -1) / 2;

    iVar2 = iVar3 * 0x30;

    iVar1 = iVar2 + param_1;

    if (*(float *)(iVar2 + 0x24 + param_1) <= param_13) break;

    iVar2 = param_2 * 0x30 + param_1;

    FUN_00691d80(iVar1);

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x10) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x10);

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x14) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x14);

    *(uint8_t *)(iVar2 + 0x18) = *(uint8_t *)(iVar1 + 0x18);

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x1c) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x1c);

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x20) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x20);

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x24) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x24);

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x28) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x28);

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x2c) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x2c);

    param_2 = iVar3;

  }

  param_1 = param_2 * 0x30 + param_1;

  FUN_00691d80(&param_4);

  *(uint8_t *)(param_1 + 0x18) = param_10;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = param_8;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = param_9;

  *(float *)(param_1 + 0x24) = param_13;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = param_11;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = param_12;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = param_14;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = param_15;

  if (param_5 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(param_5);

  }

  ExceptionList = local_c;

  return;

}
