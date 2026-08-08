// =============================================================================
// StdTree_Buynode_Val24_Isnil29_Inferred  (FUN_00407e30)
// -----------------------------------------------------------------------------
// Stable ID: aa_00407e30
// Address:   0x00407e30–0x00407eb4 exclusive (132 B / 0x84)
// System:    MSVC std::_Tree node buy — Val24 payload, isnil@+0x29
// Generated: 2026-08-04 WQ9F-B dual seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Allocate one red-black tree node (size 0x30) and construct links + 0x18-byte
//   value + color + isnil=0. Shared buynode for insert
//   StdTree_InsertAndRebalance_Isnil29_Inferred (0x00406c40).
//
// ABI: __stdcall; 5 stack args; RET 0x14; EAX = node* | null.
// Ctor helper: FUN_004098d0 (thiscall on node).
// Twin (no SEH, inlined ctor): FUN_005a2de0 — different VA; do not merge.
//
// Dual: reviews/A|B_aa_00407e30_StdTree_Buynode_Val24_Isnil29_Inferred.md

#include <cstdint>

struct NodeIsnil29 {
  NodeIsnil29* left;     // +0x00
  NodeIsnil29* parent;   // +0x04
  NodeIsnil29* right;    // +0x08
  // +0x0C unused in construct path
  std::uint32_t val[6];  // +0x10 .. +0x24  (Val24 / 0x18 bytes)
  std::uint8_t color;    // +0x28  (0=red, 1=black)
  std::uint8_t isnil;    // +0x29
  // pad to 0x30
};

// UnOWN: node construct (thiscall). Live VA 0x004098d0.
extern "C" void __thiscall FUN_004098d0(
    NodeIsnil29* self,
    NodeIsnil29* left,
    NodeIsnil29* parent,
    NodeIsnil29* right,
    const std::uint32_t* value6,
    std::uint8_t color);

// CRT
extern "C" void* operator_new(std::size_t size);

// __stdcall RET 0x14
extern "C" NodeIsnil29* __stdcall StdTree_Buynode_Val24_Isnil29_Inferred(
    NodeIsnil29* left,
    NodeIsnil29* parent,
    NodeIsnil29* right,
    const std::uint32_t* value6,
    std::uint8_t color)
{
  // SEH frame omitted in plate (present in retail: ExceptionList / LAB_009bc6e1).
  auto* node = static_cast<NodeIsnil29*>(operator_new(0x30));
  if (node != nullptr) {
    FUN_004098d0(node, left, parent, right, value6, color);
  }
  return node;
}

// Scaffold alias
extern "C" NodeIsnil29* __stdcall FUN_00407e30(
    NodeIsnil29* left,
    NodeIsnil29* parent,
    NodeIsnil29* right,
    const std::uint32_t* value6,
    std::uint8_t color)
{
  return StdTree_Buynode_Val24_Isnil29_Inferred(left, parent, right, value6, color);
}
