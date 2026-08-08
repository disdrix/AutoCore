// =============================================================================
// CVOGHBSkill_PossessCreature_ctor  (FUN_00626240)
// -----------------------------------------------------------------------------
// Stable ID: aa_00626240
// Address:   0x00626240–0x006262e4  (autoassault.exe, image base 0x400000)
// Body:      165 B / 0xA5; terminal ret 0x18; pad CC to 0x006262f0
// System:    skills-abilities
// Generated: 2026-08-05 R11-021 dual seal (raw 2026-07-23 + live re-verify)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
//
// Class:     CVOGHBSkill_PossessCreature
//            RTTI Confirmed COL@0x00aae5ec → TD@0x00afecec
//            ".?AVCVOGHBSkill_PossessCreature@@"
// Vtbl:      PTR_FUN_009d1ba4
// Size:      0x6f0 (operator_new at sole full-ctor site; type-table id 0x1a)
// Parent:    CVOGHBSkillBase_ctor (0x005788d0)
//
// PURPOSE:
//   Construct PossessCreature skill heartbeat:
//     1) CVOGHBSkillBase_ctor (skill blob, validate target, attach, period)
//     2) Install subclass vtbl 0x009d1ba4
//     3) Clear +0x6c8 / +0x6c4 / +0x6c9
//     4) dyn_cast pTarget ClonedObjectBase→Creature → +0x6c0
//     5) if cast fails: FUN_007a4480(0, "VOG_DEBUG_STOP") then still return this
//
// ABI: __thiscall; 6 stack args; ret 0x18; EAX = this
// =============================================================================

#include <stdint.h>

// External (sealed elsewhere / CRT):
// void *__thiscall CVOGHBSkillBase_ctor(void *self, void *pSource, void *pSkillBlob,
//                                       uint32_t arg4, void *pTarget, void *pTfid,
//                                       uint32_t arg7);
// void *__cdecl __RTDynamicCast(void *obj, long vfDelta, void *srcTD, void *targetTD,
//                               int isRef);
// void  __cdecl FUN_007a4480(int flag, const char *msg);

extern void *PTR_FUN_009d1ba4;
extern void *CVOGClonedObjectBase_RTTI_Type_Descriptor; // 0x00af8e10
extern void *CVOGCreature_RTTI_Type_Descriptor;         // 0x00af8d0c

// Layout (subclass tail after CVOGHBSkillBase):
//   +0x6c0  CVOGCreature*  (dyn_cast of pTarget)
//   +0x6c4  uint32_t       (ctor 0; secondary host/HB later)
//   +0x6c8  uint8_t        (ctor 0)
//   +0x6c9  uint8_t        (ctor 0)

void *__thiscall CVOGHBSkill_PossessCreature_ctor(
    void *self,
    void *pSourceObj,
    void *pSkillBlob,
    uint32_t arg4,
    void *pTarget,
    void *pTfid,
    uint32_t arg7)
{
  void *creature;

  /* SEH frame: LAB_009a8ae8; state -1 → 0 after base ctor — omitted in spirit */

  CVOGHBSkillBase_ctor(self, pSourceObj, pSkillBlob, arg4, pTarget, pTfid, arg7);

  *(uint32_t *)self = (uint32_t)(uintptr_t)&PTR_FUN_009d1ba4;
  *((uint8_t *)self + 0x6c8) = 0;
  *(uint32_t *)((char *)self + 0x6c4) = 0;
  *((uint8_t *)self + 0x6c9) = 0;

  creature = __RTDynamicCast(
      pTarget,
      0,
      &CVOGClonedObjectBase_RTTI_Type_Descriptor,
      &CVOGCreature_RTTI_Type_Descriptor,
      0);
  *(void **)((char *)self + 0x6c0) = creature;
  if (creature == 0) {
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }
  return self;
}

// Ghidra alias
void *__thiscall FUN_00626240(
    void *self,
    void *p2,
    void *p3,
    uint32_t p4,
    void *p5,
    void *p6,
    uint32_t p7)
{
  return CVOGHBSkill_PossessCreature_ctor(self, p2, p3, p4, p5, p6, p7);
}
