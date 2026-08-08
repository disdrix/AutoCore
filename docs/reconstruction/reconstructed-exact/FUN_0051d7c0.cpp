// =============================================================================
// FUN_0051d7c0  (scaffold alias — prefer Map_EraseRange_Isnil15.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_0051d7c0
// Address:   0x0051d7c0–0x0051d873 inclusive (180 B)
// Canonical: Map_EraseRange_Isnil15
// Wave:      2026-08-04 WQ9E-J OWN dual
// =============================================================================

#include <cstdint>

struct MapHead_Isnil15 {
  void* head;
  std::uint32_t size;
};

struct TreeNode_Isnil15 {
  TreeNode_Isnil15* left;
  TreeNode_Isnil15* parent;
  TreeNode_Isnil15* right;
};

extern "C" void FUN_0051be50(TreeNode_Isnil15* root);
extern "C" void __thiscall FUN_0051ce00(MapHead_Isnil15* map,
                                        TreeNode_Isnil15** pOutIt,
                                        TreeNode_Isnil15* pNode);
extern "C" void __thiscall Map_EraseRange_Isnil15(
    MapHead_Isnil15* map,
    TreeNode_Isnil15** out_it,
    TreeNode_Isnil15* first,
    TreeNode_Isnil15* last);

void __thiscall FUN_0051d7c0(
    MapHead_Isnil15* map,
    TreeNode_Isnil15** out_it,
    TreeNode_Isnil15* first,
    TreeNode_Isnil15* last)
{
  Map_EraseRange_Isnil15(map, out_it, first, last);
}
