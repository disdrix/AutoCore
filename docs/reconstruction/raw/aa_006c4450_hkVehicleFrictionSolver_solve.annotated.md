# Annotated low-level: hkVehicleFrictionSolver_solve

| Field | Value |
|---|---|
| Stable ID | `aa_006c4450` |
| VA | `0x006c4450` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006c4450`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void hkVehicleFrictionSolver_solve(float *param_1,int param_2,int param_3,float *param_4)

{
  char cVar1;
  char cVar2;
  float fVar3;
  int iVar4;
  bool bVar5;
  float *pfVar6;
  uint uVar7;
  float *pfVar8;
  float *pfVar9;
  int extraout_ECX;
  int *piVar10;
  int iVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  int local_188;
  float local_184;
  float *local_180;
  int local_178;
  float local_160;
  float local_15c;
  float local_158;
  float local_154;
  float local_130 [4];
  float local_120;
  float fStack_11c;
  float fStack_118;
  float local_110;
  float fStack_10c;
  float fStack_108;
  float local_100;
  float fStack_fc;
  float fStack_f8;
  float local_f0;
  float local_e8 [5];
  float local_d4;
  float local_d0;
  float local_cc [4];
  float local_bc;
  float local_b8;
  float local_80;
  float fStack_7c;
  float fStack_78;
  float local_70;
  float fStack_6c;
  float fStack_68;
  float local_60;
  float fStack_5c;
  float fStack_58;
  float local_48;
  float local_44;
  float local_3c;
  float local_34;
  float local_30;
  float local_2c;
  float local_20;
  float local_1c;
  float local_18;
  
  pfVar9 = param_4 + 6;
  local_180 = (float *)(param_2 + 0x54);
  pfVar6 = &local_100;
  local_184 = 2.8026e-45;
  pfVar8 = (float *)(param_3 + 0x20);
  do {
    fVar3 = pfVar8[4];
    fVar21 = *pfVar8;
    fVar23 = pfVar8[1];
    fVar18 = pfVar8[2];
    fVar19 = pfVar8[3];
    cVar1 = *(char *)(param_3 + 0xbc);
    fVar12 = pfVar8[-8] - *(float *)(param_3 + 0xf0);
    fVar13 = pfVar8[-7] - *(float *)(param_3 + 0xf4);
    fVar14 = pfVar8[-6] - *(float *)(param_3 + 0xf8);
    fVar15 = pfVar8[-5] - *(float *)(param_3 + 0xfc);
    fVar16 = pfVar8[-8] - *(float *)((int)fVar3 + 0x40);
    fVar17 = pfVar8[-7] - *(float *)((int)fVar3 + 0x44);
    fVar20 = pfVar8[-6] - *(float *)((int)fVar3 + 0x48);
    fVar22 = pfVar8[-5] - *(float *)((int)fVar3 + 0x4c);
    pfVar6[-0x14] = fVar21;
    pfVar6[-0x13] = fVar23;
    pfVar6[-0x12] = fVar18;
    pfVar6[-0x11] = fVar19;
    fVar24 = fVar13 * fVar18 - fVar14 * fVar23;
    fVar25 = fVar14 * fVar21 - fVar12 * fVar18;
    fVar27 = fVar12 * fVar23 - fVar13 * fVar21;
    fVar29 = fVar15 * fVar19 - fVar15 * fVar19;
    if (cVar1 == '\0') {
      fVar29 = *(float *)(param_3 + 300) * fVar27;
      fVar31 = *(float *)(param_3 + 0x118) * fVar25;
      fVar32 = *(float *)(param_3 + 0x11c) * fVar25;
      fVar26 = *(float *)(param_3 + 0x104) * fVar24;
      fVar28 = *(float *)(param_3 + 0x108) * fVar24;
      fVar30 = *(float *)(param_3 + 0x10c) * fVar24;
      fVar24 = *(float *)(param_3 + 0x100) * fVar24 + *(float *)(param_3 + 0x110) * fVar25 +
               *(float *)(param_3 + 0x120) * fVar27;
      fVar25 = fVar26 + *(float *)(param_3 + 0x114) * fVar25 + *(float *)(param_3 + 0x124) * fVar27;
      fVar27 = fVar28 + fVar31 + *(float *)(param_3 + 0x128) * fVar27;
      fVar29 = fVar30 + fVar32 + fVar29;
    }
    cVar2 = *(char *)((int)fVar3 + 0xc);
    pfVar6[-0x10] = fVar24;
    pfVar6[-0xf] = fVar25;
    pfVar6[-0xe] = fVar27;
    pfVar6[-0xd] = fVar29;
    fVar24 = fVar23 * fVar20 - fVar18 * fVar17;
    fVar18 = fVar18 * fVar16 - fVar21 * fVar20;
    fVar21 = fVar21 * fVar17 - fVar23 * fVar16;
    fVar23 = fVar19 * fVar22 - fVar19 * fVar22;
    if (cVar2 == '\0') {
      fVar23 = *(float *)((int)fVar3 + 0x7c) * fVar21;
      fVar29 = *(float *)((int)fVar3 + 0x68) * fVar18;
      fVar26 = *(float *)((int)fVar3 + 0x6c) * fVar18;
      fVar19 = *(float *)((int)fVar3 + 0x54) * fVar24;
      fVar25 = *(float *)((int)fVar3 + 0x58) * fVar24;
      fVar27 = *(float *)((int)fVar3 + 0x5c) * fVar24;
      fVar24 = *(float *)((int)fVar3 + 0x50) * fVar24 + *(float *)((int)fVar3 + 0x60) * fVar18 +
               *(float *)((int)fVar3 + 0x70) * fVar21;
      fVar18 = fVar19 + *(float *)((int)fVar3 + 100) * fVar18 +
               *(float *)((int)fVar3 + 0x74) * fVar21;
      fVar21 = fVar25 + fVar29 + *(float *)((int)fVar3 + 0x78) * fVar21;
      fVar23 = fVar27 + fVar26 + fVar23;
    }
    fVar27 = *(float *)(param_3 + 0xe0);
    fVar29 = *(float *)(param_3 + 0xe4);
    fVar26 = *(float *)(param_3 + 0xe8);
    fVar19 = *(float *)((int)fVar3 + 0x3c);
    fVar25 = *(float *)(param_3 + 0xec);
    fVar28 = *(float *)((int)fVar3 + 0x30);
    fVar30 = *(float *)((int)fVar3 + 0x34);
    fVar31 = *(float *)((int)fVar3 + 0x38);
    pfVar6[-0xc] = fVar24;
    pfVar6[-0xb] = fVar18;
    pfVar6[-10] = fVar21;
    pfVar6[-9] = fVar23;
    fVar25 = fVar19 + fVar25 + _DAT_00a0d2f4;
    fVar27 = pfVar6[-0xe] * pfVar6[-0xe] * fVar26 + pfVar6[-10] * pfVar6[-10] * fVar31 +
             pfVar6[-0xf] * pfVar6[-0xf] * fVar29 + pfVar6[-0xb] * pfVar6[-0xb] * fVar30 +
             pfVar6[-0x10] * pfVar6[-0x10] * fVar27 + pfVar6[-0xc] * pfVar6[-0xc] * fVar28 + fVar25;
    fVar23 = pfVar8[-4];
    fVar18 = pfVar8[-3];
    fVar19 = pfVar8[-2];
    fVar24 = pfVar8[-1];
    pfVar6[-9] = fVar27;
    pfVar6[-0xd] = g_flOne / fVar27;
    fVar21 = *local_180;
    pfVar6[0xb] = fVar27 + fVar21;
    pfVar6[10] = g_flOne / (fVar27 + fVar21);
    pfVar6[-8] = fVar23;
    pfVar6[-7] = fVar18;
    pfVar6[-6] = fVar19;
    pfVar6[-5] = fVar24;
    fVar21 = fVar13 * fVar19 - fVar14 * fVar18;
    fVar14 = fVar14 * fVar23 - fVar12 * fVar19;
    fVar12 = fVar12 * fVar18 - fVar13 * fVar23;
    fVar13 = fVar15 * fVar24 - fVar15 * fVar24;
    if (cVar1 == '\0') {
      fVar13 = *(float *)(param_3 + 300) * fVar12;
      fVar26 = *(float *)(param_3 + 0x118) * fVar14;
      fVar32 = *(float *)(param_3 + 0x11c) * fVar14;
      fVar15 = *(float *)(param_3 + 0x104) * fVar21;
      fVar27 = *(float *)(param_3 + 0x108) * fVar21;
      fVar29 = *(float *)(param_3 + 0x10c) * fVar21;
      fVar21 = *(float *)(param_3 + 0x100) * fVar21 + *(float *)(param_3 + 0x110) * fVar14 +
               *(float *)(param_3 + 0x120) * fVar12;
      fVar14 = fVar15 + *(float *)(param_3 + 0x114) * fVar14 + *(float *)(param_3 + 0x124) * fVar12;
      fVar12 = fVar27 + fVar26 + *(float *)(param_3 + 0x128) * fVar12;
      fVar13 = fVar29 + fVar32 + fVar13;
    }
    pfVar6[-4] = fVar21;
    pfVar6[-3] = fVar14;
    pfVar6[-2] = fVar12;
    pfVar6[-1] = fVar13;
    fVar12 = fVar18 * fVar20 - fVar19 * fVar17;
    fVar19 = fVar19 * fVar16 - fVar23 * fVar20;
    fVar23 = fVar23 * fVar17 - fVar18 * fVar16;
    fVar21 = fVar24 * fVar22 - fVar24 * fVar22;
    if (cVar2 == '\0') {
      fVar21 = *(float *)((int)fVar3 + 0x7c) * fVar23;
      fVar15 = *(float *)((int)fVar3 + 0x68) * fVar19;
      fVar16 = *(float *)((int)fVar3 + 0x6c) * fVar19;
      fVar18 = *(float *)((int)fVar3 + 0x54) * fVar12;
      fVar13 = *(float *)((int)fVar3 + 0x58) * fVar12;
      fVar14 = *(float *)((int)fVar3 + 0x5c) * fVar12;
      fVar12 = *(float *)((int)fVar3 + 0x50) * fVar12 + *(float *)((int)fVar3 + 0x60) * fVar19 +
               *(float *)((int)fVar3 + 0x70) * fVar23;
      fVar19 = fVar18 + *(float *)((int)fVar3 + 100) * fVar19 +
               *(float *)((int)fVar3 + 0x74) * fVar23;
      fVar23 = fVar13 + fVar15 + *(float *)((int)fVar3 + 0x78) * fVar23;
      fVar21 = fVar14 + fVar16 + fVar21;
    }
    *pfVar6 = fVar12;
    pfVar6[1] = fVar19;
    pfVar6[2] = fVar23;
    pfVar6[3] = fVar21;
    fVar25 = fVar25 + pfVar6[-2] * pfVar6[-2] * *(float *)(param_3 + 0xe8) +
                      pfVar6[2] * pfVar6[2] * fVar31 +
                      pfVar6[-3] * pfVar6[-3] * *(float *)(param_3 + 0xe4) +
                      pfVar6[1] * pfVar6[1] * fVar30 +
                      pfVar6[-4] * pfVar6[-4] * *(float *)(param_3 + 0xe0) +
                      *pfVar6 * *pfVar6 * fVar28;
    fVar21 = *(float *)(param_3 + 0x140);
    fVar23 = *(float *)(param_3 + 0x144);
    fVar18 = *(float *)(param_3 + 0x148);
    fVar19 = *(float *)(param_3 + 0x150);
    fVar12 = *(float *)(param_3 + 0x154);
    fVar13 = *(float *)(param_3 + 0x158);
    pfVar6[3] = fVar25;
    pfVar6[-1] = g_flOne / fVar25;
    pfVar6[8] = pfVar6[-1];
    pfVar6[9] = pfVar6[3];
    fVar3 = pfVar8[5];
    fVar14 = *(float *)((int)fVar3 + 0x20);
    fVar15 = *(float *)((int)fVar3 + 0x24);
    fVar16 = *(float *)((int)fVar3 + 0x28);
    fVar21 = fVar21 - *(float *)((int)fVar3 + 0x10);
    fVar23 = fVar23 - *(float *)((int)fVar3 + 0x14);
    fVar18 = fVar18 - *(float *)((int)fVar3 + 0x18);
    fVar3 = pfVar6[-0x14];
    fVar17 = pfVar6[-0x13];
    fVar20 = pfVar6[-0x12];
    fVar22 = pfVar6[-0xc];
    fVar24 = pfVar6[-0xb];
    fVar25 = pfVar6[-10];
    fVar27 = pfVar6[-0x10];
    fVar29 = pfVar6[-0xf];
    fVar26 = pfVar6[-0xe];
    pfVar9[-1] = fVar13 * pfVar6[-2] + fVar16 * pfVar6[2] + fVar18 * pfVar6[-6] +
                 fVar12 * pfVar6[-3] + fVar15 * pfVar6[1] + fVar23 * pfVar6[-7] +
                 fVar19 * pfVar6[-4] + fVar14 * *pfVar6 + fVar21 * pfVar6[-8] + pfVar9[-1];
    *pfVar9 = fVar13 * fVar26 + fVar16 * fVar25 + fVar18 * fVar20 +
              fVar12 * fVar29 + fVar15 * fVar24 + fVar23 * fVar17 +
              fVar19 * fVar27 + fVar14 * fVar22 + fVar21 * fVar3 + *pfVar9;
    local_180 = local_180 + 0x19;
    pfVar6 = pfVar6 + 0x28;
    pfVar9 = pfVar9 + 7;
    local_184 = (float)((int)local_184 + -1);
    pfVar8 = pfVar8 + 0x14;
  } while (local_184 != 0.0);
  iVar11 = *(int *)(param_3 + 0x30);
  piVar10 = (int *)(param_3 + 0x30);
  if (iVar11 == *(int *)(param_3 + 0x80)) {
    fVar3 = *(float *)(param_3 + 0xec);
    fVar21 = *(float *)(iVar11 + 0x3c);
    local_180 = (float *)(fStack_108 * fStack_68 * *(float *)(param_3 + 0xe8) +
                          fStack_f8 * fStack_58 * *(float *)(iVar11 + 0x38) +
                          fVar3 * fStack_118 * fStack_78 + fVar21 * fStack_118 * fStack_78 +
                         fStack_10c * fStack_6c * *(float *)(param_3 + 0xe4) +
                         fStack_fc * fStack_5c * *(float *)(iVar11 + 0x34) +
                         fVar3 * fStack_11c * fStack_7c + fVar21 * fStack_11c * fStack_7c +
                         local_110 * local_70 * *(float *)(param_3 + 0xe0) +
                         local_100 * local_60 * *(float *)(iVar11 + 0x30) +
                         fVar3 * local_120 * local_80 + fVar21 * local_120 * local_80);
  }
  else {
    fVar3 = *(float *)(param_3 + 0xec);
    local_180 = (float *)(fStack_108 * fStack_68 * *(float *)(param_3 + 0xe8) +
                          fVar3 * fStack_118 * fStack_78 +
                         fStack_10c * fStack_6c * *(float *)(param_3 + 0xe4) +
                         fVar3 * fStack_11c * fStack_7c +
                         local_110 * local_70 * *(float *)(param_3 + 0xe0) +
                         fVar3 * local_120 * local_80);
  }
  fVar3 = local_3c * local_e8[3] - (float)local_180 * (float)local_180;
  if (g_flZero <= fVar3 * fVar3) {
    fVar3 = g_flOne / fVar3;
    local_160 = local_3c * fVar3;
    local_15c = -((float)local_180 * fVar3);
    local_154 = fVar3 * local_e8[3];
    local_158 = local_15c;
  }
  pfVar6 = param_4 + 4;
  pfVar8 = local_130;
  local_178 = 2;
  do {
    fVar3 = *pfVar6;
    if (fVar3 != g_flZero) {
      iVar11 = *piVar10;
      fVar21 = pfVar8[-8];
      fVar23 = pfVar8[-7];
      fVar18 = pfVar8[-6];
      fVar19 = pfVar8[-5];
      fVar12 = *pfVar8;
      fVar13 = pfVar8[1];
      fVar14 = pfVar8[2];
      fVar15 = pfVar8[3];
      fVar16 = pfVar8[-4];
      fVar17 = pfVar8[-3];
      fVar20 = pfVar8[-2];
      fVar22 = pfVar8[-1];
      fVar24 = *(float *)(param_3 + 0xe0);
      fVar25 = *(float *)(param_3 + 0xe4);
      fVar27 = *(float *)(param_3 + 0xe8);
      fVar30 = fVar3 * *(float *)(param_3 + 0xec);
      fVar29 = *(float *)(iVar11 + 0x30);
      fVar26 = *(float *)(iVar11 + 0x34);
      fVar28 = *(float *)(iVar11 + 0x38);
      fVar31 = fVar3 * *(float *)(iVar11 + 0x3c);
      *(float *)(param_3 + 0xc0) = *(float *)(param_3 + 0xc0) + fVar30 * fVar21;
      *(float *)(param_3 + 0xc4) = *(float *)(param_3 + 0xc4) + fVar30 * fVar23;
      *(float *)(param_3 + 200) = *(float *)(param_3 + 200) + fVar30 * fVar18;
      *(float *)(param_3 + 0xcc) = *(float *)(param_3 + 0xcc) + fVar30 * fVar19;
      *(float *)(iVar11 + 0x10) = *(float *)(iVar11 + 0x10) - fVar31 * fVar21;
      *(float *)(iVar11 + 0x14) = *(float *)(iVar11 + 0x14) - fVar31 * fVar23;
      *(float *)(iVar11 + 0x18) = *(float *)(iVar11 + 0x18) - fVar31 * fVar18;
      *(float *)(iVar11 + 0x1c) = *(float *)(iVar11 + 0x1c) - fVar31 * fVar19;
      *(float *)(param_3 + 0xd0) = *(float *)(param_3 + 0xd0) + fVar3 * fVar24 * fVar16;
      *(float *)(param_3 + 0xd4) = *(float *)(param_3 + 0xd4) + fVar3 * fVar25 * fVar17;
      *(float *)(param_3 + 0xd8) = *(float *)(param_3 + 0xd8) + fVar3 * fVar27 * fVar20;
      *(float *)(param_3 + 0xdc) = *(float *)(param_3 + 0xdc) + fVar30 * fVar22;
      *(float *)(iVar11 + 0x20) = *(float *)(iVar11 + 0x20) + fVar3 * fVar29 * fVar12;
      *(float *)(iVar11 + 0x24) = *(float *)(iVar11 + 0x24) + fVar3 * fVar26 * fVar13;
      *(float *)(iVar11 + 0x28) = *(float *)(iVar11 + 0x28) + fVar3 * fVar28 * fVar14;
      *(float *)(iVar11 + 0x2c) = *(float *)(iVar11 + 0x2c) + fVar31 * fVar15;
    }
    pfVar6 = pfVar6 + 7;
    piVar10 = piVar10 + 0x14;
    pfVar8 = pfVar8 + 0x28;
    local_178 = local_178 + -1;
  } while (local_178 != 0);
  fVar3 = *(float *)(param_3 + 0x94);
  pfVar6 = param_4 + 6;
  pfVar8 = (float *)(param_3 + 0x48);
  fVar18 = fVar3 + *(float *)(param_3 + 0x44);
  local_188 = 2;
  local_e8[1] = *(float *)(param_3 + 0x44) * *(float *)(param_2 + 100) +
                fVar18 * *(float *)(param_2 + 0x68);
  fVar21 = *(float *)(param_2 + 0xcc);
  fVar23 = *(float *)(param_2 + 200);
  param_4[2] = 0.0;
  param_4[9] = 0.0;
  local_44 = fVar3 * fVar23 + fVar18 * fVar21;
  pfVar9 = &local_110;
  do {
    fVar21 = pfVar8[-6];
    fVar3 = pfVar6[-1];
    fVar23 = *(float *)((int)fVar21 + 0x20);
    fVar18 = *(float *)((int)fVar21 + 0x24);
    fVar19 = *(float *)((int)fVar21 + 0x28);
    fVar12 = *(float *)(param_3 + 0xd0);
    fVar13 = *(float *)(param_3 + 0xd4);
    fVar14 = *(float *)(param_3 + 0xd8);
    fVar15 = *(float *)(param_3 + 0xc0) - *(float *)((int)fVar21 + 0x10);
    fVar16 = *(float *)(param_3 + 0xc4) - *(float *)((int)fVar21 + 0x14);
    fVar21 = *(float *)(param_3 + 200) - *(float *)((int)fVar21 + 0x18);
    fVar17 = fVar14 * pfVar9[-10] + fVar19 * pfVar9[-6] + fVar21 * pfVar9[-0xe] +
             fVar13 * pfVar9[-0xb] + fVar18 * pfVar9[-7] + fVar16 * pfVar9[-0xf] +
             fVar12 * pfVar9[-0xc] + fVar23 * pfVar9[-8] + fVar15 * pfVar9[-0x10];
    pfVar9[8] = fVar17;
    fVar18 = fVar3 * DAT_00a0f704 +
             fVar14 * pfVar9[2] + fVar19 * pfVar9[6] + fVar21 * pfVar9[-2] +
             fVar13 * pfVar9[1] + fVar18 * pfVar9[5] + fVar16 * pfVar9[-3] +
             fVar12 * *pfVar9 + fVar23 * pfVar9[4] + fVar15 * pfVar9[-4];
    pfVar9[10] = fVar18;
    fVar3 = pfVar9[0xb];
    fVar21 = *param_1;
    fVar23 = *pfVar8;
    if (*(char *)(pfVar8 + 1) == '\0') {
      *pfVar6 = 0.0;
      local_184 = pfVar6[-6];
      pfVar9[9] = local_184;
    }
    else {
      local_184 = -fVar17;
      pfVar9[9] = local_184;
      fVar12 = pfVar9[0xc] * pfVar9[0xf] * (*pfVar6 * DAT_00a0f298 + fVar17) * DAT_00a0f298;
      fVar23 = pfVar8[-4] * pfVar9[0xf] * ABS(fVar3) * fVar21;
      fVar19 = fVar12;
      if ((fVar23 < ABS(fVar12)) && (fVar19 = fVar23, fVar12 <= g_flZero)) {
        fVar19 = -fVar23;
      }
      pfVar9[9] = local_184 - fVar19;
      fVar23 = g_flZero;
    }
    fVar19 = pfVar8[-4];
    if (pfVar8[-3] != g_flZero) {
      fVar19 = SQRT(local_184 * local_184 + fVar18 * fVar18) * pfVar8[-3] + pfVar8[-4];
      if (pfVar8[-2] <= fVar19) {
        fVar19 = pfVar8[-2];
      }
      if (fVar19 < g_flZero) {
        fVar19 = g_flZero;
      }
    }
    fVar19 = fVar19 * ABS(fVar3) * fVar21;
    pfVar8 = pfVar8 + 0x14;
    pfVar9[0x12] = fVar19;
    pfVar6 = pfVar6 + 7;
    pfVar9[0x13] = fVar19;
    fVar3 = g_flOne / (fVar19 + _DAT_00a0d2f4);
    pfVar9[0x14] = fVar3;
    pfVar9[0x15] = fVar3;
    local_188 = local_188 + -1;
    pfVar9[0x10] = fVar23 * *param_1 + pfVar9[0xe] * pfVar9[9];
    pfVar9 = pfVar9 + 0x28;
  } while (local_188 != 0);
  local_cc[0] = -(local_e8[0] * local_160 + local_48 * local_15c);
  local_2c = -(local_158 * local_e8[0] + local_154 * local_48);
  fVar3 = local_cc[0] * local_bc;
  fVar3 = local_d0 * local_cc[3] * local_d0 * local_cc[3] + fVar3 * fVar3;
  fVar21 = local_2c * local_1c;
  fVar21 = local_30 * local_20 * local_30 * local_20 + fVar21 * fVar21;
  if (*(float *)(param_3 + 0xa0) <= ABS(local_f0)) {
    param_4[5] = 0.0;
    param_4[6] = 0.0;
    param_4[0xc] = 0.0;
    param_4[0xd] = 0.0;
  }
  if ((g_flOne < fVar3) || (g_flOne < fVar21)) {
    if (g_flOne < fVar3) {
      fVar23 = g_flOne / fVar3;
      param_4[5] = fVar23 * param_4[5];
      param_4[6] = fVar23 * param_4[6];
    }
    if (g_flOne < fVar21) {
      fVar23 = g_flOne / fVar21;
      param_4[0xc] = fVar23 * param_4[0xc];
      param_4[0xd] = fVar23 * param_4[0xd];
    }
    local_188 = 2;
    bVar5 = fVar3 <= fVar21;
    do {
      uVar7 = (uint)bVar5;
      local_cc[uVar7 * 0x28] = -(local_e8[uVar7 * 0x28 + 2] * local_e8[uVar7 * 0x28]);
      hkVehicleFrictionSolver_circleProjection(param_4 + uVar7 * 7);
      local_188 = local_188 + -1;
      local_e8[(uint)(fVar21 < fVar3) * 0x28] =
           (float)local_180 * *(float *)(extraout_ECX + 0x84) +
           local_e8[(uint)(fVar21 < fVar3) * 0x28];
      bVar5 = fVar3 > fVar21;
    } while (local_188 != 0);
    param_4[1] = local_e8[0];
    *param_4 = local_d4 * local_b8;
    param_4[7] = local_34 * local_18;
  }
  else {
    *param_4 = 0.0;
    param_4[7] = 0.0;
    param_4[1] = 0.0;
    local_48 = 0.0;
  }
  param_4[0xb] = local_30;
  param_4[8] = local_48;
  param_4[4] = local_d0;
  piVar10 = (int *)(param_3 + 0x30);
  param_4[3] = local_cc[0] * param_1[1];
  iVar11 = 2;
  param_4[10] = local_2c * param_1[1];
  pfVar6 = (float *)&stack0xfffffe60;
  do {
    iVar4 = *piVar10;
    fVar21 = pfVar6[0x20];
    fVar23 = pfVar6[0x21];
    fVar18 = pfVar6[0x22];
    fVar19 = pfVar6[0x23];
    fVar12 = pfVar6[0x28];
    fVar13 = pfVar6[0x29];
    fVar14 = pfVar6[0x2a];
    fVar15 = pfVar6[0x2b];
    fVar16 = pfVar6[0x24];
    fVar17 = pfVar6[0x25];
    fVar20 = pfVar6[0x26];
    fVar22 = pfVar6[0x27];
    fVar3 = pfVar6[0x35];
    fVar24 = *(float *)(param_3 + 0xe0);
    fVar25 = *(float *)(param_3 + 0xe4);
    fVar27 = *(float *)(param_3 + 0xe8);
    fVar30 = fVar3 * *(float *)(param_3 + 0xec);
    fVar29 = *(float *)(iVar4 + 0x30);
    fVar26 = *(float *)(iVar4 + 0x34);
    fVar28 = *(float *)(iVar4 + 0x38);
    fVar31 = fVar3 * *(float *)(iVar4 + 0x3c);
    *(float *)(param_3 + 0xc0) = *(float *)(param_3 + 0xc0) + fVar30 * fVar21;
    *(float *)(param_3 + 0xc4) = *(float *)(param_3 + 0xc4) + fVar30 * fVar23;
    *(float *)(param_3 + 200) = *(float *)(param_3 + 200) + fVar30 * fVar18;
    *(float *)(param_3 + 0xcc) = *(float *)(param_3 + 0xcc) + fVar30 * fVar19;
    *(float *)(iVar4 + 0x10) = *(float *)(iVar4 + 0x10) - fVar31 * fVar21;
    *(float *)(iVar4 + 0x14) = *(float *)(iVar4 + 0x14) - fVar31 * fVar23;
    *(float *)(iVar4 + 0x18) = *(float *)(iVar4 + 0x18) - fVar31 * fVar18;
    *(float *)(iVar4 + 0x1c) = *(float *)(iVar4 + 0x1c) - fVar31 * fVar19;
    *(float *)(param_3 + 0xd0) = *(float *)(param_3 + 0xd0) + fVar3 * fVar24 * fVar16;
    *(float *)(param_3 + 0xd4) = *(float *)(param_3 + 0xd4) + fVar3 * fVar25 * fVar17;
    *(float *)(param_3 + 0xd8) = *(float *)(param_3 + 0xd8) + fVar3 * fVar27 * fVar20;
    *(float *)(param_3 + 0xdc) = *(float *)(param_3 + 0xdc) + fVar30 * fVar22;
    piVar10 = piVar10 + 0x14;
    iVar11 = iVar11 + -1;
    *(float *)(iVar4 + 0x20) = *(float *)(iVar4 + 0x20) + fVar3 * fVar29 * fVar12;
    *(float *)(iVar4 + 0x24) = *(float *)(iVar4 + 0x24) + fVar3 * fVar26 * fVar13;
    *(float *)(iVar4 + 0x28) = *(float *)(iVar4 + 0x28) + fVar3 * fVar28 * fVar14;
    *(float *)(iVar4 + 0x2c) = *(float *)(iVar4 + 0x2c) + fVar31 * fVar15;
    pfVar6 = pfVar6 + 0x28;
  } while (iVar11 != 0);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
