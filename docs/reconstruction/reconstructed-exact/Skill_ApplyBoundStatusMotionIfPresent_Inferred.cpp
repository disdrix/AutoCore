// =============================================================================
// Skill_ApplyBoundStatusMotionIfPresent_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004c2f20
// Address:   0x004c2f20  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-29 W21-H dual seal (decompile + read_memory)
// Exactness: Behavior-preserving rewrite. ABI from machine bytes supersedes
//            decompiler __fastcall / zero-arg callee display.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Optional status/motion side path during skill apply-effects.
//   If boundObj+0x1FC is non-null, tail into FUN_005d0d60(sub, skillId)
//   (skill-id table → handbrake / impulse / heading / flags on bound entity).
//   If null, no-op (RET 4).
//
// CALLER (sole xref):
//   Skill_ApplyEffectsOnTarget_Inferred @ 0x00553936
//     after caster->vtbl+0x214() probe non-null and
//     caster->vtbl+0x214(skillId) returns boundObj in EAX → ECX.
//
// CALLEE:
//   FUN_005d0d60 (thiscall, this=sub @ bound+0x1FC, stack skillId)
//
// =============================================================================

// Scaffold alias: FUN_004c2f20.cpp (same CF)

void __thiscall Skill_ApplyBoundStatusMotionIfPresent_Inferred(
    void *boundObj /* ECX */,
    int skillId /* stack, RET 4 */)
{
  void *motionCtl = *(void **)((char *)boundObj + 0x1fc);
  if (motionCtl != 0) {
    // Machine: JMP FUN_005d0d60 — stack skillId forwarded; no return here.
    FUN_005d0d60(motionCtl, skillId);
    return;
  }
  return;
}
