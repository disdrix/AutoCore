// =============================================================================
// StdTree_InsertAndRebalance_Isnil21_Node0x24_Inferred  (FUN_005a4950)
// -----------------------------------------------------------------------------
// Stable ID: aa_005a4950
// Address:   0x005a4950–0x005a4b3a inclusive (491 B / 0x1EB)
// System:    MSVC std::_Tree always-insert + red-black rebalance
//            (isnil@+0x21, color@+0x20, node 0x24)
// Dual A/B:  2026-08-05 R12-033 OWN-ONLY
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed ABI bytes.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Always-allocate insert under a parent hint + RB rebalance for the
//   isnil@+0x21 / node-0x24 family. Parent InsertOrFind (005a4b70) owns
//   lower-bound / uniqueness (u32 key @ node+0x0C); this unit never compares.
//
// ABI: __thiscall; ECX=map*; stack (out**, addLeft, where*, value*); RET 0x10.
// Max size: throw "map/set<T> too long" if size >= 0x0CCCCCCB.
// Buynode: FUN_005a4870 — operator_new(0x24); color red; isnil0; u32 + vector.
// Rotates: StdTree_Lrotate_Isnil21_Inferred (0050e9f0),
//          StdTree_Rrotate_Isnil21_Inferred (005a27f0); one L path inlined.
//
// Peer: StdTree_InsertAndRebalance_Isnil21_Inferred (0x00407200, node 0x28 Val16).
// Dual: reviews/A|B_aa_005a4950_StdTree_InsertAndRebalance_Isnil21_Node0x24_Inferred.md
// =============================================================================

#include <cstdint>

struct NodeIsnil21_0x24 {
  NodeIsnil21_0x24* left;    // +0x00
  NodeIsnil21_0x24* parent;  // +0x04
  NodeIsnil21_0x24* right;   // +0x08
  std::uint32_t key;         // +0x0C  (u32; sealed by caller 005a4b70 compare)
  // +0x10 .. +0x1C  vector-like payload (copy via FUN_005a42d0 in buynode)
  std::uint8_t color;        // +0x20  (0=red, 1=black)
  std::uint8_t isnil;        // +0x21
  // pad to 0x24
};

struct MapShellIsnil21_0x24 {
  void* proxy;                  // +0x00
  NodeIsnil21_0x24* head;       // +0x04 sentinel (isnil=1); parent=root, left=Lmost, right=Rmost
  std::uint32_t size;           // +0x08
};

// Residual (not dualled this OWN): buynode for node 0x24 / isnil21
extern "C" NodeIsnil21_0x24* FUN_005a4870(
    NodeIsnil21_0x24* left,
    NodeIsnil21_0x24* parent,
    NodeIsnil21_0x24* right,
    const void* value,
    std::uint8_t color);

// Dualed R10-030 / R11-007
extern "C" void __thiscall StdTree_Lrotate_Isnil21_Inferred(
    MapShellIsnil21_0x24* map, NodeIsnil21_0x24* x);
extern "C" void __thiscall StdTree_Rrotate_Isnil21_Inferred(
    MapShellIsnil21_0x24* map, NodeIsnil21_0x24* x);

// Throw path: basic_string("map/set<T> too long") + length_error +
// _CxxThrowException(DAT_00acc388). Non-returning.

extern "C" void __thiscall StdTree_InsertAndRebalance_Isnil21_Node0x24_Inferred(
    MapShellIsnil21_0x24* map,
    NodeIsnil21_0x24** out,
    char addLeft,
    NodeIsnil21_0x24* where,
    const void* value)
{
  if (map->size >= 0x0CCCCCCBu) {
    // non-returning length_error — plate sealed
    return;
  }

  NodeIsnil21_0x24* head = map->head;
  // buynode: left=head, parent=where, right=head, color=red(0)
  NodeIsnil21_0x24* n = FUN_005a4870(head, where, head, value, /*red*/ 0);
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
  NodeIsnil21_0x24* x = n;
  while (x->parent->color == 0) {
    NodeIsnil21_0x24* p = x->parent;
    NodeIsnil21_0x24* gp = p->parent;
    if (p == gp->left) {
      NodeIsnil21_0x24* uncle = gp->right;
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
      NodeIsnil21_0x24* uncle = gp->left;
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
        // Final Lrotate inlined in retail body (isnil@+0x21 on y->left):
        // y = gp->right; gp->right = y->left; reparent; root/left/right reattach;
        // y->left = gp; gp->parent = y.
        NodeIsnil21_0x24* g = x->parent->parent;
        NodeIsnil21_0x24* y = g->right;
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

  head->parent->color = 1; // root black
  *out = n;
}

// Ghidra placeholder twin: FUN_005a4950.cpp
