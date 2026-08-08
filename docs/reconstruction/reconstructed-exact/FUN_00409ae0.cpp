// =============================================================================
// FUN_00409ae0  (alias of StdVector_UninitCopyTrampoline_Elem0x28_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00409ae0
// Address:   0x00409ae0–0x00409afa inclusive (27 B / 0x1b)
// Wave:      2026-08-05 WQ9K-A OWN dual A/B seal
// Exactness: Behavior-preserving; ABI from machine bytes (RET 8).
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================

#include <cstdint>

extern "C" void *StdVector_UninitializedCopy_Elem0x28_Inferred(
    /*ECX*/ const void *src_end,
    /*stack*/ const void *src_begin,
    /*stack*/ void *dest);

extern "C" void *__fastcall FUN_00409ae0(
    void * /*ECX*/ host_unused,
    void * /*EDX*/ dest,
    const void *src_begin,
    const void *src_end)
{
  (void)host_unused;
  return StdVector_UninitializedCopy_Elem0x28_Inferred(src_end, src_begin, dest);
}

// Named clean: StdVector_UninitCopyTrampoline_Elem0x28_Inferred.cpp
