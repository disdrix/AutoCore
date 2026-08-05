// =============================================================================
// PalantirEnv_InitEffectTextures_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0048ed00
// Address:   0x0048ed00-0x0048ed81 exclusive (129 B / 0x81)
// System:    client / Palantir env effect textures (effTexture.cpp)
// Generated: 2026-07-29 W32-R dual seal
// Exactness: Behavior-preserving rewrite of decompiler CF + read_memory seals.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
// Env method (ECX=env*) that creates/binds two A8R8G8B8 effect textures via
// FUN_0096f0e0 (effTexture.cpp): full display dims into slot env+0xDC (related
// env+0xD4), half dims into slot env+0xE0 (related null).
// Sole caller: PalantirEnv_InitPhases_Inferred after light rebuild.
// Reject scaffold Named_CalleeOf_Drive_NDRiver_fx_0048ed00.

#include <cstdint>

// thiscall: slot holder int* at ECX stores created texture instance*
extern "C" int32_t __thiscall FUN_0096f0e0(void *slot,
                                           uint32_t format,
                                           void *dims,
                                           uint32_t a3,
                                           uint32_t a4,
                                           uint32_t a5,
                                           void *related);

extern "C" int DAT_00d1f058;

// __thiscall; ECX=env*; bare RET; void
void __thiscall PalantirEnv_InitEffectTextures_Inferred(void *env)
{
  auto *e = reinterpret_cast<uint8_t *>(env);
  int device = *reinterpret_cast<int *>(DAT_00d1f058 + 0x2c);
  int halfW;
  int halfH;
  int halfDims[2];

  // full-res → slot +0xDC; related +0xD4
  FUN_0096f0e0(e + 0xDC,
               /*format*/ 0x15, // D3DFMT_A8R8G8B8
               reinterpret_cast<void *>(device + 0x80),
               1,
               0x4011,
               0,
               e + 0xD4);

  halfH = *reinterpret_cast<int *>(device + 0x84) / 2;
  halfW = *reinterpret_cast<int *>(device + 0x80) / 2;
  halfDims[0] = halfW;
  halfDims[1] = halfH;

  // half-res → slot +0xE0; related null
  FUN_0096f0e0(e + 0xE0, 0x15, halfDims, 1, 0x4011, 0, nullptr);
}
