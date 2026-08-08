// =============================================================================
// FUN_00520340  (clean twin → Character_CalcCommodityTierMaxCapacity_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00520340
// Address:   0x00520340  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-08-05 R12-018 dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// Named clean twin: Character_CalcCommodityTierMaxCapacity_Inferred.cpp
// This file keeps the Ghidra symbol as the primary identifier for twin lookup.

#include <cmath>
#include <cstdint>

struct Character;

static constexpr float kTierScale[6] = {
    0.0f, 3.5f, 2.8f, 2.1f, 1.4f, 0.7f,
};

// Ghidra: FUN_00520340
int __thiscall FUN_00520340(Character* self, uint32_t tier)
{
  if (tier < 1u || tier > 5u) {
    return 0;
  }

  const auto* base = reinterpret_cast<const uint8_t*>(self);
  const uint32_t level = base[0x599];
  const double prod = static_cast<double>(static_cast<float>(level) * kTierScale[tier]);
  return static_cast<int>(std::floor(prod));
}
