// =============================================================================
// FUN_0051c880  — alias for Map_EraseNode_Isnil1d_Inferred
// Stable ID: aa_0051c880  |  VA: 0x0051c880
// See Map_EraseNode_Isnil1d_Inferred.cpp for sealed body + dual notes.
// =============================================================================

#include <cstdint>

struct MapHead;
struct TreeNode_Isnil1d;

extern void __thiscall Map_EraseNode_Isnil1d_Inferred(
    MapHead* map, TreeNode_Isnil1d** pOutIt, TreeNode_Isnil1d* pNode);

void __thiscall FUN_0051c880(
    MapHead* map, TreeNode_Isnil1d** pOutIt, TreeNode_Isnil1d* pNode)
{
  Map_EraseNode_Isnil1d_Inferred(map, pOutIt, pNode);
}
