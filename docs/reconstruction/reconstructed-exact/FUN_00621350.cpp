// =============================================================================
// FUN_00621350  (scaffold twin of CVOGHBSkill_OnDoHit_Ctor)
// -----------------------------------------------------------------------------
// Stable ID: aa_00621350
// Address:   0x00621350  (autoassault.exe, image base 0x400000)
// Body:      0x00621350 – 0x00621383 inclusive (52 B / 0x34)
// System:    skills-abilities
// Generated: 2026-08-05 R11-017 dual (keeps FUN_* scaffold path)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: OPEN.
// =============================================================================

// PURPOSE: CVOGHBSkill_OnDoHit subclass ctor — base CVOGHBSkillBase_ctor then
// install vtbl PTR_FUN_009d15c4. RTTI Confirmed ".?AVCVOGHBSkill_OnDoHit@@".
// Named clean twin: CVOGHBSkill_OnDoHit_Ctor.cpp

#include <cstdint>

extern "C" void *__thiscall FUN_005788d0(void *thisHb, void *p2, void *p3,
                                         std::uint32_t p4, void *p5, void *p6,
                                         std::uint32_t p7);
extern "C" void *PTR_FUN_009d15c4;

extern "C" void *__thiscall FUN_00621350(void *param_1, void *param_2,
                                         void *param_3, std::uint32_t param_4,
                                         void *param_5, void *param_6,
                                         std::uint32_t param_7)
{
  auto *self = static_cast<std::uint32_t *>(param_1);

  FUN_005788d0(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
  *self = reinterpret_cast<std::uint32_t>(&PTR_FUN_009d15c4);
  return param_1;
}
