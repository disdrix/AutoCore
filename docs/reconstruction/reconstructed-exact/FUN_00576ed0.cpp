// =============================================================================
// FUN_00576ed0 — scaffold twin of CVOGPhaseDistort_ctor
// -----------------------------------------------------------------------------
// Stable ID: aa_00576ed0
// Address:   0x00576ed0
// Canonical: see CVOGPhaseDistort_ctor.cpp
// Generated: 2026-07-29 W32-T dual seal
// =============================================================================

#include <cstdint>

extern void* ExceptionList;
extern void* PTR_FUN_009d3bc0;

std::uint32_t* __thiscall FUN_00576ed0(std::uint32_t* param_1, std::uint32_t param_2)
{
  void* local_c;
  std::uint8_t* puStack_8;
  std::uint32_t local_4;

  local_4 = 0xffffffff;
  puStack_8 = reinterpret_cast<std::uint8_t*>(0x009a514a);
  local_c = ExceptionList;
  ExceptionList = &local_c;

  param_1[1] = param_2;
  *param_1 = reinterpret_cast<std::uint32_t>(&PTR_FUN_009d3bc0);
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;

  ExceptionList = local_c;
  return param_1;
}
