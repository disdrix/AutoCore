# Annotated low-level: FUN_005e6fd0

| Field | Value |
|---|---|
| Stable ID | `aa_005e6fd0` |
| VA | `0x005e6fd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005e6fd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_005e6fd0(int param_1,int *param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  
  if ((**(int **)(param_1 + 0x14) == 0) && ((*(int **)(param_1 + 0x14))[1] == 0)) {
    iVar2 = (**(code **)(*param_2 + 0x1c))();
    if (iVar2 != 0) {
      iVar2 = (**(code **)(*param_2 + 0x1c))();
      if (*(int *)(*(int *)(iVar2 + 0x14) + 4) != 0) {
        **(undefined4 **)(param_1 + 0x14) = param_2;
        return;
      }
    }
  }
  iVar2 = *(int *)(param_1 + 0x14);
  piVar1 = (int *)(iVar2 + (param_4 - 1U & 1) * 4);
  if (*(int *)(iVar2 + param_4 * 4) == 0) {
    if (param_2 != (int *)*piVar1) {
      *(int **)(iVar2 + param_4 * 4) = param_2;
      return;
    }
  }
  else if ((*piVar1 == 0) && (param_2 != *(int **)(iVar2 + param_4 * 4))) {
    *piVar1 = (int)param_2;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
