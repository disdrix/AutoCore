// =============================================================================
// FUN_0085dc30
// -----------------------------------------------------------------------------
// Stable ID: aa_0085dc30
// Address:   0x0085dc30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0085dc30 @ 0x0085dc30
// Stable ID: aa_0085dc30
// Embedded strings (evidence for future rename):
//   - "i_g_2d_wnd_inventory_item_sockets.dds"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×5, return×3.
//  - Notable callees: FUN_0096efd0×2, FUN_00989e00×2, FUN_0085dc30, FUN_0096f3e0.
//  - Strings: "i_g_2d_wnd_inventory_item_sockets.dds".
//  - Return sites: 3.

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

void FUN_0085dc30(void)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *unaff_ESI;

  uint32_t /* width from decompiler */ *local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b15db;

  local_c = ExceptionList;

  pvVar1 = (void *)*unaff_ESI;

  if (pvVar1 != (void *)0x0) {

    ExceptionList = &local_c;

    FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  ExceptionList = &local_c;

  local_10 = operator_new(4);

  if (local_10 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar2 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *local_10 = 0;

    puVar2 = local_10;

  }

  local_4 = 0xffffffff;

  *unaff_ESI = puVar2;

  if (unaff_ESI[1] == 0) {

    FUN_00989e00(&local_10,"i_g_2d_wnd_inventory_item_sockets.dds");

  }

  else {

    FUN_00989e00(&local_10,unaff_ESI[1]);

  }

  iVar3 = FUN_0096f3e0(&local_10,0);

  if (iVar3 < 0) {

    pvVar1 = (void *)*unaff_ESI;

    if (pvVar1 != (void *)0x0) {

      FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    *unaff_ESI = 0;

  }

  ExceptionList = local_c;

  return;

}
