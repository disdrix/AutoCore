// =============================================================================
// StdTree_Buynode_Isnil21_Node0x24_Inferred  (FUN_005a4870)
// -----------------------------------------------------------------------------
// Stable ID: aa_005a4870
// Address:   0x005a4870–0x005a48f5 inclusive (134 B / 0x86)
// System:    MSVC std::_Tree node buy — isnil@+0x21 / node 0x24
// Generated: 2026-08-05 R13-008 dual seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Allocate one red-black tree node (size 0x24) and construct links + u32 key
//   + vector-like dword payload + color + isnil=0. Shared buynode for always-
//   insert FUN_005a4950 (dualed R12-033).
//
// ABI: __stdcall; 5 stack args; RET 0x14; EAX = node* | null.
// Payload helper: FUN_005a42d0 (thiscall on node+0x10; residual).
// Distinct from Val16/0x28 isnil21 buynode 00408990 and Val24/isnil29 0x30.
//
// Dual: reviews/A|B_aa_005a4870_StdTree_Buynode_Isnil21_Node0x24_Inferred.md

#include <cstdint>

struct VecDwordLike {
  // Live FUN_005a42d0 reads/writes begin/end/cap at +4/+8/+0xC of this object
  // (offset +0 may be proxy / unused on this path — residual).
  void* field0;   // +0x00 relative to payload base (node+0x10)
  void* begin;    // +0x04 → node+0x14
  void* end;      // +0x08 → node+0x18
  void* cap;      // +0x0C → node+0x1c
};

struct ValueU32Vec {
  std::uint32_t key;   // copied to node+0x0C
  VecDwordLike vec;    // copy-constructed at node+0x10 via FUN_005a42d0
};

struct NodeIsnil21_0x24 {
  NodeIsnil21_0x24* left;    // +0x00
  NodeIsnil21_0x24* parent;  // +0x04
  NodeIsnil21_0x24* right;   // +0x08
  std::uint32_t key;         // +0x0C
  VecDwordLike payload;      // +0x10 .. +0x1C
  std::uint8_t color;        // +0x20  (0=red, 1=black)
  std::uint8_t isnil;        // +0x21
  // size 0x24
};

// UnOWN: vector-like copy-construct at payload base. Live VA 0x005a42d0.
// thiscall: ECX = dest payload (node+0x10); stack = src VecDwordLike*.
extern "C" VecDwordLike* __thiscall FUN_005a42d0(
    VecDwordLike* self,
    const VecDwordLike* src);

// CRT
extern "C" void* operator_new(std::size_t size);

// __stdcall RET 0x14
extern "C" NodeIsnil21_0x24* __stdcall StdTree_Buynode_Isnil21_Node0x24_Inferred(
    NodeIsnil21_0x24* left,
    NodeIsnil21_0x24* parent,
    NodeIsnil21_0x24* right,
    const ValueU32Vec* value,
    std::uint8_t color)
{
  // SEH frame omitted in plate (present in retail: ExceptionList / LAB_009a6321).
  auto* node = static_cast<NodeIsnil21_0x24*>(operator_new(0x24));
  if (node != nullptr) {
    node->left = left;
    node->parent = parent;
    node->right = right;
    node->key = value->key;
    FUN_005a42d0(&node->payload, &value->vec);
    node->color = color;
    node->isnil = 0;
  }
  return node;
}

// Scaffold alias
extern "C" NodeIsnil21_0x24* __stdcall FUN_005a4870(
    NodeIsnil21_0x24* left,
    NodeIsnil21_0x24* parent,
    NodeIsnil21_0x24* right,
    const ValueU32Vec* value,
    std::uint8_t color)
{
  return StdTree_Buynode_Isnil21_Node0x24_Inferred(left, parent, right, value, color);
}
