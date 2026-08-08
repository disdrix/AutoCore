// =============================================================================
// Map_EraseRange_Isnil1d_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0051d700
// Address:   0x0051d700–0x0051d7b4  (180 B; autoassault.exe base 0x400000)
// System:    STL map/set (MSVC red-black range erase; isnil@+0x1d)
// Generated: 2026-08-04 WQ9E-I OWN dual A/B seal
// Exactness: Behavior-preserving rewrite of live decompile + sealed bytes.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// Supersedes: FUN_0051d700.cpp scaffold.
// Dual: reviews/A|B_aa_0051d700_Map_EraseRange_Isnil1d_Inferred.md
// =============================================================================
//
// PURPOSE:
//   Erase [first, last) from an MSVC-style map/set whose nodes use isnil@+0x1d
//   (distinct from Map_EraseRange / Map_EraseRange_B isnil@+0x29 family).
//   Full-range fast path frees the whole tree via FUN_0051be10(root).
//   Partial path precomputes successor then calls FUN_0051c880 per node.
//
// ABI: __thiscall ECX=map*; stack (out_it, first, last); RET 0x0C.
// =============================================================================

#include <cstdint>

struct MapHead {
  void* head;            // +0x04
  std::uint32_t size;    // +0x08
};

struct TreeNode {
  TreeNode* left;    // +0x00
  TreeNode* parent;  // +0x04
  TreeNode* right;   // +0x08
  // isnil @ +0x1d
};

extern "C" void FUN_0051be10(TreeNode* root); // free non-nil subtree (isnil@+0x1d)
extern "C" void __thiscall FUN_0051c880(MapHead* map, TreeNode** pOutIt, TreeNode* pNode);

static inline std::uint8_t node_isnil(const TreeNode* n)
{
  return *reinterpret_cast<const std::uint8_t*>(
      reinterpret_cast<const char*>(n) + 0x1d);
}

static TreeNode* tree_successor(TreeNode* node)
{
  TreeNode* succ = node;
  if (node_isnil(node) != 0)
    return succ;

  TreeNode* right = node->right;
  if (node_isnil(right) == 0) {
    succ = right;
    TreeNode* left = right->left;
    while (node_isnil(left) == 0) {
      succ = left;
      left = left->left;
    }
    return succ;
  }

  TreeNode* parent = node->parent;
  TreeNode* cur = node;
  while (node_isnil(parent) == 0 && cur == parent->right) {
    cur = parent;
    parent = parent->parent;
  }
  return parent;
}

void __thiscall Map_EraseRange_Isnil1d_Inferred(
    MapHead* map,
    TreeNode** out_it,
    TreeNode* first,
    TreeNode* last)
{
  TreeNode* head = static_cast<TreeNode*>(map->head);

  if (first == head->left && last == head) {
    FUN_0051be10(head->parent);
    head->parent = head;
    map->size = 0;
    head->left = head;
    head->right = head;
    *out_it = head->left;
    return;
  }

  while (first != last) {
    TreeNode* succ = tree_successor(first);
    FUN_0051c880(map, &first, first);
    first = succ;
  }
  *out_it = first;
}
