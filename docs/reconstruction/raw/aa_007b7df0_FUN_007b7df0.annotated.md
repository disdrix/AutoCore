# Annotated low-level: FUN_007b7df0

| Field | Value |
|---|---|
| Stable ID | `aa_007b7df0` |
| VA | `0x007b7df0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007b7df0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __fastcall FUN_007b7df0(undefined1 *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(param_1 + 0x20);
  *piVar1 = *piVar1 + -1;
  if ((*piVar1 == 0) && (DAT_00d1793c == '\0')) {
    piVar1 = *(int **)(param_1 + 0x28);
    if (piVar1 != (int *)0x0) {
      *(undefined4 *)(param_1 + 0x28) = 0;
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    piVar1 = *(int **)(param_1 + 0x24);
    if (piVar1 != (int *)0x0) {
      *(undefined4 *)(param_1 + 0x24) = 0;
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *param_1 = 0;
  }
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
