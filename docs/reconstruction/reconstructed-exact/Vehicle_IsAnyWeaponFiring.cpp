// =============================================================================
// Vehicle_IsAnyWeaponFiring
// -----------------------------------------------------------------------------
// Purpose:  True if the turret weapon or any of the three hardpoint weapons has
//           its firing flag set. Used by combat-pool OnTick to slow cooling.
//
// Address:  0x004f7480  (autoassault.exe, image base 0x400000)
// Stable:   aa_004f7480
// System:   vehicle combat pools
//
// Convention: MSVC __fastcall / __thiscall (vehicle in ECX)
//
// Layout (plate + raw):
//   vehicle+0x264  turret weapon*
//   vehicle+0x260  hardpoint table (int[3] of weapon*)
//   weapon+0xC7    char firing flag
//
// Typed decomp expresses these as pPad_248_267_Inferred+0x1C / +0x18
// (0x248+0x1C=0x264, 0x248+0x18=0x260).
//
// Exactness: Behavior-preserving rewrite of raw decompile.
// =============================================================================

#include <cstdint>

static constexpr int kOffHardpointTable = 0x260;
static constexpr int kOffTurretWeapon   = 0x264;
static constexpr int kOffWeaponFiring   = 0xC7;

bool __fastcall Vehicle_IsAnyWeaponFiring(void* pVehicle)
{
    auto* const base = reinterpret_cast<std::uint8_t*>(pVehicle);

    int pTurret = *reinterpret_cast<int*>(base + kOffTurretWeapon);
    if (pTurret != 0 && *reinterpret_cast<char*>(pTurret + kOffWeaponFiring) != '\0') {
        return true;
    }

    // Same short-circuit shape as raw: if turret missing/idle, scan hardpoints.
    // Raw returns true if the while exits early (found a firing weapon).
    int* pHardpoints = *reinterpret_cast<int**>(base + kOffHardpointTable);
    for (int i = 0; i < 3; ++i) {
        int pWeapon = pHardpoints[i];
        if (pWeapon != 0 && *reinterpret_cast<char*>(pWeapon + kOffWeaponFiring) != '\0') {
            return true;
        }
    }
    return false;
}
