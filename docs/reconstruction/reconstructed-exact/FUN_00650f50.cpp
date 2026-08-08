// =============================================================================
// FUN_00650f50  — legacy twin of CVOGHBSkill_XPAdder_ctor
// -----------------------------------------------------------------------------
// Stable ID: aa_00650f50
// Address:   0x00650f50 – 0x00650f8e  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-23 scaffold; R11-025 dual seal 2026-08-05
// Exactness: Behavior-preserving. Prefer CVOGHBSkill_XPAdder_ctor.cpp as named clean.
// =============================================================================

#include <cstdint>

extern "C" void* __thiscall CVOGHBSkillBase_ctor(
    void* self,
    void* pSourceObj,
    void* pSkillBlob,
    uint32_t arg4,
    void* pTarget,
    void* pTfid16,
    uint32_t arg7);

extern "C" void* PTR_FUN_009e5304[];

// Ghidra surface name (thiscall ECX=this; ret 0x18)
uint32_t* __thiscall FUN_00650f50(
    uint32_t* param_1 /*ECX*/,
    uint32_t param_2,
    uint32_t param_3,
    uint32_t param_4,
    uint32_t param_5,
    uint32_t param_6,
    uint32_t param_7)
{
  CVOGHBSkillBase_ctor(
      param_1,
      reinterpret_cast<void*>(static_cast<uintptr_t>(param_2)),
      reinterpret_cast<void*>(static_cast<uintptr_t>(param_3)),
      param_4,
      reinterpret_cast<void*>(static_cast<uintptr_t>(param_5)),
      reinterpret_cast<void*>(static_cast<uintptr_t>(param_6)),
      param_7);

  *param_1 = reinterpret_cast<uint32_t>(&PTR_FUN_009e5304[0]);

  // dword-index 0x1b0 == byte +0x6c0; retail uses MOVSS float zero
  *reinterpret_cast<float*>(reinterpret_cast<uint8_t*>(param_1) + 0x6c0) = 0.0f;

  return param_1;
}
