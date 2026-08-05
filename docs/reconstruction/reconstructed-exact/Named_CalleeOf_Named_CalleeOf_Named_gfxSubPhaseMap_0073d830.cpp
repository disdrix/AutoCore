// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxSubPhaseMap_0073d830
// -----------------------------------------------------------------------------
// Stable ID: aa_0073d830
// Callee of Named_CalleeOf_Named_gfxSubPhaseMap
// Address:   0x0073d830  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxSubPhaseMap: map/sector helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, while×1.
//  - Notable callees: FUN_004406e0, FUN_0073d830.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxSubPhaseMap
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_gfxSubPhaseMap_0073d830(int param_1,int param_2)



{

  int *piVar1;

  

  if ((param_2 != 0) && (*(int *)(param_2 + 8) != 0)) {

    piVar1 = *(int **)(param_1 + 4);

    if (piVar1 != *(int **)(param_1 + 8)) {

      while (*piVar1 != *(int *)(param_2 + 8)) {

        piVar1 = piVar1 + 5;

        if (piVar1 == *(int **)(param_1 + 8)) {

          return;

        }

      }

      FUN_004406e0();

    }

  }

  return;

}
