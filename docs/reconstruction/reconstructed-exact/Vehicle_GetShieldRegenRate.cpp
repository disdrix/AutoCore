// =============================================================================
// Vehicle_GetShieldRegenRate
// -----------------------------------------------------------------------------
// Purpose:  Read the equipped race-item's shield regen rate (points per pulse
//           after empty-shield debounce).
//
// Address:  0x004fb600  (autoassault.exe, image base 0x400000)
// Stable:   aa_004fb600
// System:   vehicle combat pools
//
// Convention: MSVC __fastcall / __thiscall (vehicle in ECX)
//
// Algorithm:
//   pRaceItem = vehicle->pRaceItem (+0x270)
//   if null: return 0
//   walk dual-base → clonebase (+0xAC) → subrecord (+0x3C) → short @ +0x4B6
//
// Sibling: Vehicle_GetHpRegenRate (0x004fb630) uses short @ +0x3FA.
//
// Exactness: Behavior-preserving rewrite of raw decompile.
// =============================================================================

#include <cstdint>

static constexpr int kOffRaceItem = 0x270;

int __fastcall Vehicle_GetShieldRegenRate(void* pVehicle)
{
    void* pRaceItem =
        *reinterpret_cast<void**>(
            reinterpret_cast<std::uint8_t*>(pVehicle) + kOffRaceItem);
    if (pRaceItem == nullptr) {
        return 0;
    }

    const int dualBaseOff =
        *reinterpret_cast<int*>(
            *reinterpret_cast<int*>(
                reinterpret_cast<std::uint8_t*>(pRaceItem) + 4) +
            4);
    int* pCloneBase = *reinterpret_cast<int**>(
        reinterpret_cast<std::uint8_t*>(pRaceItem) + dualBaseOff + 0xAC);
    int* pSub = *reinterpret_cast<int**>(
        reinterpret_cast<std::uint8_t*>(pCloneBase) + 0x3C);

    // RaceShieldRegenRate — short at sub+0x4B6
    return static_cast<int>(
        *reinterpret_cast<std::int16_t*>(
            reinterpret_cast<std::uint8_t*>(pSub) + 0x4B6));
}
