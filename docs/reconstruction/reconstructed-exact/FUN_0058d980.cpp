// =============================================================================
// FUN_0058d980  — Ghidra name twin of CVOGPhysics_ApplyPointImpulse
// -----------------------------------------------------------------------------
// Stable ID: aa_0058d980
// Address:   0x0058d980  (autoassault.exe, image base 0x400000)
// System:    physics / CVOGPhysics
// Generated: 2026-07-29 dual A/B W16-B — live decompile + read_memory
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: body 0x37 bytes sealed statically; image diff deferred.
// Canonical clean: reconstructed-exact/CVOGPhysics_ApplyPointImpulse.cpp
// =============================================================================

void __thiscall FUN_0058d980(int phys, uint32_t impulse, uint32_t point)
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
