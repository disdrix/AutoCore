// =============================================================================
// FUN_0054b480  (scaffold alias — prefer SkillDefMap_GetGlobal.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_0054b480
// Address:   0x0054b480  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-29 W18-C dual A/B (scaffold mirror of structural clean)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Lazy-get global SkillDefMap header &DAT_00b04734 (once-flag DAT_00b04724).
// Structural clean: reconstructed-exact/SkillDefMap_GetGlobal.cpp

#include <cstdint>

extern "C" uint8_t DAT_00b04724;
extern "C" uint8_t DAT_00b04734;
extern "C" void FUN_0054b2c0(void);

void* FUN_0054b480(void)
{
  if (DAT_00b04724 == 0) {
    FUN_0054b2c0();
  }
  return &DAT_00b04734;
}
