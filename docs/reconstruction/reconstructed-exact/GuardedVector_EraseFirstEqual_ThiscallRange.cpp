// =============================================================================
// GuardedVector_EraseFirstEqual_ThiscallRange
// -----------------------------------------------------------------------------
// Stable ID: aa_0043e630
// Address:   0x0043e630–0x0043e6c1  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0043e630
// System:    STL / guarded ring-deque container
// Dual:      W35-A 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: ESI = container; stdcall 1 stack formal (const int* key);
//             RET 0x4; AL = found (0/1).
// Optional CS at +0x14 when flag +0x2c set.
// Linear first-equal scan; on hit erase [idx, idx+1) via
// GuardedVector_EraseRange_Thiscall (0x0043df90, ECX=container).
// Twin of W28-C GuardedVector_EraseFirstEqual (0x0043c550) which uses EAX
// EraseRange (0x0043c8c0). Same outer ESI/RET4 surface; different nested ABI.
// Name is structural (GuardedVector_* family).
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
  // ... pad through +0x2b ...
  // uint8_t cs_flag;    // +0x2c
};

struct GuardedVectorIteratorPair {
  GuardedVectorHeader* container;
  uint32_t             index;
};

// External (sealed W34-L): ECX=container; stack (out, from_c, from_i, to_c, to_i); RET 0x14
extern "C" void GuardedVector_EraseRange_Thiscall(
    GuardedVectorHeader* container /*ECX*/,
    GuardedVectorIteratorPair* out,
    GuardedVectorHeader* erase_from_c,
    int32_t erase_from_i,
    GuardedVectorHeader* erase_to_c,
    int32_t erase_to_i);

// Clean signature: container explicit (retail keeps it in ESI).
uint8_t GuardedVector_EraseFirstEqual_ThiscallRange(
    const int* key /*stack*/,
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
      GuardedVector_EraseRange_Thiscall(
          container, &out,
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
