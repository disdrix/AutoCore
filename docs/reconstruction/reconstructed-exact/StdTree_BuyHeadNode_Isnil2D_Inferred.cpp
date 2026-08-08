// =============================================================================
// StdTree_BuyHeadNode_Isnil2D_Inferred  (FUN_00409780)
// -----------------------------------------------------------------------------
// Stable ID: aa_00409780
// Address:   0x00409780–0x00409809 inclusive (138 B / 0x8A)
// System:    MSVC std::_Tree head/sentinel alloc — isnil@+0x2d family, size 0x30
// Generated: 2026-08-05 WQ9J-G dual seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Allocate one 0x30 tree node and zero L/P/R, set color=black, isnil=0.
//   Tree ctors complete the head: isnil=1, self-link L/P/R, host size=0.
//
// ABI: no stack args; bare RET; EAX = node*.
// Caller (1): FUN_00406190 @ 0x004061aa.
// Distinct from isnil29 BuyHeadNode (00408a30, color@+0x28/isnil@+0x29)
// and Val16/isnil21 0x28 empty buynode (004088f0).
//
// Dual: reviews/A|B_aa_00409780_StdTree_BuyHeadNode_Isnil2D_Inferred.md

#include <cstdint>

struct NodeIsnil2D {
  NodeIsnil2D* left;     // +0x00
  NodeIsnil2D* parent;   // +0x04
  NodeIsnil2D* right;    // +0x08
  // +0x0C .. +0x2B value region (Val32) — not written by this unit
  std::uint8_t color;    // +0x2c  (forced 1 = black)
  std::uint8_t isnil;    // +0x2d  (forced 0 here; callers set 1 for head)
  // pad to 0x30
};

// CRT
extern "C" void* operator_new(std::size_t size);

// no stack args; returns node in EAX
extern "C" NodeIsnil2D* StdTree_BuyHeadNode_Isnil2D_Inferred(void)
{
  // SEH frame omitted in plate (present in retail: ExceptionList / LAB_009bc660).
  auto* node = static_cast<NodeIsnil2D*>(operator_new(0x30));

  // Retail uses MSVC field-address null checks; semantic intent:
  if (node != nullptr) {
    node->left = nullptr;
    node->parent = nullptr;
    node->right = nullptr;
    node->color = 1;
    node->isnil = 0;
  }

  return node;
}

// Scaffold alias — Ghidra may label void; machine returns EAX=node
extern "C" NodeIsnil2D* FUN_00409780(void)
{
  return StdTree_BuyHeadNode_Isnil2D_Inferred();
}
