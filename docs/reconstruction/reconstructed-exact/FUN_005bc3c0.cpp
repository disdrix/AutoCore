// =============================================================================
// FUN_005bc3c0  (scaffold twin of Emitter_UpdateTick_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_005bc3c0
// Address:   0x005bc3c0 – 0x005bdce6 exclusive  (6438 B / 0x1926)
// System:    client::fx / emitter
// Generated: 2026-07-29 W28-I dual seal
// Prefer named clean: Emitter_UpdateTick_Inferred.cpp
// Full decompiler body: docs/reconstruction/raw/aa_005bc3c0_FUN_005bc3c0.md
// Exactness: Twin points at staged named clean; raw remains authority for math.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// =============================================================================

// PURPOSE: Per-frame emitter update for NDSpecialFX HostTick list +0x1E0.
// ABI: __thiscall ECX=emitter; stack (float* dt, int host_field_2c, int camera_or_world);
//      ret 0x0C; return 0=remove, 1=keep.
// String: "Emitter found at 0,0,0: %d %I64d"
// Child: Emitter_SpawnOnIntervalTick_Inferred (FUN_005bc120)

#include <cstdint>

// Forward to staged reconstruction — full expression dump is in raw capture.
uint32_t __thiscall Emitter_UpdateTick_Inferred(int *emitter, float *dt,
                                                int host_field_2c,
                                                int camera_or_world);

uint32_t __thiscall FUN_005bc3c0(int *param_1, float *param_2, int param_3, int param_4)
{
  return Emitter_UpdateTick_Inferred(param_1, param_2, param_3, param_4);
}
