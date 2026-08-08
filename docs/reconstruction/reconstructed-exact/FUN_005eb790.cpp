// =============================================================================
// FUN_005eb790  (clean twin of VOGPhysics_QueryCollect_Ctor_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_005eb790
// Address:   0x005eb790  (autoassault.exe, image base 0x400000)
// Range:     0x005eb790–0x005eb7c0 inclusive (49 B / 0x31); pad CC after
// System:    interaction-activation
// Generated: 2026-08-05 R12-037 dual seal
// Exactness: Behavior-preserving rewrite of decompiler/assembly control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime Confirmed: OPEN (no Launcher this wave).
// Named twin: VOGPhysics_QueryCollect_Ctor_Inferred.cpp
// =============================================================================

#include <cstdint>

extern uint32_t * __thiscall FUN_005eb210(uint32_t *self /* ECX */, uint32_t params);
extern uint32_t PTR_FUN_009dce20;

uint32_t * __thiscall FUN_005eb790(
    uint32_t *param_1 /* ECX = self */,
    uint32_t param_2 /* stack = params */)
{
  FUN_005eb210(param_1, param_2);

  *param_1 = (uint32_t)(uintptr_t)&PTR_FUN_009dce20;

  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0x80000000u;

  return param_1;
}
