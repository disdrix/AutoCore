// =============================================================================
// FUN_005a2470  (scaffold twin → named clean)
// -----------------------------------------------------------------------------
// Stable ID: aa_005a2470
// Address:   0x005a2470  (autoassault.exe, image base 0x400000)
// Named:     TNL_NetClassRepInstance_Dtor
// See:       TNL_NetClassRepInstance_Dtor.cpp
// Dual A/B:  accept (W26-R 2026-07-29)
// =============================================================================

#include <cstdint>
#include <cstdlib>

extern void* PTR_FUN_009d7bf4;
extern void* PTR_LAB_009d7af4;

void __fastcall FUN_005a2470(void** param_1)
{
  void* name = param_1[8]; // +0x20
  *param_1 = &PTR_FUN_009d7bf4;
  free(name);
  *param_1 = &PTR_LAB_009d7af4;
}
