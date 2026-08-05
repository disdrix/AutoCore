// =============================================================================
// Client_DismissModalPrompt — named alias of FUN_007fc360
// -----------------------------------------------------------------------------
// Stable ID: aa_007fc360
// Address:   0x007fc360–0x007fc487
// See:       reconstructed-exact/FUN_007fc360.cpp for behavior-exact body
// Name:      INFERRED 2026-07-29 W17-M from Client_ShowModalPrompt first-call,
//            ESC path, UiModalDispatch abandon close-only, PacketDispatch, login UI.
// Ghidra:    FUN_007fc360 (keep for xref continuity)
// =============================================================================

// Signature (sealed):
//   void Client_DismissModalPrompt(void);  // EAX = ClientGame*
//
// Behavior summary:
//   Gate: client+0x1118 (panel) && client+0xf40 (host holder).
//   If panel vtbl+0x3d8: host+0xb0(panel); panel+0x440; optional 0x8006 send;
//   restore host dual-id 0x514/0x518 -> 0x498/0x49c; maybe +0xf38 vtbl+0x3c4.
//   Always: panel+0x4fd = 0.
