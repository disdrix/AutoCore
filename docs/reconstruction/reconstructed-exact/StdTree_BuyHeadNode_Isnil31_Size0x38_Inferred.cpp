// =============================================================================
// StdTree_BuyHeadNode_Isnil31_Size0x38_Inferred  (FUN_00409180)
// -----------------------------------------------------------------------------
// Stable ID: aa_00409180
// Address:   0x00409180–0x00409209 exclusive (137 B / 0x89)
// System:    MSVC std::_Tree head/sentinel alloc — isnil@+0x31 family, size 0x38
// Generated: 2026-08-04 WQ9J-F dual seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Allocate one 0x38 tree node and zero L/P/R, set color=black, isnil=0.
//   Tree ctor (sole caller FUN_00405f20) completes the head: isnil=1,
//   self-link L/P/R, host size@+8=0.
//
// ABI: no stack args; bare RET (C3); EAX = node*.
// Caller (1): FUN_00405f20 @ 0x00405f3a.
// Distinct from isnil29 head 0x00408a30 (size 0x30) and isnil21 empty 0x004088f0.
// Reject scaffold Named_CalleeOf_*Client_Constructor* plate.
//
// Dual: reviews/A|B_aa_00409180_StdTree_BuyHeadNode_Isnil31_Size0x38_Inferred.md

#include <cstdint>

struct NodeIsnil31_Size0x38 {
  NodeIsnil31_Size0x38* left;     // +0x00
  NodeIsnil31_Size0x38* parent;   // +0x04
  NodeIsnil31_Size0x38* right;    // +0x08
  // +0x0C .. +0x2F value region (Val36) — not written by this unit
  std::uint8_t color;             // +0x30  (forced 1 = black)
  std::uint8_t isnil;             // +0x31  (forced 0 here; caller sets 1 for head)
  // pad to 0x38
};

// CRT
extern "C" void* operator_new(std::size_t size);

// no stack args; returns node in EAX
extern "C" NodeIsnil31_Size0x38* StdTree_BuyHeadNode_Isnil31_Size0x38_Inferred(void)
{
  // SEH frame omitted in plate (present in retail: ExceptionList / LAB_009bc670).
  auto* node = static_cast<NodeIsnil31_Size0x38*>(operator_new(0x38));

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
extern "C" NodeIsnil31_Size0x38* FUN_00409180(void)
{
  return StdTree_BuyHeadNode_Isnil31_Size0x38_Inferred();
}
