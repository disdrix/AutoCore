// =============================================================================
// FUN_004fbb50
// -----------------------------------------------------------------------------
// Stable ID: aa_004fbb50
// Address:   0x004fbb50  (autoassault.exe, image base 0x400000)
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

void __thiscall FUN_004fbb50(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  
  if ((*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1) != 0) &&
     (param_2 != (int *)0x0)) {
    FUN_004e2600(&LAB_004f5400,param_2 + 0x58,0);
    piVar1 = *(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1);
    if ((piVar1 != (int *)0x0) &&
       ((iVar2 = (**(code **)(*piVar1 + 0x1dc))(), iVar2 != 0 &&
        (iVar2 = (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1) +
                             0x1dc))(), *(int *)(iVar2 + 0x250) != 0)))) {
      (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1) + 0x1dc))();
      FUN_004e2600(&LAB_004f5400,param_2 + 0x58,0);
    }
    (**(code **)(*param_2 + 0x40))(1);
  }
  return;
}
