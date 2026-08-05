// =============================================================================
// WeaponHitResultVec_PushBack
// -----------------------------------------------------------------------------
// Purpose:  Append one 0x20-byte POD element to an MSVC-style vector shell used
//           by weapon multi-target damage staging (hit-result records).
//
// Address:  0x0056ff00  (autoassault.exe, image base 0x400000)
// Body:     0x0056ff00–0x0056ff60 (97 bytes; exclusive end 0x0056ff61)
// Stable:   aa_0056ff00
// System:   combat / weapon multi-hit staging
// Ghidra:   FUN_0056ff00
//
// ABI:      __thiscall  void WeaponHitResultVec_PushBack(VecShell *vec, const void *value)
//           ECX=vec, [esp+4]=value*; RET 4
//
// Vector:   +0x04 begin, +0x08 end, +0x0c capacity_end; element stride 0x20
// Fast:     FUN_0056f1e0(end, 1, value) then end += 0x20
// Slow:     FUN_0056fab0(vec, end, 1, value) grow/insert
// Caller:   Weapon_ApplyDamageToTargets_Inferred @ 0x0056e000 (2 sites)
//
// Exactness: CF mirrors raw + read_memory bytes; names cleaned.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept-with-gaps (2026-07-29 W24-R seal).
// =============================================================================

#include <cstdint>

struct VecShell_Begin4 {
  std::uint32_t unused0;  // +0x00 unused by this unit
  std::uint8_t *begin;    // +0x04
  std::uint8_t *end;      // +0x08
  std::uint8_t *cap_end;  // +0x0c
};

// Callees (scaffolds / residual duals):
//   void FUN_0056f1e0(void *dest, int count, const void *src); // 8-dword POD × count
//   void __thiscall FUN_0056fab0(VecShell_Begin4 *vec, void *at, unsigned count, const void *src);

extern "C" void FUN_0056f1e0(void *dest, int count, const void *src);
extern "C" void __thiscall FUN_0056fab0(VecShell_Begin4 *vec, void *at, unsigned count, const void *src);

void __thiscall WeaponHitResultVec_PushBack(VecShell_Begin4 *vec, const void *value)
{
  std::uint8_t *begin = vec->begin;
  if (begin != nullptr) {
    auto size = static_cast<std::uint32_t>((vec->end - begin) >> 5);
    auto cap  = static_cast<std::uint32_t>((vec->cap_end - begin) >> 5);
    if (size < cap) {
      std::uint8_t *end = vec->end;
      FUN_0056f1e0(end, 1, value);
      vec->end = end + 0x20;
      return;
    }
  }
  FUN_0056fab0(vec, vec->end, 1, value);
}
