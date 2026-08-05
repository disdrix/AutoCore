// =============================================================================
// Named_CalleeOf_Client_UI_InventoryDropToGrid_0085f1d0
// Canonical inferred: Client_UI_InventoryWindow_GetPageHeight
// -----------------------------------------------------------------------------
// Stable ID: aa_0085f1d0
// Callee of Client_UI_InventoryDropToGrid (wireY pageH) and FUN_0085f220 (×4)
// Address:   0x0085f1d0  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-07-23 scaffold; refined 2026-07-29 dual A/B
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: pageH = typeHost ? typeHost->pageHeight@+0x1c : 0
// Drop pack: wireY = (i8)(pageH * pageIdx@window+0x564 + cellY) → packet +0x19
// Same body as FUN_0085f1d0.cpp (named twin for parent-seed discovery).

#include <stdint.h>

uint32_t Named_CalleeOf_Client_UI_InventoryDropToGrid_0085f1d0(void)
{
  int in_EAX; // this: inventory UI window

  if (*(int *)(in_EAX + 0x56c) != 0) {
    return *(uint32_t *)(*(int *)(in_EAX + 0x56c) + 0x1c);
  }
  return 0;
}
