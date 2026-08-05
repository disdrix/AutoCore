// =============================================================================
// FUN_004e6730
// -----------------------------------------------------------------------------
// Stable ID: aa_004e6730
// Address:   0x004e6730  (autoassault.exe, image base 0x400000)
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

void __fastcall FUN_004e6730(uint32_t /* width from decompiler */ *param_1)

{
  void *local_c;
  uint8_t *puStack_8;
  uint32_t /* width from decompiler */ local_4;
  
  puStack_8 = &LAB_009a256b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_009cc6cc;
  local_4 = 0;
  if (*(char *)((int)param_1 + 0x1d) != '\0') {
    FUN_007a4480(0,"HashError:Destructor, already locked for traversal");
    FUN_007a4480(0,"VOG_DEBUG_STOP");
  }
  FUN_004e67a0();
  FUN_0059c8a0();
  ExceptionList = local_c;
  return;
}
