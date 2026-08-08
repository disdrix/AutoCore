// =============================================================================
// StdTree_NodeCtor_Val24_Isnil29_Thiscall_Inferred  (FUN_004098d0)
// -----------------------------------------------------------------------------
// Stable ID: aa_004098d0
// Address:   0x004098d0–0x0040991e inclusive (79 B / 0x4F); exclusive end 0x0040991f
// System:    MSVC std::_Tree node construct — Val24 payload, isnil@+0x29
// Generated: 2026-08-04 WQ9J-H dual seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Construct one red-black tree node in place (no allocation): links + 24-byte
//   value + color + isnil=0. Sole caller: dualed buynode
//   StdTree_Buynode_Val24_Isnil29_Inferred (0x00407e30 / WQ9F-B) after
//   operator_new(0x30); insert parent StdTree_InsertAndRebalance_Isnil29_Inferred
//   (0x00406c40).
//
// ABI: __thiscall; ECX=this; stack left, parent, right, value*, color; RET 0x14.
// Twin EAX-this: StdTree_NodeCtor_Val24_Isnil29_EaxThis_Inferred (0x00409880).
// Store layout ≡ inlined path in FUN_005a2de0 (distinct VA; do not merge).
//
// Dual: reviews/A|B_aa_004098d0_StdTree_NodeCtor_Val24_Isnil29_Thiscall_Inferred.md

#include <cstdint>

struct NodeIsnil29_Val24 {
  NodeIsnil29_Val24* left;     // +0x00
  NodeIsnil29_Val24* parent;   // +0x04
  NodeIsnil29_Val24* right;    // +0x08
  // +0x0C unused in construct path
  std::uint32_t val[6];        // +0x10 .. +0x27  (Val24 / 0x18 bytes)
  std::uint8_t color;          // +0x28
  std::uint8_t isnil;          // +0x29
  // pad to 0x30 allocation
};

// __thiscall RET 0x14
extern "C" void __thiscall StdTree_NodeCtor_Val24_Isnil29_Thiscall_Inferred(
    NodeIsnil29_Val24* self,
    NodeIsnil29_Val24* left,
    NodeIsnil29_Val24* parent,
    NodeIsnil29_Val24* right,
    const std::uint32_t* value6,
    std::uint8_t color)
{
  self->left = left;
  self->parent = parent;
  self->right = right;
  self->val[0] = value6[0];
  self->val[1] = value6[1];
  self->val[2] = value6[2];
  self->val[3] = value6[3];
  self->val[4] = value6[4];
  self->val[5] = value6[5];
  self->color = color;
  self->isnil = 0;
}

// Scaffold alias
extern "C" void __thiscall FUN_004098d0(
    NodeIsnil29_Val24* self,
    NodeIsnil29_Val24* left,
    NodeIsnil29_Val24* parent,
    NodeIsnil29_Val24* right,
    const std::uint32_t* value6,
    std::uint8_t color)
{
  StdTree_NodeCtor_Val24_Isnil29_Thiscall_Inferred(
      self, left, parent, right, value6, color);
}
