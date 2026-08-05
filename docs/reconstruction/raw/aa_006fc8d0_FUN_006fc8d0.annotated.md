# Annotated low-level: FUN_006fc8d0

| Field | Value |
|---|---|
| Stable ID | `aa_006fc8d0` |
| VA | `0x006fc8d0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006fc8d0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __thiscall
FUN_006fc8d0(int *param_1,undefined4 param_2,undefined4 param_3,float *param_4)

{
  float *pfVar1;
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
  float fVar13;
  bool bVar14;
  int iVar15;
  float *pfVar16;
  uint uVar17;
  int iVar18;
  float *pfVar19;
  float *pfVar20;
  float *pfVar21;
  int *piVar22;
  int *piVar23;
  undefined4 uVar24;
  float local_170;
  float local_16c;
  float local_168;
  float local_164;
  float local_160;
  float local_15c;
  float local_158;
  float local_154;
  float *local_150;
  uint local_14c;
  float *local_148;
  int local_144;
  float local_140;
  float local_13c;
  float local_138;
  undefined4 local_124;
  float local_120;
  int local_11c;
  int local_118;
  int local_114;
  float local_110;
  int local_10c;
  int local_108;
  int local_104;
  float local_100;
  int local_fc;
  int local_f8;
  int local_f4;
  float local_f0;
  int local_ec;
  int local_e8;
  int local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  int local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  
  local_120 = (float)param_1[8];
  local_90 = (float)param_1[8] - (float)param_1[0x28];
  local_118 = param_1[10];
  local_11c = param_1[9];
  pfVar1 = (float *)(param_1 + 8);
  local_114 = param_1[0xb];
  local_8c = (float)param_1[9] - (float)param_1[0x29];
  local_dc = param_1[0x39];
  local_d8 = param_1[0x3a];
  local_88 = (float)param_1[10] - (float)param_1[0x2a];
  local_e0 = param_1[0x38];
  iVar15 = param_1[1];
  local_84 = (float)param_1[0xb] - (float)param_1[0x2b];
  local_d4 = param_1[0x3b];
  local_a0 = 4;
  if (iVar15 < 3) {
    if (*param_1 < 3) {
      local_a0 = 1;
      goto LAB_006fce9b;
    }
    local_110 = (float)param_1[0xc];
    local_80 = (float)param_1[0xc] - (float)param_1[0x28];
    local_10c = param_1[0xd];
    local_108 = param_1[0xe];
    local_7c = (float)param_1[0xd] - (float)param_1[0x29];
    local_104 = param_1[0xf];
    local_d0 = param_1[0x38];
    local_cc = param_1[0x39];
    local_78 = (float)param_1[0xe] - (float)param_1[0x2a];
    local_c8 = param_1[0x3a];
    local_c4 = param_1[0x3b];
    local_74 = (float)param_1[0xf] - (float)param_1[0x2b];
    local_100 = (float)param_1[0x10];
    local_fc = param_1[0x11];
    local_f8 = param_1[0x12];
    local_70 = (float)param_1[0x10] - (float)param_1[0x28];
    local_f4 = param_1[0x13];
    local_c0 = param_1[0x38];
    local_6c = (float)param_1[0x11] - (float)param_1[0x29];
    local_bc = param_1[0x39];
    local_b8 = param_1[0x3a];
    local_b4 = param_1[0x3b];
    local_68 = (float)param_1[0x12] - (float)param_1[0x2a];
    local_64 = (float)param_1[0x13] - (float)param_1[0x2b];
    if (3 < *param_1) {
      local_f0 = (float)param_1[0x14];
      local_60 = (float)param_1[0x14] - (float)param_1[0x28];
      local_ec = param_1[0x15];
      local_e8 = param_1[0x16];
      local_e4 = param_1[0x17];
      local_5c = (float)param_1[0x15] - (float)param_1[0x29];
      local_b0 = param_1[0x38];
      local_ac = param_1[0x39];
      local_a8 = param_1[0x3a];
      local_58 = (float)param_1[0x16] - (float)param_1[0x2a];
      local_54 = (float)param_1[0x17] - (float)param_1[0x2b];
      local_a4 = local_b4;
      goto LAB_006fce9b;
    }
    if (1 < iVar15) {
      local_f0 = *pfVar1;
      local_60 = *pfVar1 - (float)param_1[0x2c];
      local_ec = param_1[9];
      local_e8 = param_1[10];
      local_e4 = param_1[0xb];
      local_5c = (float)param_1[9] - (float)param_1[0x2d];
      local_b0 = param_1[0x3c];
      local_ac = param_1[0x3d];
      local_a8 = param_1[0x3e];
      local_58 = (float)param_1[10] - (float)param_1[0x2e];
      local_a4 = param_1[0x3f];
      local_54 = (float)param_1[0xb] - (float)param_1[0x2f];
      goto LAB_006fce9b;
    }
  }
  else {
    local_110 = *pfVar1;
    local_80 = *pfVar1 - (float)param_1[0x2c];
    local_10c = param_1[9];
    local_108 = param_1[10];
    local_7c = (float)param_1[9] - (float)param_1[0x2d];
    local_104 = param_1[0xb];
    local_d0 = param_1[0x3c];
    local_cc = param_1[0x3d];
    local_78 = (float)param_1[10] - (float)param_1[0x2e];
    local_c8 = param_1[0x3e];
    local_c4 = param_1[0x3f];
    local_74 = (float)param_1[0xb] - (float)param_1[0x2f];
    local_100 = *pfVar1;
    local_fc = param_1[9];
    local_f8 = param_1[10];
    local_70 = *pfVar1 - (float)param_1[0x30];
    local_f4 = param_1[0xb];
    local_c0 = param_1[0x40];
    local_6c = (float)param_1[9] - (float)param_1[0x31];
    local_bc = param_1[0x41];
    local_b8 = param_1[0x42];
    local_b4 = param_1[0x43];
    local_68 = (float)param_1[10] - (float)param_1[0x32];
    local_64 = (float)param_1[0xb] - (float)param_1[0x33];
    if (3 < iVar15) {
      local_f0 = *pfVar1;
      local_60 = *pfVar1 - (float)param_1[0x34];
      local_ec = param_1[9];
      local_e8 = param_1[10];
      local_e4 = param_1[0xb];
      local_5c = (float)param_1[9] - (float)param_1[0x35];
      local_b0 = param_1[0x44];
      local_ac = param_1[0x45];
      local_a8 = param_1[0x46];
      local_58 = (float)param_1[10] - (float)param_1[0x36];
      local_a4 = param_1[0x47];
      local_54 = (float)param_1[0xb] - (float)param_1[0x37];
      goto LAB_006fce9b;
    }
    if (1 < *param_1) {
      local_f0 = (float)param_1[0xc];
      local_60 = (float)param_1[0xc] - (float)param_1[0x28];
      local_ec = param_1[0xd];
      local_e8 = param_1[0xe];
      local_e4 = param_1[0xf];
      local_5c = (float)param_1[0xd] - (float)param_1[0x29];
      local_b0 = param_1[0x38];
      local_ac = param_1[0x39];
      local_a8 = param_1[0x3a];
      local_58 = (float)param_1[0xe] - (float)param_1[0x2a];
      local_a4 = param_1[0x3b];
      local_54 = (float)param_1[0xf] - (float)param_1[0x2b];
      goto LAB_006fce9b;
    }
  }
  local_a0 = 3;
LAB_006fce9b:
  local_124 = FUN_00702040(param_2,param_3,param_4,&local_120,&local_90,&local_40);
  param_1[9] = local_11c;
  param_1[10] = local_118;
  *pfVar1 = local_120;
  param_1[0xb] = local_114;
  param_1[0xc] = (int)local_110;
  param_1[0xd] = local_10c;
  param_1[0xe] = local_108;
  param_1[0xf] = local_104;
  param_1[0x10] = (int)local_100;
  param_1[0x11] = local_fc;
  param_1[0x12] = local_f8;
  param_1[0x13] = local_f4;
  param_1[0x38] = local_e0;
  param_1[0x39] = local_dc;
  param_1[0x3b] = local_d4;
  param_1[0x3a] = local_d8;
  param_1[0x3c] = local_d0;
  param_1[0x3e] = local_c8;
  param_1[0x3d] = local_cc;
  param_1[0x3f] = local_c4;
  param_1[0x41] = local_bc;
  param_1[0x40] = local_c0;
  param_1[0x42] = local_b8;
  param_1[0x43] = local_b4;
  if (local_a0 == 1) {
    param_1[0x49] = 0;
    param_1[0x4a] = 0;
    param_1[0x4b] = 0;
    param_1[0x48] = 0x3f800000;
    param_1[1] = 1;
    *param_1 = 1;
    return local_124;
  }
  param_1[1] = 3;
  *param_1 = 3;
  iVar15 = FUN_006fb7c0();
  if ((iVar15 == 0) || (iVar15 = FUN_006fb7c0(), iVar15 == 0)) {
    *param_1 = 2;
  }
  iVar15 = FUN_006fb7c0();
  if (iVar15 == 0) {
    iVar15 = *param_1;
    *param_1 = iVar15 + -1;
    iVar15 = iVar15 + 1;
    *pfVar1 = (float)param_1[iVar15 * 4];
    param_1[9] = param_1[iVar15 * 4 + 1];
    param_1[10] = param_1[iVar15 * 4 + 2];
    param_1[0xb] = param_1[iVar15 * 4 + 3];
  }
  iVar15 = FUN_006fb7c0();
  if ((iVar15 == 0) || (iVar15 = FUN_006fb7c0(), iVar15 == 0)) {
    param_1[1] = param_1[1] + -1;
  }
  local_14c = param_1[1];
  if ((1 < (int)local_14c) && (iVar15 = FUN_006fb7c0(), iVar15 == 0)) {
    param_1[1] = local_14c + -1;
    iVar15 = local_14c + 0xd;
    param_1[0x38] = param_1[iVar15 * 4];
    param_1[0x39] = param_1[iVar15 * 4 + 1];
    param_1[0x3a] = param_1[iVar15 * 4 + 2];
    param_1[0x3b] = param_1[iVar15 * 4 + 3];
  }
  uVar17 = param_1[1];
  local_144 = uVar17 - 1;
  local_148 = (float *)(param_1 + 0x28);
  pfVar21 = (float *)(param_1 + 0x38);
  if (3 < (int)uVar17) {
    local_150 = (float *)(param_1 + 0x2e);
    local_14c = uVar17 >> 2;
    local_144 = local_144 + local_14c * -4;
    pfVar16 = pfVar21;
    pfVar19 = local_150;
    do {
      fVar2 = *pfVar16;
      fVar3 = pfVar16[1];
      fVar4 = pfVar16[2];
      *local_148 = fVar2 * *param_4 + fVar3 * param_4[4] + fVar4 * param_4[8] + param_4[0xc];
      pfVar19[-5] = fVar2 * param_4[1] + fVar3 * param_4[5] + fVar4 * param_4[9] + param_4[0xd];
      pfVar19[-4] = fVar2 * param_4[2] + fVar3 * param_4[6] + fVar4 * param_4[10] + param_4[0xe];
      pfVar19[-3] = 0.0;
      fVar2 = pfVar16[4];
      fVar3 = pfVar16[5];
      fVar4 = pfVar16[6];
      pfVar19[-2] = fVar2 * *param_4 + fVar3 * param_4[4] + fVar4 * param_4[8] + param_4[0xc];
      pfVar19[-1] = fVar2 * param_4[1] + fVar3 * param_4[5] + fVar4 * param_4[9] + param_4[0xd];
      *pfVar19 = fVar2 * param_4[2] + fVar3 * param_4[6] + fVar4 * param_4[10] + param_4[0xe];
      pfVar19[1] = 0.0;
      fVar2 = pfVar16[8];
      fVar3 = pfVar16[9];
      fVar4 = pfVar16[10];
      pfVar19[2] = fVar2 * *param_4 + fVar3 * param_4[4] + fVar4 * param_4[8] + param_4[0xc];
      pfVar21 = pfVar16 + 0x10;
      pfVar19[3] = fVar2 * param_4[1] + fVar3 * param_4[5] + fVar4 * param_4[9] + param_4[0xd];
      pfVar19[4] = fVar2 * param_4[2] + fVar3 * param_4[6] + fVar4 * param_4[10] + param_4[0xe];
      pfVar19[5] = 0.0;
      fVar2 = pfVar16[0xc];
      fVar3 = pfVar16[0xd];
      fVar4 = pfVar16[0xe];
      pfVar19[6] = fVar2 * *param_4 + fVar3 * param_4[4] + fVar4 * param_4[8] + param_4[0xc];
      pfVar19[7] = fVar2 * param_4[1] + fVar3 * param_4[5] + fVar4 * param_4[9] + param_4[0xd];
      pfVar19[8] = fVar2 * param_4[2] + fVar3 * param_4[6] + fVar4 * param_4[10] + param_4[0xe];
      pfVar19[9] = 0.0;
      local_148 = local_148 + 0x10;
      local_14c = local_14c - 1;
      pfVar16 = pfVar21;
      pfVar19 = pfVar19 + 0x10;
    } while (local_14c != 0);
    local_14c = 0;
  }
  if (-1 < local_144) {
    iVar15 = local_144 + 1;
    pfVar16 = local_148;
    do {
      fVar2 = *pfVar21;
      fVar3 = pfVar21[1];
      iVar15 = iVar15 + -1;
      fVar4 = pfVar21[2];
      *pfVar16 = fVar2 * *param_4 + fVar3 * param_4[4] + fVar4 * param_4[8] + param_4[0xc];
      pfVar16[1] = fVar2 * param_4[1] + fVar3 * param_4[5] + fVar4 * param_4[9] + param_4[0xd];
      pfVar16[2] = fVar2 * param_4[2] + fVar3 * param_4[6] + fVar4 * param_4[10] + param_4[0xe];
      pfVar16[3] = 0.0;
      pfVar21 = pfVar21 + 4;
      pfVar16 = pfVar16 + 4;
    } while (iVar15 != 0);
  }
  if (4 < *param_1 + param_1[1]) {
    FUN_006fc5c0();
  }
  uVar17 = *param_1 << 3 | param_1[1];
  param_1[4] = 0;
  do {
    if (0x18 < uVar17 - 9) {
switchD_006fd357_caseD_6fdda6:
      param_1[0x48] = (int)-local_40;
      param_1[0x49] = (int)-local_3c;
      param_1[0x4a] = (int)-local_38;
      param_1[0x4b] = (int)-local_34;
      return local_124;
    }
    switch((&switchD_006fd357::switchdataD_006fddf0)
           [(&switchD_006fd357::switchdataD_006fde1c)[uVar17 - 9]]) {
    case (undefined *)0x6fd35e:
      iVar15 = param_1[2];
      uVar24 = 8;
      piVar23 = param_1 + 1;
      pfVar21 = (float *)(param_1 + 0x28);
      pfVar16 = pfVar1;
      piVar22 = param_1;
      goto LAB_006fd39a;
    case (undefined *)0x6fd37d:
      iVar15 = param_1[2];
      uVar24 = 0xfffffff8;
      pfVar16 = (float *)(param_1 + 0x28);
      pfVar21 = pfVar1;
      piVar22 = param_1 + 1;
      piVar23 = param_1;
LAB_006fd39a:
      iVar15 = FUN_006fc000(pfVar16,pfVar21,piVar22,piVar23,iVar15 == 2,uVar24);
      if (iVar15 != 1) {
        if (iVar15 == 2) {
switchD_006fd357_caseD_6fd3af:
          pfVar21 = (float *)(param_1 + 0x28);
          local_160 = (float)param_1[0xc] - *pfVar1;
          local_15c = (float)param_1[0xd] - (float)param_1[9];
          local_158 = (float)param_1[0xe] - (float)param_1[10];
          local_154 = (float)param_1[0xf] - (float)param_1[0xb];
          local_170 = (float)param_1[0x2c] - *pfVar21;
          local_16c = (float)param_1[0x2d] - (float)param_1[0x29];
          local_168 = (float)param_1[0x2e] - (float)param_1[0x2a];
          local_164 = (float)param_1[0x2f] - (float)param_1[0x2b];
          uVar17 = FUN_006f6ef0(pfVar1,&local_160,pfVar21,&local_170,param_1 + 0x4c);
          if (uVar17 != 0) {
            if ((uVar17 & 1) == 0) {
              if ((uVar17 & 2) != 0) goto LAB_006fd453;
            }
            else {
              *pfVar1 = (float)param_1[0xc];
              param_1[9] = param_1[0xd];
              param_1[10] = param_1[0xe];
              param_1[0xb] = param_1[0xf];
LAB_006fd453:
              *param_1 = 1;
            }
            if ((uVar17 & 4) == 0) {
              if ((uVar17 & 8) != 0) {
                param_1[1] = 1;
              }
            }
            else {
              *pfVar21 = (float)param_1[0x2c];
              param_1[0x29] = param_1[0x2d];
              param_1[0x2a] = param_1[0x2e];
              param_1[0x2b] = param_1[0x2f];
              param_1[0x38] = param_1[0x3c];
              param_1[0x39] = param_1[0x3d];
              param_1[0x3a] = param_1[0x3e];
              param_1[0x3b] = param_1[0x3f];
              param_1[1] = 1;
            }
            goto LAB_006fd8b3;
          }
          param_1[0x4b] = 0;
          param_1[0x48] = (int)(local_168 * local_15c - local_16c * local_158);
          param_1[0x49] = (int)(local_158 * local_170 - local_168 * local_160);
          param_1[0x4a] = (int)(local_16c * local_160 - local_15c * local_170);
          if ((*pfVar1 - *pfVar21) * (float)param_1[0x48] +
              ((float)param_1[9] - (float)param_1[0x29]) * (float)param_1[0x49] +
              ((float)param_1[10] - (float)param_1[0x2a]) * (float)param_1[0x4a] < g_flZero)
          goto LAB_006fdda0;
          param_1[0x48] = (int)-(float)param_1[0x48];
          param_1[0x49] = (int)-(float)param_1[0x49];
          param_1[0x4a] = (int)-(float)param_1[0x4a];
          fVar2 = -(float)param_1[0x4b];
          goto LAB_006fdd9a;
        }
        goto LAB_006fdda0;
      }
      goto switchD_006fd357_caseD_6fdda6;
    case (undefined *)0x6fd3af:
      goto switchD_006fd357_caseD_6fd3af;
    case (undefined *)0x6fd4d0:
      iVar15 = FUN_006fbc20(0xbf800000);
      if (iVar15 < 0) goto switchD_006fd357_caseD_6fdda6;
      piVar23 = param_1 + (iVar15 + 10) * 4;
      param_1[1] = param_1[1] + -1;
      *piVar23 = param_1[0x34];
      piVar23[1] = param_1[0x35];
      piVar23[2] = param_1[0x36];
      piVar23[3] = param_1[0x37];
      piVar23 = param_1 + (iVar15 + 0xe) * 4;
      *piVar23 = param_1[0x44];
      piVar23[1] = param_1[0x45];
      piVar23[2] = param_1[0x46];
      piVar23[3] = param_1[0x47];
      break;
    case (undefined *)0x6fd725:
      iVar15 = FUN_006fbc20(0x3f800000);
      if (-1 < iVar15) {
        *param_1 = *param_1 + -1;
        piVar23 = param_1 + (iVar15 + 2) * 4;
        *piVar23 = param_1[0x14];
        piVar23[1] = param_1[0x15];
        piVar23[2] = param_1[0x16];
        piVar23[3] = param_1[0x17];
switchD_006fd357_caseD_6fd766:
        iVar15 = FUN_006fb890(param_1 + 0x28,pfVar1,0xfffffff8);
        if (iVar15 != 0xe) {
          iVar15 = (int)(char)(&DAT_00a0eeec)[iVar15];
          if (-1 < iVar15) {
            local_150 = (float *)(int)(char)(&DAT_00a0eefc)[iVar15];
            fVar2 = (float)param_1[0x28];
            pfVar21 = (float *)(int)(char)(&DAT_00a0eefe)[iVar15];
            pfVar16 = (float *)(param_1 + (iVar15 + 2) * 4);
            fVar3 = *pfVar16;
            fVar4 = (float)param_1[0x29];
            pfVar19 = (float *)(param_1 + ((int)local_150 + 2) * 4);
            fVar5 = pfVar16[1];
            fVar6 = (float)param_1[0x2a];
            fVar7 = pfVar16[2];
            pfVar20 = (float *)(param_1 + ((int)pfVar21 + 2) * 4);
            fVar8 = *pfVar19;
            fVar9 = *pfVar16;
            fVar10 = pfVar19[1];
            fVar11 = pfVar16[1];
            fVar12 = pfVar19[2];
            fVar13 = pfVar16[2];
            local_140 = *pfVar20 - *pfVar16;
            local_13c = pfVar20[1] - pfVar16[1];
            local_138 = pfVar20[2] - pfVar16[2];
            *param_1 = 2;
            if ((fVar10 - fVar11) * (fVar4 - fVar5) +
                (fVar12 - fVar13) * (fVar6 - fVar7) + (fVar8 - fVar9) * (fVar2 - fVar3) < g_flZero)
            {
              *pfVar19 = (float)param_1[0x10];
              pfVar19[1] = (float)param_1[0x11];
              pfVar19[2] = (float)param_1[0x12];
              pfVar19[3] = (float)param_1[0x13];
              if (g_flZero <=
                  local_13c * (fVar4 - fVar5) +
                  local_138 * (fVar6 - fVar7) + local_140 * (fVar2 - fVar3)) goto LAB_006fd8b3;
              pfVar16 = (float *)*param_1;
              if (pfVar21 == pfVar16) {
                pfVar21 = local_150;
              }
              *param_1 = (int)pfVar16 + -1;
              iVar18 = (int)pfVar16 + 1;
              iVar15 = (int)pfVar21 + 2;
              goto LAB_006fd873;
            }
            *pfVar20 = (float)param_1[0x10];
            pfVar20[1] = (float)param_1[0x11];
            pfVar20[2] = (float)param_1[0x12];
            pfVar20[3] = (float)param_1[0x13];
            goto LAB_006fd8b3;
          }
          iVar15 = iVar15 + 8;
          if (3 < iVar15) {
            iVar15 = 1;
          }
          *param_1 = *param_1 + -1;
          piVar23 = param_1 + (iVar15 + 2) * 4;
          *piVar23 = param_1[0x10];
          piVar23[1] = param_1[0x11];
          piVar23[2] = param_1[0x12];
          piVar23[3] = param_1[0x13];
switchD_006fd357_caseD_6fdbf2:
          fVar8 = (float)param_1[0xc] - *pfVar1;
          fVar9 = (float)param_1[0xd] - (float)param_1[9];
          fVar2 = (float)param_1[0xe] - (float)param_1[10];
          fVar3 = (float)param_1[0xc] - (float)param_1[0x28];
          fVar4 = (float)param_1[0xd] - (float)param_1[0x29];
          fVar5 = (float)param_1[0xe] - (float)param_1[0x2a];
          fVar6 = *pfVar1 - (float)param_1[0x28];
          fVar7 = (float)param_1[9] - (float)param_1[0x29];
          fVar10 = (float)param_1[10] - (float)param_1[0x2a];
          if (g_flZero <= fVar3 * fVar8 + fVar4 * fVar9 + fVar5 * fVar2) {
            iVar15 = 0;
          }
          else {
            iVar15 = 8;
          }
          if (g_flZero <= fVar6 * fVar8 + fVar7 * fVar9 + fVar10 * fVar2) {
            iVar18 = 0;
          }
          else {
            iVar18 = 8;
          }
          if (iVar15 != iVar18) {
            param_1[0x4b] = 0;
            fVar11 = fVar10 * fVar4 - fVar7 * fVar5;
            fVar5 = fVar6 * fVar5 - fVar3 * fVar10;
            fVar3 = fVar3 * fVar7 - fVar6 * fVar4;
            param_1[0x48] = (int)(fVar3 * fVar9 - fVar5 * fVar2);
            param_1[0x49] = (int)(fVar11 * fVar2 - fVar8 * fVar3);
            param_1[0x4a] = (int)(fVar8 * fVar5 - fVar11 * fVar9);
            goto LAB_006fdda0;
          }
          if (iVar15 != 0) {
            *pfVar1 = (float)param_1[0xc];
            param_1[9] = param_1[0xd];
            param_1[10] = param_1[0xe];
            param_1[0xb] = param_1[0xf];
            param_1[0x18] = param_1[0x1c];
            param_1[0x19] = param_1[0x1d];
            param_1[0x1a] = param_1[0x1e];
            param_1[0x1b] = param_1[0x1f];
          }
          *param_1 = *param_1 + -1;
          goto switchD_006fd357_caseD_6fdd65;
        }
        goto LAB_006fdda0;
      }
      goto switchD_006fd357_caseD_6fdda6;
    case (undefined *)0x6fd766:
      goto switchD_006fd357_caseD_6fd766;
    case (undefined *)0x6fd9fc:
      goto switchD_006fd357_caseD_6fd9fc;
    case (undefined *)0x6fdbf2:
      goto switchD_006fd357_caseD_6fdbf2;
    case (undefined *)0x6fdd65:
      goto switchD_006fd357_caseD_6fdd65;
    case (undefined *)0x6fdda6:
      goto switchD_006fd357_caseD_6fdda6;
    }
    iVar15 = FUN_006fb890(pfVar1,param_1 + 0x28,8);
    if (iVar15 == 0xe) {
LAB_006fdda0:
      param_1[2] = param_1[1];
      goto switchD_006fd357_caseD_6fdda6;
    }
    iVar15 = (int)(char)(&DAT_00a0eeec)[iVar15];
    if (iVar15 < 0) {
      iVar15 = iVar15 + 8;
      if (3 < iVar15) {
        iVar15 = 1;
      }
      piVar23 = param_1 + (iVar15 + 10) * 4;
      param_1[1] = param_1[1] + -1;
      *piVar23 = param_1[0x30];
      piVar23[1] = param_1[0x31];
      piVar23[2] = param_1[0x32];
      piVar23[3] = param_1[0x33];
      piVar23 = param_1 + (iVar15 + 0xe) * 4;
      *piVar23 = param_1[0x40];
      piVar23[1] = param_1[0x41];
      piVar23[2] = param_1[0x42];
      piVar23[3] = param_1[0x43];
switchD_006fd357_caseD_6fd9fc:
      fVar8 = (float)param_1[0x2c] - (float)param_1[0x28];
      fVar9 = (float)param_1[0x2d] - (float)param_1[0x29];
      fVar2 = (float)param_1[0x2e] - (float)param_1[0x2a];
      fVar3 = (float)param_1[0x2c] - *pfVar1;
      fVar4 = (float)param_1[0x2d] - (float)param_1[9];
      fVar5 = (float)param_1[0x2e] - (float)param_1[10];
      fVar6 = (float)param_1[0x28] - *pfVar1;
      fVar7 = (float)param_1[0x29] - (float)param_1[9];
      fVar10 = (float)param_1[0x2a] - (float)param_1[10];
      if (g_flZero <= fVar3 * fVar8 + fVar4 * fVar9 + fVar5 * fVar2) {
        iVar15 = 0;
      }
      else {
        iVar15 = 8;
      }
      if (g_flZero <= fVar6 * fVar8 + fVar7 * fVar9 + fVar10 * fVar2) {
        iVar18 = 0;
      }
      else {
        iVar18 = 8;
      }
      if (iVar15 == iVar18) {
        if (iVar15 != 0) {
          param_1[0x28] = param_1[0x2c];
          param_1[0x29] = param_1[0x2d];
          param_1[0x2a] = param_1[0x2e];
          param_1[0x2b] = param_1[0x2f];
          param_1[0x38] = param_1[0x3c];
          param_1[0x39] = param_1[0x3d];
          param_1[0x3a] = param_1[0x3e];
          param_1[0x3b] = param_1[0x3f];
        }
        param_1[1] = param_1[1] + -1;
switchD_006fd357_caseD_6fdd65:
        param_1[0x48] = (int)((float)param_1[0x28] - *pfVar1);
        param_1[0x49] = (int)((float)param_1[0x29] - (float)param_1[9]);
        param_1[0x4a] = (int)((float)param_1[0x2a] - (float)param_1[10]);
        fVar2 = (float)param_1[0x2b] - (float)param_1[0xb];
LAB_006fdd9a:
        param_1[0x4b] = (int)fVar2;
      }
      else {
        param_1[0x4b] = 0;
        fVar11 = fVar10 * fVar4 - fVar7 * fVar5;
        fVar5 = fVar6 * fVar5 - fVar3 * fVar10;
        fVar3 = fVar3 * fVar7 - fVar6 * fVar4;
        param_1[0x48] = (int)(fVar5 * fVar2 - fVar3 * fVar9);
        param_1[0x49] = (int)(fVar8 * fVar3 - fVar11 * fVar2);
        param_1[0x4a] = (int)(fVar11 * fVar9 - fVar8 * fVar5);
      }
      goto LAB_006fdda0;
    }
    local_150 = (float *)(int)(char)(&DAT_00a0eefc)[iVar15];
    fVar2 = *pfVar1;
    pfVar21 = (float *)(int)(char)(&DAT_00a0eefe)[iVar15];
    pfVar16 = (float *)(param_1 + (iVar15 + 10) * 4);
    fVar3 = *pfVar16;
    fVar4 = (float)param_1[9];
    pfVar19 = (float *)(param_1 + ((int)local_150 + 10) * 4);
    fVar5 = pfVar16[1];
    fVar6 = (float)param_1[10];
    fVar7 = pfVar16[2];
    pfVar20 = (float *)(param_1 + ((int)pfVar21 + 10) * 4);
    fVar8 = *pfVar19;
    fVar9 = *pfVar16;
    fVar10 = pfVar19[1];
    fVar11 = pfVar16[1];
    fVar12 = pfVar19[2];
    fVar13 = pfVar16[2];
    local_50 = *pfVar20 - *pfVar16;
    local_4c = pfVar20[1] - pfVar16[1];
    local_48 = pfVar20[2] - pfVar16[2];
    param_1[1] = 2;
    if (g_flZero <=
        (fVar10 - fVar11) * (fVar4 - fVar5) +
        (fVar12 - fVar13) * (fVar6 - fVar7) + (fVar8 - fVar9) * (fVar2 - fVar3)) {
      *pfVar20 = (float)param_1[0x30];
      pfVar20[1] = (float)param_1[0x31];
      pfVar20[2] = (float)param_1[0x32];
      pfVar20[3] = (float)param_1[0x33];
      piVar23 = param_1 + ((int)pfVar21 + 0xe) * 4;
      *piVar23 = param_1[0x40];
      piVar23[1] = param_1[0x41];
      piVar23[2] = param_1[0x42];
      piVar23[3] = param_1[0x43];
    }
    else {
      *pfVar19 = (float)param_1[0x30];
      pfVar19[1] = (float)param_1[0x31];
      pfVar19[2] = (float)param_1[0x32];
      pfVar19[3] = (float)param_1[0x33];
      piVar23 = param_1 + ((int)local_150 + 0xe) * 4;
      *piVar23 = param_1[0x40];
      piVar23[1] = param_1[0x41];
      bVar14 = local_4c * (fVar4 - fVar5) + local_48 * (fVar6 - fVar7) + local_50 * (fVar2 - fVar3)
               < g_flZero;
      piVar23[2] = param_1[0x42];
      piVar23[3] = param_1[0x43];
      if (bVar14) {
        pfVar16 = (float *)param_1[1];
        if (pfVar21 == pfVar16) {
          pfVar21 = local_150;
        }
        param_1[1] = (int)pfVar16 + -1;
        iVar15 = (int)pfVar16 + 9;
        piVar23 = param_1 + ((int)pfVar21 + 10) * 4;
        *piVar23 = param_1[iVar15 * 4];
        piVar23[1] = param_1[iVar15 * 4 + 1];
        piVar23[2] = param_1[iVar15 * 4 + 2];
        piVar23[3] = param_1[iVar15 * 4 + 3];
        iVar18 = param_1[1] + 0xe;
        iVar15 = (int)pfVar21 + 0xe;
LAB_006fd873:
        piVar23 = param_1 + iVar15 * 4;
        *piVar23 = param_1[iVar18 * 4];
        piVar23[1] = param_1[iVar18 * 4 + 1];
        piVar23[2] = param_1[iVar18 * 4 + 2];
        piVar23[3] = param_1[iVar18 * 4 + 3];
      }
    }
LAB_006fd8b3:
    uVar17 = *param_1 << 3 | param_1[1];
  } while( true );
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
