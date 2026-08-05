# Annotated low-level: FUN_0098efc0

| Field | Value |
|---|---|
| Stable ID | `aa_0098efc0` |
| VA | `0x0098efc0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0098efc0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int __thiscall FUN_0098efc0(uint param_1,int param_2)

{
  float *pfVar1;
  uint in_EAX;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int local_40;
  int local_3c;
  uint local_38;
  uint local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  uVar4 = param_1;
  local_34 = in_EAX;
  if ((int)in_EAX < (int)param_1) {
    uVar4 = in_EAX;
    local_34 = param_1;
  }
  local_38 = uVar4;
  local_40 = FUN_0046c680();
  if ((local_40 == *(int *)(param_2 + 0x28)) ||
     ((int)(uVar4 << 0x10 | local_34) <
      (int)(*(int *)(local_40 + 0xc) << 0x10 | *(uint *)(local_40 + 0x10)))) {
    local_3c = *(int *)(param_2 + 0x28);
    piVar2 = &local_3c;
  }
  else {
    piVar2 = &local_40;
  }
  if (*piVar2 != *(int *)(param_2 + 0x28)) {
    return *(int *)(*piVar2 + 0x14);
  }
  iVar3 = *(int *)(param_2 + 8);
  pfVar1 = (float *)(iVar3 + in_EAX * 0x24);
  local_30 = *(float *)(iVar3 + param_1 * 0x24) + *pfVar1;
  iVar3 = iVar3 + param_1 * 0x24;
  local_2c = *(float *)(iVar3 + 4) + pfVar1[1];
  local_28 = *(float *)(iVar3 + 8) + pfVar1[2];
  FUN_0076f5f0(&local_30,&local_30);
  if (*(int *)(param_2 + 8) == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = (*(int *)(param_2 + 0xc) - *(int *)(param_2 + 8)) / 0x24;
  }
  local_24 = local_30;
  local_20 = local_2c;
  local_1c = local_28;
  local_18 = DAT_00d1a6c0;
  local_14 = DAT_00d1a6c4;
  local_10 = DAT_00d1a6c8;
  local_c = DAT_00afdf0c;
  local_8 = 0;
  local_4 = 0;
  FUN_0046c300();
  piVar2 = (int *)FUN_0046c380();
  *piVar2 = iVar3;
  return iVar3;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
