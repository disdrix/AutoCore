// =============================================================================
// FUN_0075c900
// -----------------------------------------------------------------------------
// Stable ID: aa_0075c900
// Address:   0x0075c900  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0075c900 @ 0x0075c900
// Stable ID: aa_0075c900
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0043f5e0, FUN_0075c500, FUN_0075c900, FUN_00972fa0.
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

uint32_t /* width from decompiler */ FUN_0075c900(void)



{

  uint32_t /* width from decompiler */ uVar1;

  int unaff_ESI;

  uint8_t local_c [12];

  

  if (*(char *)(unaff_ESI + 0x2c) != '\0') {

    return 0xffffffff;

  }

  FUN_0075c500();

  FUN_00972fa0(unaff_ESI);

  uVar1 = FUN_0043f5e0(local_c);

  return uVar1;

}
