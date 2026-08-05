# Annotated low-level: FUN_006ca1d0

| Field | Value |
|---|---|
| Stable ID | `aa_006ca1d0` |
| VA | `0x006ca1d0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006ca1d0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 * __thiscall FUN_006ca1d0(int param_1,undefined1 *param_2,float *param_3,float *param_4)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float local_8c;
  float local_88;
  undefined1 local_84 [4];
  float local_80;
  float local_7c;
  float local_78;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  undefined1 local_50 [16];
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  undefined4 local_1c;
  
  pfVar1 = (float *)(param_1 + 0x20);
  pfVar2 = (float *)(param_1 + 0x10);
  FUN_006c9e90(param_3,pfVar2,pfVar1,&local_60);
  if (*(float *)(param_1 + 0xc) <=
      SQRT((param_3[1] - local_5c) * (param_3[1] - local_5c) +
           (param_3[2] - local_58) * (param_3[2] - local_58) +
           (*param_3 - local_60) * (*param_3 - local_60))) {
    local_60 = param_3[4] - *param_3;
    local_5c = param_3[5] - param_3[1];
    local_58 = param_3[6] - param_3[2];
    local_54 = param_3[7] - param_3[3];
    local_8c = 3.4028235e+38;
    local_70 = *pfVar1 - *pfVar2;
    local_6c = *(float *)(param_1 + 0x24) - *(float *)(param_1 + 0x14);
    local_68 = *(float *)(param_1 + 0x28) - *(float *)(param_1 + 0x18);
    local_64 = *(float *)(param_1 + 0x2c) - *(float *)(param_1 + 0x1c);
    FUN_006c9c50(param_3,&local_60,pfVar2,&local_70,&local_8c,&local_88,local_84,local_50,&local_80)
    ;
    if (local_8c <= *(float *)(param_1 + 0xc) * *(float *)(param_1 + 0xc)) {
      fVar3 = local_6c * local_6c + local_68 * local_68 + local_70 * local_70;
      if (fVar3 <= _DAT_00a0d784) {
        local_78 = 0.0;
        local_7c = 0.0;
        local_80 = 0.0;
        fVar3 = g_flZero;
      }
      else {
        fVar3 = SQRT(fVar3);
        local_78 = g_flOne / fVar3;
        local_80 = local_70 * local_78;
        local_7c = local_6c * local_78;
        local_78 = local_68 * local_78;
      }
      fVar5 = -(local_7c * local_5c + local_78 * local_58 + local_80 * local_60);
      local_60 = local_80 * fVar5 + local_60;
      local_5c = local_7c * fVar5 + local_5c;
      local_58 = local_78 * fVar5 + local_58;
      fVar5 = local_5c * local_5c + local_58 * local_58 + local_60 * local_60;
      fVar6 = g_flZero;
      if (fVar5 != g_flZero) {
        fVar6 = g_flOne / SQRT(fVar5);
      }
      local_88 = local_88 -
                 fVar6 * SQRT(*(float *)(param_1 + 0xc) * *(float *)(param_1 + 0xc) - local_8c);
      if (local_88 <= g_flOne) {
        fVar4 = local_80 * *pfVar2 +
                local_7c * *(float *)(param_1 + 0x14) + local_78 * *(float *)(param_1 + 0x18);
        fVar7 = g_flOne - local_88;
        fVar5 = local_88 * param_3[4] + fVar7 * *param_3;
        fVar6 = fVar7 * param_3[1] + local_88 * param_3[5];
        local_58 = fVar7 * param_3[2] + local_88 * param_3[6];
        local_54 = fVar7 * param_3[3] + local_88 * param_3[7];
        local_8c = (fVar6 * local_7c + local_58 * local_78 + fVar5 * local_80) - fVar4;
        if (((g_flZero <= local_88) && (g_flZero < local_8c)) && (local_8c < fVar3)) {
          local_8c = local_8c / fVar3;
          fVar7 = g_flOne - local_8c;
          fVar3 = *(float *)(param_1 + 0x1c);
          fVar4 = *(float *)(param_1 + 0x2c);
          fVar5 = fVar5 - (local_8c * *pfVar1 + fVar7 * *pfVar2);
          fVar6 = fVar6 - (local_8c * *(float *)(param_1 + 0x24) +
                          fVar7 * *(float *)(param_1 + 0x14));
          local_58 = local_58 -
                     (local_8c * *(float *)(param_1 + 0x28) + fVar7 * *(float *)(param_1 + 0x18));
          fVar9 = fVar6 * fVar6 + local_58 * local_58 + fVar5 * fVar5;
          fVar8 = g_flZero;
          if (fVar9 != g_flZero) {
            fVar8 = g_flOne / SQRT(fVar9);
          }
          param_4[4] = -NAN;
          param_4[2] = local_58 * fVar8;
          param_4[5] = local_88;
          param_4[3] = (local_54 - (local_8c * fVar4 + fVar7 * fVar3)) * fVar8;
          *param_4 = fVar5 * fVar8;
          param_4[1] = fVar6 * fVar8;
          *param_2 = 1;
          return param_2;
        }
        fVar3 = ((local_80 * *param_3 + local_7c * param_3[1] + local_78 * param_3[2]) - fVar4) /
                fVar3;
        fVar5 = g_flOne - fVar3;
        local_60 = fVar3 * *pfVar1 + fVar5 * *pfVar2;
        local_5c = fVar3 * *(float *)(param_1 + 0x24) + fVar5 * *(float *)(param_1 + 0x14);
        fVar3 = param_3[2] -
                (fVar3 * *(float *)(param_1 + 0x28) + fVar5 * *(float *)(param_1 + 0x18));
        if ((SQRT((*param_3 - local_60) * (*param_3 - local_60) +
                  (param_3[1] - local_5c) * (param_3[1] - local_5c) + fVar3 * fVar3) <=
             *(float *)(param_1 + 0xc)) || (g_flZero <= local_88)) {
          local_1c = 0;
          if (local_8c < g_flZero == (local_8c == g_flZero)) {
            local_40 = *pfVar1;
            local_3c = param_3[1] - *(float *)(param_1 + 0x24);
            local_38 = param_3[2] - *(float *)(param_1 + 0x28);
            local_34 = param_3[3] - *(float *)(param_1 + 0x2c);
            local_30 = param_3[4] - *pfVar1;
            local_2c = param_3[5] - *(float *)(param_1 + 0x24);
            local_28 = param_3[6] - *(float *)(param_1 + 0x28);
            local_24 = param_3[7] - *(float *)(param_1 + 0x2c);
          }
          else {
            local_40 = *pfVar2;
            local_3c = param_3[1] - *(float *)(param_1 + 0x14);
            local_38 = param_3[2] - *(float *)(param_1 + 0x18);
            local_34 = param_3[3] - *(float *)(param_1 + 0x1c);
            local_30 = param_3[4] - *pfVar2;
            local_2c = param_3[5] - *(float *)(param_1 + 0x14);
            local_28 = param_3[6] - *(float *)(param_1 + 0x18);
            local_24 = param_3[7] - *(float *)(param_1 + 0x1c);
          }
          local_40 = *param_3 - local_40;
          FUN_006c7fa0(*(undefined4 *)(param_1 + 0xc));
          FUN_006c7fc0(param_2,&local_40,param_4);
          FUN_005ee650();
          return param_2;
        }
      }
    }
  }
  *param_2 = 0;
  return param_2;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
