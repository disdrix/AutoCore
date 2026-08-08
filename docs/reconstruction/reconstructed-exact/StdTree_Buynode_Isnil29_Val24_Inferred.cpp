// =============================================================================
// StdTree_Buynode_Isnil29_Val24_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005a2de0
// Address:   0x005a2de0–0x005a2e3a  (autoassault.exe @ 0x400000; 91 B / 0x5B)
// System:    std red-black tree / map node allocation (isnil@+0x29 family)
// Dual A/B:  2026-08-04 WQ9F-A
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   MSVC-style _Tree_node buy for maps/sets whose node is 0x30 bytes with
//   24-byte (6 dword) value payload and isnil flag at +0x29. Primary consumer
//   is StdTree_InsertAndRebalance_Isnil29_Inferred (0x004cbb60) and two insert
//   twin shells (0x0058da40, 0x005a3310).
//
// ABI
//   __stdcall; 5 stack args; ret 0x14; EAX = Node* (null on OOM)
//
// Layout (node 0x30)
//   +0x00  left*
//   +0x04  parent*
//   +0x08  right*
//   +0x0c  (untouched by buynode)
//   +0x10  value[6]  (24 B)
//   +0x28  color     (MSVC: 0=red, 1=black)
//   +0x29  isnil     (forced 0)
//
// Contrast
//   StdTree_Buynode_Val12 (0x005ae220) — node 0x1c, value 3 dwords, isnil@+0x19
//
// Rejected aliases
//   Val12 buynode; skill-gather product name from old scaffold path
// =============================================================================

#include <cstdint>

struct StdTreeNode_Isnil29_Val24 {
  StdTreeNode_Isnil29_Val24 *left;    // +0x00
  StdTreeNode_Isnil29_Val24 *parent;  // +0x04
  StdTreeNode_Isnil29_Val24 *right;   // +0x08
  uint32_t _gap0c;                    // +0x0c (not written here)
  uint32_t value[6];                  // +0x10
  uint8_t  color;                     // +0x28
  uint8_t  isnil;                     // +0x29
  uint8_t  _pad[2];
};

// Retail: stdcall ret 0x14; return in EAX (null on OOM).
extern "C" StdTreeNode_Isnil29_Val24 *__stdcall StdTree_Buynode_Isnil29_Val24_Inferred(
    StdTreeNode_Isnil29_Val24 *left,
    StdTreeNode_Isnil29_Val24 *parent,
    StdTreeNode_Isnil29_Val24 *right,
    const uint32_t *value6,
    uint8_t color)
{
  auto *node = static_cast<StdTreeNode_Isnil29_Val24 *>(operator_new(0x30));
  if (node != nullptr) {
    node->left = left;
    node->parent = parent;
    node->right = right;
    // +0x0c left uninitialized by this helper
    node->value[0] = value6[0];
    node->value[1] = value6[1];
    node->value[2] = value6[2];
    node->value[3] = value6[3];
    node->value[4] = value6[4];
    node->value[5] = value6[5];
    node->color = color;
    node->isnil = 0;
  }
  return node;
}
