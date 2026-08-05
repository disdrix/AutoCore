// =============================================================================
// GuardedVector_EraseRange_Thiscall
// -----------------------------------------------------------------------------
// Stable ID: aa_0043df90
// Address:   0x0043df90–0x0043e07d  (autoassault.exe, image base 0x400000)
// Body:      238 B / 0xEE
// System:    STL / guarded ring-deque container
// Generated: dual A/B seal 2026-07-29 (W34-L); Ghidra FUN_0043df90
// Exactness: Behavior-preserving rewrite of decompiler + read_memory control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================

/*
 * Behavioral notes:
 * - Thiscall erase of absolute ring range [erase_from, erase_to).
 * - ECX=container; 5 stack formals; RET 0x14.
 * - Shorter-prefix: reverse ring assign (0043ebb0) + begin advance/wrap + size--.
 * - Else: forward ring assign (0043ec50) + size-only shrink (begin=0 if empty).
 * - Out iterator {container, begin+prefix}.
 * - Twin of W27-C GuardedVector_EraseRange (EAX container + same RET 0x14).
 * - Name is structural Inferred from GuardedVector_* family.
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

// W33-K sealed: reverse ring assign + self-alias skip
extern "C" void GuardedVector_RingAssignBackwardChecked(
    void* out_seed,
    GuardedVectorHeader* stop_c, int32_t stop_i,
    uint32_t src_c, int32_t src_i,
    uint32_t dst_c, int32_t dst_i);

// W33-J sealed: forward ring dword assign
extern "C" void GuardedVector_RingAssignForward(
    void* out_seed,
    uint32_t src_c, int32_t src_i,
    GuardedVectorHeader* end_c, int32_t end_i,
    uint32_t dst_c, int32_t dst_i,
    GuardedVectorIteratorPair* residual);

// Clean signature: container is explicit (retail keeps it in ECX).
GuardedVectorIteratorPair* GuardedVector_EraseRange_Thiscall(
    GuardedVectorIteratorPair* out_pair,
    uint32_t erase_from_c,
    int32_t erase_from,
    uint32_t erase_to_c,
    int32_t erase_to,
    GuardedVectorHeader* container /* retail ECX */)
{
  const int32_t begin = container->begin;
  const uint32_t prefix =
      static_cast<uint32_t>(erase_from - begin);
  int erase_cnt = erase_to - erase_from;
  const int32_t end_idx = container->size + begin;
  const uint32_t suffix_len =
      static_cast<uint32_t>(end_idx - erase_to);

  if (prefix < suffix_len) {
    GuardedVector_RingAssignBackwardChecked(
        reinterpret_cast<void*>(&erase_from_c),
        container, begin,
        erase_from_c, erase_from,
        erase_to_c, erase_to);
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
    GuardedVector_RingAssignForward(
        reinterpret_cast<void*>(&erase_from_c),
        erase_to_c, erase_to,
        container, end_idx,
        erase_from_c, erase_from,
        out_pair);
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
