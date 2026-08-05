// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_current_004e8320
// -----------------------------------------------------------------------------
// Stable ID: aa_004e8320
// Callee of Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_current_vehicle_xml
// Address:   0x004e8320  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_current_vehicle_xml: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004e8320.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_current_vehicle_xml
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

void Named_CalleeOf_Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_current_004e8320(float *param_1,float *param_2,float *param_3,float *param_4)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  

  fVar6 = g_flLevelUpUiBase_Inferred;

  fVar5 = g_flOne;

  fVar7 = (*param_2 * param_2[1] + param_2[3] * param_2[2]) * g_flLevelUpUiBase_Inferred;

  fVar8 = (*param_2 * param_2[2] - param_2[3] * param_2[1]) * g_flLevelUpUiBase_Inferred;

  *param_4 = *param_3 *

             (g_flOne -

             (param_2[1] * param_2[1] + param_2[2] * param_2[2]) * g_flLevelUpUiBase_Inferred) +

             *param_1;

  param_4[1] = *param_3 * fVar7 + param_1[1];

  param_4[2] = *param_3 * fVar8 + param_1[2];

  fVar7 = *param_2;

  fVar8 = param_2[2];

  fVar1 = param_2[2];

  fVar2 = param_2[1];

  fVar3 = *param_2;

  fVar4 = param_2[3];

  *param_4 = param_3[1] * (*param_2 * param_2[1] - param_2[3] * param_2[2]) * fVar6 + *param_4;

  param_4[1] = param_3[1] * (fVar5 - (fVar7 * fVar7 + fVar8 * fVar8) * fVar6) + param_4[1];

  param_4[2] = param_3[1] * (fVar3 * fVar4 + fVar1 * fVar2) * fVar6 + param_4[2];

  fVar7 = *param_2;

  fVar8 = param_2[3];

  fVar1 = param_2[2];

  fVar2 = param_2[1];

  fVar3 = *param_2;

  fVar4 = param_2[1];

  *param_4 = param_3[2] * (*param_2 * param_2[2] + param_2[3] * param_2[1]) * fVar6 + *param_4;

  param_4[1] = param_3[2] * (fVar1 * fVar2 - fVar7 * fVar8) * fVar6 + param_4[1];

  param_4[2] = param_3[2] * (fVar5 - (fVar3 * fVar3 + fVar4 * fVar4) * fVar6) + param_4[2];

  return;

}
