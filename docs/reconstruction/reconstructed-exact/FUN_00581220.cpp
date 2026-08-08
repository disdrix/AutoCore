// =============================================================================
// FUN_00581220  (machine twin of TtPhantom_CtorFromAabbDesc_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00581220
// Address:   0x00581220–0x005812c6 inclusive (167 B / 0xA7)
// Canonical: TtPhantom_CtorFromAabbDesc_Inferred
// Dual:      MEGA-037 2026-08-05 — accept-with-gaps
// Exactness: Behavior-preserving; ABI corrections from assembly (thiscall RET 4;
//            EAX=this). Not modernization.
// =============================================================================

#include <cstdint>

extern "C" void* PTR_FUN_009d45b0;

// Ghidra signature corrected: not void — returns this in EAX; RET 4.
uint32_t* __thiscall FUN_00581220(uint32_t* param_1, const uint32_t* param_2)
{
  *(uint16_t*)((uint8_t*)param_1 + 6) = 1;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[4] = 0xffffffffu;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[10] = 0;
  param_1[9] = 2;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0x80000000u;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0x80000000u;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0x80000000u;
  param_1[0xb] = (uint32_t)(uintptr_t)param_1;
  *param_1 = (uint32_t)(uintptr_t)&PTR_FUN_009d45b0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0x80000000u;
  param_1[0x18] = param_2[8];
  param_1[0x19] = param_2[9];
  param_1[0x1a] = param_2[10];
  param_1[0x1b] = param_2[0xb];
  param_1[0x1c] = param_2[0xc];
  param_1[0x1d] = param_2[0xd];
  param_1[0x1e] = param_2[0xe];
  param_1[0x1f] = param_2[0xf];
  param_1[10] = *param_2;
  return param_1;
}
