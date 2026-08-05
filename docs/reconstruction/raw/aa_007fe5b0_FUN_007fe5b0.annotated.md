# Annotated low-level: FUN_007fe5b0

| Field | Value |
|---|---|
| Stable ID | `aa_007fe5b0` |
| VA | `0x007fe5b0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007fe5b0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_007fe5b0(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  
  if (*(int *)(param_1 + 0x3084) != 0) {
    iVar2 = FUN_00419b40(param_2,param_3);
    if (iVar2 == 0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = *(int **)(iVar2 + 0xc);
    }
    if (piVar3 != (int *)0x0) {
      cVar1 = (**(code **)(*piVar3 + 0x3d8))();
      if (cVar1 != '\0') {
        (**(code **)(*piVar3 + 0x440))();
      }
      if (piVar3[0xac] != 0) {
        (**(code **)(*(int *)piVar3[0xac] + 0xb0))(piVar3);
      }
      FUN_00419760(param_2,param_3);
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
