// =============================================================================
// Vehicle_FireAllPrimaryWeapons_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Walk the vehicle hardpoint weapon table and start fire on every
//           weapon that reports primary-group membership (weapon vtbl+0x38).
//           Success bits OR-accumulate; no heat check here (caller gates heat).
//
// Address:  0x004f50d0  (autoassault.exe, image base 0x400000)
// Stable:   aa_004f50d0
// System:   combat / vehicle weapons
//
// Convention: MSVC __thiscall / __fastcall (vehicle in ECX)
//
// Layout (plate + raw + asm):
//   vehicle+0x260  hardpoint table base (pointer to weapon* [3])
//   slot stride    4 bytes; loop offset 0..0xC exclusive → 3 slots
//   weapon vtbl+0x38  primary-group predicate (bool thiscall on weapon)
//   FUN_0056d520      weapon start-fire / HB enqueue (thiscall on weapon)
//
// Sibling twins (not this unit):
//   FUN_004f5110  secondary fire-all (vtbl+0x3C → same FUN_0056d520)
//   FUN_004f5290  primary heat probe (vtbl+0x38 + Weapon_CanFireHeatCheck, ∃)
//
// Sole static caller: Input_TryFirePrimaryWeapons_Inferred (0x00922270) after
// heat probe FUN_004f5290 succeeds on vehicle @ char+0x250.
//
// Exactness: Behavior-preserving rewrite of raw decompile + prolog/loop asm.
// Product symbol: _Inferred (no retail string in unit).
// =============================================================================

#include <cstdint>

// Ghidra still names this FUN_0056d520 (weapon start-fire HB path).
// Declared only for plate fidelity; not reimplemented here.
extern "C" std::uint8_t __fastcall FUN_0056d520(void* pWeapon);

static constexpr int kOffHardpointTable = 0x260;
static constexpr int kHardpointByteSpan = 0x0C; // 3 slots × 4
static constexpr int kWeaponVtblIsPrimaryGroup = 0x38;

// Returns non-zero if any primary-marked hardpoint successfully started fire.
std::uint8_t __fastcall Vehicle_FireAllPrimaryWeapons_Inferred(void* pVehicle)
{
    auto* const base = reinterpret_cast<std::uint8_t*>(pVehicle);
    std::uint8_t anyStarted = 0;

    int* pHardpoints = *reinterpret_cast<int**>(base + kOffHardpointTable);

    // Raw: i = 0; do { ...; i += 4; } while (i < 0xC);
    for (int byteOff = 0; byteOff < kHardpointByteSpan; byteOff += 4) {
        int* pWeapon = *reinterpret_cast<int**>(
            reinterpret_cast<std::uint8_t*>(pHardpoints) + byteOff);
        // Equivalent: pHardpoints[byteOff/4] when pHardpoints is weapon**.

        if (pWeapon == nullptr) {
            continue;
        }

        // thiscall: ECX = weapon; call [*vtbl + 0x38]
        auto** vtbl = *reinterpret_cast<void***>(pWeapon);
        using PredFn = char(__fastcall*)(void* self);
        char isPrimary = reinterpret_cast<PredFn>(vtbl[kWeaponVtblIsPrimaryGroup / sizeof(void*)])(pWeapon);
        if (isPrimary == '\0') {
            continue;
        }

        // thiscall: ECX = weapon → FUN_0056d520
        std::uint8_t started = FUN_0056d520(pWeapon);
        anyStarted = static_cast<std::uint8_t>(anyStarted | started);
    }

    return anyStarted;
}
