// =============================================================================
// FUN_005e2670 — twin of EdRiverHandle_StampPolylineHeightGrid_Inferred
// Stable ID: aa_005e2670  |  Dual W36-D 2026-07-29
// Canonical: docs/reconstruction/reconstructed-exact/EdRiverHandle_StampPolylineHeightGrid_Inferred.cpp
// =============================================================================

#include <cstdint>

struct MapHeightGrid;

extern "C" void EdRiverHandle_StampPolylineHeightGrid_Inferred(
    void* host /*ECX*/,
    MapHeightGrid* map,
    uint32_t argA,
    float argB,
    uint32_t argC);

extern "C" void FUN_005e2670(
    void* host /*ECX*/,
    MapHeightGrid* map,
    uint32_t argA,
    float argB,
    uint32_t argC)
{
  EdRiverHandle_StampPolylineHeightGrid_Inferred(host, map, argA, argB, argC);
}
