// =============================================================================
// StdTree_InsertAndRebalance_Val12  (FUN_005ae4e0)
// -----------------------------------------------------------------------------
// Stable ID: aa_005ae4e0
// Address:   0x005ae4e0  (autoassault.exe, image base 0x400000)
// Body:      0x005ae4e0 – 0x005ae6ca exclusive (490 B / 0x1EA)
// System:    std map/set red-black tree (Val12 / node 0x1c)
// Generated: 2026-07-29 W27-T dual seal (raw 2026-07-23 re-verified live)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE
//   MSVC-style std::_Tree always-insert + red-black rebalance for Val12 nodes
//   (3-dword mapped blob; node size 0x1c; color @ +0x18; isnil @ +0x19).
//   Parent insert-or-find owns the key walk; this unit only buys a node,
//   links it, rebalances, and writes *outIt.
//
// ABI
//   __thiscall; ECX = MapShell*; four stack args; RET 0x10
//
// THROW
//   if size > 0x15555553 -> "map/set<T> too long" via _CxxThrowException(..., &DAT_00acc388)
//
// SOLE LIVE CALLER (this image)
//   FUN_005aed20 (insert-or-find; int key at value dword0 / node+0x0c)
//
// PEER CLONE (do not merge)
//   Map_TreeInsertAndRebalance_Val12 @ 0x0051c1c0 (Skill_CategoryCooldownMap_Insert)
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
  void *proxy;            // +0x00 (unused here)
  MapNode_Val12 *head;    // +0x04  end sentinel; leftmost / root / rightmost
  uint32_t size;          // +0x08
};

struct Val12 {
  int32_t v0;
  int32_t v1;
  int32_t v2;
};

// External callees (roles sealed elsewhere)
extern "C" MapNode_Val12 *FUN_005ae220( // StdTree_Buynode_Val12
    MapNode_Val12 *left, MapNode_Val12 *parent, MapNode_Val12 *right,
    const Val12 *value, uint8_t color);
extern "C" void FUN_00573170(MapNode_Val12 *node); // StdTree_Lrotate_Val12
extern "C" void FUN_00418c10(MapNode_Val12 *node); // StdTree_Rrotate_Val12
extern "C" void _CxxThrowException(void *, void *);

void __thiscall StdTree_InsertAndRebalance_Val12(
    MapShell_Val12 *map,     // ECX
    MapNode_Val12 **outIt,   // *outIt = new node
    char addLeft,            // 1 = left of where; 0 = right
    MapNode_Val12 *where,    // parent, or head if empty
    const Val12 *value)      // 3 dwords -> node+0x0C
{
  // SEH frame omitted (LAB_009a65a2); present in retail for throw path.

  if (map->size > 0x15555553u) {
    // Construct length_error-style object with "map/set<T> too long"
    // and _CxxThrowException(..., &DAT_00acc388). No-return.
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
      // Parent is left child of grand -> uncle is grand->right
      uncle = grand->right;
      if (uncle->color == 0) {
        parent->color = 1;
        uncle->color = 1;
        grand->color = 0;
        x = grand;
      } else {
        if (x == parent->right) {
          FUN_00573170(parent); // left-rotate about parent
          x = parent;
          parent = x->parent;
        }
        parent->color = 1;
        parent->parent->color = 0;
        FUN_00418c10(parent->parent); // right-rotate about grand
      }
    } else {
      // Parent is right child of grand
      if (uncle->color == 0) {
        parent->color = 1;
        uncle->color = 1;
        grand->color = 0;
        x = grand;
      } else {
        if (x == parent->left) {
          FUN_00418c10(parent);
          x = parent;
          parent = x->parent;
        }
        parent->color = 1;
        parent->parent->color = 0;
        // left-rotate about grand (inlined in decompile at this VA)
        MapNode_Val12 *g = parent->parent;
        MapNode_Val12 *r = g->right;
        g->right = r->left;
        if (r->left->isnil == 0)
          r->left->parent = g;
        r->parent = g->parent;
        if (g == map->head->parent)
          map->head->parent = r;
        else if (g == g->parent->left)
          g->parent->left = r;
        else
          g->parent->right = r;
        r->left = g;
        g->parent = r;
      }
    }
  }
}
