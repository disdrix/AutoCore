// =============================================================================
// FUN_004f6fd0
// -----------------------------------------------------------------------------
// Stable ID: aa_004f6fd0
// Address:   0x004f6fd0  (autoassault.exe, image base 0x400000)
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

undefined * __thiscall FUN_004f6fd0(int param_1,int param_2)

{
  int iVar1;
  int unaff_retaddr;
  
  if (*(int **)(param_1 + -0x41c) != (int *)0x0) {
    iVar1 = (**(code **)(**(int **)(param_1 + -0x41c) + 0x38))();
    if (iVar1 != 0) {
      iVar1 = (**(code **)(**(int **)(param_1 + -0x41c) + 0x38))();
      return (undefined *)(iVar1 + param_2 * 2);
    }
  }
  iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x66c + param_1) + 0x210
                      ))(0);
  if (iVar1 != 0) {
    return &DAT_00b041f0 + unaff_retaddr * 2;
  }
  return (undefined *)
         (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x5c4 + param_1) + 0x3c) +
          0x48c + unaff_retaddr * 2);
}
