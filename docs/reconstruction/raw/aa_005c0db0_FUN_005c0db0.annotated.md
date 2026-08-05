# Annotated low-level: FUN_005c0db0

| Field | Value |
|---|---|
| Stable ID | `aa_005c0db0` |
| VA | `0x005c0db0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005c0db0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __thiscall FUN_005c0db0(int param_1,undefined4 param_2,int param_3)

{
  void *pvVar1;
  int iVar2;
  undefined1 local_24 [4];
  void *local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a6c9a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new__(param_3 * 4);
  *(void **)(param_1 + 200) = pvVar1;
  *(undefined4 *)(param_1 + 0xcc) = 0;
  *(uint *)(param_1 + 0xbc) = *(uint *)(param_1 + 0xbc) | 1;
  local_20 = (void *)0x0;
  local_1c = 0;
  local_18 = 0;
  local_4 = 0;
  local_14 = 0;
  local_10 = 0;
  FUN_007478c0(0x1d2);
  local_4 = 1;
  iVar2 = FUN_00414c20(param_3 * 6,local_24,0x20,0);
  local_4 = 0xffffffff;
  local_14 = 0;
  local_10 = 0;
  if (local_20 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(local_20);
  }
  local_20 = (void *)0x0;
  local_1c = 0;
  local_18 = 0;
  if (-1 < iVar2) {
    iVar2 = *(int *)(param_1 + 0x14);
    if (*(int *)(iVar2 + 0x10) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_00746520(*(undefined4 *)(iVar2 + 0x14),*(undefined4 *)(iVar2 + 0x18),0);
    }
    *(int *)(param_1 + 0xd0) = iVar2;
    if (iVar2 != 0) {
      ExceptionList = local_c;
      return 1;
    }
    if (*(int *)(*(int *)(param_1 + 0x14) + 0x10) != 0) {
      FUN_007464e0();
    }
  }
  ExceptionList = local_c;
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
