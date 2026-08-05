// =============================================================================
// FUN_00404dc0  —  alias plate; prefer CVOGPhysics_SetRotation.cpp
// -----------------------------------------------------------------------------
// Stable ID: aa_00404dc0
// Address:   0x00404dc0
// See:       reconstructed-exact/CVOGPhysics_SetRotation.cpp
// Dual A/B:  reviews/A_aa_00404dc0_CVOGPhysics_SetRotation.md
//            reviews/B_aa_00404dc0_CVOGPhysics_SetRotation.md
// Generated: 2026-07-29 dual A/B (scaffold superseded)
// =============================================================================

// PURPOSE: CVOGPhysics setRotation (inferred). Optional ready prepare; body
// vtbl +0x44 only when not fully ready (phys+0x40==0 OR phys+0x08==0).

void __thiscall FUN_00404dc0(int param_1, undefined4 param_2)
{
  char *pcVar1;
  undefined4 uStack_4;

  uStack_4 = param_1;
  pcVar1 = (char *)FUN_005070b0((int)&uStack_4 + 3);
  if ((*pcVar1 == '\0') && (*(int *)(param_1 + 0x44) != 0)) {
    FUN_005070d0();
  }
  if ((*(char *)(param_1 + 0x40) == '\0') || (*(int *)(param_1 + 8) == 0)) {
    (**(code **)(**(int **)(param_1 + 0x3c) + 0x44))(param_2);
  }
  return;
}
