// RETIRED scaffold (MEGA-051 2026-08-05)
// -----------------------------------------------------------------------------
// Prior string-only name Mission_Select_a_Mission_008ab550 understated modes
// 0/1/2 and misstated ABI (decompiler in_EAX lag).
//
// Superseded by:
//   Client_NpcMissionDialog_ApplyPanelMode_Inferred.cpp
//   FUN_008ab550.cpp (Ghidra twin)
//
// Stable ID remains aa_008ab550 @ 0x008ab550.
// =============================================================================

void Client_NpcMissionDialog_ApplyPanelMode_Inferred(void *dialog, int panelMode);

// Compatibility shim — do not extend.
void Mission_Select_a_Mission_008ab550(void *dialog /*ecx*/, int panelMode /*eax*/)
{
    Client_NpcMissionDialog_ApplyPanelMode_Inferred(dialog, panelMode);
}
