// =============================================================================
// VehicleEntity_SetHandbrake
// -----------------------------------------------------------------------------
// Purpose:  Ungated write of the vehicle entity handbrake / sharp-turn flag byte
//           (this+0x61c). Unlike SetSteerInput / SetLongitudinalInput there is
//           **no** 0xC7 suppress gate — every call stores.
//
// Address:  0x004f3620  (autoassault.exe, image base 0x400000)
// Stable:   aa_004f3620
// End:      0x004f362c inclusive (13 bytes; exclusive end 0x004f362d)
// Machine:  8a442404 88811c060000 c20400
//             mov al,[esp+4] ; mov [ecx+0x61c],al ; ret 4
//
// Convention: MSVC __thiscall  (this in ECX; stack arg; ret 4)
//
// Callers (live xrefs 2026-07-29 strengthen — 10 functions / 18 sites):
//   Client_Input_DriveControlTick  0x009223b0  aa_009223b0  (primary local)
//     clear @ 0x9224d9 / 0x9228ee / 0x922979 / 0x922dd7 / 0x92358e → 0
//     Brake/bounce @ 0x9235b9 → 1  (DAT_00d1bd5e held or bounce path)
//   Client_Input_PollBoundActions   0x00925d60  @ 0x927d58 → 1
//   FUN_005d0d60 @ 0x5d0f4c / FUN_005d73a0 @ 0x5d73c5
//   FUN_00915670 @ 0x915698 / FUN_0092f090 @ 0x92f0cc
//   FUN_009373e0 @ 0x93745b / FUN_00938670 @ 0x938698
//   FUN_0093a5c0 @ 0x93a5f8
//   FUN_00946c00 @ 0x946d67 / 0x946da7 / 0x946de7 / 0x946eb8
//
// Bypass writers of the SAME byte (not callers of this function):
//   Drive_CVOGVehicle_MoveToTarget3DPoint  0x004fc650  — direct +0x61c = 0/1
//     sharp when speed > DAT_00aaa7a4 AND |headingErr| > DAT_00a0f710; arrival → 1
//   VehicleEntity_SetDriveAxes             0x004fbec0  — bundled thr/steer/HB + Push
//
// Consumers of entity+0x61c:
//   VehicleEntity_PushDriveAxesToController 0x004fbc10 → ctrl+0x24
//     (hard-stop entity+0x109 forces ctrl HB=1 without reading +0x61c)
//   VehicleAction_calcWheelTorque 0x00598040 — rear drive torque ×0.5
//     (DAT_00a0f298 = 0.5f) if +0x61c ≠ 0
//
// Related:  VehicleEntity_SetSteerInput        @ 0x004f5620  aa_004f5620 → +0x618 (gated 0xC7)
//           VehicleEntity_SetLongitudinalInput @ 0x004f5650  aa_004f5650 → +0x614 (gated 0xC7)
//           VehicleEntity_SetFlag_109          @ 0x004f3630  → +0x109 (hard-stop; distinct)
//
// Related docs:
//   docs/reconstruction/reviews/a_004f3620.md  (dual residual seal)
//   docs/reconstruction/reconstructed-exact/Client_Input_DriveControlTick.cpp
//   docs/reconstruction/systems/input-drive-control.md
//   docs/reconstruction/types/VehicleEntity_drive_axes.md
//   docs/reconstruction/physics/verified/fn_004fbc10_pushDriveAxes.md
//   docs/reconstruction/physics/verified/fn_00598040_calcWheelTorque.md
//   docs/reconstruction/physics/verified/server_handbrake_wire.md
//
// Exactness: Preserves retail control flow (single unguarded store).
//            Does NOT invent gates, clamps, or flag mutations.
// Bit-for-bit vs retail EXE: 13-byte body sealed via read_memory; package DEFERRED.
// Runtime / differential: OPEN.
// Dual residual (static consumers + bypass + ungated + call graph): SEALED 2026-07-29.
// =============================================================================

#include <cstdint>

// Offsets — retail vehicle entity layout
static constexpr std::uintptr_t kOffHandbrakeFlag = 0x61c; // u8 / bool-like

struct VehicleEntity;

/// Ungated store of handbrake/sharp flag to entity+0x61c.
/// @param thisEntity   Vehicle entity (retail `this`).
/// @param handbrakeOn  Non-zero = engaged (DriveControlTick uses 0/1; consumers test ≠0).
void VehicleEntity_SetHandbrake(VehicleEntity* thisEntity, std::uint8_t handbrakeOn)
{
    auto* const base = reinterpret_cast<std::uint8_t*>(thisEntity);
    *(base + kOffHandbrakeFlag) = handbrakeOn;
}
