// =============================================================================
// Character_CalcCommodityTierMaxCapacity_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00520340
// Address:   0x00520340  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Ghidra:    FUN_00520340
// Generated: 2026-08-05 R12-018 dual seal (live decompile + disassemble + read_memory)
// Exactness: Behavior-preserving; not modernization.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE: Level-scaled max commodity capacity (Complexity budget) for one tier.
//   level = *(uint8_t*)(this + 0x599)
//   tier 1..5 → (int)floor(level * scale[tier]); else 0
//   scale = {3.5, 2.8, 2.1, 1.4, 0.7} = 0.7 * (6 - tier)
//
// ABI: __thiscall (ECX = Character*); one stack dword (tier); ret 4.
//
// REJECT: scaffold Named_CalleeOf_* plates; claim pure cdecl / no this;
//         claim ROUND (banker's) instead of floor+chop; claim mutates inventory;
//         claim tier 0 is valid non-zero; merge with free-score 00522780 or
//         row-cost 00522710.
//
// Used as max by dualed Character_CalcCommodityTierFreeScore_Inferred @ 0x00522780
// and as Complexity denominator by UI FUN_008e41b0.

#include <cmath>
#include <cstdint>

struct Character;

// Scale floats sealed at:
//   0x009da8a4=3.5f, 0x00aaaa3c=2.8f, 0x009cefc0=2.1f,
//   0x009cefbc=1.4f, 0x00a0f710=0.7f
static constexpr float kTierScale[6] = {
    0.0f,  // unused (tier 0 invalid)
    3.5f,  // tier 1
    2.8f,  // tier 2
    2.1f,  // tier 3
    1.4f,  // tier 4
    0.7f,  // tier 5
};

int __thiscall Character_CalcCommodityTierMaxCapacity_Inferred(
    Character* self,
    uint32_t tier /* 1..5; else 0 */)
{
  if (tier < 1u || tier > 5u) {
    return 0;
  }

  const auto* base = reinterpret_cast<const uint8_t*>(self);
  const uint32_t level = base[0x599]; // MOVZX from [ECX+0x599]

  // CRT floor + FISTP chop (OR AH,0xC) — decompiler ROUND is chop convert
  const double prod = static_cast<double>(static_cast<float>(level) * kTierScale[tier]);
  return static_cast<int>(std::floor(prod));
}
