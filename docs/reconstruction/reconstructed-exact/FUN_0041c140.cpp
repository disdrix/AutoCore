// =============================================================================
// FUN_0041c140  (scaffold twin — prefer StdVector_CopyCtor_Elem0x18_Inferred.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_0041c140
// Address:   0x0041c140–0x0041c1c9 inclusive (138 B / 0x8A)
// System:    skills-abilities (partition)
// Generated: 2026-08-05 R13-022 OWN dual — keeps Ghidra symbol as twin
// Canonical: StdVector_CopyCtor_Elem0x18_Inferred
// Exactness: Behavior-preserving; not modernization. Bit-for-bit: DEFERRED.
// =============================================================================

#include <cstdint>

// See StdVector_CopyCtor_Elem0x18_Inferred.cpp for named plate + layout notes.

extern "C" char __thiscall FUN_0041c250(void* self, unsigned n);
extern "C" void* FUN_00422580(void* first, void* last, void* dest, void* a, void* b);

extern "C" void* __thiscall FUN_0041c140(void* dest /*ECX*/, const void* src /*stack*/)
{
  int count = 0;
  void* src_begin = *reinterpret_cast<void* const*>(
      reinterpret_cast<const char*>(src) + 4);
  void* src_end = *reinterpret_cast<void* const*>(
      reinterpret_cast<const char*>(src) + 8);

  if (src_begin != nullptr) {
    count = static_cast<int>(
        (static_cast<const char*>(src_end) - static_cast<const char*>(src_begin)) /
        0x18);
  }

  char ok = FUN_0041c250(dest, static_cast<unsigned>(count));
  if (ok != 0) {
    void* dest_begin = *reinterpret_cast<void**>(
        reinterpret_cast<char*>(dest) + 4);
    void* new_end = FUN_00422580(src_begin, src_end, dest_begin,
                                 const_cast<void*>(dest),
                                 const_cast<void*>(src));
    *reinterpret_cast<void**>(reinterpret_cast<char*>(dest) + 8) = new_end;
  }
  return dest;
}
