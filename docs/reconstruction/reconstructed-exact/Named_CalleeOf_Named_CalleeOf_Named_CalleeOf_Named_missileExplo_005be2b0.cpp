// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_missileExplo_005be2b0
// -----------------------------------------------------------------------------
// Stable ID: aa_005be2b0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_missileExplosion
// Address:   0x005be2b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_missileExplosion: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_004b0bd0×2, FUN_005be2b0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_missileExplosion
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_missileExplo_005be2b0(int *param_1,int *param_2)



{

  int *piVar1;

  

  if (param_2[2] != 0) {

    FUN_004b0bd0();

    piVar1 = (int *)param_2[2];

    if (piVar1 != (int *)0x0) {

      *piVar1 = *param_1;

      *param_1 = (int)piVar1;

    }

    param_2[2] = 0;

  }

  FUN_004b0bd0();

  *param_2 = *param_1;

  *param_1 = (int)param_2;

  return;

}
