// =============================================================================
// StdTree_EraseRange_Isnil11_Inferred  (FUN_00441960)
// -----------------------------------------------------------------------------
// Stable ID: aa_00441960
// Address:   0x00441960 – 0x00441a11 inclusive (178 B / 0xB2)
//            autoassault.exe, image base 0x400000
// System:    skills-abilities — MSVC std map/set range erase (isnil@+0x11)
// Generated: 2026-08-05 MEGA-136 OWN dual seal (raw 2026-07-23 re-verified live)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed ABI from
//            disassemble_function + read_memory_bytes + call-site context.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE
//   MSVC-style _Tree::erase(first, last) for the small-node isnil@+0x11 family.
//   Full clear [begin,end)==[head->left, head] frees the whole tree via dualed
//   StdTree_FreeSubtree_Isnil11_Inferred then resets head extremities and size.
//   Partial range precomputes successor (isnil11) then calls residual single
//   erase FUN_004477a0 per node. Writes end iterator to *outIt.
//
//   Primary host: gfxUIWindow MapShell at this+0xA4 (partition alias
//   StdTree_EraseAll_ShellA4) inside gfxUIWindow_CompleteDtor residual path.
//
// ABI
//   EDI = MapShell*  (register convention — NOT ECX thiscall)
//   stack: Node** outIt, Node* first, Node* last
//   returns Node** outIt in EAX; RET 0xC both exits
//
// CALLERS (xrefs = 2)
//   FUN_00440200 @ 0x00440210  (shell tidy: erase-all + delete head)
//   gfxUIWindow_CompleteDtor (FUN_00759de0) @ 0x00759fe3  (shell@+0xA4 residual)
//
// CALLEES
//   StdTree_FreeSubtree_Isnil11_Inferred @ 0x00440d20  [dualed MEGA-132]
//   FUN_004477a0  single erase+rebalance isnil11  [residual]
//
// PEERS (do not merge)
//   StdTree_EraseRange_Isnil29_Inferred @ 0x004cbaa0
//   StdMap_EraseRange_Isnil131 / Isnil2d / Map_EraseRange* families
//   Free twin: StdTree_FreeSubtree_Isnil11_Inferred @ 0x00440d20
//
// REJECTED ALIASES
//   Named_CalleeOf_Named_gfxUIWindow_00441960  (scaffold — parent seed only)
//   Product UI-window helper (body is pure STL range erase)
//   ECX-thiscall erase-range (bytes use EDI; call sites MOV EDI,shell)
//   isnil@+0x15 / +0x1d / +0x29 / +0x31 merge
// =============================================================================

#include <cstdint>

struct MapNode_Isnil11 {
  MapNode_Isnil11 *left;    // +0x00
  MapNode_Isnil11 *parent;  // +0x04
  MapNode_Isnil11 *right;   // +0x08
  // value payload @ +0x0C (width product-open; typically 4 B)
  // uint8_t color;         // +0x10 (layout-inferred)
  // uint8_t isnil;         // +0x11  (byte-sealed)
};

struct MapShell_Isnil11 {
  void *proxy;                 // +0x00
  MapNode_Isnil11 *head;       // +0x04  end sentinel
  uint32_t size;               // +0x08
};

// Dualed MEGA-132: free non-nil subtree (isnil@+0x11). ECX=tree_base, stack node*, RET 4.
extern "C" void __fastcall StdTree_FreeSubtree_Isnil11_Inferred(
    void *tree_base,
    MapNode_Isnil11 *node);

// Residual single-node erase + RB rebalance (isnil@+0x11). Stack: map, outIt*, node.
// Ghidra FUN_004477a0. Not dualled by MEGA-136.
extern "C" void FUN_004477a0(
    MapShell_Isnil11 *map,
    MapNode_Isnil11 **outIt,
    MapNode_Isnil11 *node);

static uint8_t node_isnil11(const MapNode_Isnil11 *n)
{
  return *reinterpret_cast<const uint8_t *>(
      reinterpret_cast<const char *>(n) + 0x11);
}

// In-order successor for isnil@+0x11 nodes (matches 004419b1..004419f5).
static MapNode_Isnil11 *tree_successor_isnil11(MapNode_Isnil11 *node)
{
  MapNode_Isnil11 *succ = node;
  if (node_isnil11(node) != 0)
    return succ;

  MapNode_Isnil11 *right = node->right;
  if (node_isnil11(right) == 0) {
    succ = right;
    MapNode_Isnil11 *left = right->left;
    while (node_isnil11(left) == 0) {
      succ = left;
      left = left->left;
    }
    return succ;
  }

  MapNode_Isnil11 *parent = node->parent;
  MapNode_Isnil11 *cur = node;
  while (node_isnil11(parent) == 0 && cur == parent->right) {
    cur = parent;
    parent = parent->parent;
  }
  return parent;
}

// EDI = map (register); three stack args; RET 0xC; returns outIt*.
// Modeled as custom convention matching call sites (MOV EDI, shell).
extern "C" MapNode_Isnil11 ** /*EDI=map*/ StdTree_EraseRange_Isnil11_Inferred(
    MapShell_Isnil11 *map,           // EDI
    MapNode_Isnil11 **outIt,         // stack0
    MapNode_Isnil11 *first,          // stack1 inclusive
    MapNode_Isnil11 *last)           // stack2 exclusive
{
  MapNode_Isnil11 *head = map->head;

  // Full clear: [begin, end) == [head->left, head]
  if (first == head->left && last == head) {
    StdTree_FreeSubtree_Isnil11_Inferred(map, head->parent);
    head->parent = head;
    map->size = 0;
    head->left = head;
    head->right = head;
    *outIt = head->left;
    return outIt; // RET 0xC @ 0x004419aa
  }

  while (first != last) {
    MapNode_Isnil11 *node = first;
    MapNode_Isnil11 *succ = tree_successor_isnil11(first);
    // bytes @ 0x004419f7: push node; lea [esp+14]=&stack_first; push edi=map; call 004477a0
    FUN_004477a0(map, &first, node);
    first = succ;
  }
  *outIt = first;
  return outIt; // RET 0xC @ 0x00441a0f
}
