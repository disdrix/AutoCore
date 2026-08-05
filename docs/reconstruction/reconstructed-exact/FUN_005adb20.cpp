// =============================================================================
// FUN_005adb20
// -----------------------------------------------------------------------------
// Stable ID: aa_005adb20
// Address:   0x005adb20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005adb20 @ 0x005adb20
// Stable ID: aa_005adb20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005ae270×2, CONCAT31, FUN_005adb20, FUN_005ae2b0, FUN_00637da0.
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

uint32_t /* width from decompiler */ * __thiscall FUN_005adb20(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a6650;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00637da0(param_2);

  *param_1 = &PTR_FUN_009d92ac;

  param_1[5] = 0;

  param_1[6] = 0;

  param_1[7] = 0;

  param_1[9] = 0;

  param_1[10] = 0;

  param_1[0xb] = 0;

  param_1[0xd] = 0;

  param_1[0xe] = 0;

  param_1[0xf] = 0;

  param_1[0x13] = 0;

  param_1[0x14] = 0;

  param_1[0x15] = 0;

  local_4._0_1_ = 4;

  local_4._1_3_ = 0;

  iVar2 = FUN_005ae270();

  param_1[0x1d] = iVar2;

  *(uint8_t *)(iVar2 + 0x21) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1[0x1d] + 4) = param_1[0x1d];

  *(uint32_t /* width from decompiler */ *)param_1[0x1d] = param_1[0x1d];

  *(uint32_t /* width from decompiler */ *)(param_1[0x1d] + 8) = param_1[0x1d];

  param_1[0x1e] = 0;

  local_4._0_1_ = 5;

  iVar2 = FUN_005ae270();

  param_1[0x20] = iVar2;

  *(uint8_t *)(iVar2 + 0x21) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1[0x20] + 4) = param_1[0x20];

  *(uint32_t /* width from decompiler */ *)param_1[0x20] = param_1[0x20];

  *(uint32_t /* width from decompiler */ *)(param_1[0x20] + 8) = param_1[0x20];

  param_1[0x21] = 0;

  local_4 = CONCAT31(local_4._1_3_,6);

  iVar2 = FUN_005ae2b0();

  uVar1 = DAT_00a110d8;

  param_1[0x23] = iVar2;

  *(uint8_t *)(iVar2 + 0x19) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1[0x23] + 4) = param_1[0x23];

  *(uint32_t /* width from decompiler */ *)param_1[0x23] = param_1[0x23];

  *(uint32_t /* width from decompiler */ *)(param_1[0x23] + 8) = param_1[0x23];

  param_1[0x24] = 0;

  param_1[3] = 0xe;

  param_1[0x11] = 0xffffffff;

  param_1[0x16] = 0;

  param_1[0x17] = uVar1;

  *(uint8_t *)((int)param_1 + 0x6d) = 0;

  *(uint8_t *)(param_1 + 0x1b) = 0;

  *(uint8_t *)(param_1 + 0x19) = 0;

  param_1[0x18] = uVar1;

  param_1[0x25] = 0xffffffff;

  param_1[0x26] = 0;

  param_1[0x28] = 0;

  ExceptionList = local_c;

  return param_1;

}
