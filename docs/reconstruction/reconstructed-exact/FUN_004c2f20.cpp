// =============================================================================
// FUN_004c2f20 — alias plate
// -----------------------------------------------------------------------------
// Stable ID: aa_004c2f20
// Address:   0x004c2f20  (autoassault.exe, image base 0x400000)
// Canonical: Skill_ApplyBoundStatusMotionIfPresent_Inferred
// Clean:     reconstructed-exact/Skill_ApplyBoundStatusMotionIfPresent_Inferred.cpp
// System:    skills-abilities
// Generated: 2026-07-29 W21-H dual seal
// Exactness: Behavior-preserving; ABI from read_memory (thiscall + RET 4 + tail JMP).
// =============================================================================

// PURPOSE: Optional bound-object status/motion apply for skillId when +0x1FC set.
// See named clean for full plate.

void __thiscall FUN_004c2f20(void *boundObj /* ECX */, int skillId /* stack */)
{
  void *motionCtl = *(void **)((char *)boundObj + 0x1fc);
  if (motionCtl != 0) {
    FUN_005d0d60(motionCtl, skillId); // machine: JMP tail
    return;
  }
  return;
}
