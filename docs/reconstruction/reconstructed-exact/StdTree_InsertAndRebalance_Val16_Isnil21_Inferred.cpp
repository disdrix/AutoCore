// =============================================================================
// StdTree_InsertAndRebalance_Val16_Isnil21_Inferred  (FUN_004e37e0)
// -----------------------------------------------------------------------------
// Stable ID: aa_004e37e0
// Address:   0x004e37e0–0x004e39ca inclusive (491 B / 0x1EB)
// System:    skills-abilities / MSVC std::_Tree always-insert + RB rebalance
// Dual A/B:  2026-08-05 R12-012 (parent dual 0x005a27f0 Rrotate)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed ABI bytes.
// Bit-for-bit / runtime / diff: OPEN  (never Runtime Confirmed)
// =============================================================================
// PURPOSE
//   Always-allocate map/set node insert under a parent-supplied hint, then
//   red-black rebalance for the isnil@+0x21 / Val16 / node-0x28 family.
//   Parent FUN_004e48b0 owns lower-bound / uniqueness; this unit never compares
//   keys. Peer clone: StdTree_InsertAndRebalance_Isnil21_Inferred @ 0x00407200
//   (buynode 00408990). This clone uses buynode FUN_004e2b80.
//
// ABI: __thiscall; ECX=map*; stack (out**, addLeft, where*, value*); RET 0x10.
// Max size: throw "map/set<T> too long" if size >= 0x0FFFFFFE.
// Buynode: FUN_004e2b80 (operator_new(0x28); color red; isnil 0).
// Rotates: FUN_0050e9f0 (L), FUN_005a27f0 (R) — StdTree_*_Isnil21 family.
//
// Dual: reviews/A|B_aa_004e37e0_StdTree_InsertAndRebalance_Val16_Isnil21_Inferred.md
// =============================================================================

#include <cstdint>

struct NodeVal16Isnil21 {
  NodeVal16Isnil21* left;     // +0x00
  NodeVal16Isnil21* parent;   // +0x04
  NodeVal16Isnil21* right;    // +0x08
  // +0x0C pad / unused by buynode
  std::uint32_t val[4];       // +0x10 .. +0x1C  (Val16)
  std::uint8_t color;         // +0x20  (0=red, 1=black)
  std::uint8_t isnil;         // +0x21
  // total size 0x28
};

struct MapShellVal16Isnil21 {
  void* proxy;                  // +0x00
  NodeVal16Isnil21* head;       // +0x04 sentinel; parent=root, left=Lmost, right=Rmost
  std::uint32_t size;           // +0x08
};

// Scaffold / residual buynode for this clone (not dualed this wave)
extern "C" NodeVal16Isnil21* FUN_004e2b80(
    NodeVal16Isnil21* left,
    NodeVal16Isnil21* parent,
    NodeVal16Isnil21* right,
    const void* value,
    std::uint8_t color);

// Dualed parent: StdTree_Rrotate_Isnil21_Inferred (0x005a27f0)
// Peer dual:     StdTree_Lrotate_Isnil21_Inferred (0x0050e9f0)
extern "C" void __thiscall FUN_0050e9f0(MapShellVal16Isnil21* map, NodeVal16Isnil21* x);
extern "C" void __thiscall FUN_005a27f0(MapShellVal16Isnil21* map, NodeVal16Isnil21* x);

// Throw path: basic_string("map/set<T> too long") + exception +
// _CxxThrowException(DAT_00acc388). Non-returning.

extern "C" void __thiscall StdTree_InsertAndRebalance_Val16_Isnil21_Inferred(
    MapShellVal16Isnil21* map,
    NodeVal16Isnil21** out,
    char addLeft,
    NodeVal16Isnil21* where,
    const void* value)
{
  // Live: cmp [map+8], 0x0FFFFFFE; jb ok; else throw
  if (map->size >= 0x0FFFFFFEu) {
    // non-returning length_error — plate sealed
    return;
  }

  NodeVal16Isnil21* head = map->head;
  // buynode: left=head, parent=where, right=head, color=red(0), Val16 copy, isnil=0
  NodeVal16Isnil21* n = FUN_004e2b80(head, where, head, value, /*red*/ 0);
  map->size += 1;

  if (where == head) {
    head->parent = n;
    head->left = n;
    head->right = n;
  } else if (addLeft == 0) {
    where->right = n;
    if (where == head->right) {
      head->right = n;
    }
  } else {
    where->left = n;
    if (where == head->left) {
      head->left = n;
    }
  }

  // RB rebalance while parent is red; root blackened before return.
  // Color tests at +0x20; isnil guards at +0x21 inside rotates / inlined Lrotate.
  NodeVal16Isnil21* x = n;
  while (x->parent->color == 0) {
    NodeVal16Isnil21* p = x->parent;
    NodeVal16Isnil21* g = p->parent;
    if (p == g->left) {
      NodeVal16Isnil21* uncle = g->right;
      if (uncle->color == 0) {
        p->color = 1;
        uncle->color = 1;
        g->color = 0;
        x = g;
      } else {
        if (x == p->right) {
          FUN_0050e9f0(map, p); // Lrotate
          x = p;
          p = x->parent;
        }
        p->color = 1;
        p->parent->color = 0;
        FUN_005a27f0(map, p->parent); // Rrotate
      }
    } else {
      NodeVal16Isnil21* uncle = g->left;
      if (uncle->color == 0) {
        p->color = 1;
        uncle->color = 1;
        g->color = 0;
        x = g;
      } else {
        if (x == p->left) {
          FUN_005a27f0(map, p); // Rrotate
          x = p;
          p = x->parent;
        }
        p->color = 1;
        p->parent->color = 0;
        // inlined Lrotate of grandparent (same shape as FUN_0050e9f0)
        NodeVal16Isnil21* gp = p->parent;
        NodeVal16Isnil21* y = gp->right;
        gp->right = y->left;
        if (y->left->isnil == 0) {
          y->left->parent = gp;
        }
        y->parent = gp->parent;
        if (gp == head->parent) {
          head->parent = y;
        } else if (gp == gp->parent->left) {
          gp->parent->left = y;
        } else {
          gp->parent->right = y;
        }
        y->left = gp;
        gp->parent = y;
      }
    }
  }

  head->parent->color = 1; // root black
  *out = n;
}
