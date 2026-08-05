// =============================================================================
// UI_clanman_label_titles
// -----------------------------------------------------------------------------
// Stable ID: aa_008f1a30
// Address:   0x008f1a30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_clanman_label_titles @ 0x008f1a30
// Stable ID: aa_008f1a30
// Embedded strings (evidence for future rename):
//   - "i_d_clanman_2d_btn_details.xml"
//   - "i_d_clanman_2d_wnd_label_details.xml"
//   - "i_d_clanman_2d_btn_accept_changes.xml"
//   - "i_d_clanman_2d_wnd_label_titles_%d.xml"
//   - "i_d_clanman_2d_wnd_edit_titles_%d.xml"
//   - "i_d_clanman_2d_btn_close.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~398 non-empty decompiler lines.
//  - Control keywords: if×45, do×1, while×1, return×1.
//  - Notable callees: FUN_007b5dd0×17, FUN_0079c860×4, FUN_00795f20×3, FUN_008f0f40×3, FUN_008f0f80×3, FUN_008f1070×3, FUN_008f1290×2, FUN_004c22a0.
//  - Strings: "i_d_clanman_2d_btn_details.xml"; "i_d_clanman_2d_wnd_label_details.xml"; "i_d_clanman_2d_btn_accept_changes.xml"; "i_d_clanman_2d_wnd_label_titles_%d.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_clanman_2d_wnd_label_titles_%d.xml"
 * Domain alias of FUN_008f1a30 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall UI_clanman_label_titles(int *param_1)



