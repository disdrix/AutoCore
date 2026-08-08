// =============================================================================
// FUN_0061b960  (scaffold twin → Skill_HB_CopyTfid16At668_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0061b960
// Address:   0x0061b960  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Dual:      2026-08-05 MEGA-016 OWN-ONLY
//
// Canonical clean source:
//   docs/reconstruction/reconstructed-exact/Skill_HB_CopyTfid16At668_Inferred.cpp
//
// This file keeps the Ghidra machine name as a twin entry point for path
// stability. Prefer the named clean source for ports.
// =============================================================================

#include <cstdint>

struct TFID_16 {
  std::uint32_t dwCoidLo;
  std::uint32_t dwCoidHi;
  std::uint32_t uGlobalAndPad;
  std::uint32_t uPadTail;
};

// Ghidra: void __thiscall FUN_0061b960(int param_1, undefined4 *param_2)
// Sealed ABI: ret 4; EAX = out; ECX = this; four dwords from this+0x668.
TFID_16 *__thiscall FUN_0061b960(void *param_1, TFID_16 *param_2)
{
  const auto *src = reinterpret_cast<const std::uint32_t *>(
      reinterpret_cast<const char *>(param_1) + 0x668);
  param_2->dwCoidLo = src[0];
  param_2->dwCoidHi = src[1];
  param_2->uGlobalAndPad = src[2];
  param_2->uPadTail = src[3];
  return param_2;
}
