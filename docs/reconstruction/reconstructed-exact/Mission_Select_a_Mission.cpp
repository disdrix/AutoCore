// RETIRED scaffold (MEGA-051 2026-08-05)
// See Mission_Select_a_Mission_008ab550.cpp and
// Client_NpcMissionDialog_ApplyPanelMode_Inferred.cpp (authoritative).

void Client_NpcMissionDialog_ApplyPanelMode_Inferred(void *dialog, int panelMode);

void Mission_Select_a_Mission(void *dialog /*ecx*/, int panelMode /*eax*/)
{
    Client_NpcMissionDialog_ApplyPanelMode_Inferred(dialog, panelMode);
}
