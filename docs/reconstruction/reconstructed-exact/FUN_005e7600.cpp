// =============================================================================
// FUN_005e7600
// -----------------------------------------------------------------------------
// Stable ID: aa_005e7600
// Address:   0x005e7600  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005e7600 @ 0x005e7600
// Stable ID: aa_005e7600
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~86 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_004073a0×2, FUN_004507a0×2, FUN_00493830×2, FUN_00410420, FUN_004367f0, FUN_00442ed0, FUN_00493e00, FUN_00493f40.
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

uint32_t /* width from decompiler */ * __thiscall FUN_005e7600(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a76dd;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_005a66e0(param_2);

  local_4 = 0;

  *param_1 = &PTR_FUN_009dcafc;

  FUN_00493e00(0,0);

  FUN_00493f40(2);

  iVar1 = param_1[5];

  param_2 = 0;

  if ((iVar1 == 0) || ((uint)(param_1[7] - iVar1 >> 2) <= (uint)(param_1[6] - iVar1 >> 2))) {

    FUN_00493830(param_1[6],1,&param_2);

  }

  else {

    puVar2 = (uint32_t /* width from decompiler */ *)param_1[6];

    *puVar2 = 0;

    param_1[6] = puVar2 + 1;

  }

  iVar1 = param_1[5];

  param_2 = 0;

  if ((iVar1 == 0) || ((uint)(param_1[7] - iVar1 >> 2) <= (uint)(param_1[6] - iVar1 >> 2))) {

    FUN_00493830(param_1[6],1,&param_2);

  }

  else {

    puVar2 = (uint32_t /* width from decompiler */ *)param_1[6];

    *puVar2 = 0;

    param_1[6] = puVar2 + 1;

  }

  param_1[0x59] = DAT_00a110d8;

  param_1[0x5a] = 0;

  FUN_00410420(0,0);

  FUN_005a6ae0(2);

  iVar1 = param_1[9];

  param_2 = 0xffffffff;

  if ((iVar1 == 0) || ((uint)(param_1[0xb] - iVar1 >> 2) <= (uint)(param_1[10] - iVar1 >> 2))) {

    FUN_004073a0(param_1[10],1,&param_2);

  }

  else {

    puVar2 = (uint32_t /* width from decompiler */ *)param_1[10];

    *puVar2 = 0xffffffff;

    param_1[10] = puVar2 + 1;

  }

  iVar1 = param_1[9];

  param_2 = 0xffffffff;

  if ((iVar1 == 0) || ((uint)(param_1[0xb] - iVar1 >> 2) <= (uint)(param_1[10] - iVar1 >> 2))) {

    FUN_004073a0(param_1[10],1,&param_2);

  }

  else {

    puVar2 = (uint32_t /* width from decompiler */ *)param_1[10];

    *puVar2 = 0xffffffff;

    param_1[10] = puVar2 + 1;

  }

  param_1[0x5b] = 0;

  FUN_004367f0(0,0);

  FUN_00442ed0(2);

  iVar1 = param_1[0x55];

  param_2 = 0;

  if ((iVar1 == 0) || ((uint)(param_1[0x57] - iVar1 >> 2) <= (uint)(param_1[0x56] - iVar1 >> 2))) {

    FUN_004507a0(param_1[0x56],1,&param_2);

  }

  else {

    puVar2 = (uint32_t /* width from decompiler */ *)param_1[0x56];

    *puVar2 = 0;

    param_1[0x56] = puVar2 + 1;

  }

  iVar1 = param_1[0x55];

  param_2 = 0;

  if ((iVar1 == 0) || ((uint)(param_1[0x57] - iVar1 >> 2) <= (uint)(param_1[0x56] - iVar1 >> 2))) {

    FUN_004507a0(param_1[0x56],1,&param_2);

  }

  else {

    puVar2 = (uint32_t /* width from decompiler */ *)param_1[0x56];

    *puVar2 = 0;

    param_1[0x56] = puVar2 + 1;

  }

  ExceptionList = local_c;

  return param_1;

}
