// =============================================================================
// FUN_008d7010
// -----------------------------------------------------------------------------
// Stable ID: aa_008d7010
// Address:   0x008d7010  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008d7010 @ 0x008d7010
// Stable ID: aa_008d7010
// Embedded strings (evidence for future rename):
//   - "i_d_fec.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~129 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: CVOGReaction_RandomUnitScalar×3, FUN_004248c0×3, FUN_008d0f80, FUN_008d7010, FUN_008d8b90, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_fec.xml".
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

uint32_t /* width from decompiler */ * FUN_008d7010(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  uint uVar2;

  void *local_c;

  undefined *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &DAT_009ba1d9;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_008d8b90(param_1,param_2);

  *param_1 = &PTR_FUN_00a3f2b4;

  param_1[0x220] = 0;

  param_1[0x221] = 0;

  param_1[0x222] = 0;

  param_1[0x224] = 0;

  param_1[0x225] = 0;

  param_1[0x226] = 0;

  param_1[0x228] = 0;

  param_1[0x229] = 0;

  param_1[0x22a] = 0;

  param_1[0x22c] = 0;

  param_1[0x22d] = 0;

  param_1[0x22e] = 0;

  param_1[0x230] = 0;

  param_1[0x231] = 0;

  param_1[0x232] = 0;

  param_1[0x234] = 0;

  param_1[0x235] = 0;

  param_1[0x236] = 0;

  param_1[0x238] = 0;

  param_1[0x239] = 0;

  param_1[0x23a] = 0;

  local_4 = 7;

  param_1[0x1fc] = 0xffffffff;

  param_1[0x211] = 0xffffffff;

  param_1[0x1fd] = 0xffffffff;

  param_1[0x212] = 0xffffffff;

  param_1[0x1fe] = 0xffffffff;

  param_1[0x213] = 0xffffffff;

  param_1[0x1ff] = 0xffffffff;

  param_1[0x214] = 0xffffffff;

  param_1[0x200] = 0xffffffff;

  param_1[0x215] = 0xffffffff;

  param_1[0x201] = 0xffffffff;

  param_1[0x216] = 0xffffffff;

  param_1[0x202] = 0xffffffff;

  param_1[0x217] = 0xffffffff;

  param_1[0x203] = 0;

  param_1[0x204] = 0;

  param_1[0x205] = 0;

  param_1[0x206] = 0;

  param_1[0x207] = 0;

  param_1[0x208] = 0;

  param_1[0x209] = 0;

  param_1[0x20a] = 0;

  param_1[0x20b] = 0;

  param_1[0x20c] = 0;

  param_1[0x20d] = 0;

  param_1[0x20e] = 0;

  param_1[0x20f] = 0;

  param_1[0x210] = 0;

  param_1[0x218] = 0;

  param_1[0x219] = 0;

  param_1[0x21a] = 0;

  param_1[0x21b] = 0;

  param_1[0x21c] = 0;

  param_1[0x21d] = 0;

  param_1[0x21e] = 0;

  iVar1 = CVOGReaction_RandomUnitScalar();

  iVar1 = *(int *)(iVar1 + 0x14);

  if (*(int *)(iVar1 + 0x9c4) == 0) {

    FUN_004248c0();

  }

  *(int *)(iVar1 + 0x9c4) = *(int *)(iVar1 + 0x9c4) + -1;

  uVar2 = **(uint **)(iVar1 + 0x9c0);

  *(uint **)(iVar1 + 0x9c0) = *(uint **)(iVar1 + 0x9c0) + 1;

  uVar2 = uVar2 ^ uVar2 >> 0xb;

  uVar2 = uVar2 ^ (uVar2 & 0xff3a58ad) << 7;

  uVar2 = uVar2 ^ (uVar2 & 0xffffdf8c) << 0xf;

  param_1[0x169] = (uVar2 >> 0x12 ^ uVar2) & 1;

  iVar1 = CVOGReaction_RandomUnitScalar();

  iVar1 = *(int *)(iVar1 + 0x14);

  if (*(int *)(iVar1 + 0x9c4) == 0) {

    FUN_004248c0();

  }

  *(int *)(iVar1 + 0x9c4) = *(int *)(iVar1 + 0x9c4) + -1;

  uVar2 = **(uint **)(iVar1 + 0x9c0);

  *(uint **)(iVar1 + 0x9c0) = *(uint **)(iVar1 + 0x9c0) + 1;

  uVar2 = uVar2 ^ uVar2 >> 0xb;

  uVar2 = uVar2 ^ (uVar2 & 0xff3a58ad) << 7;

  uVar2 = uVar2 ^ (uVar2 & 0xffffdf8c) << 0xf;

  param_1[0x16a] = (uVar2 >> 0x12 ^ uVar2) % 3;

  iVar1 = CVOGReaction_RandomUnitScalar();

  iVar1 = *(int *)(iVar1 + 0x14);

  if (*(int *)(iVar1 + 0x9c4) == 0) {

    FUN_004248c0();

  }

  *(int *)(iVar1 + 0x9c4) = *(int *)(iVar1 + 0x9c4) + -1;

  uVar2 = **(uint **)(iVar1 + 0x9c0);

  *(uint **)(iVar1 + 0x9c0) = *(uint **)(iVar1 + 0x9c0) + 1;

  uVar2 = uVar2 ^ uVar2 >> 0xb;

  uVar2 = uVar2 ^ (uVar2 & 0xff3a58ad) << 7;

  uVar2 = uVar2 ^ (uVar2 & 0xffffdf8c) << 0xf;

  param_1[0x198] = 0;

  param_1[0x19e] = 0;

  param_1[0x16d] = 0;

  param_1[0x16b] = (uVar2 >> 0x12 ^ uVar2) & 3;

  param_1[0x17a] = 0;

  param_1[0x17b] = 0;

  param_1[0x17c] = 0;

  param_1[0x17d] = 0;

  param_1[0x17e] = 0;

  param_1[0x17f] = 0;

  param_1[0x180] = 0;

  param_1[0x181] = 0;

  param_1[0x182] = 0;

  param_1[0x183] = 0;

  param_1[0x184] = 0;

  param_1[0x185] = 0;

  param_1[0x186] = 0;

  param_1[0x187] = 0;

  param_1[0x188] = 0;

  FUN_008d0f80();

  NDUIWindow_ReloadInterface("i_d_fec.xml");

  ExceptionList = local_c;

  return param_1;

}
