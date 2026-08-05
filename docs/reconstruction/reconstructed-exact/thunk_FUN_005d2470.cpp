// =============================================================================
// thunk_FUN_005d2470
// -----------------------------------------------------------------------------
// Stable ID: aa_005d8350
// Address:   0x005d8350  (autoassault.exe, image base 0x400000)
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

void __fastcall thunk_FUN_005d2470(int param_1)

{
  uint8_t auStack_10 [4];
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t /* width from decompiler */ uStack_4;
  
  puStack_8 = &LAB_009a7038;
  pvStack_c = ExceptionList;
  uStack_4 = 0;
  ExceptionList = &pvStack_c;
  FUN_005d22a0(auStack_10,**(uint32_t /* width from decompiler */ **)(param_1 + 0x9c),*(uint32_t /* width from decompiler */ **)(param_1 + 0x9c));
                    /* WARNING: Subroutine does not return */
  operator_delete(*(void **)(param_1 + 0x9c));
}
