// =============================================================================
// FUN_006f2130
// -----------------------------------------------------------------------------
// Stable ID: aa_006f2130
// Address:   0x006f2130  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f2130 @ 0x006f2130
// Stable ID: aa_006f2130
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×4, return×4.
//  - Notable callees: FUN_006f2130, FUN_006f3a00, FUN_006f3a60, FUN_006f3af0, FUN_006f3c40.
//  - Return sites: 4.

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

void __thiscall FUN_006f2130(int param_1,int param_2)



{

  param_2 = *(int *)(*(int *)(param_1 + 0x10) + 0xc) - param_2;

  if (0 < param_2) {

    if (param_2 < 0xff) {

      FUN_006f3a00(5,param_2);

      return;

    }

    if (param_2 < 0xffff) {

      FUN_006f3a60(6,param_2);

      return;

    }

    if (param_2 < 0xffffff) {

      FUN_006f3af0(7,param_2);

      return;

    }

    FUN_006f3c40(8,param_2);

  }

  return;

}
