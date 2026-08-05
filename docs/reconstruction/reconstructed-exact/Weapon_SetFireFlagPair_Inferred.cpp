// =============================================================================
// Weapon_SetFireFlagPair_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Leaf dual-byte setter for hardpoint weapon fire flags:
//             this+0xC7 = value always
//             this+0xC8 = value only if currently unequal
//           this is a weapon/hardpoint object from vehicle+0x260[i] (i=0..2),
//           NOT the vehicle entity. Not the drive-axis suppress mask 0xC7.
//
// Address:  0x0056a260  (autoassault.exe, image base 0x400000)
// End:      0x0056a27a inclusive (27 bytes; exclusive end 0x0056a27b)
// Stable:   aa_0056a260
// Machine:  8a442404 3881c8000000 8881c7000000 7406 8881c8000000 c20400
//             mov al,[esp+4]
//             cmp [ecx+0xc8],al
//             mov [ecx+0xc7],al      ; always
//             jz  +6
//             mov [ecx+0xc8],al      ; change-gated
//             ret 4
//
// Convention: MSVC __thiscall  (this in ECX; stack u8; ret 4)
// Callees:    none (leaf)
//
// Callers (live xrefs 2026-07-29 — 12 sites / 9+ functions):
//   Client_Input_DriveControlTick     0x009223b0  @ 0x009231c8 → 0
//   VehicleAction_airStabilization    0x00598320  @ 0x00598512 → 0
//   Vehicle_ActivateEnterWorld        0x00503f30  @ 0x005042d4 → 0
//   VehicleNet_UnpackGhostVehicle     0x005f7720  @ 0x005f9a01 → 0/1
//   FUN_005021d0                      0x005021d0  @ 0x00502268 / 0x0050234d
//   FUN_004f4eb0 / FUN_004f4f00       clear loops → 0
//   FUN_004f9030                      @ 0x004f9076 → 0 (often +0xC9=0 after)
//   FUN_00814400                      @ 0x00814452 → 0
//   sites 0x004fb8c4 / 0x005ff9f5
//
// Sibling (inline twin, not a caller):
//   FUN_0056d520 start-fire sets +0xC7/+0xC8 = 1 and +0xC9 = 1 without calling here
//
// Related cluster on same object:
//   +0xC9  fire-started companion (set by start-fire; cleared by many clear paths)
//   +0xCB  set by FUN_0056b400; start-fire returns 0 when non-zero
//
// Exactness: Preserves retail control flow (always C7 + change-gated C8).
// Bit-for-bit vs retail EXE: 27-byte body sealed via read_memory; package DEFERRED.
// Runtime / differential: OPEN.
// Dual A/B (static): SEALED accept-with-gaps 2026-07-29.
// =============================================================================

#include <cstdint>

static constexpr std::uintptr_t kOffFireFlagDesired = 0xC7; // u8, always written
static constexpr std::uintptr_t kOffFireFlagTwin    = 0xC8; // u8, change-gated

struct WeaponHardpoint;

/// Set hardpoint weapon fire flag pair (+0xC7 always, +0xC8 if changed).
/// @param weapon  Hardpoint weapon* (from vehicle+0x260 table).
/// @param value   Typically 0/1 (clear/set); domain beyond 0/1 not sealed.
void Weapon_SetFireFlagPair_Inferred(WeaponHardpoint* weapon, std::uint8_t value)
{
    auto* const base = reinterpret_cast<std::uint8_t*>(weapon);
    // Machine compares old +0xC8 before the always-store to +0xC7.
    const std::uint8_t oldTwin = *(base + kOffFireFlagTwin);
    *(base + kOffFireFlagDesired) = value;
    if (oldTwin != value) {
        *(base + kOffFireFlagTwin) = value;
    }
}
