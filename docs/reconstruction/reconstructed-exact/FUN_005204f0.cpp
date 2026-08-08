// =============================================================================
// FUN_005204f0  (clean twin → Character_SumCommodityTierMaxCapacities_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_005204f0
// Address:   0x005204f0  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-08-05 R13-033 dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// Named clean twin: Character_SumCommodityTierMaxCapacities_Inferred.cpp
// This file keeps the Ghidra symbol as the primary identifier for twin lookup.

#include <cstdint>

struct Character;

int __thiscall FUN_00520340(Character* self, uint32_t tier);

// Ghidra: FUN_005204f0
// Decompiler surface omits this; bytes: MOV EBX,ECX / MOV ECX,EBX around CALL.
int __thiscall FUN_005204f0(Character* self)
{
  int sum = 0;
  int tier = 0;

  do {
    sum += FUN_00520340(self, static_cast<uint32_t>(tier));
    tier = tier + 1;
  } while (tier < 6);

  return sum;
}
