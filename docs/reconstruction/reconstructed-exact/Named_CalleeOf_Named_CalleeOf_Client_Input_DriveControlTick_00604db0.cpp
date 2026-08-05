// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_Input_DriveControlTick_00604db0
// -----------------------------------------------------------------------------
// Stable ID: aa_00604db0
// SUPERSEDED NAME — prefer CVOGHBBase_SetPartnerLink
// Address:   0x00604db0  (autoassault.exe, image base 0x400000)
// System:    object / combat-target / HB
// Generated: 2026-07-23 scaffold; 2026-07-29 W20-S supersede note
// =============================================================================

// PURPOSE (auto, legacy): DriveControlTick chain name was xref-seed only.
// Sole direct caller is Object_SetSelectedTarget (0x005172d0), not drive tick.
// Canonical: CVOGHBBase_SetPartnerLink — partner at +0x24, owner gate at +0x18.

void __thiscall Named_CalleeOf_Named_CalleeOf_Client_Input_DriveControlTick_00604db0(
    int param_1, int param_2)
{
  if ((param_2 == 0) || (*(int *)(param_2 + 0x18) != *(int *)(param_1 + 0x18))) {
    *(int *)(param_1 + 0x24) = param_2;
  }
  return;
}
