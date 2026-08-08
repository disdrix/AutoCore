// =============================================================================
// FUN_0051bbc0  (clean twin — Ghidra name)
// -----------------------------------------------------------------------------
// Stable ID: aa_0051bbc0
// Canonical: Map_FreeSubtree_Isnil29
// Dual A/B:  2026-08-04 WQ9E-H
// Exactness: Byte-corrected (decompiler left-walk incomplete).
// =============================================================================

#include <cstdint>

struct MapNode_Isnil29;

extern "C" void __fastcall Map_FreeSubtree_Isnil29(void *tree_base,
                                                   MapNode_Isnil29 *node);

extern "C" void __fastcall FUN_0051bbc0(void *tree_base, MapNode_Isnil29 *node)
{
  Map_FreeSubtree_Isnil29(tree_base, node);
}
