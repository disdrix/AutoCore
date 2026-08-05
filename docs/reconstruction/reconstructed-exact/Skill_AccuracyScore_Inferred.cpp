// =============================================================================
// Skill_AccuracyScore_Inferred  (was FUN_005531d0)
// -----------------------------------------------------------------------------
// Stable ID: aa_005531d0
// Address:   0x005531d0–0x00553239  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-29 dual A/B seal (decompile + body assembly + xrefs)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Dual: reviews/A|B_aa_005531d0_Skill_AccuracyScore_Inferred.md
// =============================================================================
//
// PURPOSE:
//   Skill thiscall accuracy **score** helper for AccuracyHitCheck (and a second
//   unnamed site that scales score*100 for display).
//   - If attacker non-null and attacker->vtbl[+0x214]() non-null:
//       bonus = (float) FUN_004c4140(creature)   // short stats, clamp [1,250]
//     else bonus = 0.0f
//   - return Skill_NonCreatureCastAutoHit(bonus, 0.0f, skill.f32[+0x24],
//                                         attacker, target, debugReasonOut)
//
// NAME: INFERRED — no product string/RTTI on this VA.
// =============================================================================

// External (Ghidra / sibling duals)
// short __fastcall FUN_004c4140(void *creature); // +0x140 / +0x148 clamp
// float Skill_NonCreatureCastAutoHit(float a, float b, float skillAcc,
//                                    void *attacker, void *target, char *dbg);

float __thiscall Skill_AccuracyScore_Inferred(
    void *skill,
    void *attacker,
    void *target,
    char *debugReasonOut)
{
  float attackerShortBonus;
  void *creature;
  short shortStat;

  attackerShortBonus = 0.0f;

  if (attacker != (void *)0x0) {
    creature = (*(void *(__thiscall **)(void *))(*(int *)attacker + 0x214))(attacker);
    if (creature != (void *)0x0) {
      creature = (*(void *(__thiscall **)(void *))(*(int *)attacker + 0x214))(attacker);
      shortStat = (short)FUN_004c4140(creature);
      attackerShortBonus = (float)(int)shortStat;
    }
  }

  return Skill_NonCreatureCastAutoHit(
      attackerShortBonus,
      0.0f,
      *(float *)((char *)skill + 0x24),
      attacker,
      target,
      debugReasonOut);
}
