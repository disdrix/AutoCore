// =============================================================================
// StdTree_EraseAll_Shell10_Inferred  (FUN_00441720)
// -----------------------------------------------------------------------------
// Stable ID: aa_00441720
// Address:   0x00441720 – 0x004417d1 inclusive (178 B / 0xB2)
//            Pad CC @ 0x004417d2–0x004417df; next SEH @ 0x004417e0
// System:    STL map/set range erase — isnil@+0x1d / value shell 0x10
//            (partition: skills-abilities residual of gfxUIWindow_CompleteDtor)
// Generated: 2026-08-05 MEGA-135 dual seal (raw 2026-07-23 re-verified live)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed EDI/RET ABI.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE
//   MSVC-style _Tree::erase(first, last) for isnil@+0x1d nodes with 0x10-byte
//   value payload (color@+0x1c). Full clear [begin,end) frees the whole tree
//   via FUN_00440c90 then resets head extremities and size. Partial range
//   advances with in-order successor then calls FUN_00442000 per node.
//   Writes end iterator to *outIt. Both exits RET 0x0C.
//
// ABI (retail)
//   EDI = MapShell*  (callers MOV EDI,tree before CALL; body never loads ECX)
//   stack: outIt, first, last
//   RET 0x0C; EAX = outIt
//
// CALLERS (xrefs)
//   FUN_004401d0 @ 0x004401e0  — EH residual full-clear + delete head
//   FUN_00759de0 @ 0x0075a09c  — gfxUIWindow_CompleteDtor tree-shell clear
//
// CALLEES
//   FUN_00440c90  free-subtree isnil@+0x1d (ECX=tree, stack root, RET 4)
//   FUN_00442000  erase-node + rebalance isnil@+0x1d (stack tree/out/node)
//
// PEERS (do not merge)
//   FUN_00441960                 — same shape, isnil@+0x11
//   Map_EraseRange_Isnil1d       — 0x0051d700; different free/erase pair
//   StdTree_EraseRange_Isnil29   — 0x004cbaa0; isnil@+0x29 ECX-thiscall
// =============================================================================

#include <cstdint>

struct MapNode_Shell10 {
  MapNode_Shell10 *left;    // +0x00
  MapNode_Shell10 *parent;  // +0x04
  MapNode_Shell10 *right;   // +0x08
  // value payload @ +0x0c .. +0x1b (0x10 bytes; nested head often @ +0x14)
  uint8_t color;            // +0x1c
  uint8_t isnil;            // +0x1d
};

struct MapShell_Shell10 {
  void *proxy;                 // +0x00
  MapNode_Shell10 *head;       // +0x04  end sentinel
  uint32_t size;               // +0x08
};

// Free non-nil subtree (isnil@+0x1d). thiscall ECX=tree; stack root; RET 4.
// Value destroy via FUN_00442730 then operator_delete.
extern "C" void __thiscall FUN_00440c90(MapShell_Shell10 *tree, MapNode_Shell10 *root);

// Single-node erase + RB rebalance (isnil@+0x1d). Stack (tree, outIt, node).
// Throws std::out_of_range("invalid map/set<T> iterator") on nil node.
extern "C" void FUN_00442000(MapShell_Shell10 *tree,
                             MapNode_Shell10 **outIt,
                             MapNode_Shell10 *node);

static MapNode_Shell10 *tree_successor_isnil1d(MapNode_Shell10 *node)
{
  MapNode_Shell10 *succ = node;
  if (node->isnil != 0)
    return succ;

  MapNode_Shell10 *right = node->right;
  if (right->isnil == 0) {
    succ = right;
    MapNode_Shell10 *left = right->left;
    while (left->isnil == 0) {
      succ = left;
      left = left->left;
    }
    return succ;
  }

  MapNode_Shell10 *parent = node->parent;
  MapNode_Shell10 *cur = node;
  while (parent->isnil == 0 && cur == parent->right) {
    cur = parent;
    parent = parent->parent;
  }
  return parent;
}

// Portable signature: tree is explicit. Retail binds tree in EDI + RET 0xC.
MapNode_Shell10 **StdTree_EraseAll_Shell10_Inferred(
    MapShell_Shell10 *tree,       // retail: EDI
    MapNode_Shell10 **outIt,      // stack0
    MapNode_Shell10 *first,       // stack1 inclusive
    MapNode_Shell10 *last)        // stack2 exclusive
{
  MapNode_Shell10 *head = tree->head;

  // Full clear: [begin, end) == [head->left, head]
  if (first == head->left && last == head) {
    FUN_00440c90(tree, head->parent);
    head->parent = head;
    tree->size = 0;
    head->left = head;
    head->right = head;
    *outIt = head->left;
    return outIt;
  }

  while (first != last) {
    MapNode_Shell10 *victim = first;
    if (first->isnil == 0)
      first = tree_successor_isnil1d(first);
    MapNode_Shell10 *tmp = nullptr;
    FUN_00442000(tree, &tmp, victim);
  }

  *outIt = first;
  return outIt;
}
