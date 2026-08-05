# Raw capture: QuickBar_BuildSkillButtonWidgets

| Field | Value |
|---|---|
| **Stable ID** | `aa_00829490` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00829490` |
| **Canonical name** | `QuickBar_BuildSkillButtonWidgets` |
| **System** | skills-abilities |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* QuickBar_BuildSkillButtonWidgets
   
   Constructs skill quickbar button children: bg, icon, name, value, keynum,
   i_d_qb_2d_btn_quickbar_cooldown.xml gauge, activate FX. */

void __fastcall QuickBar_BuildSkillButtonWidgets(void *pButton)

{
  void *pvVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b8555;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00792600();
  pvVar1 = operator_new(0x488);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_007b5dd0(pvVar1,0);
  }
  local_4 = 0xffffffff;
  (**(code **)(*(int *)pButton + 0xa8))(piVar2);
  (**(code **)(*piVar2 + 0x28))("i_d_qb_2d_btn_quickbar_bg.xml");
  iVar3 = *(int *)((int)pButton + 0x68) + 1;
  *(int **)((int)pButton + 0x560) = piVar2;
  *(int *)((int)pButton + 0x68) = iVar3;
  *(float *)((int)pButton + 0x74) = (float)-iVar3;
  if (*(int *)((int)pButton + 0x70) < iVar3) {
    *(int *)((int)pButton + 0x70) = iVar3;
  }
  (**(code **)(*(int *)pButton + 0x3f4))(1);
  pvVar1 = operator_new(0x488);
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_007b5dd0(pvVar1,0);
  }
  (**(code **)(*(int *)pButton + 0xa8))(piVar2);
  (**(code **)(*piVar2 + 0x28))("i_d_qb_2d_btn_quickbar_icon.xml");
  iVar3 = *(int *)((int)pButton + 0x68) + 1;
  *(int **)((int)pButton + 0x564) = piVar2;
  *(int *)((int)pButton + 0x68) = iVar3;
  *(float *)((int)pButton + 0x74) = (float)-iVar3;
  if (*(int *)((int)pButton + 0x70) < iVar3) {
    *(int *)((int)pButton + 0x70) = iVar3;
  }
  (**(code **)(*(int *)pButton + 0x3f4))(1);
  (**(code **)(*(int *)pButton + 0x404))
            ((int)pButton + 0x574,"i_d_qb_2d_btn_quickbar_name.xml",0xffffffff);
  (**(code **)(*(int *)pButton + 0x404))
            ((int)pButton + 0x578,"i_d_qb_2d_btn_quickbar_value.xml",0xffffffff);
  pvVar1 = operator_new(0x488);
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_007b5dd0(pvVar1,0);
  }
  (**(code **)(*(int *)pButton + 0xa8))(piVar2);
  (**(code **)(*piVar2 + 0x28))("i_d_qb_2d_btn_quickbar_keynum.xml");
  iVar3 = *(int *)((int)pButton + 0x68) + 1;
  *(int **)((int)pButton + 0x568) = piVar2;
  *(int *)((int)pButton + 0x68) = iVar3;
  *(float *)((int)pButton + 0x74) = (float)-iVar3;
  if (*(int *)((int)pButton + 0x70) < iVar3) {
    *(int *)((int)pButton + 0x70) = iVar3;
  }
  (**(code **)(*(int *)pButton + 0x3f4))(1);
  pvVar1 = operator_new(0x4bc);
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = UI_CooldownGaugeWidget_ctor(pvVar1);
  }
  (**(code **)(*(int *)pButton + 0xa8))(piVar2);
  (**(code **)(*piVar2 + 0x28))("i_d_qb_2d_btn_quickbar_cooldown.xml");
  (**(code **)(*piVar2 + 0x24))(1);
  iVar3 = *(int *)((int)pButton + 0x68) + 1;
  *(int **)((int)pButton + 0x570) = piVar2;
  *(int *)((int)pButton + 0x68) = iVar3;
  *(float *)((int)pButton + 0x74) = (float)-iVar3;
  if (*(int *)((int)pButton + 0x70) < iVar3) {
    *(int *)((int)pButton + 0x70) = iVar3;
  }
  (**(code **)(*(int *)pButton + 0x3f4))(1);
  pvVar1 = operator_new(0x4cc);
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_0079c860();
  }
  (**(code **)(*(int *)pButton + 0xa8))(piVar2);
  (**(code **)(*piVar2 + 0x74))(60000);
  (**(code **)(*piVar2 + 0x28))();
  iVar3 = *(int *)((int)pButton + 0x68) + 1;
  *(int **)((int)pButton + 0x57c) = piVar2;
  *(int *)((int)pButton + 0x68) = iVar3;
  *(float *)((int)pButton + 0x74) = (float)-iVar3;
  if (*(int *)((int)pButton + 0x70) < iVar3) {
    *(int *)((int)pButton + 0x70) = iVar3;
  }
  (**(code **)(*(int *)pButton + 0x3f4))(1);
  pvVar1 = operator_new(0x488);
  if (pvVar1 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_007b5dd0(pvVar1,0);
  }
  *(undefined4 *)((int)pButton + 0x56c) = uVar4;
  (**(code **)(*(int *)pButton + 0xa8))(uVar4);
  (**(code **)(**(int **)((int)pButton + 0x56c) + 0x28))("i_d_qb_2d_btn_quickbar_activate_fx.xml");
  (**(code **)(**(int **)((int)pButton + 0x56c) + 4))(0);
  FUN_00826780(0);
  (**(code **)(*(int *)pButton + 0x444))();
  (**(code **)(*(int *)pButton + 0x34c))();
  ExceptionList = s_i_d_qb_2d_btn_quickbar_btn_xml_00a74ef8;
  return;
}
```
