// =============================================================================
// FUN_005e0610  (scaffold twin → LootCatalog_TallyObjectAndEnqueueNotify_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_005e0610
// Address:   0x005e0610  (autoassault.exe, image base 0x400000)
// Wave:      W37-AA 2026-08-04 — prefer named clean source
// =============================================================================

// Full bytes-corrected body lives in:
//   LootCatalog_TallyObjectAndEnqueueNotify_Inferred.cpp
// This twin keeps the Ghidra symbol as an extern alias entry.

#include <cstdint>

struct LootCatalogManagerOpaque;
struct GameObjectOpaque;

extern "C" void __thiscall LootCatalog_TallyObjectAndEnqueueNotify_Inferred(
    LootCatalogManagerOpaque* mgr,
    GameObjectOpaque* obj,
    int bandIndex,
    int notifyPath);

extern "C" void __thiscall FUN_005e0610(
    LootCatalogManagerOpaque* mgr,
    GameObjectOpaque* obj,
    int bandIndex,
    int notifyPath)
{
    LootCatalog_TallyObjectAndEnqueueNotify_Inferred(mgr, obj, bandIndex, notifyPath);
}
