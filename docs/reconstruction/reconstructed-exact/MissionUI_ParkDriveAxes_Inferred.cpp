// =============================================================================
// MissionUI_ParkDriveAxes_Inferred  (aa_0092f090)
// -----------------------------------------------------------------------------
// Address:   0x0092f090–0x0092f0d1 inclusive (66 B / 0x42)
// Wave:      MEGA-021 OWN-ONLY dual 2026-08-05
// System:    input-drive-control / Mission-UI axis park
// Exactness: Behavior-preserving rewrite from decompile + disassemble_function
//            + read_memory + caller context. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Mission / NPC dialog UI axis park. When the client has a character
//   (client+0xe98) with a vehicle entity (character+0x250), zero longitudinal
//   and steer inputs and engage handbrake via the dualed VehicleEntity setters:
//     thr  = 0  → VehicleEntity_SetLongitudinalInput  (0x004f5650, +0x614, 0xC7 gate)
//     steer= 0  → VehicleEntity_SetSteerInput         (0x004f5620, +0x618, 0xC7 gate)
//     HB   = 1  → VehicleEntity_SetHandbrake          (0x004f3620, +0x61c, ungated)
//
// ABI:
//   ESI = client host*. No stack formals. void. Bare RET (C3).
//   All five call sites seed ESI from EBP immediately before CALL.
//
// CALLERS:
//   Client_ShowNpcMissionDialogUI @ 0x00943989, 0x00943b72
//   FUN_0093e450                      @ 0x0093e6ce, 0x0093e745, 0x0093e76f
//
// RETIRED SCAFFOLD:
//   Named_CalleeOf_Client_ShowNpcMissionDialogUI_0092f090
//   (parent-seed only; misses FUN_0093e450 and role).
// =============================================================================

#include <cstdint>

// Client layout fragments used here (not a full class def):
//   +0xe98  character*
// Character layout fragment:
//   +0x250  vehicleEntity*   (ECX for VehicleEntity_* setters)

// Dualed callees (thiscall: this in ECX; stack arg; ret 4)
extern "C" void __thiscall VehicleEntity_SetLongitudinalInput(void* self, float longitudinal);
extern "C" void __thiscall VehicleEntity_SetSteerInput(void* self, float steer);
extern "C" void __thiscall VehicleEntity_SetHandbrake(void* self, uint8_t handbrake);

// ESI-this custom convention (not MSVC thiscall ECX).
extern "C" void MissionUI_ParkDriveAxes_Inferred(void /* ESI = client host */)
{
  void* client;
  void* character;
  void* vehicle;

#if defined(_MSC_VER) && defined(_M_IX86)
  __asm {
    mov client, esi
  }
#else
  // Non-MSVC rebuilds must pass client explicitly; retail ABI is ESI.
  client = nullptr;
#endif

  // MOV EAX,[ESI+0xe98]; TEST EAX,EAX; JZ ret
  character = *reinterpret_cast<void**>(
      reinterpret_cast<uint8_t*>(client) + 0xe98);
  if (character == nullptr)
    return;

  // MOV ECX,[EAX+0x250]; TEST ECX,ECX; JZ ret
  vehicle = *reinterpret_cast<void**>(
      reinterpret_cast<uint8_t*>(character) + 0x250);
  if (vehicle == nullptr)
    return;

  // PUSH 0; CALL SetLongitudinalInput  — reloads vehicle from ESI chain
  character = *reinterpret_cast<void**>(
      reinterpret_cast<uint8_t*>(client) + 0xe98);
  vehicle = *reinterpret_cast<void**>(
      reinterpret_cast<uint8_t*>(character) + 0x250);
  VehicleEntity_SetLongitudinalInput(vehicle, 0.0f);

  // PUSH 0; CALL SetSteerInput
  character = *reinterpret_cast<void**>(
      reinterpret_cast<uint8_t*>(client) + 0xe98);
  vehicle = *reinterpret_cast<void**>(
      reinterpret_cast<uint8_t*>(character) + 0x250);
  VehicleEntity_SetSteerInput(vehicle, 0.0f);

  // PUSH 1; CALL SetHandbrake
  character = *reinterpret_cast<void**>(
      reinterpret_cast<uint8_t*>(client) + 0xe98);
  vehicle = *reinterpret_cast<void**>(
      reinterpret_cast<uint8_t*>(character) + 0x250);
  VehicleEntity_SetHandbrake(vehicle, 1);
}

// Ghidra twin name
extern "C" void FUN_0092f090(void);
