// =============================================================================
// FUN_00636ba0  — scaffold twin of CVOGHBMoveVehicle_OnEnd
// -----------------------------------------------------------------------------
// Stable ID: aa_00636ba0
// Address:   0x00636ba0  (autoassault.exe, image base 0x400000)
// Preferred: reconstructed-exact/CVOGHBMoveVehicle_OnEnd.cpp
// System:    input-drive-control / heartbeat OnEnd
// Updated:   2026-08-05 MEGA-017 (retire pure scaffold semantics)
// Exactness: Ghidra name retained for FUN_* twin path; CF matches named clean.
// =============================================================================

// See CVOGHBMoveVehicle_OnEnd.cpp for full plate, RTTI, vtbl, and port notes.

void __thiscall FUN_00636ba0(int param_1)
{
  int entity;

  entity = *(int *)(param_1 + 0x24);
  if (entity != 0) {
    // VehicleEntity_SetSteerInput(entity, 0) — thiscall; stack float 0
    // VehicleEntity_PushDriveAxesToController(entity) — thiscall/fastcall ECX
    extern void __thiscall VehicleEntity_SetSteerInput(int, float);
    extern void __fastcall VehicleEntity_PushDriveAxesToController(int);
    VehicleEntity_SetSteerInput(entity, 0.0f);
    VehicleEntity_PushDriveAxesToController(entity);
  }
  // machine: JMP 0x005081e0 (empty RET) — decompiler shows bare return
  return;
}
