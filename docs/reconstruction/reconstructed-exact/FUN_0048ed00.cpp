// =============================================================================
// FUN_0048ed00  (twin of PalantirEnv_InitEffectTextures_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0048ed00
// Address:   0x0048ed00-0x0048ed81 exclusive (129 B / 0x81)
// System:    client / Palantir env effect textures
// Generated: 2026-07-29 W32-R dual seal (supersedes 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler CF + read_memory seals.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// Named twin: PalantirEnv_InitEffectTextures_Inferred.cpp
// Reject: Named_CalleeOf_Drive_NDRiver_fx_0048ed00

#include <cstdint>

extern "C" int32_t __thiscall FUN_0096f0e0(void *slot,
                                           uint32_t format,
                                           void *dims,
                                           uint32_t a3,
                                           uint32_t a4,
                                           uint32_t a5,
                                           void *related);

extern "C" int DAT_00d1f058;

// __thiscall; ECX=param_1 env*; bare RET; void
void __fastcall FUN_0048ed00(int param_1)
{
  auto *e = reinterpret_cast<uint8_t *>(param_1);
  int device = *reinterpret_cast<int *>(DAT_00d1f058 + 0x2c);
  int local_4;
  int local_8;

  FUN_0096f0e0(e + 0xDC,
               0x15,
               reinterpret_cast<void *>(device + 0x80),
               1,
               0x4011,
               0,
               e + 0xD4);

  local_4 = *reinterpret_cast<int *>(device + 0x84) / 2;
  local_8 = *reinterpret_cast<int *>(device + 0x80) / 2;
  {
    int halfDims[2] = {local_8, local_4};
    FUN_0096f0e0(e + 0xE0, 0x15, halfDims, 1, 0x4011, 0, nullptr);
  }
}
