// =============================================================================
// FUN_004f4ff0
// -----------------------------------------------------------------------------
// Stable ID: aa_004f4ff0
// Address:   0x004f4ff0  (autoassault.exe, image base 0x400000)
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

void __thiscall FUN_004f4ff0(int param_1,char param_2,int param_3)

{
  int *piVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  
  bVar2 = false;
  iVar5 = 0;
  do {
    piVar1 = *(int **)(*(int *)(param_1 + 0x260) + iVar5);
    if (piVar1 != (int *)0x0) {
      cVar3 = (**(code **)(*piVar1 + 0x40))();
      if (cVar3 != '\0') {
        if ((param_2 == '\0') || (*(char *)(param_1 + 0x108) == '\0')) {
          iVar4 = (**(code **)(*piVar1 + 0x5c))
                            (*(uint32_t /* width from decompiler */ *)
                              (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 +
                                                param_1) + 0xe4e8) + 0x1c),param_3);
          bVar2 = (bool)(bVar2 | 0 < iVar4);
        }
        else {
          FUN_0056bf70();
          bVar2 = false;
        }
      }
    }
    iVar5 = iVar5 + 4;
  } while (iVar5 < 0xc);
  if ((!bVar2) && (param_3 == 0)) {
    *(uint8_t *)(param_1 + 0x108) = 0;
    return;
  }
  *(uint8_t *)(param_1 + 0x108) = 1;
  return;
}
