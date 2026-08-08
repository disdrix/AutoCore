// =============================================================================
// FUN_004cbe20  (named: StdMap_InsertOrFind_IntKey_Isnil29_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004cbe20
// Address:   0x004cbe20  (autoassault.exe, image base 0x400000)
// Body:      0x004cbe20–0x004cbed8 exclusive (184 B)
// System:    MSVC map insert-or-find isnil@+0x29 signed int key
// Agent:     WQ9F-D 2026-08-04 (scaffold refined)
// Exactness: Behavior-preserving. Prefer named twin:
//   StdMap_InsertOrFind_IntKey_Isnil29_Inferred.cpp
// Terminal:  false
// =============================================================================

// See named clean for full types. This twin keeps Ghidra symbol entry.

#include <cstdint>

struct MapNode_Isnil29;
struct MapShell_Isnil29;
struct InsertPair_Isnil29;
struct Val_IntKey_Isnil29;

void __thiscall StdMap_InsertOrFind_IntKey_Isnil29_Inferred(
    MapShell_Isnil29 *map,
    InsertPair_Isnil29 *out,
    const Val_IntKey_Isnil29 *value);

void __thiscall FUN_004cbe20(
    MapShell_Isnil29 *map,
    InsertPair_Isnil29 *out,
    const Val_IntKey_Isnil29 *value)
{
  StdMap_InsertOrFind_IntKey_Isnil29_Inferred(map, out, value);
}
