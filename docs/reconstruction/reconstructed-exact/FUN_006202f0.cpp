// =============================================================================
// FUN_006202f0  — scaffold twin of CVOGHBSkill_SummonSnoop_Ctor
// -----------------------------------------------------------------------------
// Stable ID: aa_006202f0
// Address:   0x006202f0–0x00620323  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-23 scaffold; refined 2026-08-05 R11-016 dual
// Exactness: Behavior-preserving. Prefer named unit:
//            reconstructed-exact/CVOGHBSkill_SummonSnoop_Ctor.cpp
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

extern "C" void *__thiscall CVOGHBSkillBase_ctor(
    void *self, void *p2, void *p3, std::uint32_t p4, void *p5, void *p6,
    std::uint32_t p7);
extern "C" void *PTR_FUN_009d156c;

extern "C" void *__thiscall FUN_006202f0(
    void *param_1 /*this ECX*/,
    void *param_2,
    void *param_3,
    std::uint32_t param_4,
    void *param_5,
    void *param_6,
    std::uint32_t param_7)
{
  CVOGHBSkillBase_ctor(param_1, param_2, param_3, param_4, param_5, param_6,
                       param_7);
  *reinterpret_cast<void **>(param_1) = &PTR_FUN_009d156c;
  return param_1;
}
