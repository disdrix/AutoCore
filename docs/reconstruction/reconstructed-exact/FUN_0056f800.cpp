// =============================================================================
// FUN_0056f800
// -----------------------------------------------------------------------------
// Stable ID: aa_0056f800
// Address:   0x0056f800  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0056f800 @ 0x0056f800
// Stable ID: aa_0056f800
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00512670, FUN_00513e70, FUN_0056f800.
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

void __thiscall FUN_0056f800(int param_1,int param_2)



{

  char cVar1;

  

  cVar1 = FUN_00513e70();

  if (cVar1 != '\0') {

    if (*(int *)(param_1 + -0x2c) != param_2) {

      FUN_00512670();

    }

    *(int *)(param_1 + -0x2c) = param_2;

    return;

  }

  *(int *)(param_1 + -0x2c) = param_2;

  return;

}
