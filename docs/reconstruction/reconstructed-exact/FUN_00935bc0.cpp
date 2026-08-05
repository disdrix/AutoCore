// =============================================================================
// FUN_00935bc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00935bc0
// Address:   0x00935bc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00935bc0 @ 0x00935bc0
// Stable ID: aa_00935bc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: strncpy×2, FUN_007290e0, FUN_008075f0, FUN_00935bc0.
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

void FUN_00935bc0(void)



{

  int iVar1;

  int unaff_ESI;

  

  if (*(int *)(unaff_ESI + 0xcc) != 0) {

    FUN_007290e0(*(int *)(unaff_ESI + 0xcc));

  }

  iVar1 = *(int *)(unaff_ESI + 0xe0c);

  strncpy((char *)(unaff_ESI + 0xd0),(char *)(iVar1 + 0xc),0x20);

  *(uint8_t *)(unaff_ESI + 0xf0) = 0;

  strncpy((char *)(unaff_ESI + 0xf1),(char *)(iVar1 + 0x2d),0x20);

  *(uint8_t *)(unaff_ESI + 0x111) = 0;

  FUN_008075f0(unaff_ESI);

  return;

}
