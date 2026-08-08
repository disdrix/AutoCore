// =============================================================================
// FUN_0054fec0  (scaffold twin — prefer Skill_StoreEffectPresenceFlags_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0054fec0
// Address:   0x0054fec0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-08-04 WQ9E-B dual A/B
// =============================================================================

#include <stdint.h>

extern uint32_t __fastcall Skill_ComputeEffectPresenceFlags_Inferred(void *pSkill);

void __fastcall FUN_0054fec0(void *pSkill)
{
  uint8_t *base = (uint8_t *)pSkill;
  uint32_t uMask = Skill_ComputeEffectPresenceFlags_Inferred(pSkill);
  uint32_t f620 = *(uint32_t *)(base + 0x620);

  if (f620 == 0) {
    *(uint32_t *)(base + 0x624) = uMask;
  } else {
    *(uint32_t *)(base + 0x624) = uMask | 4u;
    if (*(base + 0x148) == 0) {
      *(uint32_t *)(base + 0x620) = f620 | 0x100000u;
    }
  }
}
