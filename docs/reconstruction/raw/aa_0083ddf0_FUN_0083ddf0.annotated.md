# Annotated low-level: FUN_0083ddf0

| Field | Value |
|---|---|
| Stable ID | `aa_0083ddf0` |
| VA | `0x0083ddf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0083ddf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_0083ddf0(int *param_1)

{
  void *pvVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b470a;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00792600();
  pvVar1 = operator_new(0x488);
  piVar3 = (int *)0x0;
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    piVar3 = (int *)FUN_007b5dd0(pvVar1,0);
  }
  local_4 = 0xffffffff;
  (**(code **)(*param_1 + 0xa8))(piVar3);
  (**(code **)(*piVar3 + 0x28))("i_d_stack_select_2d_wnd_bg_texture.xml");
  iVar2 = param_1[0x1a] + 1;
  param_1[0x141] = (int)piVar3;
  param_1[0x1a] = iVar2;
  param_1[0x1d] = (int)(float)-iVar2;
  if (param_1[0x1c] < iVar2) {
    param_1[0x1c] = iVar2;
  }
  (**(code **)(*param_1 + 0x3f4))(1);
  pvVar1 = operator_new(0x4cc);
  if (pvVar1 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_0079c860();
  }
  (**(code **)(*param_1 + 0xa8))(piVar3);
  (**(code **)(*piVar3 + 0x28))("i_d_stack_select_2d_wnd_cancel.xml");
  (**(code **)(*piVar3 + 0x74))(0x9c4f);
  param_1[0x145] = (int)piVar3;
  pvVar1 = operator_new(0x4cc);
  if (pvVar1 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_0079c860();
  }
  (**(code **)(*param_1 + 0xa8))(piVar3);
  (**(code **)(*piVar3 + 0x28))("i_d_stack_select_2d_wnd_zero.xml");
  (**(code **)(*piVar3 + 0x74))(40000);
  param_1[0x146] = (int)piVar3;
  pvVar1 = operator_new(0x4cc);
  if (pvVar1 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_0079c860();
  }
  (**(code **)(*param_1 + 0xa8))(piVar3);
  (**(code **)(*piVar3 + 0x28))("i_d_stack_select_2d_wnd_one.xml");
  (**(code **)(*piVar3 + 0x74))(0x9c41);
  param_1[0x147] = (int)piVar3;
  pvVar1 = operator_new(0x4cc);
  if (pvVar1 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_0079c860();
  }
  (**(code **)(*param_1 + 0xa8))(piVar3);
  (**(code **)(*piVar3 + 0x28))("i_d_stack_select_2d_wnd_two.xml");
  (**(code **)(*piVar3 + 0x74))(0x9c42);
  param_1[0x148] = (int)piVar3;
  pvVar1 = operator_new(0x4cc);
  if (pvVar1 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_0079c860();
  }
  (**(code **)(*param_1 + 0xa8))(piVar3);
  (**(code **)(*piVar3 + 0x28))("i_d_stack_select_2d_wnd_three.xml");
  (**(code **)(*piVar3 + 0x74))(0x9c43);
  param_1[0x149] = (int)piVar3;
  pvVar1 = operator_new(0x4cc);
  if (pvVar1 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_0079c860();
  }
  (**(code **)(*param_1 + 0xa8))(piVar3);
  (**(code **)(*piVar3 + 0x28))("i_d_stack_select_2d_wnd_four.xml");
  (**(code **)(*piVar3 + 0x74))(0x9c44);
  param_1[0x14a] = (int)piVar3;
  pvVar1 = operator_new(0x4cc);
  if (pvVar1 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_0079c860();
  }
  (**(code **)(*param_1 + 0xa8))(piVar3);
  (**(code **)(*piVar3 + 0x28))("i_d_stack_select_2d_wnd_five.xml");
  (**(code **)(*piVar3 + 0x74))(0x9c45);
  param_1[0x14b] = (int)piVar3;
  pvVar1 = operator_new(0x4cc);
  if (pvVar1 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_0079c860();
  }
  (**(code **)(*param_1 + 0xa8))(piVar3);
  (**(code **)(*piVar3 + 0x28))("i_d_stack_select_2d_wnd_six.xml");
  (**(code **)(*piVar3 + 0x74))(0x9c46);
  param_1[0x14c] = (int)piVar3;
  pvVar1 = operator_new(0x4cc);
  if (pvVar1 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_0079c860();
  }
  (**(code **)(*param_1 + 0xa8))(piVar3);
  (**(code **)(*piVar3 + 0x28))("i_d_stack_select_2d_wnd_seven.xml");
  (**(code **)(*piVar3 + 0x74))(0x9c47);
  param_1[0x14d] = (int)piVar3;
  pvVar1 = operator_new(0x4cc);
  if (pvVar1 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_0079c860();
  }
  (**(code **)(*param_1 + 0xa8))(piVar3);
  (**(code **)(*piVar3 + 0x28))("i_d_stack_select_2d_wnd_eight.xml");
  (**(code **)(*piVar3 + 0x74))(0x9c48);
  param_1[0x14e] = (int)piVar3;
  pvVar1 = operator_new(0x4cc);
  if (pvVar1 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_0079c860();
  }
  (**(code **)(*param_1 + 0xa8))(piVar3);
  (**(code **)(*piVar3 + 0x28))("i_d_stack_select_2d_wnd_nine.xml");
  (**(code **)(*piVar3 + 0x74))(0x9c49);
  param_1[0x14f] = (int)piVar3;
  pvVar1 = operator_new(0x4cc);
  if (pvVar1 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_0079c860();
  }
  (**(code **)(*param_1 + 0xa8))(piVar3);
  (**(code **)(*piVar3 + 0x28))("i_d_stack_select_2d_wnd_minus.xml");
  (**(code **)(*piVar3 + 0x74))(0x9c4b);
  param_1[0x151] = (int)piVar3;
  pvVar1 = operator_new(0x4cc);
  if (pvVar1 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_0079c860();
  }
  (**(code **)(*param_1 + 0xa8))(piVar3);
  (**(code **)(*piVar3 + 0x28))("i_d_stack_select_2d_wnd_ok.xml");
  (**(code **)(*piVar3 + 0x74))(0x9c4c);
  param_1[0x153] = (int)piVar3;
  pvVar1 = operator_new(0x4cc);
  if (pvVar1 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_0079c860();
  }
  (**(code **)(*param_1 + 0xa8))(piVar3);
  (**(code **)(*piVar3 + 0x28))("i_d_stack_select_2d_wnd_reset.xml");
  (**(code **)(*piVar3 + 0x74))(0x9c4d);
  iVar2 = param_1[0x1a] + 1;
  param_1[0x152] = (int)piVar3;
  param_1[0x1a] = iVar2;
  param_1[0x1d] = (int)(float)-iVar2;
  if (param_1[0x1c] < iVar2) {
    param_1[0x1c] = iVar2;
  }
  (**(code **)(*param_1 + 0x3f4))(1);
  pvVar1 = operator_new(0x4a4);
  if (pvVar1 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_00795f20();
  }
  piVar4 = piVar3;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*piVar3 + 0x28))("i_d_stack_select_2d_wnd_count.xml");
  (**(code **)(*piVar3 + 0x74))(0x9c4e);
  (**(code **)(*piVar3 + 0x98))(0);
  (**(code **)(*piVar3 + 0x1d0))(5);
  *(undefined1 *)((int)piVar3 + 0x48b) = 1;
  param_1[0x144] = (int)piVar3;
  (**(code **)(*param_1 + 0x34c))();
  ExceptionList = piVar4;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
