// =============================================================================
// Inv_invlist_btn_item_filter_powerplants
// -----------------------------------------------------------------------------
// Stable ID: aa_008c1280
// Address:   0x008c1280  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Inv_invlist_btn_item_filter_powerplants @ 0x008c1280
// Stable ID: aa_008c1280
// Embedded strings (evidence for future rename):
//   - "i_d_invlist_2d_btn_item_filter_powerplants.xml"
//   - "i_d_invlist_2d_btn_item_filter_useable.xml"
//   - "i_d_invlist_2d_wnd_item_icon.xml"
//   - "i_d_invlist_2d_wnd_item_icon_frame.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~499 non-empty decompiler lines.
//  - Control keywords: if×21, do×2, while×2, goto×1, return×1.
//  - Notable callees: FUN_0079c860×8, FUN_007b5dd0×8, FUN_0078f890, FUN_00792600, FUN_008c0d10, Inv_invlist_btn_item_filter_powerplants.
//  - Strings: "i_d_invlist_2d_btn_item_filter_powerplants.xml"; "i_d_invlist_2d_btn_item_filter_useable.xml"; "i_d_invlist_2d_wnd_item_icon.xml"; "i_d_invlist_2d_wnd_item_icon_frame.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_invlist_2d_btn_item_filter_powerplants.xml"
 * Domain alias of FUN_008c1280 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Inv_invlist_btn_item_filter_powerplants(int *param_1)



