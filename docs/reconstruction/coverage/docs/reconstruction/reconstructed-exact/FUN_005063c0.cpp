// =============================================================================
// FUN_005063c0
// -----------------------------------------------------------------------------
// Stable ID: aa_005063c0
// Address:   0x005063c0  (autoassault.exe, image base 0x400000)
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

void __thiscall FUN_005063c0(int param_1,uint32_t /* width from decompiler */ param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xac);
  while (iVar1 != 0) {
    param_1 = *(int *)(param_1 + 0xac);
    iVar1 = *(int *)(param_1 + 0xac);
  }
  *(uint32_t /* width from decompiler */ *)(param_1 + 0x60) = param_2;
  return;
}
