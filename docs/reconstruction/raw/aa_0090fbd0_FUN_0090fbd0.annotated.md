# Annotated low-level: FUN_0090fbd0

| Field | Value |
|---|---|
| Stable ID | `aa_0090fbd0` |
| VA | `0x0090fbd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0090fbd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0090fbd0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(DAT_00d17944 + 0x170);
  if (iVar1 != 0) {
    iVar2 = *(int *)(param_1 + 0x2a8);
    *(undefined1 *)(iVar2 + 0x48) = 1;
    *(undefined4 *)(iVar2 + 0x44) = *(undefined4 *)(iVar2 + 0x40);
    FUN_0076c4d0();
    (**(code **)(**(int **)(iVar2 + 8) + 4))(iVar1);
    FUN_00755f10(iVar1);
  }
  iVar1 = *(int *)(DAT_00d17944 + 0x184);
  if (iVar1 != 0) {
    iVar2 = *(int *)(param_1 + 0x2a8);
    *(undefined1 *)(iVar2 + 0x48) = 1;
    *(undefined4 *)(iVar2 + 0x44) = *(undefined4 *)(iVar2 + 0x40);
    FUN_0076c4d0();
    (**(code **)(**(int **)(iVar2 + 8) + 4))(iVar1);
    FUN_00755f10(iVar1);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
