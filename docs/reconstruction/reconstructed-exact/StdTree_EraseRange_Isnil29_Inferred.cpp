// =============================================================================
// StdTree_EraseRange_Isnil29_Inferred  (FUN_004cbaa0)
// -----------------------------------------------------------------------------
// Stable ID: aa_004cbaa0
// Address:   0x004cbaa0 – 0x004cbb54 exclusive (180 B / 0xB4)
//            Ghidra body end 0x004cbb53
// System:    std map/set red-black range erase (isnil@+0x29)
// Generated: 2026-08-04 WQ9F-C dual seal (raw 2026-07-23 re-verified live)
// Exactness: Behavior-preserving rewrite of decompiler control flow + sealed ABI.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE
//   MSVC-style _Tree::erase(first, last) for isnil@+0x29 nodes.
//   Full clear [begin,end) frees the whole tree via FUN_004cb550 then resets
//   head extremities and size. Partial range precomputes successor then calls
//   StdTree_EraseAndRebalance_Isnil29_Inferred per node. Writes end iterator
//   to *outIt. Both exits RET 0x0C.
//
// ABI
//   __thiscall; ECX = MapShell*; three stack args; RET 0x0C
//
// CALLERS (xrefs)
//   FUN_004cc3d0, FUN_004c9f80 (creature dtor path), FUN_004ea350 (×3), 0x005dd8cb
//
// PEERS (do not merge)
//   Map_EraseRange @ 0x0051c7c0          — free 0051bbc0 / erase Map_EraseNode
//   Map_EraseRange_B @ 0x0051d880        — free 0051be90 / erase Map_EraseNode
//   Map_EraseRange_Isnil15 / Isnil1d / Val12 families
//   Single erase: StdTree_EraseAndRebalance_Isnil29_Inferred @ 0x004cb740
// =============================================================================

#include <cstdint>

struct MapNode_Isnil29 {
  MapNode_Isnil29 *left;    // +0x00
  MapNode_Isnil29 *parent;  // +0x04
  MapNode_Isnil29 *right;   // +0x08
  // value payload @ +0x10 ..
  uint8_t color;            // +0x28
  uint8_t isnil;            // +0x29
};

struct MapShell_Isnil29 {
  void *proxy;                 // +0x00
  MapNode_Isnil29 *head;       // +0x04  end sentinel
  uint32_t size;               // +0x08
};

// Free non-nil subtree (isnil@+0x29). Residual algebra — decomp may drop left recurse.
extern "C" void FUN_004cb550(MapNode_Isnil29 *root);

// Single-node erase + RB rebalance (dualed WQ9E-E). RET 8.
extern "C" void __thiscall StdTree_EraseAndRebalance_Isnil29_Inferred(
    MapShell_Isnil29 *map,
    MapNode_Isnil29 **outIt,
    MapNode_Isnil29 *node);

static MapNode_Isnil29 *tree_successor_isnil29(MapNode_Isnil29 *node)
{
  MapNode_Isnil29 *succ = node;
  if (node->isnil != 0)
    return succ;

  MapNode_Isnil29 *right = node->right;
  if (right->isnil == 0) {
    succ = right;
    MapNode_Isnil29 *left = right->left;
    while (left->isnil == 0) {
      succ = left;
      left = left->left;
    }
    return succ;
  }

  MapNode_Isnil29 *parent = node->parent;
  MapNode_Isnil29 *cur = node;
  while (parent->isnil == 0 && cur == parent->right) {
    cur = parent;
    parent = parent->parent;
  }
  return parent;
}

void __thiscall StdTree_EraseRange_Isnil29_Inferred(
    MapShell_Isnil29 *map,       // ECX
    MapNode_Isnil29 **outIt,     // stack0
    MapNode_Isnil29 *first,      // stack1 inclusive
    MapNode_Isnil29 *last)       // stack2 exclusive
{
  MapNode_Isnil29 *head = map->head;

  // Full clear: [begin, end) == [head->left, head]
  if (first == head->left && last == head) {
    FUN_004cb550(head->parent);
    head->parent = head;
    map->size = 0;
    head->left = head;
    head->right = head;
    *outIt = head->left;
    return; // ret 0x0c
  }

  while (first != last) {
    MapNode_Isnil29 *succ = tree_successor_isnil29(first);
    // bytes @ 0x004cbb3f: push node; lea out; push out; mov ecx, map; call 004cb740
    StdTree_EraseAndRebalance_Isnil29_Inferred(map, &first, first);
    first = succ;
  }
  *outIt = first;
  return; // ret 0x0c
}
