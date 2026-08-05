# Annotated low-level: FUN_008fa9f0

| Field | Value |
|---|---|
| Stable ID | `aa_008fa9f0` |
| VA | `0x008fa9f0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008fa9f0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int * FUN_008fa9f0(int *param_1,undefined4 param_2)

{
  void *pvVar1;
  int *piVar2;
  void *unaff_ESI;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b7a5b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_0087b890(param_1,param_2);
  local_4 = 0;
  *param_1 = (int)&PTR_FUN_00a356f4;
  FUN_00536920(1);
  local_4._0_1_ = 1;
  param_1[0x13f] = 5;
  param_1[0x140] = 1;
  FUN_008f9180();
  param_1[0x536] = 0;
  NDUIWindow_ReloadInterface("i_d_c.xml");
  (**(code **)(*param_1 + 0x448))();
  (**(code **)(*param_1 + 0x34c))();
  pvVar1 = operator_new(0x520);
  local_4._0_1_ = 2;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_00856490(pvVar1);
  }
  local_4 = CONCAT31(local_4._1_3_,1);
  param_1[0x536] = (int)piVar2;
  (**(code **)(*piVar2 + 0x28))("i_d_c_2d_wnd_geo.xml");
  *(undefined1 *)(param_1[0x536] + 0x51c) = 1;
  (**(code **)(*(int *)param_1[0x536] + 0xcc))(0);
  ExceptionList = unaff_ESI;
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
