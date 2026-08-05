// =============================================================================
// FUN_004e9060
// -----------------------------------------------------------------------------
// Stable ID: aa_004e9060
// Address:   0x004e9060  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ FUN_004e9060(float *param_1,float *param_2,uint32_t /* width from decompiler */ *param_3)

{
  char *pcVar1;
  float fVar2;
  float fVar3;
  uint8_t local_55;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
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
  
  local_50 = param_2[1] * param_1[2] - param_1[1] * param_2[2];
  local_4c = param_2[2] * *param_1 - *param_2 * param_1[2];
  local_48 = param_1[1] * *param_2 - param_2[1] * *param_1;
  local_44 = 0.0;
  pcVar1 = (char *)FUN_005d6870(&local_55);
  if ((*pcVar1 != '\0') &&
     (fVar3 = local_50 * local_50 + local_4c * local_4c + local_48 * local_48,
     DAT_00a0f718 <= SQRT(fVar3))) {
    fVar2 = 0.0;
    if (fVar3 != 0.0) {
      fVar2 = g_flOne / SQRT(fVar3);
    }
    local_44 = local_44 * fVar2;
    local_48 = local_48 * fVar2;
    local_4c = local_4c * fVar2;
    local_50 = fVar2 * local_50;
    local_40 = param_1[1] * local_48 - local_4c * param_1[2];
    local_3c = local_50 * param_1[2] - *param_1 * local_48;
    fVar3 = *param_1 * local_4c - param_1[1] * local_50;
    local_54 = local_3c * local_3c + fVar3 * fVar3 + local_40 * local_40;
    local_38 = 0.0;
    if (local_54 != 0.0) {
      local_38 = g_flOne / SQRT(local_54);
      local_54 = local_38;
    }
    local_40 = local_38 * local_40;
    local_3c = local_38 * local_3c;
    local_34 = local_38 * g_flZero;
    local_38 = local_38 * fVar3;
    local_30 = *param_1;
    local_2c = param_1[1];
    local_28 = param_1[2];
    local_24 = param_1[3];
    local_20 = local_50;
    local_1c = local_4c;
    local_18 = local_48;
    local_14 = local_44;
    FUN_00567d20(&local_40);
    return 1;
  }
  param_3[3] = 0;
  param_3[2] = 0;
  param_3[1] = 0;
  *param_3 = 0;
  param_3[3] = g_flOne;
  return 0;
}
