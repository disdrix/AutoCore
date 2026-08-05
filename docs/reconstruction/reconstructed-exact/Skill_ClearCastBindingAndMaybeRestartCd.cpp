// READABILITY (auto CF + residual 2026-07-29):
//  - Body size: ~33 non-empty decompiler lines; PE body through ret ~0x87.
//  - Control: find → optional erase → optional StartCastAgain.
//  - Callees: FUN_00518c20×3, FUN_0051c150, FUN_0051cb40,
//    owner.vtbl+0x234(skillId), Skill_StartCastAgainHeartbeat.
//  - ABI: __thiscall RET 0x14 (5 stack dwords) — PE sealed.
//  - Residual 2026-07-29: formals renamed; multi-arg FUN_00518c20 / zero-arg
//    vtbl+0x234 / 4-arg StartCastAgain are decompiler noise (see dual A/B).

// =============================================================================
// Skill_ClearCastBindingAndMaybeRestartCd
// -----------------------------------------------------------------------------
// Stable ID: aa_0051a700
// Address:   0x0051a700  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-23 from raw capture; residual strengthen 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: PE body sealed ABI/CF this residual; full image diff OPEN.
// Dual A/B:  reviews/A_aa_0051a700_Skill_ClearCastBindingAndMaybeRestartCd.md
//            reviews/B_aa_0051a700_Skill_ClearCastBindingAndMaybeRestartCd.md
// Scratch:   reviews/a_0051a700.md
// =============================================================================

/*
 * Behavioral notes:
 * - Mutating active-cast binding clear + optional cast-again restart.
 * - Map shell: FUN_00518c20 (lazy owner+0x68; leave-FUN — product name withheld).
 * - Find: FUN_0051c150 (key @ node+0x10); end = *(map+4).
 * - Erase only if partial TFID match: node+0x18/+0x1c/byte(+0x20) vs stack1..3.
 * - Full TFID16 equality NOT required; stack4 unread in body.
 * - Erase: FUN_0051cb40 (MSVC map erase; "invalid map/set<T> iterator").
 * - Restart arm is OUTSIDE erase gate:
 *     skill = owner->vtbl[0x234/4](skillId);
 *     if (skill && skill[+0x61c] != 0)
 *       Skill_StartCastAgainHeartbeat(owner, skill, chargeMs=0);
 * - Polarity of +0x61c is INVERTED vs RequestCast/ApplyStatus (those use ==0).
 * - Not SiblingCastClear (host+0xB0 list). Not LocalCastValidate.
 *
 * Readability pass:
 * - Control flow and call order preserved from authoritative raw.
 * - Comments document recovered CF where decompiler noise mis-attributes args.
 */

/* Skill_ClearCastBindingAndMaybeRestartCd(owner, skillId, tfid0, tfid1, tfid2, pad)

   Clears active-cast binding matching skillId+partial TFID; if skill+0x61c set,
   Skill_StartCastAgainHeartbeat(owner, skill, 0).

   ABI: __thiscall RET 0x14 (PE-sealed). */

void __thiscall
Skill_ClearCastBindingAndMaybeRestartCd
          (void *this,int nSkillId,int nTfid0,int nTfid1,int nTfid2,char padUnused)

{
  int iVar1;
  void *pSkill;
  void **ppvVar2;
  void **ppvVar3;
  void *local_4;

  // NOISE: unary FUN_00518c20(mapOwner) — staged pushes feed FUN_0051c150.
  ppvVar3 = (void **)&nSkillId;
  ppvVar2 = &local_4;
  local_4 = this;
  FUN_00518c20(ppvVar2,ppvVar3);
  // Recovered: FUN_0051c150(pMap, &local_4, &nSkillId).
  FUN_0051c150(ppvVar2,ppvVar3);
  iVar1 = FUN_00518c20();
  if ((((local_4 != *(void **)(iVar1 + 4)) && (*(int *)((int)local_4 + 0x18) == nTfid0)) &&
      (*(int *)((int)local_4 + 0x1c) == nTfid1)) &&
     (*(char *)((int)local_4 + 0x20) == (char)nTfid2)) {
    FUN_00518c20(&nSkillId,local_4);
    FUN_0051cb40();
  }
  // PE: push nSkillId; call [vtbl+0x234]  (decomp zero-arg is noise)
  pSkill = (void *)(**(code **)(*(int *)this + 0x234))(nSkillId);
  if ((pSkill != (void *)0x0) && (*(char *)((int)pSkill + 0x61c) != '\0')) {
    // PE @ 0x0051a77c: push 0; push skill; mov ecx,owner; call StartCastAgain
    // Sibling ABI: Skill_StartCastAgainHeartbeat(owner, skill, chargeMs) RET 0x8
    Skill_StartCastAgainHeartbeat(this,pSkill,0);
  }
  return;
}
