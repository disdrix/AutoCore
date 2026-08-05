// READABILITY (auto CF):
//  - Body size: ~464 non-empty decompiler lines.
//  - Control keywords: if×30, do×1, while×1, return×1.
//  - Notable callees: FUN_007b5dd0×19, Client_BuildNpcMissionDialogWidgets, FUN_0078f890, FUN_00792600, FUN_0079c860, FUN_00864f20, FUN_008ac110.
//  - Strings: "i_d_npc_2d_btn_item.xml"; "i_d_npc_2d_wnd_item_bg.xml"; "i_d_npc_2d_wnd_item.xml"; "i_d_npc_2d_wnd_itemtext.xml".
//  - Return sites: 1.

// =============================================================================
// Client_BuildNpcMissionDialogWidgets
// -----------------------------------------------------------------------------
// Stable ID: aa_008ad240
// Address:   0x008ad240  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-07-23 human-refined from raw capture
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Construct full NPC mission dialog widget tree from i_d_npc_2d_*.xml (rewards, dialogue, item slots, close). Heavy MSXML load - must not race CompleteObjective / interact FX after turn-in.
 *
 * Notes:
 * - Clears dialog state slots param_1[0x194..0x19b] and byte at +0x160*4 path.
 * - Repeated operator_new(0x488)+FUN_007b5dd0 child pattern like other CreateChildWidgets.
 * - XML set includes i_d_npc_2d_wnd_rewards.xml, i_d_npc_2d_wnd_dialogue.xml.
 * - Large function (16k raw) - full tree in raw capture.
 */

void __fastcall Client_BuildNpcMissionDialogWidgets(int *pDialog)
{
    (void)pDialog;
    /* large widget tree - authoritative control flow in raw */
}

// ---- Full decompiler body (width-normalized; human notes above) ----
/* Client_BuildNpcMissionDialogWidgets

   

   Construct the full NPC mission dialog widget tree: many NDUIWindow children loaded from

   i_d_npc_2d_wnd_rewards.xml, i_d_npc_2d_wnd_dialogue.xml, item slots, close button, etc.

   Heavy MSXML load - must not race with CompleteObjective / interact FX after turn-in. */



void __fastcall Client_BuildNpcMissionDialogWidgets(int *param_1)



