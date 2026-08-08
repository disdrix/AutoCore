// =============================================================================
// StdTree_Buynode_Val32_Isnil31_Inferred  (FUN_00403f30)
// -----------------------------------------------------------------------------
// Stable ID: aa_00403f30
// Address:   0x00403f30–0x00403fb2 exclusive (130 B / 0x82)
// System:    MSVC std::_Tree node buy — Val32 payload, isnil@+0x31, size 0x38
// Generated: 2026-08-05 MEGA-048 dual seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Allocate one red-black tree node (size 0x38) and construct links + 32-byte
//   value + color + isnil=0. Shared buynode for insert/rebalance residual
//   FUN_00403250 (isnil31 family under NotifyActiveMissionChanged chain).
//
// ABI: __stdcall; 5 stack args; RET 0x14; EAX = node* | null.
// Ctor helper: FUN_00404360 (EAX=this; ECX=left; EDX=parent; stack right/val/color; RET 0xC).
// Distinct from isnil29 Val24 buynode 0x00407e30 and BuyHead 0x00409180.
// Reject scaffold Named_CalleeOf_*NotifyActiveMission*.
//
// Dual: reviews/A|B_aa_00403f30_StdTree_Buynode_Val32_Isnil31_Inferred.md

#include <cstdint>

struct NodeIsnil31_Size0x38 {
  NodeIsnil31_Size0x38* left;     // +0x00
  NodeIsnil31_Size0x38* parent;   // +0x04
  NodeIsnil31_Size0x38* right;    // +0x08
  // +0x0C unused by construct path
  std::uint32_t val[8];           // +0x10 .. +0x2F  (Val32 / 0x20 bytes)
  std::uint8_t color;             // +0x30  (0=red, 1=black)
  std::uint8_t isnil;             // +0x31
  // pad to 0x38
};

// UnOWN: node construct. Live VA 0x00404360; RET 0xC.
// Retail ABI: EAX=this, ECX=left, EDX=parent, stack right/value/color.
// Plate models as explicit this* for readability (not a bit-exact calling-convention claim).
extern "C" void FUN_00404360(
    NodeIsnil31_Size0x38* self,
    NodeIsnil31_Size0x38* left,
    NodeIsnil31_Size0x38* parent,
    NodeIsnil31_Size0x38* right,
    const std::uint32_t* value8,
    std::uint8_t color);

// CRT
extern "C" void* operator_new(std::size_t size);

// __stdcall RET 0x14
extern "C" NodeIsnil31_Size0x38* __stdcall StdTree_Buynode_Val32_Isnil31_Inferred(
    NodeIsnil31_Size0x38* left,
    NodeIsnil31_Size0x38* parent,
    NodeIsnil31_Size0x38* right,
    const std::uint32_t* value8,
    std::uint8_t color)
{
  // SEH frame omitted in plate (present in retail: ExceptionList / LAB_009bc781).
  auto* node = static_cast<NodeIsnil31_Size0x38*>(operator_new(0x38));
  if (node != nullptr) {
    // Retail: MOV EAX,node; ECX=left; EDX=parent; PUSH color/value/right; CALL 00404360
    FUN_00404360(node, left, parent, right, value8, color);
    // Ctor body (evidence): *node=L/P/R; REP MOVSD 8 dwords @+0x10; color@+0x30; isnil=0@+0x31
  }
  return node;
}

// Scaffold alias — Ghidra symbol
extern "C" NodeIsnil31_Size0x38* __stdcall FUN_00403f30(
    NodeIsnil31_Size0x38* left,
    NodeIsnil31_Size0x38* parent,
    NodeIsnil31_Size0x38* right,
    const std::uint32_t* value8,
    std::uint8_t color)
{
  return StdTree_Buynode_Val32_Isnil31_Inferred(left, parent, right, value8, color);
}
