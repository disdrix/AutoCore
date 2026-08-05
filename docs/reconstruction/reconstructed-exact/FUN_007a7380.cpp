// =============================================================================
// FUN_007a7380
// -----------------------------------------------------------------------------
// Stable ID: aa_007a7380
// Address:   0x007a7380  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a7380 @ 0x007a7380
// Stable ID: aa_007a7380
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×9, return×8.
//  - Notable callees: FUN_007a7380.
//  - Return sites: 8.

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

uint32_t /* width from decompiler */ FUN_007a7380(int param_1)



{

  bool bVar1;

  

  if (param_1 < 0x32545845) {

    if (param_1 == 0x32545844) {

      return 1;

    }

    if (param_1 < 0x1b) {

      if (param_1 < 0x19) {

        if (param_1 < 0x15) {

          return 0xffffffff;

        }

        if (0x17 < param_1) {

          return 0xffffffff;

        }

      }

      return 0;

    }

    bVar1 = param_1 == 0x31545844;

  }

  else {

    if (param_1 == 0x33545844) {

      return 1;

    }

    if (param_1 == 0x34545844) {

      return 1;

    }

    bVar1 = param_1 == 0x35545844;

  }

  if (bVar1) {

    return 1;

  }

  return 0xffffffff;

}
