// =============================================================================
// StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred  (FUN_0041ba30)
// -----------------------------------------------------------------------------
// Stable ID: aa_0041ba30
// Address:   0x0041ba30–0x0041bbc5 inclusive (406 B / 0x196)
// System:    MSVC std::_Tree always-insert + red-black rebalance
//            (isnil@+0x21, char key @+0x0C, node 0x24)
// Dual A/B:  2026-08-05 R12-011
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed ABI bytes.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Always-allocate insert under a parent hint + RB rebalance for the char-key
//   isnil@+0x21 family (node 0x24, color@+0x20, isnil@+0x21, key char @+0x0C).
//   Parent FUN_0041a570 owns lower-bound / uniqueness; this unit never compares
//   keys.
//
// ABI: __thiscall; ECX=map*; stack (out**, addLeft, where*, value*); RET 0x10.
// Max size: throw "map/set<T> too long" if size >= 0x0CCCCCCB.
// Buynode: FUN_0041d860 (node 0x24 / red / isnil0) — undualed.
// Rotates: FUN_0050e9f0 (L), FUN_005a27f0 (R) — isnil21 family (dualed).
//
// Peer (do not merge): StdTree_InsertAndRebalance_Isnil21_Inferred (0x00407200)
//   Val16 / node 0x28 / max 0xFFFFFFE / buynode 00408990.
// Dual: reviews/A|B_aa_0041ba30_StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred.md
// =============================================================================

#include <cstdint>

struct NodeCharKeyIsnil21 {
  NodeCharKeyIsnil21* left;    // +0x00
  NodeCharKeyIsnil21* parent;  // +0x04
  NodeCharKeyIsnil21* right;   // +0x08
  char key;                    // +0x0C  (char-key map; residual value follows)
  // ... value payload through +0x1F (via buynode FUN_0041c140 path)
  std::uint8_t color;          // +0x20  (0=red, 1=black)
  std::uint8_t isnil;          // +0x21
  // pad to 0x24
};

struct MapShellCharKeyIsnil21 {
  void* proxy;                      // +0x00
  NodeCharKeyIsnil21* head;         // +0x04 sentinel (isnil=1)
  std::uint32_t size;               // +0x08
};

// Undualed buynode: operator_new(0x24); links; copy char key + value; color; isnil=0
extern "C" NodeCharKeyIsnil21* FUN_0041d860(
    NodeCharKeyIsnil21* left,
    NodeCharKeyIsnil21* parent,
    NodeCharKeyIsnil21* right,
    const void* value,
    std::uint8_t color);

// Dualed rotates for color@+0x20 / isnil@+0x21 family (thiscall map + node).
extern "C" void __thiscall FUN_0050e9f0(MapShellCharKeyIsnil21* map, NodeCharKeyIsnil21* x); // Lrotate
extern "C" void __thiscall FUN_005a27f0(MapShellCharKeyIsnil21* map, NodeCharKeyIsnil21* x); // Rrotate

// Throw path: basic_string("map/set<T> too long") + FUN_00401a40 +
// _CxxThrowException(DAT_00acc388).

extern "C" NodeCharKeyIsnil21** __thiscall StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred(
    MapShellCharKeyIsnil21* map,
    NodeCharKeyIsnil21** out,
    char addLeft,
    NodeCharKeyIsnil21* where,
    const void* value)
{
  if (map->size >= 0x0CCCCCCBu) {
    // non-returning length_error — plate sealed
    return out;
  }

  NodeCharKeyIsnil21* head = map->head;
  // buynode: left=head, parent=where, right=head, color=red(0)
  NodeCharKeyIsnil21* n = FUN_0041d860(head, where, head, value, /*red*/ 0);
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
  NodeCharKeyIsnil21* x = n;
  while (x->parent->color == 0) {
    NodeCharKeyIsnil21* p = x->parent;
    NodeCharKeyIsnil21* gp = p->parent;
    if (p == gp->left) {
      NodeCharKeyIsnil21* uncle = gp->right;
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
      NodeCharKeyIsnil21* uncle = gp->left;
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
  return out; // sealed: EAX = out after epilogue
}

// Ghidra placeholder twin: FUN_0041ba30.cpp
