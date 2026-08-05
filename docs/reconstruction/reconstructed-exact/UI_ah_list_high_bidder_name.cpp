// =============================================================================
// UI_ah_list_high_bidder_name
// -----------------------------------------------------------------------------
// Stable ID: aa_00905d80
// Address:   0x00905d80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_ah_list_high_bidder_name @ 0x00905d80
// Stable ID: aa_00905d80
// Embedded strings (evidence for future rename):
//   - "i_d_ah_list_2d_wnd_item_grid_info.xml"
//   - "i_d_ah_list_2d_wnd_item_icon_frame.xml"
//   - "i_d_ah_list_2d_wnd_high_bidder_name.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~534 non-empty decompiler lines.
//  - Control keywords: if×17, do×2, while×2, goto×1, return×1.
//  - Notable callees: FUN_007b5dd0×12, FUN_0078f890, FUN_00792600, FUN_0079c860, FUN_00905740, UI_ah_list_high_bidder_name.
//  - Strings: "i_d_ah_list_2d_wnd_item_grid_info.xml"; "i_d_ah_list_2d_wnd_item_icon_frame.xml"; "i_d_ah_list_2d_wnd_high_bidder_name.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_ah_list_2d_wnd_high_bidder_name.xml"
 * Domain alias of FUN_00905d80 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall UI_ah_list_high_bidder_name(int *param_1)



