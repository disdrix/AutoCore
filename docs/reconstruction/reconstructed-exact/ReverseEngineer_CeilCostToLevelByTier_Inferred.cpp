// =============================================================================
// ReverseEngineer_CeilCostToLevelByTier_Inferred  (FUN_005206d0)
// -----------------------------------------------------------------------------
// Stable ID: aa_005206d0
// Address:   0x005206d0–0x00520829 inclusive (346 B / 0x15A)
//            jump table data @ 0x0052082c (6 dwords); align 8B FF @ 0x0052082a
// Module:    autoassault.exe (image base 0x400000)
// System:    inventory-transfer / reverse-engineer cost→level by tier
// Generated: 2026-08-05 R12-019 dual seal
//            (decompile_function + analyze_function_complete + callers/xrefs
//             + read_memory; no disassemble_bytes)
// Exactness: Behavior-preserving rewrite from decompile + body bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// Terminal:  false (no runtime Confirmed)
// =============================================================================
//
// PURPOSE: Map (tier_or_row_count, material_cost) → integer RE skill level
// candidate via ceil(cost * inv_mult[tier]). Sole parent
// Character_ComputeReverseEngineerRequiredLevel_Inferred (0x0052e1d0) takes
// max(base, this(row_count,total), this(tier,row_cost[tier]) for t=1..5).
//
// Formula: level = ceil(cost * inv_mult[tier]); tier>5 → 0
// Inv mults: {1/3.5, 1/3.5, 1/2.8, 1/2.1, 1/1.4, 1/0.7} for tiers 0..5
//            = inverses of capacity mults on FUN_00520520
//
// Retires scaffold: Named_CalleeOf_Named_CalleeOf_Skill_You_do_not_possess_the_Tink_005206d0
//
// ABI: __stdcall two stack args; RET 8; EAX = int level. No this/ECX.
// Callee: CRT ceil only (worker, not pure leaf).

#include <cmath>
#include <cstdint>

// DAT seals (read_memory LE float):
//   0x009cdff4 → 0.2857143f = 1/3.5   (cases 0,1)
//   0x009cefcc → 0.3571429f = 1/2.8   (case 2)
//   0x009cefc8 → 0.4761905f = 1/2.1   (case 3)
//   0x00aaa7c4 → 0.7142857f = 1/1.4   (case 4)
//   0x009cefc4 → 1.4285715f = 1/0.7   (case 5)

// __stdcall: arg0 = tier/row-count; arg1 = cost; RET 8; EAX = level
extern "C" int __stdcall ReverseEngineer_CeilCostToLevelByTier_Inferred(
    std::uint32_t tier,
    int cost)
{
  switch (tier) {
  case 0:
  case 1:
    // ceil + FISTP(round) for non-negative results matches retail ROUND path
    return static_cast<int>(std::ceil(static_cast<double>(static_cast<float>(cost) * 0.2857143f)));
  case 2:
    return static_cast<int>(std::ceil(static_cast<double>(static_cast<float>(cost) * 0.3571429f)));
  case 3:
    return static_cast<int>(std::ceil(static_cast<double>(static_cast<float>(cost) * 0.4761905f)));
  case 4:
    return static_cast<int>(std::ceil(static_cast<double>(static_cast<float>(cost) * 0.7142857f)));
  case 5:
    return static_cast<int>(std::ceil(static_cast<double>(static_cast<float>(cost) * 1.4285715f)));
  default:
    return 0;
  }
}
