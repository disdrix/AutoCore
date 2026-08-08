// =============================================================================
// StdTree_InsertAndRebalance_Isnil29_Inferred  (FUN_00406c40)
// -----------------------------------------------------------------------------
// Stable ID: aa_00406c40
// Address:   0x00406c40–0x00406dd5 exclusive (405 B)
// System:    MSVC std::_Tree always-insert + red-black rebalance (isnil@+0x29)
// Generated: 2026-08-04 WQ9E-G dual seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler control flow + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Always-allocate insert under a parent hint + RB rebalance for the large-node
//   family (node 0x30, color@+0x28, isnil@+0x29, value 0x18 @+0x10).
//   Parent (FUN_00406040) owns lower-bound / uniqueness; this unit never compares keys.
//
// ABI: __thiscall; ECX=map*; stack (out**, addLeft, where*, value*); RET 0x10.
// Max size: throw "map/set<T> too long" if size > 0x0AAAAAA8.
// Rotates: StdTree_Lrotate_Isnil29 (004192a0), StdTree_Rrotate_Isnil29_Inferred (004192f0).
// Buynode: FUN_00407e30 → operator_new(0x30) + FUN_004098d0.
//
// Dual: reviews/A|B_aa_00406c40_StdTree_InsertAndRebalance_Isnil29_Inferred.md

#include <cstdint>

struct NodeIsnil29 {
  NodeIsnil29* left;     // +0x00
  NodeIsnil29* parent;   // +0x04
  NodeIsnil29* right;    // +0x08
  // +0x0C pad / unused in ctor copy path
  std::uint32_t val[6];  // +0x10 .. +0x24  (0x18-byte value; key often val[0])
  std::uint8_t color;    // +0x28  (0=red, 1=black)
  std::uint8_t isnil;    // +0x29
  // pad to 0x30
};

struct MapShellIsnil29 {
  void* proxy;             // +0x00
  NodeIsnil29* head;       // +0x04 sentinel (isnil=1); parent=root, left=Lmost, right=Rmost
  std::uint32_t size;      // +0x08
};

// UnOWN callees
extern "C" NodeIsnil29* FUN_00407e30(
    NodeIsnil29* left,
    NodeIsnil29* parent,
    NodeIsnil29* right,
    const void* value,
    std::uint8_t color);

extern "C" void __thiscall StdTree_Lrotate_Isnil29(MapShellIsnil29* map, NodeIsnil29* x);
extern "C" void __thiscall StdTree_Rrotate_Isnil29_Inferred(MapShellIsnil29* map, NodeIsnil29* x);
// Ghidra: FUN_004192a0 / FUN_004192f0

// Throw path: basic_string("map/set<T> too long") + FUN_00401a40 + _CxxThrowException(DAT_00acc388).

// __thiscall
extern "C" void __thiscall StdTree_InsertAndRebalance_Isnil29_Inferred(
    MapShellIsnil29* map,
    NodeIsnil29** out,
    char addLeft,
    NodeIsnil29* where,
    const void* value)
{
  if (map->size > 0x0AAAAAA8u) {
    // non-returning length_error — plate sealed
    return;
  }

  NodeIsnil29* head = map->head;
  // buynode: left=head, parent=where, right=head, color=red(0), copy value, isnil=0
  NodeIsnil29* n = FUN_00407e30(head, where, head, value, /*red*/ 0);
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
  NodeIsnil29* x = n;
  while (x->parent->color == 0) {
    NodeIsnil29* p = x->parent;
    NodeIsnil29* gp = p->parent;
    if (p == gp->left) {
      NodeIsnil29* uncle = gp->right;
      if (uncle->color == 0) {
        p->color = 1;
        uncle->color = 1;
        gp->color = 0;
        x = gp;
      } else {
        if (x == p->right) {
          StdTree_Lrotate_Isnil29(map, p);
          x = p;
          p = x->parent;
        }
        p->color = 1;
        p->parent->color = 0;
        StdTree_Rrotate_Isnil29_Inferred(map, p->parent);
      }
    } else {
      NodeIsnil29* uncle = gp->left;
      if (uncle->color == 0) {
        p->color = 1;
        uncle->color = 1;
        gp->color = 0;
        x = gp;
      } else {
        if (x == p->left) {
          StdTree_Rrotate_Isnil29_Inferred(map, p);
          x = p;
          p = x->parent;
        }
        p->color = 1;
        p->parent->color = 0;
        StdTree_Lrotate_Isnil29(map, p->parent);
      }
    }
  }

  head->parent->color = 1; // root black
  *out = n;
}

// Ghidra alias
extern "C" void __thiscall FUN_00406c40(
    MapShellIsnil29* map,
    NodeIsnil29** out,
    char addLeft,
    NodeIsnil29* where,
    const void* value)
{
  StdTree_InsertAndRebalance_Isnil29_Inferred(map, out, addLeft, where, value);
}
