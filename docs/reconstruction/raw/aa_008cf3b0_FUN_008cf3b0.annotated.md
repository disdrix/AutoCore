# Annotated low-level: FUN_008cf3b0

| Field | Value |
|---|---|
| Stable ID | `aa_008cf3b0` |
| VA | `0x008cf3b0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008cf3b0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_008cf3b0(undefined4 param_1)

{
  int in_EAX;
  int iVar1;
  int *piVar2;
  
  if (*(int *)(in_EAX + 0x70c) != 0) {
    (**(code **)(**(int **)(in_EAX + 0x70c) + 4))(param_1);
  }
  if (*(int *)(in_EAX + 0x710) != 0) {
    (**(code **)(**(int **)(in_EAX + 0x710) + 4))(param_1);
  }
  if (*(int *)(in_EAX + 0x714) != 0) {
    (**(code **)(**(int **)(in_EAX + 0x714) + 4))(param_1);
  }
  if (*(int *)(in_EAX + 0x718) != 0) {
    (**(code **)(**(int **)(in_EAX + 0x718) + 4))(param_1);
  }
  if (*(int *)(in_EAX + 0x78c) != 0) {
    (**(code **)(**(int **)(in_EAX + 0x78c) + 4))(param_1);
  }
  if (*(int *)(in_EAX + 0x790) != 0) {
    (**(code **)(**(int **)(in_EAX + 0x790) + 4))(param_1);
  }
  if (*(int *)(in_EAX + 0x6b8) != 0) {
    (**(code **)(**(int **)(in_EAX + 0x6b8) + 4))(param_1);
  }
  if (*(int *)(in_EAX + 0x6b0) != 0) {
    (**(code **)(**(int **)(in_EAX + 0x6b0) + 4))(param_1);
  }
  if (*(int *)(in_EAX + 0x694) != 0) {
    (**(code **)(**(int **)(in_EAX + 0x694) + 4))(param_1);
  }
  if (*(int *)(in_EAX + 0x6a8) != 0) {
    (**(code **)(**(int **)(in_EAX + 0x6a8) + 4))(param_1);
  }
  if (*(int *)(in_EAX + 0x6a0) != 0) {
    (**(code **)(**(int **)(in_EAX + 0x6a0) + 4))(param_1);
  }
  if (*(int *)(in_EAX + 0x698) != 0) {
    (**(code **)(**(int **)(in_EAX + 0x698) + 4))(param_1);
  }
  piVar2 = (int *)(in_EAX + 0x774);
  iVar1 = 2;
  do {
    if (piVar2[-2] != 0) {
      (**(code **)(*(int *)piVar2[-2] + 4))(param_1);
    }
    if (*piVar2 != 0) {
      (**(code **)(*(int *)*piVar2 + 4))(param_1);
    }
    if (piVar2[2] != 0) {
      (**(code **)(*(int *)piVar2[2] + 4))(param_1);
    }
    if (piVar2[4] != 0) {
      (**(code **)(*(int *)piVar2[4] + 4))(param_1);
    }
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
