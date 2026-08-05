// =============================================================================
// GhostObject_OnGhostAdd
// -----------------------------------------------------------------------------
// Stable ID: aa_005b0d70
// Address:   0x005b0d70  (autoassault.exe, image base 0x400000)
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

uint32_t /* width from decompiler */ __fastcall GhostObject_OnGhostAdd(int param_1)

{
  if (*(int *)(param_1 + 0x50) != 0) {
    (**(code **)(**(int **)(param_1 + 0x50) + 0x2b8))(param_1);
    return 1;
  }
  FUN_005a0b30(param_1,param_1 + 0x40);
  return 1;
}
