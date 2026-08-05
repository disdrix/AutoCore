# Annotated low-level: FUN_0042bfc0

| Field | Value |
|---|---|
| Stable ID | `aa_0042bfc0` |
| VA | `0x0042bfc0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0042bfc0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void * __thiscall FUN_0042bfc0(void *param_1,byte param_2)

{
  int *piVar1;
  int *piVar2;
  
  FUN_0040b290();
  FUN_0040b290();
  piVar2 = *(int **)((int)param_1 + 0x18);
  if (piVar2 != (int *)0x0) {
    piVar1 = piVar2 + 2;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (**(code **)(*piVar2 + 8))();
    }
  }
  FUN_00424d10();
  if ((param_2 & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(param_1);
  }
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
