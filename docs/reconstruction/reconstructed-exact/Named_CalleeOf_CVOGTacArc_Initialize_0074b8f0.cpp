// =============================================================================
// Named_CalleeOf_CVOGTacArc_Initialize_0074b8f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0074b8f0
// Callee of CVOGTacArc_Initialize
// Address:   0x0074b8f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGTacArc_Initialize: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: ABS×2, SQRT×2, FUN_0074b8f0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGTacArc_Initialize
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

void __thiscall Named_CalleeOf_CVOGTacArc_Initialize_0074b8f0(float *param_1,float *param_2,float *param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  

  fVar5 = DAT_00a0f298;

  param_1[5] = *param_2;

  param_1[6] = param_2[1];

  param_1[7] = param_2[2];

  param_1[8] = *param_3;

  param_1[9] = param_3[1];

  param_1[10] = param_3[2];

  fVar1 = param_2[1];

  fVar2 = param_3[1];

  fVar3 = param_2[2];

  fVar4 = param_3[2];

  *param_1 = (*param_2 + *param_3) * fVar5;

  param_1[1] = (fVar1 + fVar2) * fVar5;

  param_1[2] = (fVar3 + fVar4) * fVar5;

  param_1[3] = ABS(SQRT((*param_3 - *param_1) * (*param_3 - *param_1) +

                        (param_3[1] - param_1[1]) * (param_3[1] - param_1[1]) +

                        (param_3[2] - param_1[2]) * (param_3[2] - param_1[2])));

  fVar1 = *param_3;

  fVar2 = param_3[2];

  *(uint8_t *)(param_1 + 0xb) = 0;

  param_1[4] = ABS(SQRT((fVar2 - param_1[2]) * (fVar2 - param_1[2]) +

                        (fVar1 - *param_1) * (fVar1 - *param_1)));

  return;

}
