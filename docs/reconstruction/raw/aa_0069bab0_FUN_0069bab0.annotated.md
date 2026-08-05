# Annotated low-level: FUN_0069bab0

| Field | Value |
|---|---|
| Stable ID | `aa_0069bab0` |
| VA | `0x0069bab0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0069bab0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_0069bab0(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int local_4;
  
  iVar1 = *(int *)(param_2 + 4);
  local_4 = param_1;
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(param_2 + 0xc) - iVar1 >> 2) <= (uint)(*(int *)(param_2 + 8) - iVar1 >> 2))) {
    FUN_00697f60(*(undefined4 *)(param_2 + 8),1,&local_4);
  }
  else {
    piVar2 = *(int **)(param_2 + 8);
    *piVar2 = param_1;
    *(int **)(param_2 + 8) = piVar2 + 1;
  }
  for (uVar3 = 0;
      (*(int *)(param_1 + 0xc) != 0 &&
      (uVar3 < (uint)((*(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc)) / 0xc)));
      uVar3 = uVar3 + 1) {
    FUN_0069bab0(param_2);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
