// =============================================================================
// FUN_004e32e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004e32e0
// Address:   0x004e32e0  (autoassault.exe, image base 0x400000)
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

void __thiscall FUN_004e32e0(int param_1,char param_2)

{
  void *pvVar1;
  
  pvVar1 = (void *)FUN_004e3330();
  if (param_2 == '\0') {
    while (pvVar1 != (void *)0x0) {
      pvVar1 = (void *)FUN_004e3330();
    }
  }
  else if (pvVar1 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;
  return;
}
