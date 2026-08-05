# Annotated low-level: FUN_006ccaa0

| Field | Value |
|---|---|
| Stable ID | `aa_006ccaa0` |
| VA | `0x006ccaa0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006ccaa0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 * __thiscall FUN_006ccaa0(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float10 fVar6;
  
  *param_1 = &PTR_FUN_009e5fdc;
  *(undefined2 *)((int)param_1 + 6) = 1;
  param_1[2] = *param_2;
  *param_1 = &PTR_FUN_00a0d97c;
  param_1[3] = param_2[8];
  param_1[4] = param_2[9];
  fVar4 = (float)(int)param_2[9] - g_flOne;
  fVar2 = (float)param_2[0xb];
  fVar3 = (float)param_2[10];
  iVar1 = param_2[8];
  param_1[0x17] = 0;
  param_1[0x14] = (float)iVar1 - g_flOne;
  param_1[0x15] = fVar2 - fVar3;
  param_1[0x16] = fVar4;
  param_1[0x14] = (float)param_2[4] * (float)param_1[0x14];
  param_1[0x15] = (float)param_2[5] * (float)param_1[0x15];
  param_1[0x16] = (float)param_2[6] * (float)param_1[0x16];
  param_1[0x17] = (float)param_2[7] * (float)param_1[0x17];
  if ((float)param_2[10] <= (float)param_2[0xb]) {
    param_1[6] = ((float)param_2[0xb] + (float)param_2[10]) * DAT_00a0f298;
  }
  else {
    param_1[6] = 0xbf800000;
    param_1[0x15] = 0xbf800000;
  }
  fVar5 = g_flOne;
  param_1[8] = param_2[4];
  param_1[9] = param_2[5];
  param_1[10] = param_2[6];
  param_1[0xb] = param_2[7];
  fVar2 = (float)param_2[6];
  fVar3 = g_flOne / (float)param_2[5];
  fVar4 = g_flOne / (float)param_2[4];
  param_1[0xf] = 0;
  param_1[0xc] = fVar4;
  param_1[0xd] = fVar3;
  param_1[0xe] = fVar5 / fVar2;
  fVar6 = (float10)FUN_00718350();
  param_1[0x11] = 0;
  param_1[0x13] = (float)(fVar6 * (float10)(float)param_1[0xb]);
  param_1[0x10] = (float)(fVar6 * (float10)(float)param_1[8]);
  param_1[0x12] = (float)(fVar6 * (float10)(float)param_1[10]);
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
