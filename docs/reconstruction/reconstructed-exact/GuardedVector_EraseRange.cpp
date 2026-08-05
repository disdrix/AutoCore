// =============================================================================
// GuardedVector_EraseRange
// -----------------------------------------------------------------------------
// Stable ID: aa_0043c8c0
// Address:   0x0043c8c0–0x0043c9af  (autoassault.exe, image base 0x400000)
// System:    STL / guarded ring-vector container
// Generated: dual A/B seal 2026-07-29 (W27-C); Ghidra FUN_0043c8c0
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - Erase [erase_from, erase_to) in a ring/vector header (retail EAX=container).
 * - Stdcall 5 stack args + EAX container; RET 0x14.
 * - Shorter-side erase: prefix < suffix → reverse move + begin advance;
 *   else forward move + size-only shrink.
 * - Returns iterator pair {container, begin+prefix} through out_pair.
 * - Name is structural Inferred from GuardedVector_* parent dual family.
 */

#include <cstdint>

struct GuardedVectorHeader {
  uint32_t _unk00;
  void*    slots;      // +0x04
  int32_t  capacity;   // +0x08  (wrap threshold capacity*4)
  int32_t  begin;      // +0x0c
  int32_t  size;       // +0x10
};

struct GuardedVectorIteratorPair {
  GuardedVectorHeader* container;
  int32_t              index;
};

extern "C" int* FUN_0043d300(void* iterator_seed);
extern "C" void FUN_0043d390(void* iterator_seed, uint32_t seed4, int erase_to);

// Clean signature: container is explicit (retail keeps it in EAX).
GuardedVectorIteratorPair* GuardedVector_EraseRange(
    GuardedVectorIteratorPair* out_pair,
    uint32_t param_2,
    int32_t erase_from,
    uint32_t param_4,
    int32_t erase_to,
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
          container->begin += 1;
          if (static_cast<uint32_t>(container->capacity * 4) <=
              static_cast<uint32_t>(container->begin)) {
            container->begin = 0;
          }
          size_work -= 1;
          if (size_work == 0) {
            container->begin = 0;
          }
        }
        erase_cnt -= 1;
      } while (erase_cnt != 0);
      container->size = size_work;
    }
  } else {
    FUN_0043d390(reinterpret_cast<void*>(&param_2), param_4, erase_to);
    if (erase_cnt != 0) {
      int size_work = container->size;
      do {
        if (size_work != 0) {
          size_work -= 1;
          if (size_work == 0) {
            container->begin = 0;
          }
        }
        erase_cnt -= 1;
      } while (erase_cnt != 0);
      container->size = size_work;
    }
  }

  out_pair->container = container;
  out_pair->index = container->begin + static_cast<int32_t>(prefix);
  return out_pair;
}
