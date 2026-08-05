// =============================================================================
// Vehicle_DeactivateHardpointWeapons_Inferred
// -----------------------------------------------------------------------------
// Purpose:  For each non-null hardpoint weapon under vehicle+0x260 (3 slots):
//             1) Weapon_SetFireFlagPair(w, 0)     // +0xC7/+0xC8
//             2) Weapon_SetSuppressFlag_Cb(w, 0)  // +0xCB
//             3) w->vtbl[+0x18](0)                // deactivate-class vfunc
//           Used on vehicle-switch path (caller FUN_005252f0 loads ECX from
//           session/character+0x250). Sibling FUN_004f4f00 activates.
//
// Address:  0x004f4eb0  (autoassault.exe, image base 0x400000)
// End:      0x004f4efe exclusive (78 bytes)
// Stable:   aa_004f4eb0
// Ghidra:   FUN_004f4eb0
// Machine:  56 57 8bf9 33f6 ... 83c604 83fe0c 7cc4 5f5e c3
//
// Convention: MSVC __thiscall/__fastcall (this in ECX; 0 stack args; ret)
// Callees:    Weapon_SetFireFlagPair_Inferred (0x0056a260)
//             Weapon_SetSuppressFlag_Cb_Inferred (0x0056b400)
//             weapon vtbl+0x18
// Caller:     FUN_005252f0 @ 0x0052556b (sole)
//
// Exactness: Preserves retail control flow (3-slot loop, null skip, call order).
// Bit-for-bit vs retail EXE: 78-byte body sealed via read_memory; package DEFERRED.
// Runtime / differential: OPEN.
// Dual A/B (static): SEALED accept-with-gaps 2026-07-29 (W24-Q).
// =============================================================================

#include <cstdint>

struct WeaponHardpoint;
struct VehicleEntity;

// Sealed callees (not redefined here)
void Weapon_SetFireFlagPair_Inferred(WeaponHardpoint* weapon, std::uint8_t value);
void Weapon_SetSuppressFlag_Cb_Inferred(WeaponHardpoint* weapon, std::uint8_t value);

/// Deactivate all hardpoint weapons on a vehicle (clear fire/suppress + vfunc 0).
/// @param vehicle  Vehicle* in ECX; owns hardpoint table at +0x260 (3 pointers).
void Vehicle_DeactivateHardpointWeapons_Inferred(VehicleEntity* vehicle)
{
    auto* const base = reinterpret_cast<std::uint8_t*>(vehicle);
    auto* const table = *reinterpret_cast<WeaponHardpoint***>(base + 0x260);

    for (int slotOff = 0; slotOff < 0x0C; slotOff += 4) {
        WeaponHardpoint* w = *reinterpret_cast<WeaponHardpoint**>(
            reinterpret_cast<std::uint8_t*>(table) + slotOff);
        if (w == nullptr) {
            continue;
        }
        Weapon_SetFireFlagPair_Inferred(w, 0);
        Weapon_SetSuppressFlag_Cb_Inferred(w, 0);

        auto* vtbl = *reinterpret_cast<void***>(w);
        using VfnSetActive = void(__thiscall*)(WeaponHardpoint*, int);
        auto fn = reinterpret_cast<VfnSetActive>(vtbl[0x18 / sizeof(void*)]);
        fn(w, 0);
    }
}
