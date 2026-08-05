// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxMorphWeightArrayImpl_0073ebf0
// -----------------------------------------------------------------------------
// Stable ID: aa_0073ebf0
// Callee of Named_CalleeOf_Named_gfxMorphWeightArrayImpl
// Address:   0x0073ebf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxMorphWeightArrayImpl: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0073ebf0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxMorphWeightArrayImpl
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

void Named_CalleeOf_Named_CalleeOf_Named_gfxMorphWeightArrayImpl_0073ebf0(void)



{

  int *piVar1;

  int unaff_ESI;

  

  operator_delete__(*(void **)(unaff_ESI + 0xc));

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc) = 0;

  operator_delete__(*(void **)(unaff_ESI + 0x10));

  piVar1 = *(int **)(unaff_ESI + 8);

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x10) = 0;

  if (piVar1 != (int *)0x0) {

    if (piVar1[-1] != 0) {

      (**(code **)(*piVar1 + 0x10))(3);

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8) = 0;

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14) = 0;

      return;

    }

    operator_delete__(piVar1 + -1);

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14) = 0;

  return;

}