{

  void *pvVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  code *pcVar6;

  char *pcStack_1fc;

  void *pvStack_104;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b7891;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  pvVar1 = operator_new(0x488);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  local_4 = 0xffffffff;

  param_1[0x149] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x149] + 0x28))();

  iVar2 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvVar1 = operator_new(0x4bc);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_00864f20();

  }

  param_1[0x14a] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x14a] + 0x28))();

  iVar2 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x14b] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x14b] + 0x28))();

  iVar2 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x14c] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x14c] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x14d] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x14d] + 0x28))();

  (**(code **)(*param_1 + 0x404))();

  iVar2 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x14e] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x14e] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x150] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x150] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x151] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x151] + 0x28))();

  iVar2 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x14f] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x14f] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x152] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x152] + 0x28))();

  FUN_008f19c0();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x154] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x154] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x153] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x153] + 0x28))();

  pvVar1 = operator_new(0x4a4);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_00795f20();

  }

  param_1[0x155] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x155] + 0x28))();

  *(uint8_t *)(param_1[0x155] + 0x48c) = 1;

  (**(code **)(*(int *)param_1[0x155] + 0x1d0))();

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x156] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x156] + 0x28))();

  (**(code **)(*(int *)param_1[0x156] + 0x74))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x158] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x158] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x15b] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x15b] + 0x28))();

  iVar2 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x157] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x157] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x159] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x159] + 0x28))();

  pvVar1 = operator_new(0x4a4);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_00795f20();

  }

  param_1[0x15a] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x15a] + 0x28))();

  (**(code **)(*(int *)param_1[0x15a] + 0x1d0))();

  (**(code **)(*(int *)param_1[0x15a] + 0x98))();

  *(uint8_t *)(param_1[0x15a] + 0xba) = 1;

  pcStack_1fc = (char *)0x8f21f9;

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x162] = iVar2;

  pcStack_1fc = (char *)0x8f2230;

  (**(code **)(*param_1 + 0xa8))();

  pcStack_1fc = "i_d_clanman_2d_btn_details.xml";

  (**(code **)(*(int *)param_1[0x162] + 0x28))();

  (**(code **)(*(int *)param_1[0x162] + 0x74))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1);

  }

  param_1[0x163] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x163] + 0x28))("i_d_clanman_2d_wnd_label_details.xml");

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x164] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x164] + 0x28))("i_d_clanman_2d_btn_accept_changes.xml");

  (**(code **)(*(int *)param_1[0x164] + 0x74))(0x9c43);

  iVar4 = 1;

  piVar5 = param_1 + 0x15f;

  iVar2 = 3;

  pcVar6 = sprintf_exref;

  do {

    pvVar1 = operator_new(0x488);

    if (pvVar1 == (void *)0x0) {

      iVar3 = 0;

    }

    else {

      iVar3 = FUN_007b5dd0(pvVar1,0);

    }

    piVar5[-3] = iVar3;

    (**(code **)(*param_1 + 0xa8))(iVar3);

    (*pcVar6)(&pcStack_1fc,"i_d_clanman_2d_wnd_label_titles_%d.xml",iVar4);

    (**(code **)(*(int *)piVar5[-3] + 0x28))(&pcStack_1fc);

    pvVar1 = operator_new(0x4a4);

    iVar3 = 0;

    if (pvVar1 != (void *)0x0) {

      iVar3 = FUN_00795f20();

      pcVar6 = sprintf_exref;

    }

    *piVar5 = iVar3;

    (**(code **)(*param_1 + 0xa8))(iVar3);

    (*pcVar6)(&stack0xfffffdfc,"i_d_clanman_2d_wnd_edit_titles_%d.xml",iVar4);

    (**(code **)(*(int *)*piVar5 + 0x28))(&stack0xfffffdfc);

    *(uint8_t *)(*piVar5 + 0x48c) = 1;

    (**(code **)(*(int *)*piVar5 + 0x1d0))(0x32);

    (**(code **)(*(int *)*piVar5 + 0x98))(iVar4);

    piVar5 = piVar5 + 1;

    iVar4 = iVar4 + 1;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x141] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x141] + 0x28))("i_d_clanman_2d_btn_close.xml");

  (**(code **)(*(int *)param_1[0x141] + 0x74))(40000);

  if ((DAT_00d1b6d8 == 0) || (*DAT_00d1da30 == -1)) {

    param_1[0x148] = 0;

    FUN_008f1070(1);

    FUN_008f0f80(0);

    FUN_008f0f40();

    if ((int *)param_1[0x14f] != (int *)0x0) {

      (**(code **)(*(int *)param_1[0x14f] + 0x1d8))

                ("If you wish to create a clan, input the name you would like into the box below and click \'Submit Clan\'.  Keep in mind, however, that founding a clan is not free.  It will cost you an amount specified by the \'Creation Fee\'."

                 ,1,1);

    }

    if ((int *)param_1[0x163] != (int *)0x0) {

      (**(code **)(*(int *)param_1[0x163] + 0x1d8))(&DAT_00a1419b,1,1);

    }

    if ((int *)param_1[0x14f] != (int *)0x0) {

      (**(code **)(*(int *)param_1[0x14f] + 0x34c))();

    }

    if ((int *)param_1[0x163] != (int *)0x0) {

      (**(code **)(*(int *)param_1[0x163] + 0x34c))();

    }

    FUN_008f1290();

    (**(code **)(*param_1 + 0x448))();

  }

  else {

    iVar2 = *(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4);

    iVar2 = FUN_004c22a0(*(uint32_t /* width from decompiler */ *)(iVar2 + 0x164 + DAT_00d1b6d8),

                         *(uint32_t /* width from decompiler */ *)(iVar2 + 0x168 + DAT_00d1b6d8));

    if ((iVar2 == 0) || (*(int *)(iVar2 + 0x24) < 2)) {

      param_1[0x148] = 2;

      FUN_008f1070(0);

      FUN_008f0f80(1);

      FUN_008f0f40();

      if ((int *)param_1[0x14f] != (int *)0x0) {

        (**(code **)(*(int *)param_1[0x14f] + 0x1d8))

                  ("Contact your Clan Leader if you need any of the clan settings changed.  The current settings are displayed below."

                   ,1,1);

      }

      if ((int *)param_1[0x163] != (int *)0x0) {

        (**(code **)(*(int *)param_1[0x163] + 0x1d8))("To view clan member details:",1,1);

      }

      if ((int *)param_1[0x164] != (int *)0x0) {

        (**(code **)(*(int *)param_1[0x164] + 0xcc))(0);

      }

    }

    else {

      param_1[0x148] = 1;

      FUN_008f1070(0);

      FUN_008f0f80(1);

      FUN_008f0f40();

      if ((int *)param_1[0x14f] != (int *)0x0) {

        (**(code **)(*(int *)param_1[0x14f] + 0x1d8))

                  ("As Clan Leader, you are entitled to alter the clan\'s titles and the Message of the Day.  Once you have made your changes, click the \'Accept Changes\' button to finalize them."

                   ,1,1);

      }

      if ((int *)param_1[0x163] != (int *)0x0) {

        (**(code **)(*(int *)param_1[0x163] + 0x1d8))("To promote/demote or kick clan members:",1,1)

        ;

      }

    }

    if ((int *)param_1[0x14f] != (int *)0x0) {

      (**(code **)(*(int *)param_1[0x14f] + 0x34c))();

    }

    if ((int *)param_1[0x163] != (int *)0x0) {

      (**(code **)(*(int *)param_1[0x163] + 0x34c))();

    }

    FUN_008f1290();

    (**(code **)(*param_1 + 0x448))();

  }

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = pvStack_104;

  return;

}
