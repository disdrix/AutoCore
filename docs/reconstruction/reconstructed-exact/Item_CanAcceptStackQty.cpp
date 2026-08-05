// =============================================================================
// Item_CanAcceptStackQty
// -----------------------------------------------------------------------------
// Stable ID: aa_0040abf0
// Address:   0x0040abf0  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-07-29 dual A/B seal (live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Stack capacity predicate for merge-into-existing paths.
//   return (qty(this) + addQty) <= (maxStack(this) & 0xFFFF)
//
//   maxStack:
//     clonebase(+0xA8)->type(+0x38) == 4  → 999999  (compare uses low 16 → 16959)
//     else *(u16*)( *(clonebase+0x3C) + 0x4BA ); if 0 → 200
//
//   qty: virtual this->vtbl[+0x25C]()
//
// CALLERS (5 sites / 4 functions):
//   Inventory_SerializeAddItemPacket @ 0x004fae64
//   FUN_005714e0                     @ 0x00571558
//   FUN_00945540                     @ 0x0094564b
//   FUN_008012f0                     @ 0x00801406, 0x0080159c
//
// SEALED: formula, u16 mask, this=destination, addQty=stack ushort, bool AL.
// Sibling (inlined same max path): InventoryGrid_FindItemByCbid aa_005710c0.
// Not eligibility: Item_IsStackEligible aa_00513e70.
// =============================================================================

#include <cstdint>

// Destination stack item is `this`. addQty is quantity being merged in.
// Returns true if dest.qty + addQty fits under effective max (u16-truncated).
bool __thiscall Item_CanAcceptStackQty(int* this_item, uint16_t addQty)
{
  uint32_t maxStack;
  int qty;

  int* clonebase = reinterpret_cast<int*>(this_item[0x2a]); // +0xA8

  if (*(int*)(reinterpret_cast<char*>(clonebase) + 0x38) == 4) {
    maxStack = 999999; // 0x000F423F; compare uses low 16 bits only
  } else {
    int* defBlob = *reinterpret_cast<int**>(reinterpret_cast<char*>(clonebase) + 0x3C);
    uint16_t field = *reinterpret_cast<uint16_t*>(reinterpret_cast<char*>(defBlob) + 0x4BA);
    maxStack = field;
    if (field == 0) {
      maxStack = 200;
    }
  }

  // vtbl +0x25C — GetQuantity (inferred)
  qty = (*(int(__thiscall**)(int*))(*this_item + 0x25C))(this_item);

  // Retail: movzx edx, si  after max may be 999999 → effective 0x423F (16959)
  return (qty + static_cast<int>(addQty)) <= static_cast<int>(maxStack & 0xFFFF);
}
