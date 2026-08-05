// =============================================================================
// FUN_0040d040  (== CVOGPhysics_SetAngularVelocity, aa_0040d040)
// -----------------------------------------------------------------------------
// Stable ID: aa_0040d040
// Address:   0x0040d040  (autoassault.exe, image base 0x400000)
// System:    physics
// Generated: 2026-07-29 dual A/B refine (CF ≡ raw)
// Prefer:    reconstructed-exact/CVOGPhysics_SetAngularVelocity.cpp
// =============================================================================

void __thiscall FUN_0040d040(int param_1, uint32_t param_2)
{
  char *pcVar1;
  uint32_t uStack_4;

  uStack_4 = (uint32_t)param_1;
  pcVar1 = (char *)FUN_005070b0((int)&uStack_4 + 3);
  if ((*pcVar1 == '\0') && (*(int *)(param_1 + 0x44) != 0)) {
    FUN_005070d0();
  }
  (**(code **)(**(int **)(param_1 + 0x3c) + 0x54))(param_2);
  return;
}
