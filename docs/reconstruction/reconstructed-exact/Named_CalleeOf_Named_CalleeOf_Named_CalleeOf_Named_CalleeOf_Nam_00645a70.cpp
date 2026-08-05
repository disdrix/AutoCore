// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00645a70
// -----------------------------------------------------------------------------
// Stable ID: aa_00645a70
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00645a70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~64 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00645a70.
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00645a70(float *param_1,float *param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  float fVar18;

  float fVar19;

  float fVar20;

  float fVar21;

  float fVar22;

  float fVar23;

  float fVar24;

  

  fVar1 = param_2[1];

  fVar2 = param_2[2];

  fVar3 = *param_2;

  fVar4 = param_2[5];

  fVar5 = param_2[6];

  fVar6 = *param_1;

  fVar7 = param_2[4];

  fVar8 = param_1[1];

  fVar9 = param_1[2];

  fVar10 = param_2[6];

  fVar11 = param_2[5];

  fVar12 = param_2[8];

  fVar13 = param_2[10];

  fVar14 = param_2[9];

  fVar15 = param_1[4];

  fVar16 = *param_1;

  fVar17 = param_2[10];

  fVar18 = param_2[9];

  fVar19 = param_1[5];

  fVar20 = param_1[1];

  fVar21 = param_1[2];

  fVar22 = param_2[10];

  fVar23 = param_2[9];

  fVar24 = param_1[6];

  *param_1 = param_1[8] * fVar2 + param_1[4] * fVar1 + *param_1 * fVar3;

  param_1[1] = param_1[9] * fVar2 + param_1[5] * fVar1 + fVar3 * param_1[1];

  param_1[2] = param_1[10] * fVar2 + param_1[6] * fVar1 + fVar3 * param_1[2];

  param_1[3] = 0.0;

  param_1[6] = param_1[10] * fVar10 + param_1[6] * fVar11 + fVar7 * fVar9;

  param_1[4] = param_1[8] * fVar5 + param_1[4] * fVar4 + fVar6 * fVar7;

  param_1[5] = param_1[9] * fVar5 + param_1[5] * fVar4 + fVar7 * fVar8;

  param_1[7] = 0.0;

  param_1[8] = param_1[8] * fVar13 + fVar15 * fVar14 + fVar16 * fVar12;

  param_1[9] = param_1[9] * fVar17 + fVar19 * fVar18 + fVar12 * fVar20;

  param_1[10] = param_1[10] * fVar22 + fVar24 * fVar23 + fVar12 * fVar21;

  param_1[0xb] = 0.0;

  return;

}
