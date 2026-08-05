// =============================================================================
// VehicleEntity_SetLongitudinalInput
// -----------------------------------------------------------------------------
// Purpose:  Gated write of the vehicle entity raw longitudinal-axis float
//           (this+0x614). Allows the write when the final linked object pointer
//           is null, or when its flag byte at +0xb4 has none of bits 0xC7 set
//           (write-suppress mask; "lock" is unproven semantics). No clamps,
//           no ramps, no controller push. Axis sign/magnitude are caller-
//           supplied only.
//
// Address:  0x004f5650  (autoassault.exe, image base 0x400000)
// Stable:   aa_004f5650
// End:      ~0x004f567a (~0x2b bytes; mirror of SetSteerInput)
//
// Convention: MSVC __thiscall  (this in ECX)
//
// Callers (xref sample):
//   Client_Input_DriveControlTick  0x009223b0  aa_009223b0  (primary local digital/analog)
//     Accelerate DAT_00d1bc26 → -1.0f (0xbf800000); Reverse DAT_00d1bc5a → +1.0f (0x3f800000)
//     Release / neither → 0; post-steer damp may write DAT_00afe2b0. Gate vehicle+0x101==0.
//     Signs are caller-owned (not this body).
//   FUN_004fc650                   0x004fc650  (arrival path thr→0)
//
// Sibling:  VehicleEntity_SetSteerInput @ 0x004f5620  aa_004f5620 → +0x618
// Related:  VehicleEntity_SetHandbrake  @ 0x004f3620  aa_004f3620 → +0x61c (ungated)
//
// Related docs:
//   docs/reconstruction/reconstructed-exact/Client_Input_DriveControlTick.cpp
//   docs/reconstruction/systems/input-drive-control.md
//   docs/reconstruction/physics/verified/fn_004f5620_setSteerInput.md
//   docs/reconstruction/raw/aa_004f5650_VehicleEntity_SetLongitudinalInput.md
//   docs/reconstruction/types/VehicleEntity_drive_axes.md
//   docs/reconstruction/reviews/A_aa_009223b0_Client_Input_DriveControlTick.md
//
// Exactness: Preserves retail control flow and single conditional store.
//            Does NOT invent clamps, deadzones, or flag mutations.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime / differential: OPEN.
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
static constexpr std::uintptr_t kOffLongitudinalInput  = 0x614; // f32
// Sibling steer input lives at +0x618 (not written here).

struct VehicleEntity;

/// Gated store of raw longitudinal input to entity+0x614.
/// @param thisEntity         Vehicle entity (retail `this`).
/// @param longitudinalInput  Desired long axis; typically [-1,+1] by caller contract only.
void VehicleEntity_SetLongitudinalInput(VehicleEntity* thisEntity, float longitudinalInput)
{
    // Pointer chain (Ghidra) — identical to SetSteerInput:
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
        *reinterpret_cast<float*>(base + kOffLongitudinalInput) = longitudinalInput;
    }
    // else: retain previous value at this+0x614
}
