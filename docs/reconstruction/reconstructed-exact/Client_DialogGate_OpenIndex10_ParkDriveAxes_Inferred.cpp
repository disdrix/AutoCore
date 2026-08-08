// =============================================================================
// Client_DialogGate_OpenIndex10_ParkDriveAxes_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_009373e0
// Address:   0x009373e0 – 0x00937462  (autoassault.exe, image base 0x400000)
// Size:      131 B / 0x83
// System:    input-drive-control
// Generated: 2026-08-05 MEGA-024 dual seal (from raw + live disasm)
// Exactness: Behavior-preserving rewrite of machine control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE:
// When the client dialog-host gate matches (client+0xf40 non-null and
// **(client+0xf40) == *(client+0xf38)), open dialog table index 10, clear/bind
// the mission-dialog caption host at client+0x1058 from the stack stamp, then
// if a vehicle entity is present park drive axes: longitudinal=0, steer=0,
// handbrake=1.
//
// ABI (machine):
//   EDI = Client* host (caller MOV EDI,ECX)
//   stack +4 = int stamp for MissionDialog_SetNpcObjectAndNameCaption (0 = clear)
//   RET 4
//   Vehicle handbrake path is a tail JMP that rewrites the stack formal to 1.
//
// Ghidra name: FUN_009373e0
// Name confidence: Inferred (product method English open; behavior sealed)

#include <cstdint>

// Dualed callees (not redefined here):
//   Client_OpenDialogByIndex              @ 0x007fef20
//   MissionDialog_SetNpcObjectAndNameCaption_Inferred @ 0x008aa4b0
//   VehicleEntity_SetLongitudinalInput    @ 0x004f5650
//   VehicleEntity_SetSteerInput           @ 0x004f5620
//   VehicleEntity_SetHandbrake            @ 0x004f3620

extern "C" void __thiscall Client_OpenDialogByIndex(void* self, int dialogIndex,
                                                    char forceCloseIfOpen,
                                                    char allowWhileDriving);
extern "C" void MissionDialog_SetNpcObjectAndNameCaption_Inferred(void* dialogHost,
                                                                    int npcOrClear);
extern "C" void __thiscall VehicleEntity_SetLongitudinalInput(void* self, float v);
extern "C" void __thiscall VehicleEntity_SetSteerInput(void* self, float v);
extern "C" void __thiscall VehicleEntity_SetHandbrake(void* self, uint8_t on);

// Retail uses EDI + one stack arg; thiscall-on-ECX is a readability stand-in
// only if the caller also sets EDI=ECX (sole site does). Prefer EDI model.
void Client_DialogGate_OpenIndex10_ParkDriveAxes_Inferred(void* client /*EDI*/,
                                                          int npcOrClear)
{
  void** hostSlot = *reinterpret_cast<void***>(reinterpret_cast<char*>(client) + 0xf40);
  if (hostSlot == nullptr) {
    return; // ret 4
  }
  if (*hostSlot != *reinterpret_cast<void**>(reinterpret_cast<char*>(client) + 0xf38)) {
    return; // ret 4
  }

  Client_OpenDialogByIndex(client, 10, 0, 0);

  void* missionDialog =
      *reinterpret_cast<void**>(reinterpret_cast<char*>(client) + 0x1058);
  MissionDialog_SetNpcObjectAndNameCaption_Inferred(missionDialog, npcOrClear);

  void* actor = *reinterpret_cast<void**>(reinterpret_cast<char*>(client) + 0xe98);
  if (actor == nullptr) {
    return; // ret 4
  }
  void* vehicle =
      *reinterpret_cast<void**>(reinterpret_cast<char*>(actor) + 0x250);
  if (vehicle == nullptr) {
    return; // ret 4
  }

  VehicleEntity_SetLongitudinalInput(vehicle, 0.0f);
  VehicleEntity_SetSteerInput(vehicle, 0.0f);
  // Machine: MOV [ESP+4],1 ; JMP VehicleEntity_SetHandbrake
  VehicleEntity_SetHandbrake(vehicle, 1);
}
