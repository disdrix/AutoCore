# Annotated low-level: FUN_006fbc20

| Field | Value |
|---|---|
| Stable ID | `aa_006fbc20` |
| VA | `0x006fbc20` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006fbc20`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __fastcall FUN_006fbc20(float *param_1,float *param_2,float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  bool bVar5;
  float local_a0;
  float local_9c;
  float local_98;
  undefined4 local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_80;
  float local_7c;
  float local_78;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_50;
  float local_4c;
  float local_40;
  float local_3c;
  float local_38;
  float local_30;
  float local_2c;
  float local_28;
  float local_20;
  float local_1c;
  float local_18;
  
  local_20 = param_2[4] - *param_2;
  local_1c = param_2[5] - param_2[1];
  local_18 = param_2[6] - param_2[2];
  local_60 = param_2[0xc] - *param_2;
  local_5c = param_2[0xd] - param_2[1];
  local_8c = param_2[0xd] - param_2[9];
  local_50 = (param_2[0xe] - param_2[6]) * (param_2[9] - param_2[5]) -
             (param_2[0xd] - param_2[5]) * (param_2[10] - param_2[6]);
  local_4c = (param_2[10] - param_2[6]) * (param_2[0xc] - param_2[4]) -
             (param_2[0xe] - param_2[6]) * (param_2[8] - param_2[4]);
  fVar2 = (param_2[0xd] - param_2[5]) * (param_2[8] - param_2[4]) -
          (param_2[9] - param_2[5]) * (param_2[0xc] - param_2[4]);
  local_40 = (param_2[0xe] - param_2[10]) * (param_2[1] - param_2[9]) -
             local_8c * (param_2[2] - param_2[10]);
  local_3c = (param_2[2] - param_2[10]) * (param_2[0xc] - param_2[8]) -
             (param_2[0xe] - param_2[10]) * (*param_2 - param_2[8]);
  local_38 = local_8c * (*param_2 - param_2[8]) -
             (param_2[1] - param_2[9]) * (param_2[0xc] - param_2[8]);
  local_30 = (param_2[0xe] - param_2[2]) * local_1c - local_5c * local_18;
  local_2c = local_18 * local_60 - (param_2[0xe] - param_2[2]) * local_20;
  local_28 = local_5c * local_20 - local_1c * local_60;
  fVar1 = (*param_1 - param_2[0xc]) * param_3;
  fVar3 = (param_1[1] - param_2[0xd]) * param_3;
  param_3 = (param_1[2] - param_2[0xe]) * param_3;
  local_a0 = local_50 * fVar1 + local_4c * fVar3 + fVar2 * param_3;
  local_9c = local_40 * fVar1 + local_3c * fVar3 + local_38 * param_3;
  local_98 = local_30 * fVar1 + local_2c * fVar3 + local_28 * param_3;
  local_58 = ABS(local_98);
  local_90 = fVar2 * fVar2 + local_4c * local_4c + local_50 * local_50;
  if (local_90 == g_flZero) {
    local_90 = 3.4028235e+38;
  }
  else {
    local_90 = (ABS(local_a0) * local_a0) / local_90;
  }
  fVar1 = local_38 * local_38 + local_3c * local_3c + local_40 * local_40;
  fVar2 = _DAT_00a0f00c;
  if (fVar1 != g_flZero) {
    fVar2 = (ABS(local_9c) * local_9c) / fVar1;
  }
  local_88 = local_28 * local_28 + local_2c * local_2c + local_30 * local_30;
  if (local_88 == g_flZero) {
    local_88 = 3.4028235e+38;
  }
  else {
    local_88 = (local_58 * local_98) / local_88;
  }
  bVar5 = local_90 <= fVar2;
  fVar1 = local_90;
  if (!bVar5) {
    local_64 = local_90;
    fVar1 = fVar2;
    fVar2 = local_90;
  }
  local_90 = fVar1;
  uVar4 = (uint)bVar5;
  if (fVar2 <= local_88) {
    uVar4 = 2;
    fVar1 = local_88;
  }
  else {
    fVar1 = fVar2;
    local_64 = fVar2;
    fVar2 = local_88;
    if (local_88 < local_90) {
      fVar2 = local_90;
    }
  }
  local_88 = fVar1;
  if (_DAT_00a0f010 <= local_88) {
    if (local_88 <= DAT_00aaaa10 * fVar2) {
      local_94 = 0;
      local_80 = local_a0;
      local_7c = local_9c;
      local_78 = local_98;
      uVar4 = FUN_006fb500(param_1,&local_a0);
      return uVar4;
    }
    return uVar4;
  }
  return 0xffffffff;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
