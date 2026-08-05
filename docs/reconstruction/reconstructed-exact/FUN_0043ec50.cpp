// =============================================================================
// FUN_0043ec50 / GuardedVector_RingAssignForward
// -----------------------------------------------------------------------------
// Stable ID: aa_0043ec50
// Address:   0x0043ec50–0x0043ecdc  (autoassault.exe, image base 0x400000)
// System:    STL / guarded ring-vector container
// Generated: dual A/B seal 2026-07-29 (W33-J); prior scaffold 2026-07-23
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// Prefer named twin: GuardedVector_RingAssignForward.cpp
// Ghidra name retained for inventory linkage.

#include <cstdint>

void FUN_0043ec50(int* param_1, int param_2, uint32_t param_3, int param_4,
                  uint32_t param_5, int param_6, uint32_t param_7)
{
  uint32_t* puVar1;
  uint32_t* puVar2;
  int iVar3;
  int iVar4;
  uint32_t uVar5;
  uint32_t uVar6;

  for (; (param_2 != param_4 || (param_3 != param_5)); param_3 = param_3 + 1) {
    uVar6 = param_3 >> 2;
    iVar3 = static_cast<int>(uVar6) * -4;
    if (*reinterpret_cast<uint32_t*>(param_2 + 8) <= uVar6) {
      uVar6 = uVar6 - *reinterpret_cast<uint32_t*>(param_2 + 8);
    }
    uVar5 = param_7 >> 2;
    iVar4 = static_cast<int>(uVar5) * -4;
    if (*reinterpret_cast<uint32_t*>(param_6 + 8) <= uVar5) {
      uVar5 = uVar5 - *reinterpret_cast<uint32_t*>(param_6 + 8);
    }
    puVar1 = reinterpret_cast<uint32_t*>(
        *reinterpret_cast<int*>(*reinterpret_cast<int*>(param_2 + 4) + uVar6 * 4) +
        (static_cast<int>(param_3) + iVar3) * 4);
    puVar2 = reinterpret_cast<uint32_t*>(
        *reinterpret_cast<int*>(*reinterpret_cast<int*>(param_6 + 4) + uVar5 * 4) +
        (static_cast<int>(param_7) + iVar4) * 4);
    if (puVar2 != puVar1) {
      *puVar2 = *puVar1;
    }
    param_7 = param_7 + 1;
  }
  *param_1 = param_6;
  param_1[1] = static_cast<int>(param_7);
}
