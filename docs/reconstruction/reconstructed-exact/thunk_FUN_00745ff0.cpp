// =============================================================================
// thunk_FUN_00745ff0
// -----------------------------------------------------------------------------
// Stable ID: aa_0043b990
// Address:   0x0043b990  (autoassault.exe, image base 0x400000)
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

void __fastcall thunk_FUN_00745ff0(uint32_t /* width from decompiler */ *param_1)

{
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t /* width from decompiler */ uStack_4;
  
  puStack_8 = &LAB_009ac17e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_00aa1d40;
  uStack_4 = 0;
  FUN_00745f80();
  if ((uint32_t /* width from decompiler */ *)param_1[5] != (uint32_t /* width from decompiler */ *)0x0) {
    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[5])(1);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  *(uint8_t *)(param_1 + 0xe) = 0;
  ExceptionList = pvStack_c;
  return;
}
