// =============================================================================
// RETIRED scaffold — Named_CalleeOf_Named_gfxUIWindow_00440d20
// -----------------------------------------------------------------------------
// Stable ID: aa_00440d20
// Address:   0x00440d20
// Wave:      MEGA-132 2026-08-05 — scaffold retired; use named clean
// =============================================================================
//
// This file is intentionally a thin redirect. The seed name
// `Named_CalleeOf_Named_gfxUIWindow_00440d20` was parent-chain only and is not
// the sealed algorithm name.
//
// Canonical clean:
//   StdTree_FreeSubtree_Isnil11_Inferred.cpp
// Ghidra twin:
//   FUN_00440d20.cpp
// =============================================================================

#include <cstdint>

struct TreeNode_Isnil11;

extern "C" void __fastcall StdTree_FreeSubtree_Isnil11_Inferred(
    void *tree_base, TreeNode_Isnil11 *node);

// Deprecated alias — do not port under this name.
extern "C" void __fastcall Named_CalleeOf_Named_gfxUIWindow_00440d20(
    void *tree_base, TreeNode_Isnil11 *node)
{
  StdTree_FreeSubtree_Isnil11_Inferred(tree_base, node);
}
