# Annotated low-level: FUN_005ebcf0

| Field | Value |
|---|---|
| Stable ID | `aa_005ebcf0` |
| VA | `0x005ebcf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005ebcf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_005ebcf0(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  
  if (*param_2 != 0) {
    iVar5 = *(int *)(param_1 + 0xc4) + -1;
    if (-1 < iVar5) {
      puVar4 = (undefined4 *)(*(int *)(param_1 + 0xc0) + 4 + iVar5 * 8);
      do {
        if ((int *)*puVar4 == param_2) {
          FUN_00580b60(param_2,1);
          piVar1 = *(int **)(*(int *)(param_1 + 0xc0) + iVar5 * 8);
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 0x14))();
          }
          *(int *)(param_1 + 0xc4) = *(int *)(param_1 + 0xc4) + -1;
          iVar2 = *(int *)(param_1 + 0xc4);
          iVar3 = *(int *)(param_1 + 0xc0);
          *(undefined4 *)(iVar3 + iVar5 * 8) = *(undefined4 *)(iVar3 + iVar2 * 8);
          *(undefined4 *)(iVar3 + 4 + iVar5 * 8) = *(undefined4 *)(iVar3 + 4 + iVar2 * 8);
          return;
        }
        iVar5 = iVar5 + -1;
        puVar4 = puVar4 + -2;
      } while (-1 < iVar5);
    }
    FUN_00580b60(param_2,(uint)param_2 & 0xffffff00);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
