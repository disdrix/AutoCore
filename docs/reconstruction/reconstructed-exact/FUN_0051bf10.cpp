// =============================================================================
// FUN_0051bf10  (scaffold twin → ObjectCsListBase_ScalarDeletingDtor_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0051bf10
// Address:   0x0051bf10  (autoassault.exe, image base 0x400000)
// Wave:      W31-R OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Ignore Ghidra false-noreturn on operator_delete.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>
#include <windows.h>

extern uint32_t PTR_FUN_009ce07c;
extern "C" void __fastcall FUN_0051bc90(void* list);
extern "C" void __cdecl operator_delete(void* p);

// PURPOSE: Base CS-list scalar deleting dtor (vtbl 009ce07c slot0).
// See ObjectCsListBase_ScalarDeletingDtor_Inferred.cpp for named clean.
extern "C" uint32_t* __thiscall FUN_0051bf10(uint32_t* self, uint8_t flags)
{
  *self = reinterpret_cast<uint32_t>(&PTR_FUN_009ce07c);
  FUN_0051bc90(self);
  DeleteCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(self + 1));
  if ((flags & 1) != 0) {
    operator_delete(self);
  }
  return self;
}
