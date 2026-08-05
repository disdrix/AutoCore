// =============================================================================
// FUN_005ae220 — scaffold alias → StdTree_Buynode_Val12
// -----------------------------------------------------------------------------
// Stable ID: aa_005ae220
// Address:   0x005ae220
// See:       StdTree_Buynode_Val12.cpp (W24-I dual seal)
// =============================================================================

#include <cstdint>

struct StdTreeNode_Val12;

extern "C" StdTreeNode_Val12* __stdcall StdTree_Buynode_Val12(
    StdTreeNode_Val12* left,
    StdTreeNode_Val12* parent,
    StdTreeNode_Val12* right,
    const uint32_t* value3,
    uint8_t color);

extern "C" StdTreeNode_Val12* __stdcall FUN_005ae220(
    StdTreeNode_Val12* left,
    StdTreeNode_Val12* parent,
    StdTreeNode_Val12* right,
    const uint32_t* value3,
    uint8_t color)
{
    return StdTree_Buynode_Val12(left, parent, right, value3, color);
}
