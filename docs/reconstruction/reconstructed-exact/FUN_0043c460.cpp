// =============================================================================
// FUN_0043c460 — twin of CircularSentinel_Alloc0x14_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0043c460
// Address:   0x0043c460  (autoassault.exe, image base 0x400000)
// Wave:      W35-B OWN-ONLY dual (2026-07-29)
// =============================================================================

#include <cstdint>

extern "C" void* __cdecl operator_new(uint32_t size);

extern "C" void* FUN_0043c460(void)
{
  void* node = operator_new(0x14);
  if (node != nullptr) {
    *static_cast<void**>(node) = node; // next = self
  }
  if (reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(node) + 4) != nullptr) {
    *reinterpret_cast<void**>(static_cast<uint8_t*>(node) + 4) = node; // prev
  }
  return node; // EAX (decompiler void is wrong)
}
