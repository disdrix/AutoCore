# Raw capture: FUN_006cb9c0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006cb9c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006cb9c0` |
| **Canonical name** | `FUN_006cb9c0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_006cb9c0(int *param_1,float *param_2,undefined4 param_3,undefined4 *param_4)

{
  bool bVar1;
  bool bVar2;
  int unaff_EBX;
  int iVar3;
  float fVar4;
  float unaff_EDI;
  float fVar5;
  float fVar6;
  bool bVar7;
  float10 fVar8;
  float10 fVar9;
  float fVar10;
  float fStack_f4;
  float fStack_f0;
  float local_ec;
  float local_e8;
  int local_e4;
  float local_e0 [4];
  float local_d0;
  float local_cc;
  float fStack_c8;
  int local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_ac;
  int local_a8;
  uint local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90 [4];
  float local_80 [4];
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  undefined4 local_5c;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_34;
  float local_30;
  bool local_2c;
  float local_28;
  float *local_24;
  float local_20;
  
  local_6c = ((float)param_1[0x11] + param_2[1]) * (float)param_1[0xd] + DAT_009d81fc;
  local_64 = ((float)param_1[0x13] + param_2[3]) * (float)param_1[0xf] + DAT_009d81fc;
  local_a0 = (float)param_1[0xc] * *param_2;
  local_e0[0] = (float)(int)(short)((uint)(((float)param_1[0x10] + *param_2) * (float)param_1[0xc] +
                                          DAT_009d81fc) >> 6);
  local_e0[2] = (float)(int)(short)((uint)(((float)param_1[0x12] + param_2[2]) * (float)param_1[0xe]
                                          + DAT_009d81fc) >> 6);
  local_98 = (float)param_1[0xe] * param_2[2];
  local_c0 = param_2[4] * (float)param_1[0xc];
  local_b8 = param_2[6] * (float)param_1[0xe];
  local_94 = (float)param_1[0xd] * param_2[1];
  local_b4 = param_2[5] * (float)param_1[0xd];
  if ((char)param_1[5] == '\0') {
    local_9c = local_98 + local_a0;
    local_bc = local_b8 + local_c0;
  }
  else {
    local_9c = local_a0 - local_98;
    local_bc = local_c0 - local_b8;
  }
  fVar5 = local_c0 - local_a0;
  local_20 = ABS(fVar5);
  if (_DAT_00a0d978 <= local_20) {
    local_70 = g_flOne / fVar5;
    if (g_flZero <= fVar5) {
      local_e0[0] = (float)((int)local_e0[0] + 1);
      local_80[0] = local_70;
      local_ac = 1.4013e-45;
    }
    else {
      local_ac = -NAN;
      local_80[0] = -local_70;
    }
    local_90[0] = ((float)(int)local_e0[0] - local_a0) * local_70;
  }
  else {
    local_80[0] = 0.0;
    local_ac = -NAN;
    local_90[0] = 3.4028235e+38;
  }
  fVar6 = local_e0[0];
  fVar5 = local_bc - local_9c;
  if (_DAT_00a0d978 <= ABS(fVar5)) {
    local_90[1] = g_flOne / fVar5;
    if (g_flZero <= fVar5) {
      local_80[1] = local_90[1];
      local_e0[1] = (float)((int)local_e0[1] + 1);
      local_a8 = 1;
    }
    else {
      local_a8 = -1;
      local_80[1] = -local_90[1];
    }
    local_90[1] = ((float)(int)local_e0[1] - local_9c) * local_90[1];
  }
  else {
    local_80[1] = 0.0;
    local_a8 = -1;
    local_90[1] = 3.4028235e+38;
  }
  fVar5 = local_b8 - local_98;
  local_34 = ABS(fVar5);
  if (_DAT_00a0d978 <= local_34) {
    local_68 = g_flOne / fVar5;
    if (g_flZero <= fVar5) {
      local_80[2] = local_68;
      local_e0[2] = (float)((int)local_e0[2] + 1);
      local_a4 = 1;
    }
    else {
      local_a4 = 0xffffffff;
      local_80[2] = -local_68;
    }
    local_90[2] = ((float)(int)local_e0[2] - local_98) * local_68;
  }
  else {
    local_a4 = 0xffffffff;
    local_80[2] = 0.0;
    local_90[2] = 3.4028235e+38;
  }
  fVar4 = local_e0[2];
  if (((g_flZero != local_80[2] + local_80[0]) && (g_flZero != local_80[1] + local_80[0])) &&
     (g_flZero != local_80[1] + local_80[2])) {
    local_4c = local_9c;
    local_90[3] = local_e0[0];
    if ((int)local_ac < 1) {
      fVar5 = (float)(param_1[3] + -2);
      if ((int)fVar5 < (int)local_e0[0]) {
        fVar4 = (float)(param_1[3] + -1);
        if (fVar4 < local_c0) {
          return;
        }
        fVar4 = (local_a0 - fVar4) * local_80[0];
LAB_006cbd7b:
        local_e0[0] = fVar5;
        local_90[0] = local_80[0] + fVar4;
        local_4c = local_bc * fVar4 + local_9c * (g_flOne - fVar4);
        fVar5 = local_b8 * fVar4 + local_98 * (g_flOne - fVar4);
        local_ec = fVar4 * local_34;
        local_e8 = (float)(int)ROUND(local_ec);
        iVar3 = (int)local_e0[2] + -2 + (int)local_e8 * local_a4;
        if ((float)iVar3 < fVar5 != ((float)iVar3 == fVar5)) {
          do {
            iVar3 = iVar3 + 1;
          } while ((float)iVar3 < fVar5 != ((float)iVar3 == fVar5));
        }
        local_e0[2] = (float)(iVar3 + ((int)local_a4 >> 1));
        local_90[2] = ((float)(int)local_e0[2] - local_98) * local_68;
      }
    }
    else if ((int)local_e0[0] < 1) {
      if (local_c0 < g_flZero) {
        return;
      }
      fVar5 = 1.4013e-45;
      fVar4 = -(local_80[0] * local_a0);
      goto LAB_006cbd7b;
    }
    if ((int)local_a4 < 1) {
      fVar5 = (float)(param_1[4] + -2);
      if ((int)fVar5 < (int)local_e0[2]) {
        fVar4 = (float)(param_1[4] + -1);
        if (fVar4 < local_b8) {
          return;
        }
        local_e0[2] = fVar5;
        fVar5 = (local_98 - fVar4) * local_80[2];
        goto LAB_006cbeab;
      }
    }
    else if ((int)local_e0[2] < 1) {
      if (local_b8 < g_flZero) {
        return;
      }
      local_e0[2] = 1.4013e-45;
      fVar5 = -(local_80[2] * local_98);
LAB_006cbeab:
      local_90[2] = local_80[2] + fVar5;
      local_50 = (g_flOne - fVar5) * local_a0 + local_c0 * fVar5;
      local_4c = local_bc * fVar5 + local_9c * (g_flOne - fVar5);
      local_ec = local_20 * fVar5;
      local_e8 = (float)(int)ROUND(local_ec);
      iVar3 = (int)local_e8 * (int)local_ac + -2 + (int)fVar6;
      if ((float)iVar3 < local_50 != ((float)iVar3 == local_50)) {
        do {
          iVar3 = iVar3 + 1;
        } while ((float)iVar3 < local_50 != ((float)iVar3 == local_50));
      }
      local_e0[0] = (float)(iVar3 + ((int)local_ac >> 1));
      local_90[0] = ((float)(int)local_e0[0] - local_a0) * local_70;
    }
    if ((uint)param_1[3] <= (uint)local_e0[0]) {
      return;
    }
    if ((uint)param_1[3] <= (uint)((int)local_e0[0] - (int)local_ac)) {
      return;
    }
    bVar7 = local_80[1] == g_flZero;
    bVar2 = -1 < (int)(local_a4 ^ (uint)local_ac) != ((char)param_1[5] != '\0');
    local_2c = bVar2;
    if (bVar7) {
      local_2c = false;
    }
    bVar1 = true;
    local_cc = 2.8026e-45;
    fVar5 = local_e0[2];
    if ((char)param_1[5] != '\0') {
      fVar5 = (float)-(int)local_e0[2];
    }
    local_e0[1] = (float)((int)local_e0[0] + (int)fVar5);
    if (bVar7 || !bVar2) {
      if (g_flZero < (float)local_a8 * (local_4c - (float)(int)local_e0[1])) {
        bVar1 = false;
        local_cc = 0.0;
        iVar3 = local_a8;
        goto LAB_006cc024;
      }
    }
    else if (ABS(local_4c - (float)(int)local_e0[1]) <= g_flOne) {
      bVar1 = false;
      local_cc = 0.0;
    }
    else {
      iVar3 = -local_a8;
LAB_006cc024:
      local_e0[1] = (float)((int)local_e0[1] + iVar3);
    }
    if (local_80[1] == g_flZero) {
      local_90[1] = 3.4028235e+38;
    }
    else {
      local_90[1] = ((float)(int)local_e0[1] - local_9c) * (float)local_a8 * local_80[1];
    }
    fVar5 = DAT_00aaa63c;
    if (local_80[0] != g_flZero) {
      fVar5 = local_90[0] - local_80[0];
    }
    if (local_80[1] == g_flZero) {
      local_4c = -3.4028235e+38;
    }
    else {
      local_4c = local_90[1] - local_80[1];
    }
    if (local_80[2] == g_flZero) {
      local_48 = -3.4028235e+38;
    }
    else {
      local_48 = local_90[2] - local_80[2];
    }
    if (bVar7 || !bVar2) {
      if (local_34 <= local_20) {
        if (bVar1) {
          local_e4 = 0;
          goto LAB_006cc16d;
        }
        local_e4 = 1;
        if (local_48 < local_4c) goto LAB_006cc16d;
      }
      else if (!bVar1) {
        if (local_4c < fVar5) {
          local_e4 = 0;
          goto LAB_006cc16d;
        }
        goto LAB_006cc0fc;
      }
    }
    else {
      if (!bVar1) {
LAB_006cc0fc:
        local_e4 = 1;
        goto LAB_006cc16d;
      }
      if (local_48 < fVar5) {
        local_e4 = 0;
        goto LAB_006cc16d;
      }
    }
    local_e4 = 2;
LAB_006cc16d:
    local_e0[local_e4] = (float)((int)local_e0[local_e4] - (int)(&local_ac)[local_e4]);
    local_90[local_e4] = local_90[local_e4] - local_80[local_e4];
    local_30 = 3.4028235e+38;
    local_28 = 0.0;
    local_d0 = -1.0;
    if ((uint)param_1[3] <= (uint)local_e0[0]) {
      return;
    }
    do {
      fVar6 = local_e0[2];
      fVar5 = local_e0[0];
      if ((uint)param_1[4] <= (uint)local_e0[2]) {
        return;
      }
      if ((float)param_4[1] < local_d0) {
        return;
      }
      local_24 = local_90 + local_e4;
      local_e0[3] = local_90[local_e4];
      fVar4 = g_flOne - local_e0[3];
      local_c4 = (int)local_e0[0] - (int)local_ac;
      local_50 = local_c0 * local_e0[3] + local_a0 * fVar4;
      local_48 = local_98 * fVar4 + local_b8 * local_e0[3];
      local_44 = local_94 * fVar4 + local_b4 * local_e0[3];
      if (local_e4 == 0) {
        fVar8 = (float10)(**(code **)(*param_1 + 0x30))(local_e0[0],(int)local_e0[2] - local_a4);
        fVar6 = local_e0[0];
        fStack_f4 = (float)fVar8;
        fVar8 = (float10)(**(code **)(*param_1 + 0x30))(fVar5,local_e0[0]);
        fVar9 = ((float10)local_ec - fVar8) * ABS((float10)local_48 - (float10)(int)local_e0[2]);
      }
      else if (local_e4 == 2) {
        fVar8 = (float10)(**(code **)(*param_1 + 0x30))(local_c4,local_e0[2]);
        fStack_f4 = (float)fVar8;
        fVar8 = (float10)(**(code **)(*param_1 + 0x30))(fVar5,fVar6);
        fVar9 = ((float10)local_ec - fVar8) * ABS((float10)local_50 - (float10)(int)local_e0[0]);
      }
      else {
        local_e8 = ABS(local_50 - (float)(int)local_e0[0]);
        if (local_2c == false) {
          fVar5 = (float)((int)local_e0[2] - local_a4);
          fVar4 = local_e0[2];
        }
        else {
          fVar5 = local_e0[2];
          fVar4 = (float)((int)local_e0[2] - local_a4);
        }
        fVar8 = (float10)(**(code **)(*param_1 + 0x30))(local_c4,fVar5);
        fStack_f4 = (float)fVar8;
        fVar8 = (float10)(**(code **)(*param_1 + 0x30))(local_e8,fVar4);
        fVar9 = ((float10)local_ec - fVar8) * (float10)local_e8;
      }
      fVar9 = fVar9 + fVar8;
      if ((fVar9 <= (float10)local_44) || (local_28 < local_30)) {
LAB_006cc64e:
        local_30 = (float)fVar9;
        local_28 = local_44;
        local_d0 = local_e0[3];
      }
      else {
        if (local_d0 < g_flZero) {
          fVar8 = (float10)local_e0[3] / ((float10)local_e0[3] - (float10)local_d0);
          fVar8 = (float10)local_94 -
                  (fVar8 * (float10)local_30 + ((float10)g_flOne - fVar8) * fVar9);
          if (fVar8 < (float10)g_flZero) goto LAB_006cc64e;
          fVar8 = (fVar8 / (fVar8 - ((float10)local_44 - fVar9))) * (float10)local_e0[3];
        }
        else {
          fVar8 = ((float10)local_e0[3] - (float10)local_d0) *
                  (((float10)local_28 - (float10)local_30) /
                  (((float10)local_28 - (float10)local_30) - ((float10)local_44 - fVar9))) +
                  (float10)local_d0;
        }
        fStack_c8 = (float)fVar8;
        local_d0 = local_e0[3];
        local_30 = (float)fVar9;
        local_28 = local_44;
        if ((float)param_4[1] < fStack_c8) {
          return;
        }
        fVar5 = (float)((int)local_e0[2] - local_a4);
        local_5c = 0x3f800000;
        local_64 = 0.0;
        local_6c = 1.0;
        if (local_2c == false) {
          fVar4 = fVar5;
          fVar8 = (float10)(**(code **)(*param_1 + 0x30))(local_c4);
          local_90[1] = (float)fVar8;
          (**(code **)(*param_1 + 0x30))(local_e8,fVar6);
          if ((fStack_f4 == 0.0) || ((fStack_f4 == 1.4013e-45 && (local_30 < local_44)))) {
            fVar8 = (float10)(**(code **)(*param_1 + 0x30))(fStack_f0,fVar5);
            unaff_EDI = (float)fVar8;
            fVar8 = (float10)local_9c - (float10)unaff_EDI;
            fVar4 = unaff_EDI - fVar4;
            goto LAB_006cc529;
          }
          fVar8 = (float10)(**(code **)(*param_1 + 0x30))(local_e0[3],fVar6);
          unaff_EDI = (float)fVar8;
          fVar8 = fVar8 - (float10)fVar4;
          bVar2 = SBORROW4((int)fVar6,(int)fVar5);
          bVar7 = (int)fVar6 - (int)fVar5 < 0;
          fVar4 = local_9c - unaff_EDI;
        }
        else {
          fVar8 = (float10)(**(code **)(*param_1 + 0x30))(local_e0[0]);
          fStack_f0 = (float)fVar8;
          fVar8 = (float10)(**(code **)(*param_1 + 0x30))(local_cc,fVar6);
          local_94 = (float)fVar8;
          if (fStack_f4 == 1.4013e-45) {
            fVar8 = (float10)(**(code **)(*param_1 + 0x30))(local_e0[3],fVar5);
            local_e0[1] = (float)fVar8;
            fVar8 = fVar8 - (float10)unaff_EDI;
            fVar4 = local_e0[1] - local_9c;
LAB_006cc529:
            bVar2 = SBORROW4((int)fVar5,(int)fVar6);
            bVar7 = (int)fVar5 - (int)fVar6 < 0;
          }
          else {
            fVar8 = (float10)(**(code **)(*param_1 + 0x30))(fStack_f0,fVar6);
            local_e0[1] = (float)fVar8;
            bVar2 = SBORROW4((int)fVar6,(int)fVar5);
            bVar7 = (int)fVar6 - (int)fVar5 < 0;
            fVar8 = (float10)local_9c - (float10)local_e0[1];
            fVar4 = unaff_EDI - local_e0[1];
          }
        }
        local_90[2] = (float)((float10)local_c4 * fVar8) * (float)param_1[0xc];
        local_90[3] = local_90[3] * (float)param_1[0xd];
        local_80[0] = (float)(int)local_bc * fVar4 * (float)param_1[0xe];
        fVar10 = local_90[2] * local_90[2] + local_90[3] * local_90[3] + local_80[0] * local_80[0];
        fVar4 = g_flZero;
        if (fVar10 != g_flZero) {
          fVar4 = g_flOne / SQRT(fVar10);
        }
        local_90[2] = local_90[2] * fVar4;
        local_80[3] = local_e0[0];
        local_90[3] = local_90[3] * fVar4;
        local_80[0] = local_80[0] * fVar4;
        local_80[2] = (float)((((fVar5 != fVar6 && bVar2 == bVar7) != ((char)param_1[5] != '\0')) -
                              2) + (((((int)fStack_f0 - ((int)local_bc >> 1)) + -1) * 0x8000 -
                                    (local_c4 >> 1)) + unaff_EBX) * 2);
        local_80[1] = local_80[1] * (float)param_1[0xf] * fVar4;
        (**(code **)*param_4)(param_3,local_90 + 2);
      }
      local_e0[local_e4] = (float)((int)local_e0[local_e4] + (int)(&local_ac)[local_e4]);
      local_cc = (float)((uint)local_cc ^ 2);
      *local_24 = local_80[local_e4] + *local_24;
      if (local_2c == false) {
        if (local_34 <= local_20) {
          if (local_cc == 0.0) {
            local_e4 = 1;
            if (local_90[2] <= local_90[1]) goto LAB_006cc723;
          }
          else {
            local_e4 = 0;
          }
        }
        else if (local_cc == 0.0) {
          if (local_90[1] <= local_90[0]) goto LAB_006cc6ad;
          local_e4 = 0;
        }
        else {
LAB_006cc723:
          local_e4 = 2;
        }
      }
      else if (local_cc == 0.0) {
LAB_006cc6ad:
        local_e4 = 1;
      }
      else {
        if (local_90[2] <= local_90[0]) goto LAB_006cc723;
        local_e4 = 0;
      }
      if ((uint)param_1[3] <= (uint)local_e0[0]) {
        return;
      }
    } while( true );
  }
  if ((uint)(param_1[3] + -1) <= (uint)local_e0[0]) {
    return;
  }
  if ((uint)(param_1[4] + -1) <= (uint)local_e0[2]) {
    return;
  }
  local_5c = 0x3f800000;
  local_e0[3] = local_98 - (float)(int)local_e0[2];
  local_70 = 1.0;
  local_6c = 1.0;
  local_68 = 1.0;
  local_64 = 1.0;
  local_d0 = local_a0 - (float)(int)local_e0[0];
  if ((char)param_1[5] == '\0') {
    fVar10 = local_e0[2];
    fVar8 = (float10)(**(code **)(*param_1 + 0x30))((int)local_e0[0] + 1);
    local_d0 = (float)fVar8;
    (**(code **)(*param_1 + 0x30))(fVar6,(int)fVar4 + 1);
    if (local_e0[0] + fVar5 <= g_flOne) {
      fVar8 = (float10)(**(code **)(*param_1 + 0x30))(fVar6,fVar4);
      local_90[2] = (float)((float10)local_e0[0] - fVar8);
      fVar10 = (float)((float10)fVar10 - fVar8);
      fVar8 = (float10)fVar10 * (float10)local_ec + (float10)local_90[2] * (float10)local_e8 + fVar8
      ;
      goto LAB_006cc923;
    }
    fVar8 = (float10)(**(code **)(*param_1 + 0x30))((int)fVar6 + 1,(int)fVar4 + 1);
    local_90[2] = (float)(fVar8 - (float10)fVar10);
    fVar10 = (float)(fVar8 - (float10)local_e0[0]);
    fVar8 = (float10)fVar10 * (float10)local_ec +
            ((float10)local_e8 - (float10)g_flOne) * (float10)local_90[2] + (float10)local_e0[0];
  }
  else {
    fVar8 = (float10)(**(code **)(*param_1 + 0x30))(local_e0[0]);
    local_e0[3] = (float)fVar8;
    (**(code **)(*param_1 + 0x30))((int)fVar6 + 1,(int)fVar4 + 1);
    if (local_e0[0] <= fVar5) {
      fVar8 = (float10)(**(code **)(*param_1 + 0x30))(fVar6,(int)fVar4 + 1);
      local_90[2] = (float)((float10)unaff_EDI - fVar8);
      fVar10 = (float)(fVar8 - (float10)fVar5);
      fVar8 = (float10)fVar10 * (float10)local_ec + (float10)local_90[2] * (float10)local_e8 +
              (float10)fVar5;
LAB_006cc923:
      iVar3 = 0;
      goto LAB_006cc925;
    }
    fVar8 = (float10)(**(code **)(*param_1 + 0x30))((int)fVar6 + 1,fVar4);
    local_90[2] = (float)(fVar8 - (float10)fVar5);
    fVar10 = (float)((float10)unaff_EDI - fVar8);
    fVar8 = (float10)local_90[2] * (float10)local_e8 + (float10)fVar10 * (float10)local_ec +
            (float10)fVar5;
  }
  iVar3 = 1;
LAB_006cc925:
  local_90[2] = -local_90[2];
  local_80[3] = (float)((float10)local_ac - fVar8);
  local_e0[0] = (float)((float10)local_cc - fVar8);
  if ((((local_e0[0] <= local_80[3]) && (g_flZero <= local_80[3])) && (local_e0[0] < g_flZero)) &&
     (local_80[3] = local_80[3] / (local_80[3] - local_e0[0]), local_80[3] < (float)param_4[1])) {
    local_90[2] = local_90[2] * (float)param_1[0xc];
    local_90[3] = local_90[3] * (float)param_1[0xd];
    local_80[0] = -fVar10 * (float)param_1[0xe];
    fVar10 = local_90[3] * local_90[3] + local_80[0] * local_80[0] + local_90[2] * local_90[2];
    fVar5 = g_flZero;
    if (fVar10 != g_flZero) {
      fVar5 = g_flOne / SQRT(fVar10);
    }
    local_90[2] = fVar5 * local_90[2];
    local_80[2] = (float)(iVar3 + ((int)fVar4 * 0x8000 + (int)fVar6) * 2);
    local_90[3] = local_90[3] * fVar5;
    local_80[0] = local_80[0] * fVar5;
    local_80[1] = local_80[1] * (float)param_1[0xf] * fVar5;
    (**(code **)*param_4)(param_3,local_90 + 2);
    return;
  }
  return;
}
```
