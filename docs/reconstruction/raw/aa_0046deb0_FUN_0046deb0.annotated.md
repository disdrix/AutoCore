# Annotated low-level: FUN_0046deb0

| Field | Value |
|---|---|
| Stable ID | `aa_0046deb0` |
| VA | `0x0046deb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0046deb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0046deb0(undefined4 *param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  float10 fVar5;
  float10 fVar6;
  
  puVar2 = param_1;
  if (param_1 != param_2) {
    while (puVar2 = puVar2 + 1, puVar2 != param_2) {
      piVar1 = *(int **)*param_1;
      fVar5 = (float10)(**(code **)(**(int **)*puVar2 + 0x10))();
      fVar6 = (float10)(**(code **)(*piVar1 + 0x10))();
      puVar3 = puVar2;
      if ((float10)(float)fVar5 < fVar6 - (float10)DAT_00aaa620) {
        do {
          puVar4 = puVar3;
          piVar1 = *(int **)puVar4[-1];
          fVar5 = (float10)(**(code **)(**(int **)*puVar2 + 0x10))();
          fVar6 = (float10)(**(code **)(*piVar1 + 0x10))();
          puVar3 = puVar4 + -1;
        } while (fVar6 - (float10)DAT_00aaa620 <= (float10)(float)fVar5);
        if ((puVar4 != puVar2) && (puVar2 != puVar2 + 1)) {
          FUN_00468970(puVar4,puVar2,puVar2 + 1);
        }
      }
      else if ((param_1 != puVar2) && (puVar2 != puVar2 + 1)) {
        FUN_00468970(param_1,puVar2,puVar2 + 1);
      }
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
