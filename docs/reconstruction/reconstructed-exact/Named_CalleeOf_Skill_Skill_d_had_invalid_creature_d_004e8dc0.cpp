// =============================================================================
// Named_CalleeOf_Skill_Skill_d_had_invalid_creature_d_004e8dc0
// -----------------------------------------------------------------------------
// Stable ID: aa_004e8dc0
// Callee of Skill_Skill_d_had_invalid_creature_d
// Address:   0x004e8dc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Skill_Skill_d_had_invalid_creature_d: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~78 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: SQRT×3, FUN_004e8dc0, FUN_00567d20, FUN_005d6870.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Skill_Skill_d_had_invalid_creature_d
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

uint32_t /* width from decompiler */ Named_CalleeOf_Skill_Skill_d_had_invalid_creature_d_004e8dc0(float *param_1,uint32_t /* width from decompiler */ *param_2)



{

  float fVar1;

  char *pcVar2;

  float fVar3;

  uint8_t local_65;

  float local_64;

  float local_60;

  float local_5c;

  float local_58;

  float local_54;

  uint32_t /* width from decompiler */ local_50;

  uint32_t /* width from decompiler */ local_4c;

  uint32_t /* width from decompiler */ local_48;

  uint32_t /* width from decompiler */ local_44;

  float local_40;

  float local_3c;

  float local_38;

  float local_34;

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  

  local_60 = DAT_00af1804 * param_1[2] - DAT_00af1808 * param_1[1];

  local_5c = *param_1 * DAT_00af1808 - DAT_00af1800 * param_1[2];

  local_58 = DAT_00af1800 * param_1[1] - *param_1 * DAT_00af1804;

  local_54 = 0.0;

  pcVar2 = (char *)FUN_005d6870(&local_65);

  if ((*pcVar2 != '\0') &&

     (fVar1 = local_58 * local_58 + local_60 * local_60 + local_5c * local_5c,

     DAT_00a0f718 <= SQRT(fVar1))) {

    fVar3 = 0.0;

    if (fVar1 != 0.0) {

      fVar3 = g_flOne / SQRT(fVar1);

    }

    local_54 = local_54 * fVar3;

    local_5c = fVar3 * local_5c;

    local_58 = fVar3 * local_58;

    local_60 = fVar3 * local_60;

    local_30 = local_58 * param_1[1] - local_5c * param_1[2];

    local_2c = local_60 * param_1[2] - *param_1 * local_58;

    local_28 = *param_1 * local_5c - local_60 * param_1[1];

    local_64 = local_28 * local_28 + local_2c * local_2c + local_30 * local_30;

    local_24 = 0.0;

    if (local_64 != 0.0) {

      local_24 = g_flOne / SQRT(local_64);

      local_64 = local_24;

    }

    local_2c = local_2c * local_24;

    local_20 = *param_1;

    local_1c = param_1[1];

    local_18 = param_1[2];

    local_30 = local_24 * local_30;

    local_28 = local_28 * local_24;

    local_24 = local_24 * g_flZero;

    local_14 = param_1[3];

    local_40 = local_60;

    local_3c = local_5c;

    local_38 = local_58;

    local_34 = local_54;

    FUN_00567d20(&local_40);

    *param_2 = local_50;

    param_2[1] = local_4c;

    param_2[2] = local_48;

    param_2[3] = local_44;

    return 1;

  }

  param_2[3] = 0;

  param_2[2] = 0;

  param_2[1] = 0;

  *param_2 = 0;

  param_2[3] = g_flOne;

  return 0;

}
