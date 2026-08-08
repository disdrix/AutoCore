// =============================================================================
// FUN_0051b720  (twin of Rng_CopyUnitTableWindow_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0051b720
// Address:   0x0051b720  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-08-04 WQ9R-A dual
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// Named clean: Rng_CopyUnitTableWindow_Inferred.cpp
// Dual: reviews/A|B_aa_0051b720_Rng_CopyUnitTableWindow_Inferred.md

#include <cstdint>

// See Rng_CopyUnitTableWindow_Inferred.cpp for full plate + layout notes.
// Ghidra void return is wrong — EAX = pre-increment cursor.

extern "C" std::uint32_t __thiscall FUN_0051b720(int param_1, int param_2, std::uint32_t* param_3)
{
  std::uint32_t uVar1;
  std::uint32_t* puVar2;

  if (0xfffff < *(int*)(param_1 + 0xc) + param_2) {
    *(std::uint32_t*)(param_1 + 0xc) = 0;
  }
  puVar2 = (std::uint32_t*)(*(int*)(param_1 + 8) + *(int*)(param_1 + 0xc) * 2);
  for (uVar1 = (std::uint32_t)(param_2 * 2) >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_3 = *puVar2;
    puVar2 = puVar2 + 1;
    param_3 = param_3 + 1;
  }
  for (uVar1 = (std::uint32_t)(param_2 * 2) & 3u; uVar1 != 0; uVar1 = uVar1 - 1) {
    *(std::uint8_t*)param_3 = *(std::uint8_t*)puVar2;
    puVar2 = (std::uint32_t*)((int)puVar2 + 1);
    param_3 = (std::uint32_t*)((int)param_3 + 1);
  }
  std::uint32_t oldCursor = *(std::uint32_t*)(param_1 + 0xc);
  *(int*)(param_1 + 0xc) = *(int*)(param_1 + 0xc) + 1;
  return oldCursor;
}
