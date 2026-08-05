// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: Skill_LocalRangeTargetCheck×2, CVOGReaction_RandomUnitScalar, Skill_StartCastAgainHeartbeat, miss.
//  - Return sites: 2.

// =============================================================================
// Skill_LocalRangeTargetCheck
// -----------------------------------------------------------------------------
// Stable ID: aa_00553130
// Address:   0x00553130  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* Skill_LocalRangeTargetCheck(pCaster, pSkill, pInferredArg)

   

   Accuracy/range gate used by Skill_LocalCastValidate and NPC path.

   May start short cast-again on miss (return 0x0f).

   

   Returns: 0 ok, else eSkillResponses-like code

   INFERRED: exact accuracy formula. */



int __thiscall Skill_LocalRangeTargetCheck(void *this,void *pCaster,void *pSkill,void *pInferredArg)



{

  ushort uVar1;

  int iVar2;

  int unaff_EDI;

  float fVar3;

  

  if ((((pCaster != (void *)0x0) && (*(int *)((int)pCaster + 0xa4) != 0)) &&

      (*(float *)((int)this + 0x108) != g_flZero)) &&

     (*(char *)(*(int *)((int)pCaster + 0xa4) + 0x7e) != '\0')) {

    iVar2 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar2 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = 0;

    }

    uVar1 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

    *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

    fVar3 = (float)uVar1 * DAT_00aaa638;

    if (*(float *)((int)this + 0x108) <= fVar3 && fVar3 != *(float *)((int)this + 0x108)) {

      if ((char)pInferredArg == '\0') {

        Skill_StartCastAgainHeartbeat(pCaster,this,*(void **)((int)this + 0x10),unaff_EDI);

      }

      return 0xf;

    }

  }

  iVar2 = (**(code **)(**(int **)((int)this + 0x5f0) + 0x1c))(pCaster,this);

  return iVar2;

}
