# Annotated low-level: FUN_007fb2b0

| Field | Value |
|---|---|
| Stable ID | `aa_007fb2b0` |
| VA | `0x007fb2b0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007fb2b0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_007fb2b0(uint param_1,uint param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  char cVar4;
  int in_EAX;
  
  piVar1 = *(int **)(in_EAX + 0x110c);
  piVar2 = *(int **)(in_EAX + 0x1110);
  piVar3 = *(int **)(in_EAX + 0x1108);
  if ((param_1 & param_2) == 0xffffffff) {
    if (piVar2 != (int *)0x0) {
      cVar4 = (**(code **)(*piVar2 + 0x3d8))();
      if (cVar4 != '\0') {
        (**(code **)(*piVar2 + 0x450))(0xffffffff,0xffffffff);
      }
    }
    if (piVar3 != (int *)0x0) {
      cVar4 = (**(code **)(*piVar3 + 0x3d8))();
      if (cVar4 != '\0') {
        (**(code **)(*piVar3 + 0x450))(0xffffffff,0xffffffff);
      }
    }
    if (piVar1 != (int *)0x0) {
      cVar4 = (**(code **)(*piVar1 + 0x3d8))();
      if (cVar4 != '\0') {
        (**(code **)(*piVar1 + 0x450))(0xffffffff,0xffffffff);
        return;
      }
    }
  }
  else {
    if (piVar2 != (int *)0x0) {
      cVar4 = (**(code **)(*piVar2 + 0x3d8))();
      if (cVar4 != '\0') {
        (**(code **)(*piVar2 + 0x450))(param_1,param_2);
      }
    }
    if (piVar3 != (int *)0x0) {
      cVar4 = (**(code **)(*piVar3 + 0x3d8))();
      if (cVar4 != '\0') {
        (**(code **)(*piVar3 + 0x450))(param_1,param_2);
      }
    }
    if (piVar1 != (int *)0x0) {
      cVar4 = (**(code **)(*piVar1 + 0x3d8))();
      if (cVar4 != '\0') {
        (**(code **)(*piVar1 + 0x450))(param_1,param_2);
      }
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
