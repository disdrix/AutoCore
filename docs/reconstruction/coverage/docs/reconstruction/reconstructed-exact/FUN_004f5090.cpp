// =============================================================================
// FUN_004f5090
// -----------------------------------------------------------------------------
// Stable ID: aa_004f5090
// Address:   0x004f5090  (autoassault.exe, image base 0x400000)
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

void __thiscall FUN_004f5090(int param_1,uint32_t /* width from decompiler */ param_2)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    piVar1 = *(int **)(iVar3 + *(int *)(param_1 + 0x260));
    if (piVar1 != (int *)0x0) {
      cVar2 = (**(code **)(*piVar1 + 0x40))();
      if (cVar2 != '\0') {
        FUN_0056c010(param_2);
      }
    }
    iVar3 = iVar3 + 4;
  } while (iVar3 < 0xc);
  return;
}
