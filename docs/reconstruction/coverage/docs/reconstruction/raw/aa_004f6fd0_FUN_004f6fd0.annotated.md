# Annotated low-level: FUN_004f6fd0

| Field | Value |
|---|---|
| Stable ID | `aa_004f6fd0` |
| VA | `0x004f6fd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004f6fd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined * __thiscall FUN_004f6fd0(int param_1,int param_2)

{
  int iVar1;
  int unaff_retaddr;
  
  if (*(int **)(param_1 + -0x41c) != (int *)0x0) {
    iVar1 = (**(code **)(**(int **)(param_1 + -0x41c) + 0x38))();
    if (iVar1 != 0) {
      iVar1 = (**(code **)(**(int **)(param_1 + -0x41c) + 0x38))();
      return (undefined *)(iVar1 + param_2 * 2);
    }
  }
  iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x66c + param_1) + 0x210
                      ))(0);
  if (iVar1 != 0) {
    return &DAT_00b041f0 + unaff_retaddr * 2;
  }
  return (undefined *)
         (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x5c4 + param_1) + 0x3c) +
          0x48c + unaff_retaddr * 2);
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
