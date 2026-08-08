// =============================================================================
// FUN_005ebec0  (clean twin of VOGPhysics_SphereQueryCollect_Ctor_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_005ebec0
// Address:   0x005ebec0  (autoassault.exe, image base 0x400000)
// Range:     0x005ebec0–0x005ebef0 inclusive (49 B / 0x31)
// System:    interaction-activation
// Generated: 2026-08-05 MEGA-070 dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Named twin: VOGPhysics_SphereQueryCollect_Ctor_Inferred.cpp
// =============================================================================

#include <cstdint>

extern uint32_t * __thiscall FUN_005eb210(uint32_t *self, uint32_t params);
extern uint32_t PTR_FUN_009dce90;

uint32_t * __thiscall FUN_005ebec0(uint32_t *param_1 /* ECX */, uint32_t param_2 /* stack */)
{
  FUN_005eb210(param_1, param_2);
  *param_1 = (uint32_t)(uintptr_t)&PTR_FUN_009dce90;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0x80000000u;
  return param_1;
}
