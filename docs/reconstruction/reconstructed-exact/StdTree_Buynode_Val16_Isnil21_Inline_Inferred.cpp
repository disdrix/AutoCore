// =============================================================================
// StdTree_Buynode_Val16_Isnil21_Inline_Inferred  (FUN_004e2b80)
// -----------------------------------------------------------------------------
// Stable ID: aa_004e2b80
// Address:   0x004e2b80–0x004e2bce inclusive (79 B / 0x4F)
// System:    MSVC std::_Tree node buy — Val16 payload, isnil@+0x21, inline ctor
// Generated: 2026-08-05 R13-004 dual seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Allocate one red-black tree node (size 0x28) and construct links + 16-byte
//   value + color + isnil=0 **inline** (no separate NodeCtor, no SEH). Shared
//   buynode for insert/rebalance FUN_004e37e0 and peer FUN_005a3500.
//
// ABI: __stdcall; 5 stack args; RET 0x14; EAX = node* | null.
// Distinct from peer 0x00408990 (SEH + FUN_004099b0) — keep clones separate.
// Distinct from Val24/isnil29 0x30 buynodes (00407e30 / 005a2de0).
//
// Dual: reviews/A|B_aa_004e2b80_StdTree_Buynode_Val16_Isnil21_Inline_Inferred.md
// Scaffold retired: Named_CalleeOf_*CVOGReaction*_004e2b80

#include <cstdint>
#include <cstddef>

struct NodeIsnil21 {
  NodeIsnil21* left;     // +0x00
  NodeIsnil21* parent;   // +0x04
  NodeIsnil21* right;    // +0x08
  // +0x0C unused on construct path
  std::uint32_t val[4];  // +0x10 .. +0x1C  (Val16 / 0x10 bytes)
  std::uint8_t color;    // +0x20  (0=red, 1=black)
  std::uint8_t isnil;    // +0x21
  // pad to 0x28
};

// CRT
extern "C" void* operator_new(std::size_t size);

// __stdcall RET 0x14
extern "C" NodeIsnil21* __stdcall StdTree_Buynode_Val16_Isnil21_Inline_Inferred(
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

// Scaffold alias (Ghidra FUN_*)
extern "C" NodeIsnil21* __stdcall FUN_004e2b80(
    NodeIsnil21* left,
    NodeIsnil21* parent,
    NodeIsnil21* right,
    const std::uint32_t* value4,
    std::uint8_t color)
{
  return StdTree_Buynode_Val16_Isnil21_Inline_Inferred(
      left, parent, right, value4, color);
}
