// =============================================================================
// FUN_00465800
// -----------------------------------------------------------------------------
// Stable ID: aa_00465800
// Address:   0x00465800  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00465800 @ 0x00465800
// Stable ID: aa_00465800
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~79 non-empty decompiler lines.
//  - Control keywords: for×5, return×1.
//  - Notable callees: FUN_00465500×5, FUN_00465800, FUN_0076e3c0, FUN_0076eb00.
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

uint32_t /* width from decompiler */ * FUN_00465800(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2,int param_3)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ *in_EAX;

  int iVar3;

  uint32_t /* width from decompiler */ extraout_EDX;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint8_t local_160 [16];

  uint32_t /* width from decompiler */ local_150 [5];

  uint32_t /* width from decompiler */ local_13c;

  float local_128;

  uint32_t /* width from decompiler */ local_110 [8];

  uint32_t /* width from decompiler */ local_f0;

  uint32_t /* width from decompiler */ local_ec;

  uint32_t /* width from decompiler */ local_d0 [8];

  uint32_t /* width from decompiler */ local_b0;

  uint32_t /* width from decompiler */ local_ac;

  uint32_t /* width from decompiler */ local_90 [8];

  uint32_t /* width from decompiler */ local_70;

  uint32_t /* width from decompiler */ local_6c;

  uint8_t local_50 [76];

  

  uVar1 = in_EAX[1];

  puVar4 = &DAT_00afdf70;

  puVar5 = local_110;

  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar5 = *puVar4;

    puVar4 = puVar4 + 1;

    puVar5 = puVar5 + 1;

  }

  local_f0 = DAT_00aaa6cc;

  local_ec = DAT_00aaa6cc;

  uVar2 = *in_EAX;

  puVar4 = &DAT_00afdf70;

  puVar5 = local_90;

  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar5 = *puVar4;

    puVar4 = puVar4 + 1;

    puVar5 = puVar5 + 1;

  }

  local_70 = uVar2;

  local_6c = uVar1;

  FUN_0076e3c0(local_160,0,0,*(uint32_t /* width from decompiler */ *)(param_3 + 8));

  FUN_0076eb00(local_50,extraout_EDX);

  uVar1 = DAT_00a0f298;

  local_150[0] = *param_2;

  puVar4 = &DAT_00afdf70;

  puVar5 = local_150;

  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar5 = *puVar4;

    puVar4 = puVar4 + 1;

    puVar5 = puVar5 + 1;

  }

  local_13c = param_2[1];

  puVar4 = &DAT_00afdf70;

  puVar5 = local_d0;

  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar5 = *puVar4;

    puVar4 = puVar4 + 1;

    puVar5 = puVar5 + 1;

  }

  local_128 = g_flOne;

  puVar4 = &DAT_00afdf70;

  puVar5 = param_1;

  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar5 = *puVar4;

    puVar4 = puVar4 + 1;

    puVar5 = puVar5 + 1;

  }

  local_b0 = uVar1;

  local_ac = uVar1;

  FUN_00465500(param_1);

  FUN_00465500(param_1);

  FUN_00465500(param_1);

  FUN_00465500(param_1);

  FUN_00465500(param_1);

  return param_1;

}
