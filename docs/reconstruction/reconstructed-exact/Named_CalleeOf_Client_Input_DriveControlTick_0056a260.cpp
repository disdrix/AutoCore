// =============================================================================
// Named_CalleeOf_Client_Input_DriveControlTick_0056a260 — superseded alias
// -----------------------------------------------------------------------------
// Prefer: Weapon_SetFireFlagPair_Inferred @ 0x0056a260 (aa_0056a260)
// Parent-seed name kept for link stability only. Dual A/B 2026-07-29.
// =============================================================================

#include <cstdint>

void __thiscall Named_CalleeOf_Client_Input_DriveControlTick_0056a260(int param_1, char param_2)
{
    auto* const base = reinterpret_cast<std::uint8_t*>(param_1);
    const std::uint8_t value = static_cast<std::uint8_t>(param_2);
    const std::uint8_t oldTwin = *(base + 0xC8);
    *(base + 0xC7) = value;
    if (oldTwin != value) {
        *(base + 0xC8) = value;
    }
}
