// =============================================================================
// Character_SumCommodityTierMaxCapacities_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005204f0
// Address:   0x005204f0  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Ghidra:    FUN_005204f0
// Generated: 2026-08-05 R13-033 dual seal (live decompile + disassemble + read_memory)
// Exactness: Behavior-preserving; not modernization.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE: Sum of level-scaled max commodity capacities (Complexity budgets)
// across parent tier domain 0..5. Parent returns 0 for tier ∉ {1..5}, so tier 0
// is a dead zero contribution; effective total = Σ max over tiers 1..5.
//
// ABI: __thiscall (ECX = Character*); no stack args; ret 0 (C3).
//
// REJECT: scaffold bare FUN_* as final English; claim pure cdecl / no this;
//         claim ret 4 (parent ABI only); claim mutates inventory;
//         merge with sibling FUN_005226e0 (loop 1..5 only);
//         merge with free-score 00522780 / row-cost 00522710 / five-row 005244e0;
//         claim Runtime Confirmed.
//
// Parent: Character_CalcCommodityTierMaxCapacity_Inferred @ 0x00520340 (R12-018)
// Sibling (not this VA): FUN_005226e0 — same effective Σ, loop 1..5 only.
// Callers: none recovered (static orphan).

#include <cstdint>

struct Character;

// Declared by dualed parent aa_00520340 (R12-018).
int __thiscall Character_CalcCommodityTierMaxCapacity_Inferred(
    Character* self,
    uint32_t tier);

int __thiscall Character_SumCommodityTierMaxCapacities_Inferred(Character* self)
{
  int sum = 0;
  int tier = 0;

  // Bytes: XOR EDI,EDI; XOR ESI,ESI; loop CMP ESI,6 / JL
  do {
    // PUSH ESI; MOV ECX,EBX(this); CALL FUN_00520340 (ret 4 cleans tier)
    sum += Character_CalcCommodityTierMaxCapacity_Inferred(
        self, static_cast<uint32_t>(tier));
    tier = tier + 1;
  } while (tier < 6);

  return sum; // MOV EAX,EDI; RET
}
