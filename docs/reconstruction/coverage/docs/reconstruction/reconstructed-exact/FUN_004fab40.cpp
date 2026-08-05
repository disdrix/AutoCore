// =============================================================================
// FUN_004fab40
// -----------------------------------------------------------------------------
// Stable ID: aa_004fab40
// Address:   0x004fab40  (autoassault.exe, image base 0x400000)
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

void __thiscall FUN_004fab40(int param_1,uint32_t /* width from decompiler */ param_2)

{
  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1ac) = param_2;
  if (DAT_00b042b8 < 1) {
    FUN_00519a30();
  }
  if (*(int *)(param_1 + 0x1ac) < 0) {
    *(uint32_t /* width from decompiler */ *)(param_1 + 0x1ac) = 0;
    return;
  }
  if (DAT_00b042b8 <= *(int *)(param_1 + 0x1ac)) {
    *(int *)(param_1 + 0x1ac) = DAT_00b042b8;
  }
  return;
}
