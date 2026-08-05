// =============================================================================
// FUN_0043e3d0  (clean twin of GuardedVector_PushFront_Thiscall)
// -----------------------------------------------------------------------------
// Stable ID: aa_0043e3d0
// Address:   0x0043e3d0–0x0043e447  (autoassault.exe, image base 0x400000)
// Dual:      W31-I 2026-07-29
// Prefer:    GuardedVector_PushFront_Thiscall.cpp (named clean)
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>
#include <new>

struct GuardedVectorHeader {
  uint32_t _unk00;
  uint32_t** pages;
  int32_t  capacity;
  int32_t  begin;
  int32_t  size;
};

extern "C" void __thiscall GuardedVector_GrowBlockMap_Thiscall(
    GuardedVectorHeader* self, uint32_t min_grow);
extern "C" void FUN_0043d420(uint32_t* dest, const uint32_t* src);

void __thiscall FUN_0043e3d0(GuardedVectorHeader* container /*ECX*/,
                             const uint32_t* value /*stack*/)
{
  if ((static_cast<uint32_t>(container->begin) & 3u) == 0 &&
      static_cast<uint32_t>(container->capacity) <=
          (static_cast<uint32_t>(container->size) + 4u) >> 2) {
    GuardedVector_GrowBlockMap_Thiscall(container, 1);
  }

  int32_t begin = container->begin;
  if (begin == 0) {
    begin = container->capacity * 4;
  }
  const uint32_t new_begin = static_cast<uint32_t>(begin - 1);
  const uint32_t page = new_begin >> 2;

  if (container->pages[page] == nullptr) {
    container->pages[page] =
        static_cast<uint32_t*>(::operator new(0x10));
  }

  FUN_0043d420(container->pages[page] + (new_begin & 3u), value);
  container->size += 1;
  container->begin = static_cast<int32_t>(new_begin);
}
