// =============================================================================
// FUN_004fd970
// -----------------------------------------------------------------------------
// Stable ID: aa_004fd970
// Address:   0x004fd970  (autoassault.exe, image base 0x400000)
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

uint32_t /* width from decompiler */ __thiscall FUN_004fd970(int param_1,char param_2)

{
  if (param_2 == *(char *)(param_1 + 0x288)) {
    return 0;
  }
  FUN_00512670();
  *(char *)(param_1 + 0x288) = param_2;
  FUN_004fcd80(0);
  return 1;
}
