// =============================================================================
// FUN_00786340
// -----------------------------------------------------------------------------
// Stable ID: aa_00786340
// Address:   0x00786340  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00786340 @ 0x00786340
// Stable ID: aa_00786340
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: QueryPerformanceCounter×8, QueryPerformanceFrequency×2, FUN_0042a590, FUN_00786340, InitializeCriticalSection.
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



uint32_t /* width from decompiler */ * FUN_00786340(uint32_t /* width from decompiler */ *param_1)



{

  float fVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *local_c;

  undefined *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &DAT_009ac2b1;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = 0;

  QueryPerformanceFrequency((LARGE_INTEGER *)&DAT_00afa268);

  _DAT_00afa270 = g_flOne / (float)_DAT_00afa268;

  QueryPerformanceCounter((LARGE_INTEGER *)(param_1 + 6));

  QueryPerformanceCounter((LARGE_INTEGER *)(param_1 + 8));

  param_1[4] = 0;

  *(uint8_t *)(param_1 + 2) = 0;

  param_1[5] = 0;

  QueryPerformanceFrequency((LARGE_INTEGER *)&DAT_00afa268);

  _DAT_00afa270 = g_flOne / (float)_DAT_00afa268;

  QueryPerformanceCounter((LARGE_INTEGER *)(param_1 + 0xe));

  QueryPerformanceCounter((LARGE_INTEGER *)(param_1 + 0x10));

  param_1[0xc] = 0;

  *(uint8_t *)(param_1 + 10) = 0;

  param_1[0xd] = 0;

  param_1[0x13] = 0;

  param_1[0x14] = 0;

  param_1[0x15] = 0;

  local_4 = 0;

  *(uint8_t *)(param_1 + 0x1c) = 1;

  *(uint8_t *)((int)param_1 + 0x175) = 0;

  QueryPerformanceCounter((LARGE_INTEGER *)(param_1 + 6));

  QueryPerformanceCounter((LARGE_INTEGER *)(param_1 + 8));

  uVar2 = DAT_00aaa688;

  param_1[4] = DAT_00aaa688;

  *(uint8_t *)(param_1 + 2) = 1;

  param_1[5] = uVar2;

  QueryPerformanceCounter((LARGE_INTEGER *)(param_1 + 0xe));

  QueryPerformanceCounter((LARGE_INTEGER *)(param_1 + 0x10));

  fVar1 = g_flMultiKillCountBlend;

  param_1[0xc] = g_flMultiKillCountBlend;

  *(uint8_t *)(param_1 + 10) = 1;

  param_1[0xd] = fVar1;

  FUN_0042a590();

  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x16));

  *(uint8_t *)((int)param_1 + 0x71) = 0;

  ExceptionList = local_c;

  return param_1;

}
