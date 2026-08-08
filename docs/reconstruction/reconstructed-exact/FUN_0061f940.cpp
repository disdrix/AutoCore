// =============================================================================
// FUN_0061f940  (scaffold alias → CVOGHBSkill_Virus_Ctor)
// -----------------------------------------------------------------------------
// Stable ID: aa_0061f940
// Address:   0x0061f940  (autoassault.exe, image base 0x400000)
// Body:      0x0061f940 – 0x0061f998 inclusive (89 B)
// System:    skills-abilities
// Generated: 2026-08-04 WQ9D-B dual seal (supersedes 2026-07-23 scaffold paste)
// Exactness: Behavior-preserving; prefer named clean CVOGHBSkill_Virus_Ctor.cpp
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// See: docs/reconstruction/reconstructed-exact/CVOGHBSkill_Virus_Ctor.cpp

#include <cstdint>

extern "C" void *__thiscall FUN_00618180(void *thisHb, void *p2, void *p3,
                                         void *p4, void *p5, void *p6,
                                         std::uint32_t p7, std::uint8_t flag0,
                                         float fOne);
extern "C" void __thiscall CVOGHBBase_SetPeriodAndCounter(void *thisHb,
                                                          int period,
                                                          bool reset);
extern "C" void *PTR_FUN_009d14bc;

extern "C" std::uint32_t *__thiscall FUN_0061f940(
    std::uint32_t *param_1, void *param_2, void *param_3, void *param_4,
    void *param_5, void *param_6, std::uint32_t param_7, std::uint32_t param_8,
    int param_9)
{
  // Matches live decompile: base thiscall with stack args param_2..param_7,0,1.0f
  FUN_00618180(param_1, param_2, param_3, param_4, param_5, param_6, param_7, 0,
               1.0f /*0x3f800000*/);
  param_1[0x1b4] = param_8;
  *param_1 = reinterpret_cast<std::uint32_t>(&PTR_FUN_009d14bc);
  param_1[0x1b5] = static_cast<std::uint32_t>(param_9);
  CVOGHBBase_SetPeriodAndCounter(param_1, param_9, true);
  return param_1;
}
