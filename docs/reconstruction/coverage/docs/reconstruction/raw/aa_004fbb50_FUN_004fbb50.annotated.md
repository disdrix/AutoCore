# Annotated low-level: FUN_004fbb50

| Field | Value |
|---|---|
| Stable ID | `aa_004fbb50` |
| VA | `0x004fbb50` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004fbb50`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_004fbb50(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  
  if ((*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1) != 0) &&
     (param_2 != (int *)0x0)) {
    FUN_004e2600(&LAB_004f5400,param_2 + 0x58,0);
    piVar1 = *(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1);
    if ((piVar1 != (int *)0x0) &&
       ((iVar2 = (**(code **)(*piVar1 + 0x1dc))(), iVar2 != 0 &&
        (iVar2 = (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1) +
                             0x1dc))(), *(int *)(iVar2 + 0x250) != 0)))) {
      (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1) + 0x1dc))();
      FUN_004e2600(&LAB_004f5400,param_2 + 0x58,0);
    }
    (**(code **)(*param_2 + 0x40))(1);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
