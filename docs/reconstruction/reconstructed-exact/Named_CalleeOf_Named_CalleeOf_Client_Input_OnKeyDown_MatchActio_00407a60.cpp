// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_Input_OnKeyDown_MatchActio_00407a60
// -----------------------------------------------------------------------------
// Stable ID: aa_00407a60
// Callee of Named_CalleeOf_Client_Input_OnKeyDown_MatchAction
// Address:   0x00407a60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_Input_OnKeyDown_MatchAction: input/binding helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_00407a60.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_Input_OnKeyDown_MatchAction
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Client_Input_OnKeyDown_MatchActio_00407a60(int param_1,int param_2)



{

  int *piVar1;

  int *piVar2;

  

  piVar1 = *(int **)(param_1 + 8);

  *(int *)(param_1 + 8) = *piVar1;

  if (*(char *)(*piVar1 + 0x29) == '\0') {

    *(int *)(*piVar1 + 4) = param_1;

  }

  piVar1[1] = *(int *)(param_1 + 4);

  if (param_1 == *(int *)(*(int *)(param_2 + 4) + 4)) {

    *(int **)(*(int *)(param_2 + 4) + 4) = piVar1;

    *piVar1 = param_1;

    *(int **)(param_1 + 4) = piVar1;

    return;

  }

  piVar2 = *(int **)(param_1 + 4);

  if (param_1 == *piVar2) {

    *piVar2 = (int)piVar1;

    *piVar1 = param_1;

    *(int **)(param_1 + 4) = piVar1;

    return;

  }

  piVar2[2] = (int)piVar1;

  *piVar1 = param_1;

  *(int **)(param_1 + 4) = piVar1;

  return;

}
