// =============================================================================
// FUN_0051db60  (twin of CNDHash_Ctor_009ce1a0)
// -----------------------------------------------------------------------------
// Stable ID: aa_0051db60
// Address:   0x0051db60–0x0051dbd2  (autoassault.exe @ 0x400000)
// Dual A/B:  2026-07-29 W26-P
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// =============================================================================

#include <cstdint>

extern void *PTR_FUN_009ce1a0;
extern void __thiscall FUN_0051ba40(void *thisHash);

// returns this; __thiscall; ret 4
std::uint32_t *__thiscall FUN_0051db60(std::uint32_t *param_1, std::uint8_t param_2)
{
  // SEH frame omitted; success-path field init preserved
  *param_1 = reinterpret_cast<std::uint32_t>(&PTR_FUN_009ce1a0);
  param_1[1] = 0;
  param_1[3] = 0;
  param_1[2] = 1u << (param_2 & 0x1f);
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  *reinterpret_cast<std::uint8_t *>(param_1 + 7) = param_2;
  *reinterpret_cast<std::uint8_t *>(reinterpret_cast<std::uint8_t *>(param_1) + 0x1d) = 0;
  param_1[8] = 0;
  // +0x24 not written (matches bytes)
  param_1[10] = 0;
  param_1[11] = 0;
  param_1[12] = 0;
  FUN_0051ba40(param_1);
  return param_1;
}
