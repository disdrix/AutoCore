// =============================================================================
// FUN_00627ec0  (scaffold twin — prefer Skill_ComputeEffectScore_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00627ec0
// Address:   0x00627ec0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-08-04 WQ9E-B dual A/B
// =============================================================================
// See Skill_ComputeEffectScore_Inferred.cpp for the behavior-preserving clean
// reconstruction with sealed float constants and meaningful names.
//
// Signature (Ghidra scaffold form):
//   int __fastcall FUN_00627ec0(void *pSkill);
//   ECX = skill; EAX = (int)ceil(score); plain ret
//
// Body: 0x00627ec0–0x00628516 exclusive (1878 B)
// Callees: Skill_ComputeEffectPresenceFlags_Inferred (FUN_00627be0), ceil
// Callers: 11 UNCONDITIONAL_CALL (dual-score HB/conflict compares)
// =============================================================================

// Forward to named clean unit (implementation lives in named twin).
int __fastcall Skill_ComputeEffectScore_Inferred(void *pSkill);

int __fastcall FUN_00627ec0(void *pSkill)
{
  return Skill_ComputeEffectScore_Inferred(pSkill);
}
