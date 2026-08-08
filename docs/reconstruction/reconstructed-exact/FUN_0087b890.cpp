// =============================================================================
// FUN_0087b890  (twin of CVOGDialog_Ctor)
// -----------------------------------------------------------------------------
// Stable ID: aa_0087b890
// Address:   0x0087b890 – 0x0087b905 inclusive (118 B / 0x76)
// Module:    autoassault.exe (image base 0x400000)
// System:    missions-progression (partition); shared CVOGDialog base
// Wave:      R11-030 OWN-ONLY dual 2026-08-05
// Product:   CVOGDialog_Ctor  (RTTI .?AVCVOGDialog@@)
// Exactness: Behavior-preserving rewrite of decompiler CF + read_memory ABI seal.
// Bit-for-bit vs retail EXE: DEFERRED.
// Terminal:  false
// =============================================================================

#include <cstdint>

extern "C" std::uint32_t* FUN_00792d20(std::uint32_t* self);
extern "C" void* PTR_FUN_00a58c6c;
extern "C" void* ExceptionList;
extern "C" void* LAB_009b531d;

// Stack this + param_2; RET 8; EAX = this.
extern "C" std::uint32_t* __stdcall FUN_0087b890(
    std::uint32_t* param_1,
    std::uint32_t param_2)
{
  void* local_c;
  void* puStack_8;
  std::uint32_t local_4;

  local_4 = 0xffffffffu;
  puStack_8 = &LAB_009b531d;
  local_c = ExceptionList;
  ExceptionList = &local_c;

  FUN_00792d20(param_1);

  param_1[0x141] = 0;
  param_1[0x142] = 0;
  param_1[0x13f] = 0;
  param_1[0x140] = 0;
  *reinterpret_cast<std::uint8_t*>(reinterpret_cast<std::uint8_t*>(param_1) + 0xBF) = 0;
  *reinterpret_cast<std::uint8_t*>(param_1 + 0x124) = 0;

  *param_1 = reinterpret_cast<std::uint32_t>(static_cast<void*>(&PTR_FUN_00a58c6c));
  param_1[0xa9] = param_2;

  ExceptionList = local_c;
  return param_1;
}
