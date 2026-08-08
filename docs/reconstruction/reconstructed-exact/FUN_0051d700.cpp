// =============================================================================
// FUN_0051d700  (scaffold alias — see Map_EraseRange_Isnil1d_Inferred.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_0051d700
// Address:   0x0051d700  (autoassault.exe, image base 0x400000)
// System:    STL map/set range erase (isnil@+0x1d)
// Generated: 2026-08-04 WQ9E-I — scaffold kept as FUN_* twin of named clean
// Exactness: Behavior-preserving. Prefer Map_EraseRange_Isnil1d_Inferred.cpp.
// Dual: reviews/A|B_aa_0051d700_Map_EraseRange_Isnil1d_Inferred.md
// =============================================================================

#include <cstdint>

struct MapHead {
  void* head;
  std::uint32_t size;
};

struct TreeNode {
  TreeNode* left;
  TreeNode* parent;
  TreeNode* right;
};

extern "C" void FUN_0051be10(TreeNode* root);
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

void __thiscall FUN_0051d700(
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
