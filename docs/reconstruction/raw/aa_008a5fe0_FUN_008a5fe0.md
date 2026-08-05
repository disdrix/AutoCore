# Raw capture: FUN_008a5fe0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008a5fe0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008a5fe0` |
| **Canonical name** | `FUN_008a5fe0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_008a5fe0(int *param_1)

{
  char cVar1;
  void *pvVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  void *pvVar6;
  undefined4 *puVar7;
  int *unaff_EBX;
  uint uVar8;
  int unaff_ESI;
  int iVar9;
  longlong lVar10;
  undefined4 uStack_2e4;
  int *piStack_2e0;
  char *pcStack_2dc;
  undefined4 uStack_2d8;
  int iStack_2d4;
  int iStack_2d0;
  int *piStack_2cc;
  char *pcStack_2c8;
  undefined4 uStack_2c4;
  int *piStack_2c0;
  char *pcStack_2bc;
  undefined4 uStack_2b8;
  int *piStack_2b4;
  char *pcStack_2b0;
  undefined4 uStack_2ac;
  undefined4 *puStack_2a8;
  undefined4 ***pppuStack_2a4;
  undefined4 uStack_2a0;
  undefined4 *puStack_29c;
  undefined4 uStack_298;
  undefined4 *puStack_294;
  undefined4 *puStack_290;
  undefined4 uStack_28c;
  undefined4 **ppuStack_288;
  undefined4 uStack_284;
  undefined4 **ppuStack_280;
  undefined4 **ppuStack_27c;
  undefined4 uStack_278;
  int iStack_274;
  undefined4 ***pppuStack_270;
  undefined4 uStack_26c;
  undefined4 uStack_268;
  undefined4 *puStack_264;
  undefined4 **ppuStack_260;
  undefined4 uStack_25c;
  undefined4 *puStack_258;
  undefined4 uStack_254;
  undefined4 *puStack_250;
  undefined4 *puStack_24c;
  undefined4 uStack_248;
  undefined4 *puStack_244;
  undefined4 uStack_240;
  undefined4 ***pppuStack_23c;
  undefined4 *puStack_238;
  undefined4 uStack_234;
  int iStack_230;
  undefined4 *puStack_22c;
  undefined4 uStack_228;
  undefined4 uStack_224;
  undefined4 ***pppuStack_220;
  undefined4 *puStack_21c;
  undefined4 uStack_218;
  undefined4 uStack_214;
  undefined4 *puStack_210;
  undefined4 uStack_20c;
  undefined4 uStack_208;
  undefined4 ***pppuStack_204;
  undefined4 *puStack_200;
  undefined4 uStack_1fc;
  undefined4 uStack_1f8;
  undefined4 *puStack_1f4;
  undefined4 uStack_1f0;
  undefined4 uStack_1ec;
  undefined4 ***pppuStack_1e8;
  undefined4 *puStack_1e4;
  undefined4 uStack_1e0;
  undefined4 uStack_1dc;
  undefined4 *puStack_1d8;
  undefined4 uStack_1d4;
  undefined4 uStack_1d0;
  undefined4 ***pppuStack_1cc;
  undefined4 *puStack_1c8;
  undefined4 uStack_1c4;
  undefined4 uStack_1c0;
  undefined4 *puStack_1bc;
  undefined4 uStack_1b8;
  undefined4 uStack_1b4;
  undefined4 **ppuStack_1b0;
  char **ppcStack_1ac;
  undefined4 uStack_1a8;
  undefined4 uStack_1a4;
  char **ppcStack_1a0;
  undefined4 uStack_19c;
  undefined4 uStack_198;
  undefined4 *puStack_194;
  undefined4 *puStack_190;
  undefined4 uStack_18c;
  undefined4 uStack_188;
  char **ppcStack_184;
  char *pcStack_180;
  undefined4 uStack_178;
  int iStack_174;
  undefined4 uStack_170;
  char *pcStack_16c;
  void *pvStack_160;
  undefined4 uStack_15c;
  char *pcStack_158;
  int *piVar11;
  int *piStack_38;
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009b9981;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  FUN_00792600();
  pvVar2 = operator_new(0x488);
  local_c = 0;
  if (pvVar2 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_007b5dd0();
  }
  local_c = 0xffffffff;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*piStack_38 + 0x28))();
  (**(code **)(*unaff_EBX + 0xfc))();
  param_1[0x152] = unaff_ESI;
  iVar4 = param_1[0x1a] + 1;
  param_1[0x1a] = iVar4;
  param_1[0x1d] = (int)(float)-iVar4;
  if (param_1[0x1c] < iVar4) {
    param_1[0x1c] = iVar4;
  }
  (**(code **)(*param_1 + 0x3f4))();
  pvVar2 = operator_new(0x4bc);
  if (pvVar2 == (void *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)FUN_00864f20();
  }
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*piVar3 + 0x28))();
  (**(code **)(s_i_d_q_2d_wnd_bg_fill_xml_00a4ceb8._0_4_ + 0xfc))();
  param_1[0x153] = 1;
  iVar4 = param_1[0x1a] + 1;
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
  (**(code **)(*piVar5 + 0x28))();
  (**(code **)(s_i_d_q_2d_wnd_fx_xml_00a4cea4._0_4_ + 0xfc))();
  param_1[0x154] = 1;
  iVar4 = param_1[0x1a] + 1;
  param_1[0x1a] = iVar4;
  param_1[0x1d] = (int)(float)-iVar4;
  if (param_1[0x1c] < iVar4) {
    param_1[0x1c] = iVar4;
  }
  (**(code **)(*param_1 + 0x3f4))();
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)FUN_007b5dd0();
  }
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*piVar3 + 0x28))();
  (**(code **)(s_i_d_q_2d_wnd_bg_texture_xml_00a4ce88._0_4_ + 0xfc))();
  param_1[0x157] = 1;
  iVar4 = param_1[0x1a] + 1;
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
  (**(code **)(*piVar5 + 0x28))();
  (**(code **)(s_i_d_q_2d_wnd_title_xml_00a4ce70._0_4_ + 0xfc))();
  param_1[0x156] = 1;
  iVar4 = param_1[0x1a] + 1;
  param_1[0x1a] = iVar4;
  param_1[0x1d] = (int)(float)-iVar4;
  if (param_1[0x1c] < iVar4) {
    param_1[0x1c] = iVar4;
  }
  (**(code **)(*param_1 + 0x3f4))();
  pvVar2 = operator_new(0x488);
  if (pvVar2 != (void *)0x0) {
    FUN_007b5dd0();
  }
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*piVar3 + 0x28))();
  (**(code **)(s_i_d_q_2d_wnd_viewable_xml_00a4ce54._0_4_ + 0xfc))();
  param_1[0x155] = 1;
  (**(code **)(*param_1 + 0x404))();
  (**(code **)(s_i_d_q_2d_wnd_icon_xml_00a4ce3c._0_4_ + 0xfc))();
  iVar4 = param_1[0x1a] + 1;
  param_1[0x1a] = iVar4;
  param_1[0x1d] = (int)(float)-iVar4;
  if (param_1[0x1c] < iVar4) {
    param_1[0x1c] = iVar4;
  }
  (**(code **)(*param_1 + 0x3f4))();
  piVar3 = param_1 + 0x158;
  (**(code **)(*param_1 + 0x404))();
  pvVar2 = operator_new(0x954);
  if (pvVar2 == (void *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)FUN_0078f890();
  }
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*piVar5 + 0x28))();
  (**(code **)(*piVar5 + 0x74))();
  (**(code **)(*piVar5 + 0x43c))();
  (**(code **)(*piVar5 + 0xfc))();
  param_1[0x15a] = (int)piVar5;
  pvVar2 = operator_new(0x4cc);
  if (pvVar2 == (void *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)FUN_0079c860();
  }
  piVar11 = piVar5;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*piVar5 + 0x28))();
  (**(code **)(*piVar5 + 0x74))();
  (**(code **)(*piVar5 + 0xfc))();
  param_1[0x141] = (int)piVar5;
  pvVar2 = operator_new(0x488);
  if (pvVar2 != (void *)0x0) {
    FUN_007b5dd0();
  }
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*piVar11 + 0x28))();
  (**(code **)(s_i_d_q_2d_btn_close_xml_00a4cdd8._0_4_ + 0xfc))();
  param_1[0x15b] = 0x3f000000;
  pvVar2 = operator_new(0x954);
  if (pvVar2 == (void *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)FUN_0078f890();
  }
  piVar11 = piVar5;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*piVar5 + 0x28))();
  (**(code **)(*piVar5 + 0x74))();
  (**(code **)(*piVar5 + 0x43c))();
  (**(code **)(*piVar5 + 0xfc))();
  param_1[0x15c] = (int)piVar5;
  pvVar2 = operator_new(0x488);
  if (pvVar2 != (void *)0x0) {
    FUN_007b5dd0();
  }
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*piVar11 + 0x28))();
  (**(code **)(s_i_d_q_2d_sb_desc_xml_00a4cda4._0_4_ + 0xfc))();
  param_1[0x15d] = 0x3f000000;
  iVar4 = param_1[0x1a] + 1;
  param_1[0x1a] = iVar4;
  param_1[0x1d] = (int)(float)-iVar4;
  if (param_1[0x1c] < iVar4) {
    param_1[0x1c] = iVar4;
  }
  (**(code **)(*param_1 + 0x3f4))();
  pvVar2 = operator_new(0x590);
  if (pvVar2 == (void *)0x0) {
    pvVar2 = (void *)0x0;
  }
  else {
    pvVar2 = (void *)FUN_00854300();
  }
  param_1[0x15e] = (int)pvVar2;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x15e] + 0x28))();
  (**(code **)(*(int *)param_1[0x15e] + 0x43c))();
  (**(code **)(*(int *)param_1[0x15e] + 0xfc))();
  pcStack_158 = (char *)0x8a6683;
  pvVar6 = operator_new(0x4cc);
  if (pvVar6 == (void *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)FUN_0079c860();
  }
  pcStack_158 = (char *)0x8a66b5;
  (**(code **)(*param_1 + 0xa8))();
  pcStack_158 = "i_d_q_2d_btn_set_active.xml";
  uStack_15c = 0x8a66c1;
  (**(code **)(*piVar5 + 0x28))();
  uStack_15c = 0x9c43;
  pvStack_160 = (void *)0x8a66cd;
  (**(code **)(*piVar5 + 0x74))();
  pvStack_160 = (void *)0x3f000000;
  (**(code **)(*piVar5 + 0xfc))();
  param_1[0x15f] = (int)piVar5;
  pcStack_16c = (char *)0x8a66ee;
  pvVar6 = operator_new(0x4cc);
  if (pvVar6 == (void *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)FUN_0079c860();
  }
  pcStack_16c = (char *)0x8a6720;
  (**(code **)(*param_1 + 0xa8))();
  pcStack_16c = "i_d_q_2d_btn_set_active_all.xml";
  uStack_170 = 0x8a672c;
  (**(code **)(*piVar5 + 0x28))();
  uStack_170 = 0x9c43;
  iStack_174 = 0x8a6738;
  (**(code **)(*piVar5 + 0x74))();
  iStack_174 = 0x3f000000;
  uStack_178 = 1;
  (**(code **)(*piVar5 + 0xfc))();
  param_1[0x160] = (int)piVar5;
  cVar1 = CVOGCharacter_WeaponAllowsKillXpBonus();
  if (cVar1 == '\0') {
    pcStack_180 = (char *)0x8a6768;
    pvStack_160 = operator_new(0x4cc);
    if (pvStack_160 == (void *)0x0) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = (int *)FUN_0079c860();
    }
    pcStack_180 = (char *)0x8a679a;
    (**(code **)(*param_1 + 0xa8))();
    pcStack_180 = "i_d_q_2d_btn_abandon.xml";
    ppcStack_184 = (char **)0x8a67a6;
    (**(code **)(*piVar5 + 0x28))();
    ppcStack_184 = (char **)0x9c44;
    uStack_188 = 0x8a67b2;
    (**(code **)(*piVar5 + 0x74))();
    uStack_188 = 0x3f000000;
    uStack_18c = 1;
    puStack_190 = (undefined4 *)0x8a67c3;
    (**(code **)(*piVar5 + 0xfc))();
    param_1[0x161] = (int)piVar5;
  }
  if ((DAT_00d1b6d8 == 0) || (*(int *)(DAT_00d1b6d8 + 0xcb0) == 0)) {
    param_1[0x143] = 0;
    *(undefined1 *)(param_1 + 0x14a) = 0;
  }
  else {
    if (param_1[0x143] == 2) {
      pcStack_180 = (char *)param_1[0x144];
      ppcStack_184 = (char **)0x8a6800;
      cVar1 = FUN_00574810();
      if (cVar1 == '\0') {
        iVar4 = 0;
        do {
          pcStack_180 = (char *)0x8a681c;
          lVar10 = FUN_00574730();
          if ((lVar10 != -1) &&
             ((iVar9 = *(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4),
              (int)lVar10 != *(int *)(iVar9 + 0x164 + DAT_00d1b6d8) ||
              ((int)((ulonglong)lVar10 >> 0x20) != *(int *)(iVar9 + 0x168 + DAT_00d1b6d8))))) {
            *(longlong *)(param_1 + 0x144) = lVar10;
            break;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < 4);
      }
    }
    pcStack_180 = (char *)0x1;
    ppcStack_184 = &pcStack_158;
    iVar9 = (int)((float)DAT_00d1e81c * DAT_00aaac18);
    uStack_188 = 0x8a6882;
    iVar4 = (**(code **)(*(int *)*piVar3 + 0x120))();
    iVar4 = *(int *)(iVar4 + 4);
    uStack_188 = 0;
    uStack_18c = 1;
    puStack_190 = &uStack_15c;
    puStack_194 = (undefined4 *)0x8a689a;
    puVar7 = (undefined4 *)(**(code **)(*(int *)*piVar3 + 0x120))();
    uStack_178 = *puVar7;
    puStack_194 = &uStack_178;
    uStack_198 = 0x8a68b3;
    iStack_174 = iVar4 + iVar9;
    (**(code **)(*(int *)*piVar3 + 0x110))();
    uStack_198 = 0;
    uStack_19c = 1;
    ppcStack_1a0 = &pcStack_16c;
    uStack_1a4 = 0x8a68ca;
    iVar4 = (**(code **)(*(int *)param_1[0x156] + 0x120))();
    iVar4 = *(int *)(iVar4 + 4);
    uStack_1a4 = 0;
    uStack_1a8 = 1;
    ppcStack_1ac = &pcStack_180;
    ppuStack_1b0 = (undefined4 **)0x8a68e6;
    puStack_194 = (undefined4 *)(**(code **)(*(int *)param_1[0x156] + 0x120))();
    puStack_194 = (undefined4 *)*puStack_194;
    ppuStack_1b0 = &puStack_194;
    uStack_1b4 = 0x8a6903;
    puStack_190 = (undefined4 *)(iVar4 + iVar9);
    (**(code **)(*(int *)param_1[0x156] + 0x110))();
    uStack_1b4 = 0;
    uStack_1b8 = 1;
    puStack_1bc = &uStack_188;
    uStack_1c0 = 0x8a691a;
    iVar4 = (**(code **)(*(int *)param_1[0x15a] + 0x120))();
    iVar4 = *(int *)(iVar4 + 4);
    uStack_1c0 = 0;
    uStack_1c4 = 1;
    puStack_1c8 = &uStack_19c;
    pppuStack_1cc = (undefined4 ***)0x8a6936;
    puVar7 = (undefined4 *)(**(code **)(*(int *)param_1[0x15a] + 0x120))();
    ppuStack_1b0 = (undefined4 **)*puVar7;
    pppuStack_1cc = &ppuStack_1b0;
    uStack_1d0 = 0x8a6953;
    ppcStack_1ac = (char **)(iVar4 + iVar9);
    (**(code **)(*(int *)param_1[0x15a] + 0x110))();
    uStack_1d0 = 0;
    uStack_1d4 = 1;
    puStack_1d8 = &uStack_1a4;
    uStack_1dc = 0x8a696a;
    iVar4 = (**(code **)(*(int *)param_1[0x15b] + 0x120))();
    iVar4 = *(int *)(iVar4 + 4);
    uStack_1dc = 0;
    uStack_1e0 = 1;
    puStack_1e4 = &uStack_1b8;
    pppuStack_1e8 = (undefined4 ***)0x8a6986;
    puVar7 = (undefined4 *)(**(code **)(*(int *)param_1[0x15b] + 0x120))();
    pppuStack_1cc = (undefined4 ***)*puVar7;
    pppuStack_1e8 = &pppuStack_1cc;
    uStack_1ec = 0x8a69a3;
    puStack_1c8 = (undefined4 *)(iVar4 + iVar9);
    (**(code **)(*(int *)param_1[0x15b] + 0x110))();
    uStack_1ec = 0;
    uStack_1f0 = 1;
    puStack_1f4 = &uStack_1c0;
    uStack_1f8 = 0x8a69ba;
    iVar4 = (**(code **)(*(int *)param_1[0x15c] + 0x120))();
    iVar4 = *(int *)(iVar4 + 4);
    uStack_1f8 = 0;
    uStack_1fc = 1;
    puStack_200 = &uStack_1d4;
    pppuStack_204 = (undefined4 ***)0x8a69d6;
    puVar7 = (undefined4 *)(**(code **)(*(int *)param_1[0x15c] + 0x120))();
    pppuStack_1e8 = (undefined4 ***)*puVar7;
    pppuStack_204 = &pppuStack_1e8;
    uStack_208 = 0x8a69f3;
    puStack_1e4 = (undefined4 *)(iVar4 + iVar9);
    (**(code **)(*(int *)param_1[0x15c] + 0x110))();
    uStack_208 = 0;
    uStack_20c = 1;
    puStack_210 = &uStack_1dc;
    uStack_214 = 0x8a6a0a;
    iVar4 = (**(code **)(*(int *)param_1[0x15d] + 0x120))();
    iVar4 = *(int *)(iVar4 + 4);
    uStack_214 = 0;
    uStack_218 = 1;
    puStack_21c = &uStack_1f0;
    pppuStack_220 = (undefined4 ***)0x8a6a26;
    puVar7 = (undefined4 *)(**(code **)(*(int *)param_1[0x15d] + 0x120))();
    pppuStack_204 = (undefined4 ***)*puVar7;
    pppuStack_220 = &pppuStack_204;
    uStack_224 = 0x8a6a43;
    puStack_200 = (undefined4 *)(iVar4 + iVar9);
    (**(code **)(*(int *)param_1[0x15d] + 0x110))();
    uStack_224 = 0;
    uStack_228 = 1;
    puStack_22c = &uStack_1f8;
    iStack_230 = 0x8a6a5a;
    iVar4 = (**(code **)(*(int *)param_1[0x15e] + 0x120))();
    iVar4 = *(int *)(iVar4 + 4);
    iStack_230 = 0;
    uStack_234 = 1;
    puStack_238 = &uStack_20c;
    pppuStack_23c = (undefined4 ***)0x8a6a76;
    puVar7 = (undefined4 *)(**(code **)(*(int *)param_1[0x15e] + 0x120))();
    pppuStack_220 = (undefined4 ***)*puVar7;
    pppuStack_23c = &pppuStack_220;
    uStack_240 = 0x8a6a93;
    puStack_21c = (undefined4 *)(iVar4 + iVar9);
    (**(code **)(*(int *)param_1[0x15e] + 0x110))();
    uStack_240 = 1;
    puStack_244 = &uStack_214;
    uStack_248 = 0x8a6aa8;
    iVar4 = (**(code **)(*(int *)param_1[0x15c] + 0x140))();
    iVar4 = *(int *)(iVar4 + 4);
    uStack_248 = 1;
    puStack_24c = &uStack_224;
    puStack_250 = (undefined4 *)0x8a6ac2;
    puVar7 = (undefined4 *)(**(code **)(*(int *)param_1[0x15c] + 0x140))();
    uStack_234 = *puVar7;
    puStack_250 = &uStack_234;
    uStack_254 = 0x8a6adf;
    iStack_230 = iVar4 - iVar9;
    (**(code **)(*(int *)param_1[0x15c] + 300))();
    uStack_254 = 1;
    puStack_258 = &uStack_228;
    uStack_25c = 0x8a6afa;
    iVar4 = (**(code **)(**(int **)(param_1[0x15c] + 0x944) + 0x140))();
    iVar4 = *(int *)(iVar4 + 4);
    uStack_25c = 1;
    ppuStack_260 = &puStack_238;
    puStack_264 = (undefined4 *)0x8a6b1a;
    puVar7 = (undefined4 *)(**(code **)(**(int **)(param_1[0x15c] + 0x944) + 0x140))();
    uStack_248 = *puVar7;
    puStack_264 = &uStack_248;
    uStack_268 = 0x8a6b3d;
    puStack_244 = (undefined4 *)(iVar4 - iVar9);
    (**(code **)(**(int **)(param_1[0x15c] + 0x944) + 300))();
    uStack_268 = 0;
    uStack_26c = 1;
    pppuStack_270 = &pppuStack_23c;
    iStack_274 = 0x8a6b5a;
    iVar4 = (**(code **)(**(int **)(param_1[0x15c] + 0x950) + 0x120))();
    iVar4 = *(int *)(iVar4 + 4);
    iStack_274 = 0;
    uStack_278 = 1;
    ppuStack_27c = &puStack_250;
    ppuStack_280 = (undefined4 **)0x8a6b7c;
    puStack_264 = (undefined4 *)(**(code **)(**(int **)(param_1[0x15c] + 0x950) + 0x120))();
    puStack_264 = (undefined4 *)*puStack_264;
    ppuStack_280 = &puStack_264;
    uStack_284 = 0x8a6b9f;
    ppuStack_260 = (undefined4 **)(iVar4 - iVar9);
    (**(code **)(**(int **)(param_1[0x15c] + 0x950) + 0x110))();
    *(int *)(param_1[0x15c] + 0x514) = *(int *)(param_1[0x15c] + 0x514) - iVar9;
    uStack_284 = 1;
    ppuStack_288 = &puStack_258;
    uStack_28c = 0x8a6bc0;
    iVar4 = (**(code **)(*(int *)param_1[0x15d] + 0x140))();
    iVar4 = *(int *)(iVar4 + 4);
    uStack_28c = 1;
    puStack_290 = &uStack_268;
    puStack_294 = (undefined4 *)0x8a6bda;
    puVar7 = (undefined4 *)(**(code **)(*(int *)param_1[0x15d] + 0x140))();
    uStack_278 = *puVar7;
    puStack_294 = &uStack_278;
    uStack_298 = 0x8a6bf7;
    iStack_274 = iVar4 - iVar9;
    (**(code **)(*(int *)param_1[0x15d] + 300))();
    uStack_298 = 1;
    puStack_29c = &uStack_26c;
    uStack_2a0 = 0x8a6c0c;
    iVar4 = (**(code **)(*(int *)param_1[0x15e] + 0x140))();
    iVar4 = *(int *)(iVar4 + 4);
    uStack_2a0 = 1;
    pppuStack_2a4 = &ppuStack_27c;
    puStack_2a8 = (undefined4 *)0x8a6c26;
    puVar7 = (undefined4 *)(**(code **)(*(int *)param_1[0x15e] + 0x140))();
    uStack_28c = *puVar7;
    puStack_2a8 = &uStack_28c;
    uStack_2ac = 0x8a6c43;
    ppuStack_288 = (undefined4 **)(iVar4 - iVar9);
    (**(code **)(*(int *)param_1[0x15e] + 300))();
    uStack_2ac = 0xffffffff;
    pcStack_2b0 = "i_d_q_2d_wnd_tab_self.xml";
    uStack_2b8 = 0x8a6c5c;
    piStack_2b4 = param_1 + 0x162;
    (**(code **)(*param_1 + 0x404))();
    uStack_2b8 = 0xffffffff;
    piStack_2c0 = param_1 + 0x163;
    pcStack_2bc = "i_d_q_2d_wnd_tab_shared.xml";
    uStack_2c4 = 0x8a6c75;
    (**(code **)(*param_1 + 0x404))();
    uStack_2c4 = 0xffffffff;
    piStack_2cc = param_1 + 0x164;
    pcStack_2c8 = "i_d_q_2d_wnd_tab_convoy.xml";
    iStack_2d0 = 0x8a6c8e;
    (**(code **)(*param_1 + 0x404))();
    iStack_2d0 = *piVar3;
    iStack_2d4 = 0x8a6c9c;
    (**(code **)(*param_1 + 0xb4))();
    if (param_1[0x143] == 0) {
      iStack_2d4 = param_1[0x162];
    }
    else if (param_1[0x143] == 1) {
      iStack_2d4 = param_1[0x163];
    }
    else {
      iStack_2d4 = param_1[0x164];
    }
    uStack_2d8 = 0x8a6cc9;
    (**(code **)(*param_1 + 0xb4))();
    uStack_2d8 = 0x9c47;
    pcStack_2dc = "i_d_q_2d_btn_tab_self.xml";
    piStack_2e0 = param_1 + 0x165;
    uStack_2e4 = 0x8a6ce5;
    (**(code **)(*param_1 + 0x408))();
    uStack_2e4 = 0x9c48;
    (**(code **)(*param_1 + 0x408))(param_1 + 0x166,"i_d_q_2d_btn_tab_shared.xml");
    (**(code **)(*param_1 + 0x408))(param_1 + 0x167,"i_d_q_2d_btn_tab_convoy.xml",0x9c49);
    if ((param_1[0x143] == 0) || (param_1[0x143] == 1)) {
      FUN_008a27e0();
    }
    else {
      FUN_008a27e0();
    }
    FUN_008a27e0();
    if (param_1[0x143] == 1) {
      (**(code **)(*param_1 + 0x404))(&uStack_2e4,"i_d_q_2d_wnd_instructions_shared.xml");
      *(undefined1 *)(param_1 + 0x14a) = 1;
    }
    else if (param_1[0x143] == 2) {
      (**(code **)(*param_1 + 0x404))(&uStack_2e4,"i_d_q_2d_wnd_instructions_convoy.xml");
      *(undefined1 *)(param_1 + 0x14a) = 1;
    }
    else {
      (**(code **)(*param_1 + 0x404))(&uStack_2e4,"i_d_q_2d_wnd_instructions_self.xml",0xffffffff);
      *(undefined1 *)(param_1 + 0x14a) = 1;
    }
  }
  (**(code **)(*param_1 + 0x448))();
  (**(code **)(*param_1 + 0x34c))();
  if ((int *)param_1[0x15a] != (int *)0x0) {
    pcStack_180 = (char *)param_1[0x151];
    ppcStack_184 = (char **)0x8a6e04;
    (**(code **)(*(int *)param_1[0x15a] + 0x454))();
  }
  param_1[0x146] = -1;
  pvVar6 = (void *)param_1[0x169];
  uVar8 = 0;
  pvStack_160 = pvVar6;
  do {
    if ((pvVar6 == (void *)0x0) || ((uint)(param_1[0x16a] - (int)pvVar6 >> 2) <= uVar8))
    goto LAB_008a6eb5;
    piVar3 = *(int **)(param_1[0x169] + uVar8 * 4);
    if ((piVar3 != (int *)0x0) &&
       ((piVar3[0x141] != 0 && (piVar5 = *(int **)(piVar3[0x141] + 0x14c), piVar5 != (int *)0x0))))
    {
      iVar4 = *piVar5;
      iVar9 = 0;
      if (DAT_00d1ad10[4] != 0) {
        pcStack_180 = (char *)0x8a6e83;
        pvVar6 = CNDHash_LookupByKey(*(void **)(*(int *)(*DAT_00d1ad10 + 0xe98) + 0x548),
                                     DAT_00d1ad10[4]);
        iVar9 = 0;
        if (pvVar6 != (void *)0x0) {
          iVar9 = 0;
          if (*(int **)((int)pvVar6 + 0x14c) != (int *)0x0) {
            iVar9 = **(int **)((int)pvVar6 + 0x14c);
          }
        }
      }
      pvVar6 = pvStack_160;
      if (iVar4 == iVar9) {
        iVar4 = (**(code **)(*piVar3 + 0x78))();
        param_1[0x146] = iVar4;
        pcStack_180 = (char *)0x8a6eb5;
        FUN_008a3510();
LAB_008a6eb5:
        if (param_1[0x146] == -1) {
          pcStack_180 = (char *)0x8a6ec7;
          FUN_008a3510();
        }
        FUN_008a2df0();
        pvStack_160 = (void *)0x800f;
        if ((DAT_00d1b4bc != (int *)0x0) &&
           (cVar1 = (**(code **)(*DAT_00d1b4bc + 8))(), cVar1 != '\0')) {
          pcStack_180 = (char *)0x4;
          ppcStack_184 = &pvStack_160;
          uStack_188 = 0xffffffff;
          uStack_18c = 0x8a6eff;
          (**(code **)(*DAT_00d1b4bc + 0x18))();
        }
        ExceptionList = pvVar2;
        return;
      }
    }
    uVar8 = uVar8 + 1;
  } while( true );
}
```
