// =============================================================================
// FUN_00416e80  (scaffold twin of FreelistSlabVector_Teardown_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00416e80
// Address:   0x00416e80  (autoassault.exe, image base 0x400000)
// Body:      0x00416e80–0x00416ef6 (119 B / 0x77); stdcall ret 4
// System:    container / CNDHash freelist slab pointer vector
// Generated: 2026-08-05 WQ9I-A — points at named clean
// Exactness: Behavior-preserving. Not modernization. Bit-for-bit DEFERRED.
// Dual A/B: accept-with-gaps (2026-08-05).
// Canonical clean: FreelistSlabVector_Teardown_Inferred.cpp
// =============================================================================

#include <cstdint>

extern "C" void _aligned_free(void* p);
extern "C" void operator_delete(void* p);

// stdcall ret 4 — stack freelist subobject*
extern "C" void FUN_00416e80(void* freelistSubobject)
{
  unsigned char* base = static_cast<unsigned char*>(freelistSubobject);
  void** it = *reinterpret_cast<void***>(base + 0x08);
  void** end = *reinterpret_cast<void***>(base + 0x0c);

  while (it != end) {
    _aligned_free(*it);
    ++it;
  }

  void* begin = *reinterpret_cast<void**>(base + 0x08);
  if (begin != nullptr) {
    operator_delete(begin); // RETURNS
  }

  *reinterpret_cast<void**>(base + 0x08) = nullptr;
  *reinterpret_cast<void**>(base + 0x0c) = nullptr;
  *reinterpret_cast<void**>(base + 0x10) = nullptr;
}
