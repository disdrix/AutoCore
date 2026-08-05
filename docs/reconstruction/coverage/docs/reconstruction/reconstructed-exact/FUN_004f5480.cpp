// =============================================================================
// FUN_004f5480
// -----------------------------------------------------------------------------
// Stable ID: aa_004f5480
// Address:   0x004f5480  (autoassault.exe, image base 0x400000)
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

void __fastcall FUN_004f5480(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x5c0 + param_1);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x1dc))();
    if (iVar2 != 0) {
      iVar2 = (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x5c0 + param_1) +
                          0x1dc))();
                    /* WARNING: Could not recover jumptable at 0x004f54c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x160))();
      return;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x004f54e6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x66c + param_1) + 0x15c))();
  return;
}
