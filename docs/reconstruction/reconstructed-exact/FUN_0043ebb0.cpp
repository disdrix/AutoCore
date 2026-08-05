// =============================================================================
// FUN_0043ebb0 / GuardedVector_RingAssignBackwardChecked (twin of named clean)
// -----------------------------------------------------------------------------
// Stable ID: aa_0043ebb0
// Address:   0x0043ebb0–0x0043ec43  (autoassault.exe, image base 0x400000)
// Dual:      W33-K 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

struct GuardedVectorHeader {
  uint32_t _unk00;
  uint32_t* slots;
  uint32_t  capacity;
};

struct GuardedVectorIteratorPair {
  GuardedVectorHeader* container;
  uint32_t             index;
};

// Decompiler shows void; bytes return out in EAX — match named clean.
GuardedVectorIteratorPair* FUN_0043ebb0(
    GuardedVectorIteratorPair* param_1,
    GuardedVectorHeader* param_2,
    uint32_t param_3,
    GuardedVectorHeader* param_4,
    uint32_t param_5,
    GuardedVectorHeader* param_6,
    uint32_t param_7)
{
  while (param_2 != param_4 || param_3 != param_5) {
    param_5 = param_5 - 1;
    uint32_t uVar6 = param_5 >> 2;
    const int iVar3 = static_cast<int>(uVar6) * -4;
    if (param_4->capacity <= uVar6) {
      uVar6 -= param_4->capacity;
    }

    param_7 = param_7 - 1;
    uint32_t uVar5 = param_7 >> 2;
    const int iVar4 = static_cast<int>(uVar5) * -4;
    if (param_6->capacity <= uVar5) {
      uVar5 -= param_6->capacity;
    }

    int* src_slots = reinterpret_cast<int*>(param_4->slots);
    int* dst_slots = reinterpret_cast<int*>(param_6->slots);
    uint32_t* puVar1 = reinterpret_cast<uint32_t*>(
        src_slots[uVar6] + (static_cast<int>(param_5) + iVar3) * 4);
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(
        dst_slots[uVar5] + (static_cast<int>(param_7) + iVar4) * 4);
    if (puVar2 != puVar1) {
      *puVar2 = *puVar1;
    }
  }

  param_1->container = param_6;
  param_1->index = param_7;
  return param_1;
}
