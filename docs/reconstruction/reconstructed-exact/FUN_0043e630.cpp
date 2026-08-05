// =============================================================================
// FUN_0043e630  (twin of GuardedVector_EraseFirstEqual_ThiscallRange)
// -----------------------------------------------------------------------------
// Stable ID: aa_0043e630
// Address:   0x0043e630–0x0043e6c1  (autoassault.exe, image base 0x400000)
// Dual:      W35-A 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// See: GuardedVector_EraseFirstEqual_ThiscallRange.cpp for named clean.

#include <cstdint>
#include <windows.h>

struct GuardedVectorHeader {
  uint32_t _unk00;
  uint32_t** pages;
  int32_t  capacity;
  int32_t  begin;
  int32_t  size;
  CRITICAL_SECTION cs;
};

struct GuardedVectorIteratorPair {
  GuardedVectorHeader* container;
  uint32_t             index;
};

extern "C" void FUN_0043df90(
    GuardedVectorHeader* container /*ECX*/,
    GuardedVectorIteratorPair* out,
    GuardedVectorHeader* erase_from_c,
    int32_t erase_from_i,
    GuardedVectorHeader* erase_to_c,
    int32_t erase_to_i);

// Retail: ESI=container; stack key*; RET 4; AL found.
uint8_t FUN_0043e630(const int* key /*stack*/,
                     GuardedVectorHeader* container /*ESI*/)
{
  const uint8_t* flag = reinterpret_cast<const uint8_t*>(container) + 0x2c;
  if (*flag != 0) {
    EnterCriticalSection(&container->cs);
  }

  uint32_t idx = static_cast<uint32_t>(container->begin);
  uint8_t found = 0;
  const uint32_t end =
      static_cast<uint32_t>(container->size) + idx;

  while (idx != end) {
    uint32_t page = idx >> 2;
    const uint32_t sub = idx + page * static_cast<uint32_t>(-4);
    if (static_cast<uint32_t>(container->capacity) <= page) {
      page -= static_cast<uint32_t>(container->capacity);
    }
    const int slot =
        static_cast<int>(container->pages[page][sub]);
    if (slot == *key) {
      GuardedVectorIteratorPair out{};
      FUN_0043df90(container, &out,
                   container, static_cast<int32_t>(idx),
                   container, static_cast<int32_t>(idx + 1));
      found = 1;
      break;
    }
    idx += 1;
  }

  if (*flag != 0) {
    LeaveCriticalSection(&container->cs);
  }
  return found;
}
