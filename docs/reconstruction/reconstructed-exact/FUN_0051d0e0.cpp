// =============================================================================
// FUN_0051d0e0  (scaffold twin → ObjectCsList_CompleteDtor_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0051d0e0
// Address:   0x0051d0e0  (autoassault.exe, image base 0x400000)
// Wave:      W31-R OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>
#include <windows.h>

extern uint32_t PTR_FUN_009ce154;
extern uint32_t PTR_FUN_009ce07c;
extern "C" void __fastcall FUN_0051bc90(void* list);

// PURPOSE: Object CS-list complete dtor (derived then base vtbl + DeleteCS).
// See ObjectCsList_CompleteDtor_Inferred.cpp for named clean.
extern "C" void __fastcall FUN_0051d0e0(uint32_t* self)
{
  *self = reinterpret_cast<uint32_t>(&PTR_FUN_009ce154);
  FUN_0051bc90(self);
  *self = reinterpret_cast<uint32_t>(&PTR_FUN_009ce07c);
  FUN_0051bc90(self);
  DeleteCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(self + 1));
}
