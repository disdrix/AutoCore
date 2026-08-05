# Annotated low-level: FUN_006ccbf0

| Field | Value |
|---|---|
| Stable ID | `aa_006ccbf0` |
| VA | `0x006ccbf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006ccbf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_006ccbf0(int *param_1,float *param_2,undefined4 param_3,undefined4 *param_4)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float unaff_ESI;
  float unaff_EDI;
  float fVar6;
  float fVar7;
  bool bVar8;
  float10 fVar9;
  float10 fVar10;
  float fStack_134;
  float fStack_130;
  float fStack_12c;
  float local_128;
  float local_124;
  int local_120;
  float local_11c;
  float local_118 [4];
  undefined3 uStack_108;
  char local_105;
  float fStack_104;
  uint local_100;
  float local_fc;
  int local_f8;
  float local_f4;
  float local_f0;
  float local_ec;
  float local_e8;
  float local_e4;
  float local_dc;
  int local_d8;
  uint local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  float local_bc [7];
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  undefined4 local_7c;
  float fStack_70;
  bool local_64;
  float local_60;
  float local_5c;
  float local_58;
  float *local_54;
  float local_50;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  
  local_38 = param_2[2];
  fVar6 = param_2[0xc];
  local_30 = param_2[4];
  local_34 = param_2[3];
  local_28 = param_2[6];
  if (g_flZero < (float)param_1[9]) {
    fVar6 = -fVar6;
  }
  local_3c = param_2[1] + fVar6;
  local_58 = param_2[0xd];
  _uStack_108 = (float)CONCAT13(1,uStack_108);
  local_2c = param_2[5] + fVar6;
  local_118[0] = (float)(int)(short)((uint)((*param_2 + (float)param_1[0x10]) * (float)param_1[0xc]
                                           + DAT_009d81fc) >> 6);
  local_8c = (local_3c + (float)param_1[0x11]) * (float)param_1[0xd] + DAT_009d81fc;
  local_84 = (param_2[3] + (float)param_1[0x13]) * (float)param_1[0xf] + DAT_009d81fc;
  fVar7 = *param_2 * (float)param_1[0xc];
  local_118[2] = (float)(int)(short)((uint)((local_38 + (float)param_1[0x12]) * (float)param_1[0xe]
                                           + DAT_009d81fc) >> 6);
  local_d0 = fVar7;
  local_c8 = local_38 * (float)param_1[0xe];
  local_f0 = param_2[4] * (float)param_1[0xc];
  local_e8 = param_2[6] * (float)param_1[0xe];
  local_c4 = local_3c * (float)param_1[0xd];
  local_e4 = (param_2[5] + fVar6) * (float)param_1[0xd];
  if ((char)param_1[5] == '\0') {
    local_cc = local_c8 + fVar7;
    local_ec = local_e8 + local_f0;
  }
  else {
    local_cc = fVar7 - local_c8;
    local_ec = local_f0 - local_e8;
  }
  fVar6 = local_f0 - fVar7;
  local_50 = ABS(fVar6);
  if (_DAT_00a0d978 <= local_50) {
    local_90 = g_flOne / fVar6;
    if (g_flZero <= fVar6) {
      local_118[0] = (float)((int)local_118[0] + 1);
      local_bc[3] = local_90;
      local_dc = 1.4013e-45;
    }
    else {
      local_dc = -NAN;
      local_bc[3] = -local_90;
    }
    local_bc[0] = ((float)(int)local_118[0] - fVar7) * local_90;
  }
  else {
    local_bc[3] = 0.0;
    local_dc = -NAN;
    local_bc[0] = 3.4028235e+38;
  }
  fVar5 = local_118[0];
  fVar6 = local_ec - local_cc;
  if (_DAT_00a0d978 <= ABS(fVar6)) {
    local_bc[1] = g_flOne / fVar6;
    if (g_flZero <= fVar6) {
      local_bc[4] = local_bc[1];
      local_118[1] = (float)((int)local_118[1] + 1);
      local_d8 = 1;
    }
    else {
      local_d8 = -1;
      local_bc[4] = -local_bc[1];
    }
    local_bc[1] = ((float)(int)local_118[1] - local_cc) * local_bc[1];
  }
  else {
    local_bc[4] = 0.0;
    local_d8 = -1;
    local_bc[1] = 3.4028235e+38;
  }
  fVar6 = local_e8 - local_c8;
  local_60 = ABS(fVar6);
  if (_DAT_00a0d978 <= local_60) {
    local_88 = g_flOne / fVar6;
    if (g_flZero <= fVar6) {
      local_bc[5] = local_88;
      local_118[2] = (float)((int)local_118[2] + 1);
      local_d4 = 1;
    }
    else {
      local_d4 = 0xffffffff;
      local_bc[5] = -local_88;
    }
    local_bc[2] = ((float)(int)local_118[2] - local_c8) * local_88;
  }
  else {
    local_d4 = 0xffffffff;
    local_bc[5] = 0.0;
    local_bc[2] = 3.4028235e+38;
  }
  fVar6 = local_118[2];
  if (((g_flZero != local_bc[5] + local_bc[3]) && (g_flZero != local_bc[4] + local_bc[3])) &&
     (g_flZero != local_bc[4] + local_bc[5])) {
    local_9c = local_cc;
    local_f4 = local_118[0];
    if ((int)local_dc < 1) {
      fVar6 = (float)(param_1[3] + -2);
      if ((int)fVar6 < (int)local_118[0]) {
        fVar4 = (float)(param_1[3] + -1);
        if (fVar4 < local_f0) {
          return;
        }
        fVar4 = (fVar7 - fVar4) * local_bc[3];
LAB_006cd04e:
        local_118[0] = fVar6;
        local_bc[0] = local_bc[3] + fVar4;
        local_9c = local_cc * (g_flOne - fVar4) + local_ec * fVar4;
        fVar6 = local_c8 * (g_flOne - fVar4) + local_e8 * fVar4;
        local_128 = fVar4 * local_60;
        iVar3 = (int)local_118[2] + -2 + (int)ROUND(local_128) * local_d4;
        if ((float)iVar3 < fVar6 != ((float)iVar3 == fVar6)) {
          do {
            iVar3 = iVar3 + 1;
          } while ((float)iVar3 < fVar6 != ((float)iVar3 == fVar6));
        }
        local_118[2] = (float)(iVar3 + ((int)local_d4 >> 1));
        local_bc[2] = ((float)(int)local_118[2] - local_c8) * local_88;
      }
    }
    else if ((int)local_118[0] < 1) {
      if (local_f0 < g_flZero) {
        return;
      }
      fVar6 = 1.4013e-45;
      fVar4 = -(local_bc[3] * fVar7);
      goto LAB_006cd04e;
    }
    if ((int)local_d4 < 1) {
      fVar6 = (float)(param_1[4] + -2);
      if ((int)fVar6 < (int)local_118[2]) {
        fVar4 = (float)(param_1[4] + -1);
        if (fVar4 < local_e8) {
          return;
        }
        local_118[2] = fVar6;
        fVar6 = (local_c8 - fVar4) * local_bc[5];
        goto LAB_006cd17c;
      }
    }
    else if ((int)local_118[2] < 1) {
      if (local_e8 < g_flZero) {
        return;
      }
      local_118[2] = 1.4013e-45;
      fVar6 = -(local_bc[5] * local_c8);
LAB_006cd17c:
      local_bc[2] = local_bc[5] + fVar6;
      local_a0 = (g_flOne - fVar6) * fVar7 + local_f0 * fVar6;
      local_9c = local_cc * (g_flOne - fVar6) + local_ec * fVar6;
      local_128 = local_50 * fVar6;
      iVar3 = (int)ROUND(local_128) * (int)local_dc + -2 + (int)fVar5;
      if ((float)iVar3 < local_a0 != ((float)iVar3 == local_a0)) {
        do {
          iVar3 = iVar3 + 1;
        } while ((float)iVar3 < local_a0 != ((float)iVar3 == local_a0));
      }
      local_118[0] = (float)(iVar3 + ((int)local_dc >> 1));
      local_bc[0] = ((float)(int)local_118[0] - fVar7) * local_90;
    }
    if ((uint)param_1[3] <= (uint)local_118[0]) {
      return;
    }
    if ((uint)param_1[3] <= (uint)((int)local_118[0] - (int)local_dc)) {
      return;
    }
    bVar8 = local_bc[4] == g_flZero;
    bVar2 = -1 < (int)(local_d4 ^ (uint)local_dc) != ((char)param_1[5] != '\0');
    local_64 = bVar2;
    if (bVar8) {
      local_64 = false;
    }
    bVar1 = true;
    local_100 = 2;
    fVar6 = local_118[2];
    if ((char)param_1[5] != '\0') {
      fVar6 = (float)-(int)local_118[2];
    }
    local_118[1] = (float)((int)local_118[0] + (int)fVar6);
    if (bVar8 || !bVar2) {
      if (g_flZero < (float)local_d8 * (local_9c - (float)(int)local_118[1])) {
        bVar1 = false;
        local_100 = 0;
        iVar3 = local_d8;
        goto LAB_006cd2f7;
      }
    }
    else if (ABS(local_9c - (float)(int)local_118[1]) <= g_flOne) {
      bVar1 = false;
      local_100 = 0;
    }
    else {
      iVar3 = -local_d8;
LAB_006cd2f7:
      local_118[1] = (float)((int)local_118[1] + iVar3);
    }
    if (local_bc[4] == g_flZero) {
      local_bc[1] = 3.4028235e+38;
    }
    else {
      local_bc[1] = ((float)(int)local_118[1] - local_cc) * (float)local_d8 * local_bc[4];
    }
    fVar6 = DAT_00aaa63c;
    if (local_bc[3] != g_flZero) {
      fVar6 = local_bc[0] - local_bc[3];
    }
    if (local_bc[4] == g_flZero) {
      local_9c = -3.4028235e+38;
    }
    else {
      local_9c = local_bc[1] - local_bc[4];
    }
    if (local_bc[5] == g_flZero) {
      local_98 = -3.4028235e+38;
    }
    else {
      local_98 = local_bc[2] - local_bc[5];
    }
    if (bVar8 || !bVar2) {
      if (local_60 <= local_50) {
        if (bVar1) {
          local_120 = 0;
          goto LAB_006cd44f;
        }
        local_120 = 1;
        if (local_98 < local_9c) goto LAB_006cd44f;
      }
      else if (!bVar1) {
        if (local_9c < fVar6) {
          local_120 = 0;
          goto LAB_006cd44f;
        }
        goto LAB_006cd3de;
      }
    }
    else {
      if (!bVar1) {
LAB_006cd3de:
        local_120 = 1;
        goto LAB_006cd44f;
      }
      if (local_98 < fVar6) {
        local_120 = 0;
        goto LAB_006cd44f;
      }
    }
    local_120 = 2;
LAB_006cd44f:
    fVar6 = local_bc[local_120 + 3];
    local_118[local_120] = (float)((int)local_118[local_120] - (int)(&local_dc)[local_120]);
    local_bc[local_120] = local_bc[local_120] - fVar6;
    local_11c = 3.4028235e+38;
    local_5c = 0.0;
    local_118[3] = -1.0;
    if ((uint)param_1[3] <= (uint)local_118[0]) {
      return;
    }
    do {
      fVar7 = local_118[2];
      fVar6 = local_118[0];
      if ((uint)param_1[4] <= (uint)local_118[2]) {
        return;
      }
      if ((float)param_4[1] < local_118[3]) {
        return;
      }
      local_54 = local_bc + local_120;
      local_fc = local_bc[local_120];
      fVar5 = g_flOne - local_fc;
      local_f8 = (int)local_118[0] - (int)local_dc;
      local_a0 = fVar5 * local_d0 + local_f0 * local_fc;
      local_98 = local_e8 * local_fc + local_c8 * fVar5;
      local_94 = local_e4 * local_fc + local_c4 * fVar5;
      if (local_120 == 0) {
        fVar9 = (float10)(**(code **)(*param_1 + 0x30))(local_118[0],(int)local_118[2] - local_d4);
        fVar7 = local_118[0];
        fStack_130 = (float)fVar9;
        fVar9 = (float10)(**(code **)(*param_1 + 0x30))(fVar6,local_118[0]);
        fVar10 = ((float10)local_128 - fVar9) * ABS((float10)local_98 - (float10)(int)local_118[2]);
      }
      else if (local_120 == 2) {
        fVar9 = (float10)(**(code **)(*param_1 + 0x30))(local_f8,local_118[2]);
        fStack_130 = (float)fVar9;
        fVar9 = (float10)(**(code **)(*param_1 + 0x30))(fVar6,fVar7);
        fVar10 = ((float10)local_128 - fVar9) * ABS((float10)local_a0 - (float10)(int)local_118[0]);
      }
      else {
        fVar6 = local_a0 - (float)(int)local_118[0];
        if (local_64 == false) {
          fVar5 = (float)((int)local_118[2] - local_d4);
          fVar4 = local_118[2];
        }
        else {
          fVar5 = local_118[2];
          fVar4 = (float)((int)local_118[2] - local_d4);
        }
        fVar9 = (float10)(**(code **)(*param_1 + 0x30))(local_f8,fVar5);
        fStack_130 = (float)fVar9;
        fVar9 = (float10)(**(code **)(*param_1 + 0x30))(local_120,fVar4);
        fVar10 = ((float10)local_128 - fVar9) * (float10)ABS(fVar6);
      }
      fStack_104 = (float)(fVar10 + fVar9);
      if (local_105 == '\0') {
        if ((local_94 >= fStack_104) || (local_5c < local_11c)) goto LAB_006cd9b2;
LAB_006cd69b:
        if (local_118[3] < g_flZero) {
          fVar9 = (float10)local_fc / ((float10)local_fc - (float10)local_118[3]);
          fVar9 = (float10)local_c4 -
                  (fVar9 * (float10)local_11c + ((float10)g_flOne - fVar9) * (float10)fStack_104);
          if (fVar9 < (float10)g_flZero) {
            if (local_105 == '\0') goto LAB_006cd9b2;
            fVar9 = (float10)g_flZero;
          }
          fVar9 = (fVar9 / (fVar9 - ((float10)local_94 - (float10)fStack_104))) * (float10)local_fc;
        }
        else {
          fVar9 = ((float10)local_fc - (float10)local_118[3]) *
                  (((float10)local_5c - (float10)local_11c) /
                  (((float10)local_5c - (float10)local_11c) -
                  ((float10)local_94 - (float10)fStack_104))) + (float10)local_118[3];
        }
LAB_006cd72d:
        fVar6 = fStack_104;
        local_f4 = (float)fVar9;
        local_11c = fStack_104;
        local_5c = local_94;
        local_118[3] = local_fc;
        if ((float10)(float)param_4[1] < fVar9) {
          return;
        }
        fVar5 = (float)((int)local_118[2] - local_d4);
        local_7c = 0x3f800000;
        local_84 = 0.0;
        local_8c = 1.0;
        if (local_64 == false) {
          fVar9 = (float10)(**(code **)(*param_1 + 0x30))(local_f8,fVar5);
          local_118[3] = (float)fVar9;
          (**(code **)(*param_1 + 0x30))(local_120,fVar7);
          if ((fStack_130 == 0.0) || ((fStack_130 == 1.4013e-45 && (local_60 < fStack_70)))) {
            fVar9 = (float10)(**(code **)(*param_1 + 0x30))(local_128,fVar5);
            unaff_ESI = (float)fVar9;
            fVar9 = (float10)fVar6 - (float10)unaff_ESI;
            fVar6 = unaff_ESI - unaff_EDI;
            goto LAB_006cd882;
          }
          fVar9 = (float10)(**(code **)(*param_1 + 0x30))(_uStack_108,fVar7);
          unaff_ESI = (float)fVar9;
          fVar9 = fVar9 - (float10)unaff_EDI;
          bVar2 = SBORROW4((int)fVar7,(int)fVar5);
          bVar8 = (int)fVar7 - (int)fVar5 < 0;
          fVar6 = fVar6 - unaff_ESI;
        }
        else {
          (**(code **)(*param_1 + 0x30))(local_118[0]);
          fVar9 = (float10)(**(code **)(*param_1 + 0x30))(local_100,fVar7);
          local_118[1] = (float)fVar9;
          if (fStack_130 == 1.4013e-45) {
            fVar9 = (float10)(**(code **)(*param_1 + 0x30))(_uStack_108,fVar5);
            local_118[2] = (float)fVar9;
            fVar9 = fVar9 - (float10)unaff_ESI;
            fVar6 = local_118[2] - fVar6;
LAB_006cd882:
            bVar2 = SBORROW4((int)fVar5,(int)fVar7);
            bVar8 = (int)fVar5 - (int)fVar7 < 0;
          }
          else {
            fVar9 = (float10)(**(code **)(*param_1 + 0x30))(local_128,fVar7);
            local_118[2] = (float)fVar9;
            bVar2 = SBORROW4((int)fVar7,(int)fVar5);
            bVar8 = (int)fVar7 - (int)fVar5 < 0;
            fVar9 = (float10)fVar6 - (float10)local_118[2];
            fVar6 = unaff_ESI - local_118[2];
          }
        }
        local_bc[5] = (float)((float10)(int)local_f4 * fVar9) * (float)param_1[0xc];
        local_bc[6] = local_bc[6] * (float)param_1[0xd];
        local_a0 = (float)(int)local_ec * fVar6 * (float)param_1[0xe];
        fVar4 = local_bc[5] * local_bc[5] + local_bc[6] * local_bc[6] + local_a0 * local_a0;
        fVar6 = g_flZero;
        if (fVar4 != g_flZero) {
          fVar6 = g_flOne / SQRT(fVar4);
        }
        local_bc[5] = local_bc[5] * fVar6;
        local_94 = local_118[3];
        local_bc[6] = local_bc[6] * fVar6;
        local_a0 = local_a0 * fVar6;
        local_98 = (float)((((fVar5 != fVar7 && bVar2 == bVar8) != ((char)param_1[5] != '\0')) - 2)
                          + (((((int)local_128 - ((int)local_ec >> 1)) + -1) * 0x8000 -
                             ((int)local_f4 >> 1)) + (int)fStack_130) * 2);
        local_9c = local_9c * (float)param_1[0xf] * fVar6;
        (**(code **)*param_4)(param_3,local_bc + 5);
        if (local_105 != '\0') {
          _uStack_108 = (float)((uint)_uStack_108 & 0xffffff);
        }
      }
      else {
        if ((local_94 < fStack_104) &&
           (fVar6 = local_5c - local_11c, fVar5 = fVar6 - (local_fc - local_118[3]) * local_58,
           fVar5 < local_94 - fStack_104 == (fVar5 == local_94 - fStack_104))) {
          if (fVar6 < g_flZero == (fVar6 == g_flZero)) goto LAB_006cd69b;
          fVar9 = (float10)FUN_005ef3a0(0,local_118[3]);
          goto LAB_006cd72d;
        }
LAB_006cd9b2:
        local_5c = local_94;
        local_118[3] = local_fc;
        local_11c = fStack_104;
      }
      fVar6 = local_bc[local_120 + 3];
      local_118[local_120] = (float)((int)local_118[local_120] + (int)(&local_dc)[local_120]);
      local_100 = local_100 ^ 2;
      *local_54 = fVar6 + *local_54;
      if (local_64 == false) {
        if (local_60 <= local_50) {
          if (local_100 == 0) {
            local_120 = 1;
            if (local_bc[2] <= local_bc[1]) goto LAB_006cda9d;
          }
          else {
            local_120 = 0;
          }
        }
        else if (local_100 == 0) {
          if (local_bc[1] <= local_bc[0]) goto LAB_006cda12;
          local_120 = 0;
        }
        else {
LAB_006cda9d:
          local_120 = 2;
        }
      }
      else if (local_100 == 0) {
LAB_006cda12:
        local_120 = 1;
      }
      else {
        if (local_bc[2] <= local_bc[0]) goto LAB_006cda9d;
        local_120 = 0;
      }
      if ((uint)param_1[3] <= (uint)local_118[0]) {
        return;
      }
    } while( true );
  }
  if ((uint)(param_1[3] + -1) <= (uint)local_118[0]) {
    return;
  }
  if ((uint)(param_1[4] + -1) <= (uint)local_118[2]) {
    return;
  }
  local_7c = 0x3f800000;
  local_118[3] = local_c8 - (float)(int)local_118[2];
  local_90 = 1.0;
  local_8c = 1.0;
  local_88 = 1.0;
  local_84 = 1.0;
  fVar4 = (float)(int)local_118[0];
  if ((char)param_1[5] == '\0') {
    fVar9 = (float10)(**(code **)(*param_1 + 0x30))((int)local_118[0] + 1,local_118[2]);
    local_fc = (float)fVar9;
    (**(code **)(*param_1 + 0x30))(fVar5,(int)fVar6 + 1);
    if (fStack_12c + (fVar7 - fVar4) <= g_flOne) {
      fVar9 = (float10)(**(code **)(*param_1 + 0x30))(fVar5,fVar6);
      local_bc[5] = (float)((float10)local_118[3] - fVar9);
      fVar7 = (float)((float10)unaff_EDI - fVar9);
      fVar9 = (float10)fVar7 * (float10)local_124 + (float10)local_bc[5] * (float10)fStack_134 +
              fVar9;
      goto LAB_006cdc9d;
    }
    fVar9 = (float10)(**(code **)(*param_1 + 0x30))((int)fVar5 + 1,(int)fVar6 + 1);
    local_bc[5] = (float)(fVar9 - (float10)unaff_EDI);
    fVar7 = (float)(fVar9 - (float10)local_118[3]);
    fVar9 = (float10)fVar7 * (float10)local_124 +
            ((float10)fStack_134 - (float10)g_flOne) * (float10)local_bc[5] + (float10)local_118[3];
  }
  else {
    fVar9 = (float10)(**(code **)(*param_1 + 0x30))(local_118[0]);
    _uStack_108 = (float)fVar9;
    fVar9 = (float10)(**(code **)(*param_1 + 0x30))((int)fVar5 + 1,(int)fVar6 + 1);
    if (fStack_12c <= fVar7 - fVar4) {
      fVar10 = (float10)(**(code **)(*param_1 + 0x30))(fVar5,(int)fVar6 + 1);
      local_bc[5] = (float)((float10)unaff_ESI - fVar10);
      fVar7 = (float)(fVar10 - (float10)local_118[0]);
      fVar9 = (float10)fVar7 * (float10)local_124 + (float10)local_bc[5] * (float10)(float)fVar9 +
              (float10)local_118[0];
LAB_006cdc9d:
      iVar3 = 0;
      goto LAB_006cdc9f;
    }
    fVar10 = (float10)(**(code **)(*param_1 + 0x30))((int)fVar5 + 1,fVar6);
    local_bc[5] = (float)(fVar10 - (float10)local_118[0]);
    fVar7 = (float)((float10)unaff_ESI - fVar10);
    fVar9 = (float10)fVar7 * (float10)local_124 + (float10)local_bc[5] * (float10)(float)fVar9 +
            (float10)local_118[0];
  }
  iVar3 = 1;
LAB_006cdc9f:
  local_bc[5] = -local_bc[5];
  fVar4 = (float)((float10)local_dc - fVar9);
  local_118[0] = (float)((float10)local_fc - fVar9);
  if (local_118[0] <= fVar4) {
    if (g_flZero <= fVar4) {
      if (fVar4 < g_flZero) {
        return;
      }
      if (g_flZero <= local_118[0]) {
        return;
      }
      local_94 = fVar4 / (fVar4 - local_118[0]);
    }
    else {
      local_94 = g_flZero;
      if (fVar4 - fStack_70 < local_118[0]) {
        return;
      }
    }
    if (local_94 < (float)param_4[1]) {
      local_bc[5] = local_bc[5] * (float)param_1[0xc];
      local_bc[6] = local_bc[6] * (float)param_1[0xd];
      local_a0 = -fVar7 * (float)param_1[0xe];
      fVar4 = local_bc[6] * local_bc[6] + local_a0 * local_a0 + local_bc[5] * local_bc[5];
      fVar7 = g_flZero;
      if (fVar4 != g_flZero) {
        fVar7 = g_flOne / SQRT(fVar4);
      }
      local_bc[5] = fVar7 * local_bc[5];
      local_98 = (float)(iVar3 + ((int)fVar6 * 0x8000 + (int)fVar5) * 2);
      local_bc[6] = local_bc[6] * fVar7;
      local_a0 = local_a0 * fVar7;
      local_9c = local_9c * (float)param_1[0xf] * fVar7;
      (**(code **)*param_4)(param_3,local_bc + 5);
      return;
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
