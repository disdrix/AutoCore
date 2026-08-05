// =============================================================================
// Named_CalleeOf_Named_Server_needs_an_update_007fe2c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007fe2c0
// Callee of Named_Server_needs_an_update (+1 other named callers)
// Address:   0x007fe2c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Server_needs_an_update: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_Server_needs_an_update (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: FUN_004133c0, FUN_007fe2c0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_Server_needs_an_update (+1 other named callers)
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

void Named_CalleeOf_Named_Server_needs_an_update_007fe2c0(void)



{

  int *piVar1;

  int unaff_EDI;

  

  piVar1 = (int *)**(int **)(unaff_EDI + 0x3124);

  if (piVar1 != *(int **)(unaff_EDI + 0x3124)) {

    do {

      if ((void *)piVar1[2] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete((void *)piVar1[2]);

      }

      piVar1[2] = 0;

      piVar1 = (int *)*piVar1;

    } while (piVar1 != (int *)*(int *)(unaff_EDI + 0x3124));

  }

  FUN_004133c0(0);

  return;

}
