// =============================================================================
// FUN_00538ab0  (twin of DisciplineDefMap_ExactFindByIntKey_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00538ab0
// Address:   0x00538ab0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Dual:      R13-037 OWN-ONLY 2026-08-05 (dual start 2686)
// Exactness: Behavior-preserving rewrite of decompiler + asm-sealed CF.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime Confirmed: NOT claimed.
// =============================================================================
// Prefer named twin: DisciplineDefMap_ExactFindByIntKey_Inferred.cpp
// Scaffold name Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_00538ab0 retired.

#include <stdint.h>

extern "C" void *__thiscall DisciplineDefMap_ExactFindByIntKey_Inferred(
    void *self, void **pOut, const int *pKey);

extern "C" void *__thiscall FUN_00538ab0(void *param_1, void **param_2, const int *param_3)
{
  return DisciplineDefMap_ExactFindByIntKey_Inferred(param_1, param_2, param_3);
}
