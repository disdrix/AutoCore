// =============================================================================
// FUN_00826150
// -----------------------------------------------------------------------------
// Stable ID: aa_00826150
// Address:   0x00826150  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00826150 @ 0x00826150
// Stable ID: aa_00826150
// Embedded strings (evidence for future rename):
//   - ");

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: sprintf×2, FUN_00826150.
//  - Strings: ");

    }

    else {

      sprintf(local_10,".
//  - Return sites: 1.

    }

    else {

      sprintf(local_10,"
// Readability: control flow preserved from Ghidra decompile; types tentative.

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

void FUN_00826150(void)



{

  int in_EAX;

  int unaff_ESI;

  char local_10 [16];

  

  *(int *)(unaff_ESI + 0x500) = in_EAX;

  if (*(int *)(unaff_ESI + 0x568) != 0) {

    if (in_EAX == 9) {

      sprintf(local_10,"0");

    }

    else {

      sprintf(local_10,"%i",in_EAX + 1);

    }

    (**(code **)(**(int **)(unaff_ESI + 0x568) + 0x1d8))(local_10,1,1);

    (**(code **)(**(int **)(unaff_ESI + 0x568) + 0x34c))();

  }

  return;

}
