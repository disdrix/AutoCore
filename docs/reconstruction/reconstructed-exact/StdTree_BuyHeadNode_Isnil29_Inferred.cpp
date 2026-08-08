// =============================================================================
// StdTree_BuyHeadNode_Isnil29_Inferred  (FUN_00408a30)
// -----------------------------------------------------------------------------
// Stable ID: aa_00408a30
// Address:   0x00408a30–0x00408ab9 inclusive (138 B / 0x8A)
// System:    MSVC std::_Tree head/sentinel alloc — isnil@+0x29 family, size 0x30
// Generated: 2026-08-04 WQ9H-J dual seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Allocate one 0x30 tree node and zero L/P/R, set color=black, isnil=0.
//   Tree ctors complete the head: isnil=1, self-link L/P/R, host size=0.
//
// ABI: no stack args; bare RET; EAX = node*.
// Callers (4): FUN_00405b40, FUN_00405e60, FUN_00405fb0, FUN_004d98f0.
// Distinct from Val16/isnil21 0x28 buynode (00408990) and Val24 buynode (00407e30).
//
// Dual: reviews/A|B_aa_00408a30_StdTree_BuyHeadNode_Isnil29_Inferred.md

#include <cstdint>

struct NodeIsnil29 {
  NodeIsnil29* left;     // +0x00
  NodeIsnil29* parent;   // +0x04
  NodeIsnil29* right;    // +0x08
  // +0x0C .. +0x27 value region (Val24) — not written by this unit
  std::uint8_t color;    // +0x28  (forced 1 = black)
  std::uint8_t isnil;    // +0x29  (forced 0 here; callers set 1 for head)
  // pad to 0x30
};

// CRT
extern "C" void* operator_new(std::size_t size);

// no stack args; returns node in EAX
extern "C" NodeIsnil29* StdTree_BuyHeadNode_Isnil29_Inferred(void)
{
  // SEH frame omitted in plate (present in retail: ExceptionList / LAB_009bc690).
  auto* node = static_cast<NodeIsnil29*>(operator_new(0x30));

  // Retail uses MSVC field-address null checks; semantic intent:
  if (node != nullptr) {
    node->left = nullptr;
  }
  // Odd: subsequent checks are on &fields (not node); if node==null they touch
  // absolute 4/8. Preserve shape by only writing when node non-null in clean plate
  // while documenting the raw form in annotated notes.
  if (node != nullptr) {
    node->parent = nullptr;
    node->right = nullptr;
    node->color = 1;
    node->isnil = 0;
  }

  return node;
}

// Scaffold alias — Ghidra may label void; machine returns EAX=node
extern "C" NodeIsnil29* FUN_00408a30(void)
{
  return StdTree_BuyHeadNode_Isnil29_Inferred();
}
