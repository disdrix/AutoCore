// =============================================================================
// FUN_00664730
// -----------------------------------------------------------------------------
// Stable ID: aa_00664730
// Address:   0x00664730  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00664730 @ 0x00664730
// Stable ID: aa_00664730
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~91 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_006646f0×5, ABS×4, SQRT×2, FUN_00664730.
//  - Return sites: 1.

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

void FUN_00664730(float *param_1,float *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  bool bVar1;

  uint uVar2;

  uint uVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float local_60 [4];

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

  

  local_48 = param_2[2];

  fVar4 = *param_2 * *param_2;

  if (DAT_009e761c <= param_2[1] * param_2[1] + local_48 * local_48 + fVar4) {

    fVar8 = ABS(*param_2);

    local_50 = *param_1 + *param_2;

    local_4c = param_2[1] + param_1[1];

    local_48 = param_1[2] + local_48;

    local_44 = param_2[3] + param_1[3];

    bVar1 = fVar8 <= ABS(param_2[1]);

    if (!bVar1) {

      fVar8 = ABS(param_2[1]);

    }

    uVar2 = (uint)!bVar1;

    uVar3 = 2;

    if (ABS(param_2[2]) < fVar8) {

      uVar2 = 2;

      uVar3 = (uint)!bVar1;

    }

    fVar8 = 0.0;

    local_60[uVar2] = 0.0;

    local_60[bVar1] = param_2[uVar3];

    local_60[uVar3] = 0.0 - param_2[bVar1];

    fVar5 = local_60[2] * local_60[2] + local_60[1] * local_60[1] + local_60[0] * local_60[0];

    if (fVar5 != 0.0) {

      fVar8 = g_flOne / SQRT(fVar5);

    }

    fVar7 = local_60[2] * fVar8;

    fVar6 = fVar8 * local_60[0];

    fVar5 = fVar8 * local_60[1];

    fVar4 = SQRT(param_2[1] * param_2[1] + param_2[2] * param_2[2] + fVar4);

    fVar10 = param_2[1] * fVar7 - fVar5 * param_2[2];

    fVar9 = fVar6 * param_2[2] - *param_2 * fVar7;

    fVar11 = *param_2 * fVar5 - param_2[1] * fVar6;

    fVar8 = local_60[3] * fVar8 * fVar4;

    local_40 = *param_1 * DAT_009e7620 + local_50 * DAT_00aaa680;

    local_3c = local_4c * DAT_00aaa680 + param_1[1] * DAT_009e7620;

    local_38 = param_1[2] * DAT_009e7620 + local_48 * DAT_00aaa680;

    local_60[3] = local_44 * DAT_00aaa680 + param_1[3] * DAT_009e7620;

    local_30 = fVar4 * fVar6 * DAT_009e7620 + local_40;

    local_2c = fVar5 * fVar4 * DAT_009e7620 + local_3c;

    local_28 = fVar7 * fVar4 * DAT_009e7620 + local_38;

    local_24 = fVar8 * DAT_009e7620 + local_60[3];

    local_20 = local_40 - fVar4 * fVar6 * DAT_009e7620;

    local_1c = local_3c - fVar5 * fVar4 * DAT_009e7620;

    local_18 = local_38 - fVar7 * fVar4 * DAT_009e7620;

    local_14 = local_60[3] - fVar8 * DAT_009e7620;

    local_60[0] = fVar10 * DAT_009e7620 + local_40;

    local_60[1] = fVar9 * DAT_009e7620 + local_3c;

    local_60[2] = fVar11 * DAT_009e7620 + local_38;

    local_40 = local_40 - fVar10 * DAT_009e7620;

    local_3c = local_3c - fVar9 * DAT_009e7620;

    local_38 = local_38 - fVar11 * DAT_009e7620;

    local_34 = local_60[3];

    FUN_006646f0(param_1,&local_50,param_3,param_4);

    FUN_006646f0(&local_50,&local_30,param_3,param_4);

    FUN_006646f0(&local_50,&local_20,param_3,param_4);

    FUN_006646f0(&local_50,local_60,param_3,param_4);

    FUN_006646f0(&local_50,&local_40,param_3,param_4);

  }

  return;

}
