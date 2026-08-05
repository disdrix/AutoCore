// =============================================================================
// FUN_005123e0
// -----------------------------------------------------------------------------
// Stable ID: aa_005123e0
// Address:   0x005123e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005123e0 @ 0x005123e0
// Stable ID: aa_005123e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×7, return×5.
//  - Notable callees: FUN_005123e0.
//  - Return sites: 5.

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

uint32_t /* width from decompiler */ FUN_005123e0(uint param_1,int param_2)



{

  if (-1 < param_2) {

    if ((0 < param_2) || (999999999 < param_1)) {

      return DAT_00af1b5c;

    }

    if (-1 < param_2) {

      if ((0 < param_2) || (999999 < param_1)) {

        return DAT_00af1b58;

      }

      if (-1 < param_2) {

        if ((0 < param_2) || (999 < param_1)) {

          return DAT_00af1b54;

        }

        if ((-1 < param_2) && ((0 < param_2 || (param_1 != 0)))) {

          return DAT_00af1b50;

        }

      }

    }

  }

  return 0xffffffff;

}
