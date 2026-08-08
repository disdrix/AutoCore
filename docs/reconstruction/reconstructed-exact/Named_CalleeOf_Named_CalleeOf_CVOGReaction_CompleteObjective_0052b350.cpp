// =============================================================================
// RETIRED scaffold name — MEGA-013 2026-08-05
// -----------------------------------------------------------------------------
// Was: Named_CalleeOf_Named_CalleeOf_CVOGReaction_CompleteObjective_0052b350
// Now: CVOGCharacter_RewardInventoryList_PushBack_Inferred
// Stable ID: aa_0052b350  VA: 0x0052b350
// See: reconstructed-exact/CVOGCharacter_RewardInventoryList_PushBack_Inferred.cpp
//      docs/agents/task-dual-ab-0052b350-mega-013-report.md
// =============================================================================

#include <cstdint>

extern "C" void __thiscall CVOGCharacter_RewardInventoryList_PushBack_Inferred(
    void *this_owner,
    std::uint32_t value);

// Deprecated alias — do not use in new ports.
void __thiscall Named_CalleeOf_Named_CalleeOf_CVOGReaction_CompleteObjective_0052b350(
    void *this_owner,
    std::uint32_t value)
{
  CVOGCharacter_RewardInventoryList_PushBack_Inferred(this_owner, value);
}
