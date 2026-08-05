// =============================================================================
// VehicleEntity_SetSteerInput
// -----------------------------------------------------------------------------
// Purpose:  Gated write of the vehicle entity raw steer-axis float (this+0x618).
//           Allows the write when the final linked object pointer is null, or when
//           its flag byte at +0xb4 has none of bits 0xC7 set (write-suppress mask;
//           "lock" is unproven semantics). No clamps, no ramps, no controller push.
//           No other stores in this body (callers supply axis sign/magnitude).
//
// Address:  0x004f5620  (autoassault.exe, image base 0x400000)
// Stable:   aa_004f5620
// End:      ~0x004f564a (~0x2b bytes)
//
// Convention: MSVC __thiscall  (this in ECX)
//
// Callers (xref sample):
//   Client_Input_DriveControlTick  0x009223b0  aa_009223b0  (primary local digital/analog)
//     Hard R DAT_00d1bcc2 → -1.0f (0xbf800000); Hard L DAT_00d1bc8e → +1.0f (0x3f800000)
//     Soft L DAT_00d1bd2a → -0.5f (0xbf000000); Soft R DAT_00d1bcf6 → +0.5f (0x3f000000)
//     Clear → 0; all under vehicle+0x101==0. Signs are caller-owned (not this body).
//   FUN_004fc650                   0x004fc650
//   FUN_005d73a0                   0x005d73a0
//   FUN_00636ba0                   0x00636ba0
//   FUN_0092f090                   0x0092f090
//   FUN_009373e0                   0x009373e0
//
// Sibling:  VehicleEntity_SetLongitudinalInput @ 0x004f5650  aa_004f5650 → +0x614
// Related:  VehicleEntity_SetHandbrake        @ 0x004f3620  aa_004f3620 → +0x61c (ungated)
//
// Related docs:
//   docs/reconstruction/reconstructed-exact/Client_Input_DriveControlTick.cpp
//   docs/reconstruction/systems/input-drive-control.md
//   docs/reconstruction/physics/verified/fn_004f5620_setSteerInput.md
//   docs/reconstruction/raw/aa_004f5620_VehicleEntity_SetSteerInput.md
//   docs/reconstruction/reviews/A_aa_009223b0_Client_Input_DriveControlTick.md
//
// Exactness: Preserves retail control flow and single conditional store.
//            Does NOT invent clamps, deadzones, or flag mutations.
// =============================================================================

#include <cstdint>

// Write-suppress mask: decompiler decimal 199 == 0xC7
// bits 0x01 | 0x02 | 0x04 | 0x40 | 0x80 — per-bit meaning unresolved
static constexpr std::uint8_t kInputAxisSuppressMask = 0xC7u;

// Offsets (entity / linked object) — retail layout
static constexpr std::uintptr_t kOffEntityLink0        = 0x04;
static constexpr std::uintptr_t kOffLink1              = 0x04;
static constexpr std::uintptr_t kOffWobjEntityRelative = 0xb0;
static constexpr std::uintptr_t kOffWobjFlags          = 0xb4;
static constexpr std::uintptr_t kOffSteerInput         = 0x618; // f32
// Sibling longitudinal input lives at +0x614 (not written here).

struct VehicleEntity;

/// Gated store of raw steer input to entity+0x618.
/// @param thisEntity  Vehicle entity (retail `this`).
/// @param steerInput  Desired steer axis; typically [-1,+1] by caller contract only.
void VehicleEntity_SetSteerInput(VehicleEntity* thisEntity, float steerInput)
{
    // Pointer chain (Ghidra):
    //   wobj = *( *(*(this + 4) + 4) + this + 0xb0 )
    auto* const base = reinterpret_cast<std::uint8_t*>(thisEntity);

    auto* const p0 = *reinterpret_cast<std::uint8_t**>(base + kOffEntityLink0);
    auto* const p1 = *reinterpret_cast<std::uint8_t**>(p0 + kOffLink1);

    // Final load address is (p1 + (uintptr)this + 0xb0) — entity-relative slot.
    auto* const wobj = *reinterpret_cast<std::uint8_t**>(
        p1 + reinterpret_cast<std::uintptr_t>(thisEntity) + kOffWobjEntityRelative);

    // Note: intermediate loads p0/p1 are unchecked — null p0/p1 faults; only final
    // wobj null is an allow path. Suppress semantics beyond the mask are unproven.
    if (wobj == nullptr
        || ((*(wobj + kOffWobjFlags) & kInputAxisSuppressMask) == 0))
    {
        *reinterpret_cast<float*>(base + kOffSteerInput) = steerInput;
    }
    // else: retain previous value at this+0x618
}
