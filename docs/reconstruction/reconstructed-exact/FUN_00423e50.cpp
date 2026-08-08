// =============================================================================
// FUN_00423e50  (scaffold twin → see CNDUIWindow_ScalarDeletingDtor.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_00423e50
// Address:   0x00423e50–0x00423e6d inclusive (30 B / 0x1E)
// System:    skills-abilities residual / UI CNDUIWindow scalar-deleting dtor
// Generated: 2026-08-05 MEGA-139 (retires 2026-07-23 scaffold body)
// Canonical: CNDUIWindow_ScalarDeletingDtor
// Exactness: Behavior-preserving; Ghidra name retained for path stability.
// =============================================================================

#include <cstdint>

extern "C" void __fastcall FUN_007b5be0(void* self);
extern "C" void operator_delete(void* p);

// void* __thiscall FUN_00423e50(void* this, uint8_t flags)
extern "C" void* __thiscall FUN_00423e50(void* param_1, uint8_t param_2)
{
  FUN_007b5be0(param_1);

  if ((param_2 & 1u) != 0u) {
    operator_delete(param_1);
  }

  return param_1;
}
