// =============================================================================
// FUN_006fbc20
// -----------------------------------------------------------------------------
// Stable ID: aa_006fbc20
// Address:   0x006fbc20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006fbc20 @ 0x006fbc20
// Stable ID: aa_006fbc20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~115 non-empty decompiler lines.
//  - Control keywords: if×8, return×3.
//  - Notable callees: ABS×3, FUN_006fb500, FUN_006fbc20.
//  - Return sites: 3.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint __fastcall FUN_006fbc20(float *param_1,float *param_2,float param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  uint uVar4;

  bool bVar5;

  float local_a0;

  float local_9c;

  float local_98;

  uint32_t /* width from decompiler */ local_94;

  float local_90;

  float local_8c;

  float local_88;

  float local_80;

  float local_7c;

  float local_78;

  float local_64;

  float local_60;

  float local_5c;

  float local_58;

  float local_50;

  float local_4c;

  float local_40;

  float local_3c;

  float local_38;

  float local_30;

  float local_2c;

  float local_28;

  float local_20;

  float local_1c;

  float local_18;

  

  local_20 = param_2[4] - *param_2;

  local_1c = param_2[5] - param_2[1];

  local_18 = param_2[6] - param_2[2];

  local_60 = param_2[0xc] - *param_2;

  local_5c = param_2[0xd] - param_2[1];

  local_8c = param_2[0xd] - param_2[9];

  local_50 = (param_2[0xe] - param_2[6]) * (param_2[9] - param_2[5]) -

             (param_2[0xd] - param_2[5]) * (param_2[10] - param_2[6]);

  local_4c = (param_2[10] - param_2[6]) * (param_2[0xc] - param_2[4]) -

             (param_2[0xe] - param_2[6]) * (param_2[8] - param_2[4]);

  fVar2 = (param_2[0xd] - param_2[5]) * (param_2[8] - param_2[4]) -

          (param_2[9] - param_2[5]) * (param_2[0xc] - param_2[4]);

  local_40 = (param_2[0xe] - param_2[10]) * (param_2[1] - param_2[9]) -

             local_8c * (param_2[2] - param_2[10]);

  local_3c = (param_2[2] - param_2[10]) * (param_2[0xc] - param_2[8]) -

             (param_2[0xe] - param_2[10]) * (*param_2 - param_2[8]);

  local_38 = local_8c * (*param_2 - param_2[8]) -

             (param_2[1] - param_2[9]) * (param_2[0xc] - param_2[8]);

  local_30 = (param_2[0xe] - param_2[2]) * local_1c - local_5c * local_18;

  local_2c = local_18 * local_60 - (param_2[0xe] - param_2[2]) * local_20;

  local_28 = local_5c * local_20 - local_1c * local_60;

  fVar1 = (*param_1 - param_2[0xc]) * param_3;

  fVar3 = (param_1[1] - param_2[0xd]) * param_3;

  param_3 = (param_1[2] - param_2[0xe]) * param_3;

  local_a0 = local_50 * fVar1 + local_4c * fVar3 + fVar2 * param_3;

  local_9c = local_40 * fVar1 + local_3c * fVar3 + local_38 * param_3;

  local_98 = local_30 * fVar1 + local_2c * fVar3 + local_28 * param_3;

  local_58 = ABS(local_98);

  local_90 = fVar2 * fVar2 + local_4c * local_4c + local_50 * local_50;

  if (local_90 == g_flZero) {

    local_90 = 3.4028235e+38;

  }

  else {

    local_90 = (ABS(local_a0) * local_a0) / local_90;

  }

  fVar1 = local_38 * local_38 + local_3c * local_3c + local_40 * local_40;

  fVar2 = _DAT_00a0f00c;

  if (fVar1 != g_flZero) {

    fVar2 = (ABS(local_9c) * local_9c) / fVar1;

  }

  local_88 = local_28 * local_28 + local_2c * local_2c + local_30 * local_30;

  if (local_88 == g_flZero) {

    local_88 = 3.4028235e+38;

  }

  else {

    local_88 = (local_58 * local_98) / local_88;

  }

  bVar5 = local_90 <= fVar2;

  fVar1 = local_90;

  if (!bVar5) {

    local_64 = local_90;

    fVar1 = fVar2;

    fVar2 = local_90;

  }

  local_90 = fVar1;

  uVar4 = (uint)bVar5;

  if (fVar2 <= local_88) {

    uVar4 = 2;

    fVar1 = local_88;

  }

  else {

    fVar1 = fVar2;

    local_64 = fVar2;

    fVar2 = local_88;

    if (local_88 < local_90) {

      fVar2 = local_90;

    }

  }

  local_88 = fVar1;

  if (_DAT_00a0f010 <= local_88) {

    if (local_88 <= DAT_00aaaa10 * fVar2) {

      local_94 = 0;

      local_80 = local_a0;

      local_7c = local_9c;

      local_78 = local_98;

      uVar4 = FUN_006fb500(param_1,&local_a0);

      return uVar4;

    }

    return uVar4;

  }

  return 0xffffffff;

}
