# Annotated low-level: FUN_005fff60

| Field | Value |
|---|---|
| Stable ID | `aa_005fff60` |
| VA | `0x005fff60` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005fff60`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_005fff60(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x80);
  while (iVar3 = iVar3 + -1, -1 < iVar3) {
    piVar1 = *(int **)(*(int *)(param_1 + 0x7c) + iVar3 * 4);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(param_1);
    }
  }
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x8c)) {
    do {
      iVar2 = *(int *)(*(int *)(param_1 + 0x88) + iVar3 * 4);
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar2 + 8) + 4))(param_1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x8c));
  }
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x98)) {
    do {
      iVar2 = *(int *)(*(int *)(param_1 + 0x94) + iVar3 * 4);
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar2 + 8) + 4))(param_1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x98));
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
