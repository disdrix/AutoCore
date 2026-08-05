// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Skill_ResolveTargetList_004cb590
// -----------------------------------------------------------------------------
// Stable ID: aa_004cb590
// Callee of Named_CalleeOf_Skill_ResolveTargetList
// Address:   0x004cb590  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Skill_ResolveTargetList: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004cb590.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Skill_ResolveTargetList
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Skill_ResolveTargetList_004cb590(float *param_1,float *param_2)



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

  

  fVar1 = *param_2;

  fVar2 = param_2[1];

  fVar3 = *param_1;

  fVar4 = param_2[3];

  fVar5 = *param_1;

  fVar6 = param_2[2];

  fVar7 = param_1[1];

  fVar8 = *param_2;

  fVar9 = param_1[3];

  fVar10 = param_2[1];

  fVar11 = param_2[2];

  fVar12 = param_1[2];

  fVar13 = param_2[2];

  fVar14 = *param_2;

  fVar15 = *param_1;

  fVar16 = param_2[1];

  fVar17 = param_1[1];

  *param_1 = *param_1 * fVar4 +

             *param_2 * fVar9 + (param_1[1] * param_2[2] - param_2[1] * param_1[2]);

  param_1[1] = param_1[1] * fVar4 + fVar10 * fVar9 + (param_1[2] * fVar1 - fVar5 * fVar6);

  param_1[2] = param_1[2] * fVar4 + fVar9 * fVar11 + (fVar2 * fVar3 - fVar7 * fVar8);

  param_1[3] = param_1[3] * fVar4 - (fVar12 * fVar13 + fVar14 * fVar15 + fVar16 * fVar17);

  return;

}
