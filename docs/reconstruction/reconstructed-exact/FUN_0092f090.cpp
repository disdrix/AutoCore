// =============================================================================
// FUN_0092f090  — twin of MissionUI_ParkDriveAxes_Inferred (aa_0092f090)
// -----------------------------------------------------------------------------
// Address:   0x0092f090–0x0092f0d1 inclusive (66 B / 0x42)
// Wave:      MEGA-021 OWN-ONLY dual 2026-08-05
// System:    input-drive-control
// Canonical: MissionUI_ParkDriveAxes_Inferred
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

extern "C" void __thiscall VehicleEntity_SetLongitudinalInput(void* self, float longitudinal);
extern "C" void __thiscall VehicleEntity_SetSteerInput(void* self, float steer);
extern "C" void __thiscall VehicleEntity_SetHandbrake(void* self, uint8_t handbrake);

// Retail ABI: ESI = client host*; void; bare RET (C3).
extern "C" void FUN_0092f090(void /* ESI = client host */)
{
  void* client;
  void* character;
  void* vehicle;

#if defined(_MSC_VER) && defined(_M_IX86)
  __asm {
    mov client, esi
  }
#else
  client = nullptr;
#endif

  character = *reinterpret_cast<void**>(
      reinterpret_cast<uint8_t*>(client) + 0xe98);
  if (character == nullptr)
    return;

  vehicle = *reinterpret_cast<void**>(
      reinterpret_cast<uint8_t*>(character) + 0x250);
  if (vehicle == nullptr)
    return;

  character = *reinterpret_cast<void**>(
      reinterpret_cast<uint8_t*>(client) + 0xe98);
  vehicle = *reinterpret_cast<void**>(
      reinterpret_cast<uint8_t*>(character) + 0x250);
  VehicleEntity_SetLongitudinalInput(vehicle, 0.0f);

  character = *reinterpret_cast<void**>(
      reinterpret_cast<uint8_t*>(client) + 0xe98);
  vehicle = *reinterpret_cast<void**>(
      reinterpret_cast<uint8_t*>(character) + 0x250);
  VehicleEntity_SetSteerInput(vehicle, 0.0f);

  character = *reinterpret_cast<void**>(
      reinterpret_cast<uint8_t*>(client) + 0xe98);
  vehicle = *reinterpret_cast<void**>(
      reinterpret_cast<uint8_t*>(character) + 0x250);
  VehicleEntity_SetHandbrake(vehicle, 1);
}
