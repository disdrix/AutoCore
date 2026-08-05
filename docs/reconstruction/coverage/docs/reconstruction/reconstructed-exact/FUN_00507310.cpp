// =============================================================================
// FUN_00507310
// -----------------------------------------------------------------------------
// Stable ID: aa_00507310
// Address:   0x00507310  (autoassault.exe, image base 0x400000)
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

void __thiscall FUN_00507310(int param_1,uint32_t /* width from decompiler */ param_2)

{
  if (*(uint *)(param_1 + 0x80) == (*(uint *)(param_1 + 0x84) & 0x7fffffff)) {
    FUN_005b3370((int *)(param_1 + 0x7c),4);
  }
  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x7c) + *(int *)(param_1 + 0x80) * 4) = param_2;
  *(int *)(param_1 + 0x80) = *(int *)(param_1 + 0x80) + 1;
  return;
}
