// =============================================================================
// FUN_00594290
// -----------------------------------------------------------------------------
// Stable ID: aa_00594290
// Address:   0x00594290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00594290 @ 0x00594290
// Stable ID: aa_00594290
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_005911b0, FUN_00594290, FUN_00596f00.
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

void FUN_00594290(void)



{

  int *piVar1;

  

  piVar1 = DAT_00b04e68;

  if (DAT_00b04e68 != DAT_00b04e6c) {

    do {

      FUN_005911b0(1);

      *(byte *)(*piVar1 + 0x910) = *(byte *)(*piVar1 + 0x910) | 1;

      piVar1 = piVar1 + 1;

    } while (piVar1 != DAT_00b04e6c);

  }

  FUN_00596f00(0,0);

  return;

}
