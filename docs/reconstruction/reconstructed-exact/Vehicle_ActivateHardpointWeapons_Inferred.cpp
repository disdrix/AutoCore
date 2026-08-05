// =============================================================================
// Vehicle_ActivateHardpointWeapons_Inferred
// -----------------------------------------------------------------------------
// Purpose:  For each non-null hardpoint weapon under vehicle+0x260 (3 slots):
//             1) Weapon_SetFireFlagPair(w, 0)     // clear fire pair
//             2) if (w[+0x08]==0): full vtbl[0] activate(1, zeros, g_flOne, 0)
//                else:            vtbl+0x18(1)
//           Twin of Vehicle_DeactivateHardpointWeapons_Inferred (0x004f4eb0)
//           which also clears suppress and calls vtbl+0x18(0).
//           Used on vehicle-switch path (caller Character_SwitchVehicle 0x005252f0).
//
// Address:  0x004f4f00  (autoassault.exe, image base 0x400000)
// End:      0x004f4fab exclusive (171 bytes)
// Stable:   aa_004f4f00
// Ghidra:   FUN_004f4f00
// Machine:  83 EC 10 56 57 8B F9 33 F6 ... 83 FE 0C 0F 8C 6A FF FF FF 5F 5E 83 C4 10 C3
//
// Convention: MSVC __thiscall/__fastcall (this in ECX; 0 stack args; ret)
// Callees:    Weapon_SetFireFlagPair_Inferred (0x0056a260)
//             weapon vtbl[0] / vtbl+0x18
// Caller:     FUN_005252f0 / Character_SwitchVehicle_Inferred @ 0x005259ad (sole)
//
// Exactness: Preserves retail control flow (3-slot loop, null skip, branch, call order).
// Bit-for-bit vs retail EXE: 171-byte body sealed via read_memory; package DEFERRED.
// Runtime / differential: OPEN.
// Dual A/B (static): SEALED accept-with-gaps 2026-07-29 (W25-E).
// =============================================================================

#include <cstdint>

struct WeaponHardpoint;
struct VehicleEntity;

extern float g_flOne; // 0x00a0f2a0 = 1.0f

void Weapon_SetFireFlagPair_Inferred(WeaponHardpoint *weapon, std::uint8_t value);

/// Activate all hardpoint weapons on a vehicle (clear fire + activate vfunc).
/// @param vehicle  Vehicle* in ECX; owns hardpoint table at +0x260 (3 pointers).
void Vehicle_ActivateHardpointWeapons_Inferred(VehicleEntity *vehicle)
{
    auto *const base = reinterpret_cast<std::uint8_t *>(vehicle);
    auto *const table = *reinterpret_cast<WeaponHardpoint ***>(base + 0x260);

    for (int slotOff = 0; slotOff < 0x0C; slotOff += 4) {
        WeaponHardpoint *w = *reinterpret_cast<WeaponHardpoint **>(
            reinterpret_cast<std::uint8_t *>(table) + slotOff);
        if (w == nullptr) {
            continue;
        }
        Weapon_SetFireFlagPair_Inferred(w, 0);

        auto *vtbl = *reinterpret_cast<void ***>(w);
        auto *modeField = reinterpret_cast<std::uint32_t *>(
            reinterpret_cast<std::uint8_t *>(w) + 0x08);
        if (*modeField == 0) {
            // Full activate: vtbl[0](this, 1, 0,0,0, 0,0,0, g_flOne, 0)
            using VfnFull = void(__thiscall *)(
                WeaponHardpoint *, int, int, int, int, int, int, int, float, int);
            auto fn = reinterpret_cast<VfnFull>(vtbl[0]);
            fn(w, 1, 0, 0, 0, 0, 0, 0, g_flOne, 0);
        } else {
            using VfnShort = void(__thiscall *)(WeaponHardpoint *, int);
            auto fn = reinterpret_cast<VfnShort>(vtbl[0x18 / sizeof(void *)]);
            fn(w, 1);
        }
    }
}
