// =============================================================================
// Named_CalleeOf_CVOGVariable_EvaluateComputed_00525ba0
// -----------------------------------------------------------------------------
// Stable ID: aa_00525ba0
// Callee of CVOGVariable_EvaluateComputed
// Address:   0x00525ba0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGVariable_EvaluateComputed: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: CONCAT31, FUN_00525ba0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGVariable_EvaluateComputed
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_CVOGVariable_EvaluateComputed_00525ba0(int param_1,int param_2)



{

  int *piVar1;

  int *piVar2;

  bool bVar3;

  

  piVar1 = *(int **)(param_1 + 0x578);

  piVar2 = *(int **)(param_1 + 0x574);

  bVar3 = piVar2 == piVar1;

  if (!bVar3) {

    do {

      if (*piVar2 == param_2) break;

      piVar2 = piVar2 + 1;

    } while (piVar2 != piVar1);

    bVar3 = piVar2 == piVar1;

  }

  return CONCAT31((int3)((uint)piVar2 >> 8),!bVar3);

}
