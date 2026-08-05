// =============================================================================
// FUN_00745d70  (scaffold alias → NDResource_Ctor)
// -----------------------------------------------------------------------------
// Stable ID: aa_00745d70
// Address:   0x00745d70–0x00745dec  (autoassault.exe, image base 0x400000)
// System:    ndresource / ND resource object base
// Generated: 2026-07-23 scaffold; **sealed 2026-07-29** dual A/B W19-R
// Canonical: docs/reconstruction/reconstructed-exact/NDResource_Ctor.cpp
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// Dual:      accept-with-gaps (A+B 2026-07-29)
// =============================================================================

#include <cstdint>
#include <windows.h>

extern "C" void *PTR_FUN_00aa1d40;
extern "C" void *ExceptionList;
extern "C" void *LAB_009ab7f8;

// Decompiler-shaped signature (param_1 phantom / unused).
extern "C" std::uint32_t * __fastcall FUN_00745d70(
    std::uint32_t /*param_1*/,
    std::uint32_t param_2,
    std::uint32_t *param_3,
    std::uint32_t *param_4,
    int *param_5)
{
  std::uint32_t uVar1;
  void *local_c;
  std::uint8_t *puStack_8;
  std::uint32_t local_4;

  local_4 = 0xffffffffu;
  puStack_8 = reinterpret_cast<std::uint8_t *>(&LAB_009ab7f8);
  local_c = ExceptionList;
  ExceptionList = &local_c;

  *param_3 = reinterpret_cast<std::uint32_t>(&PTR_FUN_00aa1d40);
  param_3[1] = *param_4;
  param_3[2] = 0;
  param_3[3] = param_2;
  param_3[4] = 0;
  param_3[5] = 0;
  param_3[6] = 0xffffffffu;
  InitializeCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(param_3 + 8));
  *reinterpret_cast<std::uint8_t *>(param_3 + 0xe) = 1;
  local_4 = 0;

  if (param_5 != nullptr) {
    auto **vtbl = *reinterpret_cast<void ***>(param_5);
    using VFn = std::uint32_t(__thiscall *)(void *);
    uVar1 = reinterpret_cast<VFn>(vtbl[1])(param_5);
    param_3[5] = uVar1;
  }

  ExceptionList = local_c;
  return param_3;
}
