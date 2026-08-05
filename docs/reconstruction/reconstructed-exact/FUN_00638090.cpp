// =============================================================================
// FUN_00638090
// -----------------------------------------------------------------------------
// Stable ID: aa_00638090
// Address:   0x00638090  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00638090 @ 0x00638090
// Stable ID: aa_00638090
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: strrchr×2.
//  - Return sites: 1.

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

char * __cdecl strrchr(char *_Str,int _Ch)



{

  char *pcVar1;

  

                    /* WARNING: Could not recover jumptable at 0x00638090. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  pcVar1 = strrchr(_Str,_Ch);

  return pcVar1;

}
