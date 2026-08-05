// =============================================================================
// Skill_NonCreatureCastAutoHit
// -----------------------------------------------------------------------------
// Stable ID: aa_004ceba0
// Address:   0x004ceba0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-23 scaffold; refined notes 2026-07-29 (accuracy score chain)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================
//
// PURPOSE: Accuracy hit-chance SCORE (float in ~[0,1]). Plate name from
//   "Non-Creature cast (AutoHit)". Shared kernel for creature combat score +
//   AutoHit short-circuits (inanimate victim / non-creature attacker).
//
// CHAIN:
//   Skill_AccuracyHitCheck_Inferred (0x00553240)
//     → FUN_005531d0 (0x005531d0)
//       → Skill_NonCreatureCastAutoHit (this)
//     → miss if score <= (roll%100)*0.01f
//
// SIGNATURE (caller-recovered; decompiler still voids formals):
//   float10 Skill_NonCreatureCastAutoHit(
//       float attackerBonus,  // 005531d0: (float)FUN_004c4140(creature) or 0
//       float unusedZero,     // callers pass 0; unused in high pcode
//       float skillAccuracy,  // skill+0x24; unused in high pcode (parent -1 gate)
//       void *attacker,
//       void *victim,
//       char *diagOptional);
//
// CONSTANTS (read_memory):
//   g_flOne=1.0  g_flZero=0.0
//   DAT_009cbf7c=0.95  g_flKillSpreeBonusPerStack=0.05  DAT_00af1b6c=0.15
//
// BASE SCORE (high pcode FLOAT_ADD @ 004ced06):
//   score = *(float*)(attacker.creature + 0x260) + attackerBonus
//   then clamp [0.05, 0.95]; if both have vfunc+0x210 and score<0.15 → 0.15
//
// NOTE: FUN_004c4070 / FUN_004c41c0 are invoked but returns discarded in high pcode.
// =============================================================================

// Embedded strings:
//   "Victim inanimate (AutoHit)"
//   "Non-Creature cast (AutoHit)"
//   "No Attacker" / "No Victim"

/*
 * Behavioral notes:
 * - Domain alias of FUN_004ceba0; plate-driven rename.
 * - unaff_retaddr in raw = first float param (decompiler stack defect).
 * - in_stack_00000010/14/18 = attacker / victim / diag.
 * - Runtime / differential verification: OPEN.
 */

float10 Skill_NonCreatureCastAutoHit(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  float fVar5;
  float fVar6;
  float unaff_retaddr; /* first float param (attackerBonus) — decompiler name */
  float fVar7;
  int *in_stack_00000010; /* attacker */
  int *in_stack_00000014; /* victim */
  char *in_stack_00000018; /* diag */

  if (in_stack_00000010 == (int *)0x0) {
    if (in_stack_00000018 != (char *)0x0) {
      *(uint32_t *)in_stack_00000018 = s_No_Attacker_009cc380._0_4_;
      *(uint32_t *)(in_stack_00000018 + 4) = s_No_Attacker_009cc380._4_4_;
      *(uint32_t *)(in_stack_00000018 + 8) = s_No_Attacker_009cc380._8_4_;
    }
    return (float10)g_flOne;
  }
  if (in_stack_00000014 == (int *)0x0) {
    if (in_stack_00000018 != (char *)0x0) {
      *(uint32_t *)in_stack_00000018 = s_No_Victim_009cc374._0_4_;
      *(uint32_t *)(in_stack_00000018 + 4) = s_No_Victim_009cc374._4_4_;
      *(uint16_t *)(in_stack_00000018 + 8) = s_No_Victim_009cc374._8_2_;
    }
    return (float10)g_flZero;
  }
  iVar1 = (**(code **)(*in_stack_00000014 + 0x214))();
  if (iVar1 == 0) {
    if (in_stack_00000018 != (char *)0x0) {
      pcVar4 = "Victim inanimate (AutoHit)";
      for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
        *(uint32_t *)in_stack_00000018 = *(uint32_t *)pcVar4;
        pcVar4 = pcVar4 + 4;
        in_stack_00000018 = in_stack_00000018 + 4;
      }
      *(uint16_t *)in_stack_00000018 = *(uint16_t *)pcVar4;
      in_stack_00000018[2] = pcVar4[2];
    }
    return (float10)g_flOne;
  }
  iVar1 = (**(code **)(*in_stack_00000010 + 0x214))();
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*in_stack_00000010 + 0x27c))();
    iVar2 = (**(code **)(*in_stack_00000014 + 0x27c))();
    iVar3 = (**(code **)(*in_stack_00000010 + 0x210))(0);
    if ((iVar3 == 0) || (iVar3 = (**(code **)(*in_stack_00000014 + 0x210))(0), iVar3 == 0)) {
      if (9 < iVar1 - iVar2) {
        return (float10)DAT_009cbf7c; /* 0.95 */
      }
      if (iVar1 - iVar2 < -9) {
        return (float10)g_flKillSpreeBonusPerStack; /* 0.05 */
      }
    }
    (**(code **)(*in_stack_00000010 + 0x214))();
    FUN_004c4070(); /* return discarded in high pcode */
    (**(code **)(*in_stack_00000014 + 0x214))();
    FUN_004c41c0(); /* return discarded in high pcode */
    iVar1 = (**(code **)(*in_stack_00000010 + 0x214))();
    fVar5 = *(float *)(iVar1 + 0x260) + unaff_retaddr; /* base score */
    iVar1 = (**(code **)(*in_stack_00000014 + 0x1d4))();
    if ((iVar1 != 0) &&
       (iVar1 = (**(code **)(*in_stack_00000014 + 0x1d4))(), *(int *)(iVar1 + 0x254) != 0)) {
      (**(code **)(*in_stack_00000014 + 0x1d4))();
    }
    iVar1 = (**(code **)(*in_stack_00000014 + 0x214))();
    if (iVar1 != 0) {
      (**(code **)(*in_stack_00000014 + 0x214))();
    }
    iVar1 = (**(code **)(*in_stack_00000014 + 0x210))(0);
    if (iVar1 != 0) {
      (**(code **)(*in_stack_00000014 + 0x210))(0);
    }
    iVar1 = (**(code **)(*in_stack_00000010 + 0x210))(0);
    if (iVar1 != 0) {
      (**(code **)(*in_stack_00000010 + 0x210))(0);
    }
    (**(code **)(*in_stack_00000010 + 0x214))();
    iVar1 = (**(code **)(*in_stack_00000010 + 0x210))(0);
    /* clamp: dual-vehicle floor 0.15; else [0.05, 0.95] */
    if (((((iVar1 == 0) || (iVar1 = (**(code **)(*in_stack_00000014 + 0x210))(0), iVar1 == 0)) ||
         (fVar7 = DAT_00af1b6c, DAT_00af1b6c <= fVar5)) &&
        (fVar6 = DAT_009cbf7c, fVar7 = fVar5, DAT_009cbf7c < fVar5)) ||
       (fVar6 = g_flKillSpreeBonusPerStack, fVar7 < g_flKillSpreeBonusPerStack)) {
      fVar7 = fVar6;
    }
    return (float10)fVar7;
  }
  if (in_stack_00000018 != (char *)0x0) {
    pcVar4 = "Non-Creature cast (AutoHit)";
    for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
      *(uint32_t *)in_stack_00000018 = *(uint32_t *)pcVar4;
      pcVar4 = pcVar4 + 4;
      in_stack_00000018 = in_stack_00000018 + 4;
    }
  }
  return (float10)g_flOne;
}
