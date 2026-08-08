// =============================================================================
// Skill_StoreEffectPresenceFlags_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0054fec0
// Address:   0x0054fec0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-08-04 WQ9E-B dual A/B (from raw + live re-verify)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================
//
// PURPOSE
//   After ranked effect fields are already materialized on a skill runtime,
//   recompute effect-presence flags and store them to skill+0x624 (targeting /
//   capability mask). When skill+0x620 is non-zero, OR bit value 4 into the
//   stored mask; if skill+0x148 is zero, also OR 0x100000 into skill+0x620.
//
//   This is the store-only twin of the post-Evaluate tail inside
//   Skill_ReevaluateForCurrentRank (0x00553390). Reevaluate inlines the same
//   store rather than calling this helper. No static xrefs to this VA found.
//
// ABI: __fastcall / thiscall — ECX = skill runtime; void; plain ret
// Body: 0x0054fec0–0x0054fef8 (57 B inclusive of ret)
// Name: _Inferred — role High from CF + dualed presence leaf; product English open.
// =============================================================================

#include <stdint.h>

// Dual sealed WQ9D-E: aa_00627be0
extern uint32_t __fastcall Skill_ComputeEffectPresenceFlags_Inferred(void *pSkill);

void __fastcall Skill_StoreEffectPresenceFlags_Inferred(void *pSkill)
{
  uint8_t *base = (uint8_t *)pSkill;
  uint32_t presenceMask = Skill_ComputeEffectPresenceFlags_Inferred(pSkill);
  uint32_t flags620 = *(uint32_t *)(base + 0x620);

  if (flags620 == 0) {
    *(uint32_t *)(base + 0x624) = presenceMask;
    return;
  }

  // Non-zero +0x620 → force bit 2 (value 4) on stored targeting/presence flags
  *(uint32_t *)(base + 0x624) = presenceMask | 4u;

  // Char gate at +0x148: when clear, raise bit 20 on +0x620
  if (*(base + 0x148) == 0) {
    *(uint32_t *)(base + 0x620) = flags620 | 0x100000u;
  }
}
