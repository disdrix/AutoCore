// =============================================================================
// Map_EraseRange
// -----------------------------------------------------------------------------
// Stable ID: aa_0051c7c0
// Address:   0x0051c7c0–0x0051c873  (180 B; autoassault.exe base 0x400000)
// System:    STL map/set (MSVC red-black range erase; isnil@+0x29)
// Generated: 2026-08-04 WQ9D-H OWN dual A/B seal
// Exactness: Behavior-preserving rewrite of live decompile + sealed bytes.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// Supersedes: FUN_0051c7c0.cpp scaffold; Named_CalleeOf_CVOGHBAIBase_* chain alias.
// Dual: reviews/A|B_aa_0051c7c0_Map_EraseRange.md
// =============================================================================
//
// PURPOSE:
//   Erase [first, last) from an MSVC-style map/set whose nodes use isnil@+0x29
//   (same family as Map_EraseNode / Map_ExactFindByIntKey).
//   Full-range fast path frees the whole tree via FUN_0051bbc0(root).
//   Partial path precomputes successor then calls Map_EraseNode per node.
//
// ABI: __thiscall ECX=map*; stack (out_it, first, last); RET 0x0C.
// =============================================================================

#include <cstdint>

struct MapHead {
  // +0x00 unused here
  void* head;            // +0x04 sentinel
  std::uint32_t size;    // +0x08
};

struct TreeNode {
  TreeNode* left;    // +0x00
  TreeNode* parent;  // +0x04
  TreeNode* right;   // +0x08
  // +0x10 key …
  // +0x28 color
  // +0x29 isnil
};

extern "C" void FUN_0051bbc0(TreeNode* root); // free non-nil subtree (isnil@+0x29)
extern "C" void __thiscall Map_EraseNode(MapHead* map, TreeNode** pOutIt, TreeNode* pNode);

static inline std::uint8_t node_isnil(const TreeNode* n)
{
  return *reinterpret_cast<const std::uint8_t*>(
      reinterpret_cast<const char*>(n) + 0x29);
}

// In-order successor for non-nil nodes (MSVC tree walk; isnil@+0x29).
static TreeNode* tree_successor(TreeNode* node)
{
  TreeNode* succ = node;
  if (node_isnil(node) != 0)
    return succ;

  TreeNode* right = node->right;
  if (node_isnil(right) == 0) {
    // leftmost of right subtree
    succ = right;
    TreeNode* left = right->left;
    while (node_isnil(left) == 0) {
      succ = left;
      left = left->left;
    }
    return succ;
  }

  // climb while node is right child
  TreeNode* parent = node->parent;
  TreeNode* cur = node;
  while (node_isnil(parent) == 0 && cur == parent->right) {
    cur = parent;
    parent = parent->parent;
  }
  return parent;
}

void __thiscall Map_EraseRange(
    MapHead* map,
    TreeNode** out_it,
    TreeNode* first,
    TreeNode* last)
{
  TreeNode* head = static_cast<TreeNode*>(map->head);

  // Full clear: [begin, end) == [*head, head]
  if (first == head->left /* *head as begin in MSVC layout: *head == leftmost */
      && last == head) {
    // Decomp: first == (int*)*head where head pointer is map->head;
    // *head is leftmost (begin). last == head (end sentinel).
    // Free root = head->parent.
    FUN_0051bbc0(head->parent);
    head->parent = head;
    map->size = 0;
    head->left = head;   // *head = head
    head->right = head;
    *out_it = head->left; // *head after reset
    return;
  }

  while (first != last) {
    TreeNode* succ = tree_successor(first);
    // Bytes: push node; lea eax,&first; push eax; mov ecx, map; call Map_EraseNode
    Map_EraseNode(map, &first, first);
    first = succ;
  }
  *out_it = first;
}
