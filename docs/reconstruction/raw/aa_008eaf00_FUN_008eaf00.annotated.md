# Annotated low-level: FUN_008eaf00

| Field | Value |
|---|---|
| Stable ID | `aa_008eaf00` |
| VA | `0x008eaf00` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008eaf00`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_008eaf00(int *param_1)

{
  void *pvVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009ba6c4;
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
  (**(code **)(*piVar3 + 0x28))("i_d_con_2d_wnd_reveal_frame.xml");
  (**(code **)(*piVar3 + 0x74))(0x9c51);
  (**(code **)(*piVar3 + 0xfc))(1,0x3f000000);
  iVar2 = param_1[0x1a] + 1;
  param_1[0x16b] = (int)piVar3;
  param_1[0x1a] = iVar2;
  param_1[0x1d] = (int)(float)-iVar2;
  if (param_1[0x1c] < iVar2) {
    param_1[0x1c] = iVar2;
  }
  (**(code **)(*param_1 + 0x3f4))(1);
  FUN_008e9df0();
  iVar2 = param_1[0x1a] + 1;
  param_1[0x1a] = iVar2;
  param_1[0x1d] = (int)(float)-iVar2;
  if (param_1[0x1c] < iVar2) {
    param_1[0x1c] = iVar2;
  }
  (**(code **)(*param_1 + 0x3f4))(1);
  pvVar1 = operator_new(0x488);
  if (pvVar1 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_007b5dd0(pvVar1,0);
  }
  (**(code **)(*param_1 + 0xa8))(piVar3);
  (**(code **)(*piVar3 + 0x28))("i_d_con_2d_wnd_bg_texture.xml");
  (**(code **)(*piVar3 + 0xcc))(0);
  iVar2 = param_1[0x1a] + 1;
  param_1[0x16a] = (int)piVar3;
  param_1[0x1a] = iVar2;
  param_1[0x1d] = (int)(float)-iVar2;
  if (param_1[0x1c] < iVar2) {
    param_1[0x1c] = iVar2;
  }
  (**(code **)(*param_1 + 0x3f4))(1);
  pvVar1 = operator_new(0x488);
  if (pvVar1 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_007b5dd0(pvVar1,0);
  }
  (**(code **)(*param_1 + 0xa8))(piVar3);
  (**(code **)(*piVar3 + 0x28))("i_d_con_2d_wnd_lfg_frame.xml");
  (**(code **)(*piVar3 + 0xfc))(1,0x3f000000);
  param_1[0x16c] = (int)piVar3;
  pvVar1 = operator_new(0x4cc);
  if (pvVar1 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_0079c860();
  }
  (**(code **)(*param_1 + 0xa8))(piVar3);
  (**(code **)(*piVar3 + 0x28))("i_d_con_2d_btn_lfg.xml");
  (**(code **)(*piVar3 + 0x74))(0x9c50);
  (**(code **)(*piVar3 + 0x3b4))(1);
  (**(code **)(*piVar3 + 0x3c8))(DAT_00d1775e,1);
  (**(code **)(*piVar3 + 0xfc))(1,0x3f000000);
  iVar2 = param_1[0x1a] + 1;
  param_1[0x16d] = (int)piVar3;
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
  piVar4 = piVar3;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*piVar3 + 0x28))("i_d_con_2d_btn_options.xml");
  (**(code **)(*piVar3 + 0x74))(0x9c41);
  (**(code **)(*piVar3 + 0xcc))(0);
  param_1[0x1a] = param_1[0x1a] + 1;
  iVar2 = param_1[0x1a];
  param_1[0x142] = (int)piVar3;
  param_1[0x1d] = (int)(float)-iVar2;
  if (param_1[0x1c] < iVar2) {
    param_1[0x1c] = iVar2;
  }
  (**(code **)(*param_1 + 0x3f4))(1);
  FUN_008e88f0();
  if (((DAT_00d1b780 != (int *)0x0) && (*DAT_00d1b780 == DAT_00d1b778)) && (DAT_00d1b6d8 != 0)) {
    FUN_008ea880();
  }
  (**(code **)(*param_1 + 0x34c))();
  ExceptionList = piVar4;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