{

  int iVar1;

  void *pvVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ uStack_2d4;

  int iStack_2d0;

  char ***pppcStack_2cc;

  uint32_t /* width from decompiler */ uStack_2c8;

  int iStack_2c4;

  uint32_t /* width from decompiler */ *puStack_2c0;

  char ***pppcStack_2bc;

  int iStack_2b8;

  uint32_t /* width from decompiler */ uStack_2b4;

  uint32_t /* width from decompiler */ *puStack_2b0;

  int iStack_2ac;

  uint32_t /* width from decompiler */ uStack_2a8;

  uint32_t /* width from decompiler */ **ppuStack_2a4;

  uint8_t *puStack_2a0;

  uint32_t /* width from decompiler */ uStack_29c;

  int iStack_298;

  void **ppvStack_294;

  uint32_t /* width from decompiler */ uStack_290;

  uint32_t /* width from decompiler */ uStack_28c;

  uint32_t /* width from decompiler */ *puStack_288;

  uint8_t *puStack_284;

  uint32_t /* width from decompiler */ uStack_280;

  uint32_t /* width from decompiler */ uStack_27c;

  uint32_t /* width from decompiler */ *puStack_278;

  uint32_t /* width from decompiler */ uStack_274;

  uint32_t /* width from decompiler */ uStack_270;

  char **ppcStack_26c;

  uint32_t /* width from decompiler */ *puStack_268;

  uint32_t /* width from decompiler */ uStack_264;

  uint32_t /* width from decompiler */ uStack_260;

  uint8_t *puStack_25c;

  uint32_t /* width from decompiler */ uStack_258;

  uint32_t /* width from decompiler */ uStack_254;

  uint8_t *puStack_250;

  uint32_t /* width from decompiler */ *puStack_24c;

  uint32_t /* width from decompiler */ uStack_248;

  uint32_t /* width from decompiler */ uStack_244;

  char **ppcStack_240;

  uint32_t /* width from decompiler */ uStack_23c;

  uint32_t /* width from decompiler */ uStack_238;

  uint8_t *puStack_234;

  char *pcStack_230;

  char *pcStack_228;

  int iVar6;

  uint32_t /* width from decompiler */ uStack_1d4;

  uint32_t /* width from decompiler */ uStack_1d0;

  void *pvStack_1cc;

  uint32_t /* width from decompiler */ uStack_1c8;

  int iStack_1c4;

  void *pvStack_1c0;

  uint32_t /* width from decompiler */ uStack_1bc;

  uint32_t /* width from decompiler */ uStack_1b8;

  uint32_t /* width from decompiler */ uStack_1b4;

  uint32_t /* width from decompiler */ uStack_1b0;

  uint32_t /* width from decompiler */ uStack_1ac;

  uint32_t /* width from decompiler */ uStack_1a8;

  uint32_t /* width from decompiler */ uStack_1a4;

  uint32_t /* width from decompiler */ uStack_1a0;

  uint32_t /* width from decompiler */ uStack_19c;

  uint32_t /* width from decompiler */ uStack_198;

  uint32_t /* width from decompiler */ uStack_194;

  uint32_t /* width from decompiler */ uStack_190;

  uint32_t /* width from decompiler */ uStack_18c;

  uint32_t /* width from decompiler */ uStack_188;

  uint32_t /* width from decompiler */ uStack_184;

  uint32_t /* width from decompiler */ uStack_180;

  char *pcStack_17c;

  char *pcStack_14c;

  void *pvStack_d8;

  void *pvStack_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  

  uStack_c = 0xffffffff;

  puStack_10 = &LAB_009b9eab;

  pvStack_14 = ExceptionList;

  ExceptionList = &pvStack_14;

  FUN_00792600();

  iVar1 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar1;

  param_1[0x1d] = (int)(float)-iVar1;

  if (param_1[0x1c] < iVar1) {

    param_1[0x1c] = iVar1;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvVar2 = operator_new(0x954);

  iVar1 = 0;

  puStack_10 = (uint8_t *)0x0;

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_0078f890();

  }

  puStack_10 = (uint8_t *)0xffffffff;

  param_1[0x156] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x156] + 0x28))();

  (**(code **)(*(int *)param_1[0x156] + 0x74))();

  (**(code **)(*(int *)param_1[0x156] + 0x43c))();

  (**(code **)(*(int *)param_1[0x156] + 0x468))();

  (**(code **)(*(int *)param_1[0x156] + 0x454))();

  param_1[0x157] = 0;

  pvVar2 = operator_new(0x4cc);

  iVar3 = 0;

  if (pvVar2 != (void *)0x0) {

    iVar3 = FUN_0079c860();

  }

  param_1[0x168] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x168] + 0x28))();

  (**(code **)(*(int *)param_1[0x168] + 0x74))();

  pvVar2 = operator_new(0x4cc);

  iVar3 = 0;

  if (pvVar2 != (void *)0x0) {

    iVar3 = FUN_0079c860();

  }

  param_1[0x169] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x169] + 0x28))();

  (**(code **)(*(int *)param_1[0x169] + 0x74))();

  pcStack_14c = (char *)0x8c143a;

  pvVar2 = operator_new(0x4cc);

  iVar3 = 0;

  if (pvVar2 != (void *)0x0) {

    iVar3 = FUN_0079c860();

  }

  param_1[0x16a] = iVar3;

  pcStack_14c = (char *)0x8c1471;

  (**(code **)(*param_1 + 0xa8))();

  pcStack_14c = "i_d_invlist_2d_btn_item_filter_powerplants.xml";

  (**(code **)(*(int *)param_1[0x16a] + 0x28))();

  (**(code **)(*(int *)param_1[0x16a] + 0x74))();

  pvVar2 = operator_new(0x4cc);

  iVar3 = 0;

  if (pvVar2 != (void *)0x0) {

    iVar3 = FUN_0079c860();

  }

  param_1[0x16b] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x16b] + 0x28))();

  (**(code **)(*(int *)param_1[0x16b] + 0x74))();

  pcStack_14c = operator_new(0x4cc);

  iVar3 = 0;

  if (pcStack_14c != (char *)0x0) {

    iVar3 = FUN_0079c860();

  }

  param_1[0x16c] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x16c] + 0x28))();

  (**(code **)(*(int *)param_1[0x16c] + 0x74))();

  pvVar2 = operator_new(0x4cc);

  iVar3 = 0;

  if (pvVar2 != (void *)0x0) {

    iVar3 = FUN_0079c860();

  }

  param_1[0x16d] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x16d] + 0x28))();

  (**(code **)(*(int *)param_1[0x16d] + 0x74))();

  pcStack_17c = (char *)0x8c15be;

  pvVar2 = operator_new(0x4cc);

  iVar3 = 0;

  if (pvVar2 != (void *)0x0) {

    iVar3 = FUN_0079c860();

  }

  param_1[0x16e] = iVar3;

  pcStack_17c = (char *)0x8c15f5;

  (**(code **)(*param_1 + 0xa8))();

  pcStack_17c = "i_d_invlist_2d_btn_item_filter_useable.xml";

  uStack_180 = 0x8c1605;

  (**(code **)(*(int *)param_1[0x16e] + 0x28))();

  uStack_180 = 0x9c4c;

  uStack_184 = 0x8c1615;

  (**(code **)(*(int *)param_1[0x16e] + 0x74))();

  uStack_184 = 1;

  uStack_188 = 0;

  uStack_18c = 0x8c1626;

  (**(code **)(*(int *)param_1[0x168] + 0x3c8))();

  uStack_18c = 1;

  uStack_190 = 0;

  uStack_194 = 0x8c1637;

  (**(code **)(*(int *)param_1[0x169] + 0x3c8))();

  uStack_194 = 1;

  uStack_198 = 0;

  uStack_19c = 0x8c1648;

  (**(code **)(*(int *)param_1[0x16a] + 0x3c8))();

  uStack_19c = 1;

  uStack_1a0 = 0;

  uStack_1a4 = 0x8c1659;

  (**(code **)(*(int *)param_1[0x16b] + 0x3c8))();

  uStack_1a4 = 1;

  uStack_1a8 = 0;

  uStack_1ac = 0x8c166a;

  (**(code **)(*(int *)param_1[0x16c] + 0x3c8))();

  uStack_1ac = 1;

  uStack_1b0 = 0;

  uStack_1b4 = 0x8c167b;

  (**(code **)(*(int *)param_1[0x16d] + 0x3c8))();

  uStack_1b4 = 1;

  uStack_1b8 = 0;

  uStack_1bc = 0x8c168c;

  (**(code **)(*(int *)param_1[0x16e] + 0x3c8))();

  uStack_1bc = 0;

  pvStack_1c0 = (void *)0x8c169b;

  (**(code **)(*(int *)param_1[0x168] + 0xd4))();

  pvStack_1c0 = (void *)0x0;

  iStack_1c4 = 0x8c16aa;

  (**(code **)(*(int *)param_1[0x169] + 0xd4))();

  iStack_1c4 = 0;

  uStack_1c8 = 0x8c16b9;

  (**(code **)(*(int *)param_1[0x16a] + 0xd4))();

  uStack_1c8 = 0;

  pvStack_1cc = (void *)0x8c16c8;

  (**(code **)(*(int *)param_1[0x16b] + 0xd4))();

  pvStack_1cc = (void *)0x0;

  uStack_1d0 = 0x8c16d7;

  (**(code **)(*(int *)param_1[0x16c] + 0xd4))();

  uStack_1d0 = 0;

  uStack_1d4 = 0x8c16e6;

  (**(code **)(*(int *)param_1[0x16d] + 0xd4))();

  uStack_1d4 = 0;

  (**(code **)(*(int *)param_1[0x16e] + 0xd4))();

  if (param_1[0x14c] != 0) {

    pvVar2 = operator_new__(param_1[0x14c] * 4);

    param_1[0x15e] = (int)pvVar2;

    pvVar2 = operator_new__(param_1[0x14c] * 4);

    param_1[0x15f] = (int)pvVar2;

    pvVar2 = operator_new__(param_1[0x14c] * 4);

    param_1[0x160] = (int)pvVar2;

    pvVar2 = operator_new__(param_1[0x14c] * 4);

    param_1[0x161] = (int)pvVar2;

    pvVar2 = operator_new__(param_1[0x14c] * 4);

    param_1[0x162] = (int)pvVar2;

    pvVar2 = operator_new__(param_1[0x14c] * 4);

    param_1[0x163] = (int)pvVar2;

    pvVar2 = operator_new__(param_1[0x14c] * 4);

    param_1[0x164] = (int)pvVar2;

    pvVar2 = operator_new__(param_1[0x14c] * 4);

    param_1[0x165] = (int)pvVar2;

    pvVar2 = operator_new__(param_1[0x14c] * 4);

    param_1[0x166] = (int)pvVar2;

    iVar3 = 0;

    if (param_1[0x14c] < 1) goto LAB_008c1ff6;

    do {

      *(uint32_t /* width from decompiler */ *)(param_1[0x15e] + iVar3 * 4) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1[0x15f] + iVar3 * 4) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1[0x160] + iVar3 * 4) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1[0x161] + iVar3 * 4) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1[0x162] + iVar3 * 4) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1[0x163] + iVar3 * 4) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1[0x164] + iVar3 * 4) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1[0x165] + iVar3 * 4) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1[0x166] + iVar3 * 4) = 0;

      iVar3 = iVar3 + 1;

    } while (iVar3 < param_1[0x14c]);

  }

  if (0 < param_1[0x14c]) {

    iStack_1c4 = 0xa812;

    do {

      iVar3 = iStack_1c4;

      pvStack_1c0 = operator_new(0x488);

      if (pvStack_1c0 == (void *)0x0) {

        uVar4 = 0;

      }

      else {

        uVar4 = FUN_007b5dd0();

      }

      *(uint32_t /* width from decompiler */ *)(iVar1 + param_1[0x15e]) = uVar4;

      (**(code **)(*param_1 + 0xa8))();

      (**(code **)(**(int **)(iVar1 + param_1[0x15e]) + 0x28))();

      (**(code **)(**(int **)(iVar1 + param_1[0x15e]) + 0x74))();

      pvStack_1cc = operator_new(0x488);

      if (pvStack_1cc == (void *)0x0) {

        uVar4 = 0;

      }

      else {

        uVar4 = FUN_007b5dd0();

      }

      *(uint32_t /* width from decompiler */ *)(iVar1 + param_1[0x15f]) = uVar4;

      (**(code **)(*param_1 + 0xa8))();

      (**(code **)(**(int **)(iVar1 + param_1[0x15f]) + 0x28))();

      (**(code **)(**(int **)(iVar1 + param_1[0x15f]) + 0x74))();

      iVar6 = 0;

      (**(code **)(**(int **)(iVar1 + param_1[0x15f]) + 0x300))();

      pvVar2 = operator_new(0x488);

      if (pvVar2 == (void *)0x0) {

        uVar4 = 0;

      }

      else {

        uVar4 = FUN_007b5dd0();

      }

      *(uint32_t /* width from decompiler */ *)(iVar1 + param_1[0x160]) = uVar4;

      (**(code **)(*param_1 + 0xa8))();

      (**(code **)(**(int **)(iVar1 + param_1[0x160]) + 0x28))();

      pvVar2 = operator_new(0x488);

      if (pvVar2 == (void *)0x0) {

        uVar4 = 0;

      }

      else {

        uVar4 = FUN_007b5dd0();

      }

      *(uint32_t /* width from decompiler */ *)(iVar1 + param_1[0x161]) = uVar4;

      (**(code **)(*param_1 + 0xa8))();

      (**(code **)(**(int **)(iVar1 + param_1[0x161]) + 0x28))();

      pvVar2 = operator_new(0x4cc);

      uVar4 = 0;

      if (pvVar2 != (void *)0x0) {

        iVar3 = iVar6;

        uVar4 = FUN_0079c860();

      }

      *(uint32_t /* width from decompiler */ *)(iVar1 + param_1[0x166]) = uVar4;

      (**(code **)(*param_1 + 0xa8))();

      (**(code **)(**(int **)(iVar1 + param_1[0x166]) + 0x28))();

      (**(code **)(**(int **)(iVar1 + param_1[0x166]) + 0x74))();

      pvVar2 = operator_new(0x488);

      if (pvVar2 == (void *)0x0) {

        uVar4 = 0;

      }

      else {

        uVar4 = FUN_007b5dd0();

      }

      *(uint32_t /* width from decompiler */ *)(iVar1 + param_1[0x163]) = uVar4;

      (**(code **)(*param_1 + 0xa8))();

      (**(code **)(**(int **)(iVar1 + param_1[0x163]) + 0x28))();

      pvVar2 = operator_new(0x488);

      if (pvVar2 == (void *)0x0) {

        uVar4 = 0;

      }

      else {

        uVar4 = FUN_007b5dd0();

      }

      *(uint32_t /* width from decompiler */ *)(iVar1 + param_1[0x164]) = uVar4;

      (**(code **)(*param_1 + 0xa8))();

      (**(code **)(**(int **)(iVar1 + param_1[0x164]) + 0x28))();

      (**(code **)(**(int **)(iVar1 + param_1[0x164]) + 0xcc))();

      pcStack_228 = (char *)0x8c1b81;

      pcStack_228 = operator_new(0x488);

      if (pcStack_228 == (char *)0x0) {

        uVar4 = 0;

      }

      else {

        uVar4 = FUN_007b5dd0();

      }

      *(uint32_t /* width from decompiler */ *)(iVar1 + param_1[0x165]) = uVar4;

      pcStack_228 = (char *)0x8c1bc7;

      (**(code **)(*param_1 + 0xa8))();

      pcStack_228 = "i_d_invlist_2d_wnd_item_icon.xml";

      (**(code **)(**(int **)(iVar1 + param_1[0x165]) + 0x28))();

      pcStack_230 = (char *)0x8c1be4;

      pcStack_230 = operator_new(0x488);

      if (pcStack_230 == (char *)0x0) {

        uVar4 = 0;

      }

      else {

        puStack_234 = (uint8_t *)0x8c1c02;

        uVar4 = FUN_007b5dd0();

      }

      *(uint32_t /* width from decompiler */ *)(iVar1 + param_1[0x162]) = uVar4;

      pcStack_230 = (char *)0x8c1c2a;

      (**(code **)(*param_1 + 0xa8))();

      pcStack_230 = "i_d_invlist_2d_wnd_item_icon_frame.xml";

      puStack_234 = (uint8_t *)0x8c1c3d;

      (**(code **)(**(int **)(iVar1 + param_1[0x162]) + 0x28))();

      puStack_234 = &stack0xfffffe88;

      uStack_238 = 0x8c1c56;

      iVar6 = (**(code **)(**(int **)(iVar1 + param_1[0x15e]) + 0x134))();

      uStack_238 = 0;

      uStack_23c = 1;

      ppcStack_240 = &pcStack_14c;

      iVar6 = (int)((float)DAT_00d1e81c *

                    ((float)param_1[0x14b] + *(float *)(iVar6 + 4)) * (float)(iVar3 + -0xa812) *

                   DAT_00aaa678);

      uStack_244 = 0x8c1ca6;

      (**(code **)(**(int **)(iVar1 + param_1[0x15e]) + 0x120))();

      uStack_244 = 0;

      uStack_248 = 1;

      puStack_24c = &uStack_1c8;

      puStack_250 = (uint8_t *)0x8c1cc8;

      (**(code **)(**(int **)(iVar1 + param_1[0x15e]) + 0x120))();

      puStack_250 = &stack0xfffffe04;

      uStack_254 = 0x8c1ce8;

      (**(code **)(**(int **)(iVar1 + param_1[0x15e]) + 0x110))();

      uStack_254 = 0;

      uStack_258 = 1;

      puStack_25c = &stack0xfffffe10;

      uStack_260 = 0x8c1d02;

      (**(code **)(**(int **)(iVar1 + param_1[0x15f]) + 0x120))();

      uStack_260 = 0;

      uStack_264 = 1;

      puStack_268 = &uStack_1d4;

      ppcStack_26c = (char **)0x8c1d24;

      puVar5 = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(iVar1 + param_1[0x15f]) + 0x120))();

      pcStack_228 = (char *)*puVar5;

      ppcStack_26c = &pcStack_228;

      uStack_270 = 0x8c1d44;

      (**(code **)(**(int **)(iVar1 + param_1[0x15f]) + 0x110))();

      uStack_270 = 0;

      uStack_274 = 1;

      puStack_278 = &uStack_194;

      uStack_27c = 0x8c1d61;

      iVar3 = (**(code **)(**(int **)(iVar1 + param_1[0x160]) + 0x120))();

      iVar3 = *(int *)(iVar3 + 4);

      uStack_27c = 0;

      uStack_280 = 1;

      puStack_284 = &stack0xfffffe20;

      puStack_288 = (uint32_t /* width from decompiler */ *)0x8c1d83;

      puVar5 = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(iVar1 + param_1[0x160]) + 0x120))();

      uStack_254 = *puVar5;

      puStack_288 = &uStack_254;

      uStack_28c = 0x8c1da3;

      puStack_250 = (uint8_t *)(iVar3 + iVar6);

      (**(code **)(**(int **)(iVar1 + param_1[0x160]) + 0x110))();

      uStack_28c = 0;

      uStack_290 = 1;

      ppvStack_294 = &pvStack_1c0;

      iStack_298 = 0x8c1dc0;

      iVar3 = (**(code **)(**(int **)(iVar1 + param_1[0x161]) + 0x120))();

      iVar3 = *(int *)(iVar3 + 4);

      iStack_298 = 0;

      uStack_29c = 1;

      puStack_2a0 = &stack0xfffffe14;

      ppuStack_2a4 = (uint32_t /* width from decompiler */ **)0x8c1de2;

      puStack_288 = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(iVar1 + param_1[0x161]) + 0x120))();

      puStack_288 = (uint32_t /* width from decompiler */ *)*puStack_288;

      ppuStack_2a4 = &puStack_288;

      uStack_2a8 = 0x8c1e02;

      puStack_284 = (uint8_t *)(iVar3 + iVar6);

      (**(code **)(**(int **)(iVar1 + param_1[0x161]) + 0x110))();

      uStack_2a8 = 0;

      iStack_2ac = 1;

      puStack_2b0 = &uStack_23c;

      uStack_2b4 = 0x8c1e1c;

      iVar3 = (**(code **)(**(int **)(iVar1 + param_1[0x163]) + 0x120))();

      iVar3 = *(int *)(iVar3 + 4);

      uStack_2b4 = 0;

      iStack_2b8 = 1;

      pppcStack_2bc = &ppcStack_240;

      puStack_2c0 = (uint32_t /* width from decompiler */ *)0x8c1e3b;

      puVar5 = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(iVar1 + param_1[0x163]) + 0x120))();

      uStack_29c = *puVar5;

      puStack_2c0 = &uStack_29c;

      iStack_2c4 = 0x8c1e5b;

      iStack_298 = iVar3 + iVar6;

      (**(code **)(**(int **)(iVar1 + param_1[0x163]) + 0x110))();

      iStack_2c4 = 0;

      uStack_2c8 = 1;

      pppcStack_2cc = &ppcStack_240;

      iStack_2d0 = 0x8c1e78;

      iVar3 = (**(code **)(**(int **)(iVar1 + param_1[0x164]) + 0x120))();

      iVar3 = *(int *)(iVar3 + 4);

      iStack_2d0 = 0;

      uStack_2d4 = 1;

      puStack_2b0 = (uint32_t /* width from decompiler */ *)

                    (**(code **)(**(int **)(iVar1 + param_1[0x164]) + 0x120))(&uStack_23c);

      puStack_2b0 = (uint32_t /* width from decompiler */ *)*puStack_2b0;

      iStack_2ac = iVar3 + iVar6;

      (**(code **)(**(int **)(iVar1 + param_1[0x164]) + 0x110))(&puStack_2b0);

      iVar3 = (**(code **)(**(int **)(iVar1 + param_1[0x165]) + 0x120))(&uStack_23c,1,0);

      iVar3 = *(int *)(iVar3 + 4);

      puVar5 = (uint32_t /* width from decompiler */ *)

               (**(code **)(**(int **)(iVar1 + param_1[0x165]) + 0x120))(&uStack_238,1,0);

      pppcStack_2bc = (char ***)*puVar5;

      iStack_2b8 = iVar3 + iVar6;

      (**(code **)(**(int **)(iVar1 + param_1[0x165]) + 0x110))(&pppcStack_2bc);

      iVar3 = (**(code **)(**(int **)(iVar1 + param_1[0x166]) + 0x120))(&uStack_238,1,0);

      iVar3 = *(int *)(iVar3 + 4);

      puVar5 = (uint32_t /* width from decompiler */ *)

               (**(code **)(**(int **)(iVar1 + param_1[0x166]) + 0x120))(&puStack_234,1,0);

      uStack_2c8 = *puVar5;

      iStack_2c4 = iVar3 + iVar6;

      (**(code **)(**(int **)(iVar1 + param_1[0x166]) + 0x110))(&uStack_2c8);

      iVar3 = (**(code **)(**(int **)(iVar1 + param_1[0x162]) + 0x120))(&puStack_234,1,0);

      iVar3 = *(int *)(iVar3 + 4);

      puVar5 = (uint32_t /* width from decompiler */ *)

               (**(code **)(**(int **)(iVar1 + param_1[0x162]) + 0x120))(&pcStack_230,1,0);

      uStack_2d4 = *puVar5;

      iStack_2d0 = iVar3 + iVar6;

      (**(code **)(**(int **)(iVar1 + param_1[0x162]) + 0x110))(&uStack_2d4);

      iVar3 = iStack_1c4 + 1;

      iVar6 = iStack_1c4 + -0xa811;

      iVar1 = iVar1 + 4;

      iStack_1c4 = iVar3;

    } while (iVar6 < param_1[0x14c]);

  }

LAB_008c1ff6:

  FUN_008c0d10();

  param_1[0x127] = 40000;

  (**(code **)(*param_1 + 0x448))();

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = pvStack_d8;

  return;

}
