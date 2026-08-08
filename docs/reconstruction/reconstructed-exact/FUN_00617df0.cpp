// =============================================================================
// FUN_00617df0  — scaffold twin / Ghidra alias
// -----------------------------------------------------------------------------
// Stable ID: aa_00617df0
// Address:   0x00617df0  (autoassault.exe, image base 0x400000)
// Body:      0x00617df0 – 0x00617f2c inclusive (317 B / 0x13D)
// System:    skills-abilities
// Generated: 2026-08-05 R11-013 dual seal (refined from 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite. Prefer named clean source.
// Named:     CVOGHBSkill_OnHit_SpawnActionsForTargetList_Inferred.cpp
// =============================================================================

#include <cstdint>

// Forward to named reconstruction (same TU-level contract).
extern "C" std::uint32_t __stdcall
CVOGHBSkill_OnHit_SpawnActionsForTargetList_Inferred(
    void *pSourceObj, void *pSkillBlob, void *pWorld, void *pList,
    void *pTfid16, std::uint32_t arg7);

extern "C" std::uint32_t __stdcall FUN_00617df0(
    void *param_1, void *param_2, void *param_3, void *param_4, void *param_5,
    std::uint32_t param_6)
{
  return CVOGHBSkill_OnHit_SpawnActionsForTargetList_Inferred(
      param_1, param_2, param_3, param_4, param_5, param_6);
}

/*
 * Sealed CF summary (see named .cpp for full body):
 *   SEH LAB_009a86ab
 *   for index=0..:
 *     entry = param_4 + index*0x10
 *     if {-1,-1,type0}: return 1
 *     target = ResolveObjectTarget(*(param_3+0xe4e8), type, id0, id1)
 *     if target:
 *       p = new(0x6d0)
 *       if p: CVOGHBSkillBase_ctor(...); vtbl=PTR_FUN_009d0f1c;
 *             period from skill+0x4c → +0x6c0/+0x6c4
 *       if p->owner(+0x18): Enqueue(*(param_3+0xe4ec)); Start
 *       else: vtbl[0](1)  // FUN_00651190
 *     index++
 *   RET 0x18
 *
 * RTTI: CVOGHBSkill_OnHit @ COL 0x00aadbc4 / type_info 0x00af1d60
 * Vtbl slot +0x2c @ 0x009d0f48
 */
