// =============================================================================
// FUN_0043e910 / GuardedVector_RingFillFromPtr (twin of named clean)
// -----------------------------------------------------------------------------
// Stable ID: aa_0043e910
// Address:   0x0043e910–0x0043e963  (autoassault.exe, image base 0x400000)
// Dual:      W33-K 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

// See GuardedVector_RingFillFromPtr.cpp for named header + notes.

struct GuardedVectorHeader {
  uint32_t _unk00;
  void**   slots;
  uint32_t capacity;
};

void FUN_0043e910(
    GuardedVectorHeader* param_1,
    uint32_t param_2,
    GuardedVectorHeader* param_3,
    uint32_t param_4,
    const uint32_t* param_5)
{
  for (; (param_1 != param_3) || (param_2 != param_4); ++param_2) {
    uint32_t uVar3 = param_2 >> 2;
    const int iVar2 = static_cast<int>(uVar3) * -4;
    if (param_1->capacity <= uVar3) {
      uVar3 -= param_1->capacity;
    }
    int* slots = reinterpret_cast<int*>(param_1->slots);
    uint32_t* puVar1 = reinterpret_cast<uint32_t*>(
        slots[uVar3] + (static_cast<int>(param_2) + iVar2) * 4);
    if (puVar1 != param_5) {
      *puVar1 = *param_5;
    }
  }
}
