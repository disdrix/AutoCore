// =============================================================================
// SkillElementTypeMap_TreeInsertAndRebalance  (FUN_0054de50)
// -----------------------------------------------------------------------------
// Stable ID: aa_0054de50
// Address:   0x0054de50  (autoassault.exe, image base 0x400000)
// Body:      0x0054de50 – 0x0054e03a
// System:    skills-abilities
// Generated: 2026-07-29 W20-B dual seal (raw 2026-07-23 re-verified live)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE
//   MSVC-style std::_Tree always-insert + red-black rebalance for the
//   skill-element type→factory map (node size 0x18). Parent insert-or-find
//   (SkillElementTypeMap_InsertOrFind @ 0x0054eb20) owns the key walk; this
//   unit only allocates, links, rebalances, and writes *outIt.
//
// ABI
//   __thiscall; ECX = MapShell*; four stack args; RET 0x10
//
// THROW
//   if size > 0x1ffffffd → "map/set<T> too long" (length_error-style)
// =============================================================================

#include <cstdint>

struct MapNode_IntPtr {
  MapNode_IntPtr *left;    // +0x00
  MapNode_IntPtr *parent;  // +0x04
  MapNode_IntPtr *right;   // +0x08
  int32_t key;             // +0x0C
  void *mapped;            // +0x10
  uint8_t color;           // +0x14  0=red, 1=black
  uint8_t isnil;           // +0x15
};

struct MapShell {
  void *proxy;             // +0x00 (unused here)
  MapNode_IntPtr *head;    // +0x04  end sentinel; leftmost/root/rightmost
  uint32_t size;           // +0x08
};

struct IntPtrPair {
  int32_t key;
  void *mapped;
};

// External callees (roles sealed; product names open)
extern "C" MapNode_IntPtr *FUN_006173a0(MapNode_IntPtr *left,
                                        MapNode_IntPtr *parent,
                                        MapNode_IntPtr *right,
                                        const IntPtrPair *value,
                                        uint8_t color); // new(0x18)
extern "C" void FUN_004e22d0(MapShell *map, MapNode_IntPtr *node); // rotate
extern "C" void FUN_006753b0(MapShell *map, MapNode_IntPtr *node); // rotate
extern "C" void _CxxThrowException(void *, void *);

// ---------------------------------------------------------------------------
// Clean reconstruction — control flow ≡ live decompile / raw
// ---------------------------------------------------------------------------

void __thiscall SkillElementTypeMap_TreeInsertAndRebalance(
    MapShell *map,           // ECX
    MapNode_IntPtr **outIt,  // *outIt = new node
    char addLeft,            // 1 = left of where; 0 = right
    MapNode_IntPtr *where,   // parent, or head if empty
    const IntPtrPair *value) // 2 dwords → node+0x0C
{
  // SEH frame omitted (LAB_009a4422); present in retail for throw path.

  if (map->size > 0x1ffffffdu) {
    // Construct std::length_error-style object with "map/set<T> too long"
    // @ 0x00a1530c and _CxxThrowException(..., &DAT_00acc388). No-return.
    _CxxThrowException(nullptr, nullptr);
  }

  // Node: new(0x18), color red (0), isnil 0; value copy 2 dwords.
  MapNode_IntPtr *n =
      FUN_006173a0(map->head, where, map->head, value, /*color*/ 0);
  map->size += 1;

  if (where == map->head) {
    // First element: root = leftmost = rightmost = n
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

  // Red-black fixup while parent is red (color @ +0x14 == 0).
  MapNode_IntPtr *x = n;
  for (;;) {
    if (x->parent->color != 0) {
      // Parent black (or finished): paint root black and return.
      map->head->parent->color = 1;
      *outIt = n;
      return;
    }

    MapNode_IntPtr *parent = x->parent;
    MapNode_IntPtr *grand = parent->parent;
    MapNode_IntPtr *uncle = grand->left;

    if (parent == uncle) {
      // Parent is left child of grand → uncle is grand->right
      uncle = grand->right;
      if (uncle->color == 0) {
        // Recolor case
        parent->color = 1;
        uncle->color = 1;
        grand->color = 0;
        x = grand;
      } else {
        if (x == parent->right) {
          FUN_004e22d0(map, parent); // rotate at parent
          x = parent;
          parent = x->parent;
        }
        parent->color = 1;
        parent->parent->color = 0;
        FUN_006753b0(map, parent->parent); // rotate at grand
      }
    } else {
      // Parent is right child of grand → uncle is grand->left (already)
      if (uncle->color == 0) {
        parent->color = 1;
        uncle->color = 1;
        grand->color = 0;
        x = grand;
      } else {
        if (x == parent->left) {
          FUN_006753b0(map, parent);
          x = parent;
          parent = x->parent;
        }
        parent->color = 1;
        parent->parent->color = 0;
        // Inlined left-rotate of grandparent (isnil guard @ +0x15)
        MapNode_IntPtr *g = parent->parent;
        MapNode_IntPtr *r = g->right;
        g->right = r->left;
        if (r->left->isnil == 0)
          r->left->parent = g;
        r->parent = g->parent;
        if (g == map->head->parent)
          map->head->parent = r;
        else {
          MapNode_IntPtr *gp = g->parent;
          if (g == gp->left)
            gp->left = r;
          else
            gp->right = r;
        }
        r->left = g;
        g->parent = r;
      }
    }
  }
}

// Alias for Ghidra symbol compatibility
void __thiscall FUN_0054de50(MapShell *map, MapNode_IntPtr **outIt, char addLeft,
                             MapNode_IntPtr *where, const IntPtrPair *value) {
  SkillElementTypeMap_TreeInsertAndRebalance(map, outIt, addLeft, where, value);
}
