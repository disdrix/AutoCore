// =============================================================================
// FUN_007fb560
// -----------------------------------------------------------------------------
// Stable ID: aa_007fb560
// Address:   0x007fb560  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fb560 @ 0x007fb560
// Stable ID: aa_007fb560
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_007fb560.
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

void FUN_007fb560(void)



{

  char cVar1;

  int unaff_ESI;

  

  if (*(int *)(unaff_ESI + 0xf38) != 0) {

    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0xf38) + 0x3d8))();

    if ((cVar1 != '\0') && (*(int *)(*(int *)(unaff_ESI + 0xf38) + 0xcb4) != 0)) {

      cVar1 = (**(code **)(**(int **)(*(int *)(unaff_ESI + 0xf38) + 0xcb4) + 0x3d8))();

      if (cVar1 != '\0') {

        cVar1 = (**(code **)(**(int **)(*(int *)(unaff_ESI + 0xf38) + 0xcb4) + 0xd0))();

        if (cVar1 != '\0') {

                    /* WARNING: Could not recover jumptable at 0x007fb5c4. Too many branches */

                    /* WARNING: Treating indirect jump as call */

          (**(code **)(**(int **)(*(int *)(unaff_ESI + 0xf38) + 0xcb4) + 0x94))();

          return;

        }

      }

    }

  }

  return;

}
