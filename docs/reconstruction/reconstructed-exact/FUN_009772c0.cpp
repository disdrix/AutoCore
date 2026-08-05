// =============================================================================
// FUN_009772c0
// -----------------------------------------------------------------------------
// Stable ID: aa_009772c0
// Address:   0x009772c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009772c0 @ 0x009772c0
// Stable ID: aa_009772c0
// Embedded strings (evidence for future rename):
//   - "i_g_2d_credits.dds"
//   - "i_g_2d_credits_small.dds"
//   - "i_g_2d_resist_icons.dds"
//   - "i_g_2d_resist_icons_small.dds"
//   - "i_d_map_2d_icon_all.dds"
//   - "i_g_2d_wnd_inventory_item_sockets.dds"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~144 non-empty decompiler lines.
//  - Control keywords: if×18, return×7.
//  - Notable callees: FUN_0096efd0×6, FUN_0096f3e0×6, FUN_00989e00×6, FUN_009772c0.
//  - Strings: "i_g_2d_credits.dds"; "i_g_2d_credits_small.dds"; "i_g_2d_resist_icons.dds"; "i_g_2d_resist_icons_small.dds".
//  - Return sites: 7.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void FUN_009772c0(void)



{

  void *pvVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *unaff_ESI;

  uint32_t /* width from decompiler */ *local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b14d5;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *unaff_ESI = &PTR_FUN_00a84d64;

  local_10 = operator_new(4);

  if (local_10 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar3 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *local_10 = 0;

    puVar3 = local_10;

  }

  local_4 = 0xffffffff;

  unaff_ESI[1] = puVar3;

  FUN_00989e00(&local_10,"i_g_2d_credits.dds");

  iVar2 = FUN_0096f3e0(&local_10,0);

  if (iVar2 < 0) {

    pvVar1 = (void *)unaff_ESI[1];

    if (pvVar1 != (void *)0x0) {

      FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    unaff_ESI[1] = 0;

  }

  local_10 = operator_new(4);

  if (local_10 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar3 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *local_10 = 0;

    puVar3 = local_10;

  }

  local_4 = 0xffffffff;

  unaff_ESI[2] = puVar3;

  FUN_00989e00(&local_10,"i_g_2d_credits_small.dds");

  iVar2 = FUN_0096f3e0(&local_10,0);

  if (iVar2 < 0) {

    pvVar1 = (void *)unaff_ESI[2];

    if (pvVar1 != (void *)0x0) {

      FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    unaff_ESI[2] = 0;

  }

  local_10 = operator_new(4);

  if (local_10 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar3 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *local_10 = 0;

    puVar3 = local_10;

  }

  local_4 = 0xffffffff;

  unaff_ESI[3] = puVar3;

  FUN_00989e00(&local_10,"i_g_2d_resist_icons.dds");

  iVar2 = FUN_0096f3e0(&local_10,0);

  if (iVar2 < 0) {

    pvVar1 = (void *)unaff_ESI[3];

    if (pvVar1 != (void *)0x0) {

      FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    unaff_ESI[3] = 0;

  }

  local_10 = operator_new(4);

  if (local_10 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar3 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *local_10 = 0;

    puVar3 = local_10;

  }

  local_4 = 0xffffffff;

  unaff_ESI[4] = puVar3;

  FUN_00989e00(&local_10,"i_g_2d_resist_icons_small.dds");

  iVar2 = FUN_0096f3e0(&local_10,0);

  if (iVar2 < 0) {

    pvVar1 = (void *)unaff_ESI[4];

    if (pvVar1 != (void *)0x0) {

      FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    unaff_ESI[4] = 0;

  }

  local_10 = operator_new(4);

  if (local_10 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar3 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *local_10 = 0;

    puVar3 = local_10;

  }

  local_4 = 0xffffffff;

  unaff_ESI[5] = puVar3;

  FUN_00989e00(&local_10,"i_d_map_2d_icon_all.dds");

  iVar2 = FUN_0096f3e0(&local_10,0);

  if (iVar2 < 0) {

    pvVar1 = (void *)unaff_ESI[5];

    if (pvVar1 != (void *)0x0) {

      FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    unaff_ESI[5] = 0;

  }

  local_10 = operator_new(4);

  if (local_10 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar3 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *local_10 = 0;

    puVar3 = local_10;

  }

  local_4 = 0xffffffff;

  unaff_ESI[6] = puVar3;

  FUN_00989e00(&local_10,"i_g_2d_wnd_inventory_item_sockets.dds");

  iVar2 = FUN_0096f3e0(&local_10,0);

  if (iVar2 < 0) {

    pvVar1 = (void *)unaff_ESI[6];

    if (pvVar1 != (void *)0x0) {

      FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    unaff_ESI[6] = 0;

  }

  ExceptionList = local_c;

  return;

}
