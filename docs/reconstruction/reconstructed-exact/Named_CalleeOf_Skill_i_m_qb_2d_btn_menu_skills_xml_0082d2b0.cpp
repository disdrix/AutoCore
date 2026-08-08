// =============================================================================
// RETIRED scaffold — Named_CalleeOf_Skill_i_m_qb_2d_btn_menu_skills_xml_0082d2b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0082d2b0
// Status:    RETIRED by MEGA-072 (2026-08-05)
// Reason:    Multi-caller shared popup-shell rebuild, not skill-menu-only.
//            Skill plate is one of 7+ CALL sites (also dualed interaction-menu
//            populate 0x0082fe20, equip menu, DATA vtbl 0x00a733b8, …).
// Replacement:
//   docs/reconstruction/reconstructed-exact/UI_InteractionMenu_RebuildPopupShell_Inferred.cpp
//   Canonical name: UI_InteractionMenu_RebuildPopupShell_Inferred
// Do not treat this file as authoritative CF.
// =============================================================================

#include <cstdint>

extern "C" void __thiscall UI_InteractionMenu_RebuildPopupShell_Inferred(void* host);

// Deprecated alias — redirects to sealed named reconstruction.
extern "C" void __thiscall
Named_CalleeOf_Skill_i_m_qb_2d_btn_menu_skills_xml_0082d2b0(void* host)
{
  UI_InteractionMenu_RebuildPopupShell_Inferred(host);
}
