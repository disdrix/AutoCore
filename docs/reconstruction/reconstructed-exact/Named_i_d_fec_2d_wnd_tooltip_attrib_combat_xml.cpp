// READABILITY (auto CF):
//  - Body size: ~491 non-empty decompiler lines.
//  - Control keywords: if×31, goto×2, return×1.
//  - Notable callees: FUN_007b5dd0×7, FUN_0097ffa0×4, FUN_0078f890×3, FUN_0079c860×3, FUN_00795f20×2, FUN_00792600, FUN_008cedd0, FUN_008cf120.
//  - Strings: "i_d_fec_2d_wnd_frame_bg_right.xml"; "i_d_fec_2d_wnd_frame_name.xml"; "i_d_fec_2d_wnd_frame_gender.xml"; "i_d_fec_2d_wnd_frame_faction.xml".
//  - Return sites: 1.

// =============================================================================
// Named_i_d_fec_2d_wnd_tooltip_attrib_combat_xml
// -----------------------------------------------------------------------------
// Stable ID: aa_008d5b60
// Address:   0x008d5b60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "i_d_fec_2d_wnd_tooltip_attrib_combat.xml"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Named_i_d_fec_2d_wnd_tooltip_attrib_combat_xml(int *param_1)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  void *pvVar4;

  int iVar5;

  char *pcStack_9c;

  uint32_t /* width from decompiler */ uStack_98;

  char **ppcStack_94;

  char *pcStack_90;

  uint32_t /* width from decompiler */ uStack_8c;

  char **ppcStack_88;

  char *pcStack_84;

  uint32_t /* width from decompiler */ uStack_80;

  char **ppcStack_7c;

  char *pcStack_78;

  uint32_t /* width from decompiler */ uStack_74;

  char **ppcStack_70;

  char *pcStack_6c;

  uint32_t /* width from decompiler */ uStack_68;

  uint8_t *puStack_64;

  char *pcStack_60;

  uint32_t /* width from decompiler */ uStack_5c;

  uint32_t /* width from decompiler */ uStack_58;

  char *pcStack_54;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ba0e1;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  pvVar4 = operator_new(0x488);

  local_4 = 0;

  if (pvVar4 == (void *)0x0) {

    iVar5 = 0;

  }

  else {

    iVar5 = FUN_007b5dd0();

  }

  local_4 = 0xffffffff;

  param_1[0x154] = iVar5;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x154] + 0x28))();

  (**(code **)(*(int *)param_1[0x154] + 0x74))();

  pvVar4 = operator_new(0x488);

  if (pvVar4 == (void *)0x0) {

    iVar5 = 0;

  }

  else {

    iVar5 = FUN_007b5dd0();

  }

  param_1[0x18e] = iVar5;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x18e] + 0x28))();

  pvVar4 = operator_new(0x488);

  if (pvVar4 == (void *)0x0) {

    iVar5 = 0;

  }

  else {

    iVar5 = FUN_007b5dd0();

  }

  param_1[399] = iVar5;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[399] + 0x28))();

  iVar5 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar5;

  param_1[0x1d] = (int)(float)-iVar5;

  if (param_1[0x1c] < iVar5) {

    param_1[0x1c] = iVar5;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvVar4 = operator_new(0x488);

  if (pvVar4 == (void *)0x0) {

    iVar5 = 0;

  }

  else {

    iVar5 = FUN_007b5dd0();

  }

  param_1[400] = iVar5;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[400] + 0x28))();

  pcStack_54 = (char *)0x8d5cfc;

  pcStack_54 = operator_new(0x488);

  if (pcStack_54 == (char *)0x0) {

    iVar5 = 0;

  }

  else {

    uStack_58 = 0x8d5d16;

    iVar5 = FUN_007b5dd0();

  }

  param_1[0x191] = iVar5;

  pcStack_54 = (char *)0x8d5d2f;

  (**(code **)(*param_1 + 0xa8))();

  pcStack_54 = "i_d_fec_2d_wnd_frame_bg_right.xml";

  uStack_58 = 0x8d5d3f;

  (**(code **)(*(int *)param_1[0x191] + 0x28))();

  iVar5 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar5;

  param_1[0x1d] = (int)(float)-iVar5;

  if (param_1[0x1c] < iVar5) {

    param_1[0x1c] = iVar5;

  }

  uStack_58 = 1;

  uStack_5c = 0x8d5d69;

  (**(code **)(*param_1 + 0x3f4))();

  uStack_5c = 0xffffffff;

  pcStack_60 = "i_d_fec_2d_wnd_frame_name.xml";

  puStack_64 = &stack0xffffffb8;

  uStack_68 = 0x8d5d82;

  (**(code **)(*param_1 + 0x404))();

  uStack_68 = 0xffffffff;

  pcStack_6c = "i_d_fec_2d_wnd_frame_gender.xml";

  ppcStack_70 = &pcStack_54;

  uStack_74 = 0x8d5d97;

  (**(code **)(*param_1 + 0x404))();

  uStack_74 = 0xffffffff;

  pcStack_78 = "i_d_fec_2d_wnd_frame_faction.xml";

  ppcStack_7c = &pcStack_60;

  uStack_80 = 0x8d5dac;

  (**(code **)(*param_1 + 0x404))();

  uStack_80 = 0xffffffff;

  pcStack_84 = "i_d_fec_2d_wnd_frame_class.xml";

  ppcStack_88 = &pcStack_6c;

  uStack_8c = 0x8d5dc1;

  (**(code **)(*param_1 + 0x404))();

  uStack_8c = 0xffffffff;

  pcStack_90 = "i_d_fec_2d_wnd_frame_customization.xml";

  ppcStack_94 = &pcStack_78;

  uStack_98 = 0x8d5dd6;

  (**(code **)(*param_1 + 0x404))();

  uStack_98 = 0xffffffff;

  pcStack_9c = "i_d_fec_2d_wnd_frame_custom_player.xml";

  (**(code **)(*param_1 + 0x404))(&pcStack_84);

  (**(code **)(*param_1 + 0x404))(&pcStack_90,"i_d_fec_2d_wnd_frame_btn_create.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))(&pcStack_9c,"i_d_fec_2d_wnd_frame_btn_back.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x1a7,"i_d_fec_2d_wnd_frame_custom_body.xml",0xffffffff)

  ;

  (**(code **)(*param_1 + 0x404))

            (param_1 + 0x1a8,"i_d_fec_2d_wnd_frame_custom_vehicle.xml",0xffffffff);

  pvVar4 = operator_new(0x488);

  if (pvVar4 == (void *)0x0) {

    iVar5 = 0;

  }

  else {

    iVar5 = FUN_007b5dd0(pvVar4,0);

  }

  param_1[0x153] = iVar5;

  (**(code **)(*param_1 + 0xa8))(iVar5);

  (**(code **)(*(int *)param_1[0x153] + 0x28))("i_d_fec_2d_wnd_rotate_base.xml");

  iVar5 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar5;

  param_1[0x1d] = (int)(float)-iVar5;

  if (param_1[0x1c] < iVar5) {

    param_1[0x1c] = iVar5;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  pvVar4 = operator_new(0x488);

  if (pvVar4 == (void *)0x0) {

    iVar5 = 0;

  }

  else {

    iVar5 = FUN_007b5dd0(pvVar4,0);

  }

  param_1[0x155] = iVar5;

  (**(code **)(*param_1 + 0xa8))(iVar5);

  (**(code **)(*(int *)param_1[0x155] + 0x28))("i_d_fec_2d_wnd_logo.xml");

  iVar5 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar5;

  param_1[0x1d] = (int)(float)-iVar5;

  if (param_1[0x1c] < iVar5) {

    param_1[0x1c] = iVar5;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  pvVar4 = operator_new(0x4cc);

  iVar5 = 0;

  if (pvVar4 != (void *)0x0) {

    iVar5 = FUN_0079c860();

  }

  param_1[0x156] = iVar5;

  (**(code **)(*param_1 + 0xa8))(iVar5);

  (**(code **)(*(int *)param_1[0x156] + 0x28))("i_d_fec_2d_btn_create.xml");

  (**(code **)(*(int *)param_1[0x156] + 0x74))(40000);

  pvVar4 = operator_new(0x4cc);

  iVar5 = 0;

  if (pvVar4 != (void *)0x0) {

    iVar5 = FUN_0079c860();

  }

  param_1[0x157] = iVar5;

  (**(code **)(*param_1 + 0xa8))(iVar5);

  (**(code **)(*(int *)param_1[0x157] + 0x28))("i_d_fec_2d_btn_back.xml");

  (**(code **)(*(int *)param_1[0x157] + 0x74))(0x9c41);

  pvVar4 = operator_new(0x4cc);

  iVar5 = 0;

  if (pvVar4 != (void *)0x0) {

    iVar5 = FUN_0079c860();

  }

  param_1[0x192] = iVar5;

  (**(code **)(*param_1 + 0xa8))(iVar5);

  (**(code **)(*(int *)param_1[0x192] + 0x28))("i_d_fec_2d_btn_randomize.xml");

  (**(code **)(*(int *)param_1[0x192] + 0x74))(0x9c45);

  (**(code **)(*param_1 + 0x408))(param_1 + 0x158,"i_d_fec_2d_btn_rotate_cw.xml",0x9c43);

  (**(code **)(*param_1 + 0x408))(param_1 + 0x159,"i_d_fec_2d_btn_rotate_ccw.xml",0x9c44);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x1a9,"i_d_fec_2d_wnd_bg_name.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x1aa,"i_d_fec_2d_wnd_bg_name_vehicle.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x1ab,"i_d_fec_2d_wnd_label_name.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))

            (param_1 + 0x1ac,"i_d_fec_2d_wnd_label_name_vehicle.xml",0xffffffff);

  pvVar4 = operator_new(0x4a4);

  iVar5 = 0;

  if (pvVar4 != (void *)0x0) {

    iVar5 = FUN_00795f20();

  }

  param_1[0x1ad] = iVar5;

  (**(code **)(*param_1 + 0xa8))(iVar5);

  (**(code **)(*(int *)param_1[0x1ad] + 0x28))("i_d_fec_2d_edt_name.xml");

  (**(code **)(*(int *)param_1[0x1ad] + 0x74))(0x9c46);

  *(uint8_t *)(param_1[0x1ad] + 0x48c) = 1;

  *(uint8_t *)(param_1[0x1ad] + 0x48d) = 1;

  (**(code **)(*(int *)param_1[0x1ad] + 0x1d0))(0x10);

  iVar5 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar5;

  param_1[0x1d] = (int)(float)-iVar5;

  if (param_1[0x1c] < iVar5) {

    param_1[0x1c] = iVar5;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  (**(code **)(*param_1 + 0x404))

            (param_1 + 0x19f,"i_d_fec_2d_wnd_label_select_gender.xml",0xffffffff);

  piVar1 = param_1 + 0x1af;

  (**(code **)(*param_1 + 0x40c))(piVar1,"i_d_fec_2d_btn_radio_gender_male.xml",0x9c4a,0x9c4c);

  piVar2 = param_1 + 0x1b0;

  (**(code **)(*param_1 + 0x40c))(piVar2,"i_d_fec_2d_btn_radio_gender_female.xml",0x9c4a,0x9c4b);

  (**(code **)(*(int *)*piVar1 + 0x308))(&DAT_00a40a04);

  (**(code **)(*(int *)*piVar2 + 0x308))("Female");

  if (param_1[0x169] == 0) {

    (**(code **)(*(int *)*piVar2 + 0x3c8))();

  }

  else {

    (**(code **)(*(int *)*piVar1 + 0x3c8))(1,1);

  }

  (**(code **)(*param_1 + 0x404))

            (param_1 + 0x1a0,"i_d_fec_2d_wnd_label_select_faction.xml",0xffffffff);

  piVar1 = param_1 + 0x1b1;

  (**(code **)(*param_1 + 0x40c))(piVar1,"i_d_fec_2d_btn_radio_race_human.xml",0x9c4d,0x9c4e);

  piVar2 = param_1 + 0x1b2;

  (**(code **)(*param_1 + 0x40c))(piVar2,"i_d_fec_2d_btn_radio_race_mutant.xml",0x9c4d,0x9c4f);

  piVar3 = param_1 + 0x1b3;

  (**(code **)(*param_1 + 0x40c))(piVar3,"i_d_fec_2d_btn_radio_race_biomek.xml",0x9c4d,0x9c50);

  (**(code **)(*(int *)*piVar1 + 0x308))("Human");

  (**(code **)(*(int *)*piVar2 + 0x308))("Mutant");

  (**(code **)(*(int *)*piVar3 + 0x308))("Biomek");

  if (param_1[0x16a] == 0) {

    iVar5 = *(int *)*piVar1;

LAB_008d62f1:

    (**(code **)(iVar5 + 0x3c8))(1,1);

  }

  else {

    if (param_1[0x16a] != 1) {

      iVar5 = *(int *)*piVar3;

      goto LAB_008d62f1;

    }

    (**(code **)(*(int *)*piVar2 + 0x3c8))(1,1);

  }

  (**(code **)(*param_1 + 0x404))

            (param_1 + 0x1a1,"i_d_fec_2d_wnd_label_select_class.xml",0xffffffff);

  (**(code **)(*param_1 + 0x40c))

            (param_1 + 0x1b4,"i_d_fec_2d_btn_radio_class_commando.xml",0x9c51,0x9c52);

  (**(code **)(*param_1 + 0x40c))

            (param_1 + 0x1b5,"i_d_fec_2d_btn_radio_class_engineer.xml",0x9c51,0x9c53);

  (**(code **)(*param_1 + 0x40c))

            (param_1 + 0x1b6,"i_d_fec_2d_btn_radio_class_officer.xml",0x9c51,0x9c54);

  (**(code **)(*param_1 + 0x40c))

            (param_1 + 0x1b7,"i_d_fec_2d_btn_radio_class_ranger.xml",0x9c51,0x9c55);

  FUN_008cedd0();

  iVar5 = param_1[0x16b];

  if (iVar5 == 0) {

    (**(code **)(*(int *)param_1[0x1b4] + 0x3c8))(1,1);

  }

  else {

    if (iVar5 == 1) {

      iVar5 = *(int *)param_1[0x1b5];

    }

    else {

      if (iVar5 == 2) {

        (**(code **)(*(int *)param_1[0x1b6] + 0x3c8))(1,1);

        goto LAB_008d63f6;

      }

      iVar5 = *(int *)param_1[0x1b7];

    }

    (**(code **)(iVar5 + 0x3c8))(1,1);

  }

LAB_008d63f6:

  (**(code **)(*param_1 + 0x40c))(param_1 + 0x1e5,"i_d_fec_2d_btn_camera_body.xml",0x9c74,0x9c75);

  (**(code **)(*param_1 + 0x40c))(param_1 + 0x1e6,"i_d_fec_2d_btn_camera_face.xml",0x9c74,0x9c76);

  (**(code **)(*param_1 + 0x40c))(param_1 + 0x1e7,"i_d_fec_2d_btn_camera_vehicle.xml",0x9c74,0x9c77)

  ;

  iVar5 = param_1[0x15a];

  if ((-1 < iVar5) && (iVar5 < 3)) {

    (**(code **)(*(int *)param_1[iVar5 + 0x1e5] + 0x3c8))(1,1);

  }

  (**(code **)(*param_1 + 0x404))(param_1 + 0x1a2,"i_d_fec_2d_wnd_label_customize.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))

            (param_1 + 0x1a3,"i_d_fec_2d_wnd_label_customize_player.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))

            (param_1 + 0x1a4,"i_d_fec_2d_wnd_label_customize_vehicle.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))

            (param_1 + 0x1a5,"i_d_fec_2d_wnd_label_vehicle_name.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))

            (param_1 + 0x1a6,"i_d_fec_2d_wnd_label_vehicle_model.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x1b8,"i_d_fec_2d_wnd_label_body_geo.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x1b9,"i_d_fec_2d_wnd_label_hair_geo.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x1ba,"i_d_fec_2d_wnd_label_hair_tex.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x1bb,"i_d_fec_2d_wnd_label_helm_geo.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x1bc,"i_d_fec_2d_wnd_label_acc1_geo.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x1bd,"i_d_fec_2d_wnd_label_acc2_geo.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x1be,"i_d_fec_2d_wnd_label_eyes_tex.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x1bf,"i_d_fec_2d_wnd_label_mouth_geo.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x1c0,"i_d_fec_2d_wnd_label_color_1.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x1c1,"i_d_fec_2d_wnd_label_color_2.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x1c2,"i_d_fec_2d_wnd_label_color_3.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x1d8,"i_d_fec_2d_wnd_swatch_color_1.xml",0x9c6f);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x1d9,"i_d_fec_2d_wnd_swatch_color_2.xml",0x9c70);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x1da,"i_d_fec_2d_wnd_swatch_color_3.xml",0x9c71);

  (**(code **)(*param_1 + 0x404))

            (param_1 + 0x1c3,"i_d_fec_2d_wnd_label_vehicle_trim.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))

            (param_1 + 0x1c4,"i_d_fec_2d_wnd_label_vehicle_color_primary.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))

            (param_1 + 0x1c5,"i_d_fec_2d_wnd_label_vehicle_color_secondary.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))

            (param_1 + 0x1c6,"i_d_fec_2d_wnd_label_vehicle_wheels.xml",0xffffffff);

  (**(code **)(*param_1 + 0x408))(param_1 + 0x1c7,"i_d_fec_2d_btn_change_body_geo_prev.xml",0x9c57);

  (**(code **)(*param_1 + 0x408))(param_1 + 0x1c8,"i_d_fec_2d_btn_change_body_geo_next.xml",0x9c58);

  (**(code **)(*param_1 + 0x408))(param_1 + 0x1c9,"i_d_fec_2d_btn_change_hair_geo_prev.xml",0x9c59);

  (**(code **)(*param_1 + 0x408))(param_1 + 0x1ca,"i_d_fec_2d_btn_change_hair_geo_next.xml",0x9c5a);

  (**(code **)(*param_1 + 0x408))(param_1 + 0x1cb,"i_d_fec_2d_btn_change_hair_tex_prev.xml",0x9c5b);

  (**(code **)(*param_1 + 0x408))(param_1 + 0x1cc,"i_d_fec_2d_btn_change_hair_tex_next.xml",0x9c5c);

  (**(code **)(*param_1 + 0x408))(param_1 + 0x1cd,"i_d_fec_2d_btn_change_helm_geo_prev.xml",0x9c5d);

  (**(code **)(*param_1 + 0x408))(param_1 + 0x1ce,"i_d_fec_2d_btn_change_helm_geo_next.xml",0x9c5e);

  (**(code **)(*param_1 + 0x408))(param_1 + 0x1cf,"i_d_fec_2d_btn_change_acc1_geo_prev.xml",0x9c5f);

  (**(code **)(*param_1 + 0x408))(param_1 + 0x1d0,"i_d_fec_2d_btn_change_acc1_geo_next.xml",0x9c60);

  (**(code **)(*param_1 + 0x408))(param_1 + 0x1d1,"i_d_fec_2d_btn_change_acc2_geo_prev.xml",0x9c61);

  (**(code **)(*param_1 + 0x408))(param_1 + 0x1d2,"i_d_fec_2d_btn_change_acc2_geo_next.xml",0x9c62);

  (**(code **)(*param_1 + 0x408))(param_1 + 0x1d3,"i_d_fec_2d_btn_change_eyes_tex_prev.xml",0x9c63);

  (**(code **)(*param_1 + 0x408))(param_1 + 0x1d4,"i_d_fec_2d_btn_change_eyes_tex_next.xml",0x9c64);

  (**(code **)(*param_1 + 0x408))(param_1 + 0x1d5,"i_d_fec_2d_btn_change_mouth_geo_prev.xml",0x9c65)

  ;

  (**(code **)(*param_1 + 0x408))(param_1 + 0x1d6,"i_d_fec_2d_btn_change_mouth_geo_next.xml",0x9c66)

  ;

  (**(code **)(*param_1 + 0x408))

            (param_1 + 0x1db,"i_d_fec_2d_btn_change_vehicle_wheels_prev.xml",0x9c6d);

  (**(code **)(*param_1 + 0x408))

            (param_1 + 0x1dc,"i_d_fec_2d_btn_change_vehicle_wheels_next.xml",0x9c6e);

  (**(code **)(*param_1 + 0x408))

            (param_1 + 0x1dd,"i_d_fec_2d_btn_change_vehicle_trim_prev.xml",0x9c67);

  (**(code **)(*param_1 + 0x408))

            (param_1 + 0x1de,"i_d_fec_2d_btn_change_vehicle_trim_next.xml",0x9c68);

  (**(code **)(*param_1 + 0x404))

            (param_1 + 0x1e3,"i_d_fec_2d_wnd_swatch_vehicle_color_primary.xml",0x9c72);

  (**(code **)(*param_1 + 0x404))

            (param_1 + 0x1e4,"i_d_fec_2d_wnd_swatch_vehicle_color_secondary.xml",0x9c73);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x193,"i_d_fec_2d_wnd_race_desc_fill.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x194,"i_d_fec_2d_wnd_race_desc_frame.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x195,"i_d_fec_2d_wnd_race_desc_title.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x196,"i_d_fec_2d_wnd_race_desc_text.xml",0xffffffff);

  pvVar4 = operator_new(0x954);

  if (pvVar4 == (void *)0x0) {

    iVar5 = 0;

  }

  else {

    iVar5 = FUN_0078f890();

  }

  param_1[0x1d7] = iVar5;

  (**(code **)(*param_1 + 0xa8))(iVar5);

  (**(code **)(*(int *)param_1[0x1d7] + 0x28))("i_d_fec_2d_sb_body_scale.xml");

  (**(code **)(*(int *)param_1[0x1d7] + 0x74))(0x9c56);

  (**(code **)(*(int *)param_1[0x1d7] + 0x43c))();

  (**(code **)(*(int *)param_1[0x1d7] + 0x468))(1);

  (**(code **)(*(int *)param_1[0x1d7] + 0x454))(0,0);

  pvVar4 = operator_new(0x954);

  if (pvVar4 == (void *)0x0) {

    iVar5 = 0;

  }

  else {

    iVar5 = FUN_0078f890();

  }

  param_1[0x197] = iVar5;

  (**(code **)(*param_1 + 0xa8))(iVar5);

  (**(code **)(*(int *)param_1[0x197] + 0x28))("i_d_fec_2d_sb_race_desc.xml");

  (**(code **)(*(int *)param_1[0x197] + 0x74))(0x9c48);

  (**(code **)(*(int *)param_1[0x197] + 0x43c))();

  (**(code **)(*(int *)param_1[0x197] + 0x468))(1);

  (**(code **)(*(int *)param_1[0x197] + 0x454))(0,0);

  param_1[0x198] = 0;

  (**(code **)(*param_1 + 0x404))(param_1 + 0x199,"i_d_fec_2d_wnd_class_desc_fill.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x19a,"i_d_fec_2d_wnd_class_desc_frame.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x19b,"i_d_fec_2d_wnd_class_desc_title.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x19c,"i_d_fec_2d_wnd_class_desc_text.xml",0xffffffff);

  pvVar4 = operator_new(0x4a4);

  iVar5 = 0;

  if (pvVar4 != (void *)0x0) {

    iVar5 = FUN_00795f20();

  }

  param_1[0x1ae] = iVar5;

  (**(code **)(*param_1 + 0xa8))(iVar5);

  (**(code **)(*(int *)param_1[0x1ae] + 0x28))("i_d_fec_2d_edt_vehicle_name.xml");

  (**(code **)(*(int *)param_1[0x1ae] + 0x74))(0x9c47);

  *(uint8_t *)(param_1[0x1ae] + 0x48c) = 1;

  *(uint8_t *)(param_1[0x1ae] + 0x48d) = 0;

  (**(code **)(*(int *)param_1[0x1ae] + 0x1d0))(0x20);

  pvVar4 = operator_new(0x954);

  if (pvVar4 == (void *)0x0) {

    iVar5 = 0;

  }

  else {

    iVar5 = FUN_0078f890();

  }

  param_1[0x19d] = iVar5;

  (**(code **)(*param_1 + 0xa8))(iVar5);

  (**(code **)(*(int *)param_1[0x19d] + 0x28))("i_d_fec_2d_sb_class_desc.xml");

  (**(code **)(*(int *)param_1[0x19d] + 0x74))(0x9c49);

  (**(code **)(*(int *)param_1[0x19d] + 0x43c))();

  (**(code **)(*(int *)param_1[0x19d] + 0x468))(1);

  (**(code **)(*(int *)param_1[0x19d] + 0x454))(0,0);

  param_1[0x19e] = 0;

  (**(code **)(*param_1 + 0x404))(param_1 + 0x1ee,"i_d_fec_2d_wnd_bg_attribs.xml",0xffffffff);

  pvVar4 = operator_new(0x4f8);

  if (pvVar4 == (void *)0x0) {

    iVar5 = 0;

  }

  else {

    iVar5 = FUN_0097ffa0(pvVar4);

  }

  param_1[500] = iVar5;

  (**(code **)(*param_1 + 0xa8))(iVar5);

  (**(code **)(*(int *)param_1[500] + 0x28))("i_d_fec_2d_wnd_gauge_attrib_combat.xml");

  (**(code **)(*(int *)param_1[500] + 0x3b0))(0);

  pvVar4 = operator_new(0x4f8);

  if (pvVar4 == (void *)0x0) {

    iVar5 = 0;

  }

  else {

    iVar5 = FUN_0097ffa0(pvVar4);

  }

  param_1[0x1f5] = iVar5;

  (**(code **)(*param_1 + 0xa8))(iVar5);

  (**(code **)(*(int *)param_1[0x1f5] + 0x28))("i_d_fec_2d_wnd_gauge_attrib_tech.xml");

  (**(code **)(*(int *)param_1[0x1f5] + 0x3b0))(0);

  pvVar4 = operator_new(0x4f8);

  if (pvVar4 == (void *)0x0) {

    iVar5 = 0;

  }

  else {

    iVar5 = FUN_0097ffa0(pvVar4);

  }

  param_1[0x1f6] = iVar5;

  (**(code **)(*param_1 + 0xa8))(iVar5);

  (**(code **)(*(int *)param_1[0x1f6] + 0x28))("i_d_fec_2d_wnd_gauge_attrib_theory.xml");

  (**(code **)(*(int *)param_1[0x1f6] + 0x3b0))(0);

  pvVar4 = operator_new(0x4f8);

  if (pvVar4 == (void *)0x0) {

    iVar5 = 0;

  }

  else {

    iVar5 = FUN_0097ffa0(pvVar4);

  }

  param_1[0x1f7] = iVar5;

  (**(code **)(*param_1 + 0xa8))(iVar5);

  (**(code **)(*(int *)param_1[0x1f7] + 0x28))("i_d_fec_2d_wnd_gauge_attrib_perception.xml");

  (**(code **)(*(int *)param_1[0x1f7] + 0x3b0))(0);

  (**(code **)(*param_1 + 0x404))(param_1 + 499,"i_d_fec_2d_wnd_label_attributes.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))

            (param_1 + 0x1f8,"i_d_fec_2d_wnd_tooltip_attrib_combat.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))

            (param_1 + 0x1f9,"i_d_fec_2d_wnd_tooltip_attrib_tech.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x1fa,"i_d_fec_2d_wnd_tooltip_attrib_theory.xml");

  (**(code **)(*param_1 + 0x404))

            (param_1 + 0x1fb,"i_d_fec_2d_wnd_tooltip_attrib_perception.xml",0xffffffff);

  FUN_008d1600();

  FUN_008d1370();

  FUN_008d44a0();

  FUN_008cf120();

  param_1[0x126] = 40000;

  param_1[0x127] = 0x9c41;

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = (void *)0xffffffff;

  return;

}
