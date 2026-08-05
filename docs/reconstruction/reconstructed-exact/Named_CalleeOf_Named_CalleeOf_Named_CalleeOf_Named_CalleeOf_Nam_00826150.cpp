// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00826150
// -----------------------------------------------------------------------------
// Stable ID: aa_00826150
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mis
// Address:   0x00826150  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mis: callee helper. Evidence string: ");

    }

    else {

      sprintf(local_10,". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - ");

    }

    else {

      sprintf(local_10,"
// Readability: control flow preserved from Ghidra decompile; types tentative.

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
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mis
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00826150(void)



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
