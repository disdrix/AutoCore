// =============================================================================
// FUN_004e6930
// -----------------------------------------------------------------------------
// Stable ID: aa_004e6930
// Address:   0x004e6930  (autoassault.exe, image base 0x400000)
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

void __thiscall FUN_004e6930(int param_1,uint32_t /* width from decompiler */ *param_2)

{
  *param_2 = &PTR_LAB_009cc6e4;
  *param_2 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x20);
  *(uint32_t /* width from decompiler */ **)(param_1 + 0x20) = param_2;
  return;
}
