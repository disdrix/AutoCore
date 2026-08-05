# Annotated low-level: FUN_006daba0

| Field | Value |
|---|---|
| Stable ID | `aa_006daba0` |
| VA | `0x006daba0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006daba0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006daba0(int *param_1,int *param_2,int param_3,int *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  undefined8 uVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  bool bVar12;
  float *pfVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  uint *puVar18;
  int iVar19;
  uint local_241;
  float local_23c;
  float local_22c;
  float local_228;
  float local_224;
  float local_210 [7];
  float local_1f4;
  float local_1f0;
  float local_1ec;
  float local_1e8;
  float local_1e4;
  float local_1e0 [4];
  float local_1d0 [6];
  float local_1b8;
  float local_1b4;
  float local_1b0;
  float local_1ac;
  float local_1a8;
  float local_1a4;
  uint local_1a0;
  float local_19c;
  float local_198;
  float local_190 [4];
  float local_180 [4];
  float local_170 [4];
  float local_160;
  float local_15c;
  float local_158;
  float local_154;
  float local_150;
  float local_14c;
  float local_148;
  float local_144;
  float local_140;
  float local_13c;
  float local_138;
  float local_134;
  int *local_130;
  int *local_12c;
  float local_120;
  float local_11c;
  float local_118;
  float local_114;
  float local_110;
  float local_10c;
  float local_108;
  float local_104;
  float local_f0;
  float local_ec;
  float local_e8;
  float local_e4;
  float local_e0;
  float local_dc;
  float local_d8;
  float local_d4;
  undefined4 local_b4;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_60 [5];
  float local_4c;
  float local_48;
  undefined4 local_44;
  float local_40;
  float local_3c;
  float local_38;
  undefined4 local_34;
  undefined1 local_24 [32];
  
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = "TtCapsuleTriangle";
    uVar5 = rdtsc();
    DAT_00bc5644[1] = (int)uVar5;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  FUN_006f7450(*param_2 + 0x10,local_24);
  iVar16 = *param_1;
  local_130 = param_1;
  iVar19 = param_1[2];
  local_12c = param_2;
  fVar1 = *(float *)(iVar16 + 0x10);
  fVar2 = *(float *)(iVar16 + 0x14);
  fVar3 = *(float *)(iVar16 + 0x18);
  iVar4 = *param_2;
  local_1d0[0] = fVar2 * *(float *)(iVar19 + 0x30) +
                 fVar3 * *(float *)(iVar19 + 0x40) + fVar1 * *(float *)(iVar19 + 0x20) +
                 *(float *)(iVar19 + 0x50);
  local_1d0[1] = fVar2 * *(float *)(iVar19 + 0x34) +
                 fVar3 * *(float *)(iVar19 + 0x44) + fVar1 * *(float *)(iVar19 + 0x24) +
                 *(float *)(iVar19 + 0x54);
  local_1d0[2] = fVar2 * *(float *)(iVar19 + 0x38) +
                 fVar3 * *(float *)(iVar19 + 0x48) + fVar1 * *(float *)(iVar19 + 0x28) +
                 *(float *)(iVar19 + 0x58);
  local_1d0[3] = 0.0;
  fVar1 = *(float *)(iVar16 + 0x20);
  fVar2 = *(float *)(iVar16 + 0x24);
  fVar3 = *(float *)(iVar16 + 0x28);
  local_1d0[4] = fVar2 * *(float *)(iVar19 + 0x30) +
                 fVar3 * *(float *)(iVar19 + 0x40) + fVar1 * *(float *)(iVar19 + 0x20) +
                 *(float *)(iVar19 + 0x50);
  local_1d0[5] = fVar2 * *(float *)(iVar19 + 0x34) +
                 fVar3 * *(float *)(iVar19 + 0x44) + fVar1 * *(float *)(iVar19 + 0x24) +
                 *(float *)(iVar19 + 0x54);
  local_1b8 = fVar2 * *(float *)(iVar19 + 0x38) +
              fVar3 * *(float *)(iVar19 + 0x48) + fVar1 * *(float *)(iVar19 + 0x28) +
              *(float *)(iVar19 + 0x58);
  local_1b4 = 0.0;
  fVar1 = *(float *)(iVar4 + 0x10);
  iVar19 = param_2[2];
  fVar2 = *(float *)(iVar4 + 0x14);
  pfVar13 = (float *)(iVar19 + 0x20);
  fVar3 = *(float *)(iVar4 + 0x18);
  local_60[0] = fVar1 * *pfVar13 +
                fVar2 * *(float *)(iVar19 + 0x30) + fVar3 * *(float *)(iVar19 + 0x40) +
                *(float *)(iVar19 + 0x50);
  local_60[1] = fVar1 * *(float *)(iVar19 + 0x24) +
                fVar2 * *(float *)(iVar19 + 0x34) + fVar3 * *(float *)(iVar19 + 0x44) +
                *(float *)(iVar19 + 0x54);
  local_60[2] = fVar1 * *(float *)(iVar19 + 0x28) +
                fVar2 * *(float *)(iVar19 + 0x38) + fVar3 * *(float *)(iVar19 + 0x48) +
                *(float *)(iVar19 + 0x58);
  local_60[3] = 0.0;
  fVar1 = *(float *)(iVar4 + 0x20);
  fVar2 = *(float *)(iVar4 + 0x24);
  fVar3 = *(float *)(iVar4 + 0x28);
  local_60[4] = fVar1 * *pfVar13 +
                fVar2 * *(float *)(iVar19 + 0x30) + fVar3 * *(float *)(iVar19 + 0x40) +
                *(float *)(iVar19 + 0x50);
  local_4c = fVar1 * *(float *)(iVar19 + 0x24) +
             fVar2 * *(float *)(iVar19 + 0x34) + fVar3 * *(float *)(iVar19 + 0x44) +
             *(float *)(iVar19 + 0x54);
  local_48 = fVar1 * *(float *)(iVar19 + 0x28) +
             fVar2 * *(float *)(iVar19 + 0x38) + fVar3 * *(float *)(iVar19 + 0x48) +
             *(float *)(iVar19 + 0x58);
  local_44 = 0;
  fVar1 = *(float *)(iVar4 + 0x30);
  fVar2 = *(float *)(iVar4 + 0x34);
  fVar3 = *(float *)(iVar4 + 0x38);
  local_40 = fVar1 * *pfVar13 +
             fVar2 * *(float *)(iVar19 + 0x30) + fVar3 * *(float *)(iVar19 + 0x40) +
             *(float *)(iVar19 + 0x50);
  local_3c = fVar1 * *(float *)(iVar19 + 0x24) +
             fVar2 * *(float *)(iVar19 + 0x34) + fVar3 * *(float *)(iVar19 + 0x44) +
             *(float *)(iVar19 + 0x54);
  local_38 = fVar1 * *(float *)(iVar19 + 0x28) +
             fVar2 * *(float *)(iVar19 + 0x38) + fVar3 * *(float *)(iVar19 + 0x48) +
             *(float *)(iVar19 + 0x58);
  local_34 = 0;
  FUN_006f75d0(local_60,local_24,local_190,&local_1f0);
  fVar1 = local_1d0[0] - local_60[0];
  fVar2 = local_1d0[1] - local_60[1];
  fVar3 = local_1d0[2] - local_60[2];
  fVar6 = local_1d0[4] - local_60[0];
  fVar7 = local_1d0[5] - local_60[1];
  fVar8 = local_1b8 - local_60[2];
  local_210[0] = fVar1 * local_190[0] + fVar2 * local_180[0] + fVar3 * local_170[0] + local_160;
  local_210[1] = fVar1 * local_190[1] + fVar2 * local_180[1] + fVar3 * local_170[1] + local_15c;
  local_210[2] = fVar2 * local_180[2] + fVar1 * local_190[2] + fVar3 * local_170[2] + local_158;
  local_210[3] = fVar3 * local_170[3] + fVar2 * local_180[3] + fVar1 * local_190[3] + local_154;
  local_210[4] = local_170[0] * fVar8 + fVar6 * local_190[0] + fVar7 * local_180[0] + local_160;
  local_210[5] = local_170[1] * fVar8 + fVar6 * local_190[1] + fVar7 * local_180[1] + local_15c;
  local_210[6] = local_170[2] * fVar8 + fVar7 * local_180[2] + fVar6 * local_190[2] + local_158;
  local_1f4 = fVar8 * local_170[3] + fVar7 * local_180[3] + fVar6 * local_190[3] + local_154;
  fVar1 = *(float *)(iVar16 + 0xc) + *(float *)(iVar4 + 0xc);
  local_114 = 3.4028235e+38;
  local_e4 = 3.4028235e+38;
  local_b4 = 0x7f7fffff;
  fVar2 = fVar1 + *(float *)(param_3 + 8);
  if (((byte)(((fVar2 < local_210[0]) << 3 | (fVar2 < local_210[2]) << 1 |
               (fVar2 < local_210[1]) << 2 | fVar2 < local_210[3]) &
             ((fVar2 < local_210[6]) << 1 | (fVar2 < local_210[5]) << 2 |
              (fVar2 < local_210[4]) << 3 | fVar2 < local_1f4)) != 0) ||
     ((local_210[3] < -fVar2 && (local_1f4 < -fVar2)))) {
LAB_006dbd17:
    if (*(float *)(param_3 + 8) <= local_e4) goto LAB_006dbdaf;
    local_150 = local_f0;
    local_14c = local_ec;
    local_148 = local_e8;
    local_144 = local_e4;
    local_140 = local_e0;
    local_10c = local_dc;
    local_108 = local_d8;
    local_104 = local_d4;
  }
  else {
    local_1a0 = (uint)(local_210[2] < g_flZero) << 1 | (uint)(local_210[1] < g_flZero) << 2 |
                (uint)(local_210[0] < g_flZero) << 3 | (uint)(local_210[3] < g_flZero);
    local_241 = (uint)(local_210[4] < g_flZero);
    local_19c = (float)((uint)(local_210[6] < g_flZero) << 1 | (uint)(local_210[5] < g_flZero) << 2
                        | local_241 << 3 | (uint)(local_1f4 < g_flZero));
    if ((((uint)local_19c ^ local_1a0) & 1) == 0) {
LAB_006db7e6:
      iVar16 = 0;
      local_1b0 = local_1d0[4] - local_1d0[0];
      pfVar13 = &local_120;
      bVar12 = false;
      local_1ac = local_1d0[5] - local_1d0[1];
      local_1a8 = local_1b8 - local_1d0[2];
      local_1a4 = local_1b4 - local_1d0[3];
      if (((SUB41(local_19c,0) | (byte)local_1a0) & 0xe) == 0xe) goto LAB_006db88c;
      bVar12 = true;
      do {
        local_241._1_3_ = 8;
        iVar19 = 0;
        do {
          if (bVar12) {
            uVar15 = local_1a0 & (uint)local_241._1_3_ & (uint)local_19c;
          }
          else {
            uVar15 = (&local_1a0)[iVar16] & (uint)local_241._1_3_;
          }
          if (uVar15 == 0) {
            iVar17 = (int)(char)(&DAT_00a0eefc)[iVar19];
            iVar14 = (int)(char)(&DAT_00a0eefe)[iVar19];
            local_1e0[0] = local_60[iVar17 * 4] - local_60[iVar14 * 4];
            local_1e0[1] = local_60[iVar17 * 4 + 1] - local_60[iVar14 * 4 + 1];
            local_1e0[2] = local_60[iVar17 * 4 + 2] - local_60[iVar14 * 4 + 2];
            local_1e0[3] = local_60[iVar17 * 4 + 3] - local_60[iVar14 * 4 + 3];
            uVar15 = FUN_006f6ef0(local_1d0,&local_1b0,local_60 + iVar14 * 4,local_1e0,&local_90);
            if (local_70 < (fVar1 + pfVar13[3]) * (fVar1 + pfVar13[3])) {
              if ((uVar15 & 1 << ((byte)iVar16 & 0x1f)) != 0) {
                if (!bVar12) goto LAB_006dbcec;
                iVar16 = 1;
              }
              if (uVar15 == 0) {
                local_22c = local_1e0[0] * local_1a8 - local_1b0 * local_1e0[2];
                local_228 = local_1b0 * local_1e0[1] - local_1e0[0] * local_1ac;
                local_224 = 0.0;
                fVar2 = local_1e0[2] * local_1ac - local_1e0[1] * local_1a8;
              }
              else {
                if (local_70 < _DAT_00a0e520 != (local_70 == _DAT_00a0e520)) {
                  local_74 = 0.0;
                  local_80 = local_190[iVar19];
                  local_224 = 0.0;
                  local_7c = local_180[iVar19];
                  local_78 = local_170[iVar19];
                  fVar2 = local_1e0[2] * local_1ac - local_1e0[1] * local_1a8;
                  local_22c = local_1e0[0] * local_1a8 - local_1b0 * local_1e0[2];
                  local_228 = local_1b0 * local_1e0[1] - local_1e0[0] * local_1ac;
                  fVar3 = local_22c * local_22c + local_228 * local_228 + fVar2 * fVar2;
                  if (fVar3 < _DAT_00a0e520 == (fVar3 == _DAT_00a0e520)) goto LAB_006dbbd8;
                }
                local_22c = local_7c;
                local_228 = local_78;
                local_224 = local_74;
                fVar2 = local_80;
              }
LAB_006dbbd8:
              fVar3 = local_22c * local_22c + local_228 * local_228 + fVar2 * fVar2;
              if (fVar3 == g_flZero) {
                local_23c = 0.0;
              }
              else {
                local_23c = g_flOne / SQRT(fVar3);
              }
              fVar2 = fVar2 * local_23c;
              local_22c = local_23c * local_22c;
              local_228 = local_23c * local_228;
              local_224 = local_23c * local_224;
              fVar3 = local_7c * local_22c + local_78 * local_228 + local_80 * fVar2;
              if (fVar3 < g_flZero) {
                fVar3 = -fVar3;
                fVar2 = -fVar2;
                local_22c = -local_22c;
                local_228 = -local_228;
                local_224 = -local_224;
              }
              fVar6 = *(float *)(iVar4 + 0xc) - fVar3;
              *pfVar13 = fVar6 * fVar2 + local_90;
              pfVar13[1] = fVar6 * local_22c + local_8c;
              pfVar13[2] = local_228 * fVar6 + local_88;
              pfVar13[3] = fVar6 * local_224 + local_84;
              pfVar13[3] = fVar3 - fVar1;
              pfVar13[6] = local_228;
              pfVar13[7] = local_224;
              pfVar13[4] = fVar2;
              pfVar13[5] = local_22c;
            }
          }
LAB_006dbcec:
          iVar19 = iVar19 + 1;
          local_241._1_3_ = (uint3)((int)(uint)local_241._1_3_ >> 1);
        } while (iVar19 < 3);
        if (bVar12) goto LAB_006db755;
        iVar16 = iVar16 + 1;
        pfVar13 = pfVar13 + 0xc;
LAB_006db88c:
        while( true ) {
          if (1 < iVar16) goto LAB_006db755;
          if (((byte)(&local_1a0)[iVar16] & 0xe) != 0xe) break;
          if (((&local_1a0)[iVar16] & 1) == 0) {
            fVar2 = *(float *)(iVar4 + 0xc) - local_210[iVar16 * 4 + 3];
            *pfVar13 = local_1f0 * fVar2 + local_1d0[iVar16 * 4];
            pfVar13[1] = local_1ec * fVar2 + local_1d0[iVar16 * 4 + 1];
            pfVar13[2] = local_1e8 * fVar2 + local_1d0[iVar16 * 4 + 2];
            pfVar13[3] = fVar2 * local_1e4 + local_1d0[iVar16 * 4 + 3];
            pfVar13[3] = local_210[iVar16 * 4 + 3] - fVar1;
            pfVar13[4] = local_1f0;
            pfVar13[5] = local_1ec;
            pfVar13[6] = local_1e8;
            pfVar13[7] = local_1e4;
            iVar16 = iVar16 + 1;
            pfVar13 = pfVar13 + 0xc;
          }
          else {
            fVar2 = -*(float *)(iVar4 + 0xc) - local_210[iVar16 * 4 + 3];
            *pfVar13 = local_1f0 * fVar2 + local_1d0[iVar16 * 4];
            pfVar13[1] = local_1ec * fVar2 + local_1d0[iVar16 * 4 + 1];
            pfVar13[2] = local_1e8 * fVar2 + local_1d0[iVar16 * 4 + 2];
            pfVar13[3] = fVar2 * local_1e4 + local_1d0[iVar16 * 4 + 3];
            pfVar13[3] = -local_210[iVar16 * 4 + 3] - fVar1;
            pfVar13[4] = -local_1f0;
            pfVar13[5] = -local_1ec;
            pfVar13[6] = -local_1e8;
            pfVar13[7] = -local_1e4;
            iVar16 = iVar16 + 1;
            pfVar13 = pfVar13 + 0xc;
          }
        }
      } while( true );
    }
    fVar2 = local_210[3] / (local_210[3] - local_1f4);
    fVar3 = g_flOne - fVar2;
    local_1e0[1] = local_210[1] * fVar3 + local_210[5] * fVar2;
    local_1e0[2] = fVar2 * local_210[6] + local_210[2] * fVar3;
    local_1e0[3] = fVar2 * local_1f4 + local_210[3] * fVar3;
    if ((byte)((local_1e0[2] < g_flZero) << 1 | (local_1e0[1] < g_flZero) << 2 |
              (fVar3 * local_210[0] + fVar2 * local_210[4] < g_flZero) * -8 & 0xeU) != 0xe)
    goto LAB_006db7e6;
    local_e4 = -3.4028235e+38;
    puVar18 = &local_1a0;
    iVar16 = 0;
    do {
      if ((((byte)*puVar18 & 0xe) == 0xe) &&
         (fVar2 = -ABS(*(float *)((int)local_210 + iVar16 + 0xc)) - fVar1, local_e4 < fVar2)) {
        if ((*puVar18 & 1) == 0) {
          local_e0 = -local_1f0;
          local_dc = -local_1ec;
          local_d8 = -local_1e8;
          local_d4 = -local_1e4;
          local_e8 = *(float *)((int)local_1d0 + iVar16 + 8);
          fVar3 = -*(float *)(iVar4 + 0xc);
        }
        else {
          local_e0 = local_1f0;
          local_dc = local_1ec;
          local_d8 = local_1e8;
          local_d4 = local_1e4;
          fVar3 = *(float *)(iVar4 + 0xc);
          local_e8 = *(float *)((int)local_1d0 + iVar16 + 8);
        }
        fVar3 = fVar3 - *(float *)((int)local_210 + iVar16 + 0xc);
        local_f0 = fVar3 * local_1f0 + *(float *)((int)local_1d0 + iVar16);
        local_ec = fVar3 * local_1ec + *(float *)((int)local_1d0 + iVar16 + 4);
        local_e8 = fVar3 * local_1e8 + local_e8;
        local_e4 = fVar2;
      }
      iVar16 = iVar16 + 0x10;
      puVar18 = puVar18 + 1;
    } while (iVar16 < 0x20);
    iVar16 = 0;
    local_1e0[0] = local_210[4] - local_210[0];
    local_1e0[1] = local_210[5] - local_210[1];
    local_1e0[2] = local_210[6] - local_210[2];
    local_1e0[3] = local_1f4 - local_210[3];
    do {
      fVar2 = *(float *)((int)local_1e0 + iVar16);
      fVar3 = g_flOne / (fVar2 * fVar2 + local_1e0[3] * local_1e0[3]);
      fVar6 = local_210[3] * fVar2 - local_1e0[3] * *(float *)((int)local_210 + iVar16);
      fVar6 = fVar6 * fVar6 * fVar3;
      if (((fVar6 < (fVar1 + local_e4) * (fVar1 + local_e4)) &&
          (fVar3 = -((local_210[3] * local_1e0[3] + fVar2 * *(float *)((int)local_210 + iVar16)) *
                    fVar3), DAT_00aaa6b4 < fVar3)) && (fVar3 < _DAT_00aaac14)) {
        local_23c = local_1e0[3];
        if (local_1e0[3] < g_flZero) {
          local_23c = -local_1e0[3];
          fVar2 = -fVar2;
        }
        fVar2 = -fVar2;
        fVar8 = fVar2 * local_1f0 + *(float *)((int)local_190 + iVar16) * local_23c;
        fVar9 = fVar2 * local_1ec + local_23c * *(float *)((int)local_180 + iVar16);
        fVar7 = fVar2 * local_1e8 + local_23c * *(float *)((int)local_170 + iVar16);
        fVar11 = fVar8 * fVar8 + fVar9 * fVar9 + fVar7 * fVar7;
        fVar10 = g_flZero;
        if (fVar11 != g_flZero) {
          fVar10 = g_flOne / SQRT(fVar11);
        }
        local_e0 = fVar8 * fVar10;
        local_dc = fVar9 * fVar10;
        local_d8 = fVar7 * fVar10;
        local_d4 = (fVar2 * local_1e4 + local_23c * g_flZero) * fVar10;
        fVar11 = g_flOne - fVar3;
        local_19c = fVar3 * local_1d0[5] + local_1d0[1] * fVar11;
        local_198 = fVar3 * local_1b8 + local_1d0[2] * fVar11;
        fVar2 = -SQRT(fVar6);
        fVar6 = *(float *)(iVar4 + 0xc) - fVar2;
        local_f0 = fVar6 * fVar8 * fVar10 + fVar3 * local_1d0[4] + local_1d0[0] * fVar11;
        local_ec = fVar6 * fVar9 * fVar10 + local_19c;
        local_e8 = fVar6 * fVar7 * fVar10 + local_198;
        local_e4 = fVar2 - fVar1;
      }
      iVar16 = iVar16 + 4;
    } while (iVar16 < 0xc);
LAB_006db755:
    if (local_e4 <= local_114) goto LAB_006dbd17;
    if (*(float *)(param_3 + 8) <= local_114) goto LAB_006dbdaf;
    local_150 = local_120;
    local_14c = local_11c;
    local_148 = local_118;
    local_144 = local_114;
    local_140 = local_110;
  }
  local_13c = local_10c;
  local_138 = local_108;
  local_134 = local_104;
  (**(code **)(*param_4 + 4))(&local_150);
LAB_006dbdaf:
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = &DAT_009d2878;
    uVar5 = rdtsc();
    DAT_00bc5644[1] = (int)uVar5;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
