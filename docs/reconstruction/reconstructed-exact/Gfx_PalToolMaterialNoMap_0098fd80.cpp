// =============================================================================
// Gfx_PalToolMaterialNoMap_0098fd80  (plate-string alias — incomplete)
// -----------------------------------------------------------------------------
// Stable ID: aa_0098fd80
// Prefer: PalToolNoMap_Host0x30_MaterialSlot0x28_Init_Inferred
// Plate "PalToolMaterialNoMap.fx" is Confirmed; Host0x30 / +0x28 role is not
// captured by this short alias. Kept for search continuity.
// =============================================================================

#include <cstdint>

extern "C" uint32_t PalToolNoMap_Host0x30_MaterialSlot0x28_Init_Inferred(void *host);

extern "C" uint32_t Gfx_PalToolMaterialNoMap_0098fd80(void *host) {
  return PalToolNoMap_Host0x30_MaterialSlot0x28_Init_Inferred(host);
}
