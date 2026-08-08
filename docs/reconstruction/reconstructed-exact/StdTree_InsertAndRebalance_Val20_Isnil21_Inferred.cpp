// =============================================================================
// StdTree_InsertAndRebalance_Val20_Isnil21_Inferred  (FUN_005ae2f0)
// -----------------------------------------------------------------------------
// Stable ID: aa_005ae2f0
// Address:   0x005ae2f0–0x005ae4da inclusive (491 B / 0x1EB)
// System:    skills-abilities / MSVC std::_Tree always-insert + RB rebalance
// Dual A/B:  2026-08-05 R12-034 OWN-ONLY
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed ABI bytes.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Always-allocate insert under a parent hint + red-black rebalance for the
//   Val20 / isnil@+0x21 node family (node 0x24, color@+0x20, isnil@+0x21,
//   value 5 dwords @+0x0C). Parent insert-or-find FUN_005aec50 owns key walk /
//   uniqueness; this unit never compares keys.
//
// ABI: __thiscall; ECX=map*; stack (out**, addLeft, where*, value*); RET 0x10.
// Max size: throw "map/set<T> too long" if size >= 0xCCCCCCB
//           (MSVC max_size()-1 for sizeof(value)==0x14).
// Buynode: FUN_005ae1c0 (operator_new 0x24; color red; isnil 0).
// Rotates: FUN_0050e9f0 (L), FUN_005a27f0 (R) — shared isnil21 leaves
//          (also used by Val16 InsertAndRebalance 00407200). One L path inlined.
//
// Peers (do not merge):
//   00407200 StdTree_InsertAndRebalance_Isnil21_Inferred (Val16 / node 0x28)
//   005ae4e0 StdTree_InsertAndRebalance_Val12 (node 0x1c; different rotates)
// Dual: reviews/A|B_aa_005ae2f0_StdTree_InsertAndRebalance_Val20_Isnil21_Inferred.md
// =============================================================================

#include <cstdint>

struct NodeVal20Isnil21 {
  NodeVal20Isnil21* left;    // +0x00
  NodeVal20Isnil21* parent;  // +0x04
  NodeVal20Isnil21* right;   // +0x08
  std::uint32_t val[5];      // +0x0C .. +0x1C  (Val20)
  std::uint8_t color;        // +0x20  (0=red, 1=black)
  std::uint8_t isnil;        // +0x21
  // node size 0x24
};

struct MapShellVal20Isnil21 {
  void* proxy;                  // +0x00
  NodeVal20Isnil21* head;       // +0x04 sentinel (isnil=1); parent=root, left=Lmost, right=Rmost
  std::uint32_t size;           // +0x08
};

struct Val20 {
  std::uint32_t v[5];
};

// Residual / dualed elsewhere — not owned by R12-034
extern "C" NodeVal20Isnil21* FUN_005ae1c0( // buynode node 0x24 / Val20
    NodeVal20Isnil21* left,
    NodeVal20Isnil21* parent,
    NodeVal20Isnil21* right,
    const Val20* value,
    std::uint8_t color);

// Dualed R10-030 / R11-007 — shared isnil21 rotates (thiscall map + node)
extern "C" void __thiscall FUN_0050e9f0(MapShellVal20Isnil21* map, NodeVal20Isnil21* x); // Lrotate
extern "C" void __thiscall FUN_005a27f0(MapShellVal20Isnil21* map, NodeVal20Isnil21* x); // Rrotate

// Throw path: basic_string("map/set<T> too long") + exception + 
// _CxxThrowException(DAT_00acc388). SEH LAB_009a65a2.

extern "C" void __thiscall StdTree_InsertAndRebalance_Val20_Isnil21_Inferred(
    MapShellVal20Isnil21* map,
    NodeVal20Isnil21** out,
    char addLeft,
    NodeVal20Isnil21* where,
    const Val20* value)
{
  // size >= 0xCCCCCCB → length_error (bytes: cmp [edi+8], 0x0CCCCCCB; jb ok)
  if (map->size >= 0xCCCCCCBu) {
    // non-returning — plate sealed
    return;
  }

  NodeVal20Isnil21* head = map->head;
  // buynode: left=head, parent=where, right=head, color=red(0), Val20 copy, isnil=0
  NodeVal20Isnil21* n = FUN_005ae1c0(head, where, head, value, /*red*/ 0);
  map->size += 1;

  if (where == head) {
    head->parent = n;   // root
    head->left = n;     // leftmost
    head->right = n;    // rightmost
  } else if (addLeft == 0) {
    where->right = n;
    if (where == head->right)
      head->right = n;
  } else {
    where->left = n;
    if (where == head->left)
      head->left = n;
  }

  // Red-black fixup while parent color is red (color @ +0x20 == 0).
  NodeVal20Isnil21* x = n;
  for (;;) {
    if (x->parent->color != 0) {
      // root black; *out = n; return
      head->parent->color = 1;
      *out = n;
      return;
    }

    NodeVal20Isnil21* parent = x->parent;
    NodeVal20Isnil21* grand = parent->parent;
    NodeVal20Isnil21* uncle = grand->left;

    if (parent == uncle) {
      // parent is left child of grandparent
      uncle = grand->right;
      if (uncle->color == 0) {
        // recolor parent+uncle black, grand red; ascend to grand
        parent->color = 1;
        uncle->color = 1;
        grand->color = 0;
        x = grand;
      } else {
        if (x == parent->right) {
          FUN_0050e9f0(map, parent); // Lrotate about parent
          x = parent;
          parent = x->parent;
        }
        parent->color = 1;
        parent->parent->color = 0;
        FUN_005a27f0(map, parent->parent); // Rrotate about grand
      }
    } else {
      // parent is right child of grandparent
      if (uncle->color == 0) {
        parent->color = 1;
        uncle->color = 1;
        grand->color = 0;
        x = grand;
      } else {
        if (x == parent->left) {
          FUN_005a27f0(map, parent); // Rrotate about parent
          x = parent;
          parent = x->parent;
        }
        parent->color = 1;
        parent->parent->color = 0;
        // Inline Lrotate about grand (isnil@+0x21) — same CF as FUN_0050e9f0
        NodeVal20Isnil21* g = parent->parent;
        NodeVal20Isnil21* y = g->right;
        g->right = y->left;
        if (y->left->isnil == 0)
          y->left->parent = g;
        y->parent = g->parent;
        if (g == head->parent)
          head->parent = y;
        else if (g == g->parent->left)
          g->parent->left = y;
        else
          g->parent->right = y;
        y->left = g;
        g->parent = y;
      }
    }
  }
}
