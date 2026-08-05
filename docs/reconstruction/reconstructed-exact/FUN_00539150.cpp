// =============================================================================
// FUN_00539150 — scaffold alias → MissionStagingTree_EraseRange
// Stable ID: aa_00539150
// Address:   0x00539150
// Dual seal: W24-L 2026-07-29
// Prefer:    reconstructed-exact/MissionStagingTree_EraseRange.cpp
// =============================================================================

#include <stdint.h>

void __thiscall MissionStagingTree_EraseRange(
    void *map, void **outIter, void *first, void *last);

void __thiscall FUN_00539150(
    int param_1, uint32_t *param_2, int *param_3, int *param_4)
{
  MissionStagingTree_EraseRange(
      (void *)param_1, (void **)param_2, (void *)param_3, (void *)param_4);
}
