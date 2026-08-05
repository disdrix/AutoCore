// =============================================================================
// FUN_00560f30 / WorldObj_ReattachLinksGuarded_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00560f30
// Address:   0x00560f30  (autoassault.exe, image base 0x400000)
// Body:      0x00560f30–0x00560f60 (48 B); epilogue ret 4
// System:    world-object / phys rebind
// Generated: 2026-07-29 W27-O dual seal (live decompile ≡ raw 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================

// PURPOSE: Manager thiscall — save reentrancy flag at this+0x12c, set to 1,
// attach/register object (FUN_0055e760) then BindLinks (FUN_0055fa40), restore
// flag. Used by CVOGObject SwitchHBAI path when entering mode code 7.
// Sibling of WorldObj_RebindActivate (00560e90) and WorldObj_EnrollActivate
// (00560ec0); this unit has no counters, refcount, or host+0x28 flag write.

// void __thiscall WorldObj_ReattachLinksGuarded_Inferred(Manager *m, WorldObj *obj)
// RET 4

void __thiscall FUN_00560f30(int param_1, uint32_t param_2)
{
  uint8_t uVar1;

  uVar1 = *(uint8_t *)(param_1 + 300);
  *(uint8_t *)(param_1 + 300) = 1;
  FUN_0055e760(param_2);
  FUN_0055fa40(param_2);
  *(uint8_t *)(param_1 + 300) = uVar1;
  return;
}
