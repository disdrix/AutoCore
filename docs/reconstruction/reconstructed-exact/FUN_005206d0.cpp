// =============================================================================
// FUN_005206d0  (machine twin of ReverseEngineer_CeilCostToLevelByTier_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_005206d0
// Address:   0x005206d0–0x00520829 inclusive (346 B / 0x15A)
// Module:    autoassault.exe (image base 0x400000)
// System:    inventory-transfer / reverse-engineer
// Generated: 2026-08-05 R12-019 dual seal (keeps FUN_* twin name)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Terminal:  false
// =============================================================================
// Prefer named plate:
//   ReverseEngineer_CeilCostToLevelByTier_Inferred.cpp

#include <cmath>
#include <cstdint>

// See named plate for DAT seals and parent chain.

extern "C" int __stdcall FUN_005206d0(std::uint32_t param_1, int param_2)
{
  switch (param_1) {
  case 0:
  case 1:
    return static_cast<int>(std::ceil(static_cast<double>(static_cast<float>(param_2) * 0.2857143f)));
  case 2:
    return static_cast<int>(std::ceil(static_cast<double>(static_cast<float>(param_2) * 0.3571429f)));
  case 3:
    return static_cast<int>(std::ceil(static_cast<double>(static_cast<float>(param_2) * 0.4761905f)));
  case 4:
    return static_cast<int>(std::ceil(static_cast<double>(static_cast<float>(param_2) * 0.7142857f)));
  case 5:
    return static_cast<int>(std::ceil(static_cast<double>(static_cast<float>(param_2) * 1.4285715f)));
  default:
    return 0;
  }
}
