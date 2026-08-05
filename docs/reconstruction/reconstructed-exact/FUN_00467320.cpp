// =============================================================================
// FUN_00467320  (twin of StdVector_UninitializedFillN_Elem28_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00467320
// Address:   0x00467320–0x0046736e  (autoassault.exe, image base 0x400000)
// System:    containers / std::vector uninitialized_fill_n (POD stride 0x1c)
// Generated: dual A/B seal 2026-07-29 (W35-T)
// Exactness: Behavior-preserving rewrite. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// Canonical clean: StdVector_UninitializedFillN_Elem28_Inferred.cpp

#include <cstdint>

struct Pod28 {
  uint32_t d0, d1, d2, d3, d4, d5, d6;
};

// Retail: ECX=dest, EDX=value*, EAX=count; bare RET.
// Ghidra name retained as twin entry; prefer named clean for ports.
void FUN_00467320(Pod28* dest /*ECX*/, const Pod28* value /*EDX*/, int count /*EAX*/)
{
  if (count == 0) {
    return;
  }
  do {
    if (dest != nullptr) {
      dest->d0 = value->d0;
      dest->d1 = value->d1;
      dest->d2 = value->d2;
      dest->d3 = value->d3;
      dest->d4 = value->d4;
      dest->d5 = value->d5;
      dest->d6 = value->d6;
    }
    ++dest;
    --count;
  } while (count != 0);
}
