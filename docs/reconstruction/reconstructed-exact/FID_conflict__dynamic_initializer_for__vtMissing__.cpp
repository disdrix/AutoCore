// =============================================================================
// FID_conflict__dynamic_initializer_for__vtMissing__
// -----------------------------------------------------------------------------
// Stable ID: aa_009c2ec0
// Address:   0x009c2ec0  (autoassault.exe, image base 0x400000)
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

/* Library Function - Multiple Matches With Different Base Names
    void __cdecl `dynamic initializer for 'vtMissing''(void)
    _$E1
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug */

void FID_conflict__dynamic_initializer_for__vtMissing__(void)

{
  _variant_t::_variant_t((_variant_t *)&DAT_00d09850,-0x7ffdfffc,10);
  _atexit(FUN_009c5cf0);
  return;
}
