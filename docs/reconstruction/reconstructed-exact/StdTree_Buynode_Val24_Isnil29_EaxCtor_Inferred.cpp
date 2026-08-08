// =============================================================================
// StdTree_Buynode_Val24_Isnil29_EaxCtor_Inferred  (FUN_00404180)
// -----------------------------------------------------------------------------
// Stable ID: aa_00404180
// Address:   0x00404180–0x00404202 exclusive (130 B / 0x82)
// System:    MSVC std::_Tree node buy — Val24 payload, isnil@+0x29
// Generated: 2026-08-04 WQ9K-C dual seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Allocate one red-black tree node (size 0x30) and construct links + 0x18-byte
//   value + color + isnil=0 via EAX-this node ctor 0x00409880. Shared buynode
//   for insert path FUN_004069f0 (map/set too long + rebalance; color@+0x28).
//
// ABI: __stdcall; 5 stack args; RET 0x14; EAX = node* | null.
// Ctor helper: StdTree_NodeCtor_Val24_Isnil29_EaxThis_Inferred (0x00409880).
// Twin (thiscall ctor): StdTree_Buynode_Val24_Isnil29_Inferred (0x00407e30) — do not merge.
//
// Dual: reviews/A|B_aa_00404180_StdTree_Buynode_Val24_Isnil29_EaxCtor_Inferred.md

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

// Dualed WQ9J-H: EAX-this node construct. Live VA 0x00409880. RET 0xC.
extern "C" void StdTree_NodeCtor_Val24_Isnil29_EaxThis_Inferred(
    NodeIsnil29* /*eax*/ self,
    const std::uint32_t* /*ecx*/ value6,
    NodeIsnil29* /*edx*/ left,
    NodeIsnil29* parent,
    NodeIsnil29* right,
    std::uint8_t color);

// CRT
extern "C" void* operator_new(std::size_t size);

// __stdcall RET 0x14
extern "C" NodeIsnil29* __stdcall StdTree_Buynode_Val24_Isnil29_EaxCtor_Inferred(
    NodeIsnil29* left,
    NodeIsnil29* parent,
    NodeIsnil29* right,
    const std::uint32_t* value6,
    std::uint8_t color)
{
  // SEH frame omitted in plate (present in retail: ExceptionList / LAB_009bc701).
  auto* node = static_cast<NodeIsnil29*>(operator_new(0x30));
  if (node != nullptr) {
    // Retail: EAX=node, ECX=value6, EDX=left; stack parent/right/color
    StdTree_NodeCtor_Val24_Isnil29_EaxThis_Inferred(
        node, value6, left, parent, right, color);
  }
  return node;
}

// Scaffold alias
extern "C" NodeIsnil29* __stdcall FUN_00404180(
    NodeIsnil29* left,
    NodeIsnil29* parent,
    NodeIsnil29* right,
    const std::uint32_t* value6,
    std::uint8_t color)
{
  return StdTree_Buynode_Val24_Isnil29_EaxCtor_Inferred(
      left, parent, right, value6, color);
}
