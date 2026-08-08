// =============================================================================
// FUN_00614c80  — legacy Ghidra name twin
// Canonical: CVOGHBSkill_Master_Execute  (see CVOGHBSkill_Master_Execute.cpp)
// Stable ID: aa_00614c80
// Address:   0x00614c80–0x00614d87
// Dual:      R11-011 2026-08-05
// =============================================================================

#include <cstdint>

// Full plate lives in CVOGHBSkill_Master_Execute.cpp.
// This twin preserves the Ghidra symbol for path-stable includes.

extern uint32_t __thiscall CVOGHBSkill_Master_Execute(
    void *self,
    void *skillOrSource,
    void *a2,
    int mapWorld,
    void *targetTable,
    void *a5,
    void *a6);

uint32_t __thiscall FUN_00614c80(
    void *self,
    void *param_1,
    void *param_2,
    int param_3,
    void *param_4,
    void *param_5,
    void *param_6)
{
  return CVOGHBSkill_Master_Execute(
      self, param_1, param_2, param_3, param_4, param_5, param_6);
}
