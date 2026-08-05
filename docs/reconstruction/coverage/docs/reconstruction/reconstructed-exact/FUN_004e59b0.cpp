// =============================================================================
// FUN_004e59b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004e59b0
// Address:   0x004e59b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

uint32_t /* width from decompiler */ * __thiscall FUN_004e59b0(uint32_t /* width from decompiler */ *param_1,byte param_2)

{
  void *local_c;
  uint8_t *puStack_8;
  uint32_t /* width from decompiler */ local_4;
  
  puStack_8 = &LAB_009a256b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_009cc6c0;
  param_1[1] = 0;
  param_1[3] = 0;
  param_1[2] = 1 << (param_2 & 0x1f);
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  *(byte *)(param_1 + 7) = param_2;
  *(uint8_t *)((int)param_1 + 0x1d) = 0;
  param_1[8] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  local_4 = 0;
  FUN_004e1980();
  ExceptionList = local_c;
  return param_1;
}
