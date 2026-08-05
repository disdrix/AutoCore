// =============================================================================
// CVOGPhaseDistort_ctor  (was FUN_00576ed0)
// -----------------------------------------------------------------------------
// Stable ID: aa_00576ed0
// Address:   0x00576ed0  (autoassault.exe, image base 0x400000)
// Body:      0x00576ed0–0x00576f11 exclusive (65 bytes / 0x41)
// System:    client / VOGEnvironmentSector phases
// Generated: 2026-07-29 W32-T dual seal
// Exactness: Behavior-preserving rewrite of decompiler + read_memory CF.
// Bit-for-bit vs retail EXE: DEFERRED
//
// RTTI Confirmed: COL@0x00aaed0c → type_info@0x00af31a0 ".?AVCVOGPhaseDistort@@"
// Vtable: PTR_FUN_009d3bc0
// Dual: reviews/A|B_aa_00576ed0_CVOGPhaseDistort_ctor.md
// =============================================================================

#include <cstdint>

extern void* ExceptionList;
extern void* PTR_FUN_009d3bc0;

// Process-singleton Distort phase ctor. Sole factory:
//   PalantirEnv_InitPhases → new(0x18) + CVOGPhaseDistort_ctor(view@env+0xC0)
//   → DAT_00b04818; owner DAT_00b0481c = env.
std::uint32_t* __thiscall CVOGPhaseDistort_ctor(std::uint32_t* self, std::uint32_t view)
{
  void* local_c;
  std::uint8_t* puStack_8;
  std::uint32_t local_4;

  local_4 = 0xffffffff;
  puStack_8 = reinterpret_cast<std::uint8_t*>(0x009a514a); /* LAB_009a514a */
  local_c = ExceptionList;
  ExceptionList = &local_c;

  self[1] = view;                                      // +0x04
  *self = reinterpret_cast<std::uint32_t>(&PTR_FUN_009d3bc0);
  self[3] = 0;                                         // +0x0C
  self[4] = 0;                                         // +0x10
  self[5] = 0;                                         // +0x14

  ExceptionList = local_c;
  return self; /* ret 4 */
}

// Scaffold alias
std::uint32_t* __thiscall FUN_00576ed0(std::uint32_t* param_1, std::uint32_t param_2)
{
  return CVOGPhaseDistort_ctor(param_1, param_2);
}
