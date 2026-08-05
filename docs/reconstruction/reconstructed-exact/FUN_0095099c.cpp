// =============================================================================
// FUN_0095099c
// -----------------------------------------------------------------------------
// Stable ID: aa_0095099c
// Address:   0x0095099c  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0095099c @ 0x0095099c
// Stable ID: aa_0095099c
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00531960, FUN_008a05a0, FUN_0095099c.
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

uint32_t /* width from decompiler */ FUN_0095099c(void)



{

  char cVar1;

  int unaff_ESI;

  

  FUN_00531960();

  if (*(int *)(unaff_ESI + 0x10b0) != 0) {

    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x10b0) + 0x3d8))();

    if (cVar1 != '\0') {

      FUN_008a05a0();

    }

  }

  return 1;

}
