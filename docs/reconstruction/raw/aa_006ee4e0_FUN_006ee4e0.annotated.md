# Annotated low-level: FUN_006ee4e0

| Field | Value |
|---|---|
| Stable ID | `aa_006ee4e0` |
| VA | `0x006ee4e0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006ee4e0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 * __thiscall
FUN_006ee4e0(undefined4 *param_1,int *param_2,undefined4 *param_3,int *param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *local_10;
  int local_c;
  int local_8;
  int *local_4;
  
  param_1[2] = param_5;
  *param_1 = &PTR_LAB_00a0ea54;
  local_8 = param_2[2];
  local_4 = param_2;
  local_10 = *(int **)(*param_2 + 0xc);
  local_c = param_2[1];
  iVar1 = *param_4;
  iVar2 = (**(code **)(*local_10 + 0x14))();
  iVar3 = (**(code **)(*(int *)*param_3 + 0x14))();
  uVar4 = (**(code **)(iVar1 + 0x18c + (iVar2 * 0x20 + iVar3) * 4))
                    (&local_10,param_3,param_4,param_5);
  param_1[3] = uVar4;
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
