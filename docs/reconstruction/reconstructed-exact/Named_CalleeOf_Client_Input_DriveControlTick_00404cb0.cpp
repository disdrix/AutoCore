// =============================================================================
// CVOGPhysics_ApplyVector_Vtbl5c_Inferred
// (scaffold alias: Named_CalleeOf_Client_Input_DriveControlTick_00404cb0)
// -----------------------------------------------------------------------------
// Stable ID: aa_00404cb0
// Address:   0x00404cb0
// Also called from FUN_0091d460, FUN_0091d660, site 0x0095846c — not DCT-only.
// See FUN_00404cb0.cpp for full plate. Dual A/B 2026-07-29.
// =============================================================================

void __thiscall Named_CalleeOf_Client_Input_DriveControlTick_00404cb0(
    int param_1, uint32_t /* pointer width */ param_2)
{
  char *pcVar1;
  uint32_t uStack_4;

  uStack_4 = param_1;
  pcVar1 = (char *)FUN_005070b0((int)&uStack_4 + 3);
  if ((*pcVar1 == '\0') && (*(int *)(param_1 + 0x44) != 0)) {
    FUN_005070d0();
  }
  (**(code **)(**(int **)(param_1 + 0x3c) + 0x5c))(param_2);
  return;
}
