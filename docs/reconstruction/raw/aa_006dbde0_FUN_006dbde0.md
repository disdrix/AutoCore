# Raw capture: FUN_006dbde0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006dbde0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006dbde0` |
| **Canonical name** | `FUN_006dbde0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_006dbde0(int param_1,int *param_2,int *param_3,int param_4,int *param_5)

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
  uint local_1f4;
  float local_1f0;
  float local_1dc;
  float local_1d8;
  float local_1d4;
  float local_1c0 [7];
  float local_1a4;
  float local_1a0;
  float local_19c;
  float local_198;
  float local_194;
  float local_190 [4];
  float local_180 [6];
  float local_168;
  float local_164;
  float local_160;
  float local_15c;
  float local_158;
  float local_154;
  uint local_150;
  float local_14c;
  float local_148;
  float local_140 [4];
  float local_130 [4];
  float local_120 [4];
  float local_110;
  float local_10c;
  float local_108;
  float local_104;
  float local_100 [5];
  float local_ec;
  float local_e8;
  undefined4 local_e4;
  float local_e0;
  float local_dc;
  float local_d8;
  undefined4 local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_a0 [3];
  float local_94;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  undefined4 local_34;
  
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = "TtCapsuleTriangle";
    uVar5 = rdtsc();
    DAT_00bc5644[1] = (int)uVar5;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  iVar16 = *param_2;
  fVar1 = *(float *)(iVar16 + 0x10);
  iVar19 = param_2[2];
  fVar2 = *(float *)(iVar16 + 0x14);
  fVar3 = *(float *)(iVar16 + 0x18);
  iVar4 = *param_3;
  local_180[0] = fVar1 * *(float *)(iVar19 + 0x20) +
                 fVar2 * *(float *)(iVar19 + 0x30) + fVar3 * *(float *)(iVar19 + 0x40) +
                 *(float *)(iVar19 + 0x50);
  local_180[1] = fVar1 * *(float *)(iVar19 + 0x24) +
                 fVar2 * *(float *)(iVar19 + 0x34) + fVar3 * *(float *)(iVar19 + 0x44) +
                 *(float *)(iVar19 + 0x54);
  local_180[2] = fVar1 * *(float *)(iVar19 + 0x28) +
                 fVar2 * *(float *)(iVar19 + 0x38) + fVar3 * *(float *)(iVar19 + 0x48) +
                 *(float *)(iVar19 + 0x58);
  local_180[3] = 0.0;
  fVar1 = *(float *)(iVar16 + 0x20);
  fVar2 = *(float *)(iVar16 + 0x24);
  fVar3 = *(float *)(iVar16 + 0x28);
  local_180[4] = fVar1 * *(float *)(iVar19 + 0x20) +
                 fVar2 * *(float *)(iVar19 + 0x30) + fVar3 * *(float *)(iVar19 + 0x40) +
                 *(float *)(iVar19 + 0x50);
  local_180[5] = fVar1 * *(float *)(iVar19 + 0x24) +
                 fVar2 * *(float *)(iVar19 + 0x34) + fVar3 * *(float *)(iVar19 + 0x44) +
                 *(float *)(iVar19 + 0x54);
  local_168 = fVar1 * *(float *)(iVar19 + 0x28) +
              fVar2 * *(float *)(iVar19 + 0x38) + fVar3 * *(float *)(iVar19 + 0x48) +
              *(float *)(iVar19 + 0x58);
  iVar19 = param_3[2];
  local_164 = 0.0;
  pfVar13 = (float *)(iVar19 + 0x20);
  fVar1 = *(float *)(iVar4 + 0x10);
  fVar2 = *(float *)(iVar4 + 0x14);
  fVar3 = *(float *)(iVar4 + 0x18);
  local_100[0] = fVar1 * *pfVar13 +
                 fVar2 * *(float *)(iVar19 + 0x30) + fVar3 * *(float *)(iVar19 + 0x40) +
                 *(float *)(iVar19 + 0x50);
  local_100[1] = fVar2 * *(float *)(iVar19 + 0x34) +
                 fVar3 * *(float *)(iVar19 + 0x44) + fVar1 * *(float *)(iVar19 + 0x24) +
                 *(float *)(iVar19 + 0x54);
  local_100[2] = fVar2 * *(float *)(iVar19 + 0x38) +
                 fVar3 * *(float *)(iVar19 + 0x48) + fVar1 * *(float *)(iVar19 + 0x28) +
                 *(float *)(iVar19 + 0x58);
  local_100[3] = 0.0;
  fVar1 = *(float *)(iVar4 + 0x20);
  fVar2 = *(float *)(iVar4 + 0x24);
  fVar3 = *(float *)(iVar4 + 0x28);
  local_100[4] = fVar1 * *pfVar13 +
                 fVar2 * *(float *)(iVar19 + 0x30) + fVar3 * *(float *)(iVar19 + 0x40) +
                 *(float *)(iVar19 + 0x50);
  local_ec = fVar2 * *(float *)(iVar19 + 0x34) +
             fVar3 * *(float *)(iVar19 + 0x44) + fVar1 * *(float *)(iVar19 + 0x24) +
             *(float *)(iVar19 + 0x54);
  local_e8 = fVar2 * *(float *)(iVar19 + 0x38) +
             fVar3 * *(float *)(iVar19 + 0x48) + fVar1 * *(float *)(iVar19 + 0x28) +
             *(float *)(iVar19 + 0x58);
  local_e4 = 0;
  fVar1 = *(float *)(iVar4 + 0x30);
  fVar2 = *(float *)(iVar4 + 0x34);
  fVar3 = *(float *)(iVar4 + 0x38);
  local_e0 = fVar1 * *pfVar13 +
             fVar2 * *(float *)(iVar19 + 0x30) + fVar3 * *(float *)(iVar19 + 0x40) +
             *(float *)(iVar19 + 0x50);
  local_dc = fVar2 * *(float *)(iVar19 + 0x34) +
             fVar3 * *(float *)(iVar19 + 0x44) + fVar1 * *(float *)(iVar19 + 0x24) +
             *(float *)(iVar19 + 0x54);
  local_d8 = fVar2 * *(float *)(iVar19 + 0x38) +
             fVar3 * *(float *)(iVar19 + 0x48) + fVar1 * *(float *)(iVar19 + 0x28) +
             *(float *)(iVar19 + 0x58);
  local_d4 = 0;
  FUN_006f75d0(local_100,param_1 + 0x14,local_140,&local_1a0);
  fVar1 = local_180[0] - local_100[0];
  fVar2 = local_180[1] - local_100[1];
  fVar3 = local_180[2] - local_100[2];
  fVar6 = local_180[4] - local_100[0];
  fVar7 = local_180[5] - local_100[1];
  fVar8 = local_168 - local_100[2];
  local_1c0[0] = local_120[0] * fVar3 + local_140[0] * fVar1 + local_130[0] * fVar2 + local_110;
  local_1c0[1] = fVar1 * local_140[1] + local_120[1] * fVar3 + local_130[1] * fVar2 + local_10c;
  local_1c0[2] = fVar2 * local_130[2] + fVar1 * local_140[2] + fVar3 * local_120[2] + local_108;
  local_1c0[3] = fVar3 * local_120[3] + fVar2 * local_130[3] + fVar1 * local_140[3] + local_104;
  local_1c0[4] = local_130[0] * fVar7 + local_120[0] * fVar8 + local_140[0] * fVar6 + local_110;
  local_1c0[5] = fVar6 * local_140[1] + local_130[1] * fVar7 + local_120[1] * fVar8 + local_10c;
  local_1c0[6] = fVar7 * local_130[2] + fVar6 * local_140[2] + fVar8 * local_120[2] + local_108;
  local_1a4 = fVar8 * local_120[3] + fVar7 * local_130[3] + fVar6 * local_140[3] + local_104;
  fVar1 = *(float *)(iVar16 + 0xc) + *(float *)(iVar4 + 0xc);
  local_94 = 3.4028235e+38;
  local_64 = 3.4028235e+38;
  local_34 = 0x7f7fffff;
  fVar2 = fVar1 + *(float *)(param_4 + 8);
  if (((byte)(((fVar2 < local_1c0[0]) << 3 | (fVar2 < local_1c0[2]) << 1 |
               (fVar2 < local_1c0[1]) << 2 | fVar2 < local_1c0[3]) &
             ((fVar2 < local_1c0[6]) << 1 | (fVar2 < local_1c0[5]) << 2 |
              (fVar2 < local_1c0[4]) << 3 | fVar2 < local_1a4)) == 0) &&
     ((-fVar2 <= local_1c0[3] || (-fVar2 <= local_1a4)))) {
    local_150 = (uint)(local_1c0[2] < g_flZero) << 1 | (uint)(local_1c0[1] < g_flZero) << 2 |
                (uint)(local_1c0[0] < g_flZero) << 3 | (uint)(local_1c0[3] < g_flZero);
    local_14c = (float)((uint)(local_1c0[6] < g_flZero) << 1 | (uint)(local_1c0[5] < g_flZero) << 2
                        | (uint)(local_1c0[4] < g_flZero) << 3 | (uint)(local_1a4 < g_flZero));
    if ((((uint)local_14c ^ local_150) & 1) != 0) {
      fVar2 = local_1c0[3] / (local_1c0[3] - local_1a4);
      fVar3 = g_flOne - fVar2;
      local_190[1] = fVar3 * local_1c0[1] + local_1c0[5] * fVar2;
      local_190[2] = local_1c0[2] * fVar3 + local_1c0[6] * fVar2;
      local_190[3] = local_1c0[3] * fVar3 + local_1a4 * fVar2;
      if ((byte)((local_190[2] < g_flZero) << 1 | (local_190[1] < g_flZero) << 2 |
                (fVar3 * local_1c0[0] + fVar2 * local_1c0[4] < g_flZero) * -8 & 0xeU) == 0xe) {
        local_64 = -3.4028235e+38;
        puVar18 = &local_150;
        iVar16 = 0;
        do {
          if ((((byte)*puVar18 & 0xe) == 0xe) &&
             (fVar2 = -ABS(*(float *)((int)local_1c0 + iVar16 + 0xc)) - fVar1, local_64 < fVar2)) {
            if ((*puVar18 & 1) == 0) {
              local_60 = -local_1a0;
              local_5c = -local_19c;
              local_58 = -local_198;
              local_54 = -local_194;
              local_68 = *(float *)((int)local_180 + iVar16 + 8);
              fVar3 = -*(float *)(iVar4 + 0xc);
            }
            else {
              local_60 = local_1a0;
              local_5c = local_19c;
              local_58 = local_198;
              local_54 = local_194;
              fVar3 = *(float *)(iVar4 + 0xc);
              local_68 = *(float *)((int)local_180 + iVar16 + 8);
            }
            fVar3 = fVar3 - *(float *)((int)local_1c0 + iVar16 + 0xc);
            local_70 = fVar3 * local_1a0 + *(float *)((int)local_180 + iVar16);
            local_6c = fVar3 * local_19c + *(float *)((int)local_180 + iVar16 + 4);
            local_68 = fVar3 * local_198 + local_68;
            local_64 = fVar2;
          }
          iVar16 = iVar16 + 0x10;
          puVar18 = puVar18 + 1;
        } while (iVar16 < 0x20);
        iVar16 = 0;
        local_190[0] = local_1c0[4] - local_1c0[0];
        local_190[1] = local_1c0[5] - local_1c0[1];
        local_190[2] = local_1c0[6] - local_1c0[2];
        local_190[3] = local_1a4 - local_1c0[3];
        do {
          fVar2 = *(float *)((int)local_190 + iVar16);
          fVar3 = g_flOne / (fVar2 * fVar2 + local_190[3] * local_190[3]);
          fVar6 = local_1c0[3] * fVar2 - local_190[3] * *(float *)((int)local_1c0 + iVar16);
          fVar6 = fVar6 * fVar6 * fVar3;
          if (((fVar6 < (fVar1 + local_64) * (fVar1 + local_64)) &&
              (fVar3 = -((local_1c0[3] * local_190[3] + fVar2 * *(float *)((int)local_1c0 + iVar16))
                        * fVar3), DAT_00aaa6b4 < fVar3)) && (fVar3 < _DAT_00aaac14)) {
            local_1f0 = local_190[3];
            if (local_190[3] < g_flZero) {
              local_1f0 = -local_190[3];
              fVar2 = -fVar2;
            }
            fVar2 = -fVar2;
            fVar8 = fVar2 * local_1a0 + *(float *)((int)local_140 + iVar16) * local_1f0;
            fVar9 = fVar2 * local_19c + local_1f0 * *(float *)((int)local_130 + iVar16);
            fVar7 = fVar2 * local_198 + local_1f0 * *(float *)((int)local_120 + iVar16);
            fVar11 = fVar8 * fVar8 + fVar9 * fVar9 + fVar7 * fVar7;
            fVar10 = g_flZero;
            if (fVar11 != g_flZero) {
              fVar10 = g_flOne / SQRT(fVar11);
            }
            local_60 = fVar8 * fVar10;
            local_5c = fVar10 * fVar9;
            local_58 = fVar7 * fVar10;
            local_54 = fVar10 * (fVar2 * local_194 + local_1f0 * g_flZero);
            fVar11 = g_flOne - fVar3;
            local_14c = fVar3 * local_180[5] + local_180[1] * fVar11;
            local_148 = local_168 * fVar3 + local_180[2] * fVar11;
            fVar2 = -SQRT(fVar6);
            fVar6 = *(float *)(iVar4 + 0xc) - fVar2;
            local_70 = fVar6 * fVar8 * fVar10 + fVar3 * local_180[4] + local_180[0] * fVar11;
            local_6c = fVar6 * fVar10 * fVar9 + local_14c;
            local_68 = fVar6 * fVar7 * fVar10 + local_148;
            local_64 = fVar2 - fVar1;
          }
          iVar16 = iVar16 + 4;
        } while (iVar16 < 0xc);
        goto LAB_006dc9a9;
      }
    }
    iVar16 = 0;
    local_160 = local_180[4] - local_180[0];
    pfVar13 = local_a0;
    bVar12 = false;
    local_15c = local_180[5] - local_180[1];
    local_158 = local_168 - local_180[2];
    local_154 = local_164 - local_180[3];
    if (((SUB41(local_14c,0) | (byte)local_150) & 0xe) == 0xe) goto LAB_006dcaac;
    bVar12 = true;
    do {
      local_1f4 = 8;
      iVar19 = 0;
      do {
        if (bVar12) {
          uVar15 = local_150 & local_1f4 & (uint)local_14c;
        }
        else {
          uVar15 = (&local_150)[iVar16] & local_1f4;
        }
        if (uVar15 == 0) {
          iVar17 = (int)(char)(&DAT_00a0eefc)[iVar19];
          iVar14 = (int)(char)(&DAT_00a0eefe)[iVar19];
          local_190[0] = local_100[iVar17 * 4] - local_100[iVar14 * 4];
          local_190[1] = local_100[iVar17 * 4 + 1] - local_100[iVar14 * 4 + 1];
          local_190[2] = local_100[iVar17 * 4 + 2] - local_100[iVar14 * 4 + 2];
          local_190[3] = local_100[iVar17 * 4 + 3] - local_100[iVar14 * 4 + 3];
          uVar15 = FUN_006f6ef0(local_180,&local_160,local_100 + iVar14 * 4,local_190,&local_d0);
          if (local_b0 < (fVar1 + pfVar13[3]) * (fVar1 + pfVar13[3])) {
            if ((uVar15 & 1 << ((byte)iVar16 & 0x1f)) != 0) {
              if (!bVar12) goto LAB_006dcf38;
              iVar16 = 1;
            }
            if (uVar15 == 0) {
              local_1dc = local_190[0] * local_158 - local_160 * local_190[2];
              local_1d8 = local_160 * local_190[1] - local_190[0] * local_15c;
              local_1d4 = 0.0;
              fVar2 = local_190[2] * local_15c - local_190[1] * local_158;
            }
            else {
              if (local_b0 < _DAT_00a0e520 != (local_b0 == _DAT_00a0e520)) {
                local_b4 = 0.0;
                local_c0 = local_140[iVar19];
                local_1d4 = 0.0;
                local_bc = local_130[iVar19];
                local_b8 = local_120[iVar19];
                fVar2 = local_190[2] * local_15c - local_190[1] * local_158;
                local_1dc = local_190[0] * local_158 - local_160 * local_190[2];
                local_1d8 = local_160 * local_190[1] - local_190[0] * local_15c;
                fVar3 = local_1dc * local_1dc + local_1d8 * local_1d8 + fVar2 * fVar2;
                if (fVar3 < _DAT_00a0e520 == (fVar3 == _DAT_00a0e520)) goto LAB_006dce24;
              }
              local_1dc = local_bc;
              local_1d8 = local_b8;
              local_1d4 = local_b4;
              fVar2 = local_c0;
            }
LAB_006dce24:
            fVar3 = local_1dc * local_1dc + local_1d8 * local_1d8 + fVar2 * fVar2;
            if (fVar3 == g_flZero) {
              local_1f0 = 0.0;
            }
            else {
              local_1f0 = g_flOne / SQRT(fVar3);
            }
            fVar2 = fVar2 * local_1f0;
            local_1dc = local_1f0 * local_1dc;
            local_1d8 = local_1f0 * local_1d8;
            local_1d4 = local_1f0 * local_1d4;
            fVar3 = local_bc * local_1dc + local_b8 * local_1d8 + local_c0 * fVar2;
            if (fVar3 < g_flZero) {
              fVar3 = -fVar3;
              fVar2 = -fVar2;
              local_1dc = -local_1dc;
              local_1d8 = -local_1d8;
              local_1d4 = -local_1d4;
            }
            fVar6 = *(float *)(iVar4 + 0xc) - fVar3;
            *pfVar13 = fVar6 * fVar2 + local_d0;
            pfVar13[1] = fVar6 * local_1dc + local_cc;
            pfVar13[2] = local_1d8 * fVar6 + local_c8;
            pfVar13[3] = fVar6 * local_1d4 + local_c4;
            pfVar13[3] = fVar3 - fVar1;
            pfVar13[6] = local_1d8;
            pfVar13[7] = local_1d4;
            pfVar13[4] = fVar2;
            pfVar13[5] = local_1dc;
          }
        }
LAB_006dcf38:
        local_1f4 = (int)local_1f4 >> 1;
        iVar19 = iVar19 + 1;
      } while (iVar19 < 3);
      if (bVar12) break;
      iVar16 = iVar16 + 1;
      pfVar13 = pfVar13 + 0xc;
LAB_006dcaac:
      while( true ) {
        if (1 < iVar16) goto LAB_006dc9a9;
        if (((byte)(&local_150)[iVar16] & 0xe) != 0xe) break;
        if (((&local_150)[iVar16] & 1) == 0) {
          fVar2 = *(float *)(iVar4 + 0xc) - local_1c0[iVar16 * 4 + 3];
          *pfVar13 = local_1a0 * fVar2 + local_180[iVar16 * 4];
          pfVar13[1] = local_19c * fVar2 + local_180[iVar16 * 4 + 1];
          pfVar13[2] = local_198 * fVar2 + local_180[iVar16 * 4 + 2];
          pfVar13[3] = fVar2 * local_194 + local_180[iVar16 * 4 + 3];
          pfVar13[3] = local_1c0[iVar16 * 4 + 3] - fVar1;
          pfVar13[4] = local_1a0;
          pfVar13[5] = local_19c;
          pfVar13[6] = local_198;
          pfVar13[7] = local_194;
          iVar16 = iVar16 + 1;
          pfVar13 = pfVar13 + 0xc;
        }
        else {
          fVar2 = -*(float *)(iVar4 + 0xc) - local_1c0[iVar16 * 4 + 3];
          *pfVar13 = local_1a0 * fVar2 + local_180[iVar16 * 4];
          pfVar13[1] = local_19c * fVar2 + local_180[iVar16 * 4 + 1];
          pfVar13[2] = local_198 * fVar2 + local_180[iVar16 * 4 + 2];
          pfVar13[3] = fVar2 * local_194 + local_180[iVar16 * 4 + 3];
          pfVar13[3] = -local_1c0[iVar16 * 4 + 3] - fVar1;
          pfVar13[4] = -local_1a0;
          pfVar13[5] = -local_19c;
          pfVar13[6] = -local_198;
          pfVar13[7] = -local_194;
          iVar16 = iVar16 + 1;
          pfVar13 = pfVar13 + 0xc;
        }
      }
    } while( true );
  }
LAB_006dc9a9:
  if ((local_94 < g_flZero) || (local_64 < g_flZero)) {
    (**(code **)(*param_5 + 4))(param_2,param_3);
  }
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = &DAT_009d2878;
    uVar5 = rdtsc();
    DAT_00bc5644[1] = (int)uVar5;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  return;
}
```
