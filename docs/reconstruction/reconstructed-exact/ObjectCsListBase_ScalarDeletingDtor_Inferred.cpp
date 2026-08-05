// =============================================================================
// ObjectCsListBase_ScalarDeletingDtor_Inferred  (aa_0051bf10)
// -----------------------------------------------------------------------------
// Address:   0x0051bf10  (autoassault.exe, image base 0x400000)
// Wave:      W31-R OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite from decompile + full-body read_memory.
//            Ignore Ghidra false-noreturn on operator_delete (bytes fall through).
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>
#include <windows.h>

extern uint32_t PTR_FUN_009ce07c;

extern "C" void __fastcall FUN_0051bc90(void* list);
extern "C" void __cdecl operator_delete(void* p);

// Scalar deleting dtor for base vtbl PTR_FUN_009ce07c (slot0).
// Base-phase only: install base vtbl, drain, DeleteCS, optional free.
extern "C" uint32_t* __thiscall ObjectCsListBase_ScalarDeletingDtor_Inferred(
    uint32_t* self, uint8_t flags)
{
  *self = reinterpret_cast<uint32_t>(&PTR_FUN_009ce07c);
  FUN_0051bc90(self);
  DeleteCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(self + 1));
  if ((flags & 1) != 0) {
    operator_delete(self);
  }
  return self;
}

// Scaffold twin symbol
extern "C" uint32_t* __thiscall FUN_0051bf10(uint32_t* self, uint8_t flags)
{
  return ObjectCsListBase_ScalarDeletingDtor_Inferred(self, flags);
}
