// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxGeometryPiece_0044bb80
// -----------------------------------------------------------------------------
// Stable ID: aa_0044bb80
// Callee of Named_CalleeOf_Named_gfxGeometryPiece
// Address:   0x0044bb80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxGeometryPiece: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0044bb80.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxGeometryPiece
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_gfxGeometryPiece_0044bb80(int param_1,int *param_2)



{

  int *piVar1;

  int *piVar2;

  

  if ((param_2 != (int *)0x0) && (param_2[1] = param_2[1] + 1, param_2[1] == 1)) {

    (**(code **)(*param_2 + 4))();

  }

  piVar2 = *(int **)(param_1 + 0x20);

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  *(int **)(param_1 + 0x20) = param_2;

  return;

}
