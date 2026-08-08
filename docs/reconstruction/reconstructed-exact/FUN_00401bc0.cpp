// =============================================================================
// FUN_00401bc0  — Ghidra twin of Std_OutOfRange_CtorFromString
// -----------------------------------------------------------------------------
// Stable ID: aa_00401bc0
// Address:   0x00401bc0  (autoassault.exe, image base 0x400000)
// System:    MSVC STL / std::out_of_range
// Generated: 2026-08-05 WQ9L-B dual seal (supersedes 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// Named reconstruction: Std_OutOfRange_CtorFromString.cpp
// Purpose: std::out_of_range ctor from string; SEH + logic_error base + vtbl 009c7640.

#include <cstdint>

extern "C" void *ExceptionList;
extern "C" void FUN_00401aa0(/* const std::string* */ std::uint32_t msg);
extern "C" void *PTR_FUN_009c7640;
extern "C" void LAB_009bc828;

// __thiscall; RET 4; returns this
extern "C" std::uint32_t *__thiscall FUN_00401bc0(
    std::uint32_t *param_1,
    std::uint32_t param_2)
{
  void *local_c;
  std::uint8_t *puStack_8;
  std::uint32_t local_4;

  local_4 = 0xffffffff;
  puStack_8 = reinterpret_cast<std::uint8_t *>(&LAB_009bc828);
  local_c = ExceptionList;
  ExceptionList = &local_c;

  FUN_00401aa0(param_2);
  *param_1 = reinterpret_cast<std::uint32_t>(&PTR_FUN_009c7640);

  ExceptionList = local_c;
  return param_1;
}
