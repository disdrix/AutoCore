// =============================================================================
// FUN_004e53a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004e53a0
// Address:   0x004e53a0  (autoassault.exe, image base 0x400000)
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

uint32_t /* width from decompiler */ __thiscall FUN_004e53a0(int param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xef0) + 0x10) +
                           (*(uint *)(*(int *)(param_1 + 0xef0) + 8) & param_2) * 4) + 4);
  if (iVar1 != 0) {
    while (param_2 != *(uint *)(iVar1 + 0x10)) {
      iVar1 = *(int *)(iVar1 + 0xc);
      if (iVar1 == 0) {
        return 0;
      }
    }
    if (iVar1 != 0) {
      return *(uint32_t /* width from decompiler */ *)(iVar1 + 8);
    }
  }
  return 0;
}
