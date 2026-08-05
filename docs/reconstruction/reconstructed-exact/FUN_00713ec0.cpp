// =============================================================================
// FUN_00713ec0
// -----------------------------------------------------------------------------
// Stable ID: aa_00713ec0
// Address:   0x00713ec0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00713ec0 @ 0x00713ec0
// Stable ID: aa_00713ec0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×4, return×4.
//  - Notable callees: FUN_00713ec0.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



int FUN_00713ec0(float *param_1,int param_2,int param_3)



{

  param_2 = param_2 + -1;

  if (param_3 < param_2) {

    if ((param_3 == 0) || (_DAT_00a11068 * *param_1 <= param_1[param_3])) {

      if (param_1[param_2] < _DAT_00a1106c * param_1[param_3]) {

        return param_3;

      }

      return param_2;

    }

  }

  else if (_DAT_00a11070 * *param_1 <= param_1[param_2]) {

    return param_2;

  }

  return 0;

}
