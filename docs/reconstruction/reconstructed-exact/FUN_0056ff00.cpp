// =============================================================================
// FUN_0056ff00 — Ghidra-name twin of WeaponHitResultVec_PushBack
// Address: 0x0056ff00  Stable: aa_0056ff00  Dual: W24-R 2026-07-29
// See WeaponHitResultVec_PushBack.cpp for sealed CF + ABI.
// =============================================================================

#include <cstdint>

// Layout on ECX base: +4 begin, +8 end, +0xc cap_end (+0 unused).

extern "C" void FUN_0056f1e0(void *dest, int count, const void *src);
extern "C" void __thiscall FUN_0056fab0(void *vec, void *at, unsigned count, const void *src);

void __thiscall FUN_0056ff00(int param_1, const void *param_2)
{
  int begin = *reinterpret_cast<int *>(param_1 + 4);
  if (begin != 0 &&
      (static_cast<unsigned>(*reinterpret_cast<int *>(param_1 + 8) - begin) >> 5) <
      (static_cast<unsigned>(*reinterpret_cast<int *>(param_1 + 0xc) - begin) >> 5)) {
    int end = *reinterpret_cast<int *>(param_1 + 8);
    FUN_0056f1e0(reinterpret_cast<void *>(end), 1, param_2);
    *reinterpret_cast<int *>(param_1 + 8) = end + 0x20;
    return;
  }
  FUN_0056fab0(reinterpret_cast<void *>(param_1),
               *reinterpret_cast<void **>(param_1 + 8), 1, param_2);
}
