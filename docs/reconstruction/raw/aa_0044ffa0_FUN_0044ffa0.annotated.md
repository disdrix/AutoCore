# Annotated low-level: FUN_0044ffa0

| Field | Value |
|---|---|
| Stable ID | `aa_0044ffa0` |
| VA | `0x0044ffa0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0044ffa0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int FUN_0044ffa0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  FUN_0044fdd0();
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 8);
  if (*(int *)(param_2 + 0x10) == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = *(int *)(param_2 + 0x14) - *(int *)(param_2 + 0x10) >> 2;
  }
  FUN_0044fe70(0);
  uVar4 = 0;
  if (uVar5 != 0) {
    do {
      iVar2 = *(int *)(param_1 + 0x10);
      iVar1 = uVar4 * 4;
      uVar3 = (**(code **)(**(int **)(*(int *)(param_2 + 0x10) + iVar1) + 0xc))();
      uVar4 = uVar4 + 1;
      *(undefined4 *)(iVar2 + iVar1) = uVar3;
    } while (uVar4 < uVar5);
  }
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
