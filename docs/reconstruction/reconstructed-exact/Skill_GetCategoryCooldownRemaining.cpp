// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×5, return×3.
//  - Notable callees: Skill_GetCategoryCooldownMap×3, FUN_004188e0, FUN_00418b80, Skill_GetCategoryCooldownRemaining, remaining, seconds.
//  - Return sites: 3.

// =============================================================================
// Skill_GetCategoryCooldownRemaining
// -----------------------------------------------------------------------------
// Stable ID: aa_00519150
// Address:   0x00519150  (autoassault.exe, image base 0x400000)
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

/* Skill_GetCategoryCooldownRemaining(nCategoryId, bAsSeconds)

   

   Parameters:

     nCategoryId - skill+0x5e8 category key

     bAsSeconds  - nonzero returns remaining as float seconds (ms * g_flMsToSeconds)

   

   Algorithm: map lookup; entry +0x10 start, +0x14 duration; erase if expired.

   Returns: remaining (float10) or 0 if none.

   

   VERIFIED against quickbar consumers. */



float10 * Skill_GetCategoryCooldownRemaining

                    (float10 *__return_storage_ptr__,int nCategoryId,char bAsSeconds)



{

  float10 *pfVar1;

  uint nDeadline;

  void *in_ECX;

  void **ppvVar2;

  float10 **ppfVar3;

  void *pMapIt;

  int *pTmp;

  

  ppfVar3 = &__return_storage_ptr__;

  ppvVar2 = &pMapIt;

  pMapIt = in_ECX;

  Skill_GetCategoryCooldownMap(in_ECX);

  FUN_00418b80(ppvVar2,ppfVar3);

  pfVar1 = Skill_GetCategoryCooldownMap(in_ECX);

  if (pMapIt != *(void **)((int)pfVar1 + 4)) {

    __return_storage_ptr__ = *(float10 **)((int)pMapIt + 0x14);

    nDeadline = *(int *)((int)pMapIt + 0x10) + (int)__return_storage_ptr__;

    if (g_dwClientTickMs < nDeadline) {

      pfVar1 = (float10 *)(nDeadline - g_dwClientTickMs);

      if ((char)nCategoryId != '\0') {

        return pfVar1;

      }

      return pfVar1;

    }

    pTmp = &nCategoryId;

    Skill_GetCategoryCooldownMap(in_ECX);

    pfVar1 = (float10 *)FUN_004188e0(pTmp,pMapIt);

  }

  return pfVar1;

}
