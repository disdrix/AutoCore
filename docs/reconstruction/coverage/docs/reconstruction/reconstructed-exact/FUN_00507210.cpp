// =============================================================================
// FUN_00507210
// -----------------------------------------------------------------------------
// Stable ID: aa_00507210
// Address:   0x00507210  (autoassault.exe, image base 0x400000)
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

void __thiscall FUN_00507210(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x80)) {
    piVar2 = *(int **)(param_1 + 0x7c);
    do {
      if (*piVar2 == param_2) goto LAB_00507236;
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x80));
  }
  iVar1 = -1;
LAB_00507236:
  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x7c) + iVar1 * 4) = 0;
  if (*(int *)(param_1 + 8) != 0) {
    FUN_0055ec00();
    return;
  }
  return;
}
