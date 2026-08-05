// =============================================================================
// FUN_0056a260 — alias plate
// -----------------------------------------------------------------------------
// Canonical clean: Weapon_SetFireFlagPair_Inferred.cpp
// Stable ID: aa_0056a260  |  VA: 0x0056a260
// This file retained so older links resolve; body matches dual A/B 2026-07-29.
// =============================================================================

#include <cstdint>

// See Weapon_SetFireFlagPair_Inferred.cpp for full plate / callers / siblings.

void __thiscall FUN_0056a260(int param_1, char param_2)
{
    auto* const base = reinterpret_cast<std::uint8_t*>(param_1);
    const std::uint8_t value = static_cast<std::uint8_t>(param_2);
    const std::uint8_t oldTwin = *(base + 0xC8);
    *(base + 0xC7) = value;
    if (oldTwin != value) {
        *(base + 0xC8) = value;
    }
}
