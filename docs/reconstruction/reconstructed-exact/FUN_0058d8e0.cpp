// =============================================================================
// FUN_0058d8e0  (scaffold twin — prefer Skill_HB_ApplyMultiArgEffect_Inferred.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_0058d8e0
// Address:   0x0058d8e0  (autoassault.exe, image base 0x400000)
// Body:      0x0058d8e0–0x0058d95d inclusive (126 B / 0x7E)
// System:    skills-abilities
// Generated: 2026-08-05 MEGA-009 dual seal (machine-name twin retained)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Named clean: Skill_HB_ApplyMultiArgEffect_Inferred.cpp
// =============================================================================

#include <cstdint>

extern int FUN_0058c850(void *, std::uint32_t *, void *, std::uint32_t, void *, int);
extern std::uint32_t DAT_009d4d28;
extern std::uint32_t DAT_009d4d2c;
extern std::uint32_t DAT_009d4d30;
extern std::uint32_t DAT_009d4d34;

// __cdecl; bare ret; EAX = damage sum
int FUN_0058d8e0(
    void *param_1,
    void *param_2,
    void *param_3,
    std::uint32_t param_4,
    void *param_5,
    int param_6)
{
  std::uint32_t local_20[8];

  if (param_2 == nullptr) {
    return 0;
  }

  const auto *src = reinterpret_cast<const std::uint32_t *>(
      reinterpret_cast<const char *>(param_2) + 0x160);
  local_20[0] = src[0];
  local_20[1] = src[1];
  local_20[2] = src[2];
  local_20[3] = src[3];
  local_20[4] = DAT_009d4d28;
  local_20[5] = DAT_009d4d2c;
  local_20[6] = DAT_009d4d30;
  local_20[7] = DAT_009d4d34;

  return FUN_0058c850(param_1, local_20, param_3, param_4, param_5, param_6);
}
