// =============================================================================
// FUN_00680320
// -----------------------------------------------------------------------------
// Stable ID: aa_00680320
// Address:   0x00680320  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00680320 @ 0x00680320
// Stable ID: aa_00680320
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0095cf70×2, InitializeCriticalSection×2, CONCAT31, FUN_00439770, FUN_00680320, FUN_0071aeb0.
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

uint32_t /* width from decompiler */ * __fastcall FUN_00680320(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a9984;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0071aeb0();

  local_4 = 0;

  *param_1 = &PTR_FUN_009e9674;

  FUN_0095cf70(0,0,0);

  local_4._0_1_ = 1;

  FUN_0095cf70(0,0,0);

  param_1[10] = 0;

  param_1[0xb] = 0;

  param_1[0xc] = 0;

  param_1[0xd] = 0;

  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xe));

  *(uint8_t *)(param_1 + 0x14) = 1;

  param_1[0x16] = 0;

  param_1[0x17] = 0;

  param_1[0x18] = 0;

  param_1[0x19] = 0;

  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1a));

  *(uint8_t *)(param_1 + 0x20) = 1;

  local_4 = CONCAT31(local_4._1_3_,4);

  iVar1 = FUN_00439770();

  param_1[0x23] = iVar1;

  *(uint8_t *)(iVar1 + 0x15) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1[0x23] + 4) = param_1[0x23];

  *(uint32_t /* width from decompiler */ *)param_1[0x23] = param_1[0x23];

  *(uint32_t /* width from decompiler */ *)(param_1[0x23] + 8) = param_1[0x23];

  param_1[0x24] = 0;

  ExceptionList = local_c;

  return param_1;

}
