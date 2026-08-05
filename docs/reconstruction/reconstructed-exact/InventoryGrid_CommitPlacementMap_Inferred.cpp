// =============================================================================
// InventoryGrid_CommitPlacementMap_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00571e10
// Address:   0x00571e10 – 0x00571fae (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-07-29 W22-C dual seal (from live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of sealed control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
// Walk the placement map at grid+0x60. For each staged item:
//   - optional InventoryGrid_RemoveItem from related grid (when related && flag)
//   - set item origin from node (vtbl+0x24c)
//   - bind owner from grid+0x24 (vtbl+0x158)
//   - if type != 4, restamp cell COID footprint into grid+0x28
// Then free all map nodes and reset head/count.
//
// Callers:
//   InventoryGrid_RePlaceItems_Inferred fail / success-with-flag: (related, 1)
//   InventoryGrid_SortAndRepack_Inferred fail: (0, 0)

#include <cstdint>

struct InventoryGrid;
struct ItemObject;
struct MapNode;

extern "C" ItemObject* InventoryGrid_RemoveItem(
    InventoryGrid* thisGrid, ItemObject* item, int removeQty, char forceFull);
extern "C" void FUN_005731c0(void* mapShell /*this+0x5c*/, void* nodeRight);
extern "C" void operator_delete(void* p);

// MSVC __thiscall; RET 8
extern "C" void InventoryGrid_CommitPlacementMap_Inferred(
    InventoryGrid* self,      // ECX
    InventoryGrid* related,   // stack0
    char doRemoveFromRelated) // stack1
{
  auto* base = reinterpret_cast<uint8_t*>(self);
  auto* head = *reinterpret_cast<MapNode**>(base + 0x60);
  auto* node = *reinterpret_cast<MapNode**>(head); // begin

  if (node != head) {
    do {
      auto* item = *reinterpret_cast<ItemObject**>(reinterpret_cast<uint8_t*>(node) + 0x10);
      auto* itemBytes = reinterpret_cast<uint8_t*>(item);
      auto** vtbl = *reinterpret_cast<void***>(item);

      if (item != nullptr && related != nullptr && doRemoveFromRelated != 0) {
        using QtyFn = int(__thiscall*)(ItemObject*, int);
        int qty = reinterpret_cast<QtyFn>(vtbl[0x25c / 4])(item, 1);
        InventoryGrid_RemoveItem(related, item, qty, 1);
      }

      {
        using SetOriginFn = void(__thiscall*)(ItemObject*, char, uint8_t);
        char ox = *reinterpret_cast<char*>(reinterpret_cast<uint8_t*>(node) + 0x14);
        uint8_t oy = *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(node) + 0x15);
        // item may be reloaded from node+0x10 after RemoveItem path
        item = *reinterpret_cast<ItemObject**>(reinterpret_cast<uint8_t*>(node) + 0x10);
        vtbl = *reinterpret_cast<void***>(item);
        reinterpret_cast<SetOriginFn>(vtbl[0x24c / 4])(item, ox, oy);
      }

      {
        using BindFn = void(__thiscall*)(ItemObject*, void*);
        void* owner = *reinterpret_cast<void**>(base + 0x24);
        item = *reinterpret_cast<ItemObject**>(reinterpret_cast<uint8_t*>(node) + 0x10);
        vtbl = *reinterpret_cast<void***>(item);
        reinterpret_cast<BindFn>(vtbl[0x158 / 4])(item, owner);
      }

      item = *reinterpret_cast<ItemObject**>(reinterpret_cast<uint8_t*>(node) + 0x10);
      auto* itemDwords = reinterpret_cast<int*>(item);
      // type at *(item+0xa8)+0x38; decompiler also uses piVar12[4]+0xa8
      int type = *reinterpret_cast<int*>(
          *reinterpret_cast<uint8_t**>(reinterpret_cast<uint8_t*>(item) + 0xa8) + 0x38);
      if (type != 4) {
        // footprint: clonebase +0x406 = sizeX (outer), +0x407 = sizeY (inner)
        // index = originY + (originX + dx) * pitch + dy   ≡ Place/Remove family
        auto* clone = *reinterpret_cast<uint8_t**>(
            reinterpret_cast<uint8_t*>(itemDwords[0x2a]) + 0x3c);
        uint8_t sizeX = clone[0x406];
        uint8_t sizeY = clone[0x407];
        int pitch = *reinterpret_cast<int*>(base + 0x0c);
        int* cells = *reinterpret_cast<int**>(base + 0x28);
        uint8_t originX = *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(node) + 0x14);
        uint8_t originY = *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(node) + 0x15);
        for (int dx = 0; dx < sizeX; ++dx) {
          for (int dy = 0; dy < sizeY; ++dy) {
            int index = originY + (originX + dx) * pitch + dy;
            cells[index * 2 + 0] = itemDwords[0x58];
            cells[index * 2 + 1] = itemDwords[0x59];
          }
        }
      }

      // map iterator next (isnil @ +0x19) — sealed structure from decompile
      auto* nb = reinterpret_cast<uint8_t*>(node);
      if (nb[0x19] == 0) {
        auto* right = *reinterpret_cast<MapNode**>(nb + 8);
        if (*reinterpret_cast<char*>(reinterpret_cast<uint8_t*>(right) + 0x19) == 0) {
          node = right;
          auto* left = *reinterpret_cast<MapNode**>(node);
          while (*reinterpret_cast<char*>(reinterpret_cast<uint8_t*>(left) + 0x19) == 0) {
            node = left;
            left = *reinterpret_cast<MapNode**>(node);
          }
        } else {
          auto* parent = *reinterpret_cast<MapNode**>(nb + 4);
          auto* cur = node;
          while (*reinterpret_cast<char*>(reinterpret_cast<uint8_t*>(parent) + 0x19) == 0 &&
                 cur == *reinterpret_cast<MapNode**>(reinterpret_cast<uint8_t*>(parent) + 8)) {
            cur = parent;
            parent = *reinterpret_cast<MapNode**>(reinterpret_cast<uint8_t*>(parent) + 4);
          }
          node = parent;
        }
      }
    } while (node != head);
  }

  // free tree under head->parent; shell = this+0x5c
  auto* shell = base + 0x5c;
  auto* cur = *reinterpret_cast<MapNode**>(reinterpret_cast<uint8_t*>(head) + 4);
  while (*reinterpret_cast<char*>(reinterpret_cast<uint8_t*>(cur) + 0x19) == 0) {
    FUN_005731c0(shell, *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(cur) + 8));
    auto* doomed = cur;
    cur = *reinterpret_cast<MapNode**>(cur);
    operator_delete(doomed);
  }

  *reinterpret_cast<MapNode**>(reinterpret_cast<uint8_t*>(head) + 4) = head;
  *reinterpret_cast<int*>(base + 0x64) = 0;
  *reinterpret_cast<MapNode**>(head) = head;
  *reinterpret_cast<MapNode**>(reinterpret_cast<uint8_t*>(head) + 8) = head;
}

