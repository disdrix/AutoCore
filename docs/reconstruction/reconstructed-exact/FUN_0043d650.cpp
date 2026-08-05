// =============================================================================
// FUN_0043d650  (twin of GuardedVector_ResizeZeroFill_Thiscall)
// -----------------------------------------------------------------------------
// Stable ID: aa_0043d650
// Address:   0x0043d650–0x0043d66b  (autoassault.exe, image base 0x400000)
// Dual:      W34-M 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

struct GuardedVectorHeader {
  uint32_t _unk00;
  uint32_t** pages;
  uint32_t capacity;
  int32_t  begin;
  int32_t  size;
};

extern "C" void GuardedVector_Resize_Thiscall(GuardedVectorHeader* container /*ECX*/,
                                              uint32_t new_size,
                                              uint32_t fill);

// Retail: ECX=container; stack new_size; RET 4. Zero-fill wrapper over Resize_Thiscall.
extern "C" void FUN_0043d650(GuardedVectorHeader* container /*ECX*/,
                             uint32_t new_size)
{
  uint32_t fill = 0;
  GuardedVector_Resize_Thiscall(container, new_size, fill);
}
