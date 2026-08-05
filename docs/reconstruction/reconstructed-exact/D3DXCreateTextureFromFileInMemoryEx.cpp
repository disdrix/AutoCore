// =============================================================================
// D3DXCreateTextureFromFileInMemoryEx
// -----------------------------------------------------------------------------
// Stable ID: aa_006a5d64
// Address:   0x006a5d64  (autoassault.exe, image base 0x400000)
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

void D3DXCreateTextureFromFileInMemoryEx(void)

{
                    /* WARNING: Could not recover jumptable at 0x006a5d64. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  D3DXCreateTextureFromFileInMemoryEx();
  return;
}
