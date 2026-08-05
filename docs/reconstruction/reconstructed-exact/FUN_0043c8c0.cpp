// =============================================================================
// FUN_0043c8c0 / GuardedVector_EraseRange
// -----------------------------------------------------------------------------
// Stable ID: aa_0043c8c0
// Address:   0x0043c8c0–0x0043c9af  (autoassault.exe, image base 0x400000)
// System:    STL / guarded ring-vector container
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W27-C)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - Erase absolute index range [erase_from, erase_to) in ring container.
 * - Retail ABI: EAX=container; stdcall 5 stack args; RET 0x14.
 * - Shorter-side erase: prefix < suffix → FUN_0043d300 + advance begin;
 *   else FUN_0043d390 + size-only shrink.
 * - Returns out-iterator pair {container, begin+prefix} through out_pair.
 * - Header: +0x04 slots, +0x08 capacity, +0x0c begin, +0x10 size.
 * - begin wraps when begin >= capacity*4.
 * - Nested move helpers not dualed here.
 */

#include <cstdint>

struct GuardedVectorHeader {
  uint32_t _unk00;
  void*    slots;      // +0x04
  int32_t  capacity;   // +0x08
  int32_t  begin;      // +0x0c
  int32_t  size;       // +0x10
};

extern "C" int* FUN_0043d300(void* iterator_seed);
extern "C" void FUN_0043d390(void* iterator_seed, uint32_t seed4, int erase_to);

// Retail: container in EAX (decompiler in_EAX). Clean exposes it explicitly last
// so the control flow is host-callable; call sites must match retail register ABI.
extern "C" int* FUN_0043c8c0(int* out_pair,
                             uint32_t param_2,
                             int erase_from,
                             uint32_t param_4,
                             int erase_to,
                             GuardedVectorHeader* container /* retail EAX */)
{
  const uint32_t prefix =
      static_cast<uint32_t>(erase_from - container->begin);
  int erase_cnt = erase_to - erase_from;
  const uint32_t suffix_len = static_cast<uint32_t>(
      (container->size + container->begin) - erase_to);

  if (prefix < suffix_len) {
    FUN_0043d300(reinterpret_cast<void*>(&param_2));
    if (erase_cnt != 0) {
      int size_work = container->size;
      do {
        if (size_work != 0) {
          container->begin = container->begin + 1;
          if (static_cast<uint32_t>(container->capacity * 4) <=
              static_cast<uint32_t>(container->begin)) {
            container->begin = 0;
          }
          size_work = size_work - 1;
          if (size_work == 0) {
            container->begin = 0;
          }
        }
        erase_cnt = erase_cnt - 1;
      } while (erase_cnt != 0);
      container->size = size_work;
    }
  } else {
    FUN_0043d390(reinterpret_cast<void*>(&param_2), param_4, erase_to);
    if (erase_cnt != 0) {
      int size_work = container->size;
      do {
        if (size_work != 0) {
          size_work = size_work - 1;
          if (size_work == 0) {
            container->begin = 0;
          }
        }
        erase_cnt = erase_cnt - 1;
      } while (erase_cnt != 0);
      container->size = size_work;
    }
  }

  out_pair[0] = reinterpret_cast<int>(container);
  out_pair[1] = container->begin + static_cast<int>(prefix);
  return out_pair;
}
