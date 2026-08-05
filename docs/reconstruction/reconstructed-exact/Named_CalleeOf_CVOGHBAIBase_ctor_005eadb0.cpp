// =============================================================================
// Named_CalleeOf_CVOGHBAIBase_ctor_005eadb0
// -----------------------------------------------------------------------------
// Stable ID: aa_005eadb0
// Callee of CVOGHBAIBase_ctor
// Address:   0x005eadb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGHBAIBase_ctor: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00568100, FUN_005eadb0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGHBAIBase_ctor
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

void __thiscall Named_CalleeOf_CVOGHBAIBase_ctor_005eadb0(float *param_1,float *param_2)



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

  uint8_t local_2d [13];

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  

  local_20 = *param_2;

  local_1c = param_2[1];

  local_18 = param_2[2];

  local_14 = param_2[3];

  FUN_00568100(local_2d);

  fVar1 = *param_2;

  fVar2 = param_2[1];

  fVar3 = param_2[2];

  fVar9 = param_2[2] * g_flLevelUpUiBase_Inferred;

  fVar12 = *param_2 * *param_2 * g_flLevelUpUiBase_Inferred;

  fVar11 = *param_2 * g_flLevelUpUiBase_Inferred * param_2[3];

  fVar4 = param_2[3];

  fVar10 = param_2[1] * g_flLevelUpUiBase_Inferred;

  fVar5 = *param_2;

  fVar6 = param_2[1];

  fVar7 = param_2[3];

  *param_1 = g_flOne - (fVar3 * fVar9 + fVar6 * fVar10);

  param_1[1] = fVar9 * fVar4 + fVar5 * fVar10;

  param_1[2] = fVar1 * fVar9 - fVar10 * fVar7;

  param_1[3] = 0.0;

  fVar8 = g_flOne;

  param_1[4] = fVar5 * fVar10 - fVar9 * fVar4;

  param_1[5] = fVar8 - (fVar3 * fVar9 + fVar12);

  param_1[7] = 0.0;

  param_1[6] = fVar11 + fVar2 * fVar9;

  param_1[8] = fVar10 * fVar7 + fVar1 * fVar9;

  param_1[9] = fVar2 * fVar9 - fVar11;

  param_1[10] = fVar8 - (fVar6 * fVar10 + fVar12);

  param_1[0xb] = 0.0;

  return;

}
