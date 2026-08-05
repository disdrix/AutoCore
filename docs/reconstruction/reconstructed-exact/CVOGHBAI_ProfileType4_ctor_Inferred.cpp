// =============================================================================
// CVOGHBAI_ProfileType4_ctor_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Thin HBAI subclass ctor for AI-profile factory type word 4:
//           run mid-base FUN_005d1990(this, owner), install vtbl 009db08c.
//
// Address:  0x005d7de0  (autoassault.exe, image base 0x400000)
// Stable:   aa_005d7de0
// Body:     0x005d7de0–0x005d7df8 (25 B; RET 4; pad CC)
// System:   npc-ai / HBAI / profile-type-4
//
// Factory:  Object_EnsurePrimaryHBAI_FromAIProfile case 4 → new(0xC0) + this.
// DoLogic:  CVOGHBAI_ProfileType4_DoLogic_Inferred @ 0x005d7ca0 (vtbl+0x50).
//
// Exactness: CF mirrors raw + byte seal.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Human-refined plate: 2026-07-29 W28-K
// =============================================================================

// Ghidra: FUN_005d7de0
// ABI: __thiscall; stack owner; RET 4; returns this

extern void *__thiscall FUN_005d1990(void *self, void *pOwner);
extern void *PTR_FUN_009db08c;

void *__thiscall CVOGHBAI_ProfileType4_ctor_Inferred(void *self, void *pOwner)
{
  FUN_005d1990(self, pOwner); /* thiscall: ECX=self, stack=pOwner */
  *(void **)self = &PTR_FUN_009db08c;
  return self;
}
