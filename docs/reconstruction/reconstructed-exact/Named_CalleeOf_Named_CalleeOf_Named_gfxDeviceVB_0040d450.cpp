// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxDeviceVB_0040d450
// -----------------------------------------------------------------------------
// Stable ID: aa_0040d450
// Callee of Named_CalleeOf_Named_gfxDeviceVB
// Address:   0x0040d450  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxDeviceVB: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: ABS×5, FUN_0040d450.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxDeviceVB
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Named_gfxDeviceVB_0040d450(float param_1,float param_2,float param_3,float param_4)



{

  float fVar1;

  float *pfVar2;

  

  fVar1 = param_1 - param_2;

  if (param_4 < ABS(fVar1)) {

    pfVar2 = &param_2;

    param_4 = ABS(param_2);

    param_2 = ABS(param_1);

    if (ABS(param_1) <= param_4) {

      pfVar2 = &param_4;

    }

    if (*pfVar2 * param_3 < ABS(fVar1)) {

      return 0;

    }

  }

  return 1;

}
