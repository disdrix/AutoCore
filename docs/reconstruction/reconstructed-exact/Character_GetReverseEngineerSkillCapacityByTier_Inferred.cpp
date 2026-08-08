// =============================================================================
// Character_GetReverseEngineerSkillCapacityByTier_Inferred  (FUN_00520520)
// -----------------------------------------------------------------------------
// Stable ID: aa_00520520
// Address:   0x00520520–0x005206aa inclusive (395 B / 0x18b)
//            jump table data @ 0x005206ac (6 dwords); pad NOP @ 0x005206ab
// Module:    autoassault.exe (image base 0x400000)
// System:    inventory-transfer / reverse-engineer skill capacity by tier
// Generated: 2026-08-05 R10-033 dual seal
//            (decompile_function + analyze_function_complete + disassemble_function
//             + read_memory + callers/xrefs + parent call-site bytes)
// Exactness: Behavior-preserving rewrite from decompile + body bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// Terminal:  false (no runtime Confirmed)
// =============================================================================
//
// PURPOSE: Map character RE skill byte at +0x598 × tier multiplier → integer
// capacity used by Character_ComputeReverseEngineerSuccessFraction_Inferred
// (0x0052e640) as:
//   - per recipe-row secondary cost budget (caller passes row_index+1)
//   - per-tier score capacity[t] (caller passes tier 0..5)
//
// Formula: capacity = floor(skill_byte * mult[tier]); tier>5 → 0
// Mults:   {3.5, 3.5, 2.8, 2.1, 1.4, 0.7} for tiers 0..5
//
// Retires scaffold: Named_CalleeOf_Named_CalleeOf_Skill_You_do_not_possess_the_Tink_00520520
//
// ABI: __thiscall ECX=character; stack tier; RET 4; EAX=capacity int.
// Callee: CRT floor only (worker, not pure leaf).

#include <cmath>
#include <cstdint>

// character+0x598 : uint8 RE skill rank/level (product English open → _Inferred)

// DAT seals (read_memory LE float):
//   0x009da8a4 → 3.5f
//   0x00aaaa3c → 2.8f
//   0x009cefc0 → 2.1f
//   0x009cefbc → 1.4f
//   0x00a0f710 → 0.7f

// __thiscall: ECX = character; stack arg0 = tier; RET 4; EAX = capacity
extern "C" int __thiscall Character_GetReverseEngineerSkillCapacityByTier_Inferred(
    void *character,
    std::uint32_t tier)
{
  const auto *base = reinterpret_cast<const std::uint8_t *>(character);
  const float skill = static_cast<float>(base[0x598]);

  switch (tier) {
  case 0:
  case 1:
    // floor + FISTP(chop) ≡ (int)floor for non-negative results
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
