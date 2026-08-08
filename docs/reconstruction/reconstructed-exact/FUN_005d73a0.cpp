// =============================================================================
// FUN_005d73a0  (twin of CVOGHBAIDriver_AxisPark_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_005d73a0
// Address:   0x005d73a0–0x005d73e7 inclusive (72 B / 0x48)
// Module:    autoassault.exe (image base 0x400000)
// System:    input-drive-control / HB AI driver
// Agent:     MEGA-015 OWN-ONLY dual 2026-08-05
// Canonical: CVOGHBAIDriver_AxisPark_Inferred
// Exactness: Behavior-preserving rewrite of decompiler + assembly control flow.
// Terminal:  false (no runtime Confirmed / no Launcher).
// =============================================================================

// Twin keeps Ghidra symbol as entry alias; body matches named clean.

void __thiscall VehicleEntity_SetSteerInput(void *vehicle, int steer_or_float_bits);
void __thiscall VehicleEntity_SetLongitudinalInput(void *vehicle, int long_or_float_bits);
void __thiscall VehicleEntity_SetHandbrake(void *vehicle, unsigned char handbrake);
void __thiscall CVOGHBAIFollowVehicle_FireWeapons(void *self, int may_fire, int unused);
void __thiscall VehicleEntity_PushDriveAxesToController(void *vehicle);
void __fastcall FUN_005cc560(void *self);

void __thiscall FUN_005d73a0(void *self /* ECX */)
{
  void *vehicle;

  vehicle = *(void **)((char *)self + 0xbc);

  VehicleEntity_SetSteerInput(vehicle, 0);
  VehicleEntity_SetLongitudinalInput(vehicle, 0);
  VehicleEntity_SetHandbrake(vehicle, 1);

  CVOGHBAIFollowVehicle_FireWeapons(self, /*mayFire*/ 0, /*unused*/ 0);

  VehicleEntity_PushDriveAxesToController(vehicle);

  FUN_005cc560(self);
}
