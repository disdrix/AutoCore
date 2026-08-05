# Raw capture: FUN_006dcf70

| Field | Value |
|---|---|
| **Stable ID** | `aa_006dcf70` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006dcf70` |
| **Canonical name** | `FUN_006dcf70` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006dcf70(int *param_1,int *param_2,int param_3,int *param_4)

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
  uint local_214;
  float local_210;
  float local_1fc;
  float local_1f8;
  float local_1f4;
  float local_1e0 [7];
  float local_1c4;
  float local_1c0;
  float local_1bc;
  float local_1b8;
  float local_1b4;
  float local_1b0 [4];
  float local_1a0 [6];
  float local_188;
  float local_184;
  float local_180;
  float local_17c;
  float local_178;
  float local_174;
  uint local_170;
  float local_16c;
  float local_168;
  float local_160 [4];
  float local_150 [4];
  float local_140 [4];
  float local_130;
  float local_12c;
  float local_128;
  float local_124;
  float local_120 [5];
  float local_10c;
  float local_108;
  undefined4 local_104;
  float local_100;
  float local_fc;
  float local_f8;
  undefined4 local_f4;
  float local_f0;
  float local_ec;
  float local_e8;
  float local_e4;
  float local_e0;
  float local_dc;
  float local_d8;
  float local_d4;
  float local_d0;
  float local_c0 [3];
  float local_b4;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  undefined4 local_54;
  undefined1 local_24 [32];
  
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = "TtCapsuleTriangle";
    uVar5 = rdtsc();
    DAT_00bc5644[1] = (int)uVar5;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  FUN_006f7450(*param_2 + 0x10,local_24);
  iVar16 = *param_1;
  fVar1 = *(float *)(iVar16 + 0x10);
  iVar19 = param_1[2];
  fVar2 = *(float *)(iVar16 + 0x14);
  fVar3 = *(float *)(iVar16 + 0x18);
  iVar4 = *param_2;
  local_1a0[0] = fVar1 * *(float *)(iVar19 + 0x20) +
                 fVar2 * *(float *)(iVar19 + 0x30) + fVar3 * *(float *)(iVar19 + 0x40) +
                 *(float *)(iVar19 + 0x50);
  local_1a0[1] = fVar2 * *(float *)(iVar19 + 0x34) +
                 fVar3 * *(float *)(iVar19 + 0x44) + fVar1 * *(float *)(iVar19 + 0x24) +
                 *(float *)(iVar19 + 0x54);
  local_1a0[2] = fVar2 * *(float *)(iVar19 + 0x38) +
                 fVar3 * *(float *)(iVar19 + 0x48) + fVar1 * *(float *)(iVar19 + 0x28) +
                 *(float *)(iVar19 + 0x58);
  local_1a0[3] = 0.0;
  fVar1 = *(float *)(iVar16 + 0x20);
  fVar2 = *(float *)(iVar16 + 0x24);
  fVar3 = *(float *)(iVar16 + 0x28);
  local_1a0[4] = fVar1 * *(float *)(iVar19 + 0x20) +
                 fVar2 * *(float *)(iVar19 + 0x30) + fVar3 * *(float *)(iVar19 + 0x40) +
                 *(float *)(iVar19 + 0x50);
  local_1a0[5] = fVar2 * *(float *)(iVar19 + 0x34) +
                 fVar3 * *(float *)(iVar19 + 0x44) + fVar1 * *(float *)(iVar19 + 0x24) +
                 *(float *)(iVar19 + 0x54);
  local_188 = fVar2 * *(float *)(iVar19 + 0x38) +
              fVar3 * *(float *)(iVar19 + 0x48) + fVar1 * *(float *)(iVar19 + 0x28) +
              *(float *)(iVar19 + 0x58);
  iVar19 = param_2[2];
  local_184 = 0.0;
  pfVar13 = (float *)(iVar19 + 0x20);
  fVar1 = *(float *)(iVar4 + 0x10);
  fVar2 = *(float *)(iVar4 + 0x14);
  fVar3 = *(float *)(iVar4 + 0x18);
  local_120[0] = fVar1 * *pfVar13 +
                 fVar2 * *(float *)(iVar19 + 0x30) + fVar3 * *(float *)(iVar19 + 0x40) +
                 *(float *)(iVar19 + 0x50);
  local_120[1] = fVar1 * *(float *)(iVar19 + 0x24) +
                 fVar2 * *(float *)(iVar19 + 0x34) + fVar3 * *(float *)(iVar19 + 0x44) +
                 *(float *)(iVar19 + 0x54);
  local_120[2] = fVar1 * *(float *)(iVar19 + 0x28) +
                 fVar2 * *(float *)(iVar19 + 0x38) + fVar3 * *(float *)(iVar19 + 0x48) +
                 *(float *)(iVar19 + 0x58);
  local_120[3] = 0.0;
  fVar1 = *(float *)(iVar4 + 0x20);
  fVar2 = *(float *)(iVar4 + 0x24);
  fVar3 = *(float *)(iVar4 + 0x28);
  local_120[4] = fVar1 * *pfVar13 +
                 fVar2 * *(float *)(iVar19 + 0x30) + fVar3 * *(float *)(iVar19 + 0x40) +
                 *(float *)(iVar19 + 0x50);
  local_10c = fVar1 * *(float *)(iVar19 + 0x24) +
              fVar2 * *(float *)(iVar19 + 0x34) + fVar3 * *(float *)(iVar19 + 0x44) +
              *(float *)(iVar19 + 0x54);
  local_108 = fVar1 * *(float *)(iVar19 + 0x28) +
              fVar2 * *(float *)(iVar19 + 0x38) + fVar3 * *(float *)(iVar19 + 0x48) +
              *(float *)(iVar19 + 0x58);
  local_104 = 0;
  fVar1 = *(float *)(iVar4 + 0x30);
  fVar2 = *(float *)(iVar4 + 0x34);
  fVar3 = *(float *)(iVar4 + 0x38);
  local_100 = fVar1 * *pfVar13 +
              fVar2 * *(float *)(iVar19 + 0x30) + fVar3 * *(float *)(iVar19 + 0x40) +
              *(float *)(iVar19 + 0x50);
  local_fc = fVar1 * *(float *)(iVar19 + 0x24) +
             fVar2 * *(float *)(iVar19 + 0x34) + fVar3 * *(float *)(iVar19 + 0x44) +
             *(float *)(iVar19 + 0x54);
  local_f8 = fVar1 * *(float *)(iVar19 + 0x28) +
             fVar2 * *(float *)(iVar19 + 0x38) + fVar3 * *(float *)(iVar19 + 0x48) +
             *(float *)(iVar19 + 0x58);
  local_f4 = 0;
  FUN_006f75d0(local_120,local_24,local_160,&local_1c0);
  fVar1 = local_1a0[0] - local_120[0];
  fVar2 = local_1a0[1] - local_120[1];
  fVar3 = local_1a0[2] - local_120[2];
  fVar6 = local_1a0[4] - local_120[0];
  fVar7 = local_1a0[5] - local_120[1];
  fVar8 = local_188 - local_120[2];
  local_1e0[0] = local_140[0] * fVar3 + local_160[0] * fVar1 + local_150[0] * fVar2 + local_130;
  local_1e0[1] = fVar2 * local_150[1] + fVar1 * local_160[1] + local_140[1] * fVar3 + local_12c;
  local_1e0[2] = fVar2 * local_150[2] + fVar1 * local_160[2] + fVar3 * local_140[2] + local_128;
  local_1e0[3] = fVar3 * local_140[3] + fVar2 * local_150[3] + fVar1 * local_160[3] + local_124;
  local_1e0[4] = local_150[0] * fVar7 + local_140[0] * fVar8 + local_160[0] * fVar6 + local_130;
  local_1e0[5] = fVar6 * local_160[1] + local_140[1] * fVar8 + fVar7 * local_150[1] + local_12c;
  local_1e0[6] = fVar7 * local_150[2] + fVar6 * local_160[2] + fVar8 * local_140[2] + local_128;
  local_1c4 = fVar8 * local_140[3] + fVar7 * local_150[3] + fVar6 * local_160[3] + local_124;
  fVar1 = *(float *)(iVar16 + 0xc) + *(float *)(iVar4 + 0xc);
  local_b4 = 3.4028235e+38;
  local_84 = 3.4028235e+38;
  local_54 = 0x7f7fffff;
  fVar2 = fVar1 + *(float *)(param_3 + 8);
  if (((byte)(((fVar2 < local_1e0[0]) << 3 | (fVar2 < local_1e0[2]) << 1 |
               (fVar2 < local_1e0[1]) << 2 | fVar2 < local_1e0[3]) &
             ((fVar2 < local_1e0[6]) << 1 | (fVar2 < local_1e0[5]) << 2 |
              (fVar2 < local_1e0[4]) << 3 | fVar2 < local_1c4)) == 0) &&
     ((-fVar2 <= local_1e0[3] || (-fVar2 <= local_1c4)))) {
    local_170 = (uint)(local_1e0[2] < g_flZero) << 1 | (uint)(local_1e0[1] < g_flZero) << 2 |
                (uint)(local_1e0[0] < g_flZero) << 3 | (uint)(local_1e0[3] < g_flZero);
    local_16c = (float)((uint)(local_1e0[6] < g_flZero) << 1 | (uint)(local_1e0[5] < g_flZero) << 2
                        | (uint)(local_1e0[4] < g_flZero) << 3 | (uint)(local_1c4 < g_flZero));
    if ((((uint)local_16c ^ local_170) & 1) != 0) {
      fVar2 = local_1e0[3] / (local_1e0[3] - local_1c4);
      fVar3 = g_flOne - fVar2;
      local_1b0[1] = fVar3 * local_1e0[1] + local_1e0[5] * fVar2;
      local_1b0[2] = local_1e0[2] * fVar3 + local_1e0[6] * fVar2;
      local_1b0[3] = local_1e0[3] * fVar3 + local_1c4 * fVar2;
      if ((byte)((local_1b0[2] < g_flZero) << 1 | (local_1b0[1] < g_flZero) << 2 |
                (fVar3 * local_1e0[0] + fVar2 * local_1e0[4] < g_flZero) * -8 & 0xeU) == 0xe) {
        local_84 = -3.4028235e+38;
        puVar18 = &local_170;
        iVar16 = 0;
        do {
          if ((((byte)*puVar18 & 0xe) == 0xe) &&
             (fVar2 = -ABS(*(float *)((int)local_1e0 + iVar16 + 0xc)) - fVar1, local_84 < fVar2)) {
            if ((*puVar18 & 1) == 0) {
              local_80 = -local_1c0;
              local_7c = -local_1bc;
              local_78 = -local_1b8;
              local_74 = -local_1b4;
              local_88 = *(float *)((int)local_1a0 + iVar16 + 8);
              fVar3 = -*(float *)(iVar4 + 0xc);
            }
            else {
              local_80 = local_1c0;
              local_7c = local_1bc;
              local_78 = local_1b8;
              local_74 = local_1b4;
              fVar3 = *(float *)(iVar4 + 0xc);
              local_88 = *(float *)((int)local_1a0 + iVar16 + 8);
            }
            fVar3 = fVar3 - *(float *)((int)local_1e0 + iVar16 + 0xc);
            local_90 = fVar3 * local_1c0 + *(float *)((int)local_1a0 + iVar16);
            local_8c = fVar3 * local_1bc + *(float *)((int)local_1a0 + iVar16 + 4);
            local_88 = fVar3 * local_1b8 + local_88;
            local_84 = fVar2;
          }
          iVar16 = iVar16 + 0x10;
          puVar18 = puVar18 + 1;
        } while (iVar16 < 0x20);
        iVar16 = 0;
        local_1b0[0] = local_1e0[4] - local_1e0[0];
        local_1b0[1] = local_1e0[5] - local_1e0[1];
        local_1b0[2] = local_1e0[6] - local_1e0[2];
        local_1b0[3] = local_1c4 - local_1e0[3];
        do {
          fVar2 = *(float *)((int)local_1b0 + iVar16);
          fVar3 = g_flOne / (fVar2 * fVar2 + local_1b0[3] * local_1b0[3]);
          fVar6 = local_1e0[3] * fVar2 - local_1b0[3] * *(float *)((int)local_1e0 + iVar16);
          fVar6 = fVar6 * fVar6 * fVar3;
          if (((fVar6 < (fVar1 + local_84) * (fVar1 + local_84)) &&
              (fVar3 = -((fVar2 * *(float *)((int)local_1e0 + iVar16) + local_1e0[3] * local_1b0[3])
                        * fVar3), DAT_00aaa6b4 < fVar3)) && (fVar3 < _DAT_00aaac14)) {
            local_210 = local_1b0[3];
            if (local_1b0[3] < g_flZero) {
              local_210 = -local_1b0[3];
              fVar2 = -fVar2;
            }
            fVar2 = -fVar2;
            fVar8 = fVar2 * local_1c0 + *(float *)((int)local_160 + iVar16) * local_210;
            fVar9 = fVar2 * local_1bc + local_210 * *(float *)((int)local_150 + iVar16);
            fVar7 = fVar2 * local_1b8 + local_210 * *(float *)((int)local_140 + iVar16);
            fVar11 = fVar8 * fVar8 + fVar9 * fVar9 + fVar7 * fVar7;
            fVar10 = g_flZero;
            if (fVar11 != g_flZero) {
              fVar10 = g_flOne / SQRT(fVar11);
            }
            local_80 = fVar8 * fVar10;
            local_7c = fVar10 * fVar9;
            local_78 = fVar7 * fVar10;
            local_74 = fVar10 * (fVar2 * local_1b4 + local_210 * g_flZero);
            fVar11 = g_flOne - fVar3;
            local_16c = local_1a0[1] * fVar11 + fVar3 * local_1a0[5];
            local_168 = local_188 * fVar3 + local_1a0[2] * fVar11;
            fVar2 = -SQRT(fVar6);
            fVar6 = *(float *)(iVar4 + 0xc) - fVar2;
            local_90 = fVar8 * fVar10 * fVar6 + fVar3 * local_1a0[4] + local_1a0[0] * fVar11;
            local_8c = fVar10 * fVar9 * fVar6 + local_16c;
            local_88 = fVar7 * fVar10 * fVar6 + local_168;
            local_84 = fVar2 - fVar1;
          }
          iVar16 = iVar16 + 4;
        } while (iVar16 < 0xc);
        goto LAB_006ddb4d;
      }
    }
    iVar16 = 0;
    local_180 = local_1a0[4] - local_1a0[0];
    pfVar13 = local_c0;
    bVar12 = false;
    local_17c = local_1a0[5] - local_1a0[1];
    local_178 = local_188 - local_1a0[2];
    local_174 = local_184 - local_1a0[3];
    if (((SUB41(local_16c,0) | (byte)local_170) & 0xe) == 0xe) goto LAB_006ddc4c;
    bVar12 = true;
    do {
      local_214 = 8;
      iVar19 = 0;
      do {
        if (bVar12) {
          uVar15 = local_170 & local_214 & (uint)local_16c;
        }
        else {
          uVar15 = (&local_170)[iVar16] & local_214;
        }
        if (uVar15 == 0) {
          iVar17 = (int)(char)(&DAT_00a0eefc)[iVar19];
          iVar14 = (int)(char)(&DAT_00a0eefe)[iVar19];
          local_1b0[0] = local_120[iVar17 * 4] - local_120[iVar14 * 4];
          local_1b0[1] = local_120[iVar17 * 4 + 1] - local_120[iVar14 * 4 + 1];
          local_1b0[2] = local_120[iVar17 * 4 + 2] - local_120[iVar14 * 4 + 2];
          local_1b0[3] = local_120[iVar17 * 4 + 3] - local_120[iVar14 * 4 + 3];
          uVar15 = FUN_006f6ef0(local_1a0,&local_180,local_120 + iVar14 * 4,local_1b0,&local_f0);
          if (local_d0 < (fVar1 + pfVar13[3]) * (fVar1 + pfVar13[3])) {
            if ((uVar15 & 1 << ((byte)iVar16 & 0x1f)) != 0) {
              if (!bVar12) goto LAB_006de0d8;
              iVar16 = 1;
            }
            if (uVar15 == 0) {
              local_1fc = local_1b0[0] * local_178 - local_180 * local_1b0[2];
              local_1f8 = local_180 * local_1b0[1] - local_1b0[0] * local_17c;
              local_1f4 = 0.0;
              fVar2 = local_1b0[2] * local_17c - local_1b0[1] * local_178;
            }
            else {
              if (local_d0 < _DAT_00a0e520 != (local_d0 == _DAT_00a0e520)) {
                local_d4 = 0.0;
                local_e0 = local_160[iVar19];
                local_1f4 = 0.0;
                local_dc = local_150[iVar19];
                local_d8 = local_140[iVar19];
                fVar2 = local_1b0[2] * local_17c - local_1b0[1] * local_178;
                local_1fc = local_1b0[0] * local_178 - local_180 * local_1b0[2];
                local_1f8 = local_180 * local_1b0[1] - local_1b0[0] * local_17c;
                fVar3 = local_1fc * local_1fc + local_1f8 * local_1f8 + fVar2 * fVar2;
                if (fVar3 < _DAT_00a0e520 == (fVar3 == _DAT_00a0e520)) goto LAB_006ddfc4;
              }
              local_1fc = local_dc;
              local_1f8 = local_d8;
              local_1f4 = local_d4;
              fVar2 = local_e0;
            }
LAB_006ddfc4:
            fVar3 = local_1fc * local_1fc + local_1f8 * local_1f8 + fVar2 * fVar2;
            if (fVar3 == g_flZero) {
              local_210 = 0.0;
            }
            else {
              local_210 = g_flOne / SQRT(fVar3);
            }
            fVar2 = fVar2 * local_210;
            local_1fc = local_210 * local_1fc;
            local_1f8 = local_210 * local_1f8;
            local_1f4 = local_210 * local_1f4;
            fVar3 = local_dc * local_1fc + local_d8 * local_1f8 + local_e0 * fVar2;
            if (fVar3 < g_flZero) {
              fVar3 = -fVar3;
              fVar2 = -fVar2;
              local_1fc = -local_1fc;
              local_1f8 = -local_1f8;
              local_1f4 = -local_1f4;
            }
            fVar6 = *(float *)(iVar4 + 0xc) - fVar3;
            *pfVar13 = fVar6 * fVar2 + local_f0;
            pfVar13[1] = fVar6 * local_1fc + local_ec;
            pfVar13[2] = local_1f8 * fVar6 + local_e8;
            pfVar13[3] = fVar6 * local_1f4 + local_e4;
            pfVar13[3] = fVar3 - fVar1;
            pfVar13[6] = local_1f8;
            pfVar13[7] = local_1f4;
            pfVar13[4] = fVar2;
            pfVar13[5] = local_1fc;
          }
        }
LAB_006de0d8:
        local_214 = (int)local_214 >> 1;
        iVar19 = iVar19 + 1;
      } while (iVar19 < 3);
      if (bVar12) break;
      iVar16 = iVar16 + 1;
      pfVar13 = pfVar13 + 0xc;
LAB_006ddc4c:
      while( true ) {
        if (1 < iVar16) goto LAB_006ddb4d;
        if (((byte)(&local_170)[iVar16] & 0xe) != 0xe) break;
        if (((&local_170)[iVar16] & 1) == 0) {
          fVar2 = *(float *)(iVar4 + 0xc) - local_1e0[iVar16 * 4 + 3];
          *pfVar13 = local_1c0 * fVar2 + local_1a0[iVar16 * 4];
          pfVar13[1] = local_1bc * fVar2 + local_1a0[iVar16 * 4 + 1];
          pfVar13[2] = local_1b8 * fVar2 + local_1a0[iVar16 * 4 + 2];
          pfVar13[3] = fVar2 * local_1b4 + local_1a0[iVar16 * 4 + 3];
          pfVar13[3] = local_1e0[iVar16 * 4 + 3] - fVar1;
          pfVar13[4] = local_1c0;
          pfVar13[5] = local_1bc;
          pfVar13[6] = local_1b8;
          pfVar13[7] = local_1b4;
          iVar16 = iVar16 + 1;
          pfVar13 = pfVar13 + 0xc;
        }
        else {
          fVar2 = -*(float *)(iVar4 + 0xc) - local_1e0[iVar16 * 4 + 3];
          *pfVar13 = local_1c0 * fVar2 + local_1a0[iVar16 * 4];
          pfVar13[1] = local_1bc * fVar2 + local_1a0[iVar16 * 4 + 1];
          pfVar13[2] = local_1b8 * fVar2 + local_1a0[iVar16 * 4 + 2];
          pfVar13[3] = fVar2 * local_1b4 + local_1a0[iVar16 * 4 + 3];
          pfVar13[3] = -local_1e0[iVar16 * 4 + 3] - fVar1;
          pfVar13[4] = -local_1c0;
          pfVar13[5] = -local_1bc;
          pfVar13[6] = -local_1b8;
          pfVar13[7] = -local_1b4;
          iVar16 = iVar16 + 1;
          pfVar13 = pfVar13 + 0xc;
        }
      }
    } while( true );
  }
LAB_006ddb4d:
  if ((local_b4 < g_flZero) || (local_84 < g_flZero)) {
    (**(code **)(*param_4 + 4))(param_1,param_2);
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
