// =============================================================================
// FUN_004ebee0
// -----------------------------------------------------------------------------
// Stable ID: aa_004ebee0
// Address:   0x004ebee0  (autoassault.exe, image base 0x400000)
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

void __fastcall FUN_004ebee0(int param_1)

{
  void *local_c;
  uint8_t *puStack_8;
  uint32_t /* width from decompiler */ local_4;
  
  puStack_8 = &LAB_009a27bd;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_004eaf30();
  local_4 = 0xffffffff;
  if (-1 < *(int *)(param_1 + 0x18)) {
    (**(code **)(*DAT_00b05060 + 0x14))
              (*(uint32_t /* width from decompiler */ *)(param_1 + 0x10),*(int *)(param_1 + 0x18) << 4,0x12);
  }
  ExceptionList = local_c;
  return;
}
