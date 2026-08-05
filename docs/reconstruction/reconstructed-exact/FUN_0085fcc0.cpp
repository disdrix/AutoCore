// =============================================================================
// Client_UI_InventorySheet_RemoveByCoid  (Ghidra: FUN_0085fcc0)
// -----------------------------------------------------------------------------
// Stable ID: aa_0085fcc0
// Address:   0x0085fcc0  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer (UI sheet)
// Generated: 2026-07-23 scaffold; dual-refined 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Dual: docs/reconstruction/reviews/A_aa_0085fcc0_Client_UI_InventorySheet_RemoveByCoid.md
//       docs/reconstruction/reviews/B_aa_0085fcc0_Client_UI_InventorySheet_RemoveByCoid.md
// =============================================================================

// PURPOSE
//   Remove one inventory-sheet UI entry by instance COID (lo, hi).
//   Hash-unlink widget from sheet+0x570 (FUN_00413a60, EDI=hash), optional selection
//   clear (FUN_007fbb70 + DAT_00d1a840), sheet vtbl +0xbc detach, sheet+0x500 count--.
//   Does NOT stamp grids, send C2S, or call InventoryGrid_RemoveItem.
//
// ABI (SEALED 2026-07-29):
//   ESI = InventorySheetHost*
//   stdcall coidLo, coidHi  (Stack[0x4], Stack[0x8]); ret 0x08
//   Prolog sets EDI = [esi+0x570] for FUN_00413a60.
//   Decompiler unaff_ESI[0x15c] == byte +0x570; [0x140] == byte +0x500.
// Twin add: FUN_008605b0 (hash insert, vtbl +0xa8, count++).
// Wrapper: FUN_0085fd20 (EAX=item* → push +0x164/+0x160).
//
// READABILITY (CF): if×2, return×1; callees FUN_00413a60, FUN_007fbb70, vtbl +0x3ac/+0xbc

/*
 * Behavioral notes:
 * - Dual-sealed 2026-07-29 for ESI sheet ABI, stdcall COID pair, hash/count offsets.
 * - Widget vtbl +0x3ac product name and whether +0xbc frees the widget remain open.
 * - Runtime / differential verification: OPEN.
 *
 * Readability pass:
 * - Control flow and call order preserved from authoritative raw + entry bytes.
 * - unaff_ESI retained as decompiler form; ports must supply ESI = sheet host.
 */

void FUN_0085fcc0(uint32_t /* width from decompiler */ param_1,
                  uint32_t /* width from decompiler */ param_2)
{
  int *piVar1;
  int *unaff_ESI; /* InventorySheetHost* — caller-owned (ESI) */
  int *local_4;   /* out widget* from hash remove */

  /* Gate: *(ESI + 0x570) != 0  (decompiler dword index 0x15c) */
  if (unaff_ESI[0x15c] != 0) {
    local_4 = (int *)0x0;
    /* EDI = unaff_ESI[0x15c] before call (hash table*) */
    FUN_00413a60(param_1, param_2, &local_4);
    piVar1 = local_4;
    if (local_4 != (int *)0x0) {
      /* widget thiscall vtbl +0x3ac → cookie in EAX, moved to EDX for next */
      (**(code **)(*local_4 + 0x3ac))();
      /* EAX = DAT_00d1a840, EDX = cookie */
      FUN_007fbb70();
      /* sheet thiscall vtbl +0xbc(widget) */
      (**(code **)(*unaff_ESI + 0xbc))(piVar1);
      /* *(ESI + 0x500)--  (decompiler dword index 0x140) */
      unaff_ESI[0x140] = unaff_ESI[0x140] + -1;
    }
  }
  return; /* ret 8 */
}
