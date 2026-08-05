# Annotated low-level: FUN_005de0e0

| Field | Value |
|---|---|
| Stable ID | `aa_005de0e0` |
| VA | `0x005de0e0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005de0e0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_005de0e0(int param_1,uint param_2)

{
  void *pvVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009a7270;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (0xfffffff < param_2) {
    ExceptionList = &local_10;
    param_2 = FUN_004cb1d0();
  }
  if (*(int *)(param_1 + 4) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(int *)(param_1 + 0xc) - *(int *)(param_1 + 4) >> 4;
  }
  if (uVar2 < param_2) {
    param_2 = param_2 * 0x10;
    pvVar1 = operator_new(param_2);
    local_8 = 0;
    FUN_005dd920(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),pvVar1,param_1,param_2);
    if (*(void **)(param_1 + 4) != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete(*(void **)(param_1 + 4));
    }
    *(void **)(param_1 + 0xc) = (void *)(param_2 + (int)pvVar1);
    *(void **)(param_1 + 8) = pvVar1;
    *(void **)(param_1 + 4) = pvVar1;
  }
  ExceptionList = local_10;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
