// =============================================================================
// GuardedVector_ContainsFirstEqual
// -----------------------------------------------------------------------------
// Stable ID: aa_0043e5b0
// Address:   0x0043e5b0–0x0043e62a  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0043e5b0
// System:    STL / guarded ring-deque container
// Dual:      W30-B 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: EAX = container; stdcall 1 stack formal (const int* key);
//             RET 0x4; AL = found (0/1).
// Optional CS at +0x14 when flag +0x2c set.
// Linear first-equal scan over ring page map; no mutate.
// Name is structural (GuardedVector_* family); pairs with EraseFirstEqual (W28-C).
// =============================================================================

#include <cstdint>
#include <windows.h>

struct GuardedVectorHeader {
  uint32_t _unk00;
  uint32_t** pages;      // +0x04  array of page pointers (each page 4 dwords)
  int32_t  capacity;     // +0x08  page count
  int32_t  begin;        // +0x0c  absolute element index of front
  int32_t  size;         // +0x10  element count
  CRITICAL_SECTION cs;   // +0x14
  // ... pad ...
  // uint8_t cs_flag;    // +0x2c
};

// Clean signature: container explicit (retail keeps it in EAX).
uint8_t GuardedVector_ContainsFirstEqual(GuardedVectorHeader* container /*EAX*/,
                                         const int* key /*stack*/)
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
    // sub = idx % 4 via (idx + page*(-4))
    const uint32_t sub = idx + page * static_cast<uint32_t>(-4);
    if (static_cast<uint32_t>(container->capacity) <= page) {
      page -= static_cast<uint32_t>(container->capacity);
    }
    const int slot =
        static_cast<int>(container->pages[page][sub]);
    if (slot == *key) {
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
