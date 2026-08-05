// =============================================================================
// ObjectCsList_CompleteDtor_Inferred  (aa_0051d0e0)
// -----------------------------------------------------------------------------
// Address:   0x0051d0e0  (autoassault.exe, image base 0x400000)
// Wave:      W31-R OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite from decompile + full-body read_memory.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>
#include <windows.h>

extern uint32_t PTR_FUN_009ce154;
extern uint32_t PTR_FUN_009ce07c;

// CS-list drain under critical section (no node+4 clear). Twin of
// ObjectCsList_ClearDestroy_Inferred without the node+4=0 step / same layout.
extern "C" void __fastcall FUN_0051bc90(void* list);

// Complete dtor only for Object SharedBase CS helper list (sizeof 0x2C @ core+0xB0).
// Does NOT free `self`. Scalar wrapper is FUN_0051d0c0 (vtbl 009ce154 slot0).
extern "C" void __fastcall ObjectCsList_CompleteDtor_Inferred(uint32_t* self)
{
  *self = reinterpret_cast<uint32_t>(&PTR_FUN_009ce154);
  FUN_0051bc90(self);

  *self = reinterpret_cast<uint32_t>(&PTR_FUN_009ce07c);
  FUN_0051bc90(self);

  DeleteCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(self + 1));
}

// Scaffold twin symbol
extern "C" void __fastcall FUN_0051d0e0(uint32_t* self)
{
  ObjectCsList_CompleteDtor_Inferred(self);
}
