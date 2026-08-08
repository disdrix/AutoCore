// =============================================================================
// CVOGHBAIDriver_AxisPark_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005d73a0
// Address:   0x005d73a0–0x005d73e7 inclusive (72 B / 0x48)
// Module:    autoassault.exe (image base 0x400000)
// System:    input-drive-control / HB AI driver
// Agent:     MEGA-015 OWN-ONLY dual 2026-08-05
// Exactness: Behavior-preserving rewrite of decompiler + assembly control flow.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// Terminal:  false (no runtime Confirmed / no Launcher).
// =============================================================================
//
// PURPOSE
//   Virtual method on CVOGHBAIDriver (RTTI .?AVCVOGHBAIDriver@@; vtbl 009db02c
//   slot +0x10). Parks AI drive axes on the bound vehicle (this+0xbc):
//     steer = 0, longitudinal = 0, handbrake = 1,
//     clear weapon fire mask via FireWeapons(mayFire=0),
//     push axes into the VehicleAction controller,
//     then tail into FUN_005cc560 owner-counter cleanup.
//
// ABI (sealed by disassemble_function + read_memory)
//   __thiscall: ECX = CVOGHBAIDriver* this
//   No stack arguments
//   Void return; exit is tail JMP to FUN_005cc560 after POP ESI
//
// CLASS / DISPATCH
//   Ctor FUN_005d7bb0 installs *this = &PTR_FUN_009db02c
//   DATA xref only @ 0x009db03c — no direct CALL sites
//
// CALLEES
//   VehicleEntity_SetSteerInput            0x004f5620  (vehicle+0x618)
//   VehicleEntity_SetLongitudinalInput     0x004f5650  (vehicle+0x614)
//   VehicleEntity_SetHandbrake             0x004f3620  (vehicle+0x61c)
//   CVOGHBAIFollowVehicle_FireWeapons      0x005d7100  (RET 8; may-fire gate)
//   VehicleEntity_PushDriveAxesToController 0x004fbc10
//   FUN_005cc560                           0x005cc560  (tail)
//
// GAPS
//   Product method English open → _Inferred
//   Virtual call-site inventory open
//   FUN_005cc560 residual
// =============================================================================

// Forward decls (names from dualed / prior plates; residual keeps FUN_*)
void __thiscall VehicleEntity_SetSteerInput(void *vehicle, int steer_or_float_bits);
void __thiscall VehicleEntity_SetLongitudinalInput(void *vehicle, int long_or_float_bits);
void __thiscall VehicleEntity_SetHandbrake(void *vehicle, unsigned char handbrake);
// FireWeapons: thiscall, two stack dwords (mayFire + unused), RET 8
void __thiscall CVOGHBAIFollowVehicle_FireWeapons(void *self, int may_fire, int unused);
void __thiscall VehicleEntity_PushDriveAxesToController(void *vehicle);
void __fastcall FUN_005cc560(void *self);

void __thiscall CVOGHBAIDriver_AxisPark_Inferred(void *self /* ECX */)
{
  void *vehicle;

  vehicle = *(void **)((char *)self + 0xbc);

  VehicleEntity_SetSteerInput(vehicle, 0);
  VehicleEntity_SetLongitudinalInput(vehicle, 0);
  VehicleEntity_SetHandbrake(vehicle, 1);

  CVOGHBAIFollowVehicle_FireWeapons(self, /*mayFire*/ 0, /*unused*/ 0);

  VehicleEntity_PushDriveAxesToController(vehicle);

  // Assembly: MOV ECX,ESI; POP ESI; JMP FUN_005cc560
  FUN_005cc560(self);
}
