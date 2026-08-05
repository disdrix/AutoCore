// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxShadowVolume_00452e20
// -----------------------------------------------------------------------------
// Stable ID: aa_00452e20
// Callee of Named_CalleeOf_Named_gfxShadowVolume
// Address:   0x00452e20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxShadowVolume: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, goto×1, return×1.
//  - Notable callees: FUN_00452e20, FUN_0046bba0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxShadowVolume
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

int * Named_CalleeOf_Named_CalleeOf_Named_gfxShadowVolume_00452e20(int *param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  int unaff_EDI;

  

  iVar1 = *(int *)(unaff_EDI + 4);

  if (iVar1 != 0) {

    if ((*(int *)(unaff_EDI + 8) - iVar1) / 0x18 != 0) {

      iVar1 = (param_2 - iVar1) / 0x18;

      goto LAB_00452e67;

    }

  }

  iVar1 = 0;

LAB_00452e67:

  FUN_0046bba0(param_2,param_3);

  *param_1 = *(int *)(unaff_EDI + 4) + iVar1 * 0x18;

  return param_1;

}
