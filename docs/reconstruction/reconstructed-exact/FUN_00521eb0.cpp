// =============================================================================
// FUN_00521eb0  (clean twin of Item_GetTinkerSkillOrCap_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00521eb0
// Address:   0x00521eb0–0x00521ef6 inclusive (71 B / 0x47)
// Module:    autoassault.exe (image base 0x400000)
// System:    inventory-transfer / tinker kit skill-tier map
// Generated: 2026-08-05 MEGA-106 dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical named twin: Item_GetTinkerSkillOrCap_Inferred.cpp
// =============================================================================

#include <cstdint>

// ECX = item; EAX = tier 0..5; RET
extern "C" std::uint8_t __thiscall FUN_00521eb0(void *param_1)
{
  const std::uint8_t bVar1 =
      *reinterpret_cast<const std::uint8_t *>(
          reinterpret_cast<const std::uint8_t *>(param_1) + 0x59b);

  if (bVar1 != 0) {
    switch (bVar1) {
    case 1:
    case 2:
      return 1;
    case 3:
    case 4:
      return 2;
    case 5:
    case 6:
      return 3;
    case 7:
    case 8:
      return 4;
    case 9:
      return 5;
    default:
      // decompiler: return -(9 < bVar1) & 5;
      return static_cast<std::uint8_t>((-(static_cast<int>(9 < bVar1))) & 5);
    }
  }
  return 0;
}
