// =============================================================================
// FUN_00725a70
// -----------------------------------------------------------------------------
// Stable ID: aa_00725a70
// Address:   0x00725a70 – 0x00725bcd
// Prefer:    CSoundManager_TryQueueMissionCompleteSound_Inferred.cpp
// Generated: 2026-07-29 W18-R dual A/B (scaffold redirect)
// =============================================================================

// Thin scaffold name kept for stable-ID greps. Implementation lives in the
// named clean unit; this file re-exports the same CF for tooling that keys on
// FUN_* paths.

#include <cstdint>

uint32_t __thiscall CSoundManager_TryQueueMissionCompleteSound_Inferred(
    int this_mgr, void *path_or_key, float *world_pos);

uint32_t __thiscall FUN_00725a70(int this_mgr, void *path_or_key, float *world_pos)
{
  return CSoundManager_TryQueueMissionCompleteSound_Inferred(this_mgr, path_or_key, world_pos);
}
