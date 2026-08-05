// =============================================================================
// FUN_006380a0  (scaffold alias of Mem_CopyBytes)
// -----------------------------------------------------------------------------
// Stable ID: aa_006380a0
// Address:   0x006380a0  (autoassault.exe, image base 0x400000)
// Body:      0x006380a0–0x006380be (31 B through bare ret)
// System:    util / memory
// Generated: 2026-07-29 W21-K dual seal (refined from 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (retail rep movsd/movsb ≡ this CF).
// Canonical clean: Mem_CopyBytes.cpp
// Dual A/B: accept (2026-07-29).
// =============================================================================

#include <cstdint>

void FUN_006380a0(uint32_t* param_1, uint32_t* param_2, unsigned param_3)
{
  unsigned uVar1;

  for (uVar1 = param_3 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_1 = *param_2;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  }
  for (param_3 = param_3 & 3; param_3 != 0; param_3 = param_3 - 1) {
    *reinterpret_cast<uint8_t*>(param_1) = *reinterpret_cast<uint8_t*>(param_2);
    param_2 = reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 1);
    param_1 = reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_1) + 1);
  }
  return;
}
