// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004e8590
// -----------------------------------------------------------------------------
// Stable ID: aa_004e8590
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x004e8590  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004e8590.
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004e8590(float *param_1,float *param_2,float *param_3,float *param_4)



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

  

  fVar3 = (*param_2 * param_2[1] - param_2[3] * param_2[2]) * g_flLevelUpUiBase_Inferred;

  fVar4 = *param_2 * *param_2;

  fVar6 = g_flOne - (param_2[2] * param_2[2] + fVar4) * g_flLevelUpUiBase_Inferred;

  fVar7 = (*param_2 * param_2[3] + param_2[2] * param_2[1]) * g_flLevelUpUiBase_Inferred;

  fVar8 = (*param_2 * param_2[2] + param_2[3] * param_2[1]) * g_flLevelUpUiBase_Inferred;

  fVar9 = (param_2[2] * param_2[1] - *param_2 * param_2[3]) * g_flLevelUpUiBase_Inferred;

  fVar1 = g_flOne - (param_2[1] * param_2[1] + fVar4) * g_flLevelUpUiBase_Inferred;

  fVar2 = param_3[1] - param_1[1];

  fVar5 = param_3[2] - param_1[2];

  fVar4 = *param_3 - *param_1;

  *param_4 = (*param_2 * param_2[2] - param_2[3] * param_2[1]) * g_flLevelUpUiBase_Inferred * fVar5

             + (*param_2 * param_2[1] + param_2[3] * param_2[2]) * g_flLevelUpUiBase_Inferred *

               fVar2 + (g_flOne -

                       (param_2[1] * param_2[1] + param_2[2] * param_2[2]) *

                       g_flLevelUpUiBase_Inferred) * fVar4;

  param_4[1] = fVar7 * fVar5 + fVar6 * fVar2 + fVar3 * fVar4;

  param_4[2] = fVar1 * fVar5 + fVar9 * fVar2 + fVar8 * fVar4;

  return;

}
