// =============================================================================
// FUN_0043df70  (twin of GuardedVector_PopBack)
// -----------------------------------------------------------------------------
// Stable ID: aa_0043df70
// Address:   0x0043df70–0x0043df86  (autoassault.exe, image base 0x400000)
// Dual:      W30-C 2026-07-29
// =============================================================================

#include <cstdint>

struct GuardedVectorHeader {
  uint32_t _unk00;
  uint32_t** pages;
  int32_t  capacity;
  int32_t  begin;
  int32_t  size;
};

void FUN_0043df70(GuardedVectorHeader* container /*ECX*/)
{
  int32_t size = container->size;
  if (size == 0) {
    return;
  }
  size -= 1;
  container->size = size;
  if (size == 0) {
    container->begin = 0;
  }
}