{

  void *pvVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int iVar6;

  uint32_t /* width from decompiler */ uStack_308;

  uint32_t /* width from decompiler */ *puStack_304;

  uint32_t /* width from decompiler */ uStack_300;

  uint32_t /* width from decompiler */ uStack_2fc;

  uint32_t /* width from decompiler */ **ppuStack_2f8;

  uint32_t /* width from decompiler */ *puStack_2f4;

  uint32_t /* width from decompiler */ uStack_2f0;

  int iStack_2ec;

  uint32_t /* width from decompiler */ *puStack_2e8;

  uint32_t /* width from decompiler */ uStack_2e4;

  int iStack_2e0;

  uint32_t /* width from decompiler */ *puStack_2dc;

  uint32_t /* width from decompiler */ *puStack_2d8;

  int iStack_2d4;

  uint32_t /* width from decompiler */ uStack_2d0;

  uint32_t /* width from decompiler */ *puStack_2cc;

  int iStack_2c8;

  uint32_t /* width from decompiler */ uStack_2c4;

  uint32_t /* width from decompiler */ **ppuStack_2c0;

  void **ppvStack_2bc;

  uint32_t /* width from decompiler */ uStack_2b8;

  int iStack_2b4;

  uint8_t *puStack_2b0;

  uint32_t /* width from decompiler */ uStack_2ac;

  uint32_t /* width from decompiler */ uStack_2a8;

  uint32_t /* width from decompiler */ *puStack_2a4;

  uint8_t *puStack_2a0;

  uint32_t /* width from decompiler */ uStack_29c;

  uint32_t /* width from decompiler */ uStack_298;

  uint8_t *puStack_294;

  uint32_t /* width from decompiler */ uStack_290;

  uint32_t /* width from decompiler */ uStack_28c;

  char **ppcStack_288;

  uint8_t *puStack_284;

  uint32_t /* width from decompiler */ uStack_280;

  uint32_t /* width from decompiler */ uStack_27c;

  uint8_t *puStack_278;

  uint32_t /* width from decompiler */ uStack_274;

  uint32_t /* width from decompiler */ uStack_270;

  uint32_t /* width from decompiler */ *puStack_26c;

  uint8_t *puStack_268;

  uint32_t /* width from decompiler */ uStack_264;

  uint32_t /* width from decompiler */ uStack_260;

  char **ppcStack_25c;

  uint32_t /* width from decompiler */ uStack_258;

  uint32_t /* width from decompiler */ uStack_254;

  char **ppcStack_250;

  uint8_t *puStack_24c;

  uint32_t /* width from decompiler */ uStack_248;

  uint32_t /* width from decompiler */ uStack_244;

  uint8_t *puStack_240;

  uint32_t /* width from decompiler */ uStack_23c;

  uint32_t /* width from decompiler */ uStack_238;

  char **ppcStack_234;

  uint8_t *puStack_230;

  uint32_t /* width from decompiler */ uStack_22c;

  uint32_t /* width from decompiler */ uStack_228;

  uint8_t *puStack_224;

  uint32_t /* width from decompiler */ uStack_220;

  uint32_t /* width from decompiler */ uStack_21c;

  uint8_t *puStack_218;

  char *pcStack_214;

  char *pcStack_1fc;

  char *pcStack_1d0;

  void *pvStack_1c8;

  int iStack_1c4;

  int iVar7;

  uint8_t auStack_140 [4];

  uint8_t auStack_13c [80];

  uint8_t auStack_ec [12];

  uint8_t auStack_e0 [56];

  uint32_t /* width from decompiler */ uStack_a8;

  uint32_t /* width from decompiler */ uStack_a0;

  uint32_t /* width from decompiler */ uStack_98;

  uint32_t /* width from decompiler */ uStack_90;

  uint32_t /* width from decompiler */ uStack_88;

  uint32_t /* width from decompiler */ uStack_7c;

  uint32_t /* width from decompiler */ uStack_74;

  uint32_t /* width from decompiler */ uStack_6c;

  uint32_t /* width from decompiler */ uStack_64;

  uint32_t /* width from decompiler */ uStack_54;

  uint32_t /* width from decompiler */ uStack_44;

  uint32_t /* width from decompiler */ uStack_38;

  void *pvStack_2c;

  uint32_t /* width from decompiler */ uStack_24;

  void *pvStack_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ local_c;

  

  local_c = 0xffffffff;

  puStack_10 = &LAB_009babf8;

  pvStack_14 = ExceptionList;

  ExceptionList = &pvStack_14;

  FUN_00792600();

  pvVar1 = operator_new(0x954);

  iVar6 = 0;

  local_c = 0;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0078f890();

  }

  local_c = 0xffffffff;

  param_1[0x14a] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x14a] + 0x28))();

  (**(code **)(*(int *)param_1[0x14a] + 0x74))();

  (**(code **)(*(int *)param_1[0x14a] + 0x43c))();

  (**(code **)(*(int *)param_1[0x14a] + 0x468))();

  (**(code **)(*(int *)param_1[0x14a] + 0x454))();

  param_1[0x14b] = 0;

  if (param_1[0x149] != 0) {

    pvVar1 = operator_new__(param_1[0x149] * 4);

    param_1[0x14e] = (int)pvVar1;

    pvVar1 = operator_new__(param_1[0x149] * 4);

    param_1[0x14f] = (int)pvVar1;

    pvVar1 = operator_new__(param_1[0x149] * 4);

    param_1[0x150] = (int)pvVar1;

    pvVar1 = operator_new__(param_1[0x149] * 4);

    param_1[0x151] = (int)pvVar1;

    pvVar1 = operator_new__(param_1[0x149] * 4);

    param_1[0x152] = (int)pvVar1;

    pvVar1 = operator_new__(param_1[0x149] * 4);

    param_1[0x153] = (int)pvVar1;

    pvVar1 = operator_new__(param_1[0x149] * 4);

    param_1[0x154] = (int)pvVar1;

    pvVar1 = operator_new__(param_1[0x149] * 4);

    param_1[0x155] = (int)pvVar1;

    pvVar1 = operator_new__(param_1[0x149] * 4);

    param_1[0x156] = (int)pvVar1;

    pvVar1 = operator_new__(param_1[0x149] * 4);

    param_1[0x158] = (int)pvVar1;

    pvVar1 = operator_new__(param_1[0x149] * 4);

    param_1[0x159] = (int)pvVar1;

    pvVar1 = operator_new__(param_1[0x149] * 4);

    param_1[0x15a] = (int)pvVar1;

    pvVar1 = operator_new__(param_1[0x149] * 4);

    param_1[0x15b] = (int)pvVar1;

    iStack_1c4 = 0x905f7f;

    pvVar1 = operator_new__(param_1[0x149] * 8);

    param_1[0x15c] = (int)pvVar1;

    iVar2 = 0;

    if (param_1[0x149] < 1) goto LAB_00906b36;

    do {

      *(uint32_t /* width from decompiler */ *)(param_1[0x14e] + iVar2 * 4) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1[0x14f] + iVar2 * 4) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1[0x150] + iVar2 * 4) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1[0x151] + iVar2 * 4) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1[0x152] + iVar2 * 4) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1[0x153] + iVar2 * 4) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1[0x154] + iVar2 * 4) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1[0x155] + iVar2 * 4) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1[0x156] + iVar2 * 4) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1[0x158] + iVar2 * 4) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1[0x159] + iVar2 * 4) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1[0x15a] + iVar2 * 4) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1[0x15b] + iVar2 * 4) = 0;

      iVar7 = param_1[0x15c];

      *(uint32_t /* width from decompiler */ *)(iVar7 + iVar2 * 8) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar7 + 4 + iVar2 * 8) = 0;

      iVar2 = iVar2 + 1;

    } while (iVar2 < param_1[0x149]);

  }

  if (0 < param_1[0x149]) {

    iVar2 = 0xa7fe;

    do {

      iVar7 = iVar2;

      pvVar1 = operator_new(0x4cc);

      uStack_24 = 1;

      uVar3 = 0;

      if (pvVar1 != (void *)0x0) {

        uVar3 = FUN_0079c860();

      }

      uStack_24 = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(iVar6 + param_1[0x15b]) = uVar3;

      (**(code **)(*param_1 + 0xa8))();

      (**(code **)(**(int **)(iVar6 + param_1[0x15b]) + 0x28))();

      (**(code **)(**(int **)(iVar6 + param_1[0x15b]) + 0x74))();

      (**(code **)(**(int **)(iVar6 + param_1[0x15b]) + 0x3c8))();

      pvVar1 = operator_new(0x488);

      uStack_38 = 2;

      if (pvVar1 == (void *)0x0) {

        uVar3 = 0;

      }

      else {

        uVar3 = FUN_007b5dd0();

      }

      uStack_38 = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(iVar6 + param_1[0x14e]) = uVar3;

      (**(code **)(*param_1 + 0xa8))();

      (**(code **)(**(int **)(iVar6 + param_1[0x14e]) + 0x28))();

      (**(code **)(**(int **)(iVar6 + param_1[0x14e]) + 0x74))();

      pvVar1 = operator_new(0x488);

      uStack_44 = 3;

      if (pvVar1 == (void *)0x0) {

        uVar3 = 0;

      }

      else {

        uVar3 = FUN_007b5dd0();

      }

      uStack_44 = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(iVar6 + param_1[0x14f]) = uVar3;

      (**(code **)(*param_1 + 0xa8))();

      (**(code **)(**(int **)(iVar6 + param_1[0x14f]) + 0x28))();

      (**(code **)(**(int **)(iVar6 + param_1[0x14f]) + 0x74))();

      (**(code **)(**(int **)(iVar6 + param_1[0x14f]) + 0x300))();

      pvVar1 = operator_new(0x488);

      uStack_54 = 4;

      if (pvVar1 == (void *)0x0) {

        uVar3 = 0;

      }

      else {

        iStack_1c4 = 0x906204;

        uVar3 = FUN_007b5dd0();

      }

      uStack_54 = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(iVar6 + param_1[0x150]) = uVar3;

      (**(code **)(*param_1 + 0xa8))();

      iStack_1c4 = 0x90623f;

      (**(code **)(**(int **)(iVar6 + param_1[0x150]) + 0x28))();

      iStack_1c4 = iVar2 + 0x1772;

      pvStack_1c8 = (void *)0x906254;

      (**(code **)(**(int **)(iVar6 + param_1[0x150]) + 0x74))();

      pvStack_1c8 = (void *)0x0;

      (**(code **)(**(int **)(iVar6 + param_1[0x150]) + 0x300))();

      pcStack_1d0 = (char *)0x906271;

      pcStack_1d0 = operator_new(0x488);

      uStack_64 = 5;

      if (pcStack_1d0 == (char *)0x0) {

        uVar3 = 0;

      }

      else {

        uVar3 = FUN_007b5dd0();

      }

      uStack_64 = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(iVar6 + param_1[0x151]) = uVar3;

      pcStack_1d0 = (char *)0x9062b7;

      (**(code **)(*param_1 + 0xa8))();

      pcStack_1d0 = "i_d_ah_list_2d_wnd_item_grid_info.xml";

      (**(code **)(**(int **)(iVar6 + param_1[0x151]) + 0x28))();

      pvVar1 = operator_new(0x488);

      uStack_6c = 6;

      if (pvVar1 == (void *)0x0) {

        uVar3 = 0;

      }

      else {

        uVar3 = FUN_007b5dd0();

      }

      uStack_6c = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(iVar6 + param_1[0x152]) = uVar3;

      (**(code **)(*param_1 + 0xa8))();

      (**(code **)(**(int **)(iVar6 + param_1[0x152]) + 0x28))();

      pvStack_1c8 = operator_new(0x488);

      uStack_74 = 7;

      if (pvStack_1c8 == (void *)0x0) {

        uVar3 = 0;

      }

      else {

        uVar3 = FUN_007b5dd0();

      }

      uStack_74 = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(iVar6 + param_1[0x154]) = uVar3;

      (**(code **)(*param_1 + 0xa8))();

      (**(code **)(**(int **)(iVar6 + param_1[0x154]) + 0x28))();

      pcStack_1d0 = operator_new(0x488);

      uStack_7c = 8;

      if (pcStack_1d0 == (char *)0x0) {

        uVar3 = 0;

      }

      else {

        uVar3 = FUN_007b5dd0();

      }

      uStack_7c = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(iVar6 + param_1[0x155]) = uVar3;

      (**(code **)(*param_1 + 0xa8))();

      (**(code **)(**(int **)(iVar6 + param_1[0x155]) + 0x28))();

      (**(code **)(**(int **)(iVar6 + param_1[0x155]) + 0xcc))();

      pvVar1 = operator_new(0x488);

      uStack_88 = 9;

      if (pvVar1 == (void *)0x0) {

        uVar3 = 0;

      }

      else {

        uVar3 = FUN_007b5dd0();

      }

      uStack_88 = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(iVar6 + param_1[0x156]) = uVar3;

      (**(code **)(*param_1 + 0xa8))();

      (**(code **)(**(int **)(iVar6 + param_1[0x156]) + 0x28))();

      pcStack_1fc = (char *)0x906473;

      pcStack_1fc = operator_new(0x488);

      uStack_90 = 10;

      if (pcStack_1fc == (char *)0x0) {

        uVar3 = 0;

      }

      else {

        uVar3 = FUN_007b5dd0();

      }

      uStack_90 = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(iVar6 + param_1[0x153]) = uVar3;

      pcStack_1fc = (char *)0x9064b9;

      (**(code **)(*param_1 + 0xa8))();

      pcStack_1fc = "i_d_ah_list_2d_wnd_item_icon_frame.xml";

      (**(code **)(**(int **)(iVar6 + param_1[0x153]) + 0x28))();

      pvVar1 = operator_new(0x488);

      uStack_98 = 0xb;

      if (pvVar1 == (void *)0x0) {

        uVar3 = 0;

      }

      else {

        uVar3 = FUN_007b5dd0();

      }

      uStack_98 = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(iVar6 + param_1[0x158]) = uVar3;

      (**(code **)(*param_1 + 0xa8))();

      (**(code **)(**(int **)(iVar6 + param_1[0x158]) + 0x28))();

      pvVar1 = operator_new(0x488);

      uStack_a0 = 0xc;

      if (pvVar1 == (void *)0x0) {

        uVar3 = 0;

      }

      else {

        uVar3 = FUN_007b5dd0();

      }

      uStack_a0 = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(iVar6 + param_1[0x159]) = uVar3;

      (**(code **)(*param_1 + 0xa8))();

      (**(code **)(**(int **)(iVar6 + param_1[0x159]) + 0x28))();

      pcStack_214 = (char *)0x90659c;

      pcStack_214 = operator_new(0x488);

      uStack_a8 = 0xd;

      pcStack_1fc = pcStack_214;

      if (pcStack_214 == (char *)0x0) {

        uVar3 = 0;

      }

      else {

        puStack_218 = (uint8_t *)0x9065ba;

        uVar3 = FUN_007b5dd0();

      }

      uStack_a8 = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(iVar6 + param_1[0x15a]) = uVar3;

      pcStack_214 = (char *)0x9065e2;

      (**(code **)(*param_1 + 0xa8))();

      pcStack_214 = "i_d_ah_list_2d_wnd_high_bidder_name.xml";

      puStack_218 = (uint8_t *)0x9065f5;

      (**(code **)(**(int **)(iVar6 + param_1[0x15a]) + 0x28))();

      puStack_218 = auStack_ec;

      uStack_21c = 0x90660e;

      iVar4 = (**(code **)(**(int **)(iVar6 + param_1[0x14e]) + 0x134))();

      uStack_21c = 0;

      uStack_220 = 1;

      puStack_224 = auStack_e0;

      iVar4 = (int)((float)DAT_00d1e81c *

                    ((float)param_1[0x148] + *(float *)(iVar4 + 4)) * (float)(iVar2 + -0xa7fe) *

                   DAT_00aaa678);

      uStack_228 = 0x90665e;

      (**(code **)(**(int **)(iVar6 + param_1[0x14e]) + 0x120))();

      uStack_228 = 0;

      uStack_22c = 1;

      puStack_230 = &stack0xfffffe74;

      ppcStack_234 = (char **)0x906680;

      puVar5 = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(iVar6 + param_1[0x14e]) + 0x120))();

      pcStack_1d0 = (char *)*puVar5;

      ppcStack_234 = &pcStack_1d0;

      uStack_238 = 0x9066a0;

      (**(code **)(**(int **)(iVar6 + param_1[0x14e]) + 0x110))();

      uStack_238 = 0;

      uStack_23c = 1;

      puStack_240 = auStack_13c;

      uStack_244 = 0x9066bd;

      (**(code **)(**(int **)(iVar6 + param_1[0x14f]) + 0x120))();

      uStack_244 = 0;

      uStack_248 = 1;

      puStack_24c = &stack0xfffffe68;

      ppcStack_250 = (char **)0x9066df;

      puVar5 = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(iVar6 + param_1[0x14f]) + 0x120))();

      pcStack_1fc = (char *)*puVar5;

      ppcStack_250 = &pcStack_1fc;

      uStack_254 = 0x9066ff;

      (**(code **)(**(int **)(iVar6 + param_1[0x14f]) + 0x110))();

      uStack_254 = 0;

      uStack_258 = 1;

      ppcStack_25c = &pcStack_1d0;

      uStack_260 = 0x90671c;

      iVar2 = (**(code **)(**(int **)(iVar6 + param_1[0x150]) + 0x120))();

      iVar2 = *(int *)(iVar2 + 4);

      uStack_260 = 0;

      uStack_264 = 1;

      puStack_268 = &stack0xfffffe5c;

      puStack_26c = (uint32_t /* width from decompiler */ *)0x90673e;

      puVar5 = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(iVar6 + param_1[0x150]) + 0x120))();

      uStack_238 = *puVar5;

      puStack_26c = &uStack_238;

      uStack_270 = 0x90675e;

      ppcStack_234 = (char **)(iVar2 + iVar4);

      (**(code **)(**(int **)(iVar6 + param_1[0x150]) + 0x110))();

      uStack_270 = 0;

      uStack_274 = 1;

      puStack_278 = &stack0xfffffe9c;

      uStack_27c = 0x90677b;

      (**(code **)(**(int **)(iVar6 + param_1[0x151]) + 0x120))();

      uStack_27c = 0;

      uStack_280 = 1;

      puStack_284 = &stack0xfffffe50;

      ppcStack_288 = (char **)0x90679d;

      puVar5 = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(iVar6 + param_1[0x151]) + 0x120))();

      pcStack_214 = (char *)*puVar5;

      ppcStack_288 = &pcStack_214;

      uStack_28c = 0x9067bd;

      (**(code **)(**(int **)(iVar6 + param_1[0x151]) + 0x110))();

      uStack_28c = 0;

      uStack_290 = 1;

      puStack_294 = auStack_140;

      uStack_298 = 0x9067da;

      iVar2 = (**(code **)(**(int **)(iVar6 + param_1[0x152]) + 0x120))();

      iVar2 = *(int *)(iVar2 + 4);

      uStack_298 = 0;

      uStack_29c = 1;

      puStack_2a0 = &stack0xfffffe44;

      puStack_2a4 = (uint32_t /* width from decompiler */ *)0x9067fc;

      puVar5 = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(iVar6 + param_1[0x152]) + 0x120))();

      uStack_260 = *puVar5;

      puStack_2a4 = &uStack_260;

      uStack_2a8 = 0x90681c;

      ppcStack_25c = (char **)(iVar2 + iVar4);

      (**(code **)(**(int **)(iVar6 + param_1[0x152]) + 0x110))();

      uStack_2a8 = 0;

      uStack_2ac = 1;

      puStack_2b0 = &stack0xfffffe74;

      iStack_2b4 = 0x906839;

      iVar2 = (**(code **)(**(int **)(iVar6 + param_1[0x154]) + 0x120))();

      iVar2 = *(int *)(iVar2 + 4);

      iStack_2b4 = 0;

      uStack_2b8 = 1;

      ppvStack_2bc = &pvStack_1c8;

      ppuStack_2c0 = (uint32_t /* width from decompiler */ **)0x90685b;

      puStack_2a4 = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(iVar6 + param_1[0x154]) + 0x120))();

      puStack_2a4 = (uint32_t /* width from decompiler */ *)*puStack_2a4;

      ppuStack_2c0 = &puStack_2a4;

      uStack_2c4 = 0x90687b;

      puStack_2a0 = (uint8_t *)(iVar2 + iVar4);

      (**(code **)(**(int **)(iVar6 + param_1[0x154]) + 0x110))();

      uStack_2c4 = 0;

      iStack_2c8 = 1;

      puStack_2cc = &uStack_238;

      uStack_2d0 = 0x906898;

      iVar2 = (**(code **)(**(int **)(iVar6 + param_1[0x155]) + 0x120))();

      iVar2 = *(int *)(iVar2 + 4);

      uStack_2d0 = 0;

      iStack_2d4 = 1;

      puStack_2d8 = &uStack_23c;

      puStack_2dc = (uint32_t /* width from decompiler */ *)0x9068ba;

      puVar5 = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(iVar6 + param_1[0x155]) + 0x120))();

      uStack_2b8 = *puVar5;

      puStack_2dc = &uStack_2b8;

      iStack_2e0 = 0x9068da;

      iStack_2b4 = iVar2 + iVar4;

      (**(code **)(**(int **)(iVar6 + param_1[0x155]) + 0x110))();

      iStack_2e0 = 0;

      uStack_2e4 = 1;

      puStack_2e8 = &uStack_23c;

      iStack_2ec = 0x9068f7;

      iVar2 = (**(code **)(**(int **)(iVar6 + param_1[0x156]) + 0x120))();

      iVar2 = *(int *)(iVar2 + 4);

      iStack_2ec = 0;

      uStack_2f0 = 1;

      puStack_2f4 = &uStack_238;

      ppuStack_2f8 = (uint32_t /* width from decompiler */ **)0x906919;

      puStack_2cc = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(iVar6 + param_1[0x156]) + 0x120))();

      puStack_2cc = (uint32_t /* width from decompiler */ *)*puStack_2cc;

      ppuStack_2f8 = &puStack_2cc;

      uStack_2fc = 0x906939;

      iStack_2c8 = iVar2 + iVar4;

      (**(code **)(**(int **)(iVar6 + param_1[0x156]) + 0x110))();

      uStack_2fc = 0;

      uStack_300 = 1;

      puStack_304 = &uStack_238;

      uStack_308 = 0x906956;

      iVar2 = (**(code **)(**(int **)(iVar6 + param_1[0x153]) + 0x120))();

      iVar2 = *(int *)(iVar2 + 4);

      uStack_308 = 0;

      puStack_2d8 = (uint32_t /* width from decompiler */ *)

                    (**(code **)(**(int **)(iVar6 + param_1[0x153]) + 0x120))(&ppcStack_234,1);

      puStack_2d8 = (uint32_t /* width from decompiler */ *)*puStack_2d8;

      iStack_2d4 = iVar2 + iVar4;

      (**(code **)(**(int **)(iVar6 + param_1[0x153]) + 0x110))(&puStack_2d8);

      iVar2 = (**(code **)(**(int **)(iVar6 + param_1[0x158]) + 0x120))(&ppcStack_234,1,0);

      iVar2 = *(int *)(iVar2 + 4);

      puVar5 = (uint32_t /* width from decompiler */ *)

               (**(code **)(**(int **)(iVar6 + param_1[0x158]) + 0x120))(&puStack_230,1,0);

      uStack_2e4 = *puVar5;

      iStack_2e0 = iVar2 + iVar4;

      (**(code **)(**(int **)(iVar6 + param_1[0x158]) + 0x110))(&uStack_2e4);

      iVar2 = (**(code **)(**(int **)(iVar6 + param_1[0x159]) + 0x120))(&puStack_230,1,0);

      iVar2 = *(int *)(iVar2 + 4);

      puVar5 = (uint32_t /* width from decompiler */ *)

               (**(code **)(**(int **)(iVar6 + param_1[0x159]) + 0x120))(&uStack_22c,1,0);

      uStack_2f0 = *puVar5;

      iStack_2ec = iVar2 + iVar4;

      (**(code **)(**(int **)(iVar6 + param_1[0x159]) + 0x110))(&uStack_2f0);

      iVar2 = (**(code **)(**(int **)(iVar6 + param_1[0x15a]) + 0x120))(&uStack_22c,1,0);

      iVar2 = *(int *)(iVar2 + 4);

      puVar5 = (uint32_t /* width from decompiler */ *)

               (**(code **)(**(int **)(iVar6 + param_1[0x15a]) + 0x120))(&uStack_228,1,0);

      uStack_2fc = *puVar5;

      ppuStack_2f8 = (uint32_t /* width from decompiler */ **)(iVar2 + iVar4);

      (**(code **)(**(int **)(iVar6 + param_1[0x15a]) + 0x110))(&uStack_2fc);

      iVar2 = (**(code **)(**(int **)(iVar6 + param_1[0x15b]) + 0x120))(&uStack_228,1,0);

      iVar2 = *(int *)(iVar2 + 4);

      puVar5 = (uint32_t /* width from decompiler */ *)

               (**(code **)(**(int **)(iVar6 + param_1[0x15b]) + 0x120))(&puStack_224,1,0);

      uStack_308 = *puVar5;

      puStack_304 = (uint32_t /* width from decompiler */ *)(iVar2 + iVar4);

      (**(code **)(**(int **)(iVar6 + param_1[0x15b]) + 0x110))(&uStack_308);

      iVar2 = iVar7 + 1;

      iVar6 = iVar6 + 4;

    } while (iVar7 + -0xa7fd < param_1[0x149]);

  }

LAB_00906b36:

  FUN_00905740();

  param_1[0x127] = 40000;

  (**(code **)(*param_1 + 0x448))();

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = pvStack_2c;

  return;

}
