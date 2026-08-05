// =============================================================================
// VehicleEntity_SetDriveAxes
// -----------------------------------------------------------------------------
// Purpose:  Bulk-write the three drive-axis fields on a vehicle entity, then
//           always push thr/HB into the input controller via
//           PushDriveAxesToController. Steer is stored on the entity only;
//           Push does not copy +0x618 (applyAction ramps steer).
//
// Address:  0x004fbec0  (autoassault.exe, image base 0x400000)
// Span:     0x004fbec0 – 0x004fbeed inclusive (46 bytes); ret 0xc
// Stable:   aa_004fbec0
// System:   input-drive-control
//
// Convention: MSVC __thiscall (this in ECX)
//   thisEntity     vehicle entity
//   thr            f32 → entity+0x614 (longitudinal; Accel≈−1, Reverse≈+1)
//   steer          f32 → entity+0x618
//   handbrake      u8  → entity+0x61c
//
// Sibling setters:
//   VehicleEntity_SetLongitudinalInput  0x004f5650 → +0x614 (gated 0xC7; no Push)
//   VehicleEntity_SetSteerInput         0x004f5620 → +0x618 (gated 0xC7; no Push)
//   VehicleEntity_SetHandbrake          0x004f3620 → +0x61c (ungated; no Push)
//
// This body does NOT apply the write-suppress gate used by the single thr/steer
// setters — it always stores all three, then always calls Push.
//
// Sole static caller (xrefs 2026-07-29): VehicleAction_airStabilization recovery
//   site 0x0059858a → SetDriveAxes(entity, 0.f, 0.f, 1)  // NOT all-zero HB
//
// Exactness: Behavior-preserving rewrite of decompiler control flow + machine
//            proof (read_memory). Dual A/B strengthened 2026-07-29.
// =============================================================================

#include <cstdint>

// Offsets on vehicle entity (retail layout)
static constexpr std::uintptr_t kOffLongitudinalInput = 0x614; // f32
static constexpr std::uintptr_t kOffSteerInput        = 0x618; // f32
static constexpr std::uintptr_t kOffHandbrake         = 0x61c; // u8

struct VehicleEntity;

// aa_004fbc10 — pushes +0x614 thr and +0x61c HB (plus speed-cap / hard-stop);
// does NOT copy +0x618 steer.
void __fastcall VehicleEntity_PushDriveAxesToController(VehicleEntity* thisEntity);

void __thiscall VehicleEntity_SetDriveAxes(
    VehicleEntity* thisEntity,
    float          thr,
    float          steer,
    std::uint8_t   handbrake)
{
    auto* const base = reinterpret_cast<std::uint8_t*>(thisEntity);

    *reinterpret_cast<float*>(base + kOffLongitudinalInput) = thr;
    *reinterpret_cast<float*>(base + kOffSteerInput)        = steer;
    *(base + kOffHandbrake)                                 = handbrake;

    // __fastcall/__thiscall with this in ECX (same object).
    VehicleEntity_PushDriveAxesToController(thisEntity);
}
