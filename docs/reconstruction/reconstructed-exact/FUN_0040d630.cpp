// =============================================================================
// FUN_0040d630  (scaffold twin → StdTree_FreeSubtree_Val12)
// -----------------------------------------------------------------------------
// Stable ID: aa_0040d630
// Address:   0x0040d630  (autoassault.exe, image base 0x400000)
// Wave:      W31-A OWN-ONLY dual 2026-07-29
// Exactness: Twin of StdTree_FreeSubtree_Val12.cpp (named plate is authoritative clean).
// =============================================================================

#include <cstdint>

struct StdTreeNode_Val12;

extern "C" void __fastcall StdTree_FreeSubtree_Val12(void* tree_base,
                                                     StdTreeNode_Val12* node);

extern "C" void __fastcall FUN_0040d630(void* tree_base, StdTreeNode_Val12* node)
{
  StdTree_FreeSubtree_Val12(tree_base, node);
}
