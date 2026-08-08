// =============================================================================
// FUN_00401db0 — alias → StdTree_InsertAndRebalance_Isnil2D_Inferred
// Stable ID: aa_00401db0 | MEGA-066 2026-08-05
// Authoritative clean: StdTree_InsertAndRebalance_Isnil2D_Inferred.cpp
// =============================================================================

#include <cstdint>

struct NodeIsnil2D;
struct MapShellIsnil2D;

extern "C" void StdTree_InsertAndRebalance_Isnil2D_Inferred(
    /*EDI*/ MapShellIsnil2D* map,
    /*ECX*/ NodeIsnil2D* where,
    NodeIsnil2D** out,
    char addLeft,
    const void* value);

extern "C" void FUN_00401db0(
    /*EDI*/ MapShellIsnil2D* map,
    /*ECX*/ NodeIsnil2D* where,
    NodeIsnil2D** out,
    char addLeft,
    const void* value)
{
  StdTree_InsertAndRebalance_Isnil2D_Inferred(map, where, out, addLeft, value);
}
