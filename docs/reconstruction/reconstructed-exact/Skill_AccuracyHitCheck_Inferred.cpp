// =============================================================================
// Skill_AccuracyHitCheck_Inferred  (was FUN_00553240)
// -----------------------------------------------------------------------------
// Stable ID: aa_00553240
// Address:   0x00553240–0x005532ce  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-29 dual A/B seal (decompile + call-site assembly)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Dual: reviews/A|B_aa_00553240_Skill_AccuracyHitCheck_Inferred.md
// =============================================================================
//
// PURPOSE:
//   Skill thiscall accuracy hit/miss gate for ApplyEffects (skill+0x624 bit0) and
//   multi-target helper FUN_0058c850.
//   - skill+0x24 f32 == -1.0f → auto-hit (return 1)
//   - else score = FUN_005531d0(attacker, target, &debugBuf); // this=skill
//   - miss if score <= (roll % 100) * 0.01f → optional *out=1, return 0
//   - else return 1
//
// NAME: INFERRED — no product string/RTTI.
// =============================================================================

// External (Ghidra names / sealed sibling roles)
// float10 FUN_005531d0(void *attacker, void *target, char *debugReasonOut); // thiscall skill
// DAT_00aaa668 = -1.0f
// DAT_00a0f718 = 0.01f

unsigned int __thiscall Skill_AccuracyHitCheck_Inferred(
    void *skill,
    void *attacker,
    void *target,
    unsigned short roll,
    unsigned char *outMissFlagOptional)
{
  float acc;
  unsigned int junkHigh;
  int i;
  unsigned int *pClear;
  long double score;
  unsigned short debugLead;
  unsigned int debugBody[255];
  unsigned char deadLocal;

  acc = *(float *)((char *)skill + 0x24);

  /* zero ~0x400-byte debug reason buffer for score helper */
  debugLead = 0;
  pClear = debugBody;
  for (i = 0xff; i != 0; i = i + -1) {
    *pClear = 0;
    pClear = pClear + 1;
  }
  *(unsigned short *)pClear = 0;

  /* decompiler FP-flag pack into junkHigh; not semantically required */
  junkHigh = (unsigned int)(unsigned char)(
      ((acc == -1.0f) << 6) |
      ((/* NAN(acc) || NAN(-1.0f) */ 0) << 2) |
      2U |
      (acc < -1.0f))
      << 8;
  deadLocal = 0;

  if (acc != -1.0f) {
    score = (long double)FUN_005531d0(attacker, target, &debugLead);
    junkHigh = (unsigned int)roll / 100; /* not used in hit decision */
    if (score <= (long double)((unsigned int)roll % 100) * (long double)0.01f) {
      if (outMissFlagOptional != (unsigned char *)0x0) {
        *outMissFlagOptional = 1;
      }
      return (unsigned int)(size_t)outMissFlagOptional & 0xffffff00; /* AL = 0 miss */
    }
  }
  return (junkHigh & 0xffffff00) | 1; /* AL = 1 hit */
}
