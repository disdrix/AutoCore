# Annotated low-level: FUN_007fdb20

| Field | Value |
|---|---|
| Stable ID | `aa_007fdb20` |
| VA | `0x007fdb20` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007fdb20`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_007fdb20(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int unaff_EDI;
  
  piVar1 = *(int **)(unaff_EDI + 0x3124);
  piVar2 = (int *)*piVar1;
  if (piVar2 != piVar1) {
    while ((*(int *)piVar2[2] != param_1 || (((int *)piVar2[2])[1] != param_2))) {
      piVar2 = (int *)*piVar2;
      if (piVar2 == piVar1) {
        return;
      }
    }
    if ((void *)piVar2[2] != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete((void *)piVar2[2]);
    }
    piVar2[2] = 0;
    if (piVar2 != *(int **)(unaff_EDI + 0x3124)) {
      *(int *)piVar2[1] = *piVar2;
      *(int *)(*piVar2 + 4) = piVar2[1];
                    /* WARNING: Subroutine does not return */
      operator_delete(piVar2);
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
