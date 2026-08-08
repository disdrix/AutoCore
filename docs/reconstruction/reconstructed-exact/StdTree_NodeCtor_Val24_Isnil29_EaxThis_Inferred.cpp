// =============================================================================
// StdTree_NodeCtor_Val24_Isnil29_EaxThis_Inferred  (FUN_00409880)
// -----------------------------------------------------------------------------
// Stable ID: aa_00409880
// Address:   0x00409880–0x004098c4 inclusive (69 B / 0x45); exclusive end 0x004098c5
// System:    MSVC std::_Tree node construct — Val24 payload, isnil@+0x29
// Generated: 2026-08-04 WQ9J-H dual seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Construct one red-black tree node in place (no allocation): links + 24-byte
//   value + color + isnil=0. Called from SEH buynode FUN_00404180 after
//   operator_new(0x30); that buy is used by insert/rebalance FUN_004069f0.
//
// ABI: __usercall — node@<eax>, value*@<ecx>, left@<edx>, parent/right/color stack;
//      RET 0xC. Ghidra labels this as incomplete __fastcall with in_EAX.
// Twin thiscall: StdTree_NodeCtor_Val24_Isnil29_Thiscall_Inferred (0x004098d0).
//
// Dual: reviews/A|B_aa_00409880_StdTree_NodeCtor_Val24_Isnil29_EaxThis_Inferred.md

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

// __usercall node@<eax>(value*@<ecx>, left@<edx>, parent, right, color) RET 0xC
// Represented as free function with explicit node* for plate readability.
extern "C" void StdTree_NodeCtor_Val24_Isnil29_EaxThis_Inferred(
    NodeIsnil29_Val24* node,          // EAX
    const std::uint32_t* value6,      // ECX
    NodeIsnil29_Val24* left,          // EDX
    NodeIsnil29_Val24* parent,        // stack +0
    NodeIsnil29_Val24* right,         // stack +4
    std::uint8_t color)               // stack +8
{
  node->left = left;
  node->parent = parent;
  node->right = right;
  node->val[0] = value6[0];
  node->val[1] = value6[1];
  node->val[2] = value6[2];
  node->val[3] = value6[3];
  node->val[4] = value6[4];
  node->val[5] = value6[5];
  node->color = color;
  node->isnil = 0;
}

// Scaffold alias
extern "C" void FUN_00409880(
    NodeIsnil29_Val24* node,
    const std::uint32_t* value6,
    NodeIsnil29_Val24* left,
    NodeIsnil29_Val24* parent,
    NodeIsnil29_Val24* right,
    std::uint8_t color)
{
  StdTree_NodeCtor_Val24_Isnil29_EaxThis_Inferred(
      node, value6, left, parent, right, color);
}
