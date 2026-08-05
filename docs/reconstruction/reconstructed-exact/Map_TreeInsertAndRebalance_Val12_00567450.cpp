// =============================================================================
// Map_TreeInsertAndRebalance_Val12  (FUN_00567450) — clone instance
// -----------------------------------------------------------------------------
// Stable ID: aa_00567450
// Address:   0x00567450  (autoassault.exe, image base 0x400000)
// Body:      0x00567450 – 0x0056763a exclusive (490 B / 0x1EA)
// System:    std map/set red-black tree (Val12 / node 0x1c)
// Generated: 2026-07-29 W27-R dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE
//   MSVC-style std::_Tree always-insert + red-black rebalance for Val12 nodes
//   (3-dword value; node size 0x1c; color @ +0x18; isnil @ +0x19).
//   Parent insert-or-find owns the key walk; this unit only buys a node,
//   links it, rebalances, and writes *outIt.
//
// ABI
//   __thiscall; ECX = MapShell*; four stack args; RET 0x10
//
// THROW
//   if size > 0x15555553 → length_error "map/set<T> too long"
//   via _CxxThrowException(..., &DAT_00acc388)
//
// TWIN (do not merge)
//   aa_0051c1c0 @ 0x0051c1c0 — same body size / max / buynode family;
//   different sole caller (category-cooldown). Clean plate there:
//   Map_TreeInsertAndRebalance_Val12.cpp
//
// SOLE LIVE CALLER (this VA)
//   FUN_00567860 — int-key lower_bound then insert (xref 0x005678aa)
// =============================================================================

#include <cstdint>

struct MapNode_Val12 {
  MapNode_Val12 *left;    // +0x00
  MapNode_Val12 *parent;  // +0x04
  MapNode_Val12 *right;   // +0x08
  int32_t v0;             // +0x0C
  int32_t v1;             // +0x10
  int32_t v2;             // +0x14
  uint8_t color;          // +0x18  0=red, 1=black
  uint8_t isnil;          // +0x19
};

struct MapShell_Val12 {
  void *proxy;            // +0x00
  MapNode_Val12 *head;    // +0x04
  uint32_t size;          // +0x08
};

struct Val12 {
  int32_t v0;
  int32_t v1;
  int32_t v2;
};

extern "C" MapNode_Val12 *FUN_005ae220( // StdTree_Buynode_Val12
    MapNode_Val12 *left, MapNode_Val12 *parent, MapNode_Val12 *right,
    const Val12 *value, uint8_t color); // new(0x1c); ret 0x14
extern "C" void FUN_00573170(MapNode_Val12 *node); // StdTree_Lrotate_Val12
extern "C" void FUN_00418c10(MapNode_Val12 *node); // StdTree_Rrotate_Val12
extern "C" void _CxxThrowException(void *, void *);

void __thiscall Map_TreeInsertAndRebalance_Val12(
    MapShell_Val12 *map,     // ECX
    MapNode_Val12 **outIt,   // *outIt = new node
    char addLeft,            // 1 = left of where; 0 = right
    MapNode_Val12 *where,    // parent, or head if empty
    const Val12 *value)      // 3 dwords → node+0x0C
{
  // SEH frame omitted (LAB_009a4c12).

  if (map->size > 0x15555553u) {
    // "map/set<T> too long" → _CxxThrowException(..., &DAT_00acc388)
    _CxxThrowException(nullptr, nullptr);
  }

  MapNode_Val12 *n =
      FUN_005ae220(map->head, where, map->head, value, /*color*/ 0);
  map->size += 1;

  if (where == map->head) {
    map->head->parent = n;
    map->head->left = n;
    map->head->right = n;
  } else if (addLeft == 0) {
    where->right = n;
    if (where == map->head->right)
      map->head->right = n;
  } else {
    where->left = n;
    if (where == map->head->left)
      map->head->left = n;
  }

  // Red-black fixup while parent is red (color @ +0x18 == 0).
  MapNode_Val12 *x = n;
  for (;;) {
    if (x->parent->color != 0) {
      map->head->parent->color = 1;
      *outIt = n;
      return;
    }

    MapNode_Val12 *parent = x->parent;
    MapNode_Val12 *grand = parent->parent;
    MapNode_Val12 *uncle = grand->left;

    if (parent == uncle) {
      // Parent is left child of grand → uncle is grand->right
      uncle = grand->right;
      if (uncle->color == 0) {
        parent->color = 1;
        uncle->color = 1;
        grand->color = 0;
        x = grand;
      } else {
        if (x == parent->right) {
          FUN_00573170(parent); // Lrotate
          x = parent;
          parent = x->parent;
        }
        parent->color = 1;
        grand->color = 0;
        FUN_00418c10(grand); // Rrotate
      }
    } else {
      // Parent is right child of grand → uncle is grand->left
      if (uncle->color == 0) {
        parent->color = 1;
        uncle->color = 1;
        grand->color = 0;
        x = grand;
      } else {
        if (x == parent->left) {
          FUN_00418c10(parent); // Rrotate
          x = parent;
          parent = x->parent;
        }
        parent->color = 1;
        grand->color = 0;
        // One L-rotate path is inlined in retail (see raw); other sites call
        // FUN_00573170. Mirror raw for exact rotate choice at this site.
        FUN_00573170(grand);
      }
    }
  }
}
