// =============================================================================
// FUN_005226e0  (clean twin of Character_SumCommodityTierMaxCapacities_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_005226e0
// Address:   0x005226e0  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-08-05 R13-034 dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow + bytes ABI.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
// Prefer named twin: Character_SumCommodityTierMaxCapacities_Inferred.cpp

#include <cstdint>

struct Character;

extern int __thiscall Character_CalcCommodityTierMaxCapacity_Inferred(
    Character* self,
    uint32_t tier);

// Ghidra symbol retained for path parity with scaffold twin.
int __thiscall FUN_005226e0(Character* self)
{
  int sum = 0;
  int tier = 0;

  do {
    tier = tier + 1;
    sum += Character_CalcCommodityTierMaxCapacity_Inferred(
        self, static_cast<uint32_t>(tier));
  } while (tier < 5);

  return sum;
}
