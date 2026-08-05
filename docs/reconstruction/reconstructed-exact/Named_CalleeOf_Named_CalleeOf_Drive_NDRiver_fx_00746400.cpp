// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Drive_NDRiver_fx_00746400
// -----------------------------------------------------------------------------
// Stable ID: aa_00746400
// Callee of Named_CalleeOf_Drive_NDRiver_fx
// Address:   0x00746400  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Drive_NDRiver_fx: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, goto×1, while×1.
//  - Notable callees: FUN_004406e0, FUN_00746400.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Drive_NDRiver_fx
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Drive_NDRiver_fx_00746400(int param_1,int param_2)



{

  int *piVar1;

  

  piVar1 = *(int **)(param_1 + 4);

  do {

    if (piVar1 == *(int **)(param_1 + 8)) {

LAB_0074641c:

      FUN_004406e0();

      return 0;

    }

    if (*piVar1 == param_2) {

      if (piVar1 != *(int **)(param_1 + 8)) {

        return 1;

      }

      goto LAB_0074641c;

    }

    piVar1 = piVar1 + 1;

  } while( true );

}
