// =============================================================================
// FUN_00405bd0  (scaffold twin → StdMap_InsertOrFind_PairKey_Isnil29_EbxMap_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00405bd0
// Address:   0x00405bd0  (autoassault.exe, image base 0x400000)
// Body:      0x00405bd0–0x00405c7e inclusive (175 B / 0xAF)
// System:    MSVC std::map insert-or-find (isnil@+0x29, pair key)
// Generated: 2026-08-05 WQ9K-D dual seal
// Exactness: Behavior-preserving; meaningful names. Not modernization.
// Terminal:  false
// =============================================================================

#include <cstdint>

// See StdMap_InsertOrFind_PairKey_Isnil29_EbxMap_Inferred.cpp for full plate.

struct MapShell_Isnil29_Pair;
struct InsertPair_Isnil29;
struct Val_PairKey_Isnil29;

extern "C" InsertPair_Isnil29* StdMap_InsertOrFind_PairKey_Isnil29_EbxMap_Inferred(
    MapShell_Isnil29_Pair* map /*EBX*/,
    InsertPair_Isnil29* out /*ESI*/,
    const Val_PairKey_Isnil29* value /*EAX*/);

extern "C" InsertPair_Isnil29* FUN_00405bd0(
    MapShell_Isnil29_Pair* map /*EBX*/,
    InsertPair_Isnil29* out /*ESI*/,
    const Val_PairKey_Isnil29* value /*EAX*/)
{
  return StdMap_InsertOrFind_PairKey_Isnil29_EbxMap_Inferred(map, out, value);
}