{

  float fVar1;

  void *pvVar2;

  int *piVar3;

  int iVar4;

  int *piVar5;

  byte *pbVar6;

  int iVar7;

  int iVar8;

  char **ppcStack_1b8;

  int **ppiStack_1b4;

  void *pvStack_1b0;

  char *pcStack_1ac;

  uint32_t /* decomp width */ *puStack_1a4;

  int *piStack_1a0;

  void *pvStack_19c;

  int iStack_198;

  int **ppiStack_194;

  int *piStack_190;

  int iStack_18c;

  char *pcStack_188;

  char *pcStack_184;

  int iStack_16c;

  int *piStack_168;

  void *pvStack_14;

  uint8_t *puStack_10;

  uint32_t /* decomp width */ local_c;

  

  local_c = 0xffffffff;

  puStack_10 = &LAB_009b9aa1;

  pvStack_14 = ExceptionList;

  ExceptionList = &pvStack_14;

  FUN_00792600();

  param_1[0x194] = 0;

  param_1[0x195] = 0;

  param_1[0x196] = 0;

  param_1[0x197] = 0;

  param_1[0x198] = 0;

  param_1[0x199] = 0;

  param_1[0x19a] = 0;

  param_1[0x19b] = 0;

  *(uint8_t *)(param_1 + 0x160) = 0;

  pvVar2 = operator_new(0x488);

  iVar8 = 0;

  local_c = 0;

  if (pvVar2 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_007b5dd0();

  }

  local_c = 0xffffffff;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar3 + 0x28))();

  (**(code **)(*piVar3 + 0xfc))();

  iVar4 = param_1[0x1a] + 1;

  param_1[0x1a0] = (int)piVar3;

  param_1[0x1a] = iVar4;

  param_1[0x1d] = (int)(float)-iVar4;

  if (param_1[0x1c] < iVar4) {

    param_1[0x1c] = iVar4;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvVar2 = operator_new(0x4bc);

  if (pvVar2 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_00864f20();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar3 + 0x28))();

  (**(code **)(*piVar3 + 0xfc))();

  iVar4 = param_1[0x1a] + 1;

  param_1[0x1a1] = (int)piVar3;

  param_1[0x1a] = iVar4;

  param_1[0x1d] = (int)(float)-iVar4;

  if (param_1[0x1c] < iVar4) {

    param_1[0x1c] = iVar4;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_007b5dd0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar3 + 0x28))();

  (**(code **)(*piVar3 + 0xfc))();

  param_1[0x1a2] = (int)piVar3;

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_007b5dd0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar3 + 0x28))();

  (**(code **)(*piVar3 + 0xcc))();

  param_1[0x1a4] = (int)piVar3;

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_007b5dd0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar3 + 0x28))();

  (**(code **)(*piVar3 + 0xfc))();

  iVar4 = param_1[0x1a] + 1;

  param_1[0x1a5] = (int)piVar3;

  param_1[0x1a] = iVar4;

  param_1[0x1d] = (int)(float)-iVar4;

  if (param_1[0x1c] < iVar4) {

    param_1[0x1c] = iVar4;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_007b5dd0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar3 + 0x28))();

  (**(code **)(*piVar3 + 0xfc))();

  param_1[0x1bb] = (int)piVar3;

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_007b5dd0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar3 + 0x28))();

  (**(code **)(*piVar3 + 0xfc))();

  param_1[0x1bc] = (int)piVar3;

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_007b5dd0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar3 + 0x28))();

  (**(code **)(*piVar3 + 0xfc))();

  param_1[0x1bd] = (int)piVar3;

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_007b5dd0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar3 + 0x28))();

  (**(code **)(*piVar3 + 0xfc))();

  param_1[0x1be] = (int)piVar3;

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_007b5dd0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar3 + 0x28))();

  (**(code **)(*piVar3 + 0xfc))();

  iVar4 = param_1[0x1a] + 1;

  param_1[0x1bf] = (int)piVar3;

  param_1[0x1a] = iVar4;

  param_1[0x1d] = (int)(float)-iVar4;

  if (param_1[0x1c] < iVar4) {

    param_1[0x1c] = iVar4;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_007b5dd0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar3 + 0x28))();

  (**(code **)(*piVar3 + 0xfc))();

  param_1[0x1b6] = (int)piVar3;

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_007b5dd0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar3 + 0x28))();

  (**(code **)(*piVar3 + 0xfc))();

  param_1[0x1b7] = (int)piVar3;

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_007b5dd0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar3 + 0x28))();

  (**(code **)(*piVar3 + 0xfc))();

  param_1[0x1b8] = (int)piVar3;

  pvVar2 = operator_new(0x954);

  if (pvVar2 == (void *)0x0) {

    iVar4 = 0;

  }

  else {

    iVar4 = FUN_0078f890();

  }

  param_1[0x1c0] = iVar4;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x1c0] + 0x28))();

  (**(code **)(*(int *)param_1[0x1c0] + 0x74))();

  (**(code **)(*(int *)param_1[0x1c0] + 0x43c))();

  (**(code **)(*(int *)param_1[0x1c0] + 0xcc))();

  (**(code **)(*(int *)param_1[0x1c0] + 0x468))();

  param_1[0x1c1] = 0;

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_007b5dd0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar3 + 0x28))();

  (**(code **)(*piVar3 + 0xfc))();

  param_1[0x1a3] = (int)piVar3;

  piStack_168 = (int *)0x8ad8d2;

  piVar3 = operator_new(0x488);

  if (piVar3 == (int *)0x0) {

    piVar5 = (int *)0x0;

  }

  else {

    iStack_16c = 0x8ad8ec;

    piStack_168 = piVar3;

    piVar5 = (int *)FUN_007b5dd0();

  }

  piStack_168 = (int *)0x8ad901;

  (**(code **)(*param_1 + 0xa8))();

  piStack_168 = (int *)0xa4af00;

  iStack_16c = 0x8ad90d;

  (**(code **)(*piVar5 + 0x28))();

  iStack_16c = 0x3f000000;

  (**(code **)(*piVar5 + 0xfc))();

  param_1[0x1b9] = (int)piVar5;

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    piVar5 = (int *)0x0;

  }

  else {

    piVar5 = (int *)FUN_007b5dd0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar5 + 0x28))();

  (**(code **)(*piVar5 + 0xcc))();

  param_1[0x1ba] = (int)piVar5;

  if (param_1[399] < 1) {

    param_1[399] = 1;

  }

  piStack_168 = param_1 + 0x1b2;

  do {

    iVar4 = iVar8 / param_1[399];

    iVar8 = iVar8 - param_1[399] * iVar4;

    pcStack_184 = (char *)0x8ad9bc;

    pcStack_184 = operator_new(0x488);

    if (pcStack_184 == (char *)0x0) {

      piVar5 = (int *)0x0;

    }

    else {

      pcStack_188 = (void *)0x8ad9d7;

      piVar5 = (int *)FUN_007b5dd0();

    }

    pcStack_184 = (char *)0x8ad9f0;

    (**(code **)(*param_1 + 0xa8))();

    pcStack_184 = "i_d_npc_2d_btn_item.xml";

    pcStack_188 = (char *)0x8ad9fc;

    (**(code **)(*piVar5 + 0x28))();

    pcStack_188 = (char *)0x0;

    iStack_18c = 0x8ada08;

    (**(code **)(*piVar5 + 0xcc))();

    iStack_18c = 0x9c43;

    piStack_190 = (int *)0x8ada1a;

    (**(code **)(*piVar5 + 0x74))();

    iStack_16c = (int)((float)param_1[0x177] * (float)DAT_00d1e818 * DAT_00aaa67c) +

                 (int)((float)param_1[0x17b] * (float)DAT_00d1e818 * DAT_00aaa67c) * iVar8;

    piStack_168 = (int *)((int)((float)param_1[0x178] * (float)DAT_00d1e81c * DAT_00aaa678) +

                         (int)((float)param_1[0x17c] * (float)DAT_00d1e81c * DAT_00aaa678) * iVar4);

    piStack_190 = &iStack_16c;

    ppiStack_194 = (int **)0x8adaad;

    (**(code **)(*piVar5 + 0x118))();

    piStack_168 = (int *)(int)((float)param_1[0x179] * (float)DAT_00d1e818 * DAT_00aaa67c);

    ppiStack_194 = &piStack_168;

    iStack_198 = 0x8adb01;

    (**(code **)(*piVar5 + 8))();

    iStack_198 = 0;

    pvStack_19c = (void *)0x8adb0d;

    pbVar6 = (byte *)(**(code **)(*piVar5 + 0x164))();

    fVar1 = DAT_00b017e8;

    param_1[0x165] = (int)((float)pbVar6[2] * DAT_00b017e8);

    param_1[0x166] = (int)((float)pbVar6[1] * fVar1);

    param_1[0x167] = (int)((float)*pbVar6 * fVar1);

    param_1[0x168] = (int)((float)pbVar6[3] * fVar1);

    pvStack_19c = (void *)0x1;

    piStack_1a0 = (int *)0x8adb70;

    pbVar6 = (byte *)(**(code **)(*piVar5 + 0x164))();

    fVar1 = DAT_00b017e8;

    param_1[0x161] = (int)((float)pbVar6[2] * DAT_00b017e8);

    param_1[0x162] = (int)((float)pbVar6[1] * fVar1);

    param_1[0x163] = (int)((float)*pbVar6 * fVar1);

    param_1[0x164] = (int)((float)pbVar6[3] * fVar1);

    piStack_1a0 = (int *)0x2;

    puStack_1a4 = (uint32_t /* decomp width */ *)0x8adbd3;

    pbVar6 = (byte *)(**(code **)(*piVar5 + 0x164))();

    fVar1 = DAT_00b017e8;

    param_1[0x169] = (int)((float)pbVar6[2] * DAT_00b017e8);

    param_1[0x16a] = (int)((float)pbVar6[1] * fVar1);

    param_1[0x16b] = (int)((float)*pbVar6 * fVar1);

    param_1[0x16c] = (int)((float)pbVar6[3] * fVar1);

    *(int **)(iStack_18c + -0x30) = piVar5;

    iVar7 = param_1[0x1a] + 1;

    param_1[0x1a] = iVar7;

    param_1[0x1d] = (int)(float)-iVar7;

    if (param_1[0x1c] < iVar7) {

      param_1[0x1c] = iVar7;

    }

    puStack_1a4 = (uint32_t /* decomp width */ *)0x1;

    (**(code **)(*param_1 + 0x3f4))();

    pcStack_1ac = (char *)0x8adc65;

    pcStack_1ac = operator_new(0x488);

    pcStack_188 = pcStack_1ac;

    if (pcStack_1ac == (void *)0x0) {

      piVar5 = (int *)0x0;

    }

    else {

      pvStack_1b0 = (void *)0x8adc80;

      piVar5 = (int *)FUN_007b5dd0();

    }

    pcStack_1ac = (char *)0x8adc99;

    (**(code **)(*param_1 + 0xa8))();

    pcStack_1ac = "i_d_npc_2d_wnd_item_bg.xml";

    pvStack_1b0 = (void *)0x8adca5;

    (**(code **)(*piVar5 + 0x28))();

    pvStack_1b0 = (void *)0x0;

    ppiStack_1b4 = (int **)0x8adcb1;

    (**(code **)(*piVar5 + 0xcc))();

    piStack_190 = (int *)((int)((float)param_1[0x189] * (float)DAT_00d1e818 * DAT_00aaa67c) +

                         (int)((float)param_1[0x18d] * (float)DAT_00d1e818 * DAT_00aaa67c) * iVar8);

    iStack_18c = (int)((float)param_1[0x18a] * (float)DAT_00d1e81c * DAT_00aaa678) +

                 (int)((float)param_1[0x18e] * (float)DAT_00d1e81c * DAT_00aaa678) * iVar4;

    ppiStack_1b4 = &piStack_190;

    ppcStack_1b8 = (char **)0x8add44;

    (**(code **)(*piVar5 + 0x118))();

    pcStack_184 = (char *)(int)((float)param_1[0x18b] * (float)DAT_00d1e818 * DAT_00aaa67c);

    ppcStack_1b8 = &pcStack_184;

    (**(code **)(*piVar5 + 8))();

    *puStack_1a4 = piVar5;

    pvStack_19c = operator_new(0x488);

    if (pvStack_19c == (void *)0x0) {

      piVar5 = (int *)0x0;

    }

    else {

      piVar5 = (int *)FUN_007b5dd0(pvStack_19c,0);

    }

    iVar7 = -1;

    (**(code **)(*param_1 + 0xa8))(piVar5);

    (**(code **)(*piVar5 + 0x28))("i_d_npc_2d_wnd_item.xml");

    (**(code **)(*piVar5 + 0xcc))(0);

    puStack_1a4 = (uint32_t /* decomp width */ *)

                  ((int)((float)param_1[0x17d] * (float)DAT_00d1e818 * DAT_00aaa67c) +

                  (int)((float)param_1[0x181] * (float)DAT_00d1e818 * DAT_00aaa67c) * iVar8);

    piStack_1a0 = (int *)((int)((float)param_1[0x17e] * (float)DAT_00d1e81c * DAT_00aaa678) +

                         (int)((float)param_1[0x182] * (float)DAT_00d1e81c * DAT_00aaa678) * iVar4);

    (**(code **)(*piVar5 + 0x118))(&puStack_1a4);

    piStack_190 = (int *)(int)((float)param_1[0x17f] * (float)DAT_00d1e818 * DAT_00aaa67c);

    iStack_18c = (int)((float)param_1[0x180] * (float)DAT_00d1e81c * DAT_00aaa678);

    (**(code **)(*piVar5 + 8))();

    ppcStack_1b8[-8] = (char *)piVar5;

    pvStack_1b0 = operator_new(0x488);

    if (pvStack_1b0 == (void *)0x0) {

      piVar5 = (int *)0x0;

    }

    else {

      piVar5 = (int *)FUN_007b5dd0(pvStack_1b0,0);

    }

    (**(code **)(*param_1 + 0xa8))(piVar5);

    (**(code **)(*piVar5 + 0x28))("i_d_npc_2d_wnd_itemtext.xml");

    (**(code **)(*piVar5 + 0xcc))(0);

    ppcStack_1b8 = (char **)((int)((float)param_1[0x183] * (float)DAT_00d1e818 * DAT_00aaa67c) +

                            (int)((float)param_1[0x187] * (float)DAT_00d1e818 * DAT_00aaa67c) *

                            iVar8);

    ppiStack_1b4 = (int **)((int)((float)param_1[0x184] * (float)DAT_00d1e81c * DAT_00aaa678) +

                           (int)((float)param_1[0x188] * (float)DAT_00d1e81c * DAT_00aaa678) * iVar4

                           );

    (**(code **)(*piVar5 + 0x118))(&ppcStack_1b8);

    pvStack_19c = (void *)(int)((float)param_1[0x185] * (float)DAT_00d1e818 * DAT_00aaa67c);

    iStack_198 = (int)((float)param_1[0x186] * (float)DAT_00d1e81c * DAT_00aaa678);

    (**(code **)(*piVar5 + 8))(&pvStack_19c);

    iVar8 = param_1[0x1a] + 1;

    param_1[0x1a] = iVar8;

    param_1[0x1d] = (int)(float)-iVar8;

    if (param_1[0x1c] < iVar8) {

      param_1[0x1c] = iVar8;

    }

    piStack_1a0 = piVar5;

    (**(code **)(*param_1 + 0x3f4))(1);

    piStack_168 = piStack_168 + 1;

    iVar8 = iVar7 + 1;

  } while (iVar8 < 4);

  pcStack_184 = (char *)0x8ae073;

  pvVar2 = operator_new(0x4cc);

  if (pvVar2 == (void *)0x0) {

    piVar5 = (int *)0x0;

  }

  else {

    piVar5 = (int *)FUN_0079c860();

  }

  pcStack_184 = (char *)0x8ae0a8;

  (**(code **)(*param_1 + 0xa8))();

  pcStack_184 = (char *)0x9c40;

  pcStack_188 = (char *)0x8ae0b4;

  (**(code **)(*piVar5 + 0x74))();

  pcStack_188 = "i_d_npc_2d_btn_close.xml";

  iStack_18c = 0x8ae0c0;

  (**(code **)(*piVar5 + 0x28))();

  iStack_18c = 0x3f000000;

  piStack_190 = (int *)0x1;

  ppiStack_194 = (int **)0x8ae0d1;

  (**(code **)(*piVar5 + 0xfc))();

  param_1[0x141] = (int)piVar5;

  ppiStack_194 = (int **)0x8ae0dc;

  FUN_008ac110();

  param_1[0x1a] = param_1[0x1a] + 1;

  iVar8 = param_1[0x1a];

  param_1[0x1d] = (int)(float)-iVar8;

  if (param_1[0x1c] < iVar8) {

    param_1[0x1c] = iVar8;

  }

  ppiStack_194 = (int **)0x1;

  iStack_198 = 0x8ae104;

  (**(code **)(*param_1 + 0x3f4))();

  iStack_198 = 0x8ae10e;

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = piVar3;

  return;

}
