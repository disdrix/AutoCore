// =============================================================================
// FUN_0054cbb0  — twin of CVOGHBSkill_PossessCreature_DefaultFactory_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0054cbb0
// Address:   0x0054cbb0–0x0054cc02  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-08-05 R12-023 dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
//
// Prefer the named clean:
//   CVOGHBSkill_PossessCreature_DefaultFactory_Inferred.cpp
// =============================================================================

#include <stdint.h>

extern void *PTR_FUN_009d1ba4;
// void *operator_new(uint32_t size);
// void *__fastcall CVOGHBSkillBase_DefaultCtor(void *self); // FUN_00578830

void *FUN_0054cbb0(void)
{
  void *p;

  p = operator_new(0x6f0);
  if (p == 0) {
    return 0;
  }
  CVOGHBSkillBase_DefaultCtor(p);
  *(uint32_t *)p = (uint32_t)(uintptr_t)&PTR_FUN_009d1ba4;
  return p;
}
