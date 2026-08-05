# Raw capture: FUN_006dfb90

| Field | Value |
|---|---|
| **Stable ID** | `aa_006dfb90` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006dfb90` |
| **Canonical name** | `FUN_006dfb90` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006dfb90(int *param_1,int *param_2,int param_3,int *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int *piVar6;
  bool bVar7;
  undefined8 uVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  short sVar13;
  float *pfVar14;
  uint uVar15;
  float *pfVar16;
  uint uVar17;
  int iVar18;
  uint uVar19;
  short *psVar20;
  float local_17c;
  float local_178;
  int local_16c;
  float local_160 [7];
  float local_144;
  float local_140;
  float local_13c;
  float local_138;
  float local_134;
  float local_130;
  float local_12c;
  float local_128;
  float local_124;
  float local_11c;
  float local_118;
  float local_114;
  float local_108;
  float local_104;
  float local_100;
  float local_fc;
  float local_f8;
  float local_f4;
  float local_ec;
  int local_e8;
  float local_e4;
  float local_dc;
  float local_d8;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c0;
  float local_bc;
  float local_b8;
  undefined4 local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  undefined4 local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90 [11];
  float local_64;
  float local_58 [9];
  float local_34;
  
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = "TtCapsCaps";
    uVar8 = rdtsc();
    DAT_00bc5644[1] = (int)uVar8;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  local_94 = *(float *)(param_3 + 8);
  iVar5 = *param_2;
  local_64 = local_94;
  local_34 = local_94;
  FUN_00404d80(&local_c0,0x10,2,FUN_005edf20);
  fVar1 = *(float *)(iVar5 + 0x10);
  fVar2 = *(float *)(iVar5 + 0x14);
  iVar18 = param_2[2];
  fVar3 = *(float *)(iVar5 + 0x18);
  local_c0 = fVar2 * *(float *)(iVar18 + 0x30) +
             fVar3 * *(float *)(iVar18 + 0x40) + fVar1 * *(float *)(iVar18 + 0x20) +
             *(float *)(iVar18 + 0x50);
  local_bc = fVar2 * *(float *)(iVar18 + 0x34) +
             fVar3 * *(float *)(iVar18 + 0x44) + fVar1 * *(float *)(iVar18 + 0x24) +
             *(float *)(iVar18 + 0x54);
  local_b8 = fVar2 * *(float *)(iVar18 + 0x38) +
             fVar3 * *(float *)(iVar18 + 0x48) + fVar1 * *(float *)(iVar18 + 0x28) +
             *(float *)(iVar18 + 0x58);
  local_b4 = 0;
  fVar1 = *(float *)(iVar5 + 0x20);
  fVar2 = *(float *)(iVar5 + 0x24);
  fVar3 = *(float *)(iVar5 + 0x28);
  local_b0 = fVar2 * *(float *)(iVar18 + 0x30) +
             fVar3 * *(float *)(iVar18 + 0x40) + fVar1 * *(float *)(iVar18 + 0x20) +
             *(float *)(iVar18 + 0x50);
  local_ac = fVar2 * *(float *)(iVar18 + 0x34) +
             fVar3 * *(float *)(iVar18 + 0x44) + fVar1 * *(float *)(iVar18 + 0x24) +
             *(float *)(iVar18 + 0x54);
  local_a8 = fVar2 * *(float *)(iVar18 + 0x38) +
             fVar3 * *(float *)(iVar18 + 0x48) + fVar1 * *(float *)(iVar18 + 0x28) +
             *(float *)(iVar18 + 0x58);
  local_a4 = 0;
  local_ec = *(float *)(iVar5 + 0xc);
  iVar5 = *param_1;
  fVar1 = *(float *)(iVar5 + 0x10);
  iVar18 = param_1[2];
  fVar2 = *(float *)(iVar5 + 0x14);
  fVar3 = *(float *)(iVar5 + 0x18);
  fVar12 = fVar2 * *(float *)(iVar18 + 0x30) +
           fVar3 * *(float *)(iVar18 + 0x40) + fVar1 * *(float *)(iVar18 + 0x20) +
           *(float *)(iVar18 + 0x50);
  fVar9 = fVar2 * *(float *)(iVar18 + 0x34) +
          fVar3 * *(float *)(iVar18 + 0x44) + fVar1 * *(float *)(iVar18 + 0x24) +
          *(float *)(iVar18 + 0x54);
  fVar10 = fVar2 * *(float *)(iVar18 + 0x38) +
           fVar3 * *(float *)(iVar18 + 0x48) + fVar1 * *(float *)(iVar18 + 0x28) +
           *(float *)(iVar18 + 0x58);
  fVar1 = *(float *)(iVar5 + 0x20);
  fVar2 = *(float *)(iVar5 + 0x24);
  fVar3 = *(float *)(iVar5 + 0x28);
  fVar4 = fVar2 * *(float *)(iVar18 + 0x30) +
          fVar3 * *(float *)(iVar18 + 0x40) + fVar1 * *(float *)(iVar18 + 0x20) +
          *(float *)(iVar18 + 0x50);
  local_cc = fVar2 * *(float *)(iVar18 + 0x34) +
             fVar3 * *(float *)(iVar18 + 0x44) + fVar1 * *(float *)(iVar18 + 0x24) +
             *(float *)(iVar18 + 0x54);
  local_c8 = fVar2 * *(float *)(iVar18 + 0x38) +
             fVar3 * *(float *)(iVar18 + 0x48) + fVar1 * *(float *)(iVar18 + 0x28) +
             *(float *)(iVar18 + 0x58);
  local_160[0] = fVar4 - fVar12;
  local_160[1] = local_cc - fVar9;
  local_160[2] = local_c8 - fVar10;
  local_134 = 0.0;
  local_140 = local_b0 - local_c0;
  local_13c = local_ac - local_bc;
  local_138 = local_a8 - local_b8;
  local_144 = local_140 * local_160[0] + local_13c * local_160[1] + local_138 * local_160[2];
  local_dc = fVar9;
  local_d8 = fVar10;
  local_d0 = fVar4;
  if (local_144 < g_flZero) {
    local_144 = -local_144;
    local_160[0] = -local_160[0];
    local_160[1] = -local_160[1];
    local_160[2] = -local_160[2];
    local_dc = local_cc;
    local_d8 = local_c8;
    local_d0 = fVar12;
    local_cc = fVar9;
    local_c8 = fVar10;
    fVar12 = fVar4;
  }
  local_160[3] = 0.0;
  local_108 = (local_c0 - fVar12) * local_160[0] +
              (local_bc - local_dc) * local_160[1] + local_160[2] * (local_b8 - local_d8);
  local_104 = (local_c0 - fVar12) * local_140 +
              (local_bc - local_dc) * local_13c + (local_b8 - local_d8) * local_138;
  fVar1 = local_160[0] * local_160[0] + local_160[1] * local_160[1] + local_160[2] * local_160[2];
  fVar2 = local_140 * local_140 + local_13c * local_13c + local_138 * local_138;
  fVar3 = fVar2 * fVar1;
  fVar10 = ABS(fVar3 - local_144 * local_144);
  fVar9 = fVar2 * local_108 - local_104 * local_144;
  if (fVar10 * fVar10 < fVar9 * fVar10 == (fVar10 * fVar10 == fVar9 * fVar10)) {
    if (fVar9 < g_flZero == (fVar9 == g_flZero)) {
      if (fVar10 <= (ABS(fVar3) + local_144 * local_144) * _DAT_00aaab90) goto LAB_006e0036;
      uVar17 = 0;
      fVar9 = fVar9 / fVar10;
    }
    else {
      uVar17 = 2;
      fVar9 = g_flZero;
    }
  }
  else {
LAB_006e0036:
    uVar17 = 1;
    fVar9 = g_flOne;
  }
  local_17c = local_144 * fVar9 - local_104;
  if (local_17c < fVar2) {
    if (g_flZero <= local_17c) {
      local_17c = local_17c / fVar2;
      goto LAB_006e00e7;
    }
    local_17c = 0.0;
    uVar17 = 8;
  }
  else {
    local_17c = 1.0;
    uVar17 = 4;
  }
  fVar9 = local_17c * local_144 + local_108;
  if (g_flZero <= fVar9) {
    if (fVar9 < fVar1) {
      fVar9 = fVar9 / fVar1;
    }
    else {
      uVar17 = uVar17 | 1;
      fVar9 = g_flOne;
    }
  }
  else {
    uVar17 = uVar17 | 2;
    fVar9 = g_flZero;
  }
LAB_006e00e7:
  local_100 = local_160[0] * fVar9 + fVar12;
  local_fc = local_160[1] * fVar9 + local_dc;
  local_f8 = local_160[2] * fVar9 + local_d8;
  local_118 = local_138 * local_17c + local_b8;
  local_114 = local_17c * g_flZero;
  local_130 = local_100 - (local_140 * local_17c + local_c0);
  local_12c = local_fc - (local_13c * local_17c + local_bc);
  local_128 = local_f8 - local_118;
  local_124 = fVar9 * g_flZero - local_114;
  fVar9 = local_ec + *(float *)(iVar5 + 0xc);
  fVar4 = local_94 + fVar9;
  fVar11 = local_130 * local_130 + local_12c * local_12c + local_128 * local_128;
  if (fVar11 < fVar4 * fVar4) {
    local_90[1] = local_12c;
    local_90[3] = local_124;
    local_90[0] = local_130;
    local_90[2] = local_128;
    if (fVar11 < _DAT_00a0e548) {
      bVar7 = ABS(local_160[0]) <= ABS(local_160[1]);
      fVar4 = ABS(local_160[0]);
      if (!bVar7) {
        fVar4 = ABS(local_160[1]);
      }
      uVar15 = (uint)!bVar7;
      uVar19 = 2;
      if (ABS(local_160[2]) < fVar4) {
        uVar15 = 2;
        uVar19 = (uint)!bVar7;
      }
      fVar4 = local_160[bVar7];
      local_90[uVar15] = 0.0;
      local_90[bVar7] = local_160[uVar19];
      local_90[uVar19] = -fVar4;
    }
    fVar4 = local_90[0] * local_90[0] + local_90[1] * local_90[1] + local_90[2] * local_90[2];
    local_90[3] = g_flZero;
    if (fVar4 != g_flZero) {
      local_90[3] = g_flOne / SQRT(fVar4);
    }
    local_90[0] = local_90[0] * local_90[3];
    local_90[1] = local_90[1] * local_90[3];
    local_90[2] = local_90[2] * local_90[3];
    local_90[3] = local_124 * local_90[3];
    fVar4 = local_ec - SQRT(fVar11);
    local_a0 = local_90[0] * fVar4 + local_100;
    local_9c = local_90[1] * fVar4 + local_fc;
    local_98 = local_90[2] * fVar4 + local_f8;
    local_94 = SQRT(fVar11) - fVar9;
    if (fVar10 <= fVar3 * DAT_00a0f70c) {
      local_11c = local_dc;
      local_118 = local_d8;
      iVar18 = 0;
      uVar15 = 10;
      pfVar16 = local_58;
      fVar9 = fVar2 * (g_flOne / fVar3);
      local_e4 = (g_flOne / fVar3) * fVar1;
      local_178 = -local_104;
      fVar3 = local_c0;
      local_17c = local_108;
      local_12c = local_bc;
      local_128 = local_b8;
      do {
        local_124 = 0.0;
        local_114 = 0.0;
        if ((uVar17 & uVar15) == 0) {
          if (local_178 <= g_flZero) {
            if (g_flZero < local_17c) {
              if (fVar1 < local_17c) goto LAB_006e0700;
LAB_006e050b:
              local_114 = local_17c * fVar9;
              fVar12 = local_160[0] * local_114 + fVar12;
              local_11c = local_160[1] * local_114 + local_11c;
              local_118 = local_160[2] * local_114 + local_118;
              local_114 = local_160[3] * local_114;
            }
          }
          else {
            if (fVar2 < local_178) goto LAB_006e0700;
            if (g_flZero < local_17c) {
              if (fVar1 < local_17c) goto LAB_006e0700;
              if (local_17c * local_17c * fVar9 < local_178 * local_178 * local_e4)
              goto LAB_006e050b;
            }
            fVar10 = local_178 * local_e4;
            fVar3 = local_140 * fVar10 + fVar3;
            local_12c = local_13c * fVar10 + local_12c;
            local_128 = local_138 * fVar10 + local_128;
            local_124 = local_134 * fVar10 + 0.0;
          }
          fVar3 = fVar12 - fVar3;
          local_fc = local_11c - local_12c;
          local_f8 = local_118 - local_128;
          local_f4 = local_114 - local_124;
          fVar4 = local_ec + *(float *)(iVar5 + 0xc);
          fVar10 = fVar4 + pfVar16[-3];
          local_108 = local_fc * local_fc + local_f8 * local_f8 + fVar3 * fVar3;
          if (local_108 < fVar10 * fVar10) {
            local_104 = SQRT(local_108);
            pfVar16[-1] = local_fc;
            *pfVar16 = local_f8;
            pfVar16[1] = local_f4;
            pfVar16[-2] = fVar3;
            if (local_108 <= _DAT_00a0e548) {
              pfVar16[-2] = local_90[0];
              pfVar16[-1] = local_90[1];
              *pfVar16 = local_90[2];
              pfVar16[1] = local_90[3];
            }
            else {
              fVar3 = *pfVar16 * *pfVar16 + pfVar16[-1] * pfVar16[-1] + pfVar16[-2] * pfVar16[-2];
              fVar10 = g_flZero;
              if (fVar3 != g_flZero) {
                fVar10 = g_flOne / SQRT(fVar3);
              }
              pfVar16[-2] = fVar10 * pfVar16[-2];
              pfVar16[-1] = fVar10 * pfVar16[-1];
              *pfVar16 = fVar10 * *pfVar16;
              pfVar16[1] = fVar10 * pfVar16[1];
            }
            pfVar16[-6] = fVar12;
            pfVar16[-5] = local_11c;
            fVar3 = local_ec - local_104;
            pfVar16[-4] = local_118;
            pfVar16[-3] = local_114;
            pfVar16[-6] = fVar3 * pfVar16[-2] + fVar12;
            pfVar16[-5] = fVar3 * pfVar16[-1] + local_11c;
            pfVar16[-4] = fVar3 * *pfVar16 + local_118;
            pfVar16[-3] = fVar3 * pfVar16[1] + local_114;
            pfVar16[-3] = local_104 - fVar4;
          }
        }
LAB_006e0700:
        if (iVar18 == 1) break;
        local_11c = local_cc;
        local_118 = local_c8;
        local_178 = (fVar2 - local_178) - local_144;
        pfVar16 = pfVar16 + 0xc;
        iVar18 = iVar18 + 1;
        uVar15 = 5;
        local_17c = (fVar1 - local_17c) - local_144;
        local_160[0] = -local_160[0];
        local_160[1] = -local_160[1];
        local_160[2] = -local_160[2];
        local_160[3] = -local_160[3];
        local_140 = -local_140;
        local_13c = -local_13c;
        local_138 = -local_138;
        local_134 = -local_134;
        fVar3 = local_b0;
        local_12c = local_ac;
        local_128 = local_a8;
        fVar12 = local_d0;
      } while( true );
    }
  }
  psVar20 = (short *)(local_e8 + 0xc);
  pfVar16 = &local_98;
  local_16c = 3;
  do {
    if (*(float *)(param_3 + 8) <= pfVar16[1]) {
      if (*psVar20 != -1) {
        (**(code **)(**(int **)(local_e8 + 8) + 8))(*psVar20);
        *psVar20 = -1;
      }
    }
    else {
      if (*psVar20 == -1) {
        sVar13 = (**(code **)(**(int **)(local_e8 + 8) + 4))(param_1,param_2,param_3,pfVar16 + -2);
        *psVar20 = sVar13;
        if (sVar13 == -1) goto LAB_006e08bf;
      }
      piVar6 = (int *)*param_4;
      if (piVar6[1] == (piVar6[2] & 0x7fffffffU)) {
        FUN_005b3370(piVar6,0x30);
      }
      pfVar14 = (float *)(piVar6[1] * 0x30 + *piVar6);
      piVar6[1] = piVar6[1] + 1;
      *pfVar14 = pfVar16[-2];
      pfVar14[1] = pfVar16[-1];
      pfVar14[2] = *pfVar16;
      pfVar14[3] = pfVar16[1];
      pfVar14[4] = pfVar16[2];
      pfVar14[5] = pfVar16[3];
      pfVar14[6] = pfVar16[4];
      pfVar14[7] = pfVar16[5];
      *(short *)(pfVar14 + 8) = *psVar20;
    }
LAB_006e08bf:
    psVar20 = psVar20 + 1;
    pfVar16 = pfVar16 + 0xc;
    local_16c = local_16c + -1;
    if (local_16c == 0) {
      if (DAT_00bc5644 < DAT_00bc5648) {
        *DAT_00bc5644 = &DAT_009d2878;
        uVar8 = rdtsc();
        DAT_00bc5644[1] = (int)uVar8;
        DAT_00bc5644 = DAT_00bc5644 + 3;
      }
      return;
    }
  } while( true );
}
```
