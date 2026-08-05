// =============================================================================
// Named_CalleeOf_CVOGTacArc_dtor_helper_0096f510
// -----------------------------------------------------------------------------
// Stable ID: aa_0096f510
// Callee of CVOGTacArc_dtor_helper
// Address:   0x0096f510  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGTacArc_dtor_helper: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0096f510.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of CVOGTacArc_dtor_helper
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

void __fastcall Named_CalleeOf_CVOGTacArc_dtor_helper_0096f510(int *param_1)



{

  int *piVar1;

  

  param_1 = (int *)*param_1;

  if (param_1 != (int *)0x0) {

    piVar1 = param_1 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

                    /* WARNING: Could not recover jumptable at 0x0096f51e. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(*param_1 + 8))();

      return;

    }

  }

  return;

}
