// =============================================================================
// ftell
// -----------------------------------------------------------------------------
// Stable ID: aa_006a3d48
// Address:   0x006a3d48  (autoassault.exe, image base 0x400000)
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

long __cdecl ftell(FILE *_File)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x006a3d48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = ftell(_File);
  return lVar1;
}
