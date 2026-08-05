// =============================================================================
// FUN_0099f450 — twin of Gfx_PalDiffMapFx_BindAndInitMesh_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0099f450
// Address:   0x0099f450–0x0099f5c3  (autoassault.exe, image base 0x400000)
// System:    gfx / PalDiffMap.fx host material + mesh init
// Generated: scaffold 2026-07-23; dual A/B seal 2026-07-29 (W36-I)
// Exactness: Behavior-preserving rewrite of decompiler + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
// See: Gfx_PalDiffMapFx_BindAndInitMesh_Inferred.cpp for named clean.

#include <cstdint>

extern "C" uint32_t Gfx_PalDiffMapFx_BindAndInitMesh_Inferred(void* host, uint32_t scale_bits);

extern "C" uint32_t FUN_0099f450(void* host, uint32_t scale_bits)
{
  return Gfx_PalDiffMapFx_BindAndInitMesh_Inferred(host, scale_bits);
}
