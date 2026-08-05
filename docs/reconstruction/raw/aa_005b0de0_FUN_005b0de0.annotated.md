# Annotated low-level: FUN_005b0de0

| Field | Value |
|---|---|
| Stable ID | `aa_005b0de0` |
| VA | `0x005b0de0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005b0de0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_005b0de0(int param_1,char param_2)

{
  if (*(int *)(param_1 + 0x50) != 0) {
    if ((*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xa8) + 0x38) == 3) && (param_2 != '\0')) {
      (**(code **)(**(int **)(param_1 + 0x50) + 700))(1);
    }
    else {
      (**(code **)(**(int **)(param_1 + 0x50) + 700))(0);
    }
  }
  if (*(int *)(param_1 + 0x34) != 0) {
    FUN_005a0470(param_1 + 0x40);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
