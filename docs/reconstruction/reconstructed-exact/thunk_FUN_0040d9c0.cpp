// =============================================================================
// thunk_FUN_0040d9c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0040fd50
// Address:   0x0040fd50  (autoassault.exe, image base 0x400000)
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

void thunk_FUN_0040d9c0(void)

{
  void *pvVar1;
  int iVar2;
  int unaff_ESI;
  
  iVar2 = *(int *)(unaff_ESI + 0x10);
  while (iVar2 != 0) {
    if ((*(int *)(unaff_ESI + 0x10) != 0) &&
       (iVar2 = *(int *)(unaff_ESI + 0x10) + -1, *(int *)(unaff_ESI + 0x10) = iVar2, iVar2 == 0)) {
      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc) = 0;
    }
    iVar2 = *(int *)(unaff_ESI + 0x10);
  }
  iVar2 = *(int *)(unaff_ESI + 8);
  while (iVar2 != 0) {
    pvVar1 = *(void **)(*(int *)(unaff_ESI + 4) + -4 + iVar2 * 4);
    iVar2 = iVar2 + -1;
    if (pvVar1 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete(pvVar1);
    }
  }
  if (*(void **)(unaff_ESI + 4) != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(*(void **)(unaff_ESI + 4));
  }
  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8) = 0;
  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 4) = 0;
  return;
}
