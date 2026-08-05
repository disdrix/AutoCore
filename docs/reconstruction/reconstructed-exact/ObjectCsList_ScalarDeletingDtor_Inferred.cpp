// =============================================================================
// ObjectCsList_ScalarDeletingDtor_Inferred  (aa_0051d0c0)
// -----------------------------------------------------------------------------
// Address:   0x0051d0c0  (autoassault.exe, image base 0x400000)
// Wave:      W37-O OWN-ONLY dual 2026-08-04
// Exactness: Behavior-preserving rewrite from decompile + full-body read_memory.
//            Ignore Ghidra false-noreturn on operator_delete (bytes fall through).
// Bit-for-bit vs retail EXE: DEFERRED.
// Accuracy:  NOT skill — object-core derived CS-list scalar deleting dtor.
//            Pair of ObjectCsList_CompleteDtor_Inferred (0x0051d0e0, W31-R).
// =============================================================================

#include <cstdint>

// Complete dtor: derived vtbl → clear → base vtbl → clear → DeleteCS(+4). No free.
extern "C" void __thiscall FUN_0051d0e0(void* self);
extern "C" void __cdecl operator_delete(void* p);

// Scalar deleting dtor for derived vtbl PTR_FUN_009ce154 (slot0).
// Complete dtor then optional heap free on flags bit0. Returns this. RET 4.
extern "C" void* __thiscall ObjectCsList_ScalarDeletingDtor_Inferred(
    void* self, uint8_t flags)
{
  FUN_0051d0e0(self);
  if ((flags & 1) != 0) {
    operator_delete(self);
  }
  return self;
}

// Scaffold twin symbol
extern "C" void* __thiscall FUN_0051d0c0(void* self, uint8_t flags)
{
  return ObjectCsList_ScalarDeletingDtor_Inferred(self, flags);
}
