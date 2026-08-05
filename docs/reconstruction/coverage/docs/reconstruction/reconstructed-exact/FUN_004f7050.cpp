// =============================================================================
// FUN_004f7050
// -----------------------------------------------------------------------------
// Stable ID: aa_004f7050
// Address:   0x004f7050  (autoassault.exe, image base 0x400000)
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

int __fastcall FUN_004f7050(int param_1)

{
  int iVar1;
  
  if (*(char *)(*(int *)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x5c8 + param_1) + 0xf5) !=
      '\0') {
    iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x66c + param_1) +
                        0x210))(0);
    if (iVar1 != 0) {
      iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x66c + param_1) +
                          0x210))(0);
                    /* WARNING: Could not recover jumptable at 0x004f70b5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x1a0))();
      return iVar1;
    }
  }
  if (*(int *)(param_1 + -0x668) != 0) {
    return *(int *)(*(int *)(param_1 + -0x668) + 0x3c) + 0xb0;
  }
  return *(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x5ec + param_1;
}
