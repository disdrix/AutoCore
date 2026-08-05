// =============================================================================
// FUN_004e32b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004e32b0
// Address:   0x004e32b0  (autoassault.exe, image base 0x400000)
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

void __fastcall FUN_004e32b0(uint32_t /* width from decompiler */ *param_1)

{
  *param_1 = &PTR_FUN_009cc3f4;
  FUN_004e32e0(1);
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 10));
  return;
}
