// =============================================================================
// thunk_FUN_00578a60
// -----------------------------------------------------------------------------
// Stable ID: aa_00548f90
// Address:   0x00548f90  (autoassault.exe, image base 0x400000)
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

void __fastcall thunk_FUN_00578a60(uint32_t /* width from decompiler */ *param_1)

{
  *param_1 = &PTR_FUN_009d3fdc;
  if ((void *)param_1[0x1a8] != (void *)0x0) {
    operator_delete__((void *)param_1[0x1a8]);
  }
  param_1[0x1a8] = 0;
  if ((void *)param_1[0x1ac] != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete((void *)param_1[0x1ac]);
  }
  param_1[0x1ac] = 0;
  param_1[0x1ad] = 0;
  param_1[0x1ae] = 0;
  FUN_00508390();
  return;
}
