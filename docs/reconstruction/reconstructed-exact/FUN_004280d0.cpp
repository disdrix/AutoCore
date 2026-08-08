// =============================================================================
// FUN_004280d0  (scaffold twin of CNDUIDialog_ScalarDeletingDtor)
// -----------------------------------------------------------------------------
// Stable ID: aa_004280d0
// Address:   0x004280d0  (autoassault.exe, image base 0x400000)
// Preferred: CNDUIDialog_ScalarDeletingDtor
// Generated: 2026-08-05 MEGA-140 (keeps Ghidra name as twin path)
// =============================================================================

#include <cstdint>

extern "C" void __thiscall FUN_00792c20(void* self);
extern "C" void operator_delete(void* p);

extern "C" void* __thiscall FUN_004280d0(void* param_1, uint8_t param_2)
{
  FUN_00792c20(param_1);
  if ((param_2 & 1u) != 0u) {
    operator_delete(param_1);
  }
  return param_1;
}
