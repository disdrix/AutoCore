// =============================================================================
// FUN_004cbdc0  (clean twin → SkillCNDHash_Recreate_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004cbdc0
// Address:   0x004cbdc0–0x004cbe14  (autoassault.exe @ 0x400000; 85 B)
// System:    skills-abilities
// Dual A/B:  2026-08-04 WQ9D-A
// Named clean: SkillCNDHash_Recreate_Inferred.cpp
// Exactness: Behavior-preserving Ghidra-symbol twin of named clean.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================

#include <cstdint>

extern void FUN_004cba60(void);
extern void FUN_004cb410(void);
extern void FUN_007a4480(int level, const char *msg);

void __thiscall FUN_004cbdc0(int param_1, uint8_t param_2)
{
  if (*reinterpret_cast<char *>(param_1 + 0x1d) != '\0') {
    FUN_007a4480(0, "HashError:Recreate, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }
  FUN_004cba60();
  *reinterpret_cast<uint8_t *>(param_1 + 0x1c) = param_2;
  *reinterpret_cast<uint32_t *>(param_1 + 0x18) = 0;
  *reinterpret_cast<int *>(param_1 + 8) = 1 << (param_2 & 0x1f);
  *reinterpret_cast<uint32_t *>(param_1 + 0x14) = 0;
  FUN_004cb410();
  return;
}
