// =============================================================================
// FUN_0052b350  (Ghidra symbol twin)
// -----------------------------------------------------------------------------
// Stable ID: aa_0052b350
// Address:   0x0052b350–0x0052b388 inclusive (57 B / 0x39)
// Canonical: CVOGCharacter_RewardInventoryList_PushBack_Inferred
// System:    missions-progression
// Generated: 2026-08-05 MEGA-013 dual seal (body ≡ 2026-07-23 raw CF)
// Exactness: Behavior-preserving rewrite. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================

#include <cstdint>

// Forward to named reconstruction (same ABI / CF).
extern "C" void __thiscall CVOGCharacter_RewardInventoryList_PushBack_Inferred(
    void *this_owner,
    std::uint32_t value);

extern "C" void __thiscall FUN_0052b350(void *this_owner, std::uint32_t value)
{
  CVOGCharacter_RewardInventoryList_PushBack_Inferred(this_owner, value);
}
