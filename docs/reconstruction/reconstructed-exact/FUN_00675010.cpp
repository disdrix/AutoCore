// =============================================================================
// FUN_00675010
// -----------------------------------------------------------------------------
// Stable ID: aa_00675010
// Address:   0x00675010  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00675010 @ 0x00675010
// Stable ID: aa_00675010
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~87 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00680300×10, InitializeCriticalSection×2, CONCAT31, FUN_00439770, FUN_0044e060, FUN_004933f0, FUN_00675010, FUN_00680320.
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

uint32_t /* width from decompiler */ * __fastcall FUN_00675010(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ *local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a94f0;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  local_10 = param_1;

  FUN_00680320();

  *param_1 = &PTR_FUN_009e8488;

  param_1[0x2a] = 0;

  param_1[0x2c] = 0;

  param_1[0x2d] = DAT_00aa9110;

  param_1[0x2e] = DAT_00aa9114;

  param_1[0x2f] = DAT_00aa9118;

  param_1[0x30] = DAT_00aa911c;

  local_4 = 0;

  param_1[0x32] = 0;

  param_1[0x33] = 0;

  param_1[0x34] = 0;

  param_1[0x35] = 0;

  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x36));

  *(uint8_t *)(param_1 + 0x3c) = 1;

  param_1[0x3e] = 0;

  param_1[0x3f] = 0;

  param_1[0x40] = 0;

  param_1[0x41] = 0;

  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x42));

  *(uint8_t *)(param_1 + 0x48) = 1;

  param_1[0x4a] = 0;

  param_1[0x4b] = 0;

  param_1[0x4c] = 0;

  local_4._0_1_ = 3;

  uVar1 = FUN_004933f0();

  param_1[0x4e] = uVar1;

  param_1[0x4f] = 0;

  local_4._0_1_ = 4;

  iVar2 = FUN_00439770();

  param_1[0x51] = iVar2;

  *(uint8_t *)(iVar2 + 0x15) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1[0x51] + 4) = param_1[0x51];

  *(uint32_t /* width from decompiler */ *)param_1[0x51] = param_1[0x51];

  *(uint32_t /* width from decompiler */ *)(param_1[0x51] + 8) = param_1[0x51];

  param_1[0x52] = 0;

  local_4._0_1_ = 5;

  *(uint8_t *)(param_1 + 0x53) = 0;

  param_1[0x54] = 0;

  param_1[0x55] = 0;

  param_1[0x56] = 0;

  param_1[0x57] = 0;

  iVar2 = FUN_0044e060();

  param_1[0x59] = iVar2;

  *(uint8_t *)(iVar2 + 0x25) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1[0x59] + 4) = param_1[0x59];

  *(uint32_t /* width from decompiler */ *)param_1[0x59] = param_1[0x59];

  *(uint32_t /* width from decompiler */ *)(param_1[0x59] + 8) = param_1[0x59];

  param_1[0x5a] = 0;

  local_4 = CONCAT31(local_4._1_3_,6);

  local_14 = 0;

  FUN_00680300(&local_14,&LAB_00677470);

  local_14 = 1;

  FUN_00680300(&local_14,&LAB_00677570);

  local_14 = 2;

  FUN_00680300(&local_14,&LAB_006775a0);

  local_14 = 3;

  FUN_00680300(&local_14,&LAB_00676ac0);

  local_14 = 4;

  FUN_00680300(&local_14,&LAB_00676af0);

  local_14 = 5;

  FUN_00680300(&local_14,&LAB_00677370);

  local_14 = 6;

  FUN_00680300(&local_14,&LAB_006770c0);

  local_14 = 7;

  FUN_00680300(&local_14,&LAB_00677380);

  local_14 = 8;

  FUN_00680300(&local_14,&LAB_00675920);

  local_14 = 9;

  FUN_00680300(&local_14,&LAB_00676b00);

  ExceptionList = local_c;

  return param_1;

}
