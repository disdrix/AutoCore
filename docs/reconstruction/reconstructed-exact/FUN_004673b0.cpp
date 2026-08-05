// =============================================================================
// FUN_004673b0  (twin of StdVector_UninitializedCopy_Elem28_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004673b0
// Address:   0x004673b0–0x00467406  (autoassault.exe, image base 0x400000)
// System:    containers / std::vector uninitialized_copy (POD stride 0x1c)
// Generated: dual A/B seal 2026-07-29 (W35-T)
// Exactness: Behavior-preserving rewrite. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// Canonical clean: StdVector_UninitializedCopy_Elem28_Inferred.cpp

#include <cstdint>

struct Pod28 {
  uint32_t d0, d1, d2, d3, d4, d5, d6;
};

// Retail: EAX=dest, ECX=first, [ESP+4]=last; bare RET.
// Ghidra name retained as twin entry; prefer named clean for ports.
void FUN_004673b0(Pod28* dest /*EAX*/, Pod28* first /*ECX*/, Pod28* last /*stack*/)
{
  if (first == last) {
    return;
  }
  do {
    if (dest != nullptr) {
      dest->d0 = first->d0;
      dest->d1 = first->d1;
      dest->d2 = first->d2;
      dest->d3 = first->d3;
      dest->d4 = first->d4;
      dest->d5 = first->d5;
      dest->d6 = first->d6;
    }
    ++first;
    ++dest;
  } while (first != last);
}
