// =============================================================================
// StdTree_InsertAndRebalance_Node24_Isnil21_Inferred  (FUN_00511950)
// -----------------------------------------------------------------------------
// Stable ID: aa_00511950
// Address:   0x00511950–0x00511b3a inclusive (491 B / 0x1EB)
// System:    MSVC std::_Tree always-insert + red-black rebalance
//            (isnil@+0x21 / color@+0x20 / node 0x24)
// Dual A/B:  2026-08-05 R12-014 OWN-ONLY
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed ABI bytes.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Always-allocate insert under a parent hint + RB rebalance for the Node24
//   isnil@+0x21 family (node 0x24, color@+0x20, isnil@+0x21, int key @+0x0C,
//   vector payload). Parent InsertOrFind FUN_00511b40 owns lower-bound /
//   uniqueness; this unit never compares keys.
//
// ABI: __thiscall; ECX=map*; stack (out**, addLeft, where*, value*); RET 0x10.
// Max size: throw "map/set<T> too long" if size >= 0xCCCCCCB.
// Buynode: FUN_005118b0 (residual) — operator_new(0x24), color red.
// Rotates: StdTree_Lrotate_Isnil21_Inferred (0050e9f0, dualed);
//          StdTree_Rrotate_Isnil21_Inferred (005a27f0, dualed R11-007);
//          one Lrotate path inlined in body.
//
// Peer (different instantiation): StdTree_InsertAndRebalance_Isnil21_Inferred
//   (0x00407200) — Val16 / node 0x28 / max 0xFFFFFFE / buynode 00408990.
// Dual: reviews/A|B_aa_00511950_StdTree_InsertAndRebalance_Node24_Isnil21_Inferred.md
// =============================================================================

#include <cstdint>

struct Node24Isnil21 {
  Node24Isnil21* left;     // +0x00
  Node24Isnil21* parent;   // +0x04
  Node24Isnil21* right;    // +0x08
  std::int32_t key;        // +0x0C  (int key; parent InsertOrFind compares here)
  // +0x10 .. +0x1B  vector-like payload (3 pointers; element size 0x10)
  // +0x1C .. +0x1F  pad / residual
  std::uint8_t color;      // +0x20  (0=red, 1=black)
  std::uint8_t isnil;      // +0x21
  // total node size 0x24
};

struct MapShellNode24Isnil21 {
  void* proxy;                // +0x00
  Node24Isnil21* head;        // +0x04 sentinel (isnil=1); parent=root, left=Lmost, right=Rmost
  std::uint32_t size;         // +0x08
};

// Residual nested buynode (not OWN dual R12-014)
extern "C" Node24Isnil21* FUN_005118b0(
    Node24Isnil21* left,
    Node24Isnil21* parent,
    Node24Isnil21* right,
    const void* value,
    std::uint8_t color);

// Dualed rotates for color@+0x20 / isnil@+0x21 family
extern "C" void __thiscall StdTree_Lrotate_Isnil21_Inferred(
    MapShellNode24Isnil21* map, Node24Isnil21* x); // 0x0050e9f0
extern "C" void __thiscall StdTree_Rrotate_Isnil21_Inferred(
    MapShellNode24Isnil21* map, Node24Isnil21* x); // 0x005a27f0

// Throw path: basic_string("map/set<T> too long") + exception +
// _CxxThrowException(DAT_00acc388). Non-returning.

extern "C" void __thiscall StdTree_InsertAndRebalance_Node24_Isnil21_Inferred(
    MapShellNode24Isnil21* map,
    Node24Isnil21** out,
    char addLeft,
    Node24Isnil21* where,
    const void* value)
{
  if (map->size >= 0xCCCCCCBu) {
    // non-returning length_error — plate sealed
    return;
  }

  Node24Isnil21* head = map->head;
  // buynode: left=head, parent=where, right=head, color=red(0), isnil=0, copy value
  Node24Isnil21* n = FUN_005118b0(head, where, head, value, /*red*/ 0);
  map->size += 1;

  if (where == head) {
    head->parent = n;
    head->left = n;
    head->right = n;
  } else if (addLeft == 0) {
    where->right = n;
    if (where == head->right)
      head->right = n;
  } else {
    where->left = n;
    if (where == head->left)
      head->left = n;
  }

  // RB fixup while parent is red
  Node24Isnil21* x = n;
  while (x->parent->color == 0) {
    Node24Isnil21* p = x->parent;
    Node24Isnil21* gp = p->parent;
    if (p == gp->left) {
      Node24Isnil21* uncle = gp->right;
      if (uncle->color == 0) {
        p->color = 1;
        uncle->color = 1;
        gp->color = 0;
        x = gp;
      } else {
        if (x == p->right) {
          StdTree_Lrotate_Isnil21_Inferred(map, p);
          x = p;
        }
        x->parent->color = 1;
        x->parent->parent->color = 0;
        StdTree_Rrotate_Isnil21_Inferred(map, x->parent->parent);
      }
    } else {
      Node24Isnil21* uncle = gp->left;
      if (uncle->color == 0) {
        p->color = 1;
        uncle->color = 1;
        gp->color = 0;
        x = gp;
      } else {
        if (x == p->left) {
          StdTree_Rrotate_Isnil21_Inferred(map, p);
          x = p;
        }
        x->parent->color = 1;
        x->parent->parent->color = 0;
        // Lrotate about grandparent — inlined in retail body (isnil@+0x21)
        // Equivalent to StdTree_Lrotate_Isnil21_Inferred(map, x->parent->parent):
        Node24Isnil21* g = x->parent->parent;
        Node24Isnil21* y = g->right;
        g->right = y->left;
        if (y->left->isnil == 0)
          y->left->parent = g;
        y->parent = g->parent;
        if (g == map->head->parent)
          map->head->parent = y;
        else if (g == g->parent->left)
          g->parent->left = y;
        else
          g->parent->right = y;
        y->left = g;
        g->parent = y;
      }
    }
  }

  head->parent->color = 1; // root black
  *out = n;
}

// Ghidra placeholder twin: FUN_00511950.cpp
