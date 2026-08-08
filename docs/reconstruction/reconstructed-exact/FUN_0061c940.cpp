// =============================================================================
// FUN_0061c940  (scaffold twin of CVOGHBSkill_XP_OnHeartBeat_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0061c940
// Address:   0x0061c940–0x0061caf0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-08-05 R12-004 dual (scaffold kept in sync with named clean)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// Prefer named unit:
//   docs/reconstruction/reconstructed-exact/CVOGHBSkill_XP_OnHeartBeat_Inferred.cpp

#include <cstdint>

// See CVOGHBSkill_XP_OnHeartBeat_Inferred.cpp for full clean named body.
// Scaffold entry retains Ghidra symbol for inventory/search stability.

extern std::uint32_t *CVOGHBSkill_XP_OnHeartBeat_Inferred(void *thisHb,
                                                          std::uint32_t *pOutStatus);

std::uint32_t *__thiscall FUN_0061c940(void *param_1, std::uint32_t *param_2) {
  return CVOGHBSkill_XP_OnHeartBeat_Inferred(param_1, param_2);
}
