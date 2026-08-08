// =============================================================================
// FUN_00416350  (twin of Class_00a7000c_ScalarDeletingDtor_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00416350
// Address:   0x00416350  (autoassault.exe, image base 0x400000)
// Wave:      WQ9I-H OWN-ONLY dual 2026-08-05
// =============================================================================

#include <cstdint>

extern "C" void __fastcall FUN_00832fa0(void* self);
extern "C" void __cdecl operator_delete(void* p);

extern "C" void* __thiscall FUN_00416350(void* self, uint8_t flags)
{
  FUN_00832fa0(self);
  if ((flags & 1u) != 0u) {
    operator_delete(self);
  }
  return self;
}
