// =============================================================================
// FUN_00409b40  (scaffold twin → StdVector_UninitCopyTrampoline_Elem12_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00409b40
// Address:   0x00409b40–0x00409b5a inclusive (27 B / 0x1b)
// Wave:      2026-08-05 R10-008 OWN dual A/B seal
// Prefer:    StdVector_UninitCopyTrampoline_Elem12_Inferred.cpp
// =============================================================================

#include <cstdint>

extern "C" void *StdVector_UninitializedCopy_Elem12_Inferred(
    /*ECX*/ const void *src_end,
    /*stack*/ const void *src_begin,
    /*stack*/ void *dest);

// ECX=host_unused; EDX=dest; stack begin,end; EAX=dest_end; RET 8
extern "C" void *__fastcall FUN_00409b40(
    void * /*ECX*/ host_unused,
    void * /*EDX*/ dest,
    const void *src_begin,
    const void *src_end)
{
  (void)host_unused;
  return StdVector_UninitializedCopy_Elem12_Inferred(
      /*ECX*/ src_end,
      /*stack*/ src_begin,
      /*stack*/ dest);
}
