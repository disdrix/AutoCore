// =============================================================================
// __onexit
// -----------------------------------------------------------------------------
// Stable ID: aa_004898b0
// Address:   0x004898b0  (autoassault.exe, image base 0x400000)
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
    __onexit
   
   Library: Visual Studio 2003 Release */

void __onexit(_onexit_t param_1)

{
  if (DAT_00d21a08 == -1) {
                    /* WARNING: Could not recover jumptable at 0x004898b9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    _onexit(param_1);
    return;
  }
  __dllonexit(param_1,&DAT_00d21a08,&DAT_00d21a04);
  return;
}
