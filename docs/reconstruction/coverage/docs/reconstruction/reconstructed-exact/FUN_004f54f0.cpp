// =============================================================================
// FUN_004f54f0
// -----------------------------------------------------------------------------
// Stable ID: aa_004f54f0
// Address:   0x004f54f0  (autoassault.exe, image base 0x400000)
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

void __thiscall FUN_004f54f0(int param_1,uint32_t /* width from decompiler */ param_2,char param_3)

{
  char cVar1;
  
  cVar1 = (char)((int)(*(uint *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac +
                                                  param_1) + 0x3c) + 0x50c) &
                      7 << (param_3 * '\x03' & 0x1fU)) >> (param_3 * '\x03' & 0x1fU));
  if ((-1 < cVar1) && (cVar1 < '\x02')) {
    FUN_00567ce0(&DAT_00af18b0,0);
    return;
  }
  FUN_00567ce0(&DAT_00af18b0,*(uint32_t /* width from decompiler */ *)(param_1 + 0x158));
  return;
}
