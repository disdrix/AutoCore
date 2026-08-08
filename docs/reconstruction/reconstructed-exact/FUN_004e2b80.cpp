// =============================================================================
// FUN_004e2b80  (twin of StdTree_Buynode_Val16_Isnil21_Inline_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004e2b80
// Address:   0x004e2b80–0x004e2bce inclusive (79 B / 0x4F)
// System:    MSVC std::_Tree node buy — Val16 / isnil@+0x21 / inline
// Generated: 2026-08-05 R13-004 dual seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Canonical name: StdTree_Buynode_Val16_Isnil21_Inline_Inferred
// Dual: reviews/A|B_aa_004e2b80_StdTree_Buynode_Val16_Isnil21_Inline_Inferred.md
// Named clean: StdTree_Buynode_Val16_Isnil21_Inline_Inferred.cpp
// Scaffold retired: Named_CalleeOf_*CVOGReaction*_004e2b80

#include <cstdint>
#include <cstddef>

struct NodeIsnil21 {
  NodeIsnil21* left;     // +0x00
  NodeIsnil21* parent;   // +0x04
  NodeIsnil21* right;    // +0x08
  // +0x0C unused on construct path
  std::uint32_t val[4];  // +0x10 .. +0x1C
  std::uint8_t color;    // +0x20
  std::uint8_t isnil;    // +0x21
};

extern "C" void* operator_new(std::size_t size);

// __stdcall RET 0x14; EAX = node* | null
extern "C" NodeIsnil21* __stdcall FUN_004e2b80(
    NodeIsnil21* left,
    NodeIsnil21* parent,
    NodeIsnil21* right,
    const std::uint32_t* value4,
    std::uint8_t color)
{
  auto* node = static_cast<NodeIsnil21*>(operator_new(0x28));
  if (node != nullptr) {
    node->left = left;
    node->parent = parent;
    node->right = right;
    node->val[0] = value4[0];
    node->val[1] = value4[1];
    node->val[2] = value4[2];
    node->val[3] = value4[3];
    node->color = color;
    node->isnil = 0;
  }
  return node;
}
