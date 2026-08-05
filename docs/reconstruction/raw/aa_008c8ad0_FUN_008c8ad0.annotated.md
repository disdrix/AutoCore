# Annotated low-level: FUN_008c8ad0

| Field | Value |
|---|---|
| Stable ID | `aa_008c8ad0` |
| VA | `0x008c8ad0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008c8ad0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int * FUN_008c8ad0(int *param_1)

{
  char cVar1;
  void *pvVar2;
  int *piVar3;
  undefined1 extraout_DL;
  void *unaff_EBX;
  int iVar4;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b6bee;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_0087b890(param_1,0);
  local_4 = 0;
  *param_1 = (int)&PTR_FUN_00a42dec;
  *(undefined1 *)((int)param_1 + 0x522) = 0xff;
  *(undefined1 *)((int)param_1 + 0x521) = 0xff;
  *(undefined1 *)(param_1 + 0x148) = 0xff;
  *(undefined1 *)((int)param_1 + 0x523) = 0xff;
  iVar4 = 0;
  *(undefined1 *)((int)param_1 + 0x526) = 0xff;
  *(undefined1 *)((int)param_1 + 0x525) = 0xff;
  *(undefined1 *)(param_1 + 0x149) = 0xff;
  *(undefined1 *)((int)param_1 + 0x527) = 0xff;
  *(undefined1 *)((int)param_1 + 0x52a) = 0xff;
  *(undefined1 *)((int)param_1 + 0x529) = 0xff;
  *(undefined1 *)(param_1 + 0x14a) = 0xff;
  *(undefined1 *)((int)param_1 + 0x52b) = 0xff;
  *(undefined1 *)((int)param_1 + 0x52e) = 0xff;
  *(undefined1 *)((int)param_1 + 0x52d) = 0xff;
  *(undefined1 *)(param_1 + 0x14b) = 0xff;
  *(undefined1 *)((int)param_1 + 0x52f) = 0xff;
  *(undefined1 *)((int)param_1 + 0x532) = 0xff;
  *(undefined1 *)((int)param_1 + 0x531) = 0xff;
  *(undefined1 *)(param_1 + 0x14c) = 0xff;
  *(undefined1 *)((int)param_1 + 0x533) = 0xff;
  *(undefined1 *)((int)param_1 + 0x536) = 0xff;
  *(undefined1 *)((int)param_1 + 0x535) = 0xff;
  *(undefined1 *)(param_1 + 0x14d) = 0xff;
  *(undefined1 *)((int)param_1 + 0x537) = 0xff;
  *(undefined1 *)((int)param_1 + 0x53a) = 0xff;
  *(undefined1 *)((int)param_1 + 0x539) = 0xff;
  *(undefined1 *)(param_1 + 0x14e) = 0xff;
  *(undefined1 *)((int)param_1 + 0x53b) = 0xff;
  param_1[0x13f] = 10;
  param_1[0x140] = 2;
  param_1[0x146] = 1;
  param_1[0x145] = 0;
  FUN_008c51b0();
  param_1[0x143] = iVar4;
  iVar4 = DAT_00a10e78;
  *(undefined1 *)(param_1 + 0x124) = 0;
  *(undefined1 *)(param_1 + 0x147) = 0;
  *(undefined1 *)((int)param_1 + 0x51d) = 0;
  param_1[0x144] = iVar4;
  *(undefined1 *)((int)param_1 + 0x522) = extraout_DL;
  *(undefined1 *)((int)param_1 + 0x521) = extraout_DL;
  *(undefined1 *)(param_1 + 0x148) = extraout_DL;
  *(undefined1 *)((int)param_1 + 0x523) = extraout_DL;
  *(undefined1 *)((int)param_1 + 0x526) = extraout_DL;
  *(undefined1 *)((int)param_1 + 0x525) = extraout_DL;
  *(undefined1 *)(param_1 + 0x149) = extraout_DL;
  *(undefined1 *)((int)param_1 + 0x527) = extraout_DL;
  *(undefined1 *)((int)param_1 + 0x52a) = extraout_DL;
  *(undefined1 *)((int)param_1 + 0x529) = extraout_DL;
  *(undefined1 *)(param_1 + 0x14a) = extraout_DL;
  *(undefined1 *)((int)param_1 + 0x52b) = extraout_DL;
  *(undefined1 *)((int)param_1 + 0x52e) = extraout_DL;
  *(undefined1 *)((int)param_1 + 0x52d) = extraout_DL;
  *(undefined1 *)(param_1 + 0x14b) = extraout_DL;
  *(undefined1 *)((int)param_1 + 0x52f) = extraout_DL;
  *(undefined1 *)((int)param_1 + 0x532) = extraout_DL;
  *(undefined1 *)((int)param_1 + 0x531) = extraout_DL;
  *(undefined1 *)(param_1 + 0x14c) = extraout_DL;
  *(undefined1 *)((int)param_1 + 0x533) = extraout_DL;
  *(undefined1 *)((int)param_1 + 0x536) = extraout_DL;
  *(undefined1 *)((int)param_1 + 0x535) = extraout_DL;
  *(undefined1 *)(param_1 + 0x14d) = extraout_DL;
  *(undefined1 *)((int)param_1 + 0x537) = extraout_DL;
  *(undefined1 *)((int)param_1 + 0x53a) = extraout_DL;
  *(undefined1 *)((int)param_1 + 0x539) = extraout_DL;
  *(undefined1 *)(param_1 + 0x14e) = extraout_DL;
  *(undefined1 *)((int)param_1 + 0x53b) = extraout_DL;
  NDUIWindow_ReloadInterface("i_d_g.xml");
  *(undefined1 *)(param_1 + 0x147) = 0;
  cVar1 = (**(code **)(*param_1 + 0x3d8))();
  if (cVar1 != '\0') {
    (**(code **)(*param_1 + 0x458))();
    (**(code **)(*param_1 + 0x448))();
  }
  (**(code **)(*param_1 + 0x34c))();
  pvVar2 = operator_new(0x560);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_0097c720(pvVar2);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  param_1[0x165] = (int)piVar3;
  (**(code **)(*piVar3 + 0x28))("i_d_g_2d_wnd_particles.xml");
  (**(code **)(*(int *)param_1[0x165] + 0xcc))(0);
  *(undefined1 *)(param_1 + 0x17a) = 0;
  ExceptionList = unaff_EBX;
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
