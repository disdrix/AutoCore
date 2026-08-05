// READABILITY (auto CF):
//  - Body size: ~76 non-empty decompiler lines.
//  - Control keywords: if×6, return×3.
//  - Notable callees: FUN_0096efd0×2, FUN_0096f3e0×2, FUN_00989e00×2, CONCAT31, FUN_007b5dd0, FUN_0085cd40, FUN_0085dc30, FUN_0085e590.
//  - Strings: "i_g_2d_wnd_inventory_item_template.xml"; "i_g_2d_overlay_broken.dds"; "i_g_2d_highlight.dds".
//  - Return sites: 3.

// =============================================================================
// Inv_i_g_2d_wnd_inventory_item_template_xml_0085e590
// -----------------------------------------------------------------------------
// Stable ID: aa_0085e590
// Address:   0x0085e590  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "i_g_2d_wnd_inventory_item_template.xml"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * Inv_i_g_2d_wnd_inventory_item_template_xml_0085e590(uint32_t /* width from decompiler */ *param_1)



{

  void *pvVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b3745;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_007b5dd0(param_1,0);

  local_4 = 0;

  *param_1 = &PTR_FUN_00a65354;

  FUN_0085cd40();

  local_4._0_1_ = 1;

  *(uint8_t *)((int)param_1 + 0x492) = 0;

  *(uint8_t *)((int)param_1 + 199) = 0;

  *(uint8_t *)(param_1 + 0x124) = 0;

  *(uint8_t *)((int)param_1 + 0x491) = 0;

  param_1[0x123] = 0;

  param_1[0x143] = 0;

  param_1[0x144] = 0;

  param_1[0x125] = 0;

  param_1[0x122] = 1;

  param_1[0x12a] = 0;

  param_1[299] = 0;

  NDUIWindow_LoadInterfaceFile("i_g_2d_wnd_inventory_item_template.xml");

  FUN_0085dc30();

  local_10 = operator_new(4);

  if (local_10 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar3 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *local_10 = 0;

    puVar3 = local_10;

  }

  local_4._0_1_ = 1;

  param_1[0x143] = puVar3;

  FUN_00989e00(&local_10,"i_g_2d_overlay_broken.dds");

  iVar2 = FUN_0096f3e0(&local_10,0);

  if (iVar2 < 0) {

    pvVar1 = (void *)param_1[0x143];

    if (pvVar1 != (void *)0x0) {

      FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    param_1[0x143] = 0;

  }

  local_10 = operator_new(4);

  if (local_10 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar3 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *local_10 = 0;

    puVar3 = local_10;

  }

  local_4 = CONCAT31(local_4._1_3_,1);

  param_1[0x144] = puVar3;

  FUN_00989e00(&local_10,"i_g_2d_highlight.dds");

  iVar2 = FUN_0096f3e0(&local_10,0);

  if (iVar2 < 0) {

    pvVar1 = (void *)param_1[0x144];

    if (pvVar1 != (void *)0x0) {

      FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    param_1[0x144] = 0;

  }

  ExceptionList = local_c;

  return param_1;

}
