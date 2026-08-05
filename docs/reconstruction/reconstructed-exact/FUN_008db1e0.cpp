// =============================================================================
// FUN_008db1e0
// -----------------------------------------------------------------------------
// Stable ID: aa_008db1e0
// Address:   0x008db1e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008db1e0 @ 0x008db1e0
// Stable ID: aa_008db1e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: FUN_008db1e0, sprintf.
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

void FUN_008db1e0(void)



{

  int unaff_ESI;

  char local_20 [32];

  

  if (*(char *)(unaff_ESI + 0x518) == '\0') {

    if (*(int *)(unaff_ESI + 0x5a4) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x5a4) + 4))(0);

    }

  }

  else if (*(int *)(unaff_ESI + 0x5a4) != 0) {

    if (*(int *)(unaff_ESI + 0x544) != 0) {

      sprintf(local_20,"%d",*(int *)(unaff_ESI + 0x544) + 1);

      (**(code **)(**(int **)(unaff_ESI + 0x5a4) + 0x1d8))(local_20,1,1);

      (**(code **)(**(int **)(unaff_ESI + 0x5a4) + 0xcc))(1);

      (**(code **)(**(int **)(unaff_ESI + 0x5a4) + 0x34c))();

      return;

    }

    (**(code **)(**(int **)(unaff_ESI + 0x5a4) + 4))(0);

    return;

  }

  return;

}
