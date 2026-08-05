# Annotated low-level: FUN_005bbc20

| Field | Value |
|---|---|
| Stable ID | `aa_005bbc20` |
| VA | `0x005bbc20` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005bbc20`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_005bbc20(int param_1,undefined4 param_2)

{
  int *piVar1;
  
  piVar1 = (int *)**(int **)(param_1 + 0xa24);
  if (piVar1 != *(int **)(param_1 + 0xa24)) {
    do {
      FUN_004b0f00(param_2);
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*(int *)(param_1 + 0xa24));
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
