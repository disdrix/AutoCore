// =============================================================================
// GuardedVector_EraseFirstEqual
// -----------------------------------------------------------------------------
// Stable ID: aa_0043c550
// Address:   0x0043c550–0x0043c5e1  (autoassault.exe, image base 0x400000)
// System:    STL / guarded ring-vector container
// Generated: dual A/B seal 2026-07-29 (W28-C); Ghidra FUN_0043c550
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - Optional CS around linear scan for first element equal to *key, then erase one.
 * - Retail ABI: ESI=container, stack key*, RET 4, AL=bool.
 * - Callers (assManager resolver removal) set ESI to object+0x58 member before call.
 * - Erase delegates to GuardedVector_EraseRange [idx, idx+1) with EAX=container.
 * - Layout shared with GuardedVector_AssignTo / EraseRange family.
 * - Name structural Inferred; product open.
 */

#include <cstdint>
#include <windows.h>

struct GuardedVectorHeader {
  uint32_t _unk00;
  int*     slots;      // +0x04
  uint32_t capacity;   // +0x08
  uint32_t begin;      // +0x0c
  int32_t  size;       // +0x10
  CRITICAL_SECTION cs; // +0x14  (through +0x2b)
  char     lockEnable; // +0x2c
};

struct GuardedVectorIteratorPair {
  GuardedVectorHeader* container;
  uint32_t             index;
};

// External (sealed W27-C): EAX=container; stdcall 5 args; RET 0x14
extern "C" int* FUN_0043c8c0(int* out_pair, uint32_t seed2, int erase_from,
                             uint32_t seed4, int erase_to);

// Clean signature: container explicit (retail keeps it in ESI).
uint8_t GuardedVector_EraseFirstEqual(
    int* key /* retail stack */,
    GuardedVectorHeader* container /* retail ESI */)
{
  if (container->lockEnable != 0) {
    EnterCriticalSection(&container->cs);
  }

  uint8_t found = 0;
  uint32_t idx = container->begin;
  const uint32_t end = static_cast<uint32_t>(container->size) + container->begin;

  while (idx != end) {
    uint32_t block = idx >> 2;
    const int lane_base = static_cast<int>(block) * -4;
    if (container->capacity <= block) {
      block -= container->capacity;
    }
    const int elem = *reinterpret_cast<int*>(
        container->slots[block] + (static_cast<int>(idx) + lane_base) * 4);

    if (elem == *key) {
      GuardedVectorIteratorPair out{};
      // Retail also passes container seeds on stack; EAX=container.
      FUN_0043c8c0(reinterpret_cast<int*>(&out),
                   reinterpret_cast<uint32_t>(container),
                   static_cast<int>(idx),
                   reinterpret_cast<uint32_t>(container),
                   static_cast<int>(idx + 1));
      found = 1;
      break;
    }
    idx += 1;
  }

  if (container->lockEnable != 0) {
    LeaveCriticalSection(&container->cs);
  }
  return found;
}
