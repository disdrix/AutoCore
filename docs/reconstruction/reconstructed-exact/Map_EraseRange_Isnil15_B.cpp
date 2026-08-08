// =============================================================================
// Map_EraseRange_Isnil15_B
// -----------------------------------------------------------------------------
// Stable ID: aa_0051d940
// Address:   0x0051d940–0x0051d9f3 inclusive (180 B; autoassault.exe base 0x400000)
// System:    STL map/set (MSVC red-black range erase; isnil@+0x15)
// Generated: 2026-08-04 WQ9F-J OWN dual A/B seal
// Exactness: Behavior-preserving rewrite of live decompile + sealed bytes.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// Supersedes: FUN_0051d940.cpp scaffold.
// Dual: reviews/A|B_aa_0051d940_Map_EraseRange_Isnil15_B.md
// Twin: Map_EraseRange_Isnil15 (aa_0051d7c0; free FUN_0051be50).
// Peer: Map_EraseRange / Map_EraseRange_B (isnil@+0x29).
// =============================================================================
//
// PURPOSE:
//   Twin of Map_EraseRange_Isnil15. Same CF / ABI / isnil@+0x15 /
//   FUN_0051ce00 partial path. Discriminator: full-clear free-subtree
//   FUN_0051bed0 (vs FUN_0051be50). Separate MSVC map instantiation.
//
// ABI: __thiscall ECX=map*; stack (out_it, first, last); RET 0x0C.
// =============================================================================

#include <cstdint>

struct MapHead_Isnil15 {
  // +0x00 unused here
  void* head;            // +0x04 sentinel
  std::uint32_t size;    // +0x08
};

struct TreeNode_Isnil15 {
  TreeNode_Isnil15* left;    // +0x00
  TreeNode_Isnil15* parent;  // +0x04
  TreeNode_Isnil15* right;   // +0x08
  // color @ +0x14; isnil @ +0x15
};

extern "C" void FUN_0051bed0(TreeNode_Isnil15* root); // free non-nil subtree (isnil@+0x15)
extern "C" void __thiscall FUN_0051ce00(MapHead_Isnil15* map,
                                        TreeNode_Isnil15** pOutIt,
                                        TreeNode_Isnil15* pNode);

static inline std::uint8_t node_isnil(const TreeNode_Isnil15* n)
{
  return *reinterpret_cast<const std::uint8_t*>(
      reinterpret_cast<const char*>(n) + 0x15);
}

// In-order successor for non-nil nodes (MSVC tree walk; isnil@+0x15).
static TreeNode_Isnil15* tree_successor(TreeNode_Isnil15* node)
{
  TreeNode_Isnil15* succ = node;
  if (node_isnil(node) != 0)
    return succ;

  TreeNode_Isnil15* right = node->right;
  if (node_isnil(right) == 0) {
    succ = right;
    TreeNode_Isnil15* left = right->left;
    while (node_isnil(left) == 0) {
      succ = left;
      left = left->left;
    }
    return succ;
  }

  TreeNode_Isnil15* parent = node->parent;
  TreeNode_Isnil15* cur = node;
  while (node_isnil(parent) == 0 && cur == parent->right) {
    cur = parent;
    parent = parent->parent;
  }
  return parent;
}

void __thiscall Map_EraseRange_Isnil15_B(
    MapHead_Isnil15* map,
    TreeNode_Isnil15** out_it,
    TreeNode_Isnil15* first,
    TreeNode_Isnil15* last)
{
  TreeNode_Isnil15* head = static_cast<TreeNode_Isnil15*>(map->head);

  // Full clear: [begin, end) == [*head, head]
  // Note: MSVC head->left is leftmost; decomp compares first to *head (left link).
  if (first == *reinterpret_cast<TreeNode_Isnil15**>(head) && last == head) {
    FUN_0051bed0(head->parent);
    head->parent = head;
    map->size = 0;
    *reinterpret_cast<TreeNode_Isnil15**>(head) = head; // left
    head->right = head;
    *out_it = *reinterpret_cast<TreeNode_Isnil15**>(head);
    return;
  }

  while (first != last) {
    TreeNode_Isnil15* succ = tree_successor(first);
    // Bytes: push node; lea eax,&first; push eax; mov ecx, map; call FUN_0051ce00
    FUN_0051ce00(map, &first, first);
    first = succ;
  }
  *out_it = first;
}
