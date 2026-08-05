// =============================================================================
// FUN_008a05a0
// -----------------------------------------------------------------------------
// Stable ID: aa_008a05a0
// Address:   0x008a05a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008a05a0 @ 0x008a05a0
// Stable ID: aa_008a05a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_008a0370, FUN_008a05a0, FUN_008af180.
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

void FUN_008a05a0(void)



{

  int unaff_EDI;

  

  if (*(int *)(unaff_EDI + 0x684) != 0) {

    FUN_008af180(0);

    FUN_008a0370();

    if (*(int *)(unaff_EDI + 0x664) != 0) {

                    /* WARNING: Could not recover jumptable at 0x008a05cb. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(**(int **)(unaff_EDI + 0x664) + 0x480))();

      return;

    }

  }

  return;

}
