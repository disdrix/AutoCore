// =============================================================================
// FUN_008e55e0  (twin of UI_CraftHost_RefreshCraftEnableAndStatus_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_008e55e0
// Address:   0x008e55e0–0x008e598d inclusive (942 B / 0x3AE)
// Module:    autoassault.exe (image base 0x400000)
// System:    inventory-transfer
// Dual:      R13-015 OWN-ONLY 2026-08-05
// =============================================================================
// Canonical human name: UI_CraftHost_RefreshCraftEnableAndStatus_Inferred
// Full annotated clean plate:
//   reconstructed-exact/UI_CraftHost_RefreshCraftEnableAndStatus_Inferred.cpp
// =============================================================================

void UI_CraftHost_RefreshCraftEnableAndStatus_Inferred(void* host /*EAX*/);

// Ghidra default symbol entry — same body, EAX host, plain RET.
void FUN_008e55e0(void) {
  // Host arrives in EAX (fastcall-style single register arg; not ECX thiscall).
  void* host;
  __asm { mov host, eax }
  UI_CraftHost_RefreshCraftEnableAndStatus_Inferred(host);
}
