// =============================================================================
// StdTree_Buynode_Val16_Isnil21_Inferred  (FUN_00408990)
// -----------------------------------------------------------------------------
// Stable ID: aa_00408990
// Address:   0x00408990–0x00408a13 inclusive (132 B / 0x84)
// System:    MSVC std::_Tree node buy — Val16 payload, isnil@+0x21
// Generated: 2026-08-04 WQ9H-J dual seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Allocate one red-black tree node (size 0x28) and construct links + 16-byte
//   value + color + isnil=0. Shared buynode for insert/rebalance FUN_00407200.
//
// ABI: __stdcall; 5 stack args; RET 0x14; EAX = node* | null.
// Ctor helper: FUN_004099b0 (thiscall on node; also RET 0x14).
// Distinct from Val24/isnil29 0x30 buynodes (00407e30 / 005a2de0).
//
// Dual: reviews/A|B_aa_00408990_StdTree_Buynode_Val16_Isnil21_Inferred.md

#include <cstdint>

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

// UnOWN: node construct (thiscall). Live VA 0x004099b0.
extern "C" void __thiscall FUN_004099b0(
    NodeIsnil21* self,
    NodeIsnil21* left,
    NodeIsnil21* parent,
    NodeIsnil21* right,
    const std::uint32_t* value4,
    std::uint8_t color);

// CRT
extern "C" void* operator_new(std::size_t size);

// __stdcall RET 0x14
extern "C" NodeIsnil21* __stdcall StdTree_Buynode_Val16_Isnil21_Inferred(
    NodeIsnil21* left,
    NodeIsnil21* parent,
    NodeIsnil21* right,
    const std::uint32_t* value4,
    std::uint8_t color)
{
  // SEH frame omitted in plate (present in retail: ExceptionList / LAB_009bc6b1).
  auto* node = static_cast<NodeIsnil21*>(operator_new(0x28));
  if (node != nullptr) {
    FUN_004099b0(node, left, parent, right, value4, color);
  }
  return node;
}

// Scaffold alias
extern "C" NodeIsnil21* __stdcall FUN_00408990(
    NodeIsnil21* left,
    NodeIsnil21* parent,
    NodeIsnil21* right,
    const std::uint32_t* value4,
    std::uint8_t color)
{
  return StdTree_Buynode_Val16_Isnil21_Inferred(left, parent, right, value4, color);
}
