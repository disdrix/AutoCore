# Annotated low-level: FUN_0096bab0

| Field | Value |
|---|---|
| Stable ID | `aa_0096bab0` |
| VA | `0x0096bab0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0096bab0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0096bab0(int param_1)

{
  int iVar1;
  int iVar2;
  int unaff_EBX;
  int iVar3;
  
  if (((((byte)*(undefined4 *)(param_1 + 0x2c) & 0xf) == 1) && (*(int *)(param_1 + 0x30) == 1)) &&
     (1 < *(uint *)(param_1 + 0x48))) {
    iVar3 = 0;
    if (unaff_EBX != 0) {
      iVar1 = *(int *)(param_1 + 0x1c);
      for (iVar2 = *(int *)(param_1 + 0x20);
          ((unaff_EBX < iVar1 || (unaff_EBX < iVar2)) && ((1 < iVar1 && (1 < iVar2))));
          iVar2 = iVar2 / 2) {
        iVar1 = iVar1 / 2;
        iVar3 = iVar3 + 1;
      }
    }
    (**(code **)(**(int **)(param_1 + 0x10) + 0x2c))(*(int **)(param_1 + 0x10),iVar3);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
