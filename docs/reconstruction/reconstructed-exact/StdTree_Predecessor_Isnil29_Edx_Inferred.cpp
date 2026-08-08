// =============================================================================
// StdTree_Predecessor_Isnil29_Edx_Inferred  (FUN_00409820)
// -----------------------------------------------------------------------------
// Stable ID: aa_00409820
// Address:   0x00409820–0x00409870 inclusive (81 B / 0x51); pad CC to 0x00409880
// System:    shared client::stdtree (MSVC _Tree predecessor / iterator--)
// Generated: 2026-08-05 WQ9J-G dual seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: In-place tree/map iterator predecessor (operator-- / _Dec).
//   Node layout: +0 left, +4 parent, +8 right, +0x29 is_nil.
//   Twin: StdTree_Predecessor_Isnil29_Inferred (aa_004cb4f0, ECX ABI).
//   Peer algs: Map_Tree_Predecessor_Isnil15_Edx; successor Isnil31 (00408590).
//
// ABI: EDX = Node**; ECX unused; void; bare RET (C3) x3 exits.
//      Call site LEA EDX,[stack_it] then CALL (FUN_00405bd0 @ 0x00405c33).
//
// Dual: reviews/A|B_aa_00409820_StdTree_Predecessor_Isnil29_Edx_Inferred.md

#include <cstdint>

struct StdTreeNode_Isnil29 {
  StdTreeNode_Isnil29* left;    // +0x00
  StdTreeNode_Isnil29* parent;  // +0x04
  StdTreeNode_Isnil29* right;   // +0x08
  // value payload begins +0x0C (not accessed here)
  // color @ +0x28 (layout context; not accessed)
  // isnil @ +0x29
};

// Retail: EDX = it; bare C3; void. Ghidra: __fastcall (ECX phantom, EDX real).
extern "C" void StdTree_Predecessor_Isnil29_Edx_Inferred(
    StdTreeNode_Isnil29** it /*EDX*/)
{
  StdTreeNode_Isnil29* node = *it;
  if (*(char *)((int)node + 0x29) != '\0') {
    // end/header → rightmost via header.right
    *it = node->right;
    return;
  }

  StdTreeNode_Isnil29* left = node->left;
  if (*(char *)((int)left + 0x29) == '\0') {
    StdTreeNode_Isnil29* p = left;
    while (*(char *)((int)p->right + 0x29) == '\0') {
      p = p->right;
    }
    *it = p;
    return;
  }

  StdTreeNode_Isnil29* parent = node->parent;
  if (*(char *)((int)parent + 0x29) == '\0') {
    while (*(char *)((int)parent + 0x29) == '\0' && *it == parent->left) {
      *it = parent;
      parent = parent->parent;
    }
    if (*(char *)((int)parent + 0x29) == '\0') {
      *it = parent;
    }
  }
}

// Scaffold alias (Ghidra FUN name)
extern "C" void __fastcall FUN_00409820(
    std::uint32_t /*ecx unused*/,
    StdTreeNode_Isnil29** it /*EDX*/)
{
  (void)0; /* ecx phantom */
  StdTree_Predecessor_Isnil29_Edx_Inferred(it);
}
