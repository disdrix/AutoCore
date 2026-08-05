// =============================================================================
// FUN_006061e0 — scaffold alias for CVOGHBWakeupSkill_ctor
// -----------------------------------------------------------------------------
// Stable ID: aa_006061e0
// Address:   0x006061e0 – 0x00606353  (autoassault.exe, image base 0x400000)
// Canonical: CVOGHBWakeupSkill_ctor (RTTI Confirmed)
// Clean named: reconstructed-exact/CVOGHBWakeupSkill_ctor.cpp
// Generated: 2026-07-29 W19-G OWN dual — thin alias; see named unit for full body.
// Exactness: Behavior-preserving. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

// Full reconstruction lives in CVOGHBWakeupSkill_ctor.cpp.
extern void* __thiscall CVOGHBWakeupSkill_ctor(
    void* thisHb,
    uint32_t skillTypeOrPeriodSeed,
    void* hostObject,
    uint32_t* skillBlobSrc,
    void* world,
    int* tfidList,
    void* pos,
    uint32_t seed,
    uint32_t flagWord);

extern "C" void* __thiscall FUN_006061e0(
    void* param_1,
    uint32_t param_2,
    void* param_3,
    uint32_t* param_4,
    void* param_5,
    int* param_6,
    void* param_7,
    uint32_t param_8,
    uint32_t param_9)
{
  return CVOGHBWakeupSkill_ctor(
      param_1, param_2, param_3, param_4, param_5,
      param_6, param_7, param_8, param_9);
}
