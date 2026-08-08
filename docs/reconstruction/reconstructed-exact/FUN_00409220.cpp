// =============================================================================
// FUN_00409220 — alias → Map_EraseNode_B
// Stable ID: aa_00409220 | WQ9E-G 2026-08-04
// Authoritative clean: Map_EraseNode_B.cpp
// =============================================================================

#include <cstdint>

struct NodeIsnil29;
struct MapShellIsnil29;

extern "C" void __thiscall Map_EraseNode_B(
    MapShellIsnil29* map,
    NodeIsnil29** outIt,
    NodeIsnil29* z);

extern "C" void __thiscall FUN_00409220(
    MapShellIsnil29* map,
    NodeIsnil29** outIt,
    NodeIsnil29* z)
{
  Map_EraseNode_B(map, outIt, z);
}
