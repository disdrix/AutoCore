// =============================================================================
// FUN_0051cb40  — alias for Map_EraseNode
// Stable ID: aa_0051cb40  |  VA: 0x0051cb40
// See Map_EraseNode.cpp for sealed body + dual notes.
// =============================================================================

#include <cstdint>

struct MapHead;
struct TreeNode;

extern void __thiscall Map_EraseNode(MapHead* map, TreeNode** pOutIt, TreeNode* pNode);

void __thiscall FUN_0051cb40(MapHead* map, TreeNode** pOutIt, TreeNode* pNode)
{
  Map_EraseNode(map, pOutIt, pNode);
}
