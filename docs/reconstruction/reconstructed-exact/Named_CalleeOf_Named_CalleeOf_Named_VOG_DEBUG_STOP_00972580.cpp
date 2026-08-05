// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_00972580
// -----------------------------------------------------------------------------
// Stable ID: aa_00972580
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x00972580  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~63 non-empty decompiler lines.
//  - Control keywords: if×2, for×1, return×1.
//  - Notable callees: FUN_0076f5f0×2, FUN_00972580.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
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

float * __thiscall Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_00972580(float *param_1,float *param_2,float *param_3)



{

  int iVar1;

  float *extraout_EDX;

  float *extraout_EDX_00;

  float *pfVar2;

  float *pfVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  fVar5 = DAT_00aaa620;

  pfVar2 = (float *)&DAT_00afdf70;

  pfVar3 = param_1;

  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {

    *pfVar3 = *pfVar2;

    pfVar2 = pfVar2 + 1;

    pfVar3 = pfVar3 + 1;

  }

  local_c = param_3[1] * param_2[2] - param_3[2] * param_2[1];

  local_8 = param_3[2] * *param_2 - param_2[2] * *param_3;

  local_4 = param_2[1] * *param_3 - param_3[1] * *param_2;

  if (local_4 * local_4 + local_8 * local_8 + local_c * local_c < fVar5) {

    local_c = param_2[1] * 0.0 - param_2[2] * 0.0;

    fVar4 = *param_2 * 0.0;

    local_8 = param_2[2] - fVar4;

    local_4 = fVar4 - param_2[1];

    if (local_4 * local_4 + local_8 * local_8 + local_c * local_c < fVar5) {

      local_c = param_2[2] * 0.0 - param_2[1] * DAT_00aaa668;

      local_8 = *param_2 * DAT_00aaa668 - param_2[2] * 0.0;

      local_4 = param_2[1] * 0.0 - fVar4;

    }

  }

  local_18 = local_c;

  local_14 = local_8;

  local_10 = local_4;

  FUN_0076f5f0(&local_18,&local_18);

  local_c = extraout_EDX[1] * local_10 - extraout_EDX[2] * local_14;

  local_8 = extraout_EDX[2] * local_18 - *extraout_EDX * local_10;

  local_4 = *extraout_EDX * local_14 - extraout_EDX[1] * local_18;

  fVar5 = local_10;

  fVar4 = local_14;

  fVar6 = local_18;

  local_18 = local_c;

  local_14 = local_8;

  local_10 = local_4;

  FUN_0076f5f0(&local_18,&local_18);

  param_1[4] = local_18;

  param_1[5] = local_14;

  *param_1 = fVar6;

  param_1[1] = fVar4;

  param_1[2] = fVar5;

  param_1[6] = local_10;

  param_1[8] = *extraout_EDX_00;

  param_1[9] = extraout_EDX_00[1];

  param_1[10] = extraout_EDX_00[2];

  return param_1;

}
