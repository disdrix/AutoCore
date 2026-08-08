// =============================================================================
// StdTree_NodeCtor_Val32_Isnil31_EaxThis_Inferred  (FUN_00404360)
// -----------------------------------------------------------------------------
// Stable ID: aa_00404360
// Address:   0x00404360–0x0040438C exclusive (44 B / 0x2C); epilogue RET 0xC
// System:    MSVC std::_Tree node construct — Val32 payload, isnil@+0x31
// Generated: 2026-08-05 R10-021 dual seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Construct one red-black tree node in place (no allocation): links + 32-byte
//   value + color + isnil=0. Called from SEH buynode FUN_00403f30 /
//   StdTree_Buynode_Val32_Isnil31_Inferred after operator_new(0x38); that buy
//   is used by residual insert/rebalance FUN_00403250 (isnil31 family).
//
// ABI: __usercall — node@<eax>, left@<ecx>, parent@<edx>, right/value*/color stack;
//      RET 0xC. Ghidra labels incomplete __fastcall with phantom in_EAX.
//
// Dual: reviews/A|B_aa_00404360_StdTree_NodeCtor_Val32_Isnil31_EaxThis_Inferred.md

#include <cstdint>

struct NodeIsnil31_Val32 {
  NodeIsnil31_Val32* left;     // +0x00
  NodeIsnil31_Val32* parent;   // +0x04
  NodeIsnil31_Val32* right;    // +0x08
  // +0x0C unused in construct path
  std::uint32_t val[8];        // +0x10 .. +0x2F  (Val32 / 0x20 bytes)
  std::uint8_t color;          // +0x30
  std::uint8_t isnil;          // +0x31
  // pad to 0x38 allocation (parent buynode)
};

// __usercall node@<eax>(left@<ecx>, parent@<edx>, right, value*, color) RET 0xC
// Represented as free function with explicit node* for plate readability.
extern "C" void StdTree_NodeCtor_Val32_Isnil31_EaxThis_Inferred(
    NodeIsnil31_Val32* node,          // EAX
    NodeIsnil31_Val32* left,          // ECX
    NodeIsnil31_Val32* parent,        // EDX
    NodeIsnil31_Val32* right,         // stack +0
    const std::uint32_t* value8,      // stack +4
    std::uint8_t color)               // stack +8
{
  node->left = left;
  node->parent = parent;
  node->right = right;
  // REP MOVSD ECX=8 → +0x10
  node->val[0] = value8[0];
  node->val[1] = value8[1];
  node->val[2] = value8[2];
  node->val[3] = value8[3];
  node->val[4] = value8[4];
  node->val[5] = value8[5];
  node->val[6] = value8[6];
  node->val[7] = value8[7];
  node->color = color;   // +0x30
  node->isnil = 0;       // +0x31
}

// Scaffold alias
extern "C" void FUN_00404360(
    NodeIsnil31_Val32* node,
    NodeIsnil31_Val32* left,
    NodeIsnil31_Val32* parent,
    NodeIsnil31_Val32* right,
    const std::uint32_t* value8,
    std::uint8_t color)
{
  StdTree_NodeCtor_Val32_Isnil31_EaxThis_Inferred(
      node, left, parent, right, value8, color);
}
