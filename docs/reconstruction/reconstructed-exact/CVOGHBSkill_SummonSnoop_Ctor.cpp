// =============================================================================
// CVOGHBSkill_SummonSnoop_Ctor  (FUN_006202f0)
// -----------------------------------------------------------------------------
// Stable ID: aa_006202f0
// Address:   0x006202f0–0x00620323  (autoassault.exe, image base 0x400000)
// Body size: 52 bytes (0x34) inclusive of ret 0x18
// System:    skills-abilities
// Generated: 2026-07-23 scaffold as FUN_006202f0; dual A/B seal 2026-08-05 R11-016
// Exactness: Behavior-preserving rewrite of decompiler + entry-byte CF.
//            Not modernization. Bit-for-bit vs retail: DEFERRED.
// =============================================================================
//
// Class:     CVOGHBSkill_SummonSnoop
//            RTTI Confirmed ".?AVCVOGHBSkill_SummonSnoop@@"
//            COL @ 0x00aae154 → type_info @ 0x00afed18
// Vtbl:      PTR_FUN_009d156c
// Size:      0x6c0 (operator_new from Skill_SpawnTemplateAndStartHB)
//
// PURPOSE
//   Construct CVOGHBSkill_SummonSnoop heartbeat action:
//     1. CVOGHBSkillBase_ctor (base skill HB: blob, ValidateTarget, AttachOwner, period)
//     2. Install subclass vtbl PTR_FUN_009d156c
//   No subclass-local field stores in this unit.
//
// ABI (retail)
//   __thiscall this in ECX
//   stack: (pSourceObj, pSkillBlob, arg4, pTarget, pTfid16, arg7) → ret 0x18
//   return: this* in EAX
//
// SOLE CALLER
//   Skill_SpawnTemplateAndStartHB (FUN_00620480) @ 0x006208f4
//     operator_new(0x6c0) → this ctor → (owner null ? dtor : Enqueue+Start)
//
// VTABLE peers (context; not dualled here)
//   +0x00  FUN_00651190  scalar deleting dtor
//   +0x04  FUN_00620340  OnHeartBeat-like tick
//   +0x2c  0x00620480    Skill_SpawnTemplateAndStartHB (also DATA @ 0x009d1598)
//

#include <cstdint>

// Base ctor (sealed elsewhere as CVOGHBSkillBase_ctor / aa_005788d0)
extern "C" void *__thiscall CVOGHBSkillBase_ctor(
    void *self /*ECX*/,
    void *pSourceObj,
    void *pSkillBlob,
    std::uint32_t arg4,
    void *pTarget,
    void *pTfid16,
    std::uint32_t arg7);

// Image data (subclass vtbl)
extern "C" void *PTR_FUN_009d156c;

extern "C" void *__thiscall CVOGHBSkill_SummonSnoop_Ctor(
    void *self /*ECX*/,
    void *pSourceObj,
    void *pSkillBlob,
    std::uint32_t arg4,
    void *pTarget,
    void *pTfid16,
    std::uint32_t arg7)
{
  CVOGHBSkillBase_ctor(self, pSourceObj, pSkillBlob, arg4, pTarget, pTfid16, arg7);
  *reinterpret_cast<void **>(self) = &PTR_FUN_009d156c;
  return self;
}

// Ghidra alias
extern "C" void *__thiscall FUN_006202f0(
    void *self,
    void *pSourceObj,
    void *pSkillBlob,
    std::uint32_t arg4,
    void *pTarget,
    void *pTfid16,
    std::uint32_t arg7)
{
  return CVOGHBSkill_SummonSnoop_Ctor(self, pSourceObj, pSkillBlob, arg4, pTarget,
                                      pTfid16, arg7);
}
