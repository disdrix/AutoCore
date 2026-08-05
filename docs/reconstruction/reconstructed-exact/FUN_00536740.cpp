// =============================================================================
// FUN_00536740  (alias scaffold — prefer CVOGCharacter_CompleteRegionMissions.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_00536740
// Address:   0x00536740  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-07-29 dual W18-J (supersedes 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Canonical named clean: reconstructed-exact/CVOGCharacter_CompleteRegionMissions.cpp
// Dual A/B: reviews/A_aa_00536740_* / B_aa_00536740_*
// =============================================================================

#include <cstdint>

// Forward to named reconstruction — keep Ghidra symbol as weak alias entry for tooling.
std::uint32_t __thiscall CVOGCharacter_CompleteRegionMissions(
    void *thisCharacter,
    std::uint32_t region,
    std::uint32_t pocket);

std::uint32_t __thiscall FUN_00536740(void *param_1, std::uint32_t param_2, std::uint32_t param_3)
{
    return CVOGCharacter_CompleteRegionMissions(param_1, param_2, param_3);
}
