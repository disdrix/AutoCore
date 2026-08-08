// =============================================================================
// FUN_004cba00  (scaffold twin of StdMap_Find_Tfid_Isnil29_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004cba00
// Address:   0x004cba00  (autoassault.exe, image base 0x400000)
// Wave:      WQ9G-G 2026-08-04 — points at named clean
// =============================================================================

#include <cstdint>

// See StdMap_Find_Tfid_Isnil29_Inferred.cpp for sealed body, ABI, and notes.
// This twin exists for stable FUN_* path continuity.

struct KeyU32I32 {
  uint32_t lo;
  int32_t  hi;
};

struct Node_Isnil29;
struct MapHost_Head4;

extern "C" void __fastcall StdMap_Find_Tfid_Isnil29_Inferred(
    MapHost_Head4* self, Node_Isnil29** outIt, const KeyU32I32* pKey);

extern "C" void __fastcall FUN_004cba00(
    MapHost_Head4* self, Node_Isnil29** outIt, const KeyU32I32* pKey)
{
  StdMap_Find_Tfid_Isnil29_Inferred(self, outIt, pKey);
}
