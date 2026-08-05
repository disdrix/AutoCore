# Annotated low-level: FUN_006f6ef0

| Field | Value |
|---|---|
| Stable ID | `aa_006f6ef0` |
| VA | `0x006f6ef0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006f6ef0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_006f6ef0(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float local_44;
  uint local_40;
  
  fVar2 = *param_2 * *param_4 + param_2[1] * param_4[1] + param_2[2] * param_4[2];
  fVar1 = (*param_3 - *param_1) * *param_2 +
          (param_3[1] - param_1[1]) * param_2[1] + (param_3[2] - param_1[2]) * param_2[2];
  local_44 = (param_3[1] - param_1[1]) * param_4[1] +
             (param_3[2] - param_1[2]) * param_4[2] + (*param_3 - *param_1) * *param_4;
  fVar3 = param_2[2] * param_2[2] + param_2[1] * param_2[1] + *param_2 * *param_2;
  fVar4 = param_4[2] * param_4[2] + param_4[1] * param_4[1] + *param_4 * *param_4;
  fVar5 = ABS(fVar4 * fVar3 - fVar2 * fVar2);
  fVar6 = fVar4 * fVar1 - local_44 * fVar2;
  if (fVar5 * fVar5 < fVar6 * fVar5 == (fVar5 * fVar5 == fVar6 * fVar5)) {
    if (fVar6 < g_flZero == (fVar6 == g_flZero)) {
      if (fVar5 <= (fVar2 * fVar2 + fVar4 * fVar3) * _DAT_00aaab90) goto LAB_006f7040;
      fVar6 = fVar6 / fVar5;
      local_40 = 0;
    }
    else {
      local_40 = 2;
      fVar6 = g_flZero;
    }
  }
  else {
LAB_006f7040:
    local_40 = 1;
    fVar6 = g_flOne;
  }
  local_44 = fVar2 * fVar6 - local_44;
  if (local_44 < fVar4) {
    if (local_44 < g_flZero == (local_44 == g_flZero)) {
      local_44 = local_44 / fVar4;
      goto LAB_006f70ff;
    }
    local_44 = 0.0;
    local_40 = 8;
  }
  else {
    local_44 = 1.0;
    local_40 = 4;
  }
  fVar6 = local_44 * fVar2 + fVar1;
  if (fVar6 < g_flZero == (fVar6 == g_flZero)) {
    if (fVar6 < fVar3) {
      fVar6 = fVar6 / fVar3;
    }
    else {
      local_40 = local_40 | 1;
      fVar6 = g_flOne;
    }
  }
  else {
    local_40 = local_40 | 2;
    fVar6 = g_flZero;
  }
LAB_006f70ff:
  *param_5 = *param_1;
  param_5[1] = param_1[1];
  param_5[2] = param_1[2];
  param_5[3] = param_1[3];
  *param_5 = fVar6 * *param_2 + *param_5;
  param_5[1] = fVar6 * param_2[1] + param_5[1];
  param_5[2] = fVar6 * param_2[2] + param_5[2];
  param_5[3] = fVar6 * param_2[3] + param_5[3];
  fVar5 = param_3[2];
  fVar1 = param_3[1];
  fVar6 = param_3[3];
  fVar2 = param_4[1];
  fVar3 = param_4[2];
  fVar4 = param_4[3];
  param_5[4] = *param_5 - (local_44 * *param_4 + *param_3);
  param_5[5] = param_5[1] - (local_44 * fVar2 + fVar1);
  param_5[6] = param_5[2] - (local_44 * fVar3 + fVar5);
  param_5[7] = param_5[3] - (local_44 * fVar4 + fVar6);
  param_5[8] = param_5[6] * param_5[6] + param_5[5] * param_5[5] + param_5[4] * param_5[4];
  return local_40;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
