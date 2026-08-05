// =============================================================================
// FUN_00423580
// -----------------------------------------------------------------------------
// Stable ID: aa_00423580
// Address:   0x00423580  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00423580 @ 0x00423580
// Stable ID: aa_00423580
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: while×1, return×1.
//  - Notable callees: FUN_00423580, free.
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

void __fastcall FUN_00423580(int *param_1)



{

  int iVar1;

  int *_Memory;

  

  iVar1 = *param_1;

  while (iVar1 != 0) {

    _Memory = (int *)*param_1;

    *param_1 = *_Memory;

    free(_Memory);

    iVar1 = *param_1;

  }

  return;

}
