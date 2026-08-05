// READABILITY (auto CF):
//  - Body size: ~396 non-empty decompiler lines.
//  - Control keywords: if×13, do×2, while×2, return×1.
//  - Notable callees: FUN_007b5dd0×8, FUN_0078f890, FUN_00792600, FUN_0079c860, FUN_008b6d50, FUN_008b7480.
//  - Strings: "i_d_m_list_2d_sb_inventory_list.xml"; "i_d_m_list_2d_wnd_item_time_left.xml"; "i_d_m_list_2d_wnd_item_icon.xml"; "i_d_m_list_2d_wnd_item_icon_frame.xml".
//  - Return sites: 1.

// =============================================================================
// Inv_i_d_m_list_2d_sb_inventory_list_xml_008b7480
// -----------------------------------------------------------------------------
// Stable ID: aa_008b7480
// Address:   0x008b7480  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "i_d_m_list_2d_sb_inventory_list.xml"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Inv_i_d_m_list_2d_sb_inventory_list_xml_008b7480(int *param_1)



{

  int iVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  int iVar6;

  uint32_t /* width from decompiler */ uStack_238;

  int iStack_234;

  uint8_t **ppuStack_230;

  uint32_t /* width from decompiler */ uStack_22c;

  int iStack_228;

  uint32_t /* width from decompiler */ *puStack_224;

  uint8_t **ppuStack_220;

  int iStack_21c;

  uint32_t /* width from decompiler */ uStack_218;

  uint32_t /* width from decompiler */ *puStack_214;

  int iStack_210;

  uint32_t /* width from decompiler */ uStack_20c;

  uint32_t /* width from decompiler */ **ppuStack_208;

  int *piStack_204;

  uint32_t /* width from decompiler */ uStack_200;

  int iStack_1fc;

  void **ppvStack_1f8;

  uint32_t /* width from decompiler */ uStack_1f4;

  uint32_t /* width from decompiler */ uStack_1f0;

  uint32_t /* width from decompiler */ *puStack_1ec;

  uint8_t *puStack_1e8;

  uint32_t /* width from decompiler */ uStack_1e4;

  uint32_t /* width from decompiler */ uStack_1e0;

  uint8_t *puStack_1dc;

  uint32_t /* width from decompiler */ uStack_1d8;

  uint32_t /* width from decompiler */ uStack_1d4;

  char **ppcStack_1d0;

  char **ppcStack_1cc;

  uint32_t /* width from decompiler */ uStack_1c8;

  uint32_t /* width from decompiler */ uStack_1c4;

  void **ppvStack_1c0;

  uint32_t /* width from decompiler */ uStack_1bc;

  uint32_t /* width from decompiler */ uStack_1b8;

  char **ppcStack_1b4;

  uint8_t *puStack_1b0;

  uint32_t /* width from decompiler */ uStack_1ac;

  uint32_t /* width from decompiler */ uStack_1a8;

  uint8_t *puStack_1a4;

  uint32_t /* width from decompiler */ uStack_1a0;

  uint32_t /* width from decompiler */ uStack_19c;

  uint8_t *puStack_198;

  char *pcStack_194;

  char *pcStack_18c;

  char *pcStack_160;

  int iStack_150;

  void *pvStack_124;

  uint32_t /* width from decompiler */ uStack_120;

  uint32_t /* width from decompiler */ uStack_11c;

  char *pcStack_118;

  void *local_fc;

  uint8_t auStack_f8 [72];

  uint8_t auStack_b0 [40];

  uint32_t /* width from decompiler */ uStack_88;

  uint32_t /* width from decompiler */ uStack_80;

  uint32_t /* width from decompiler */ uStack_74;

  uint32_t /* width from decompiler */ uStack_6c;

  uint32_t /* width from decompiler */ uStack_64;

  uint32_t /* width from decompiler */ uStack_5c;

  uint32_t /* width from decompiler */ uStack_54;

  uint32_t /* width from decompiler */ uStack_40;

  void *pvStack_3c;

  uint32_t /* width from decompiler */ uStack_34;

  void *pvStack_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ local_c;

  

  local_c = 0xffffffff;

  puStack_10 = &LAB_009b9c71;

  pvStack_14 = ExceptionList;

  ExceptionList = &pvStack_14;

  FUN_00792600();

  pcStack_118 = (char *)0x8b74b6;

  local_fc = operator_new(0x954);

  iVar5 = 0;

  local_c = 0;

  if (local_fc == (void *)0x0) {

    iVar1 = 0;

  }

  else {

    iVar1 = FUN_0078f890();

  }

  local_c = 0xffffffff;

  param_1[0x149] = iVar1;

  pcStack_118 = (char *)0x8b74f0;

  (**(code **)(*param_1 + 0xa8))();

  pcStack_118 = "i_d_m_list_2d_sb_inventory_list.xml";

  uStack_11c = 0x8b7500;

  (**(code **)(*(int *)param_1[0x149] + 0x28))();

  uStack_11c = 0x9c43;

  uStack_120 = 0x8b7510;

  (**(code **)(*(int *)param_1[0x149] + 0x74))();

  uStack_120 = 0x8b751e;

  (**(code **)(*(int *)param_1[0x149] + 0x43c))();

  uStack_120 = 1;

  pvStack_124 = (void *)0x8b752e;

  (**(code **)(*(int *)param_1[0x149] + 0x468))();

  pvStack_124 = (void *)0x0;

  (**(code **)(*(int *)param_1[0x149] + 0x454))();

  param_1[0x14a] = 0;

  param_1[0x14c] = -1;

  param_1[0x14d] = -1;

  if (param_1[0x148] != 0) {

    pvVar2 = operator_new__(param_1[0x148] * 4);

    param_1[0x14f] = (int)pvVar2;

    pvVar2 = operator_new__(param_1[0x148] * 4);

    param_1[0x150] = (int)pvVar2;

    pvVar2 = operator_new__(param_1[0x148] * 4);

    param_1[0x151] = (int)pvVar2;

    pvVar2 = operator_new__(param_1[0x148] * 4);

    param_1[0x152] = (int)pvVar2;

    pvVar2 = operator_new__(param_1[0x148] * 4);

    param_1[0x153] = (int)pvVar2;

    pvVar2 = operator_new__(param_1[0x148] * 4);

    param_1[0x154] = (int)pvVar2;

    pvVar2 = operator_new__(param_1[0x148] * 4);

    param_1[0x155] = (int)pvVar2;

    pvVar2 = operator_new__(param_1[0x148] * 4);

    param_1[0x156] = (int)pvVar2;

    iStack_150 = 0x8b761b;

    pvVar2 = operator_new__(param_1[0x148] * 4);

    param_1[0x157] = (int)pvVar2;

    iVar1 = 0;

    if (0 < param_1[0x148]) {

      do {

        *(uint32_t /* width from decompiler */ *)(param_1[0x14f] + iVar1 * 4) = 0;

        *(uint32_t /* width from decompiler */ *)(param_1[0x150] + iVar1 * 4) = 0;

        *(uint32_t /* width from decompiler */ *)(param_1[0x151] + iVar1 * 4) = 0;

        *(uint32_t /* width from decompiler */ *)(param_1[0x152] + iVar1 * 4) = 0;

        *(uint32_t /* width from decompiler */ *)(param_1[0x153] + iVar1 * 4) = 0;

        *(uint32_t /* width from decompiler */ *)(param_1[0x154] + iVar1 * 4) = 0;

        *(uint32_t /* width from decompiler */ *)(param_1[0x155] + iVar1 * 4) = 0;

        *(uint32_t /* width from decompiler */ *)(param_1[0x156] + iVar1 * 4) = 0;

        *(uint32_t /* width from decompiler */ *)(param_1[0x157] + iVar1 * 4) = 0;

        iVar1 = iVar1 + 1;

      } while (iVar1 < param_1[0x148]);

    }

  }

  (**(code **)(*param_1 + 0x404))();

  (**(code **)(*(int *)param_1[0x14e] + 0xcc))();

  if (0 < param_1[0x148]) {

    do {

      pvStack_124 = operator_new(0x488);

      uStack_34 = 1;

      if (pvStack_124 == (void *)0x0) {

        uVar3 = 0;

      }

      else {

        uVar3 = FUN_007b5dd0();

      }

      uStack_34 = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(param_1[0x14f] + iVar5 * 4) = uVar3;

      (**(code **)(*param_1 + 0xa8))();

      (**(code **)(**(int **)(param_1[0x14f] + iVar5 * 4) + 0x28))();

      (**(code **)(**(int **)(param_1[0x14f] + iVar5 * 4) + 0x74))();

      pvVar2 = operator_new(0x4cc);

      uStack_40 = 2;

      uVar3 = 0;

      if (pvVar2 != (void *)0x0) {

        uVar3 = FUN_0079c860();

      }

      uStack_40 = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(param_1[0x157] + iVar5 * 4) = uVar3;

      (**(code **)(*param_1 + 0xa8))();

      iStack_150 = 0x8b7798;

      (**(code **)(**(int **)(param_1[0x157] + iVar5 * 4) + 0x28))();

      iStack_150 = iVar5 + 0x9c45;

      (**(code **)(**(int **)(param_1[0x157] + iVar5 * 4) + 0x74))();

      (**(code **)(**(int **)(param_1[0x157] + iVar5 * 4) + 0x3c8))();

      pcStack_160 = (char *)0x8b77cc;

      pcStack_160 = operator_new(0x488);

      uStack_54 = 3;

      if (pcStack_160 == (char *)0x0) {

        uVar3 = 0;

      }

      else {

        uVar3 = FUN_007b5dd0();

      }

      uStack_54 = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(param_1[0x156] + iVar5 * 4) = uVar3;

      pcStack_160 = (char *)0x8b7812;

      (**(code **)(*param_1 + 0xa8))();

      pcStack_160 = "i_d_m_list_2d_wnd_item_time_left.xml";

      (**(code **)(**(int **)(param_1[0x156] + iVar5 * 4) + 0x28))();

      pvVar2 = operator_new(0x488);

      uStack_5c = 4;

      if (pvVar2 == (void *)0x0) {

        uVar3 = 0;

      }

      else {

        uVar3 = FUN_007b5dd0();

      }

      uStack_5c = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(param_1[0x150] + iVar5 * 4) = uVar3;

      (**(code **)(*param_1 + 0xa8))();

      (**(code **)(**(int **)(param_1[0x150] + iVar5 * 4) + 0x28))();

      pvVar2 = operator_new(0x488);

      uStack_64 = 5;

      if (pvVar2 == (void *)0x0) {

        uVar3 = 0;

      }

      else {

        uVar3 = FUN_007b5dd0();

      }

      uStack_64 = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(param_1[0x151] + iVar5 * 4) = uVar3;

      (**(code **)(*param_1 + 0xa8))();

      (**(code **)(**(int **)(param_1[0x151] + iVar5 * 4) + 0x28))();

      pvVar2 = operator_new(0x488);

      uStack_6c = 6;

      if (pvVar2 == (void *)0x0) {

        uVar3 = 0;

      }

      else {

        uVar3 = FUN_007b5dd0();

      }

      uStack_6c = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(param_1[0x153] + iVar5 * 4) = uVar3;

      (**(code **)(*param_1 + 0xa8))();

      (**(code **)(**(int **)(param_1[0x153] + iVar5 * 4) + 0x28))();

      pvVar2 = operator_new(0x488);

      uStack_74 = 7;

      if (pvVar2 == (void *)0x0) {

        uVar3 = 0;

      }

      else {

        uVar3 = FUN_007b5dd0();

      }

      uStack_74 = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(param_1[0x154] + iVar5 * 4) = uVar3;

      (**(code **)(*param_1 + 0xa8))();

      (**(code **)(**(int **)(param_1[0x154] + iVar5 * 4) + 0x28))();

      (**(code **)(**(int **)(param_1[0x154] + iVar5 * 4) + 0xcc))();

      pcStack_18c = (char *)0x8b79ce;

      pcStack_18c = operator_new(0x488);

      uStack_80 = 8;

      if (pcStack_18c == (char *)0x0) {

        uVar3 = 0;

      }

      else {

        uVar3 = FUN_007b5dd0();

      }

      uStack_80 = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(param_1[0x155] + iVar5 * 4) = uVar3;

      pcStack_18c = (char *)0x8b7a14;

      (**(code **)(*param_1 + 0xa8))();

      pcStack_18c = "i_d_m_list_2d_wnd_item_icon.xml";

      (**(code **)(**(int **)(param_1[0x155] + iVar5 * 4) + 0x28))();

      pcStack_194 = (char *)0x8b7a31;

      pcStack_194 = operator_new(0x488);

      uStack_88 = 9;

      if (pcStack_194 == (char *)0x0) {

        uVar3 = 0;

      }

      else {

        puStack_198 = (uint8_t *)0x8b7a4f;

        uVar3 = FUN_007b5dd0();

      }

      uStack_88 = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(param_1[0x152] + iVar5 * 4) = uVar3;

      pcStack_194 = (char *)0x8b7a77;

      (**(code **)(*param_1 + 0xa8))();

      pcStack_194 = "i_d_m_list_2d_wnd_item_icon_frame.xml";

      puStack_198 = (uint8_t *)0x8b7a8a;

      (**(code **)(**(int **)(param_1[0x152] + iVar5 * 4) + 0x28))();

      puStack_198 = &stack0xfffffef4;

      uStack_19c = 0x8b7aa3;

      iVar1 = (**(code **)(**(int **)(param_1[0x14f] + iVar5 * 4) + 0x134))();

      uStack_19c = 0;

      uStack_1a0 = 1;

      puStack_1a4 = auStack_b0;

      iVar6 = (int)((float)DAT_00d1e81c *

                    ((float)param_1[0x147] + *(float *)(iVar1 + 4)) * (float)iVar5 * DAT_00aaa678);

      uStack_1a8 = 0x8b7aed;

      (**(code **)(**(int **)(param_1[0x14f] + iVar5 * 4) + 0x120))();

      uStack_1a8 = 0;

      uStack_1ac = 1;

      puStack_1b0 = &stack0xfffffed4;

      ppcStack_1b4 = (char **)0x8b7b0f;

      puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(param_1[0x14f] + iVar5 * 4) + 0x120))();

      pcStack_160 = (char *)*puVar4;

      ppcStack_1b4 = &pcStack_160;

      uStack_1b8 = 0x8b7b2f;

      (**(code **)(**(int **)(param_1[0x14f] + iVar5 * 4) + 0x110))();

      uStack_1b8 = 0;

      uStack_1bc = 1;

      ppvStack_1c0 = &local_fc;

      uStack_1c4 = 0x8b7b4c;

      (**(code **)(**(int **)(param_1[0x150] + iVar5 * 4) + 0x120))();

      uStack_1c4 = 0;

      uStack_1c8 = 1;

      ppcStack_1cc = &pcStack_160;

      ppcStack_1d0 = (char **)0x8b7b6b;

      puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(param_1[0x150] + iVar5 * 4) + 0x120))();

      pcStack_18c = (char *)*puVar4;

      ppcStack_1d0 = &pcStack_18c;

      uStack_1d4 = 0x8b7b8b;

      (**(code **)(**(int **)(param_1[0x150] + iVar5 * 4) + 0x110))();

      uStack_1d4 = 0;

      uStack_1d8 = 1;

      puStack_1dc = auStack_f8;

      uStack_1e0 = 0x8b7ba8;

      iVar1 = (**(code **)(**(int **)(param_1[0x151] + iVar5 * 4) + 0x120))();

      iVar1 = *(int *)(iVar1 + 4);

      uStack_1e0 = 0;

      uStack_1e4 = 1;

      puStack_1e8 = &stack0xfffffebc;

      puStack_1ec = (uint32_t /* width from decompiler */ *)0x8b7bca;

      puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(param_1[0x151] + iVar5 * 4) + 0x120))();

      uStack_1b8 = *puVar4;

      puStack_1ec = &uStack_1b8;

      uStack_1f0 = 0x8b7bea;

      ppcStack_1b4 = (char **)(iVar1 + iVar6);

      (**(code **)(**(int **)(param_1[0x151] + iVar5 * 4) + 0x110))();

      uStack_1f0 = 0;

      uStack_1f4 = 1;

      ppvStack_1f8 = &pvStack_124;

      iStack_1fc = 0x8b7c07;

      iVar1 = (**(code **)(**(int **)(param_1[0x153] + iVar5 * 4) + 0x120))();

      iVar1 = *(int *)(iVar1 + 4);

      iStack_1fc = 0;

      uStack_200 = 1;

      piStack_204 = &iStack_150;

      ppuStack_208 = (uint32_t /* width from decompiler */ **)0x8b7c29;

      puStack_1ec = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(param_1[0x153] + iVar5 * 4) + 0x120))();

      puStack_1ec = (uint32_t /* width from decompiler */ *)*puStack_1ec;

      ppuStack_208 = &puStack_1ec;

      uStack_20c = 0x8b7c49;

      puStack_1e8 = (uint8_t *)(iVar1 + iVar6);

      (**(code **)(**(int **)(param_1[0x153] + iVar5 * 4) + 0x110))();

      uStack_20c = 0;

      iStack_210 = 1;

      puStack_214 = &uStack_1a0;

      uStack_218 = 0x8b7c63;

      iVar1 = (**(code **)(**(int **)(param_1[0x154] + iVar5 * 4) + 0x120))();

      iVar1 = *(int *)(iVar1 + 4);

      uStack_218 = 0;

      iStack_21c = 1;

      ppuStack_220 = &puStack_1a4;

      puStack_224 = (uint32_t /* width from decompiler */ *)0x8b7c82;

      puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(param_1[0x154] + iVar5 * 4) + 0x120))();

      uStack_200 = *puVar4;

      puStack_224 = &uStack_200;

      iStack_228 = 0x8b7ca2;

      iStack_1fc = iVar1 + iVar6;

      (**(code **)(**(int **)(param_1[0x154] + iVar5 * 4) + 0x110))();

      iStack_228 = 0;

      uStack_22c = 1;

      ppuStack_230 = &puStack_1a4;

      iStack_234 = 0x8b7cbf;

      iVar1 = (**(code **)(**(int **)(param_1[0x155] + iVar5 * 4) + 0x120))();

      iVar1 = *(int *)(iVar1 + 4);

      iStack_234 = 0;

      uStack_238 = 1;

      puStack_214 = (uint32_t /* width from decompiler */ *)

                    (**(code **)(**(int **)(param_1[0x155] + iVar5 * 4) + 0x120))(&uStack_1a0);

      puStack_214 = (uint32_t /* width from decompiler */ *)*puStack_214;

      iStack_210 = iVar1 + iVar6;

      (**(code **)(**(int **)(param_1[0x155] + iVar5 * 4) + 0x110))(&puStack_214);

      iVar1 = (**(code **)(**(int **)(param_1[0x157] + iVar5 * 4) + 0x120))(&uStack_1a0,1,0);

      iVar1 = *(int *)(iVar1 + 4);

      puVar4 = (uint32_t /* width from decompiler */ *)

               (**(code **)(**(int **)(param_1[0x157] + iVar5 * 4) + 0x120))(&uStack_19c,1,0);

      ppuStack_220 = (uint8_t **)*puVar4;

      iStack_21c = iVar1 + iVar6;

      (**(code **)(**(int **)(param_1[0x157] + iVar5 * 4) + 0x110))(&ppuStack_220);

      iVar1 = (**(code **)(**(int **)(param_1[0x152] + iVar5 * 4) + 0x120))(&uStack_19c,1,0);

      iVar1 = *(int *)(iVar1 + 4);

      puVar4 = (uint32_t /* width from decompiler */ *)

               (**(code **)(**(int **)(param_1[0x152] + iVar5 * 4) + 0x120))(&puStack_198,1,0);

      uStack_22c = *puVar4;

      iStack_228 = iVar1 + iVar6;

      (**(code **)(**(int **)(param_1[0x152] + iVar5 * 4) + 0x110))(&uStack_22c);

      iVar1 = (**(code **)(**(int **)(param_1[0x156] + iVar5 * 4) + 0x120))(&puStack_198,1,0);

      iVar1 = *(int *)(iVar1 + 4);

      puVar4 = (uint32_t /* width from decompiler */ *)

               (**(code **)(**(int **)(param_1[0x156] + iVar5 * 4) + 0x120))(&pcStack_194,1,0);

      uStack_238 = *puVar4;

      iStack_234 = iVar1 + iVar6;

      (**(code **)(**(int **)(param_1[0x156] + iVar5 * 4) + 0x110))(&uStack_238);

      iVar5 = iVar5 + 1;

    } while (iVar5 < param_1[0x148]);

  }

  FUN_008b6d50();

  param_1[0x127] = 40000;

  (**(code **)(*param_1 + 0x448))();

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = pvStack_3c;

  return;

}
