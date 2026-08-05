// =============================================================================
// FUN_004f5110
// -----------------------------------------------------------------------------
// Stable ID: aa_004f5110
// Address:   0x004f5110  (autoassault.exe, image base 0x400000)
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

byte __fastcall FUN_004f5110(int param_1)

{
  int *piVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  
  bVar4 = 0;
  iVar5 = 0;
  do {
    piVar1 = *(int **)(iVar5 + *(int *)(param_1 + 0x260));
    if (piVar1 != (int *)0x0) {
      cVar2 = (**(code **)(*piVar1 + 0x3c))();
      if (cVar2 != '\0') {
        bVar3 = FUN_0056d520();
        bVar4 = bVar4 | bVar3;
      }
    }
    iVar5 = iVar5 + 4;
  } while (iVar5 < 0xc);
  return bVar4;
}
