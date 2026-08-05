# Annotated low-level: FUN_008dcb00

| Field | Value |
|---|---|
| Stable ID | `aa_008dcb00` |
| VA | `0x008dcb00` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008dcb00`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_008dcb00(int *param_1)

{
  char cVar1;
  void *pvVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uStack_e0;
  void *pvStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  char *pcStack_d0;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b7027;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00792600();
  pvVar2 = operator_new(0x488);
  local_4 = 0;
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_007b5dd0();
  }
  local_4 = 0xffffffff;
  param_1[0x155] = iVar3;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x155] + 0x28))();
  pvVar2 = operator_new(0x4cc);
  pvStack_c = (void *)0x1;
  iVar3 = 0;
  if (pvVar2 != (void *)0x0) {
    iVar3 = FUN_0079c860();
  }
  pvStack_c = (void *)0xffffffff;
  param_1[0x156] = iVar3;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x156] + 0x28))();
  (**(code **)(*(int *)param_1[0x156] + 0x74))();
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_007b5dd0();
  }
  param_1[0x157] = iVar3;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x157] + 0x28))();
  pvVar2 = operator_new(0x4cc);
  iVar3 = 0;
  if (pvVar2 != (void *)0x0) {
    iVar3 = FUN_0079c860();
  }
  param_1[0x158] = iVar3;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x158] + 0x28))();
  (**(code **)(*(int *)param_1[0x158] + 0x74))();
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_007b5dd0();
  }
  param_1[0x159] = iVar3;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x159] + 0x28))();
  pvVar2 = operator_new(0x4cc);
  iVar3 = 0;
  if (pvVar2 != (void *)0x0) {
    iVar3 = FUN_0079c860();
  }
  param_1[0x15a] = iVar3;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x15a] + 0x28))();
  (**(code **)(*(int *)param_1[0x15a] + 0x74))();
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_007b5dd0();
  }
  param_1[0x15b] = iVar3;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x15b] + 0x28))();
  pvVar2 = operator_new(0x4cc);
  iVar3 = 0;
  if (pvVar2 != (void *)0x0) {
    iVar3 = FUN_0079c860();
  }
  param_1[0x15c] = iVar3;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x15c] + 0x28))();
  (**(code **)(*(int *)param_1[0x15c] + 0x74))();
  (**(code **)(*(int *)param_1[0x15c] + 0x3b4))();
  (**(code **)(*(int *)param_1[0x15c] + 0x3c8))();
  if ((DAT_00d1b6d8 != 0) && (*(int *)(DAT_00d1b6d8 + 0xd30) < 0)) {
    (**(code **)(*(int *)param_1[0x15c] + 0x3c8))();
  }
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_007b5dd0();
  }
  param_1[0x15e] = iVar3;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x15e] + 0x28))();
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_007b5dd0();
  }
  param_1[0x15d] = iVar3;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x15d] + 0x28))();
  iVar3 = param_1[0x1a] + 1;
  param_1[0x1a] = iVar3;
  param_1[0x1d] = (int)(float)-iVar3;
  if (param_1[0x1c] < iVar3) {
    param_1[0x1c] = iVar3;
  }
  (**(code **)(*param_1 + 0x3f4))();
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_007b5dd0();
  }
  param_1[0x15f] = iVar3;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x15f] + 0x28))();
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_007b5dd0();
  }
  param_1[0x160] = iVar3;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x160] + 0x28))();
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_007b5dd0();
  }
  param_1[0x161] = iVar3;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x161] + 0x28))();
  (**(code **)(*(int *)param_1[0x161] + 0xcc))();
  if ((-1 < param_1[0x14b]) && (param_1[0x14b] < 0x32)) {
    (**(code **)(*param_1 + 0x454))();
    (**(code **)(*param_1 + 0x458))();
    (**(code **)(*param_1 + 0x45c))();
  }
  iVar3 = param_1[0x1a] + 1;
  param_1[0x1a] = iVar3;
  param_1[0x1d] = (int)(float)-iVar3;
  if (param_1[0x1c] < iVar3) {
    param_1[0x1c] = iVar3;
  }
  (**(code **)(*param_1 + 0x3f4))();
  pvVar2 = operator_new(0x4cc);
  iVar3 = 0;
  if (pvVar2 != (void *)0x0) {
    iVar3 = FUN_0079c860();
  }
  param_1[0x141] = iVar3;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x141] + 0x28))();
  (**(code **)(*(int *)param_1[0x141] + 0x74))();
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_007b5dd0();
  }
  param_1[0x166] = iVar3;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x166] + 0x28))();
  pcStack_d0 = (char *)0x8dd0e4;
  pvVar2 = operator_new(0x4cc);
  iVar3 = 0;
  if (pvVar2 != (void *)0x0) {
    iVar3 = FUN_0079c860();
  }
  param_1[0x167] = iVar3;
  pcStack_d0 = (char *)0x8dd115;
  (**(code **)(*param_1 + 0xa8))();
  pcStack_d0 = "i_d_first_2d_btn_hide_tips.xml";
  uStack_d4 = 0x8dd125;
  (**(code **)(*(int *)param_1[0x167] + 0x28))();
  uStack_d4 = 0x9c41;
  uStack_d8 = 0x8dd135;
  (**(code **)(*(int *)param_1[0x167] + 0x74))();
  uStack_d8 = 1;
  pvStack_dc = (void *)0x8dd145;
  (**(code **)(*(int *)param_1[0x167] + 0x3b4))();
  pvStack_dc = (void *)0x1;
  uStack_e0 = 0;
  (**(code **)(*(int *)param_1[0x167] + 0x3c8))();
  if ((DAT_00d1b6d8 != 0) &&
     (cVar1 = -(char)((int)*(undefined4 *)(DAT_00d1b6d8 + 0xd30) >> 0x1f),
     uStack_d4 = CONCAT13(cVar1,(undefined3)uStack_d4), cVar1 != '\0')) {
    (**(code **)(*(int *)param_1[0x167] + 0x3c8))(1,1);
  }
  pcStack_d0 = operator_new(0x488);
  if (pcStack_d0 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_007b5dd0(pcStack_d0,0);
  }
  param_1[0x16b] = iVar3;
  (**(code **)(*param_1 + 0xa8))(iVar3);
  (**(code **)(*(int *)param_1[0x16b] + 0x28))("i_d_first_2d_wnd_minimize_effect.xml");
  (**(code **)(*(int *)param_1[0x16b] + 4))(0);
  pvStack_dc = operator_new(0x488);
  if (pvStack_dc == (void *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)FUN_007b5dd0(pvStack_dc,0);
  }
  (**(code **)(*piVar4 + 0x28))("i_d_first_2d_wnd_minimize_location.xml");
  piVar5 = (int *)(**(code **)(*piVar4 + 0x120))(&uStack_e0,1,0);
  iVar3 = piVar5[1];
  param_1[0x149] = *piVar5;
  param_1[0x14a] = iVar3;
  (**(code **)*piVar4)(1);
  pvVar2 = operator_new(0x4cc);
  uStack_e0 = 0x12;
  iVar3 = 0;
  if (pvVar2 != (void *)0x0) {
    iVar3 = FUN_0079c860();
  }
  uStack_e0 = 0xffffffff;
  param_1[0x168] = iVar3;
  (**(code **)(*param_1 + 0xa8))(iVar3);
  (**(code **)(*(int *)param_1[0x168] + 0x28))("i_d_first_2d_btn_minimize.xml");
  (**(code **)(*(int *)param_1[0x168] + 0x74))(0x9c42);
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_007b5dd0(pvVar2,0);
  }
  param_1[0x169] = iVar3;
  (**(code **)(*param_1 + 0xa8))(iVar3);
  (**(code **)(*(int *)param_1[0x169] + 0x28))("i_d_first_2d_wnd_queued_tip_count.xml");
  (**(code **)(*(int *)param_1[0x169] + 0xcc))(0);
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_007b5dd0(pvVar2,0);
  }
  param_1[0x162] = iVar3;
  (**(code **)(*param_1 + 0xa8))(iVar3);
  (**(code **)(*(int *)param_1[0x162] + 0x28))("i_d_first_2d_wnd_prev_tip.xml");
  pvVar2 = operator_new(0x4cc);
  iVar3 = 0;
  if (pvVar2 != (void *)0x0) {
    iVar3 = FUN_0079c860();
  }
  param_1[0x163] = iVar3;
  (**(code **)(*param_1 + 0xa8))(iVar3);
  (**(code **)(*(int *)param_1[0x163] + 0x28))("i_d_first_2d_btn_prev_tip.xml");
  (**(code **)(*(int *)param_1[0x163] + 0x74))(0x9c44);
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_007b5dd0(pvVar2,0);
  }
  param_1[0x164] = iVar3;
  (**(code **)(*param_1 + 0xa8))(iVar3);
  (**(code **)(*(int *)param_1[0x164] + 0x28))("i_d_first_2d_wnd_next_tip.xml");
  pvVar2 = operator_new(0x4cc);
  iVar3 = 0;
  if (pvVar2 != (void *)0x0) {
    iVar3 = FUN_0079c860();
  }
  param_1[0x165] = iVar3;
  (**(code **)(*param_1 + 0xa8))(iVar3);
  (**(code **)(*(int *)param_1[0x165] + 0x28))();
  (**(code **)(*(int *)param_1[0x165] + 0x74))(0x9c43);
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_007b5dd0(pvVar2,0);
  }
  param_1[0x16a] = iVar3;
  (**(code **)(*param_1 + 0xa8))(iVar3);
  (**(code **)(*(int *)param_1[0x16a] + 0x28))("i_d_first_2d_wnd_minimize_effect.xml");
  (**(code **)(*(int *)param_1[0x16a] + 4))(0);
  *(undefined1 *)(param_1 + 0x146) = 0;
  (**(code **)(*param_1 + 0x110))(param_1 + 0x147);
  (**(code **)(*param_1 + 0x464))(1);
  FUN_008db100();
  FUN_008db480();
  (**(code **)(*param_1 + 0x34c))();
  ExceptionList = s_i_d_first_2d_btn_next_tip_xml_00a3dd4c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
