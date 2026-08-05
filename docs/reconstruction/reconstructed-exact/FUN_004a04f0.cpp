// =============================================================================
// FUN_004a04f0 — twin of MissionTree_InorderCollectMediaPreloads_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004a04f0
// Address:   0x004a04f0–0x004a057a exclusive (138 B)
// Wave:      W37-C 2026-08-04
// See:       MissionTree_InorderCollectMediaPreloads_Inferred.cpp
// =============================================================================

#include <cstdint>

struct TreeNode {
  TreeNode* left;
  TreeNode* parent;
  TreeNode* right;
  uint8_t pad_0c[4];
  void* payload;
};

struct TreeHolder {
  uint8_t* impl;
};

extern "C" void MissionHost_CollectMediaPreloads_Inferred(
    void* host, uint32_t unused, uint32_t f3, uint32_t f4, uint32_t f5);

static inline bool node_is_nil(const TreeNode* n)
{
  return *reinterpret_cast<const uint8_t*>(reinterpret_cast<const char*>(n) +
                                           0x15) != 0;
}

static TreeNode* tree_inorder_successor(TreeNode* node)
{
  if (!node_is_nil(node)) {
    TreeNode* r = node->right;
    if (!node_is_nil(r)) {
      TreeNode* cur = r;
      TreeNode* left = cur->left;
      while (!node_is_nil(left)) {
        cur = left;
        left = cur->left;
      }
      return cur;
    }
    TreeNode* p = node->parent;
    TreeNode* cur = node;
    while (!node_is_nil(p) && cur == p->right) {
      cur = p;
      p = p->parent;
    }
    return p;
  }
  return node;
}

// ABI: thiscall ECX=holder; 4 stack dwords; RET 0x10
extern "C" void __thiscall FUN_004a04f0(TreeHolder* holder,
                                        uint32_t unused,
                                        uint32_t flag_media_strings,
                                        uint32_t flag_mission_audio,
                                        uint32_t flag_obj_paths)
{
  TreeNode* head = *reinterpret_cast<TreeNode**>(holder->impl + 4);
  TreeNode* node = head->left;
  if (node == head) {
    return;
  }
  do {
    void* host = *reinterpret_cast<void**>(
        reinterpret_cast<char*>(node) + 0x10);
    MissionHost_CollectMediaPreloads_Inferred(
        host, unused, flag_media_strings, flag_mission_audio, flag_obj_paths);
    node = tree_inorder_successor(node);
  } while (node != head);
}
