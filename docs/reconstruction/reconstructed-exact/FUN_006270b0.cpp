// =============================================================================
// FUN_006270b0 — Ghidra twin of CVOGHBSkill_AddSkillLevels_ctor
// -----------------------------------------------------------------------------
// Stable ID: aa_006270b0
// Address:   0x006270b0–0x00627160
// See:       CVOGHBSkill_AddSkillLevels_ctor.cpp  (named plate; RTTI Confirmed)
// R11-022 dual seal 2026-08-05
// =============================================================================

#include <cstdint>

// Named implementation
extern "C" std::uint32_t* __thiscall CVOGHBSkill_AddSkillLevels_ctor(
    std::uint32_t* self,
    void* pSource,
    void* pSkillBlob,
    void* arg4,
    void* pTarget,
    void* pTfid,
    void* arg7);

// Legacy Ghidra name — same ABI (__thiscall + ret 0x18)
std::uint32_t* __thiscall FUN_006270b0(
    std::uint32_t* param_1,
    void* param_2,
    void* param_3,
    void* param_4,
    void* param_5,
    void* param_6,
    void* param_7)
{
    return CVOGHBSkill_AddSkillLevels_ctor(
        param_1, param_2, param_3, param_4, param_5, param_6, param_7);
}
