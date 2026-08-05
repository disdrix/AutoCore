// =============================================================================
// Named_CalleeOf_Client_ShowMissionRewardChatToast_0051f510
// -----------------------------------------------------------------------------
// Alias of Mission_ComputeObjectiveXpAsFloat / FUN_0051f510 (aa_0051f510).
// Parent-seed name retained for xref discoverability.
// Prefer: Mission_ComputeObjectiveXpAsFloat
// Dual A/B: accept (2026-07-29 W25-I).
// =============================================================================

float /* ST0 */ Named_CalleeOf_Client_ShowMissionRewardChatToast_0051f510(void *param_1)
{
  int iVar1;

  if ((param_1 != 0) && (*(int *)((int)param_1 + 0x14c) != 0)) {
    iVar1 = Mission_ComputeObjectiveXp(param_1);
    return (float)iVar1;
  }
  return 0.0f;  // g_flZero
}
