# Annotated low-level: FUN_008dea70

| Field | Value |
|---|---|
| Stable ID | `aa_008dea70` |
| VA | `0x008dea70` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008dea70`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_008dea70(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  char acStack_40 [2];
  undefined4 auStack_3e [15];
  
  if (*(int *)(param_1 + 0x528) != 0) {
    (**(code **)(**(int **)(param_1 + 0x528) + 0x458))();
  }
  if (*(int *)(param_1 + 0x52c) != 0) {
    (**(code **)(**(int **)(param_1 + 0x52c) + 0x458))();
  }
  if (*(int *)(param_1 + 0x530) != 0) {
    (**(code **)(**(int **)(param_1 + 0x530) + 0x458))();
  }
  if ((*(int *)(DAT_00d1da2c + 0x28) != 0) &&
     (0 < *(int *)(DAT_00d1da2c + 0x2c) - *(int *)(DAT_00d1da2c + 0x28) >> 2)) {
    acStack_40[0] = '\0';
    acStack_40[1] = '\0';
    puVar4 = auStack_3e;
    for (iVar1 = 0xf; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    *(undefined2 *)puVar4 = 0;
    piVar3 = *(int **)(DAT_00d1da2c + 0x28);
    piVar2 = (int *)(DAT_00d1da2c + 0x2c);
    if (piVar3 != (int *)*piVar2) {
      do {
        if (*(int *)(param_1 + 0x528) != 0) {
          iVar1 = *piVar3;
          (**(code **)(**(int **)(param_1 + 0x528) + 0x444))
                    (iVar1 + 0x23,*(undefined4 *)(iVar1 + 8),*(undefined4 *)(iVar1 + 0xc),1);
        }
        if (*(int *)(param_1 + 0x52c) != 0) {
          sprintf(acStack_40,"%i",*(undefined4 *)(*piVar3 + 0x18));
          (**(code **)(**(int **)(param_1 + 0x52c) + 0x444))
                    (acStack_40,*(undefined4 *)(*piVar3 + 8),*(undefined4 *)(*piVar3 + 0xc),1);
        }
        if (*(int *)(param_1 + 0x530) != 0) {
          sprintf(acStack_40,"%i",*(undefined4 *)(*piVar3 + 0x1c));
          (**(code **)(**(int **)(param_1 + 0x530) + 0x444))
                    (acStack_40,*(undefined4 *)(*piVar3 + 8),*(undefined4 *)(*piVar3 + 0xc),1);
        }
        piVar3 = piVar3 + 1;
      } while (piVar3 != (int *)*piVar2);
    }
    FUN_007fbd30();
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
