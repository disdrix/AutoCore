// =============================================================================
// FUN_00778a00
// -----------------------------------------------------------------------------
// Stable ID: aa_00778a00
// Address:   0x00778a00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00778a00 @ 0x00778a00
// Stable ID: aa_00778a00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00771cb0, FUN_00778a00, free, malloc.
//  - Return sites: 2.

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

void * FUN_00778a00(void)



{

  void *_Memory;

  int iVar1;

  

  _Memory = malloc(0x30);

  if (_Memory != (void *)0x0) {

    iVar1 = FUN_00771cb0(_Memory,(int)_Memory + 0x10,(int)_Memory + 0x20,0);

    if (iVar1 == 0) {

      return _Memory;

    }

    free(_Memory);

  }

  return (void *)0x0;

}
