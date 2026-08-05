// =============================================================================
// GuardedVector_Dtor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005b2ba0
// Address:   0x005b2ba0–0x005b2c05  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_005b2ba0
// System:    STL / guarded ring-deque container
// Dual:      W37-D 2026-08-04
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: ECX = container; 0 stack formals; plain RET; void.
// Teardown storage: drain size (clear begin when emptied), free each page,
// free page map, zero capacity + pages. Does NOT free the header object itself
// (stack locals / embedded members). Name structural (GuardedVector_* family).
// =============================================================================

#include <cstdint>

struct GuardedVectorHeader {
  uint32_t  _unk00;     // +0x00  untouched by this body
  uint32_t** pages;     // +0x04  map of page pointers
  int32_t   capacity;   // +0x08  page count
  int32_t   begin;      // +0x0c  absolute front index
  int32_t   size;       // +0x10  element count
};

extern "C" void __cdecl operator_delete(void* p);

// Clean signature: container explicit (retail keeps it in ECX).
void GuardedVector_Dtor_Inferred(GuardedVectorHeader* container /*ECX*/)
{
  // Drain size to 0; when last element drops, force begin=0.
  while (container->size != 0) {
    container->size -= 1;
    if (container->size == 0) {
      container->begin = 0;
    }
  }

  // Free each allocated page block (capacity = page count).
  for (int32_t i = container->capacity; i > 0; ) {
    void* page = container->pages[i - 1];
    i -= 1;
    if (page != nullptr) {
      operator_delete(page);
    }
  }

  // Free page map, then always zero map + capacity (bytes; both paths).
  if (container->pages != nullptr) {
    operator_delete(container->pages);
  }
  container->capacity = 0;
  container->pages = nullptr;
}
