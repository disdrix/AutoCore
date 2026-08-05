# Annotated low-level: FUN_0044bad0

| Field | Value |
|---|---|
| Stable ID | `aa_0044bad0` |
| VA | `0x0044bad0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0044bad0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0044bad0(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  int in_EAX;
  int *piVar3;
  
  if (*(int *)(in_EAX + 4) == 0) {
    piVar3 = (int *)FUN_0044c150();
    if (piVar3 == (int *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3[1] = 0;
      piVar3[2] = 0;
      piVar3[3] = 0;
      *piVar3 = (int)&PTR_FUN_00aa213c;
      piVar3[4] = 0;
      piVar3[5] = 2;
      piVar3[6] = 0;
      piVar3[7] = 0;
      piVar3[8] = 0;
      piVar3[9] = 0;
    }
    if ((piVar3 != (int *)0x0) && (piVar3[1] = piVar3[1] + 1, piVar3[1] == 1)) {
      (**(code **)(*piVar3 + 4))();
    }
    piVar2 = *(int **)(in_EAX + 4);
    if (piVar2 != (int *)0x0) {
      piVar1 = piVar2 + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (**(code **)(*piVar2 + 8))();
      }
    }
    *(int **)(in_EAX + 4) = piVar3;
  }
  FUN_00988c70(param_1,param_2);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
