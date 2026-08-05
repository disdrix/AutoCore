// =============================================================================
// FUN_0073f750
// -----------------------------------------------------------------------------
// Stable ID: aa_0073f750
// Address:   0x0073f750  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0073f750 @ 0x0073f750
// Stable ID: aa_0073f750
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: FUN_0073f750.
//  - Return sites: 3.

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

int __thiscall FUN_0073f750(int param_1,uint param_2)



{

  uint uVar1;

  

  if (param_2 == 0) {

    return param_1 + 8;

  }

  if (-1 < (int)param_2) {

    uVar1 = 0;

    if (*(int *)(param_1 + 0x28) != 0) {

      uVar1 = (*(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x28)) / 0x1c;

    }

    if (param_2 <= uVar1) {

      return *(int *)(param_1 + 0x28) + -0x1c + param_2 * 0x1c;

    }

  }

  return 0;

}
