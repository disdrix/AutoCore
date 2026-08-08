// =============================================================================
// RETIRED scaffold alias — UI_int_btn_generic_0082fa60
// -----------------------------------------------------------------------------
// Stable ID: aa_0082fa60
// Status:    RETIRED by MEGA-076 (2026-08-05)
// Reason:    Plate-only name from "i_m_int_2d_btn_generic.xml"; role is clan
//            Invite/Kick pack, not a generic button factory.
// Canonical: UI_InteractionMenu_AddClanInviteOrKick_Inferred
// Clean:     reconstructed-exact/UI_InteractionMenu_AddClanInviteOrKick_Inferred.cpp
// =============================================================================

void UI_InteractionMenu_AddClanInviteOrKick_Inferred(void* target, void* menu);

// Keep symbol so any stale include still resolves to the named unit.
void UI_int_btn_generic_0082fa60(void* target, void* menu)
{
  UI_InteractionMenu_AddClanInviteOrKick_Inferred(target, menu);
}
