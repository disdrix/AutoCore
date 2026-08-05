# Raw capture: FUN_006df0b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006df0b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006df0b0` |
| **Canonical name** | `FUN_006df0b0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006df0b0(int *param_1,float *param_2,float param_3,float *param_4)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  bool bVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  uint uVar20;
  float *pfVar21;
  uint uVar22;
  int iVar23;
  float *pfVar24;
  float local_c8;
  float local_c4;
  float local_b0 [6];
  uint local_98;
  float local_94;
  float local_8c;
  float local_88;
  float local_84;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  uint local_60;
  float local_3c;
  float local_38;
  float local_30;
  float local_2c;
  float local_28;
  
  iVar1 = *param_1;
  fVar2 = *(float *)(iVar1 + 0x10);
  iVar23 = param_1[2];
  fVar3 = *(float *)(iVar1 + 0x14);
  fVar4 = *(float *)(iVar1 + 0x18);
  fVar16 = fVar3 * *(float *)(iVar23 + 0x30) +
           fVar4 * *(float *)(iVar23 + 0x40) + fVar2 * *(float *)(iVar23 + 0x20) +
           *(float *)(iVar23 + 0x50);
  fVar7 = fVar3 * *(float *)(iVar23 + 0x34) +
          fVar4 * *(float *)(iVar23 + 0x44) + fVar2 * *(float *)(iVar23 + 0x24) +
          *(float *)(iVar23 + 0x54);
  fVar8 = fVar3 * *(float *)(iVar23 + 0x38) +
          fVar4 * *(float *)(iVar23 + 0x48) + fVar2 * *(float *)(iVar23 + 0x28) +
          *(float *)(iVar23 + 0x58);
  fVar2 = *(float *)(iVar1 + 0x20);
  fVar3 = *(float *)(iVar1 + 0x24);
  fVar4 = *(float *)(iVar1 + 0x28);
  fVar9 = fVar3 * *(float *)(iVar23 + 0x30) +
          fVar4 * *(float *)(iVar23 + 0x40) + fVar2 * *(float *)(iVar23 + 0x20) +
          *(float *)(iVar23 + 0x50);
  local_2c = fVar3 * *(float *)(iVar23 + 0x34) +
             fVar4 * *(float *)(iVar23 + 0x44) + fVar2 * *(float *)(iVar23 + 0x24) +
             *(float *)(iVar23 + 0x54);
  local_28 = fVar3 * *(float *)(iVar23 + 0x38) +
             fVar4 * *(float *)(iVar23 + 0x48) + fVar2 * *(float *)(iVar23 + 0x28) +
             *(float *)(iVar23 + 0x58);
  local_b0[0] = fVar9 - fVar16;
  local_b0[1] = local_2c - fVar7;
  local_b0[2] = local_28 - fVar8;
  local_70 = param_2[4] - *param_2;
  local_6c = param_2[5] - param_2[1];
  local_68 = param_2[6] - param_2[2];
  local_64 = param_2[7] - param_2[3];
  local_94 = local_68 * local_b0[2] + local_6c * local_b0[1] + local_70 * local_b0[0];
  local_3c = fVar7;
  local_38 = fVar8;
  local_30 = fVar9;
  if (local_94 < g_flZero) {
    local_94 = -local_94;
    local_b0[0] = -local_b0[0];
    local_b0[1] = -local_b0[1];
    local_b0[2] = -local_b0[2];
    local_3c = local_2c;
    local_38 = local_28;
    local_30 = fVar16;
    local_2c = fVar7;
    local_28 = fVar8;
    fVar16 = fVar9;
  }
  local_b0[3] = 0.0;
  fVar9 = (param_2[2] - local_38) * local_b0[2] +
          (param_2[1] - local_3c) * local_b0[1] + (*param_2 - fVar16) * local_b0[0];
  local_c4 = (param_2[1] - local_3c) * local_6c +
             (param_2[2] - local_38) * local_68 + (*param_2 - fVar16) * local_70;
  fVar2 = local_b0[1] * local_b0[1] + local_b0[2] * local_b0[2] + local_b0[0] * local_b0[0];
  fVar3 = local_6c * local_6c + local_68 * local_68 + local_70 * local_70;
  fVar4 = fVar3 * fVar2;
  fVar8 = ABS(fVar4 - local_94 * local_94);
  fVar7 = fVar3 * fVar9 - local_c4 * local_94;
  if (fVar8 * fVar8 < fVar7 * fVar8 == (fVar8 * fVar8 == fVar7 * fVar8)) {
    if (fVar7 < g_flZero == (fVar7 == g_flZero)) {
      if (fVar8 <= (ABS(fVar4) + local_94 * local_94) * _DAT_00aaab90) goto LAB_006df3fd;
      local_98 = 0;
      fVar7 = fVar7 / fVar8;
    }
    else {
      local_98 = 2;
      fVar7 = g_flZero;
    }
  }
  else {
LAB_006df3fd:
    local_98 = 1;
    fVar7 = g_flOne;
  }
  local_c8 = local_94 * fVar7 - local_c4;
  if (local_c8 < fVar3) {
    if (local_c8 < g_flZero == (local_c8 == g_flZero)) {
      local_c8 = local_c8 / fVar3;
      goto LAB_006df4c7;
    }
    local_c8 = 0.0;
    local_98 = 8;
  }
  else {
    local_c8 = 1.0;
    local_98 = 4;
  }
  fVar7 = local_c8 * local_94 + fVar9;
  if (fVar7 < g_flZero == (fVar7 == g_flZero)) {
    if (fVar7 < fVar2) {
      fVar7 = fVar7 / fVar2;
    }
    else {
      local_98 = local_98 | 1;
      fVar7 = g_flOne;
    }
  }
  else {
    local_98 = local_98 | 2;
    fVar7 = g_flZero;
  }
LAB_006df4c7:
  fVar5 = param_2[3];
  fVar17 = local_b0[0] * fVar7 + fVar16;
  fVar19 = local_b0[1] * fVar7 + local_3c;
  fVar18 = local_b0[2] * fVar7 + local_38;
  fVar7 = fVar7 * g_flZero;
  fVar12 = fVar17 - (local_70 * local_c8 + *param_2);
  fVar10 = fVar19 - (local_6c * local_c8 + param_2[1]);
  fVar11 = fVar18 - (local_68 * local_c8 + param_2[2]);
  fVar13 = param_3 + *(float *)(iVar1 + 0xc);
  fVar14 = fVar13 + param_4[3];
  fVar15 = fVar12 * fVar12 + fVar10 * fVar10 + fVar11 * fVar11;
  if (fVar15 < fVar14 * fVar14) {
    param_4[5] = fVar10;
    param_4[7] = fVar7 - (local_64 * local_c8 + fVar5);
    param_4[4] = fVar12;
    param_4[6] = fVar11;
    if (fVar15 < _DAT_00a0e548) {
      bVar6 = ABS(local_b0[0]) <= ABS(local_b0[1]);
      fVar5 = ABS(local_b0[0]);
      if (!bVar6) {
        fVar5 = ABS(local_b0[1]);
      }
      uVar20 = (uint)!bVar6;
      uVar22 = 2;
      if (ABS(local_b0[2]) < fVar5) {
        uVar20 = 2;
        uVar22 = (uint)!bVar6;
      }
      fVar5 = local_b0[bVar6];
      param_4[uVar20 + 4] = 0.0;
      param_4[bVar6 + 4] = local_b0[uVar22];
      param_4[uVar22 + 4] = -fVar5;
    }
    fVar5 = param_4[6] * param_4[6] + param_4[5] * param_4[5] + param_4[4] * param_4[4];
    fVar10 = g_flZero;
    if (fVar5 != g_flZero) {
      fVar10 = g_flOne / SQRT(fVar5);
    }
    param_4[4] = fVar10 * param_4[4];
    param_4[5] = fVar10 * param_4[5];
    param_4[6] = fVar10 * param_4[6];
    param_4[7] = fVar10 * param_4[7];
    *param_4 = fVar17;
    fVar5 = param_3 - SQRT(fVar15);
    param_4[1] = fVar19;
    param_4[2] = fVar18;
    param_4[3] = fVar7;
    *param_4 = fVar5 * param_4[4] + fVar17;
    param_4[1] = fVar5 * param_4[5] + fVar19;
    param_4[2] = fVar5 * param_4[6] + fVar18;
    param_4[3] = fVar5 * param_4[7] + fVar7;
    param_4[3] = SQRT(fVar15) - fVar13;
    if (fVar8 <= fVar4 * DAT_00a0f70c) {
      local_88 = local_38;
      local_78 = param_2[2];
      local_8c = local_3c;
      local_7c = param_2[1];
      local_74 = param_2[3];
      iVar23 = 0;
      local_60 = 10;
      pfVar21 = param_4 + 0x12;
      fVar7 = fVar3 * (g_flOne / fVar4);
      fVar8 = (g_flOne / fVar4) * fVar2;
      fVar4 = *param_2;
      local_c4 = -local_c4;
      pfVar24 = param_4;
      local_c8 = fVar9;
      do {
        local_84 = 0.0;
        pfVar24 = pfVar24 + 0xc;
        if ((local_60 & local_98) == 0) {
          if (local_c4 <= g_flZero) {
            if (g_flZero < local_c8) {
              if (fVar2 < local_c8) goto LAB_006dfaac;
LAB_006df8c4:
              local_84 = local_c8 * fVar7;
              fVar16 = local_b0[0] * local_84 + fVar16;
              local_8c = local_b0[1] * local_84 + local_8c;
              local_88 = local_b0[2] * local_84 + local_88;
              local_84 = local_b0[3] * local_84;
            }
          }
          else {
            if (fVar3 < local_c4) goto LAB_006dfaac;
            if (g_flZero < local_c8) {
              if (fVar2 < local_c8) goto LAB_006dfaac;
              if (local_c8 * local_c8 * fVar7 < local_c4 * local_c4 * fVar8) goto LAB_006df8c4;
            }
            fVar9 = local_c4 * fVar8;
            fVar4 = local_70 * fVar9 + fVar4;
            local_7c = local_6c * fVar9 + local_7c;
            local_78 = local_68 * fVar9 + local_78;
            local_74 = local_64 * fVar9 + local_74;
          }
          fVar4 = fVar16 - fVar4;
          local_7c = local_8c - local_7c;
          local_78 = local_88 - local_78;
          fVar10 = param_3 + *(float *)(iVar1 + 0xc);
          fVar5 = fVar10 + pfVar21[-3];
          fVar9 = fVar4 * fVar4 + local_7c * local_7c + local_78 * local_78;
          if (fVar9 < fVar5 * fVar5) {
            pfVar21[-1] = local_7c;
            *pfVar21 = local_78;
            pfVar21[1] = local_84 - local_74;
            pfVar21[-2] = fVar4;
            if (fVar9 <= _DAT_00a0e548) {
              pfVar21[-2] = param_4[4];
              pfVar21[-1] = param_4[5];
              *pfVar21 = param_4[6];
              pfVar21[1] = param_4[7];
            }
            else {
              fVar4 = *pfVar21 * *pfVar21 + pfVar21[-1] * pfVar21[-1] + pfVar21[-2] * pfVar21[-2];
              fVar5 = g_flZero;
              if (fVar4 != g_flZero) {
                fVar5 = g_flOne / SQRT(fVar4);
              }
              pfVar21[-2] = fVar5 * pfVar21[-2];
              pfVar21[-1] = fVar5 * pfVar21[-1];
              *pfVar21 = fVar5 * *pfVar21;
              pfVar21[1] = fVar5 * pfVar21[1];
            }
            *pfVar24 = fVar16;
            pfVar21[-5] = local_8c;
            fVar4 = param_3 - SQRT(fVar9);
            pfVar21[-4] = local_88;
            pfVar21[-3] = local_84;
            *pfVar24 = fVar4 * pfVar21[-2] + fVar16;
            pfVar21[-5] = fVar4 * pfVar21[-1] + local_8c;
            pfVar21[-4] = fVar4 * *pfVar21 + local_88;
            pfVar21[-3] = fVar4 * pfVar21[1] + local_84;
            pfVar21[-3] = SQRT(fVar9) - fVar10;
          }
        }
LAB_006dfaac:
        if (iVar23 == 1) {
          return;
        }
        local_8c = local_2c;
        fVar4 = param_2[4];
        local_88 = local_28;
        local_7c = param_2[5];
        local_c4 = (fVar3 - local_c4) - local_94;
        local_78 = param_2[6];
        local_74 = param_2[7];
        pfVar21 = pfVar21 + 0xc;
        iVar23 = iVar23 + 1;
        local_c8 = (fVar2 - local_c8) - local_94;
        local_60 = 5;
        local_b0[0] = -local_b0[0];
        local_b0[1] = -local_b0[1];
        local_b0[2] = -local_b0[2];
        local_b0[3] = -local_b0[3];
        local_70 = -local_70;
        local_6c = -local_6c;
        local_68 = -local_68;
        local_64 = -local_64;
        fVar16 = local_30;
      } while( true );
    }
  }
  return;
}
```
