// =============================================================================
// FUN_0082f810  (twin of UI_InteractionMenu_AddSendTell_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0082f810
// Address:   0x0082f810 – 0x0082f849 inclusive (autoassault.exe, base 0x400000)
// Size:      0x3A (58 B); epilogue POP ESI; RET (C3)
// System:    interaction menu / tell UI
// Generated: 2026-08-05 MEGA-073 dual
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical name: UI_InteractionMenu_AddSendTell_Inferred
// =============================================================================

#include <cstdint>

// EDI = menu host* (parent-preserved). No stack args. ret 0.
void FUN_0082f810(void)
{
  // See UI_InteractionMenu_AddSendTell_Inferred.cpp for typed reconstruction.
  //
  // CF (sealed):
  //   btn = [EDI]->vtbl+0x444("i_m_int_2d_btn_generic.xml", 0, 0x11176, -1)
  //   if (btn) btn->vtbl+0x1D8("Send a Tell", 1, 1)
  //   [EDI+0x554] = btn
  //   return
}
