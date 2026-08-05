// =============================================================================
// CVOGHB_SlewFacingYaw_ctor_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Secondary HB ctor: attach owner, pulse period 30ms, zero facing
//           yaw (owner+0x11c), run one immediate CVOGCreature_SlewFacingYaw step.
//
// Address:  0x005d6b80  (autoassault.exe, image base 0x400000)
// Stable:   aa_005d6b80
// Body:     0x005d6b80–0x005d6c0f (144 B; RET 4)
// System:   heartbeat / creature facing
//
// Factory:  Object_EnsurePrimaryHBAI_FromAIProfile secondary path when
//           def+0x4e8==1 → operator_new(0x28) + this ctor → Enqueue + Start.
// Vtbl:     PTR_FUN_009daee8 (tick FUN_005d6c10 @ +0x0C).
//
// Exactness: CF mirrors raw + byte seal for slew this-arg residual.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Human-refined plate: 2026-07-29 W28-K
// =============================================================================

// Ghidra: FUN_005d6b80
// ABI: __thiscall; stack owner raw; RET 4; returns this

extern void __thiscall CVOGHBBase_ctor(void *self);
extern void __thiscall CVOGHBBase_SetPeriodAndCounter(void *self, int periodMs, bool resetCounter);
extern void __thiscall CVOGHBBase_AttachOwnerObject(void *self, void *pOwnerAdjusted);
extern void __thiscall CVOGCreature_SlewFacingYaw_Inferred(void *pCreature, int deltaMs);
extern void *ExceptionList;
extern void *LAB_009a7138;
extern void *PTR_FUN_009daee8;

void *__thiscall CVOGHB_SlewFacingYaw_ctor_Inferred(void *self, void *pOwnerRaw)
{
  void *local_c;
  void *puStack_8;
  unsigned local_4;
  void *pAttach;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a7138;
  local_c = ExceptionList;
  ExceptionList = &local_c;

  CVOGHBBase_ctor(self);
  local_4 = 0;
  *(void **)self = &PTR_FUN_009daee8;
  *(int *)((char *)self + 8) = 0x1e; /* pulse ms @ +0x08 */
  CVOGHBBase_SetPeriodAndCounter(self, -1000, true);

  *(void **)((char *)self + 0x24) = pOwnerRaw; /* raw owner stash */
  pAttach = pOwnerRaw;
  if (pAttach != 0) {
    /* MI adjust: *( *(p+4) + 4 ) + 4 + p */
    pAttach = (void *)(*(int *)(*(int *)((char *)pAttach + 4) + 4) + 4 + (int)pAttach);
  }
  CVOGHBBase_AttachOwnerObject(self, pAttach);

  /* bytes: xorps/movss float zero — not dword store residual alone */
  *(float *)((char *)pOwnerRaw + 0x11c) = 0.0f;
  /* bytes: ECX = raw owner @ self+0x24; stack arg = *(self+8)=0x1e */
  CVOGCreature_SlewFacingYaw_Inferred(pOwnerRaw, 0x1e);

  ExceptionList = local_c;
  return self;
}
