// =============================================================================
// FUN_008ab550 (Ghidra twin)
// -----------------------------------------------------------------------------
// Stable ID: aa_008ab550
// Address:   0x008ab550–0x008ab799 (586 B / 0x24A)
// Named:     Client_NpcMissionDialog_ApplyPanelMode_Inferred
// System:    missions-progression
//
// Authoritative clean body lives in:
//   Client_NpcMissionDialog_ApplyPanelMode_Inferred.cpp
//
// ABI: ECX = dialog*, EAX = panelMode {0,1,2,3}, plain RET (C3).
// MEGA-051 dual seal 2026-08-05.
// =============================================================================

// Forward to the named reconstruction (same symbol contract).
void Client_NpcMissionDialog_ApplyPanelMode_Inferred(void *dialog /*ecx*/,
                                                       int panelMode /*eax*/);

void FUN_008ab550(void *dialog /*ecx*/, int panelMode /*eax*/)
{
    Client_NpcMissionDialog_ApplyPanelMode_Inferred(dialog, panelMode);
}
