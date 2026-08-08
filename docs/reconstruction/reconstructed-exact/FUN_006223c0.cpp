// =============================================================================
// FUN_006223c0  — scaffold twin of CVOGHBSkill_KillCharge_Ctor
// -----------------------------------------------------------------------------
// Stable ID: aa_006223c0
// Address:   0x006223c0  (autoassault.exe, image base 0x400000)
// Body:      0x006223c0 – 0x006223f3 inclusive (52 B / 0x34)
// System:    skills-abilities
// Generated: 2026-08-05 R11-019 dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Named twin: CVOGHBSkill_KillCharge_Ctor.cpp
// =============================================================================

#include <cstdint>

extern "C" void *__thiscall CVOGHBSkillBase_ctor(
    void *thisHb, void *p2, void *p3, void *p4, void *p5, void *p6,
    std::uint32_t p7);
extern "C" void *PTR_FUN_009d16e4;

// PURPOSE: CVOGHBSkill_KillCharge subclass ctor — base skill HB then vtbl install.
// RTTI Confirmed: .?AVCVOGHBSkill_KillCharge@@
// ABI: __thiscall; 6 stack args; ret 0x18; EAX = this.

extern "C" void *__thiscall FUN_006223c0(
    void *thisHb, void *param_2, void *param_3, void *param_4, void *param_5,
    void *param_6, std::uint32_t param_7)
{
  CVOGHBSkillBase_ctor(thisHb, param_2, param_3, param_4, param_5, param_6,
                       param_7);
  *static_cast<void **>(thisHb) = &PTR_FUN_009d16e4;
  return thisHb;
}
