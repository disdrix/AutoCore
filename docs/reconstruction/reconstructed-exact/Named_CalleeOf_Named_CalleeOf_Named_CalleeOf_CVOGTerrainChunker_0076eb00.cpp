// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGTerrainChunker_0076eb00
// -----------------------------------------------------------------------------
// Stable ID: aa_0076eb00
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGTerrainChunker_SubmitForRende
// Address:   0x0076eb00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGTerrainChunker_SubmitForRende: presentation/world helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0076e5e0, FUN_0076eb00.
//  - Return sites: 1.

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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGTerrainChunker_0076eb00(float *param_1,float *param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  local_10 = *param_2;

  local_c = param_2[1];

  local_8 = param_2[2];

  local_4 = param_2[3];

  FUN_0076e5e0(&local_10,&local_10);

  fVar3 = local_8 * g_flLevelUpUiBase_Inferred;

  fVar4 = local_c * g_flLevelUpUiBase_Inferred;

  fVar5 = local_10 * local_10 * g_flLevelUpUiBase_Inferred;

  fVar6 = local_4 * local_10 * g_flLevelUpUiBase_Inferred;

  *param_1 = g_flOne - (local_8 * fVar3 + local_c * fVar4);

  fVar1 = g_flOne;

  param_1[4] = fVar4 * local_10 - local_4 * fVar3;

  param_1[1] = local_4 * fVar3 + fVar4 * local_10;

  param_1[6] = fVar6 + fVar3 * local_c;

  fVar2 = g_flOne;

  param_1[9] = fVar3 * local_c - fVar6;

  param_1[2] = fVar3 * local_10 - local_4 * fVar4;

  param_1[3] = 0.0;

  param_1[5] = fVar1 - (local_8 * fVar3 + fVar5);

  param_1[7] = 0.0;

  param_1[8] = local_4 * fVar4 + fVar3 * local_10;

  param_1[10] = fVar2 - (local_c * fVar4 + fVar5);

  param_1[0xb] = 0.0;

  param_1[0xc] = 0.0;

  param_1[0xd] = 0.0;

  param_1[0xe] = 0.0;

  param_1[0xf] = fVar2;

  return;

}
