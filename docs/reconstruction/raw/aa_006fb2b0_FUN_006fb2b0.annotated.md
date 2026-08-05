# Annotated low-level: FUN_006fb2b0

| Field | Value |
|---|---|
| Stable ID | `aa_006fb2b0` |
| VA | `0x006fb2b0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006fb2b0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_006fb2b0(undefined2 *param_1,int *param_2,int param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined1 uVar5;
  float fStack_74;
  float local_70;
  float local_6c;
  float local_68;
  undefined4 local_64;
  float local_60;
  float local_5c;
  float local_58;
  float fStack_54;
  float local_50;
  float local_4c;
  float fStack_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_30;
  float local_2c;
  float local_20;
  float local_1c;
  
  param_1[1] = 0;
  param_1[2] = 0x10;
  param_1[3] = 0x20;
  fVar1 = *(float *)(param_3 + 0x10);
  fVar2 = *(float *)(param_3 + 0x14);
  fVar3 = *(float *)(param_3 + 0x18);
  local_40 = fVar1 * *param_4 + fVar2 * param_4[4] + fVar3 * param_4[8] + param_4[0xc];
  local_3c = fVar2 * param_4[5] + fVar3 * param_4[9] + fVar1 * param_4[1] + param_4[0xd];
  local_38 = fVar2 * param_4[6] + fVar3 * param_4[10] + fVar1 * param_4[2] + param_4[0xe];
  fVar1 = *(float *)(param_3 + 0x20);
  fVar2 = *(float *)(param_3 + 0x24);
  fVar3 = *(float *)(param_3 + 0x28);
  local_30 = fVar1 * *param_4 + fVar2 * param_4[4] + fVar3 * param_4[8] + param_4[0xc];
  local_2c = fVar2 * param_4[5] + fVar3 * param_4[9] + fVar1 * param_4[1] + param_4[0xd];
  fVar4 = fVar2 * param_4[6] + fVar3 * param_4[10] + fVar1 * param_4[2] + param_4[0xe];
  fVar1 = *(float *)(param_3 + 0x30);
  fVar2 = *(float *)(param_3 + 0x34);
  fVar3 = *(float *)(param_3 + 0x38);
  local_20 = fVar1 * *param_4 + fVar2 * param_4[4] + fVar3 * param_4[8] + param_4[0xc];
  local_64 = 0;
  local_1c = fVar2 * param_4[5] + fVar3 * param_4[9] + fVar1 * param_4[1] + param_4[0xd];
  local_60 = local_30 - local_40;
  local_5c = local_2c - local_3c;
  local_58 = fVar4 - local_38;
  local_50 = local_20 - local_30;
  local_4c = local_1c - local_2c;
  fVar4 = (fVar2 * param_4[6] + fVar3 * param_4[10] + fVar1 * param_4[2] + param_4[0xe]) - fVar4;
  local_70 = local_5c * fVar4 - local_4c * local_58;
  local_6c = local_58 * local_50 - fVar4 * local_60;
  local_68 = local_4c * local_60 - local_5c * local_50;
  (**(code **)(*param_2 + 0x38))(&local_50);
  if (fStack_74 * (fStack_54 - fStack_44) +
      (local_50 - local_40) * local_70 + local_6c * (local_4c - local_3c) < g_flZero) {
    fStack_74 = -fStack_74;
    local_70 = -local_70;
    local_6c = -local_6c;
    local_68 = -local_68;
  }
  (**(code **)(*param_2 + 0x30))(&fStack_74,&local_64);
  *param_1 = local_60._0_2_;
  *(undefined1 *)(param_1 + 4) = 1;
  *(undefined1 *)((int)param_1 + 9) = 3;
  uVar5 = (**(code **)(*param_2 + 0x3c))();
  *(undefined1 *)(param_1 + 5) = uVar5;
  *(undefined1 *)((int)param_1 + 0xb) = 3;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
