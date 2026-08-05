// =============================================================================
// FUN_007195fe
// -----------------------------------------------------------------------------
// Stable ID: aa_007195fe
// Address:   0x007195fe  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007195fe @ 0x007195fe
// Stable ID: aa_007195fe
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: memcpy×2.
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

void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size)



{

  void *pvVar1;

  

                    /* WARNING: Could not recover jumptable at 0x007195fe. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  pvVar1 = memcpy(_Dst,_Src,_Size);

  return pvVar1;

}
