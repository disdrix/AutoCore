// =============================================================================
// Vehicle_CanFireAnyPrimaryHeatOK_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Existential primary heat gate for a vehicle. True if any of the
//           three hardpoint weapons is primary-group (vtbl+0x38) and passes
//           Weapon_CanFireHeatCheck (owner vehicle heat < max).
//
// Address:  0x004f5290  (autoassault.exe, image base 0x400000)
// Stable:   aa_004f5290
// System:   combat / vehicle weapon heat
//
// Convention: MSVC __thiscall / __fastcall (vehicle in ECX)
//
// Layout:
//   vehicle+0x260  pointer to weapon* hardpoint table (3 slots)
//   weapon.vtbl+0x38  primary-group predicate (bool thiscall)
//   Weapon_CanFireHeatCheck(weapon) → vehicle heat+0x150 < max+0x244
//
// Twin: secondary FUN_004f52e0 uses vtbl+0x3C with universal (∀) heat OK.
// Caller: Input_TryFirePrimaryWeapons_Inferred (0x00922270) before FUN_004f50d0.
//
// Exactness: Behavior-preserving rewrite of raw decompile + asm. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Dual: reviews/A_aa_004f5290_Vehicle_CanFireAnyPrimaryHeatOK_Inferred.md
// =============================================================================

#include <cstdint>

// Declared elsewhere (aa_0056aca0); vehicle heat pool gate.
extern bool __fastcall Weapon_CanFireHeatCheck(void* pWeapon);

static constexpr int kOffHardpointTable = 0x260;
static constexpr int kHardpointCount    = 3;
static constexpr int kVtblPrimaryGroup  = 0x38; // vs secondary 0x3C

using WeaponBoolFn = char(__fastcall*)(void* /*this weapon*/);

bool __fastcall Vehicle_CanFireAnyPrimaryHeatOK_Inferred(void* pVehicle)
{
    auto* const base = reinterpret_cast<std::uint8_t*>(pVehicle);
    void** const table = *reinterpret_cast<void***>(base + kOffHardpointTable);

    for (int i = 0; i < kHardpointCount; ++i) {
        void* pWeapon = table[i];
        if (pWeapon == nullptr) {
            continue;
        }
        auto* vtbl = *reinterpret_cast<std::uint8_t**>(pWeapon);
        auto isPrimaryGroup = reinterpret_cast<WeaponBoolFn>(
            *reinterpret_cast<void**>(vtbl + kVtblPrimaryGroup));
        if (isPrimaryGroup(pWeapon) == '\0') {
            continue;
        }
        if (Weapon_CanFireHeatCheck(pWeapon)) {
            return true; // existential: first heat-OK primary
        }
    }
    return false;
}
