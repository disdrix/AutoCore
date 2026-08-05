// =============================================================================
// Gfx_PalToolMaterialNoMap_0098df00  (plate-string alias — incomplete)
// -----------------------------------------------------------------------------
// Stable ID: aa_0098df00
// Prefer: PalToolNoMap_Host0x40_MaterialAndShadowVolInit_Inferred
// Also binds PalVisibleShadowVolume.fx ×2 — this short alias is incomplete.
// Kept for search continuity.
// =============================================================================

#include <cstdint>

extern "C" uint32_t PalToolNoMap_Host0x40_MaterialAndShadowVolInit_Inferred(void *host);

extern "C" uint32_t Gfx_PalToolMaterialNoMap_0098df00(void *host) {
  return PalToolNoMap_Host0x40_MaterialAndShadowVolInit_Inferred(host);
}
