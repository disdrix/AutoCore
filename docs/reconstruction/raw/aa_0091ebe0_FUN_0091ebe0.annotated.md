# Annotated low-level: FUN_0091ebe0

| Field | Value |
|---|---|
| Stable ID | `aa_0091ebe0` |
| VA | `0x0091ebe0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0091ebe0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_0091ebe0(int *param_1)

{
  void **ppvVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  char *pcVar7;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009b3acb;
  local_c = ExceptionList;
  ppvVar1 = &local_c;
  if (*(char *)((int)param_1 + 0xc65) != '\0') {
    if ((int *)param_1[0x31a] == (int *)0x0) {
      return;
    }
    ExceptionList = &local_c;
    iVar2 = (**(code **)(*(int *)param_1[0x31a] + 0xe8))();
    if (iVar2 != -1) {
      ExceptionList = local_c;
      return;
    }
    (**(code **)(*(int *)param_1[0x31a] + 0x100))();
    FUN_0091b050();
    ppvVar1 = ExceptionList;
  }
  ExceptionList = ppvVar1;
  *(undefined1 *)((int)param_1 + 0xc65) = 1;
  *(undefined1 *)((int)param_1 + 0xc66) = 0;
  FUN_007feb20();
  if (param_1[0x31a] != 0) {
    (**(code **)(*param_1 + 0xb0))(param_1[0x31a]);
    if ((undefined4 *)param_1[0x31a] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x31a])(1);
    }
    param_1[0x31a] = 0;
  }
  if (param_1[0x31b] != 0) {
    (**(code **)(*param_1 + 0xb0))(param_1[0x31b]);
    if ((undefined4 *)param_1[0x31b] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x31b])(1);
    }
    param_1[0x31b] = 0;
  }
  pvVar3 = operator_new(0x488);
  uStack_4 = 0;
  if (pvVar3 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_007b5dd0(pvVar3,0);
  }
  uStack_4 = 0xffffffff;
  param_1[0x31a] = iVar2;
  (**(code **)(*param_1 + 0xa8))(iVar2);
  pcVar7 = "i_s_av_2d_wnd_cutscene_frame_top.xml";
  (**(code **)(*(int *)param_1[0x31a] + 0x28))("i_s_av_2d_wnd_cutscene_frame_top.xml");
  (**(code **)(*(int *)param_1[0x31a] + 0x74))(0x4e64);
  if (DAT_00d1a8dd != '\0') {
    iVar4 = (**(code **)(*(int *)param_1[0x31a] + 0x164))(0);
    *(undefined1 *)(iVar4 + 3) = 0;
  }
  uVar6 = 0x3f000000;
  uVar5 = 1;
  (**(code **)(*(int *)param_1[0x31a] + 0xfc))(1,0x3f000000);
  pvVar3 = operator_new(0x488);
  if (pvVar3 == (void *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = FUN_007b5dd0(pvVar3,0);
  }
  param_1[0x31b] = iVar4;
  (**(code **)(*param_1 + 0xa8))(iVar4,uVar5,uVar6,pvVar3,pcVar7,iVar2,0xffffffff);
  (**(code **)(*(int *)param_1[0x31b] + 0x28))("i_s_av_2d_wnd_cutscene_frame_bottom.xml");
  (**(code **)(*(int *)param_1[0x31b] + 0x74))(0x4e65);
  if (DAT_00d1a8dd != '\0') {
    iVar2 = (**(code **)(*(int *)param_1[0x31b] + 0x164))(0);
    *(undefined1 *)(iVar2 + 3) = 0;
  }
  (**(code **)(*(int *)param_1[0x31b] + 0xfc))(1,0x3f000000);
  ExceptionList = local_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
