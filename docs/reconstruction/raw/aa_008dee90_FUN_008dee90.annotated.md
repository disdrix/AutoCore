# Annotated low-level: FUN_008dee90

| Field | Value |
|---|---|
| Stable ID | `aa_008dee90` |
| VA | `0x008dee90` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008dee90`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_008dee90(int *param_1)

{
  void *pvVar1;
  int iVar2;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009ba475;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00792600();
  pvVar1 = operator_new(0x488);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_007b5dd0(pvVar1,0);
  }
  local_4 = 0xffffffff;
  param_1[0x146] = iVar2;
  (**(code **)(*param_1 + 0xa8))(iVar2);
  (**(code **)(*(int *)param_1[0x146] + 0x28))("i_d_e_2d_wnd_frame_enemies.xml");
  pvVar1 = operator_new(0x488);
  pvStack_c = (void *)0x1;
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_007b5dd0(pvVar1,0);
  }
  pvStack_c = (void *)0xffffffff;
  param_1[0x145] = iVar2;
  (**(code **)(*param_1 + 0xa8))(iVar2);
  (**(code **)(*(int *)param_1[0x145] + 0x28))("i_d_e_2d_wnd_bg_enemies.xml");
  pvVar1 = operator_new(0x488);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_007b5dd0(pvVar1,0);
  }
  param_1[0x143] = iVar2;
  (**(code **)(*param_1 + 0xa8))(iVar2);
  (**(code **)(*(int *)param_1[0x143] + 0x28))("i_d_e_2d_wnd_title.xml");
  pvVar1 = operator_new(0x488);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_007b5dd0(pvVar1,0);
  }
  param_1[0x144] = iVar2;
  (**(code **)(*param_1 + 0xa8))(iVar2);
  (**(code **)(*(int *)param_1[0x144] + 0x28))("i_d_e_2d_wnd_label_enemies.xml");
  pvVar1 = operator_new(0x4cc);
  iVar2 = 0;
  if (pvVar1 != (void *)0x0) {
    iVar2 = FUN_0079c860();
  }
  param_1[0x147] = iVar2;
  (**(code **)(*param_1 + 0xa8))(iVar2);
  (**(code **)(*(int *)param_1[0x147] + 0x28))("i_d_e_2d_btn_sort_enemies_name.xml");
  (**(code **)(*(int *)param_1[0x147] + 0x74))(0x9c41);
  pvVar1 = operator_new(0x4cc);
  iVar2 = 0;
  if (pvVar1 != (void *)0x0) {
    iVar2 = FUN_0079c860();
  }
  param_1[0x148] = iVar2;
  (**(code **)(*param_1 + 0xa8))(iVar2);
  (**(code **)(*(int *)param_1[0x148] + 0x28))("i_d_e_2d_btn_sort_enemies_your_kills.xml");
  (**(code **)(*(int *)param_1[0x148] + 0x74))(0x9c42);
  pvVar1 = operator_new(0x4cc);
  iVar2 = 0;
  if (pvVar1 != (void *)0x0) {
    iVar2 = FUN_0079c860();
  }
  param_1[0x149] = iVar2;
  (**(code **)(*param_1 + 0xa8))(iVar2);
  (**(code **)(*(int *)param_1[0x149] + 0x28))("i_d_e_2d_btn_sort_enemies_their_kills.xml");
  (**(code **)(*(int *)param_1[0x149] + 0x74))(0x9c43);
  pvVar1 = operator_new(0x9a8);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0078b6e0();
  }
  param_1[0x14a] = iVar2;
  (**(code **)(*param_1 + 0xa8))(iVar2);
  (**(code **)(*(int *)param_1[0x14a] + 0x28))("i_d_e_2d_lb_enemies_name.xml");
  (**(code **)(*(int *)param_1[0x14a] + 0x474))(0x9c48);
  (**(code **)(*(int *)param_1[0x14a] + 0x43c))();
  pvVar1 = operator_new(0x9a8);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0078b6e0();
  }
  param_1[0x14b] = iVar2;
  (**(code **)(*param_1 + 0xa8))(iVar2);
  (**(code **)(*(int *)param_1[0x14b] + 0x28))("i_d_e_2d_lb_enemies_your_kills.xml");
  (**(code **)(*(int *)param_1[0x14b] + 0x474))(0x9c48);
  (**(code **)(*(int *)param_1[0x14b] + 0x43c))();
  pvVar1 = operator_new(0x9a8);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0078b6e0();
  }
  param_1[0x14c] = iVar2;
  (**(code **)(*param_1 + 0xa8))(iVar2);
  (**(code **)(*(int *)param_1[0x14c] + 0x28))("i_d_e_2d_lb_enemies_their_kills.xml");
  (**(code **)(*(int *)param_1[0x14c] + 0x474))(0x9c48);
  (**(code **)(*(int *)param_1[0x14c] + 0x43c))();
  pvVar1 = operator_new(0x954);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0078f890();
  }
  param_1[0x14d] = iVar2;
  (**(code **)(*param_1 + 0xa8))(iVar2);
  (**(code **)(*(int *)param_1[0x14d] + 0x28))("i_d_e_2d_sb_enemies.xml");
  (**(code **)(*(int *)param_1[0x14d] + 0x43c))();
  (**(code **)(*(int *)param_1[0x14d] + 0x74))(0x9c47);
  pvVar1 = operator_new(0x4a4);
  iVar2 = 0;
  if (pvVar1 != (void *)0x0) {
    iVar2 = FUN_00795f20();
  }
  param_1[0x14e] = iVar2;
  (**(code **)(*param_1 + 0xa8))(iVar2);
  (**(code **)(*(int *)param_1[0x14e] + 0x28))("i_d_e_2d_wnd_edit_enemies.xml");
  (**(code **)(*(int *)param_1[0x14e] + 0x74))(0x9c44);
  (**(code **)(*(int *)param_1[0x14e] + 0x1d0))(0x10);
  *(undefined1 *)(param_1[0x14e] + 0x48c) = 1;
  *(undefined1 *)(param_1[0x14e] + 0x48d) = 1;
  pvVar1 = operator_new(0x4cc);
  iVar2 = 0;
  if (pvVar1 != (void *)0x0) {
    iVar2 = FUN_0079c860();
  }
  param_1[0x14f] = iVar2;
  (**(code **)(*param_1 + 0xa8))(iVar2);
  (**(code **)(*(int *)param_1[0x14f] + 0x28))();
  (**(code **)(*(int *)param_1[0x14f] + 0x74))(0x9c45);
  pvVar1 = operator_new(0x4cc);
  iVar2 = 0;
  if (pvVar1 != (void *)0x0) {
    iVar2 = FUN_0079c860();
  }
  param_1[0x150] = iVar2;
  (**(code **)(*param_1 + 0xa8))(iVar2);
  (**(code **)(*(int *)param_1[0x150] + 0x28))("i_d_e_2d_btn_remove_enemies.xml");
  (**(code **)(*(int *)param_1[0x150] + 0x74))(0x9c46);
  FUN_007fbe50();
  (**(code **)(*param_1 + 0x448))();
  (**(code **)(*param_1 + 0x34c))();
  ExceptionList = s_i_d_e_2d_btn_add_enemies_xml_00a3cb2c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
