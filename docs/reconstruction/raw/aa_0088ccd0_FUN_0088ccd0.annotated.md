# Annotated low-level: FUN_0088ccd0

| Field | Value |
|---|---|
| Stable ID | `aa_0088ccd0` |
| VA | `0x0088ccd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0088ccd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_0088ccd0(int param_1)

{
  if (*(int *)(param_1 + 0x5e0) != 0) {
    if (*(int *)(param_1 + 0x558) < *(int *)(param_1 + 0x55c) + -1) {
      (**(code **)(**(int **)(param_1 + 0x5e0) + 0xd4))(1);
    }
    else {
      (**(code **)(**(int **)(param_1 + 0x5e0) + 0xd4))(0);
    }
    (**(code **)(**(int **)(param_1 + 0x5e0) + 0x34c))();
  }
  if (*(int *)(param_1 + 0x5e4) != 0) {
    if (*(int *)(param_1 + 0x558) < 1) {
      (**(code **)(**(int **)(param_1 + 0x5e4) + 0xd4))(0);
    }
    else {
      (**(code **)(**(int **)(param_1 + 0x5e4) + 0xd4))(1);
    }
                    /* WARNING: Could not recover jumptable at 0x0088cd4e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + 0x5e4) + 0x34c))();
    return;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
