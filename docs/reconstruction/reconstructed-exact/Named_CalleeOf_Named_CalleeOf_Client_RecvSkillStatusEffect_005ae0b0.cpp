// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RecvSkillStatusEffect_005ae0b0
// -----------------------------------------------------------------------------
// Stable ID: aa_005ae0b0
// Address:   0x005ae0b0  (autoassault.exe, image base 0x400000)
// System:    std red-black tree / map iterator (Val12)
// Note:      LEGACY narrow seed alias — prefer StdTree_Inc_Val12.
// Refined:   2026-07-29 W28-N (forwards to structural name)
// =============================================================================

#include <cstdint>

struct StdTreeNode_Val12 {
    StdTreeNode_Val12* left;
    StdTreeNode_Val12* parent;
    StdTreeNode_Val12* right;
    uint32_t value[3];
    uint8_t  color;
    uint8_t  isnil;
    uint8_t  _pad[2];
};

extern "C" void __fastcall StdTree_Inc_Val12(StdTreeNode_Val12** it);

extern "C" void __fastcall
Named_CalleeOf_Named_CalleeOf_Client_RecvSkillStatusEffect_005ae0b0(
    StdTreeNode_Val12** it)
{
    StdTree_Inc_Val12(it);
}
