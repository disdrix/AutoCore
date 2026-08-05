// =============================================================================
// Creature_GetPerception  (was FUN_004c41c0)
// -----------------------------------------------------------------------------
// Stable ID: aa_004c41c0
// Address:   0x004c41c0–0x004c428e  (autoassault.exe, image base 0x400000)
// System:    skills-abilities / character stats
// Generated: 2026-07-29 W18-H dual A/B seal (decompile + read_memory + callers)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Dual: reviews/A|B_aa_004c41c0_Creature_GetPerception.md
// =============================================================================
//
// PURPOSE:
//   Return the creature's **Perception** stat as a clamped integer with optional
//   MI/vehicle floor (same shape as Combat getter FUN_004c4070):
//
//     score = min(min(int16(this+0x142), 200) + int16(this+0x14a), 250)
//     thr   = (MI_vtbl(+0x1DC) != 0) ? 1 : -100
//     return max(score, thr)
//
//   Product name from UI requirements formatter FUN_00845360:
//     FUN_007a6de0("Perception") paired with this call.
//   Debug dump packs as **P** in "(C:%d Th:%d Te:%d P:%d)".
//
//   Siblings (not owned): Combat FUN_004c4070, Theory FUN_004c4140.
// =============================================================================

// __fastcall / thiscall: creature in ECX; return int in EAX; plain RET
int __fastcall Creature_GetPerception(void *creature)
{
  short base;
  short bonus;
  int score;
  int probe;
  int thr;
  int capped;

  base = *(short *)((char *)creature + 0x142);
  bonus = *(short *)((char *)creature + 0x14a);

  capped = (int)base;
  if (199 < base) {
    capped = 200;
  }
  if (capped + (int)bonus < 0xfa) {
    if (199 < base) {
      base = 200;
    }
    score = (int)base + (int)bonus;
  } else {
    score = 0xfa;
  }

  // MI this-adjust then vtbl+0x1DC (vehicle/MI presence probe)
  probe = (**(int (**)())(
      *(int *)(*(int *)(*(int *)((char *)creature + 4) + 4) + 4 + (int)creature) + 0x1dc))();
  thr = (-(unsigned int)(probe != 0) & 0x65) - 100;  // 1 or -100

  if (thr < score) {
    // recompute score (asm does not CSE)
    base = *(short *)((char *)creature + 0x142);
    capped = (int)base;
    if (199 < base) {
      capped = 200;
    }
    if (capped + (int)*(short *)((char *)creature + 0x14a) < 0xfa) {
      if (199 < base) {
        base = 200;
      }
      return (int)base + (int)*(short *)((char *)creature + 0x14a);
    }
    return 0xfa;
  }

  probe = (**(int (**)())(
      *(int *)(*(int *)(*(int *)((char *)creature + 4) + 4) + 4 + (int)creature) + 0x1dc))();
  return (-(unsigned int)(probe != 0) & 0x65) - 100;
}

// Algebraically equivalent (readable form; same integer results):
//   score = min(min((int)base, 200) + (int)bonus, 250);
//   thr   = (MI_vtbl(+0x1DC) != 0) ? 1 : -100;
//   return (thr < score) ? score : thr;   // max(score, thr)
