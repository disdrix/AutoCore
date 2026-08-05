// =============================================================================
// Creature_GetTheory  (was FUN_004c4140)
// -----------------------------------------------------------------------------
// Stable ID: aa_004c4140
// Address:   0x004c4140–0x004c41bb  (autoassault.exe, image base 0x400000)
// System:    skills-abilities / character stats
// Generated: 2026-07-29 W17-I dual A/B seal (decompile + read_memory + callers)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Dual: reviews/A|B_aa_004c4140_Creature_GetTheory.md
// =============================================================================
//
// PURPOSE:
//   Return the creature's **Theory** stat as a clamped integer:
//     clamp(min(int16(this+0x140), 200) + int16(this+0x148), 1, 250)
//
//   Product name from UI requirements formatter FUN_00845360:
//     FUN_007a6de0("Theory") paired with this call.
//
//   Also used as attacker short-stat bonus (cast to float) by
//   Skill_AccuracyScore_Inferred (0x005531d0) → Skill_NonCreatureCastAutoHit.
//
//   Siblings (not owned): Combat FUN_004c4070, Perception FUN_004c41c0.
// =============================================================================

// __fastcall / thiscall: creature in ECX; return int in EAX; plain RET
int __fastcall Creature_GetTheory(void *creature)
{
  short base;
  short bonus;
  int capped;
  int sum;

  base = *(short *)((char *)creature + 0x140);
  bonus = *(short *)((char *)creature + 0x148);

  capped = (int)base;
  if (199 < base) {
    capped = 200;
  }
  sum = capped + (int)bonus;

  if (sum < 0xfa) {
    // re-cap base (decompiler repeats min); floor branch
    capped = (int)base;
    if (199 < base) {
      capped = 200;
    }
    if (capped + (int)bonus < 2) {
      return 1;
    }
  }

  capped = (int)base;
  if (199 < base) {
    capped = 200;
  }
  if (capped + (int)bonus < 0xfa) {
    if (199 < base) {
      base = 200;
    }
    return (int)base + (int)bonus;
  }
  return 0xfa;
}

// Algebraically equivalent (readable form; same integer results for all short inputs):
//   return clamp(min((int)base, 200) + (int)bonus, 1, 250);
