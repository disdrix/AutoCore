// =============================================================================
// _com_issue_error
// -----------------------------------------------------------------------------
// Stable ID: aa_00717f00
// Address:   0x00717f00  (autoassault.exe, image base 0x400000)
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

/* Library Function - Single Match
    void __stdcall _com_issue_error(long)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug */

void _com_issue_error(long param_1)

{
  (*(code *)PTR_FUN_00af8b20)(param_1,0);
  return;
}
