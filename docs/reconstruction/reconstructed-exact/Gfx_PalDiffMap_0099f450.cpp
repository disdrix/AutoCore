// =============================================================================
// Gfx_PalDiffMap_0099f450 — legacy scaffold alias
// -----------------------------------------------------------------------------
// Stable ID: aa_0099f450
// Canonical sealed name: Gfx_PalDiffMapFx_BindAndInitMesh_Inferred (W36-I)
// Address:   0x0099f450–0x0099f5c3
// =============================================================================
// Prefer Gfx_PalDiffMapFx_BindAndInitMesh_Inferred.cpp

#include <cstdint>

extern "C" uint32_t Gfx_PalDiffMapFx_BindAndInitMesh_Inferred(void* host, uint32_t scale_bits);

extern "C" uint32_t Gfx_PalDiffMap_0099f450(void* host, uint32_t scale_bits)
{
  return Gfx_PalDiffMapFx_BindAndInitMesh_Inferred(host, scale_bits);
}
