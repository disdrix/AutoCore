// =============================================================================
// Map_EraseRange_B
// -----------------------------------------------------------------------------
// Stable ID: aa_0051d880
// Address:   0x0051d880–0x0051d933  (180 B; autoassault.exe base 0x400000)
// System:    STL map/set (MSVC red-black range erase; isnil@+0x29)
// Generated: 2026-08-04 WQ9D-H OWN dual A/B seal
// Exactness: Behavior-preserving rewrite of live decompile + sealed bytes.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// Supersedes: FUN_0051d880.cpp scaffold.
// Dual: reviews/A|B_aa_0051d880_Map_EraseRange_B.md
// =============================================================================
//
// PURPOSE:
//   Twin of Map_EraseRange (0x0051c7c0). Same CF / ABI / isnil@+0x29 /
//   Map_EraseNode partial path. Discriminator: full-clear free-subtree
//   FUN_0051be90 (vs FUN_0051bbc0). Separate MSVC map instantiation.
//
// ABI: __thiscall ECX=map*; stack (out_it, first, last); RET 0x0C.
// =============================================================================

#include <cstdint>

struct MapHead {
  void* head;            // +0x04
  std::uint32_t size;    // +0x08
};

struct TreeNode {
  TreeNode* left;
  TreeNode* parent;
  TreeNode* right;
  // isnil @ +0x29
};

extern "C" void FUN_0051be90(TreeNode* root);
extern "C" void __thiscall Map_EraseNode(MapHead* map, TreeNode** pOutIt, TreeNode* pNode);

static inline std::uint8_t node_isnil(const TreeNode* n)
{
  return *reinterpret_cast<const std::uint8_t*>(
      reinterpret_cast<const char*>(n) + 0x29);
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

void __thiscall Map_EraseRange_B(
    MapHead* map,
    TreeNode** out_it,
    TreeNode* first,
    TreeNode* last)
{
  TreeNode* head = static_cast<TreeNode*>(map->head);

  if (first == head->left && last == head) {
    FUN_0051be90(head->parent); // only free-subtree delta vs Map_EraseRange
    head->parent = head;
    map->size = 0;
    head->left = head;
    head->right = head;
    *out_it = head->left;
    return;
  }

  while (first != last) {
    TreeNode* succ = tree_successor(first);
    Map_EraseNode(map, &first, first);
    first = succ;
  }
  *out_it = first;
}
