// =============================================================================
// FUN_0054cc10  — twin of SkillStaging_ZeroPayloadFields_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0054cc10
// Address:   0x0054cc10–0x0054d43f  (autoassault.exe, image base 0x400000)
// Body:      2096 B / 0x830; terminal bare RET (C3)
// System:    skills-abilities
// Generated: 2026-08-05 R13-038 dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical: SkillStaging_ZeroPayloadFields_Inferred
// =============================================================================

#include <stdint.h>

void __fastcall FUN_0054cc10(void *param_1)
{
  uint32_t *p;
  int i;

  /* Zero this+0x28 .. this+0x534 inclusive (0x144 dwords). */
  p = (uint32_t *)((char *)param_1 + 0x28);
  for (i = 0; i < 0x144; i++) {
    p[i] = 0;
  }
}
