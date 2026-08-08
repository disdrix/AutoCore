// =============================================================================
// FUN_00617ad0 — twin of CVOGHBSkill_OnHit_ctor
// -----------------------------------------------------------------------------
// Stable ID: aa_00617ad0
// Address:   0x00617ad0  (autoassault.exe, image base 0x400000)
// Body:      0x00617ad0 – 0x00617b33 (100 B / 0x64)
// System:    skills-abilities
// Generated: 2026-08-05 R11-012 dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Canonical clean: CVOGHBSkill_OnHit_ctor.cpp
// Scaffold Named_CalleeOf_Named_VOG_DEBUG_STOP_00617ad0 retired (RTTI sealed).
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

extern "C" void* __thiscall CVOGHBSkillBase_ctor(
    void* self, void* pSourceObj, void* pSkillBlob, std::uint32_t arg4,
    void* pTarget, std::uint32_t* pTfid, std::uint32_t arg7);
extern "C" void* PTR_FUN_009d0f1c;
extern "C" float g_flZero;

// Prefer CVOGHBSkill_OnHit_ctor for named use.
extern "C" void* __thiscall FUN_00617ad0(
    void* thisHb,
    void* pSourceObj,
    void* pSkillBlob,
    std::uint32_t arg4,
    void* pTarget,
    std::uint32_t* pTfid,
    std::uint32_t arg7)
{
  auto* self = static_cast<std::uint32_t*>(thisHb);

  CVOGHBSkillBase_ctor(thisHb, pSourceObj, pSkillBlob, arg4, pTarget, pTfid,
                       arg7);
  *self = reinterpret_cast<std::uint32_t>(&PTR_FUN_009d0f1c);

  float f = *reinterpret_cast<float*>(static_cast<char*>(pSkillBlob) + 0x4c);
  if (f != g_flZero) {
    *reinterpret_cast<std::uint8_t*>(static_cast<char*>(thisHb) + 0x6c4) = 1;
    *reinterpret_cast<int*>(static_cast<char*>(thisHb) + 0x6c0) =
        static_cast<int>(f);
    return thisHb;
  }
  *reinterpret_cast<std::uint8_t*>(static_cast<char*>(thisHb) + 0x6c4) = 0;
  return thisHb;
}
