# Annotated low-level: FUN_004fed40

| Field | Value |
|---|---|
| Stable ID | `aa_004fed40` |
| VA | `0x004fed40` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004fed40`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __thiscall FUN_004fed40(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  FUN_005cae70(param_2,param_3);
  FUN_004ce940();
  iVar1 = FUN_00404d70(param_2);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 0x3c) == 0) {
      FUN_004f1e20(1,1);
    }
    puVar2 = (undefined4 *)(*(int *)(iVar1 + 0x3c) + 0x4c0);
    if (puVar2 != (undefined4 *)0x0) {
      puVar2 = (undefined4 *)FUN_00508bb0(*puVar2);
      if (puVar2 != (undefined4 *)0x0) {
        (**(code **)*puVar2)(param_1 + -0x670,param_3,1);
        return 1;
      }
    }
  }
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
