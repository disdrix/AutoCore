// =============================================================================
// FUN_0051dd60  (clean twin → SkillCNDHash_Ctor_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0051dd60
// Address:   0x0051dd60–0x0051ddd2  (autoassault.exe @ 0x400000; 115 B)
// System:    skills-abilities
// Dual A/B:  2026-08-04 WQ9D-A
// Named clean: SkillCNDHash_Ctor_Inferred.cpp
// Exactness: Behavior-preserving Ghidra-symbol twin of named clean.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================

#include <cstdint>

extern void FUN_004cb410(void);

uint32_t *__thiscall FUN_0051dd60(uint32_t *param_1, uint8_t param_2)
{
  // SEH LAB_009a371b omitted in twin CF
  *param_1 = 0x009ce1b8u; // PTR_FUN_009ce1b8
  param_1[1] = 0;
  param_1[3] = 0;
  param_1[2] = 1u << (param_2 & 0x1f);
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  *reinterpret_cast<uint8_t *>(param_1 + 7) = param_2;
  *reinterpret_cast<uint8_t *>(reinterpret_cast<char *>(param_1) + 0x1d) = 0;
  param_1[8] = 0;
  // +0x24 not written
  param_1[10] = 0;
  param_1[11] = 0;
  param_1[12] = 0;
  FUN_004cb410();
  return param_1;
}
