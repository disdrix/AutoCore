// =============================================================================
// FUN_00620480  (scaffold alias → Skill_SpawnTemplateAndStartHB)
// -----------------------------------------------------------------------------
// Stable ID: aa_00620480
// Address:   0x00620480  (autoassault.exe, image base 0x400000)
// System:    skills / HB action spawn
// Generated: 2026-07-23 scaffold; dual-sealed 2026-07-29 W19-E
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Prefer:    reconstructed-exact/Skill_SpawnTemplateAndStartHB.cpp
// String:    "Skill %d had invalid template %d."
// ABI:       6 stack args, ret 0x18; returns 0 (invalid template) | 1
// DATA:      0x009d1598 → this
// =============================================================================

// Full sealed body lives in Skill_SpawnTemplateAndStartHB.cpp.
// This scaffold keeps the FUN_* symbol for coverage tooling.

#include <cstdint>

extern std::uint32_t Skill_SpawnTemplateAndStartHB(
    int* param_1, int param_2, void* param_3,
    std::uint32_t param_4, std::uint32_t param_5, std::uint32_t param_6);

std::uint32_t FUN_00620480(
    int* param_1, int param_2, void* param_3,
    std::uint32_t param_4, std::uint32_t param_5, std::uint32_t param_6)
{
  return Skill_SpawnTemplateAndStartHB(
      param_1, param_2, param_3, param_4, param_5, param_6);
}
