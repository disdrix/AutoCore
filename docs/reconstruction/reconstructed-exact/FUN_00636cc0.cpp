// =============================================================================
// FUN_00636cc0  (FUN twin of CVOGHBMoveVehicle_OnHeartBeat)
// -----------------------------------------------------------------------------
// Stable ID: aa_00636cc0
// Address:   0x00636cc0  (autoassault.exe, image base 0x400000)
// Body:      0x00636cc0 – 0x00636d07 inclusive (72 B / 0x48)
// System:    input-drive-control / heartbeat OnHeartBeat
// Generated: 2026-08-05 R11-023 dual seal
// Exactness: Behavior-preserving; machine CF supersedes scaffold decompiler paste.
// Named twin: CVOGHBMoveVehicle_OnHeartBeat.cpp
// =============================================================================

#include <cstdint>

// Prefer the named unit for port work:
//   docs/reconstruction/reconstructed-exact/CVOGHBMoveVehicle_OnHeartBeat.cpp

struct VehicleEntity;

extern uint32_t __thiscall FUN_004fc650(
    VehicleEntity *self,
    float acceptDist,
    float cruiseScale,
    void *aimUnused,
    char allowReverse);

extern void __fastcall FUN_005081d0(void *hbSelf);

extern uint32_t DAT_00af4f84; // 1
extern uint32_t DAT_00d02c60; // 0

uint32_t *__thiscall FUN_00636cc0(int param_1, uint32_t *param_2)
{
  auto *const base = reinterpret_cast<char *>(param_1);
  VehicleEntity *entity =
      *reinterpret_cast<VehicleEntity **>(base + 0x24);

  if (entity == nullptr) {
    *param_2 = DAT_00af4f84;
    return param_2;
  }

  const float acceptDist = *reinterpret_cast<float *>(base + 0x2c);
  const float cruiseScale = *reinterpret_cast<float *>(base + 0x30);
  void *const aimUnused = *reinterpret_cast<void **>(base + 0x34);

  const uint32_t ok =
      FUN_004fc650(entity, acceptDist, cruiseScale, aimUnused, 1);

  if (ok == 0) {
    FUN_005081d0(reinterpret_cast<void *>(param_1));
  }

  *param_2 = DAT_00d02c60;
  return param_2;
}
