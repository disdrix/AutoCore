// =============================================================================
// fputs
// -----------------------------------------------------------------------------
// Stable ID: aa_0048990c
// Address:   0x0048990c  (autoassault.exe, image base 0x400000)
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

int __cdecl fputs(char *_Str,FILE *_File)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0048990c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = fputs(_Str,_File);
  return iVar1;
}
