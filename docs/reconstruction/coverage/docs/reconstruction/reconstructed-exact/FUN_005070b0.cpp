// =============================================================================
// FUN_005070b0
// -----------------------------------------------------------------------------
// Stable ID: aa_005070b0
// Address:   0x005070b0  (autoassault.exe, image base 0x400000)
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

void __thiscall FUN_005070b0(int param_1,uint8_t *param_2)

{
  if (*(int *)(param_1 + 0x44) == 0) {
    *param_2 = 0;
    return;
  }
  *param_2 = *(uint8_t *)(*(int *)(param_1 + 0x44) + 0x29);
  return;
}
