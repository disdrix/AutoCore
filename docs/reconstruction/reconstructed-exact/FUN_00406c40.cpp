// =============================================================================
// FUN_00406c40 — alias → StdTree_InsertAndRebalance_Isnil29_Inferred
// Stable ID: aa_00406c40 | WQ9E-G 2026-08-04
// Authoritative clean: StdTree_InsertAndRebalance_Isnil29_Inferred.cpp
// =============================================================================

#include <cstdint>

struct NodeIsnil29;
struct MapShellIsnil29;

extern "C" void __thiscall StdTree_InsertAndRebalance_Isnil29_Inferred(
    MapShellIsnil29* map,
    NodeIsnil29** out,
    char addLeft,
    NodeIsnil29* where,
    const void* value);

extern "C" void __thiscall FUN_00406c40(
    MapShellIsnil29* map,
    NodeIsnil29** out,
    char addLeft,
    NodeIsnil29* where,
    const void* value)
{
  StdTree_InsertAndRebalance_Isnil29_Inferred(map, out, addLeft, where, value);
}
