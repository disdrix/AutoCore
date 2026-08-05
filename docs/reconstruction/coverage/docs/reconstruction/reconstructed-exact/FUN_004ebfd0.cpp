// =============================================================================
// FUN_004ebfd0
// -----------------------------------------------------------------------------
// Stable ID: aa_004ebfd0
// Address:   0x004ebfd0  (autoassault.exe, image base 0x400000)
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

void __fastcall FUN_004ebfd0(int param_1)

{
  void *pvVar1;
  
  pvVar1 = *(void **)(param_1 + 0x88);
  if (pvVar1 != (void *)0x0) {
    FUN_004a2670();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  *(uint32_t /* width from decompiler */ *)(param_1 + 0x88) = 0;
  FUN_004eb3b0();
  return;
}
