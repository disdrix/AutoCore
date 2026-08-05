// =============================================================================
// FUN_0051d0c0  →  ObjectCsList_ScalarDeletingDtor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0051d0c0
// Address:   0x0051d0c0  (autoassault.exe, image base 0x400000)
// Wave:      W37-O OWN-ONLY dual 2026-08-04
// Exactness: Behavior-preserving rewrite from decompile + full-body read_memory.
// Bit-for-bit vs retail EXE: DEFERRED.
// Accuracy:  NOT skill — object-core CS-list scalar deleting dtor (derived vtbl).
// =============================================================================

#include <cstdint>

extern "C" void* __thiscall ObjectCsList_ScalarDeletingDtor_Inferred(
    void* self, uint8_t flags);

extern "C" void* __thiscall FUN_0051d0c0(void* self, uint8_t flags)
{
  return ObjectCsList_ScalarDeletingDtor_Inferred(self, flags);
}
