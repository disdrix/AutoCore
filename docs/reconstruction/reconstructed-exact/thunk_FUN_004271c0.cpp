// =============================================================================
// thunk_FUN_004271c0
// -----------------------------------------------------------------------------
// Stable ID: aa_00427040
// Address:   0x00427040  (autoassault.exe, image base 0x400000)
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

void thunk_FUN_004271c0(void)

{
  int iVar1;
  int unaff_EBX;
  int iVar2;
  
  iVar2 = *(int *)(unaff_EBX + 4);
  if (iVar2 == 0) {
    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 4) = 0;
    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 8) = 0;
    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0xc) = 0;
    return;
  }
  iVar1 = *(int *)(unaff_EBX + 8);
  for (; iVar2 != iVar1; iVar2 = iVar2 + 0x80) {
    FUN_00426f70();
  }
                    /* WARNING: Subroutine does not return */
  operator_delete(*(void **)(unaff_EBX + 4));
}
