// =============================================================================
// Map_TreeInsertAndRebalance_Val12_EsiBuy_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0044a8c0
// Address:   0x0044a8c0  (autoassault.exe, image base 0x400000)
// System:    std red-black tree / map insert + rebalance (Val12)
// Generated: 2026-07-29 W27-P from live decompile + read_memory
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Always-insert a Val12 RB node under `where`, rebalance while parent is red,
//   paint root black, write *outIt. Throw if size > 0x15555553.
//   Parent FUN_0044a730 owns key walk / duplicate gate.
//
// ABI (bytes):
//   Map pointer in **EDI** (caller: mov edi, map).
//   Stack: (Node** outIt, char addLeft, Node* where, const Val12* value)
//   Epilogue: add esp, 0x50; ret 0x10
//   Body: 0x0044a8c0–0x0044aa46 exclusive (390 B)
//
// BUYNODE:
//   FUN_0046c6c0(left, parent, right, color) with **value in ESI** (3 dwords).
//   operator_new(0x1c); isnil@+0x19=0; color@+0x18.
//   Distinct from StdTree_Buynode_Val12 @ 0x005ae220 used by 0x0051c1c0.
//
// ROTATES:
//   FUN_00573170 StdTree_Lrotate_Val12; FUN_00418c10 StdTree_Rrotate_Val12
//   (both thiscall ECX=map; sealed W26-Q).
//

#include <cstdint>
#include <stdexcept>
#include <string>

struct MapNode_Val12 {
  MapNode_Val12* left;    // +0x00
  MapNode_Val12* parent;  // +0x04
  MapNode_Val12* right;   // +0x08
  uint32_t value[3];      // +0x0c  (12-byte payload)
  uint8_t color;          // +0x18  0=red, 1=black
  uint8_t isnil;          // +0x19
};

struct MapShell_Val12 {
  void* pad0;             // +0x00 (allocator / proxy; not read here)
  MapNode_Val12* head;    // +0x04 sentinel head
  uint32_t size;          // +0x08
};

// External
extern "C" MapNode_Val12* __cdecl FUN_0046c6c0(
    MapNode_Val12* left,
    MapNode_Val12* parent,
    MapNode_Val12* right,
    uint8_t color); // value via ESI
extern "C" void __thiscall FUN_00573170(void* map, MapNode_Val12* x); // Lrotate
extern "C" void __thiscall FUN_00418c10(void* map, MapNode_Val12* x); // Rrotate

// Retail uses EDI this + SEH; clean presents portable signature for reading.
extern "C" void Map_TreeInsertAndRebalance_Val12_EsiBuy_Inferred(
    MapShell_Val12* map,          // EDI in retail
    MapNode_Val12** outIt,
    char addLeft,
    MapNode_Val12* where,
    const uint32_t value[3])      // loaded to ESI for buy
{
  if (map->size > 0x15555553u) {
    throw std::length_error("map/set<T> too long");
  }

  // Retail: mov esi, value*; call FUN_0046c6c0(head, where, head, 0)
  MapNode_Val12* n = FUN_0046c6c0(map->head, where, map->head, /*color*/ 0);
  // FUN_0046c6c0 copies value[0..2] from ESI
  (void)value;
  map->size = map->size + 1;

  MapNode_Val12* head = map->head;
  if (where == head) {
    head->parent = n; // root
    head->left = n;   // leftmost
    head->right = n;  // rightmost (may update below)
  } else if (addLeft != 0) {
    where->left = n;
    if (where == head->left) {
      head->left = n; // new leftmost
    }
  } else {
    where->right = n;
    if (where == head->right) {
      head->right = n; // new rightmost
    }
  }

  // RB rebalance (decomp loop; rotates thiscall ECX=map)
  MapNode_Val12* cur = n;
  while (cur->parent->color == 0) { // parent red
    MapNode_Val12* parent = cur->parent;
    MapNode_Val12* grand = parent->parent;
    if (parent == grand->left) {
      MapNode_Val12* uncle = grand->right;
      if (uncle->color == 0) {
        parent->color = 1;
        uncle->color = 1;
        grand->color = 0;
        cur = grand;
      } else {
        if (cur == parent->right) {
          FUN_00573170(map, parent); // left-rotate parent
          cur = parent;
          parent = cur->parent;
        }
        parent->color = 1;
        parent->parent->color = 0;
        FUN_00418c10(map, parent->parent); // right-rotate grand
      }
    } else {
      MapNode_Val12* uncle = grand->left;
      if (uncle->color == 0) {
        parent->color = 1;
        uncle->color = 1;
        grand->color = 0;
        cur = grand;
      } else {
        if (cur == parent->left) {
          FUN_00418c10(map, parent);
          cur = parent;
          parent = cur->parent;
        }
        parent->color = 1;
        parent->parent->color = 0;
        FUN_00573170(map, parent->parent);
      }
    }
  }
  map->head->parent->color = 1; // root black
  *outIt = n;
}

// Ghidra export alias (signature incomplete in decomp — value is 4th stack arg)
extern "C" void FUN_0044a8c0(
    MapNode_Val12** outIt,
    char addLeft,
    MapNode_Val12* where,
    const uint32_t value[3])
{
  // map must be in EDI in retail; portable path not available without map*
  (void)outIt;
  (void)addLeft;
  (void)where;
  (void)value;
}
