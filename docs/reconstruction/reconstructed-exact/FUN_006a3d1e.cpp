// =============================================================================
// FUN_006a3d1e
// -----------------------------------------------------------------------------
// Stable ID: aa_006a3d1e
// Address:   0x006a3d1e  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006a3d1e @ 0x006a3d1e
// Stable ID: aa_006a3d1e
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: memset×2.
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

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)



{

  void *pvVar1;

  

                    /* WARNING: Could not recover jumptable at 0x006a3d1e. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  pvVar1 = memset(_Dst,_Val,_Size);

  return pvVar1;

}
