// =============================================================================
// Map_EraseRange_C  (FUN_00407d70)
// -----------------------------------------------------------------------------
// Stable ID: aa_00407d70
// Address:   0x00407d70–0x00407e24 exclusive (180 B / 0xB4)
// System:    MSVC std::_Tree range erase (isnil@+0x29)
// Dual A/B:  2026-08-04 WQ9H-F
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed ABI bytes.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Erase [first, last) from an MSVC-style map/set whose nodes use isnil@+0x29.
//   Full-range fast path frees the whole tree via dualed free-subtree
//   StdTree_FreeSubtree_Isnil29_Inferred (0x00406c00), then resets head/size.
//   Partial path precomputes successor then calls dualed Map_EraseNode_B
//   (0x00409220) per node.
//
// ABI
//   __thiscall; ECX = map*; stack (Node** outIt, Node* first, Node* last);
//   RET 0x0c.
//
// Callers
//   FUN_00405350, FUN_00406010, FUN_004d98f0 (full-range clear / map tidy).
//
// Twin family
//   Map_EraseRange (0x0051c7c0), Map_EraseRange_B (0x0051d880) — same CF class.
// =============================================================================

#include <cstdint>

struct NodeIsnil29 {
  NodeIsnil29* left;     // +0x00
  NodeIsnil29* parent;   // +0x04
  NodeIsnil29* right;    // +0x08
  // +0x10 key/value ...
  // +0x28 color
  std::uint8_t isnil;    // +0x29  (layout note; offset sealed by immediates)
};

// Force exact isnil offset without relying on trailing packing assumptions.
static inline std::uint8_t node_isnil(const NodeIsnil29* n)
{
  return *reinterpret_cast<const std::uint8_t*>(
      reinterpret_cast<const char*>(n) + 0x29);
}

struct MapShell {
  void* proxy;           // +0x00
  NodeIsnil29* head;     // +0x04 sentinel
  std::uint32_t size;    // +0x08
};

// Dualed WQ9G free-subtree (right-first free of non-nil nodes).
extern "C" void FUN_00406c00(NodeIsnil29* root);

// Dualed WQ9E-G single-node erase (RET 8).
extern "C" void __thiscall Map_EraseNode_B(
    MapShell* map, NodeIsnil29** pOutIt, NodeIsnil29* pNode);

// In-order successor for non-nil nodes (MSVC tree walk; isnil@+0x29).
static NodeIsnil29* tree_successor(NodeIsnil29* node)
{
  NodeIsnil29* succ = node;
  if (node_isnil(node) != 0)
    return succ;

  NodeIsnil29* right = node->right;
  if (node_isnil(right) == 0) {
    succ = right;
    NodeIsnil29* left = right->left;
    while (node_isnil(left) == 0) {
      succ = left;
      left = left->left;
    }
    return succ;
  }

  NodeIsnil29* parent = node->parent;
  NodeIsnil29* cur = node;
  while (node_isnil(parent) == 0 && cur == parent->right) {
    cur = parent;
    parent = parent->parent;
  }
  return parent;
}

extern "C" NodeIsnil29** __thiscall Map_EraseRange_C(
    MapShell* map,
    NodeIsnil29** out_it,
    NodeIsnil29* first,
    NodeIsnil29* last)
{
  NodeIsnil29* head = map->head;

  // Full clear: [begin, end) == [*head, head]
  if (first == head->left && last == head) {
    FUN_00406c00(head->parent);
    head->parent = head;
    map->size = 0;
    head->left = head;
    head->right = head;
    *out_it = head->left;
    return out_it;
  }

  while (first != last) {
    NodeIsnil29* succ = tree_successor(first);
    // Bytes: push node; lea eax,&first; push eax; mov ecx,map; call Map_EraseNode_B
    Map_EraseNode_B(map, &first, first);
    first = succ;
  }
  *out_it = first;
  return out_it;
}