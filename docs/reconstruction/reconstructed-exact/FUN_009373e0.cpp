// =============================================================================
// FUN_009373e0  (twin of Client_DialogGate_OpenIndex10_ParkDriveAxes_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_009373e0
// Address:   0x009373e0 – 0x00937462  (autoassault.exe, image base 0x400000)
// Size:      131 B / 0x83
// System:    input-drive-control
// Generated: 2026-08-05 MEGA-024 dual seal
// Exactness: Behavior-preserving rewrite of machine control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical named twin: Client_DialogGate_OpenIndex10_ParkDriveAxes_Inferred.cpp
// =============================================================================

// PURPOSE: Dialog-host gate → open dialog index 10 → mission-dialog caption
// stamp → park vehicle thr0/steer0/HB1 when vehicle present.
//
// ABI: EDI=client; stack dword stamp; RET 4. See named twin for full notes.

#include <cstdint>

extern "C" void __thiscall Client_OpenDialogByIndex(void* self, int dialogIndex,
                                                    char forceCloseIfOpen,
                                                    char allowWhileDriving);
extern "C" void MissionDialog_SetNpcObjectAndNameCaption_Inferred(void* dialogHost,
                                                                    int npcOrClear);
extern "C" void __thiscall VehicleEntity_SetLongitudinalInput(void* self, float v);
extern "C" void __thiscall VehicleEntity_SetSteerInput(void* self, float v);
extern "C" void __thiscall VehicleEntity_SetHandbrake(void* self, uint8_t on);

void FUN_009373e0(void* client /*EDI*/, int npcOrClear)
{
  void** hostSlot = *reinterpret_cast<void***>(reinterpret_cast<char*>(client) + 0xf40);
  if (hostSlot == nullptr) {
    return;
  }
  if (*hostSlot != *reinterpret_cast<void**>(reinterpret_cast<char*>(client) + 0xf38)) {
    return;
  }

  Client_OpenDialogByIndex(client, 10, 0, 0);

  void* missionDialog =
      *reinterpret_cast<void**>(reinterpret_cast<char*>(client) + 0x1058);
  MissionDialog_SetNpcObjectAndNameCaption_Inferred(missionDialog, npcOrClear);

  void* actor = *reinterpret_cast<void**>(reinterpret_cast<char*>(client) + 0xe98);
  if (actor == nullptr) {
    return;
  }
  void* vehicle =
      *reinterpret_cast<void**>(reinterpret_cast<char*>(actor) + 0x250);
  if (vehicle == nullptr) {
    return;
  }

  VehicleEntity_SetLongitudinalInput(vehicle, 0.0f);
  VehicleEntity_SetSteerInput(vehicle, 0.0f);
  VehicleEntity_SetHandbrake(vehicle, 1);
}
