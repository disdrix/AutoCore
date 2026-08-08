// =============================================================================
// FUN_00617fc0  — twin of CVOGHBSkill_Reflect_SpawnActionsForTargetList_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00617fc0
// Address:   0x00617fc0  (autoassault.exe, image base 0x400000)
// Body:      0x00617fc0 – 0x006180fb inclusive (316 B / 0x13C)
// System:    skills-abilities
// Generated: 2026-08-05 R12-039 dual seal (machine-name twin)
// See:       CVOGHBSkill_Reflect_SpawnActionsForTargetList_Inferred.cpp
// =============================================================================

#include <cstdint>

// Forward to named clean unit (same body; Ghidra symbol retained for ledger twin).
extern "C" std::uint32_t __stdcall
CVOGHBSkill_Reflect_SpawnActionsForTargetList_Inferred(
    void *pSourceObj, void *pSkillBlob, void *pWorld, void *pList,
    void *pTfid16, std::uint32_t arg7);

extern "C" std::uint32_t __stdcall FUN_00617fc0(
    void *param_1, void *param_2, void *param_3, void *param_4, void *param_5,
    std::uint32_t param_6)
{
  return CVOGHBSkill_Reflect_SpawnActionsForTargetList_Inferred(
      param_1, param_2, param_3, param_4, param_5, param_6);
}
