// =============================================================================
// FUN_004cb4b0  (scaffold twin → StdMap_LowerBound_Tfid_Isnil29)
// -----------------------------------------------------------------------------
// Stable ID: aa_004cb4b0
// Address:   0x004cb4b0  (autoassault.exe, image base 0x400000)
// Wave:      W31-N 2026-07-29 — see StdMap_LowerBound_Tfid_Isnil29.cpp
// =============================================================================

#include <cstdint>

struct MapHost_Head4;
struct KeyU32I32;
struct Node_Isnil29;

extern "C" Node_Isnil29* __fastcall StdMap_LowerBound_Tfid_Isnil29(
    MapHost_Head4* self, const KeyU32I32* pKey);

extern "C" Node_Isnil29* __fastcall FUN_004cb4b0(
    MapHost_Head4* self, const KeyU32I32* pKey)
{
  return StdMap_LowerBound_Tfid_Isnil29(self, pKey);
}
