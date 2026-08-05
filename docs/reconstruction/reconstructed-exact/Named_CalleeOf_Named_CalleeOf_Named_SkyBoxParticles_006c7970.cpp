// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles_006c7970
// -----------------------------------------------------------------------------
// Stable ID: aa_006c7970
// Callee of Named_CalleeOf_Named_SkyBoxParticles
// Address:   0x006c7970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_SkyBoxParticles: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_006c7970.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_SkyBoxParticles
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles_006c7970(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ param_3)



{

  float fVar1;

  

  param_1[3] = param_3;

  *(uint16_t *)((int)param_1 + 6) = 1;

  param_1[2] = 0;

  *param_1 = &PTR_FUN_00a0d530;

  param_1[4] = *param_2;

  param_1[5] = param_2[1];

  param_1[6] = param_2[2];

  param_1[7] = param_2[3];

  if ((float)param_1[5] <= (float)param_1[4]) {

    fVar1 = (float)param_1[5];

  }

  else {

    fVar1 = (float)param_1[4];

  }

  param_1[7] = fVar1;

  if ((float)param_1[6] < fVar1) {

    fVar1 = (float)param_1[6];

  }

  param_1[7] = fVar1;

  return param_1;

}
