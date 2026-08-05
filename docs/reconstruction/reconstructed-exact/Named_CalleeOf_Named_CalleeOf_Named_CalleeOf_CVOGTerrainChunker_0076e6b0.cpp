// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGTerrainChunker_0076e6b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0076e6b0
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGTerrainChunker_SubmitForRende
// Address:   0x0076e6b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGTerrainChunker_SubmitForRende: presentation/world helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0076e6b0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_CVOGTerrainChunker_SubmitForRende
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float * Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGTerrainChunker_0076e6b0(float *param_1,float *param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  

  fVar3 = *param_2 * *param_2 + param_2[1] * param_2[1] + param_2[2] * param_2[2] +

          param_2[3] * param_2[3];

  if ((fVar3 < _DAT_00a240ec) && (DAT_00aaa640 < fVar3)) {

    return param_1;

  }

  *param_1 = 0.0 - *param_2;

  fVar1 = param_2[1];

  param_1[1] = 0.0 - fVar1;

  param_1[2] = 0.0 - param_2[2];

  fVar2 = param_2[3];

  fVar3 = g_flOne / fVar3;

  *param_1 = *param_1 * fVar3;

  param_1[1] = (0.0 - fVar1) * fVar3;

  param_1[3] = fVar2;

  param_1[2] = param_1[2] * fVar3;

  param_1[3] = param_1[3] * fVar3;

  return param_1;

}
