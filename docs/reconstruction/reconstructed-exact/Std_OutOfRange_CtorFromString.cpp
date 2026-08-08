// =============================================================================
// Std_OutOfRange_CtorFromString  (FUN_00401bc0)
// -----------------------------------------------------------------------------
// Stable ID: aa_00401bc0
// Address:   0x00401bc0–0x00401c10 inclusive (81 B / 0x51)
// Module:    autoassault.exe (image base 0x400000)
// System:    MSVC STL / std::out_of_range
// Generated: 2026-08-05 WQ9L-B dual seal (body ≡ 2026-07-23 raw)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes (WQ9L-B sealed):
 * - Product: std::out_of_range::out_of_range(std::string const&)
 * - RTTI: .?AVout_of_range@std@@ @ 0x00af8b98
 * - Base: FUN_00401aa0 = logic_error(string) [vtbl PTR_FUN_009c7628, string@+0x0c]
 * - Installs out_of_range vtbl PTR_FUN_009c7640; __thiscall RET 4; returns this
 * - ThrowInfo DAT_00acc34c (catchables size 0x28) — parents throw after this ctor
 * - Shared message plate: "invalid map/set<T> iterator" @ 0x00a152f0
 * - Twin: Std_LengthError_CtorFromString (0x00401a40 / vtbl 009c7634 / ThrowInfo acc388)
 * - Rejects scaffold plate Named_CalleeOf_*RecvSkillStatusEffect* (xref-seed false)
 */

#include <cstdint>

// FUN_00401aa0: std::logic_error::logic_error(std::string const&)
// PTR_FUN_009c7640: out_of_range vftable
// LAB_009bc828: shared EH state machine with length_error sibling

extern "C" void *ExceptionList;
extern "C" void FUN_00401aa0(/* const std::string* */ std::uint32_t msg);
extern "C" void *PTR_FUN_009c7640;
extern "C" void LAB_009bc828;

// __thiscall; RET 4
extern "C" std::uint32_t *__thiscall Std_OutOfRange_CtorFromString(
    std::uint32_t *this_obj,
    /* const std::string* */ std::uint32_t msg)
{
  void *local_c;
  std::uint8_t *puStack_8;
  std::uint32_t local_4;

  local_4 = 0xffffffff;
  puStack_8 = reinterpret_cast<std::uint8_t *>(&LAB_009bc828);
  local_c = ExceptionList;
  ExceptionList = &local_c;

  FUN_00401aa0(msg); /* logic_error(msg) — this remains in ECX at call */
  *this_obj = reinterpret_cast<std::uint32_t>(&PTR_FUN_009c7640);

  ExceptionList = local_c;
  return this_obj;
}
