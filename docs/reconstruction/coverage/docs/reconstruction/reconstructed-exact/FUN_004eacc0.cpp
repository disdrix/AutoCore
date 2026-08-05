// =============================================================================
// FUN_004eacc0
// -----------------------------------------------------------------------------
// Stable ID: aa_004eacc0
// Address:   0x004eacc0  (autoassault.exe, image base 0x400000)
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

void __fastcall FUN_004eacc0(uint32_t /* width from decompiler */ *param_1)

{
  void *local_c;
  uint8_t *puStack_8;
  uint32_t /* width from decompiler */ local_4;
  
  puStack_8 = &LAB_009a25b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_009ccbb4;
  local_4 = 0;
  if (-1 < (int)param_1[4]) {
    (**(code **)(*DAT_00b05060 + 0x14))(param_1[2],param_1[4] << 4,0x12);
  }
  *param_1 = &PTR_LAB_009ccb9c;
  ExceptionList = local_c;
  return;
}
