// =============================================================================
// Client_UI_InventoryWindow_GetPageHeight  (Ghidra: FUN_0085f1d0)
// -----------------------------------------------------------------------------
// Stable ID: aa_0085f1d0
// Address:   0x0085f1d0  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-07-23 scaffold; refined 2026-07-29 dual A/B
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE: Leaf page-height getter for inventory UI window.
//   typeHost = *(window + 0x56c)
//   return typeHost ? *(typeHost + 0x1c) : 0
// Used as pageH in Drop wireY (pageH * pageIdx + cellY) and FUN_0085f220 Y scale.
// Sibling FUN_0085f1f0 loads host +0x18 (width-family).
//
// ABI: this in EAX; return in EAX; no stack args; no side effects.
// Dual: reviews/A_aa_0085f1d0_* / B_aa_0085f1d0_* (2026-07-29 accept-with-gaps).

/*
 * Behavioral notes:
 * - Bytes: 8B806C050000 85C0 7404 8B401C C3 33C0 C3
 * - +0x1c on type host is page height written by InventoryGrid allocate:
 *     pageH = (nTotal / pages) / width  (cargo → 13)
 * - Null type host → 0 (not garbage).
 * - Runtime / differential verification: OPEN.
 */

#include <stdint.h>

// Inventory UI window* in EAX (MSVC register this for this leaf).
uint32_t FUN_0085f1d0(void)
{
  int in_EAX; // compiler register: this

  if (*(int *)(in_EAX + 0x56c) != 0) {
    return *(uint32_t *)(*(int *)(in_EAX + 0x56c) + 0x1c);
  }
  return 0;
}
