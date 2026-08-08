// =============================================================================
// FUN_00520520  (twin of Character_GetReverseEngineerSkillCapacityByTier_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00520520
// Address:   0x00520520–0x005206aa inclusive (395 B / 0x18b)
// Module:    autoassault.exe (image base 0x400000)
// System:    inventory-transfer / reverse-engineer skill capacity by tier
// Generated: 2026-08-05 R10-033 dual seal (Ghidra symbol twin)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Terminal:  false
// =============================================================================
//
// Named form: Character_GetReverseEngineerSkillCapacityByTier_Inferred
// Retires:    Named_CalleeOf_Named_CalleeOf_Skill_You_do_not_possess_the_Tink_00520520

#include <cmath>
#include <cstdint>

// __thiscall: ECX = character; stack arg0 = tier; RET 4; EAX = capacity
extern "C" int __thiscall FUN_00520520(void *param_1, std::uint32_t param_2)
{
  const auto *base = reinterpret_cast<const std::uint8_t *>(param_1);
  const float skill = static_cast<float>(base[0x598]);

  switch (param_2) {
  case 0:
  case 1:
    return static_cast<int>(std::floor(static_cast<double>(skill * 3.5f)));
  case 2:
    return static_cast<int>(std::floor(static_cast<double>(skill * 2.8f)));
  case 3:
    return static_cast<int>(std::floor(static_cast<double>(skill * 2.1f)));
  case 4:
    return static_cast<int>(std::floor(static_cast<double>(skill * 1.4f)));
  case 5:
    return static_cast<int>(std::floor(static_cast<double>(skill * 0.7f)));
  default:
    return 0;
  }
}
