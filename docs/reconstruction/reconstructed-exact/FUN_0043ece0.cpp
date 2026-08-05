// =============================================================================
// FUN_0043ece0 — alias of Pod8_CopyIfNonNull
// -----------------------------------------------------------------------------
// Stable ID: aa_0043ece0
// Address:   0x0043ece0–0x0043ecee  (autoassault.exe, image base 0x400000)
// Dual:      W32-M 2026-07-29
// Prefer named clean: Pod8_CopyIfNonNull.cpp
// =============================================================================

#include <cstdint>

struct PodU32x2 {
  uint32_t a;
  uint32_t b;
};

// Retail: EAX=dest (nullable); ECX=src; bare RET.
void FUN_0043ece0(PodU32x2* dest /*EAX*/, const PodU32x2* src /*ECX*/)
{
  if (dest != nullptr) {
    dest->a = src->a;
    dest->b = src->b;
  }
}
