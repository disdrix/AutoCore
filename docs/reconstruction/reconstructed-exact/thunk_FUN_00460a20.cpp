// =============================================================================
// thunk_FUN_00460a20
// -----------------------------------------------------------------------------
// Stable ID: aa_00428c20
// Address:   0x00428c20  (autoassault.exe, image base 0x400000)
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

void thunk_FUN_00460a20(void)

{
  uint32_t /* width from decompiler */ *puVar1;
  int unaff_EDI;
  
  puVar1 = *(uint32_t /* width from decompiler */ **)(unaff_EDI + 8);
  if (puVar1 != *(uint32_t /* width from decompiler */ **)(unaff_EDI + 0xc)) {
    do {
      _aligned_free((void *)*puVar1);
      puVar1 = puVar1 + 1;
    } while (puVar1 != *(uint32_t /* width from decompiler */ **)(unaff_EDI + 0xc));
  }
  if (*(void **)(unaff_EDI + 8) == (void *)0x0) {
    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 8) = 0;
    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xc) = 0;
    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x10) = 0;
    return;
  }
                    /* WARNING: Subroutine does not return */
  operator_delete(*(void **)(unaff_EDI + 8));
}
