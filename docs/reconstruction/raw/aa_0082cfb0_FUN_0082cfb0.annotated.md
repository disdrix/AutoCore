# Annotated low-level: FUN_0082cfb0

| Field | Value |
|---|---|
| Stable ID | `aa_0082cfb0` |
| VA | `0x0082cfb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0082cfb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_0082cfb0(int *param_1,undefined4 param_2)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  char cVar5;
  float fVar6;
  float fVar7;
  int local_8;
  int local_4;
  
  NDUIWindow_ReloadInterface(param_2);
  iVar4 = DAT_00d17944;
  fVar3 = DAT_00aaa67c;
  fVar2 = DAT_00aaa678;
  if (*(char *)((int)param_1 + 0x1c9) == '\0') {
    fVar6 = (float)param_1[0x141] * (float)DAT_00d1e81c;
    iVar1 = DAT_00d1e818;
  }
  else {
    fVar6 = (float)*(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x84) * (float)param_1[0x141];
    iVar1 = *(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x80);
  }
  local_4 = (int)(fVar6 * DAT_00aaa678);
  local_8 = (int)((float)iVar1 * (float)param_1[0x140] * DAT_00aaa67c);
  param_1[0x140] = local_8;
  param_1[0x141] = local_4;
  param_1[0x148] = local_8;
  param_1[0x149] = local_4;
  if (*(char *)((int)param_1 + 0x1ca) == '\0') {
    fVar6 = (float)param_1[0x142] * (float)DAT_00d1e818;
    fVar7 = (float)param_1[0x143] * (float)DAT_00d1e81c;
  }
  else {
    fVar6 = (float)*(int *)(*(int *)(iVar4 + 0x2c) + 0x80) * (float)param_1[0x142];
    fVar7 = (float)*(int *)(*(int *)(iVar4 + 0x2c) + 0x84) * (float)param_1[0x143];
  }
  local_4 = (int)(fVar7 * fVar2);
  local_8 = (int)(fVar6 * fVar3);
  param_1[0x142] = local_8;
  param_1[0x143] = local_4;
  if (*(char *)((int)param_1 + 0x1ca) == '\0') {
    fVar6 = (float)param_1[0x144] * (float)DAT_00d1e818;
    fVar7 = (float)param_1[0x145] * (float)DAT_00d1e81c;
  }
  else {
    fVar6 = (float)*(int *)(*(int *)(iVar4 + 0x2c) + 0x80) * (float)param_1[0x144];
    fVar7 = (float)*(int *)(*(int *)(iVar4 + 0x2c) + 0x84) * (float)param_1[0x145];
  }
  local_4 = (int)(fVar7 * fVar2);
  local_8 = (int)(fVar6 * fVar3);
  param_1[0x144] = local_8;
  param_1[0x145] = local_4;
  if (*(char *)((int)param_1 + 0x1ca) == '\0') {
    fVar7 = (float)param_1[0x146] * (float)DAT_00d1e818;
    fVar6 = (float)param_1[0x147] * (float)DAT_00d1e81c;
  }
  else {
    fVar7 = (float)*(int *)(*(int *)(iVar4 + 0x2c) + 0x80) * (float)param_1[0x146];
    fVar6 = (float)*(int *)(*(int *)(iVar4 + 0x2c) + 0x84) * (float)param_1[0x147];
  }
  local_4 = (int)(fVar6 * fVar2);
  local_8 = (int)(fVar7 * fVar3);
  param_1[0x146] = local_8;
  param_1[0x147] = local_4;
  (**(code **)(*param_1 + 0x44c))();
  cVar5 = (**(code **)(*param_1 + 0x3d8))();
  if (cVar5 != '\0') {
    (**(code **)(*param_1 + 0x460))(0xffffffff);
  }
  (**(code **)(*param_1 + 0x34c))();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
