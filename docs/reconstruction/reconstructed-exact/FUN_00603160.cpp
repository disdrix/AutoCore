// =============================================================================
// FUN_00603160
// -----------------------------------------------------------------------------
// Stable ID: aa_00603160
// Address:   0x00603160  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00603160 @ 0x00603160
// Stable ID: aa_00603160
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00602720, FUN_00603160.
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

uint32_t /* width from decompiler */ * __thiscall FUN_00603160(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint8_t param_3)



{

  int iVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a7f61;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  param_1[5] = 0;

  param_1[6] = 0;

  param_1[7] = 0;

  param_1[9] = 0;

  param_1[10] = 0;

  param_1[0xb] = 0;

  local_4 = 1;

  iVar1 = FUN_00602720();

  param_1[0xd] = iVar1;

  *(uint8_t *)(iVar1 + 0x29) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1[0xd] + 4) = param_1[0xd];

  *(uint32_t /* width from decompiler */ *)param_1[0xd] = param_1[0xd];

  *(uint32_t /* width from decompiler */ *)(param_1[0xd] + 8) = param_1[0xd];

  param_1[0xe] = 0;

  param_1[3] = param_2;

  *param_1 = 0;

  param_1[1] = 0;

  *(uint8_t *)(param_1 + 2) = 0;

  *(uint8_t *)((int)param_1 + 9) = param_3;

  ExceptionList = local_c;

  return param_1;

}
