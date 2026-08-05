// =============================================================================
// FUN_00575c00  (named: Object_009d33c4_ScalarDeletingDtor)
// -----------------------------------------------------------------------------
// Stable ID: aa_00575c00
// Address:   0x00575c00  (autoassault.exe, image base 0x400000)
// Body:      0x00575c00–0x00575c1e exclusive (30 B / 0x1E)
// Generated: 2026-07-29 W29-H dual seal
// Exactness: Behavior-preserving rewrite. See Object_009d33c4_ScalarDeletingDtor.cpp.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// Twin of named clean. Prefer Object_009d33c4_ScalarDeletingDtor for ports.
// See docs/reconstruction/functions/aa_00575c00_Object_009d33c4_ScalarDeletingDtor.md

#include <cstdint>

extern "C" void __thiscall Object_009d33c4_CompleteDtor(void *self); // FUN_00575350
extern "C" void *__cdecl operator_delete(void *p);

void *__thiscall FUN_00575c00(void *self, uint8_t flags)
{
  Object_009d33c4_CompleteDtor(self);
  if ((flags & 1) != 0) {
    operator_delete(self);
  }
  return self;
}
