// =============================================================================
// FUN_004975e0  (Ghidra twin of Class_009c7a1c_ScalarDeletingDtor)
// -----------------------------------------------------------------------------
// Stable ID: aa_004975e0
// Address:   0x004975e0–0x004975fe  (30 B / 0x1E)
// W29-F:     2026-07-29 dual A/B sealed — see Class_009c7a1c_ScalarDeletingDtor.cpp
// =============================================================================

#include <cstdint>

extern "C" void __thiscall FUN_004970b0(void* self);
extern "C" void operator_delete(void* p);
extern "C" void* __thiscall Class_009c7a1c_ScalarDeletingDtor(void* self, uint8_t flags);

extern "C" void* __thiscall FUN_004975e0(void* param_1, uint8_t param_2)
{
  return Class_009c7a1c_ScalarDeletingDtor(param_1, param_2);
}

// Scaffold CF (authoritative for order; Ghidra may warn false-noreturn on delete):
//   FUN_004970b0();
//   if ((param_2 & 1) != 0) operator_delete(param_1);
//   return param_1;
