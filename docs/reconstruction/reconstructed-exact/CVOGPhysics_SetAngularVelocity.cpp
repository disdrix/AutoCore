// =============================================================================
// CVOGPhysics_SetAngularVelocity  (inferred; Ghidra FUN_0040d040)
// -----------------------------------------------------------------------------
// Stable ID: aa_0040d040
// Address:   0x0040d040  (autoassault.exe, image base 0x400000)
// System:    physics (callee of DriveControlTick / network soft / airStab / AI)
// Generated: 2026-07-29 dual A/B — live decompile + read_memory
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: body 0x30 bytes sealed statically; image diff deferred.
// =============================================================================
//
// PURPOSE:
//   Optional readiness prepare, then body vtbl +0x54(angVelVec) — set angular velocity.
//
// SIBLING: CVOGPhysics_ApplyImpulseVector @ 0x0040d260 (identical CF, vtbl +0x50 linear).
//
// CALLEES: FUN_005070b0, FUN_005070d0, indirect (*(*(phys+0x3c))+0x54)
// CALLERS: DriveControlTick 0x00922653; FUN_0053eec0; airStabilization; DecideHeading; …
//
// ASM note: decompiler form FUN_005070b0((int)&uStack_4+3) is out-byte scaffolding;
//           thiscall ECX remains phys for both helpers (see annotated).
// =============================================================================

void __thiscall CVOGPhysics_SetAngularVelocity(int phys, uint32_t angVelVec)
{
  char *pcVar1;
  uint32_t uStack_4;

  uStack_4 = (uint32_t)phys;
  pcVar1 = (char *)FUN_005070b0((int)&uStack_4 + 3);
  if ((*pcVar1 == '\0') && (*(int *)(phys + 0x44) != 0)) {
    FUN_005070d0();
  }
  (**(code **)(**(int **)(phys + 0x3c) + 0x54))(angVelVec);
  return;
}
