// =============================================================================
// FUN_005a1f50
// -----------------------------------------------------------------------------
// Stable ID: aa_005a1f50
// Address:   0x005a1f50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a1f50 @ 0x005a1f50
// Stable ID: aa_005a1f50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CONCAT31, FUN_005a1b40, FUN_005a1f50, FUN_005a2160, FUN_005ae270, FUN_00975f90, QueryPerformanceCounter.
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

uint32_t /* width from decompiler */ * __thiscall

FUN_005a1f50(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            uint32_t /* width from decompiler */ param_5,uint8_t param_6,uint32_t /* width from decompiler */ param_7,uint32_t /* width from decompiler */ param_8,

            uint32_t /* width from decompiler */ param_9,uint32_t /* width from decompiler */ param_10,uint32_t /* width from decompiler */ param_11)



{

  int iVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a6271;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_005a2160(param_2,param_3,param_4,param_5,param_7,param_8,param_9,param_10,param_11);

  local_4 = 0;

  *param_1 = &PTR_FUN_009d7fcc;

  param_1[0x2c] = 0;

  *(uint8_t *)(param_1 + 0x2d) = param_6;

  iVar1 = FUN_005ae270();

  param_1[0x2f] = iVar1;

  *(uint8_t *)(iVar1 + 0x21) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1[0x2f] + 4) = param_1[0x2f];

  *(uint32_t /* width from decompiler */ *)param_1[0x2f] = param_1[0x2f];

  *(uint32_t /* width from decompiler */ *)(param_1[0x2f] + 8) = param_1[0x2f];

  param_1[0x30] = 0;

  local_4 = CONCAT31(local_4._1_3_,1);

  QueryPerformanceCounter((LARGE_INTEGER *)&param_7);

  FUN_00975f90(&param_7,8);

  FUN_005a1b40();

  param_1[0x31] = 1;

  ExceptionList = local_c;

  return param_1;

}
