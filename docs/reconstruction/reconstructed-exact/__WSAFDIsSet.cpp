// =============================================================================
// __WSAFDIsSet
// -----------------------------------------------------------------------------
// Stable ID: aa_00717e82
// Address:   0x00717e82  (autoassault.exe, image base 0x400000)
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

int __WSAFDIsSet(SOCKET param_1,fd_set *param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00717e82. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = __WSAFDIsSet(param_1,param_2);
  return iVar1;
}
