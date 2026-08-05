// =============================================================================
// FUN_008a7100
// -----------------------------------------------------------------------------
// Stable ID: aa_008a7100
// Address:   0x008a7100  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008a7100 @ 0x008a7100
// Stable ID: aa_008a7100
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_008a7100.
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

void FUN_008a7100(void)



{

  int unaff_ESI;

  int unaff_EDI;

  

  if (*(int *)(unaff_ESI + 0x554) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x554) + 0x74))();

    if (unaff_EDI < 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x554) + 0xcc))(0);

    }

    else {

      (**(code **)(**(int **)(unaff_ESI + 0x554) + 0xcc))(1);

    }

                    /* WARNING: Could not recover jumptable at 0x008a713d. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(**(int **)(unaff_ESI + 0x554) + 0x34c))();

    return;

  }

  return;

}
