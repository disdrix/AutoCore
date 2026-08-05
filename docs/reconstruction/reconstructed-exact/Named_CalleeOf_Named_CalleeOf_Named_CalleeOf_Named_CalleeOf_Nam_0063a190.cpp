// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0063a190
// -----------------------------------------------------------------------------
// Stable ID: aa_0063a190
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0063a190  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0063a190.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0063a190(float *param_1,float *param_2,float *param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  

  fVar1 = param_3[2];

  fVar2 = *param_3;

  fVar3 = param_3[1];

  *param_1 = *param_2 * fVar2 + param_2[8] * fVar1 + param_2[4] * fVar3;

  param_1[1] = param_2[9] * fVar1 + param_2[5] * fVar3 + fVar2 * param_2[1];

  param_1[2] = param_2[10] * fVar1 + param_2[6] * fVar3 + fVar2 * param_2[2];

  param_1[3] = 0.0;

  fVar1 = param_3[6];

  fVar2 = param_3[4];

  fVar3 = param_3[5];

  param_1[4] = *param_2 * fVar2 + param_2[8] * fVar1 + param_2[4] * fVar3;

  param_1[5] = param_2[9] * fVar1 + param_2[5] * fVar3 + fVar2 * param_2[1];

  param_1[6] = param_2[10] * fVar1 + param_2[6] * fVar3 + fVar2 * param_2[2];

  param_1[7] = 0.0;

  fVar1 = param_3[8];

  fVar2 = param_3[10];

  fVar3 = param_3[9];

  param_1[8] = *param_2 * fVar1 + param_2[8] * fVar2 + param_2[4] * fVar3;

  param_1[9] = param_2[9] * fVar2 + param_2[5] * fVar3 + fVar1 * param_2[1];

  param_1[10] = param_2[10] * fVar2 + param_2[6] * fVar3 + fVar1 * param_2[2];

  param_1[0xb] = 0.0;

  fVar1 = param_3[0xe];

  fVar2 = param_3[0xc];

  fVar3 = param_3[0xd];

  param_1[0xc] = *param_2 * fVar2 + param_2[8] * fVar1 + param_2[4] * fVar3;

  param_1[0xd] = param_2[9] * fVar1 + param_2[5] * fVar3 + fVar2 * param_2[1];

  param_1[0xe] = param_2[10] * fVar1 + param_2[6] * fVar3 + fVar2 * param_2[2];

  param_1[0xf] = 0.0;

  param_1[0xc] = param_1[0xc] + param_2[0xc];

  param_1[0xd] = param_2[0xd] + param_1[0xd];

  param_1[0xe] = param_2[0xe] + param_1[0xe];

  param_1[0xf] = param_2[0xf] + param_1[0xf];

  return;

}
