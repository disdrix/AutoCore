// =============================================================================
// FUN_0067e030
// -----------------------------------------------------------------------------
// Stable ID: aa_0067e030
// Address:   0x0067e030  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0067e030 @ 0x0067e030
// Stable ID: aa_0067e030
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~103 non-empty decompiler lines.
//  - Control keywords: for×1, if×1, return×1.
//  - Notable callees: CONCAT31, FUN_0067bf50, FUN_0067e030, FUN_0067f8b0, FUN_0076c4d0, FUN_0076c500, thunk_FUN_0076c4d0.
//  - Return sites: 1.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ * __thiscall FUN_0067e030(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  uint64_t uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a985c;

  local_c = ExceptionList;

  local_4 = 0;

  ExceptionList = &local_c;

  *param_1 = &PTR_FUN_009e9174;

  *(uint8_t *)(param_1 + 1) = 1;

  *(uint8_t *)((int)param_1 + 5) = 0;

  *(uint8_t *)((int)param_1 + 6) = 0;

  iVar3 = FUN_0067f8b0();

  param_1[0x43] = iVar3;

  *(uint8_t *)(iVar3 + 0xe) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1[0x43] + 4) = param_1[0x43];

  *(uint32_t /* width from decompiler */ *)param_1[0x43] = param_1[0x43];

  *(uint32_t /* width from decompiler */ *)(param_1[0x43] + 8) = param_1[0x43];

  param_1[0x44] = 0;

  local_4._0_1_ = 1;

  _eh_vector_constructor_iterator_

            (param_1 + 0x45,0x28,0x100,FUN_0067c630,(_func_void_void_ptr *)&LAB_0067c690);

  param_1[0xa46] = 0;

  param_1[0xa47] = 0;

  param_1[0xa48] = 0;

  param_1[0xa4a] = 0;

  param_1[0xa4b] = 0;

  param_1[0xa4c] = 0;

  param_1[0xa4e] = 0;

  param_1[0xa4f] = 0;

  param_1[0xa50] = 0;

  param_1[0xa52] = 0;

  param_1[0xa53] = 0;

  param_1[0xa54] = 0;

  param_1[0xa56] = 0;

  param_1[0xa57] = 0;

  param_1[0xa58] = 0;

  param_1[0xa5a] = 0;

  param_1[0xa5b] = 0;

  param_1[0xa5c] = 0;

  param_1[0xa5e] = 0;

  param_1[0xa5f] = 0;

  param_1[0xa60] = 0;

  param_1[0xa61] = param_2;

  local_4 = CONCAT31(local_4._1_3_,9);

  FUN_0076c500(100);

  param_1[0xa6e] = 0;

  param_1[0xa6f] = 0;

  param_1[0xa70] = 0;

  param_1[0xa71] = 0;

  *(uint16_t *)((int)param_1 + 0x29ca) = 0;

  param_1[0xa73] = 0;

  param_1[0xa74] = 0;

  *(uint8_t *)(param_1 + 0xa75) = 0;

  param_1[0xa76] = 0x10000;

  uVar2 = _DAT_00aaaa78;

  uVar1 = DAT_00a0f520;

  param_1[0xa77] = 0x10000;

  *(uint64_t *)(param_1 + 0xa7e) = uVar2;

  param_1[0xa78] = 0x10000;

  param_1[0xa79] = 0x10000;

  param_1[0xa7a] = 0;

  param_1[0xa7b] = 0xfa;

  param_1[0xa7c] = 0;

  param_1[0xa80] = 0;

  param_1[0xa81] = 1;

  param_1[0xa82] = 0;

  param_1[0xa83] = 1;

  *(uint8_t *)(param_1 + 0xa84) = 0;

  *(uint8_t *)((int)param_1 + 0x2a11) = 0;

  *(uint8_t *)((int)param_1 + 0x2a12) = 0;

  param_1[0xa85] = 0;

  param_1[0xa86] = 0;

  param_1[0xa87] = 0xffffffff;

  param_1[0xa88] = 0;

  param_1[0xa89] = 0x368;

  param_1[0xa8a] = 0x3e0;

  param_1[0xa8b] = 0x3d0;

  *(uint8_t *)(param_1 + 0xa8c) = 0;

  param_1[0xa8d] = 0;

  param_1[0xa8e] = 0;

  param_1[0xa8f] = 0;

  param_1[0xa90] = uVar1;

  puVar4 = (uint32_t /* width from decompiler */ *)((int)param_1 + 7);

  for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar4 = 0;

    puVar4 = puVar4 + 1;

  }

  FUN_0076c4d0();

  thunk_FUN_0076c4d0();

  if ((int *)param_1[0xa61] != (int *)0x0) {

    iVar3 = (**(code **)(*(int *)param_1[0xa61] + 0x38))();

    FUN_0067bf50(iVar3 + -0x10);

  }

  ExceptionList = local_c;

  return param_1;

}
