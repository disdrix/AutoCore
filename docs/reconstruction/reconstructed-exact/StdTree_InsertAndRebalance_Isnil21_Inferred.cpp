// =============================================================================
// StdTree_InsertAndRebalance_Isnil21_Inferred  (FUN_00407200)
// -----------------------------------------------------------------------------
// Stable ID: aa_00407200
// Address:   0x00407200–0x00407395 inclusive (406 B / 0x196)
// System:    MSVC std::_Tree always-insert + red-black rebalance (isnil@+0x21)
// Dual A/B:  2026-08-05 WQ9I-B
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed ABI bytes.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Always-allocate insert under a parent hint + RB rebalance for the small-node
//   isnil@+0x21 family (node 0x28, color@+0x20, isnil@+0x21, Val16 @+0x10).
//   Parents (InsertHint 00406560 / InsertOrFind 00407060) own lower-bound /
//   uniqueness; this unit never compares keys.
//
// ABI: __thiscall; ECX=map*; stack (out**, addLeft, where*, value*); RET 0x10.
// Max size: throw "map/set<T> too long" if size >= 0xFFFFFFE.
// Buynode: StdTree_Buynode_Val16_Isnil21_Inferred (00408990) color red.
// Rotates: FUN_0050e9f0 (L), FUN_005a27f0 (R) — color@+0x20 family (undualed).
//
// Peer: StdTree_InsertAndRebalance_Isnil29_Inferred (0x00406c40).
// Dual: reviews/A|B_aa_00407200_StdTree_InsertAndRebalance_Isnil21_Inferred.md
// =============================================================================

#include <cstdint>

struct NodeIsnil21 {
  NodeIsnil21* left;     // +0x00
  NodeIsnil21* parent;   // +0x04
  NodeIsnil21* right;    // +0x08
  // +0x0C
  std::uint32_t val[4];  // +0x10 .. +0x1C  (Val16)
  std::uint8_t color;    // +0x20  (0=red, 1=black)
  std::uint8_t isnil;    // +0x21
  // pad to 0x28
};

struct MapShellIsnil21 {
  void* proxy;             // +0x00
  NodeIsnil21* head;       // +0x04 sentinel (isnil=1); parent=root, left=Lmost, right=Rmost
  std::uint32_t size;      // +0x08
};

// Dualed WQ9H-J
extern "C" NodeIsnil21* StdTree_Buynode_Val16_Isnil21_Inferred(
    NodeIsnil21* left,
    NodeIsnil21* parent,
    NodeIsnil21* right,
    const void* value,
    std::uint8_t color);

// Undualed rotates for color@+0x20 / isnil@+0x21 family (thiscall map + node).
extern "C" void __thiscall FUN_0050e9f0(MapShellIsnil21* map, NodeIsnil21* x); // Lrotate
extern "C" void __thiscall FUN_005a27f0(MapShellIsnil21* map, NodeIsnil21* x); // Rrotate

// Throw path: basic_string("map/set<T> too long") + FUN_00401a40 +
// _CxxThrowException(DAT_00acc388).

extern "C" void __thiscall StdTree_InsertAndRebalance_Isnil21_Inferred(
    MapShellIsnil21* map,
    NodeIsnil21** out,
    char addLeft,
    NodeIsnil21* where,
    const void* value)
{
  if (map->size >= 0xFFFFFFEu) {
    // non-returning length_error — plate sealed
    return;
  }

  NodeIsnil21* head = map->head;
  // buynode: left=head, parent=where, right=head, color=red(0), Val16 copy, isnil=0
  NodeIsnil21* n = StdTree_Buynode_Val16_Isnil21_Inferred(
      head, where, head, value, /*red*/ 0);
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
  NodeIsnil21* x = n;
  while (x->parent->color == 0) {
    NodeIsnil21* p = x->parent;
    NodeIsnil21* gp = p->parent;
    if (p == gp->left) {
      NodeIsnil21* uncle = gp->right;
      if (uncle->color == 0) {
        p->color = 1;
        uncle->color = 1;
        gp->color = 0;
        x = gp;
      } else {
        if (x == p->right) {
          FUN_0050e9f0(map, p); // left rotate
          x = p;
          p = x->parent;
        }
        p->color = 1;
        p->parent->color = 0;
        FUN_005a27f0(map, p->parent); // right rotate
      }
    } else {
      NodeIsnil21* uncle = gp->left;
      if (uncle->color == 0) {
        p->color = 1;
        uncle->color = 1;
        gp->color = 0;
        x = gp;
      } else {
        if (x == p->left) {
          FUN_005a27f0(map, p); // right rotate
          x = p;
          p = x->parent;
        }
        p->color = 1;
        p->parent->color = 0;
        FUN_0050e9f0(map, p->parent); // left rotate
      }
    }
  }

  head->parent->color = 1; // root black
  *out = n;
}

// Ghidra placeholder twin: FUN_00407200.cpp
