// =============================================================================
// FUN_0060c3c0  (Ghidra twin of MissionReqHost_LazyFillMatchRefFromSkill_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0060c3c0
// Address:   0x0060c3c0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities / missions-progression
// Generated: 2026-08-05 R11-010 dual seal (replaces 2026-07-23 scaffold paste)
// Exactness: Behavior-preserving; see named twin for full plate.
// Canonical: MissionReqHost_LazyFillMatchRefFromSkill_Inferred
// =============================================================================

#include <cstdint>

extern "C" void* __cdecl CVOGReaction_ResolveSkillTargets(int skillId, int rankPacked);
extern "C" void  __cdecl operator_delete(void* p);

// Prefer named twin: MissionReqHost_LazyFillMatchRefFromSkill_Inferred.cpp
void __thiscall FUN_0060c3c0(void* reqHost /* ECX */)
{
  if (*reinterpret_cast<std::int32_t*>(reinterpret_cast<char*>(reqHost) + 0x44) != -1) {
    return;
  }

  const int skillId =
      *reinterpret_cast<std::int32_t*>(reinterpret_cast<char*>(reqHost) + 0x10);
  const int rankPacked = static_cast<int>(
      *reinterpret_cast<std::uint16_t*>(reinterpret_cast<char*>(reqHost) + 0x14));

  void* skill = CVOGReaction_ResolveSkillTargets(skillId, rankPacked);
  if (skill == nullptr) {
    return;
  }

  *reinterpret_cast<std::uint32_t*>(reinterpret_cast<char*>(reqHost) + 0x44) =
      *reinterpret_cast<std::uint32_t*>(reinterpret_cast<char*>(skill) + 0x14c);
  *reinterpret_cast<std::uint8_t*>(reinterpret_cast<char*>(reqHost) + 0x48) =
      (*reinterpret_cast<std::uint8_t*>(reinterpret_cast<char*>(skill) + 0x22) != 0)
          ? static_cast<std::uint8_t>(1)
          : static_cast<std::uint8_t>(0);

  operator_delete(skill);
}
