// =============================================================================
// QuickBar_BuildSkillButtonWidgets
// -----------------------------------------------------------------------------
// Stable ID: aa_00829490
// Address:   0x00829490  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-23 human-refined from raw capture
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Constructs skill quickbar button child widgets: background, icon, name, value, keynum, cooldown gauge (i_d_qb_2d_btn_quickbar_cooldown.xml), activate FX.
 *
 * Notes:
 * - SEH frame; FUN_00792600() then repeated operator_new(0x488)+FUN_007b5dd0 child ctor.
 * - Each child: parent vtable+0xa8 attach, vtable+0x28 load XML path, store ptr at button+0x560/0x564/…
 * - Z-order via button+0x68 child count and +0x74 float depth.
 * - Cooldown gauge XML: i_d_qb_2d_btn_quickbar_cooldown.xml.
 */

void __fastcall QuickBar_BuildSkillButtonWidgets(void *pButton)
{
    (void)pButton;
    /* allocate/load bg, icon, name, value, keynum, cooldown, FX — see raw */
}

// ---- Full decompiler body (width-normalized; human notes above) ----
/* QuickBar_BuildSkillButtonWidgets

   

   Constructs skill quickbar button children: bg, icon, name, value, keynum,

   i_d_qb_2d_btn_quickbar_cooldown.xml gauge, activate FX. */



void __fastcall QuickBar_BuildSkillButtonWidgets(void *pButton)



{

  void *pvVar1;

  int *piVar2;

  int iVar3;

  uint32_t /* decomp width */ uVar4;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* decomp width */ local_4;

  

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

  *(uint32_t /* decomp width */ *)((int)pButton + 0x56c) = uVar4;

  (**(code **)(*(int *)pButton + 0xa8))(uVar4);

  (**(code **)(**(int **)((int)pButton + 0x56c) + 0x28))("i_d_qb_2d_btn_quickbar_activate_fx.xml");

  (**(code **)(**(int **)((int)pButton + 0x56c) + 4))(0);

  FUN_00826780(0);

  (**(code **)(*(int *)pButton + 0x444))();

  (**(code **)(*(int *)pButton + 0x34c))();

  ExceptionList = s_i_d_qb_2d_btn_quickbar_btn_xml_00a74ef8;

  return;

}
