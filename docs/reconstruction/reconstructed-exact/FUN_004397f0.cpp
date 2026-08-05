// =============================================================================
// FUN_004397f0  (twin of CircularSentinel_Alloc0x10_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004397f0
// Address:   0x004397f0–0x00439809  (26 B / 0x1A)
// Wave:      W35-C OWN-ONLY dual 2026-07-29
// See:       CircularSentinel_Alloc0x10_Inferred.cpp for sealed semantics.
// =============================================================================

#include <cstdint>

extern "C" void* __cdecl operator_new(uint32_t size);

extern "C" void* FUN_004397f0(void)
{
  void* node = operator_new(0x10);
  if (node != nullptr) {
    *static_cast<void**>(node) = node; // next = self
  }
  if (reinterpret_cast<uint32_t*>(
          static_cast<uint8_t*>(node) + 4) != nullptr) {
    *reinterpret_cast<void**>(static_cast<uint8_t*>(node) + 4) = node; // prev
  }
  return node; // EAX — decompiler void is wrong
}
