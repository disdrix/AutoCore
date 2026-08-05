// =============================================================================
// MissionTree_InorderCollectMediaPreloads_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004a04f0
// Address:   0x004a04f0–0x004a057a exclusive (138 B / 0x8A)
// Module:    autoassault.exe @ 0x400000
// System:    mission tree inorder walk → media preload collect
// Wave:      W37-C OWN-ONLY 2026-08-04
// Exactness: Behavior-preserving from decompile + full-body read_memory.
//            Not modernization. Bit-for-bit / runtime: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Walk a tree of mission-host payloads in inorder; for each non-nil node,
//   call MissionHost_CollectMediaPreloads with the four stack flags from the
//   parent (graphics / sound / physics collectors select flag triples).
//
// ABI:
//   thiscall ECX = tree_holder*
//   stack0  = unused (forwarded; not read here)
//   stack1  = flag_media_strings
//   stack2  = flag_mission_audio
//   stack3  = flag_obj_paths
//   void; RET 0x10
//
// Tree holder (from bytes):
//   p = *holder; head = *(p + 4); begin = *head; empty iff begin == head.
//
// Node (from walk CF):
//   +0x00 left, +0x04 parent, +0x08 right
//   +0x10 payload (mission host* → ECX of 004b88e0)
//   +0x15 nil-gate (successor / child tests)
//
// Callee: 0x004b88e0 MissionHost_CollectMediaPreloads_Inferred (W32-H)
// Ghidra: FUN_004a04f0
// Reject: Named_CalleeOf_*VOG_DEBUG*_004a04f0
//

#include <cstdint>

struct TreeNode {
  TreeNode* left;    // +0x00
  TreeNode* parent;  // +0x04
  TreeNode* right;   // +0x08
  uint8_t pad_0c[4]; // layout residual through +0x0f
  void* payload;     // +0x10 — mission host*
  // nil-gate observed at +0x15 (inside/after pad relative to payload start)
};

// Holder first field points at a structure with head pointer at +4.
struct TreeHolder {
  uint8_t* impl; // *impl + 4 → head node*
};

// W32-H: thiscall; stack unused + 3 flags; RET 0x10
extern "C" void MissionHost_CollectMediaPreloads_Inferred(
    void* host /*ECX*/,
    uint32_t unused,
    uint32_t flag_media_strings,
    uint32_t flag_mission_audio,
    uint32_t flag_obj_paths);

static inline bool node_is_nil(const TreeNode* n)
{
  return *reinterpret_cast<const uint8_t*>(reinterpret_cast<const char*>(n) +
                                           0x15) != 0;
}

// MSVC-style inorder successor (matches decompile / bytes).
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

extern "C" void __thiscall MissionTree_InorderCollectMediaPreloads_Inferred(
    TreeHolder* holder /*ECX*/,
    uint32_t unused,
    uint32_t flag_media_strings,
    uint32_t flag_mission_audio,
    uint32_t flag_obj_paths)
{
  TreeNode* head =
      *reinterpret_cast<TreeNode**>(holder->impl + 4);
  TreeNode* node = head->left; // bytes: mov esi, [eax] after head load
  // Empty: begin == head (bytes cmp esi, eax)
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

// Ghidra / scaffold alias
extern "C" void __thiscall FUN_004a04f0(TreeHolder* holder,
                                        uint32_t a,
                                        uint32_t b,
                                        uint32_t c,
                                        uint32_t d)
{
  MissionTree_InorderCollectMediaPreloads_Inferred(holder, a, b, c, d);
}
