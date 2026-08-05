// =============================================================================
// Vehicle_GetSkillCooldownModifier
// -----------------------------------------------------------------------------
// Stable ID: aa_0052a9b0
// Address:   0x0052a9b0  (autoassault.exe, image base 0x400000)
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

/* Vehicle_GetSkillCooldownModifier
   
   Parameters:
     this           - character/vehicle context (thiscall)
     categoryScale  - base category scale (default g_flOne=1.0 if unmapped)
   
   Algorithm:
     look up category scale map entry
     if vehicle has power plant at +0x268: scale *= plant+0xCC
   
   Returns: float10 cooldown scale for cast-again duration
   
   Used by CVOGHBOKToCastAgain_ctor / hotbar recharge UI. */

float10 * __thiscall
Vehicle_GetSkillCooldownModifier(void *this,float10 *__return_storage_ptr__,float flCategoryScale)

{
  float10 *pfVar1;
  int *unaff_ESI;
  void *pCategoryIt;
  
  pCategoryIt = this;
  Map_LowerBoundFindByIntKey
            ((void *)((int)this + 0xc70),&pCategoryIt,&__return_storage_ptr__,unaff_ESI);
  pfVar1 = (float10 *)0x0;
  if (*(int *)((int)this + 0x250) != 0) {
    pfVar1 = *(float10 **)(*(int *)((int)this + 0x250) + 0x268);
  }
  return pfVar1;
}
