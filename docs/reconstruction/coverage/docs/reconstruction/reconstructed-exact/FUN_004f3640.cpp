// =============================================================================
// FUN_004f3640
// -----------------------------------------------------------------------------
// Stable ID: aa_004f3640
// Address:   0x004f3640  (autoassault.exe, image base 0x400000)
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

void __thiscall FUN_004f3640(int param_1,int param_2,char param_3)

{
  if ((*(int *)(param_1 + 0x284) != 0) &&
     ((param_3 != '\0' || (*(int *)(*(int *)(param_1 + 0x284) + 0x10) != param_2)))) {
    FUN_005a53e0(1);
    *(int *)(*(int *)(param_1 + 0x284) + 0x10) = param_2;
  }
  return;
}
