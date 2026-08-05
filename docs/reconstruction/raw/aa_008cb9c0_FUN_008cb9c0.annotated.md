# Annotated low-level: FUN_008cb9c0

| Field | Value |
|---|---|
| Stable ID | `aa_008cb9c0` |
| VA | `0x008cb9c0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008cb9c0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_008cb9c0(int *param_1)

{
  void *pvVar1;
  int iVar2;
  int *piVar3;
  void *pvVar4;
  undefined8 uVar5;
  char **ppcStack_b4;
  char **ppcStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  char *pcStack_a4;
  char *pcStack_9c;
  char *pcStack_90;
  void *pvStack_8c;
  char *pcStack_88;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b9fc2;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00792600();
  DAT_00d1a980 = 0;
  pvVar1 = operator_new(0x488);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_007b5dd0();
  }
  local_4 = 0xffffffff;
  param_1[0x249] = iVar2;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x249] + 0x28))();
  (**(code **)(*(int *)param_1[0x249] + 0xfc))();
  iVar2 = param_1[0x1a] + 1;
  param_1[0x1a] = iVar2;
  param_1[0x1d] = (int)(float)-iVar2;
  if (param_1[0x1c] < iVar2) {
    param_1[0x1c] = iVar2;
  }
  (**(code **)(*param_1 + 0x3f4))();
  pvVar1 = operator_new(0x488);
  if (pvVar1 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_007b5dd0();
  }
  param_1[0x24a] = (int)piVar3;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x24a] + 0x28))();
  iVar2 = param_1[0x1a] + 1;
  param_1[0x1a] = iVar2;
  param_1[0x1d] = (int)(float)-iVar2;
  if (param_1[0x1c] < iVar2) {
    param_1[0x1c] = iVar2;
  }
  (**(code **)(*param_1 + 0x3f4))();
  pcStack_88 = (char *)0x8cbafe;
  pcStack_88 = operator_new(0x488);
  if (pcStack_88 != (void *)0x0) {
    pvStack_8c = (void *)0x8cbb19;
    FUN_007b5dd0();
  }
  pcStack_88 = (char *)0x8cbb30;
  (**(code **)(*param_1 + 0xa8))();
  pcStack_88 = "i_d_fesh_2d_wnd_frame_inner.xml";
  pvStack_8c = (void *)0x8cbb3e;
  (**(code **)(*piVar3 + 0x28))();
  pvStack_8c = (void *)0xffffffff;
  pcStack_90 = "i_d_fesh_2d_wnd_frame_btn_back.xml";
  (**(code **)(*param_1 + 0x404))();
  pcStack_9c = (char *)0x8cbb5d;
  pcStack_9c = operator_new(0x488);
  if (pcStack_9c == (char *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_007b5dd0();
  }
  param_1[0x24b] = iVar2;
  pcStack_9c = (char *)0x8cbb91;
  (**(code **)(*param_1 + 0xa8))();
  pcStack_9c = "i_d_fesh_2d_wnd_logo.xml";
  (**(code **)(*(int *)param_1[0x24b] + 0x28))();
  pcStack_a4 = (char *)0x8cbbab;
  pcStack_a4 = operator_new(0x488);
  pvStack_8c = pcStack_a4;
  if (pcStack_a4 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    uStack_a8 = 0x8cbbc6;
    iVar2 = FUN_007b5dd0();
  }
  param_1[0x24c] = iVar2;
  pcStack_a4 = (char *)0x8cbbdf;
  (**(code **)(*param_1 + 0xa8))();
  pcStack_a4 = "i_d_fesh_2d_wnd_version.xml";
  uStack_a8 = 0x8cbbef;
  (**(code **)(*(int *)param_1[0x24c] + 0x28))();
  uStack_a8 = DAT_00b047ec;
  uStack_ac = DAT_00b047e8;
  ppcStack_b0 = (char **)DAT_00b047e4;
  ppcStack_b4 = DAT_00b047e0;
  sprintf((char *)&pcStack_90,"v.%i.%i.%i.%i");
  uStack_a8 = 1;
  uStack_ac = 1;
  ppcStack_b0 = &pcStack_90;
  ppcStack_b4 = (char **)0x8cbc36;
  (**(code **)(*(int *)param_1[0x24c] + 0x1d8))();
  ppcStack_b4 = DAT_00b047fc;
  sprintf((char *)&pcStack_9c,"%i.%i.%i.%i",DAT_00b047f0,DAT_00b047f4,DAT_00b047f8);
  ppcStack_b4 = &pcStack_9c;
  (**(code **)(*(int *)param_1[0x24c] + 0x308))();
  pcStack_a4 = operator_new(0x488);
  if (pcStack_a4 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_007b5dd0(pcStack_a4,0);
  }
  param_1[0x24d] = iVar2;
  (**(code **)(*param_1 + 0xa8))(iVar2);
  (**(code **)(*(int *)param_1[0x24d] + 0x28))("i_d_fesh_2d_wnd_label_select.xml");
  iVar2 = param_1[0x1a] + 1;
  param_1[0x1a] = iVar2;
  param_1[0x1d] = (int)(float)-iVar2;
  if (param_1[0x1c] < iVar2) {
    param_1[0x1c] = iVar2;
  }
  (**(code **)(*param_1 + 0x3f4))(1);
  (**(code **)(*param_1 + 0x404))(&ppcStack_b4,"i_d_fesh_2d_wnd_frame_btn_login.xml",0xffffffff);
  pvVar1 = operator_new(0x4cc);
  iVar2 = 0;
  if (pvVar1 != (void *)0x0) {
    iVar2 = FUN_0079c860();
  }
  param_1[0x24e] = iVar2;
  (**(code **)(*param_1 + 0xa8))(iVar2);
  (**(code **)(*(int *)param_1[0x24e] + 0x28))("i_d_fesh_2d_btn_login.xml");
  (**(code **)(*(int *)param_1[0x24e] + 0x74))(40000);
  pvVar1 = operator_new(0x4cc);
  pvVar4 = (void *)0x0;
  if (pvVar1 != (void *)0x0) {
    pvVar4 = (void *)FUN_0079c860();
  }
  param_1[0x24f] = (int)pvVar4;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x24f] + 0x28))("i_d_fesh_2d_btn_back.xml");
  (**(code **)(*(int *)param_1[0x24f] + 0x74))(0x9c42);
  iVar2 = param_1[0x1a] + 1;
  param_1[0x1a] = iVar2;
  param_1[0x1d] = (int)(float)-iVar2;
  if (param_1[0x1c] < iVar2) {
    param_1[0x1c] = iVar2;
  }
  (**(code **)(*param_1 + 0x3f4))(1);
  pvVar1 = operator_new(0x4cc);
  pvStack_8c = (void *)0x8;
  iVar2 = 0;
  if (pvVar1 != (void *)0x0) {
    iVar2 = FUN_0079c860();
  }
  pvStack_8c = (void *)0xffffffff;
  param_1[0x250] = iVar2;
  (**(code **)(*param_1 + 0xa8))(iVar2);
  (**(code **)(*(int *)param_1[0x250] + 0x28))("i_d_fesh_2d_btn_sort_name.xml");
  (**(code **)(*(int *)param_1[0x250] + 0x74))(0x9c45);
  pvVar1 = operator_new(0x4cc);
  iVar2 = 0;
  if (pvVar1 != (void *)0x0) {
    iVar2 = FUN_0079c860();
  }
  param_1[0x251] = iVar2;
  (**(code **)(*param_1 + 0xa8))(iVar2);
  (**(code **)(*(int *)param_1[0x251] + 0x28))("i_d_fesh_2d_btn_sort_capacity.xml");
  (**(code **)(*(int *)param_1[0x251] + 0x74))(0x9c46);
  pvVar1 = operator_new(0x9a8);
  pcStack_a4 = (char *)0xa;
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0078b6e0();
  }
  pcStack_a4 = (char *)0xffffffff;
  param_1[0x252] = iVar2;
  (**(code **)(*param_1 + 0xa8))(iVar2);
  (**(code **)(*(int *)param_1[0x252] + 0x28))("i_d_fesh_2d_lb_name.xml");
  (**(code **)(*(int *)param_1[0x252] + 0x474))(0x9c48);
  (**(code **)(*(int *)param_1[0x252] + 0x74))(0x9c48);
  (**(code **)(*(int *)param_1[0x252] + 0x43c))();
  pvVar1 = operator_new(0x9a8);
  ppcStack_b4 = (char **)0xb;
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0078b6e0();
  }
  ppcStack_b4 = (char **)0xffffffff;
  param_1[0x253] = iVar2;
  (**(code **)(*param_1 + 0xa8))(iVar2);
  (**(code **)(*(int *)param_1[0x253] + 0x28))("i_d_fesh_2d_lb_capacity.xml");
  (**(code **)(*(int *)param_1[0x253] + 0x474))(0x9c48);
  (**(code **)(*(int *)param_1[0x253] + 0x74))(0x9c48);
  (**(code **)(*(int *)param_1[0x253] + 0x43c))();
  pvVar1 = operator_new(0x954);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0078f890();
  }
  param_1[0x254] = iVar2;
  (**(code **)(*param_1 + 0xa8))(iVar2);
  (**(code **)(*(int *)param_1[0x254] + 0x28))("i_d_fesh_2d_sb_shards.xml");
  (**(code **)(*(int *)param_1[0x254] + 0x43c))();
  (**(code **)(*(int *)param_1[0x254] + 0x74))(0x9c47);
  param_1[0x1a] = param_1[0x1a] + 1;
  iVar2 = param_1[0x1a];
  param_1[0x1d] = (int)(float)-iVar2;
  if (param_1[0x1c] < iVar2) {
    param_1[0x1c] = iVar2;
  }
  (**(code **)(*param_1 + 0x3f4))(1);
  FUN_007fbe50();
  param_1[0x126] = 40000;
  param_1[0x127] = 0x9c42;
  FUN_008ca6c0();
  if ((int *)param_1[0x252] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0x252] + 0x448))(param_1[0x154],param_1[0x155]);
    uVar5 = (**(code **)(*(int *)param_1[0x252] + 0x44c))();
    *(undefined8 *)(param_1 + 0x154) = uVar5;
  }
  (**(code **)(*param_1 + 0x34c))();
  ExceptionList = pvVar4;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
