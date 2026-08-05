// =============================================================================
// GuardedVector_ResizeZeroFill_Thiscall
// -----------------------------------------------------------------------------
// Stable ID: aa_0043d650
// Address:   0x0043d650–0x0043d66b  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0043d650
// System:    STL / guarded ring-deque container
// Dual:      W34-M 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: ECX = container; stack new_size; RET 0x4.
// Seeds fill=0 on stack and calls GuardedVector_Resize_Thiscall (W33-L).
// Callers often pass new_size=0 (clear); any new_size is legal.
// Name is structural (GuardedVector_* family); product/PDB open.
// Reject scaffold Named_CalleeOf_Named_VOG_DEBUG_STOP_0043d650.
// =============================================================================

#include <cstdint>

struct GuardedVectorHeader {
  uint32_t _unk00;
  uint32_t** pages;   // +0x04
  uint32_t capacity;  // +0x08
  int32_t  begin;     // +0x0c
  int32_t  size;      // +0x10
};

// Sealed W33-L: ECX=container; stack (new_size, fill); RET 0x8
extern "C" void GuardedVector_Resize_Thiscall(GuardedVectorHeader* container /*ECX*/,
                                              uint32_t new_size,
                                              uint32_t fill);

// Clean: container explicit (retail keeps it in ECX).
extern "C" void GuardedVector_ResizeZeroFill_Thiscall(
    GuardedVectorHeader* container /*ECX*/,
    uint32_t new_size)
{
  const uint32_t fill = 0;
  GuardedVector_Resize_Thiscall(container, new_size, fill);
}

extern "C" void FUN_0043d650(GuardedVectorHeader* container /*ECX*/,
                             uint32_t new_size)
{
  GuardedVector_ResizeZeroFill_Thiscall(container, new_size);
}
