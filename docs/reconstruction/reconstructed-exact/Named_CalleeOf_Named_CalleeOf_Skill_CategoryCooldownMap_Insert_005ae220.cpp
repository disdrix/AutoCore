// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Skill_CategoryCooldownMap_Insert_005ae220
// Legacy auto-seed alias — MISLEADING as sole product role (multi-map buynode).
// Canonical: StdTree_Buynode_Val12 @ 0x005ae220 (aa_005ae220)
// =============================================================================

#include <cstdint>

struct StdTreeNode_Val12;

extern "C" StdTreeNode_Val12* __stdcall StdTree_Buynode_Val12(
    StdTreeNode_Val12* left,
    StdTreeNode_Val12* parent,
    StdTreeNode_Val12* right,
    const uint32_t* value3,
    uint8_t color);

extern "C" StdTreeNode_Val12* __stdcall
Named_CalleeOf_Named_CalleeOf_Skill_CategoryCooldownMap_Insert_005ae220(
    StdTreeNode_Val12* left,
    StdTreeNode_Val12* parent,
    StdTreeNode_Val12* right,
    const uint32_t* value3,
    uint8_t color)
{
    return StdTree_Buynode_Val12(left, parent, right, value3, color);
}
