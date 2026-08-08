// =============================================================================
// FUN_005d5cc0  (twin of CVOGWaypoint_DoFollowObjectShortcutsUpdate)
// -----------------------------------------------------------------------------
// Stable ID: aa_005d5cc0
// Address:   0x005d5cc0 – 0x005d62fb  (autoassault.exe, image base 0x400000)
// System:    skills-abilities / waypoint path AI
// Generated: 2026-08-05 MEGA-057
// Exactness: Machine twin — same CF as named clean; Ghidra symbol retained.
// Prefer:    CVOGWaypoint_DoFollowObjectShortcutsUpdate.cpp
// =============================================================================

// See CVOGWaypoint_DoFollowObjectShortcutsUpdate.cpp for full plate, ABI, field
// map, and annotated body. This twin keeps the Ghidra FUN_* symbol for ledger
// joins and xref tables.

void __fastcall FUN_005d5cc0(void *param_1);

// Implementation is the named unit (link / include by project convention):
//   CVOGWaypoint_DoFollowObjectShortcutsUpdate
//
// Ghidra signature residual: void __fastcall FUN_005d5cc0(int param_1)
// Byte ABI: thiscall ECX=CVOGWaypoint*; void; RET 0; body 0x005d5cc0–0x005d62fb.

void __fastcall FUN_005d5cc0(void *param_1)
{
  // Forward to product-named reconstruction (same VA, same CF).
  extern void __fastcall CVOGWaypoint_DoFollowObjectShortcutsUpdate(void *this_wp);
  CVOGWaypoint_DoFollowObjectShortcutsUpdate(param_1);
}
