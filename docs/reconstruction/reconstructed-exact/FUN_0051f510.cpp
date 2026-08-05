// =============================================================================
// FUN_0051f510  (scaffold alias → Mission_ComputeObjectiveXpAsFloat)
// -----------------------------------------------------------------------------
// Stable ID: aa_0051f510
// Address:   0x0051f510  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-07-29 W25-I seal (replaces 2026-07-23 auto scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical clean: Mission_ComputeObjectiveXpAsFloat.cpp
// Dual A/B: accept (W25-I).
// =============================================================================

float /* ST0 */ FUN_0051f510(void *param_1)
{
  int iVar1;

  if ((param_1 != 0) && (*(int *)((int)param_1 + 0x14c) != 0)) {
    iVar1 = Mission_ComputeObjectiveXp(param_1);
    return (float)iVar1;
  }
  return 0.0f;  // g_flZero @ 0x00a0f518
}
