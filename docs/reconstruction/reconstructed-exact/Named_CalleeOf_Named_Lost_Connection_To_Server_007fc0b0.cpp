// =============================================================================
// Named_CalleeOf_Named_Lost_Connection_To_Server_007fc0b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007fc0b0
// Callee of Named_Lost_Connection_To_Server
// Address:   0x007fc0b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Lost_Connection_To_Server: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_007fc0b0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_Lost_Connection_To_Server
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

uint8_t * Named_CalleeOf_Named_Lost_Connection_To_Server_007fc0b0(void)



{

  char cVar1;

  int unaff_ESI;

  uint8_t *apuStack_c [3];

  

  if (*(int *)(unaff_ESI + 0xc78) != 0) {

    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0xc78) + 8))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(unaff_ESI + 0xc78) + 0x54))();

      if ((apuStack_c < apuStack_c[0]) && ((uint8_t *)0x1770 < apuStack_c[0])) {

        return apuStack_c[0];

      }

      return (uint8_t *)apuStack_c;

    }

  }

  return (uint8_t *)0x0;

}
