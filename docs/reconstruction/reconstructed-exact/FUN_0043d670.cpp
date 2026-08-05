// =============================================================================
// FUN_0043d670  (clean twin of GuardedVector_PushBack_Thiscall)
// -----------------------------------------------------------------------------
// Stable ID: aa_0043d670
// Address:   0x0043d670–0x0043d6e6  (autoassault.exe, image base 0x400000)
// Dual:      W31-I 2026-07-29
// Prefer:    GuardedVector_PushBack_Thiscall.cpp (named clean)
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

void __thiscall FUN_0043d670(GuardedVectorHeader* container /*ECX*/,
                             const uint32_t* value /*stack*/)
{
  const uint32_t end_probe =
      static_cast<uint32_t>(container->begin) +
      static_cast<uint32_t>(container->size);
  if ((end_probe & 3u) == 0 &&
      static_cast<uint32_t>(container->capacity) <=
          (static_cast<uint32_t>(container->size) + 4u) >> 2) {
    GuardedVector_GrowBlockMap_Thiscall(container, 1);
  }

  uint32_t abs =
      static_cast<uint32_t>(container->begin) +
      static_cast<uint32_t>(container->size);
  uint32_t page = abs >> 2;
  if (static_cast<uint32_t>(container->capacity) <= page) {
    page -= static_cast<uint32_t>(container->capacity);
  }

  if (container->pages[page] == nullptr) {
    container->pages[page] =
        static_cast<uint32_t*>(::operator new(0x10));
  }

  FUN_0043d420(container->pages[page] + (abs & 3u), value);
  container->size += 1;
}
