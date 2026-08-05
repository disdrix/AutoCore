// =============================================================================
// FUN_005b35a0 — scaffold twin of CVOGEnvironmentReflect_ctor
// -----------------------------------------------------------------------------
// Stable ID: aa_005b35a0
// Address:   0x005b35a0
// Canonical: see CVOGEnvironmentReflect_ctor.cpp
// Generated: 2026-07-29 W32-T dual seal
// =============================================================================

#include <cstdint>

extern void* ExceptionList;
extern void* PTR_FUN_009d95a0;
extern float DAT_00a0f2a0;
extern float DAT_00aaa668;
extern std::uint32_t* __fastcall FUN_007560d0(std::uint32_t* self);
extern void __fastcall FUN_00972cc0(std::uint32_t* matrix_sub);
extern void __fastcall FUN_00972e50(std::uint32_t* matrix_sub);
extern void __thiscall FUN_0044b440(std::uint32_t* matrix_sub, float a, float b, float c);

std::uint32_t* __thiscall FUN_005b35a0(std::uint32_t* param_1, std::uint32_t* param_2)
{
  void* local_c;
  std::uint8_t* puStack_8;
  std::uint32_t local_4;

  local_4 = 0xffffffff;
  puStack_8 = reinterpret_cast<std::uint8_t*>(0x009a67ed);
  local_c = ExceptionList;
  ExceptionList = &local_c;

  FUN_007560d0(param_1);
  local_4 = 0;
  *param_1 = reinterpret_cast<std::uint32_t>(&PTR_FUN_009d95a0);

  std::uint32_t* matrix = param_1 + 0x24;
  FUN_00972cc0(matrix);

  param_1[0x57] = reinterpret_cast<std::uint32_t>(param_2);
  param_1[0x56] = 0;
  param_1[0x58] = param_2[0xE4E8 / 4];
  param_1[0x55] = 0;
  param_1[0x54] = 0;
  param_1[0x59] = param_2[0xE894 / 4];

  FUN_0044b440(matrix, DAT_00a0f2a0, DAT_00aaa668, DAT_00a0f2a0);

  if ((*(reinterpret_cast<std::uint8_t*>(param_1 + 0x53)) & 1) != 0) {
    FUN_00972e50(matrix);
  }

  *(reinterpret_cast<std::uint8_t*>(param_1 + 0x1e)) = 1;
  *(reinterpret_cast<std::uint8_t*>(param_1 + 0x20)) = 1;

  ExceptionList = local_c;
  return param_1;
}
