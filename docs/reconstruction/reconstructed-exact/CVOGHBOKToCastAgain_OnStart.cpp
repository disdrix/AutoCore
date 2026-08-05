// READABILITY (human residual 2026-07-29):
//  - Body: owner gate → SetIsCastingFlag(skill,1) → tail StampLastFireTime.
//  - unaff_SI / third formal: FALSIFIED (ESI = saved this only).
//  - Stamp is CVOGHBBase_StampLastFireTime (HB+0x14), not a separate "ResetStartTick".

// =============================================================================
// CVOGHBOKToCastAgain_OnStart
// -----------------------------------------------------------------------------
// Purpose:  OK-to-cast-again HB vtable OnStart — mark skill casting + stamp last fire.
//
// Address:  0x0051e390  (autoassault.exe, image base 0x400000)
// Stable:   aa_0051e390
// System:   skills-abilities
//
// Pairs with ctor duration math and OnEnd cleanup (flag → 0).
//
// Exactness: CF mirrors raw + asm seal 2026-07-29; names cleaned; no invented clamps.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Human-refined plate: 2026-07-29 (dual residual)
// =============================================================================

/* CVOGHBOKToCastAgain_OnStart (vtable activate @ g_pVtbl+4 / 0x009ce1c8)

   if (HB+0x18 owner entity != null)
     Skill_SetIsCastingFlag(skill @ HB+0x24, 1);  // thiscall; char; skill+0x628
   CVOGHBBase_StampLastFireTime(HB);              // HB+0x14 = g_dwClientTickMs (tail) */

void __fastcall CVOGHBOKToCastAgain_OnStart(void *pHeartbeat /* ECX */)
{
  if (*(int *)((int)pHeartbeat + 0x18) != 0) {
    Skill_SetIsCastingFlag(*(void **)((int)pHeartbeat + 0x24), (char)1);
  }
  CVOGHBBase_StampLastFireTime(pHeartbeat);
}
