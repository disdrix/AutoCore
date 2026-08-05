// =============================================================================
// CVOGPhysics_ApplyPointImpulse  (inferred; Ghidra FUN_0058d980)
// -----------------------------------------------------------------------------
// Stable ID: aa_0058d980
// Address:   0x0058d980  (autoassault.exe, image base 0x400000)
// System:    physics / CVOGPhysics
// Generated: 2026-07-29 dual A/B W16-B — live decompile + read_memory
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: body 0x37 bytes sealed statically; image diff deferred.
// =============================================================================
//
// PURPOSE:
//   Optional readiness prepare, then body vtbl +0x60(impulse, point) — apply point impulse.
//
// SIBLINGS (same ready-gate prologue; different vtbl slot / arity):
//   CVOGPhysics_ApplyImpulseVector     @ 0x0040d260  vtbl +0x50  (1 arg, ret 4)
//   CVOGPhysics_SetAngularVelocity     @ 0x0040d040  vtbl +0x54  (1 arg, ret 4)
//   CVOGPhysics_ApplyVector_Vtbl5c     @ 0x00404cb0  vtbl +0x5c  (1 arg, ret 4)
//   this                               @ 0x0058d980  vtbl +0x60  (2 args, ret 8)
//
// CALLEES: FUN_005070b0 (ProbeReadyFlag), FUN_005070d0 (PrepareReady),
//          indirect (*(*(phys+0x3c))+0x60)
//
// PRIOR ART: physics/0.4-suspension.md — chassis RB applyPointImpulse at vtbl +0x60
//            (postTick hardpoint impulse; impulse vec + wheel/contact).
//
// ASM note: decompiler form FUN_005070b0((int)&uStack_4+3) is out-byte scaffolding;
//           thiscall ECX remains phys for both helpers (see annotated).
// =============================================================================

void __thiscall CVOGPhysics_ApplyPointImpulse(int phys, uint32_t impulse, uint32_t point)
{
  char *pcVar1;
  uint32_t uStack_4;

  uStack_4 = (uint32_t)phys;
  pcVar1 = (char *)FUN_005070b0((int)&uStack_4 + 3);
  if ((*pcVar1 == '\0') && (*(int *)(phys + 0x44) != 0)) {
    FUN_005070d0();
  }
  (**(code **)(**(int **)(phys + 0x3c) + 0x60))(impulse, point);
  return;
}
