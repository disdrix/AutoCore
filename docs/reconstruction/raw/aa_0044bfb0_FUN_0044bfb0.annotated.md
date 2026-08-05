# Annotated low-level: FUN_0044bfb0

| Field | Value |
|---|---|
| Stable ID | `aa_0044bfb0` |
| VA | `0x0044bfb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0044bfb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0044bfb0(void)

{
  int *piVar1;
  int *piVar2;
  int in_EAX;
  int *piVar3;
  int unaff_EDI;
  
  if (in_EAX == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)(in_EAX + 4);
  }
  piVar3 = (int *)*piVar3;
  if ((piVar3 != (int *)0x0) && (piVar3[1] = piVar3[1] + 1, piVar3[1] == 1)) {
    (**(code **)(*piVar3 + 4))();
  }
  piVar2 = *(int **)(unaff_EDI + 4);
  if (piVar2 != (int *)0x0) {
    piVar1 = piVar2 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (**(code **)(*piVar2 + 8))();
    }
  }
  *(int **)(unaff_EDI + 4) = piVar3;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
