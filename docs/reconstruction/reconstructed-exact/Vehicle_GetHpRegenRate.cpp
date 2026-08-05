// =============================================================================
// Vehicle_GetHpRegenRate
// -----------------------------------------------------------------------------
// Purpose:  Read the equipped race-item's HP regen rate (points per combat-pool
//           pulse). Used by CVOGHBRegeneration_OnHeartBeat / pool tick.
//
// Address:  0x004fb630  (autoassault.exe, image base 0x400000)
// Stable:   aa_004fb630
// System:   vehicle combat pools
//
// Convention: MSVC __fastcall / __thiscall (vehicle in ECX)
//
// Algorithm:
//   pRaceItem = vehicle->pRaceItem (+0x270)
//   if null: return 0
//   walk dual-base → clonebase (+0xAC) → subrecord (+0x3C) → short @ +0x3FA
//
// Sibling: Vehicle_GetShieldRegenRate (0x004fb600) uses short @ +0x4B6.
// Related: Creature_GetHpRegenFromEquippedRaceItem delegates here when vehicle
//          is present (else returns 1).
//
// Exactness: Behavior-preserving rewrite of raw decompile.
// =============================================================================

#include <cstdint>

// Minimal field view used by this getter.
struct VehicleCombatPools_Inferred {
    // ...
    // void* pRaceItem_Inferred; @ +0x270
};

static constexpr int kOffRaceItem = 0x270;

int __fastcall Vehicle_GetHpRegenRate(void* pVehicle)
{
    void* pRaceItem =
        *reinterpret_cast<void**>(
            reinterpret_cast<std::uint8_t*>(pVehicle) + kOffRaceItem);
    if (pRaceItem == nullptr) {
        return 0;
    }

    // Dual-base: clonebase* at (raceItem + *( *(raceItem+4)+4 ) + 0xAC)
    const int dualBaseOff =
        *reinterpret_cast<int*>(
            *reinterpret_cast<int*>(
                reinterpret_cast<std::uint8_t*>(pRaceItem) + 4) +
            4);
    int* pCloneBase = *reinterpret_cast<int**>(
        reinterpret_cast<std::uint8_t*>(pRaceItem) + dualBaseOff + 0xAC);
    int* pSub = *reinterpret_cast<int**>(
        reinterpret_cast<std::uint8_t*>(pCloneBase) + 0x3C);

    // RaceRegenRate (HP) — short at sub+0x3FA
    return static_cast<int>(
        *reinterpret_cast<std::int16_t*>(
            reinterpret_cast<std::uint8_t*>(pSub) + 0x3FA));
}
