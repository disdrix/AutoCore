# Annotated low-level: FUN_008db2d0

| Field | Value |
|---|---|
| Stable ID | `aa_008db2d0` |
| VA | `0x008db2d0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008db2d0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_008db2d0(undefined4 param_1)

{
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x578) != 0) {
    (**(code **)(**(int **)(unaff_ESI + 0x578) + 4))(param_1);
  }
  if (*(int *)(unaff_ESI + 0x574) != 0) {
    (**(code **)(**(int **)(unaff_ESI + 0x574) + 4))(param_1);
  }
  if (*(int *)(unaff_ESI + 0x504) != 0) {
    (**(code **)(**(int **)(unaff_ESI + 0x504) + 4))(param_1);
  }
  if (*(int *)(unaff_ESI + 0x57c) != 0) {
    (**(code **)(**(int **)(unaff_ESI + 0x57c) + 4))(param_1);
  }
  if (*(int *)(unaff_ESI + 0x580) != 0) {
    (**(code **)(**(int **)(unaff_ESI + 0x580) + 4))(param_1);
  }
  if (*(int *)(unaff_ESI + 0x598) != 0) {
    (**(code **)(**(int **)(unaff_ESI + 0x598) + 4))(param_1);
  }
  if (*(int *)(unaff_ESI + 0x59c) != 0) {
    (**(code **)(**(int **)(unaff_ESI + 0x59c) + 4))(param_1);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
