// =============================================================================
// FUN_00626240  (alias of CVOGHBSkill_PossessCreature_ctor)
// -----------------------------------------------------------------------------
// Stable ID: aa_00626240
// Address:   0x00626240–0x006262e4  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-08-05 R11-021 dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Named twin: CVOGHBSkill_PossessCreature_ctor.cpp
// RTTI:      .?AVCVOGHBSkill_PossessCreature@@  (Confirmed)
// =============================================================================

#include <stdint.h>

extern void *__thiscall CVOGHBSkillBase_ctor(
    void *self, void *pSource, void *pSkillBlob, uint32_t arg4,
    void *pTarget, void *pTfid, uint32_t arg7);
extern void *__cdecl __RTDynamicCast(
    void *obj, long vfDelta, void *srcTD, void *targetTD, int isRef);
extern void __cdecl FUN_007a4480(int flag, const char *msg);
extern void *PTR_FUN_009d1ba4;
extern void *CVOGClonedObjectBase_RTTI_Type_Descriptor;
extern void *CVOGCreature_RTTI_Type_Descriptor;

void *__thiscall FUN_00626240(
    void *self,
    void *param_2,
    void *param_3,
    uint32_t param_4,
    void *param_5,
    void *param_6,
    uint32_t param_7)
{
  void *creature;

  CVOGHBSkillBase_ctor(self, param_2, param_3, param_4, param_5, param_6, param_7);

  *(uint32_t *)self = (uint32_t)(uintptr_t)&PTR_FUN_009d1ba4;
  *((uint8_t *)self + 0x6c8) = 0;
  *(uint32_t *)((char *)self + 0x6c4) = 0;
  *((uint8_t *)self + 0x6c9) = 0;

  creature = __RTDynamicCast(
      param_5, 0,
      &CVOGClonedObjectBase_RTTI_Type_Descriptor,
      &CVOGCreature_RTTI_Type_Descriptor,
      0);
  *(void **)((char *)self + 0x6c0) = creature;
  if (creature == 0) {
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }
  return self;
}
