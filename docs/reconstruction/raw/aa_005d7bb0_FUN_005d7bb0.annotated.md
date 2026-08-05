# Annotated low-level: FUN_005d7bb0

| Field | Value |
|---|---|
| Stable ID | `aa_005d7bb0` |
| VA | `0x005d7bb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005d7bb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 * __thiscall FUN_005d7bb0(undefined4 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a71ab;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_005d1990(param_2);
  *param_1 = &PTR_FUN_009db02c;
  *(undefined1 *)(param_1 + 0x2c) = 0;
  *(undefined1 *)((int)param_1 + 0xb1) = 3;
  *(undefined1 *)((int)param_1 + 0xb2) = 0;
  *(undefined1 *)((int)param_1 + 0xb3) = 0;
  param_1[0x2d] = 0;
  *(undefined1 *)(param_1 + 0x2e) = 0;
  iVar1 = *(int *)(param_2 + 0x250);
  local_4 = 0;
  param_1[0x2f] = iVar1;
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_2 + 600);
    if (iVar1 == 0) {
      uVar3 = 0xffffffff;
      uVar4 = 0xffffffff;
    }
    else {
      iVar2 = *(int *)(*(int *)(iVar1 + 4) + 4);
      uVar3 = *(undefined4 *)(iVar2 + 0x164 + iVar1);
      uVar4 = *(undefined4 *)(iVar2 + 0x168 + iVar1);
    }
    iVar1 = *(int *)(*(int *)(param_2 + 4) + 4);
    FUN_007a4480(1,"%d had no vehicle, disabled map: %s, spawn: %I64d",
                 *(undefined4 *)(*(int *)(iVar1 + 0xac + param_2) + 0x34),
                 *(int *)(iVar1 + 0xa8 + param_2) + 0xb4,uVar3,uVar4);
    FUN_005cc5b0(1,1);
  }
  param_1[9] = 0x96;
  ExceptionList = local_c;
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
