# Annotated low-level: FUN_005db1b0

| Field | Value |
|---|---|
| Stable ID | `aa_005db1b0` |
| VA | `0x005db1b0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005db1b0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_005db1b0(int param_1)

{
  undefined4 *puVar1;
  
  if (*(int *)(param_1 + 0xd0) != 0) {
    if (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) + 0xe4a4) != 0) {
      FUN_00560020(*(int *)(param_1 + 0xd0));
    }
    puVar1 = *(undefined4 **)(param_1 + 0xd0);
    *(short *)((int)puVar1 + 6) = *(short *)((int)puVar1 + 6) + -1;
    if (*(short *)((int)puVar1 + 6) == 0) {
      (**(code **)*puVar1)(1);
    }
    *(undefined4 *)(param_1 + 0xd0) = 0;
    if (*(void **)(param_1 + 0xd4) != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete(*(void **)(param_1 + 0xd4));
    }
    *(undefined4 *)(param_1 + 0xd4) = 0;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
