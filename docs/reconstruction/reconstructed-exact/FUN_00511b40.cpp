// =============================================================================
// FUN_00511b40  — twin export for Ghidra symbol path
// -----------------------------------------------------------------------------
// Stable ID: aa_00511b40
// Address:   0x00511b40  (autoassault.exe, image base 0x400000)
// Canonical: StdMap_InsertOrFind_IntKey_Isnil21_Inferred
// Agent:     R13-031 OWN-ONLY dual 2026-08-05
// Terminal:  false
// =============================================================================

// Full meaningful reconstruction lives in:
//   StdMap_InsertOrFind_IntKey_Isnil21_Inferred.cpp
// This twin keeps the Ghidra symbol name for path continuity.

#include <cstdint>

struct MapNode_Isnil21_Node24;
struct MapShell_Isnil21_Node24;
struct InsertPair_Isnil21;
struct Val_IntKey_Isnil21;

void __thiscall StdMap_InsertOrFind_IntKey_Isnil21_Inferred(
    MapShell_Isnil21_Node24 *map,
    InsertPair_Isnil21 *out,
    const Val_IntKey_Isnil21 *value);

void __thiscall FUN_00511b40(
    MapShell_Isnil21_Node24 *map,
    InsertPair_Isnil21 *out,
    const Val_IntKey_Isnil21 *value)
{
  StdMap_InsertOrFind_IntKey_Isnil21_Inferred(map, out, value);
}
