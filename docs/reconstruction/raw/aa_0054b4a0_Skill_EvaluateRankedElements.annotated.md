# Annotated low-level: Skill_EvaluateRankedElements

| Field | Value |
|---|---|
| Stable ID | `aa_0054b4a0` |
| VA | `0x0054b4a0` |
| System | skills-abilities |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0054b4a0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Skill_EvaluateRankedElements(nSkillId, nRank, pOutRuntime, nRankOffset)
   
   Parameters:
     nSkillId     - WAD skill id
     nRank        - effective rank for base + rank*perLevel
     pOutRuntime  - skill runtime fields written
     nRankOffset  - secondary rank offset (skill+0x174)
   
   Algorithm: load template elements; evaluate each equation type into cost/cooldown(+0x10)/
   charge(+0x14)/range/damage channels.
   
   VERIFIED cooldown write at runtime+0x10 as int ms. */

void Skill_EvaluateRankedElements
               (undefined4 param_1,undefined4 param_2,short *param_3,undefined4 param_4)

{
  short *psVar1;
  undefined1 uVar2;
  int *piVar3;
  float *pfVar4;
  int iVar5;
  short *psVar6;
  short sVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  float *pfVar10;
  float fVar11;
  float local_544;
  undefined4 local_540;
  short local_53c;
  undefined1 local_53a;
  undefined1 local_539;
  undefined1 local_538;
  undefined1 local_537;
  undefined4 local_534;
  undefined1 local_52c;
  undefined1 local_52b;
  uint local_528;
  uint local_524;
  uint local_520;
  uint local_51c;
  int local_518;
  float local_514;
  float local_510;
  int local_50c;
  float local_508;
  float local_504;
  int local_500;
  float local_4fc;
  float local_4f8;
  int local_4f4;
  float local_4f0;
  float local_4ec;
  int local_4e8;
  float local_4e4;
  float local_4e0;
  int local_4dc;
  float local_4d8;
  float local_4d4;
  int local_4d0;
  float local_4cc;
  float local_4c8;
  int local_4c4;
  float local_4c0;
  float local_4bc;
  int local_4b8;
  float local_4b4;
  float local_4b0;
  int local_4ac;
  float local_4a8;
  float local_4a4;
  int local_4a0;
  float local_49c;
  float local_498;
  int local_494;
  float local_490;
  float local_48c;
  int local_488;
  float local_484;
  float local_480;
  int local_47c;
  float local_478;
  float local_474;
  int local_470;
  float local_46c;
  float local_468;
  int local_464;
  float local_460;
  float local_45c;
  int local_458;
  float local_454;
  float local_450;
  int local_44c;
  float local_448;
  float local_444;
  int local_440;
  float local_43c;
  float local_438;
  int local_434;
  float local_430;
  float local_42c;
  float local_420 [142];
  int local_1e8;
  float local_1e4;
  float local_1e0;
  int local_1dc;
  float local_1d8;
  float local_1d4;
  int local_1d0;
  float local_1cc;
  float local_1c8;
  int local_1c4;
  float local_1c0;
  float local_1bc;
  int local_1b8;
  float local_1b4;
  float local_1b0;
  int local_1ac;
  float local_1a8;
  float local_1a4;
  int local_1a0;
  float local_19c;
  float local_198;
  int local_194;
  float local_190;
  float local_18c;
  int local_188;
  float local_184;
  float local_180;
  int local_17c;
  float local_178;
  float local_174;
  int local_170;
  float local_16c;
  float local_168;
  int local_164;
  float local_160;
  float local_15c;
  int local_158;
  float local_154;
  float local_150;
  int local_14c;
  float local_148;
  float local_144;
  int local_140;
  float local_13c;
  float local_138;
  int local_134;
  float local_130;
  float local_12c;
  int local_128;
  float local_124;
  float local_120;
  int local_11c;
  float local_118;
  float local_114;
  int local_110;
  float local_10c;
  float local_108;
  int local_104;
  float local_100;
  float local_fc;
  int local_f8;
  float local_f4;
  float local_f0;
  int local_ec;
  float local_e8;
  float local_e4;
  int local_e0;
  float local_dc;
  float local_d8;
  int local_d4;
  float local_d0;
  float local_cc;
  int local_c8;
  float local_c4;
  float local_c0;
  int local_bc;
  float local_b8;
  float local_b4;
  int local_b0;
  float local_ac;
  float local_a8;
  int local_a4;
  float local_a0;
  float local_9c;
  int local_98;
  float local_94;
  float local_90;
  int local_8c;
  float local_88;
  float local_84;
  int local_80;
  float local_7c;
  float local_78;
  int local_74;
  float local_70;
  float local_6c;
  int local_68;
  float local_64;
  float local_60;
  int local_5c;
  float local_58;
  float local_54;
  int local_50;
  float local_4c;
  float local_48;
  int local_44;
  float local_40;
  float local_3c;
  int local_38;
  float local_34;
  float local_30;
  int local_2c;
  float local_28;
  float local_24;
  int local_20;
  float local_1c;
  float local_18;
  int local_14;
  float local_10;
  float local_c;
  
  if (DAT_00b04724 == '\0') {
    FUN_0054b2c0();
  }
  piVar3 = (int *)FUN_0054d9a0(&local_544,&param_1);
  psVar1 = param_3;
  local_544 = g_flMissionXpRoundBias;
  if (*piVar3 == DAT_00b0472c) {
    for (iVar5 = 0x5c; iVar5 != 0; iVar5 = iVar5 + -1) {
      param_3[0] = 0;
      param_3[1] = 0;
      param_3 = param_3 + 2;
    }
    return;
  }
  puVar8 = (undefined4 *)(*piVar3 + 0x10);
  puVar9 = &local_540;
  for (iVar5 = 0x14e; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar9 = *puVar8;
    puVar8 = puVar8 + 1;
    puVar9 = puVar9 + 1;
  }
  sVar7 = (short)param_2;
  if (local_500 == 0) {
    local_4f8 = 0.0;
LAB_0054b542:
    local_4f8 = local_4f8 + g_flMissionXpRoundBias;
  }
  else {
    if (local_500 == 4) {
      local_4f8 = 0.0;
      goto LAB_0054b542;
    }
    local_4f8 = (float)(int)sVar7 * local_4fc + local_4f8;
    if (0.0 <= local_4f8) goto LAB_0054b542;
    local_4f8 = local_4f8 - g_flMissionXpRoundBias;
  }
  param_3[4] = (short)(int)local_4f8;
  if ((local_4f4 == 0) || (local_4f4 == 4)) {
    local_4ec = 0.0;
LAB_0054b58b:
    local_4ec = local_4ec + local_544;
  }
  else {
    local_4ec = (float)(int)sVar7 * local_4f0 + local_4ec;
    if (0.0 <= local_4ec) goto LAB_0054b58b;
    local_4ec = local_4ec - local_544;
  }
  param_3[5] = (short)(int)local_4ec;
  if ((local_4e8 == 0) || (local_4e8 == 4)) {
    local_4e0 = 0.0;
LAB_0054b5c5:
    local_4e0 = local_4e0 + local_544;
  }
  else {
    local_4e0 = (float)(int)sVar7 * local_4e4 + local_4e0;
    if (0.0 <= local_4e0) goto LAB_0054b5c5;
    local_4e0 = local_4e0 - local_544;
  }
  *(int *)(param_3 + 8) = (int)local_4e0;
  if ((local_4dc == 0) || (local_4dc == 4)) {
    local_4d4 = 0.0;
LAB_0054b5fe:
    local_4d4 = local_4d4 + local_544;
  }
  else {
    local_4d4 = (float)(int)sVar7 * local_4d8 + local_4d4;
    if (0.0 <= local_4d4) goto LAB_0054b5fe;
    local_4d4 = local_4d4 - local_544;
  }
  param_3[10] = (short)(int)local_4d4;
  if ((local_4d0 == 0) || (local_4d0 == 4)) {
    local_4c8 = 0.0;
LAB_0054b641:
    local_4c8 = local_4c8 + local_544;
  }
  else {
    local_4c8 = (float)(int)sVar7 * local_4cc + local_4c8;
    if (0.0 <= local_4c8) goto LAB_0054b641;
    local_4c8 = local_4c8 - local_544;
  }
  *(int *)(param_3 + 0xc) = (int)local_4c8;
  if ((int)local_4c8 == -1) {
    param_3[0xc] = -1000;
    param_3[0xd] = -1;
  }
  if ((local_4c4 == 0) || (local_4c4 == 4)) {
    local_4bc = 0.0;
LAB_0054b690:
    local_4bc = local_4bc + local_544;
  }
  else {
    local_4bc = (float)(int)sVar7 * local_4c0 + local_4bc;
    if (0.0 <= local_4bc) goto LAB_0054b690;
    local_4bc = local_4bc - local_544;
  }
  *(int *)(param_3 + 0xe) = (int)local_4bc;
  if ((int)local_4bc == -1) {
    param_3[0xe] = -1000;
    param_3[0xf] = -1;
  }
  if ((local_4b8 == 0) || (local_4b8 == 4)) {
    local_4b0 = 0.0;
  }
  else {
    local_4b0 = (float)(int)sVar7 * local_4b4 + local_4b0;
  }
  *(float *)(param_3 + 0x14) = local_4b0;
  if ((local_4ac == 0) || (local_4ac == 4)) {
    local_4a4 = 0.0;
  }
  else {
    local_4a4 = (float)(int)sVar7 * local_4a8 + local_4a4;
  }
  *(float *)(param_3 + 0x16) = local_4a4;
  if ((local_4a0 == 0) || (local_4a0 == 4)) {
    local_498 = 0.0;
  }
  else {
    local_498 = (float)(int)sVar7 * local_49c + local_498;
  }
  *(float *)(param_3 + 0x18) = local_498;
  if ((local_494 == 0) || (local_494 == 4)) {
    local_48c = 0.0;
  }
  else {
    local_48c = (float)(int)sVar7 * local_490 + local_48c;
  }
  *(float *)(param_3 + 0x1a) = local_48c;
  if ((local_488 == 0) || (local_488 == 4)) {
    local_480 = 0.0;
  }
  else {
    local_480 = (float)(int)sVar7 * local_484 + local_480;
  }
  *(float *)(param_3 + 0x1c) = local_480;
  if ((local_47c == 0) || (local_47c == 4)) {
    local_474 = 0.0;
  }
  else {
    local_474 = (float)(int)sVar7 * local_478 + local_474;
  }
  *(float *)(param_3 + 0x1e) = local_474;
  if ((local_470 == 0) || (local_470 == 4)) {
    local_468 = 0.0;
  }
  else {
    local_468 = (float)(int)sVar7 * local_46c + local_468;
  }
  *(float *)(param_3 + 0x20) = local_468;
  if ((local_464 == 0) || (local_464 == 4)) {
    local_45c = 0.0;
  }
  else {
    local_45c = (float)(int)sVar7 * local_460 + local_45c;
  }
  *(float *)(param_3 + 0x22) = local_45c;
  if ((local_458 == 0) || (local_458 == 4)) {
    local_450 = 0.0;
  }
  else {
    local_450 = (float)(int)sVar7 * local_454 + local_450;
  }
  *(float *)(param_3 + 0x26) = local_450;
  if ((local_440 == 0) || (local_440 == 4)) {
    local_438 = 0.0;
LAB_0054b8a5:
    local_438 = local_438 + local_544;
  }
  else {
    local_438 = (float)(int)sVar7 * local_43c + local_438;
    if (0.0 <= local_438) goto LAB_0054b8a5;
    local_438 = local_438 - local_544;
  }
  param_3[0x28] = (short)(int)local_438;
  if ((local_44c == 0) || (local_44c == 4)) {
    local_444 = 0.0;
  }
  else {
    local_444 = (float)(int)sVar7 * local_448 + local_444;
  }
  *(float *)(param_3 + 0x24) = local_444;
  pfVar10 = (float *)(param_3 + 0x54);
  psVar6 = param_3 + 0x30;
  pfVar4 = local_420;
  iVar5 = 6;
  do {
    if ((pfVar4[-2] == 0.0) || (pfVar4[-2] == 5.60519e-45)) {
      fVar11 = 0.0;
LAB_0054b92b:
      fVar11 = fVar11 + local_544;
    }
    else {
      fVar11 = (float)(int)sVar7 * pfVar4[-1] + *pfVar4;
      if (0.0 <= fVar11) goto LAB_0054b92b;
      fVar11 = fVar11 - local_544;
    }
    psVar6[-6] = (short)(int)fVar11;
    if ((pfVar4[0x10] == 0.0) || (pfVar4[0x10] == 5.60519e-45)) {
      fVar11 = 0.0;
LAB_0054b963:
      fVar11 = fVar11 + local_544;
    }
    else {
      fVar11 = (float)(int)sVar7 * pfVar4[0x11] + pfVar4[0x12];
      if (0.0 <= fVar11) goto LAB_0054b963;
      fVar11 = fVar11 - local_544;
    }
    *psVar6 = (short)(int)fVar11;
    if ((pfVar4[0x22] == 0.0) || (pfVar4[0x22] == 5.60519e-45)) {
      fVar11 = 0.0;
LAB_0054b9a3:
      fVar11 = fVar11 + local_544;
    }
    else {
      fVar11 = (float)(int)sVar7 * pfVar4[0x23] + pfVar4[0x24];
      if (0.0 <= fVar11) goto LAB_0054b9a3;
      fVar11 = fVar11 - local_544;
    }
    psVar6[6] = (short)(int)fVar11;
    if ((pfVar4[0x34] == 0.0) || (pfVar4[0x34] == 5.60519e-45)) {
      fVar11 = 0.0;
LAB_0054b9e4:
      fVar11 = fVar11 + local_544;
    }
    else {
      fVar11 = (float)(int)sVar7 * pfVar4[0x35] + pfVar4[0x36];
      if (0.0 <= fVar11) goto LAB_0054b9e4;
      fVar11 = fVar11 - local_544;
    }
    psVar6[0xc] = (short)(int)fVar11;
    if ((pfVar4[0x46] == 0.0) || (pfVar4[0x46] == 5.60519e-45)) {
      fVar11 = 0.0;
LAB_0054ba25:
      fVar11 = fVar11 + local_544;
    }
    else {
      fVar11 = (float)(int)sVar7 * pfVar4[0x47] + pfVar4[0x48];
      if (0.0 <= fVar11) goto LAB_0054ba25;
      fVar11 = fVar11 - local_544;
    }
    psVar6[0x12] = (short)(int)fVar11;
    if ((pfVar4[0x58] == 0.0) || (pfVar4[0x58] == 5.60519e-45)) {
      fVar11 = 0.0;
LAB_0054ba66:
      fVar11 = fVar11 + local_544;
    }
    else {
      fVar11 = (float)(int)sVar7 * pfVar4[0x59] + pfVar4[0x5a];
      if (0.0 <= fVar11) goto LAB_0054ba66;
      fVar11 = fVar11 - local_544;
    }
    psVar6[0x18] = (short)(int)fVar11;
    if ((pfVar4[0x6a] == 0.0) || (pfVar4[0x6a] == 5.60519e-45)) {
      fVar11 = 0.0;
LAB_0054baa7:
      fVar11 = fVar11 + local_544;
    }
    else {
      fVar11 = (float)(int)sVar7 * pfVar4[0x6b] + pfVar4[0x6c];
      if (0.0 <= fVar11) goto LAB_0054baa7;
      fVar11 = fVar11 - local_544;
    }
    psVar6[0x1e] = (short)(int)fVar11;
    if ((pfVar4[0x7c] == 0.0) || (pfVar4[0x7c] == 5.60519e-45)) {
      fVar11 = 0.0;
    }
    else {
      fVar11 = (float)(int)sVar7 * pfVar4[0x7d] + pfVar4[0x7e];
    }
    *pfVar10 = fVar11;
    psVar6 = psVar6 + 1;
    pfVar10 = pfVar10 + 1;
    pfVar4 = pfVar4 + 3;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  if ((local_1e8 == 0) || (local_1e8 == 4)) {
    local_1e0 = 0.0;
  }
  else {
    local_1e0 = (float)(int)sVar7 * local_1e4 + local_1e0;
  }
  *(float *)(param_3 + 0x60) = local_1e0;
  if ((local_1dc == 0) || (local_1dc == 4)) {
    local_1d4 = 0.0;
  }
  else {
    local_1d4 = (float)(int)sVar7 * local_1d8 + local_1d4;
  }
  *(float *)(param_3 + 0x62) = local_1d4;
  if ((local_1d0 == 0) || (local_1d0 == 4)) {
    local_1c8 = 0.0;
  }
  else {
    local_1c8 = (float)(int)sVar7 * local_1cc + local_1c8;
  }
  *(float *)(param_3 + 100) = local_1c8;
  if ((local_1c4 == 0) || (local_1c4 == 4)) {
    local_1bc = 0.0;
  }
  else {
    local_1bc = (float)(int)sVar7 * local_1c0 + local_1bc;
  }
  *(float *)(param_3 + 0x66) = local_1bc;
  if ((local_1b8 == 0) || (local_1b8 == 4)) {
    local_1b0 = 0.0;
LAB_0054bc07:
    local_1b0 = local_1b0 + local_544;
  }
  else {
    local_1b0 = (float)(int)sVar7 * local_1b4 + local_1b0;
    if (0.0 <= local_1b0) goto LAB_0054bc07;
    local_1b0 = local_1b0 - local_544;
  }
  param_3[0x68] = (short)(int)local_1b0;
  if ((local_1ac == 0) || (local_1ac == 4)) {
    local_1a4 = 0.0;
LAB_0054bc4d:
    local_1a4 = local_1a4 + local_544;
  }
  else {
    local_1a4 = (float)(int)sVar7 * local_1a8 + local_1a4;
    if (0.0 <= local_1a4) goto LAB_0054bc4d;
    local_1a4 = local_1a4 - local_544;
  }
  param_3[0x69] = (short)(int)local_1a4;
  if ((local_1a0 == 0) || (local_1a0 == 4)) {
    local_198 = 0.0;
LAB_0054bc93:
    local_198 = local_198 + local_544;
  }
  else {
    local_198 = (float)(int)sVar7 * local_19c + local_198;
    if (0.0 <= local_198) goto LAB_0054bc93;
    local_198 = local_198 - local_544;
  }
  param_3[0x6a] = (short)(int)local_198;
  if ((local_194 == 0) || (local_194 == 4)) {
    local_18c = 0.0;
LAB_0054bcd9:
    local_18c = local_18c + local_544;
  }
  else {
    local_18c = (float)(int)sVar7 * local_190 + local_18c;
    if (0.0 <= local_18c) goto LAB_0054bcd9;
    local_18c = local_18c - local_544;
  }
  param_3[0x6b] = (short)(int)local_18c;
  if ((local_434 == 0) || (local_434 == 4)) {
    local_42c = 0.0;
LAB_0054bd1f:
    local_42c = local_42c + local_544;
  }
  else {
    local_42c = (float)(int)sVar7 * local_430 + local_42c;
    if (0.0 <= local_42c) goto LAB_0054bd1f;
    local_42c = local_42c - local_544;
  }
  param_3[0x6c] = (short)(int)local_42c;
  if ((local_188 == 0) || (local_188 == 4)) {
    local_180 = 0.0;
LAB_0054bd65:
    local_544 = local_180 + local_544;
  }
  else {
    local_180 = (float)(int)sVar7 * local_184 + local_180;
    if (0.0 <= local_180) goto LAB_0054bd65;
    local_544 = local_180 - local_544;
  }
  uVar2 = FUN_006a3db0();
  *(undefined1 *)(psVar1 + 0x6d) = uVar2;
  local_544 = g_flMissionXpRoundBias;
  sVar7 = (short)param_2;
  if ((local_17c == 0) || (local_17c == 4)) {
    local_174 = 0.0;
LAB_0054bdc3:
    local_174 = local_174 + g_flMissionXpRoundBias;
  }
  else {
    local_174 = (float)(int)sVar7 * local_178 + local_174;
    if (0.0 <= local_174) goto LAB_0054bdc3;
    local_174 = local_174 - g_flMissionXpRoundBias;
  }
  psVar1[0x6e] = (short)(int)local_174;
  if ((local_170 == 0) || (local_170 == 4)) {
    local_168 = 0.0;
LAB_0054be18:
    local_544 = local_168 + local_544;
  }
  else {
    local_168 = (float)(int)sVar7 * local_16c + local_168;
    if (0.0 <= local_168) goto LAB_0054be18;
    local_544 = local_168 - local_544;
  }
  uVar2 = FUN_006a3db0();
  fVar11 = 0.0;
  *(undefined1 *)(psVar1 + 0x6f) = uVar2;
  if (local_164 == 0) {
    local_15c = 0.0;
  }
  else if (local_164 == 4) {
    local_15c = 0.0;
  }
  else {
    local_15c = (float)(int)sVar7 * local_160 + local_15c;
  }
  *(float *)(psVar1 + 0x70) = local_15c;
  if ((local_158 == 0) || (local_158 == 4)) {
    local_150 = 0.0;
  }
  else {
    local_150 = (float)(int)sVar7 * local_154 + local_150;
  }
  *(float *)(psVar1 + 0x72) = local_150;
  if ((local_14c == 0) || (local_14c == 4)) {
    local_144 = 0.0;
  }
  else {
    local_144 = (float)(int)sVar7 * local_148 + local_144;
  }
  *(float *)(psVar1 + 0x74) = local_144;
  if ((local_140 == 0) || (local_140 == 4)) {
    local_138 = 0.0;
  }
  else {
    local_138 = (float)(int)sVar7 * local_13c + local_138;
  }
  *(float *)(psVar1 + 0x76) = local_138;
  if ((local_134 == 0) || (local_134 == 4)) {
    local_12c = 0.0;
  }
  else {
    local_12c = (float)(int)sVar7 * local_130 + local_12c;
  }
  *(float *)(psVar1 + 0x78) = local_12c;
  if ((local_128 == 0) || (local_128 == 4)) {
    local_120 = 0.0;
  }
  else {
    local_120 = (float)(int)sVar7 * local_124 + local_120;
  }
  *(float *)(psVar1 + 0xb0) = local_120;
  if ((local_11c == 0) || (local_11c == 4)) {
    local_114 = 0.0;
  }
  else {
    local_114 = (float)(int)sVar7 * local_118 + local_114;
  }
  *(float *)(psVar1 + 0xb2) = local_114;
  if ((local_110 == 0) || (local_110 == 4)) {
    local_108 = 0.0;
  }
  else {
    local_108 = (float)(int)sVar7 * local_10c + local_108;
  }
  *(float *)(psVar1 + 0xb4) = local_108;
  if ((local_104 == 0) || (local_104 == 4)) {
    local_fc = 0.0;
  }
  else {
    local_fc = (float)(int)sVar7 * local_100 + local_fc;
  }
  *(float *)(psVar1 + 0xb6) = local_fc;
  if ((local_f8 == 0) || (local_f8 == 4)) {
    local_f0 = 0.0;
  }
  else {
    local_f0 = (float)(int)sVar7 * local_f4 + local_f0;
  }
  *(float *)(psVar1 + 0x7a) = local_f0;
  if ((local_ec == 0) || (local_ec == 4)) {
    local_e4 = 0.0;
  }
  else {
    local_e4 = (float)(int)sVar7 * local_e8 + local_e4;
  }
  *(float *)(psVar1 + 0x12) = local_e4;
  if ((local_d4 == 0) || (local_d4 == 4)) {
    local_cc = 0.0;
  }
  else {
    local_cc = (float)(int)sVar7 * local_d0 + local_cc;
  }
  *(float *)(psVar1 + 0x7c) = local_cc;
  if ((local_e0 == 0) || (local_e0 == 4)) {
    local_d8 = 0.0;
  }
  else {
    local_d8 = (float)(int)sVar7 * local_dc + local_d8;
  }
  *(float *)(psVar1 + 0x7e) = local_d8;
  if ((local_c8 == 0) || (local_c8 == 4)) {
    local_c0 = 0.0;
  }
  else {
    local_c0 = (float)(int)sVar7 * local_c4 + local_c0;
  }
  *(float *)(psVar1 + 0x80) = local_c0;
  if ((local_bc == 0) || (local_bc == 4)) {
    local_b4 = 0.0;
  }
  else {
    local_b4 = (float)(int)sVar7 * local_b8 + local_b4;
  }
  *(float *)(psVar1 + 0x82) = local_b4;
  if ((local_b0 == 0) || (local_b0 == 4)) {
    local_a8 = 0.0;
  }
  else {
    local_a8 = (float)(int)sVar7 * local_ac + local_a8;
  }
  *(float *)(psVar1 + 0x84) = local_a8;
  if ((local_518 == 0) || (local_518 == 4)) {
    local_510 = 0.0;
  }
  else {
    local_510 = (float)(int)(short)(sVar7 - (short)param_4) * local_514 + local_510;
    if (local_510 < 0.0) {
      local_510 = local_510 - g_flMissionXpRoundBias;
      goto LAB_0054c1d5;
    }
  }
  local_510 = local_510 + g_flMissionXpRoundBias;
LAB_0054c1d5:
  psVar1[1] = (short)(int)local_510;
  if ((local_50c == 0) || (local_50c == 4)) {
    local_504 = 0.0;
  }
  else {
    local_504 = (float)(int)sVar7 * local_508 + local_504;
  }
  *(undefined1 *)(psVar1 + 0x10) = local_53a;
  psVar1[0x29] = local_53c;
  *(float *)(psVar1 + 2) = local_504;
  *(undefined1 *)((int)psVar1 + 0x21) = local_539;
  *(undefined1 *)(psVar1 + 0x11) = local_538;
  if ((local_a4 == 0) || (local_a4 == 4)) {
    local_9c = 0.0;
  }
  else {
    local_9c = (float)(int)sVar7 * local_a0 + local_9c;
  }
  *(float *)(psVar1 + 0x86) = local_9c;
  if ((local_98 == 0) || (local_98 == 4)) {
    local_90 = 0.0;
  }
  else {
    local_90 = (float)(int)sVar7 * local_94 + local_90;
  }
  *(float *)(psVar1 + 0x88) = local_90;
  if ((local_8c == 0) || (local_8c == 4)) {
    local_84 = 0.0;
  }
  else {
    local_84 = (float)(int)sVar7 * local_88 + local_84;
  }
  *(float *)(psVar1 + 0x8a) = local_84;
  if ((local_80 == 0) || (local_80 == 4)) {
    local_78 = 0.0;
  }
  else {
    local_78 = (float)(int)sVar7 * local_7c + local_78;
  }
  *(float *)(psVar1 + 0x8c) = local_78;
  *(undefined1 *)(psVar1 + 0x8e) = local_537;
  if ((local_74 == 0) || (local_74 == 4)) {
    local_6c = 0.0;
  }
  else {
    local_6c = (float)(int)sVar7 * local_70 + local_6c;
  }
  *(float *)(psVar1 + 0x90) = local_6c;
  if ((local_68 == 0) || (local_68 == 4)) {
    local_60 = 0.0;
  }
  else {
    local_60 = (float)(int)sVar7 * local_64 + local_60;
  }
  *(float *)(psVar1 + 0x92) = local_60;
  if ((local_5c == 0) || (local_5c == 4)) {
    local_54 = 0.0;
  }
  else {
    local_54 = (float)(int)sVar7 * local_58 + local_54;
  }
  *(float *)(psVar1 + 0x94) = local_54;
  if ((local_50 == 0) || (local_50 == 4)) {
    local_48 = 0.0;
  }
  else {
    local_48 = (float)(int)sVar7 * local_4c + local_48;
  }
  *(float *)(psVar1 + 0x96) = local_48;
  if ((local_44 == 0) || (local_44 == 4)) {
    local_3c = 0.0;
  }
  else {
    local_3c = (float)(int)sVar7 * local_40 + local_3c;
  }
  *(float *)(psVar1 + 0x98) = local_3c;
  if ((local_38 == 0) || (local_38 == 4)) {
    local_30 = 0.0;
  }
  else {
    local_30 = (float)(int)sVar7 * local_34 + local_30;
  }
  *(int *)(psVar1 + 0x9a) = (int)local_30;
  if ((local_2c == 0) || (local_2c == 4)) {
    local_24 = 0.0;
  }
  else {
    local_24 = (float)(int)sVar7 * local_28 + local_24;
  }
  *(float *)(psVar1 + 0x9c) = local_24;
  if ((local_20 == 0) || (local_20 == 4)) {
    local_18 = 0.0;
  }
  else {
    local_18 = (float)(int)sVar7 * local_1c + local_18;
  }
  *(undefined1 *)(psVar1 + 0xa0) = local_52c;
  *(float *)(psVar1 + 0x9e) = local_18;
  if ((local_14 != 0) && (local_14 != 4)) {
    fVar11 = (float)(int)sVar7 * local_10 + local_c;
  }
  *(undefined4 *)(psVar1 + 0xa6) = local_534;
  *(undefined1 *)(psVar1 + 0xa4) = local_52b;
  *(uint *)(psVar1 + 0xa8) = -(uint)(local_528 != 0xffffffff) & local_528;
  *(uint *)(psVar1 + 0xaa) = -(uint)(local_524 != 0xffffffff) & local_524;
  *psVar1 = sVar7;
  *(float *)(psVar1 + 0xa2) = fVar11;
  *(uint *)(psVar1 + 0xac) = -(uint)(local_520 != 0xffffffff) & local_520;
  *(uint *)(psVar1 + 0xae) = -(uint)(local_51c != 0xffffffff) & local_51c;
  *(undefined4 *)(psVar1 + 6) = local_540;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
