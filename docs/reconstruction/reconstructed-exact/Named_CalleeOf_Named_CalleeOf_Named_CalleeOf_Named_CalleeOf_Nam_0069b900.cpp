// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0069b900
// -----------------------------------------------------------------------------
// Stable ID: aa_0069b900
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0069b900  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×3, while×2, do×1, return×1.
//  - Notable callees: FUN_0069ab70, FUN_0069b900.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0069b900(int *param_1,int *param_2)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  

  piVar1 = param_1;

  if (param_1 != param_2) {

    while (piVar1 = piVar1 + 1, piVar1 != param_2) {

      piVar2 = piVar1;

      piVar3 = param_1;

      if (*(float *)(*piVar1 + 0x2c) <= *(float *)(*param_1 + 0x2c)) {

        do {

          piVar3 = piVar2;

          piVar2 = piVar3 + -1;

        } while (*(float *)(piVar3[-1] + 0x2c) < *(float *)(*piVar1 + 0x2c));

      }

      if ((piVar3 != piVar1) && (piVar1 != piVar1 + 1)) {

        FUN_0069ab70(piVar3,piVar1,piVar1 + 1,0,0);

      }

    }

  }

  return;

}
