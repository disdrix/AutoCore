# Annotated low-level: FUN_004a8ec0

| Field | Value |
|---|---|
| Stable ID | `aa_004a8ec0` |
| VA | `0x004a8ec0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004a8ec0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a8ec0(char param_1,char param_2,float *param_3,undefined1 param_4)

{
  uint uVar1;
  uint uVar2;
  float fVar3;
  float fVar4;
  
  uVar1 = (uint)param_2;
  uVar2 = uVar1 & 0x8000000f;
  if ((int)uVar2 < 0) {
    uVar2 = (uVar2 - 1 | 0xfffffff0) + 1;
  }
  fVar4 = (float)(int)uVar2 * DAT_00a14000;
  fVar3 = (float)((int)(uVar1 + ((int)uVar1 >> 0x1f & 0xfU)) >> 4) * DAT_00a14000 +
          (float)(int)param_1 * DAT_00a110c0;
  *param_3 = fVar4;
  param_3[1] = fVar3;
  switch(param_4) {
  case 0:
    fVar3 = fVar3 + DAT_00a0f514;
    *param_3 = fVar4 + DAT_00a0f514;
    param_3[1] = fVar3;
    return;
  case 1:
    fVar3 = fVar3 + DAT_00a0f514;
    *param_3 = fVar4 + _DAT_009cae98;
    param_3[1] = fVar3;
    return;
  case 2:
    fVar3 = fVar3 + _DAT_009cae98;
    *param_3 = fVar4 + DAT_00a0f514;
    param_3[1] = fVar3;
    return;
  case 3:
    fVar3 = fVar3 + _DAT_009cae98;
    *param_3 = fVar4 + _DAT_009cae98;
    param_3[1] = fVar3;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
