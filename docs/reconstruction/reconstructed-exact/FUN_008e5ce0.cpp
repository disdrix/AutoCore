// =============================================================================
// FUN_008e5ce0 / Client_UI_CraftHost_BindObjectByTfid_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_008e5ce0
// Address:   0x008e5ce0–0x008e5df3  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-08-04 (WQ8R-H)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Prefer: reconstructed-exact/Client_UI_CraftHost_BindObjectByTfid_Inferred.cpp
// Reject: Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow_008e5ce0
// =============================================================================

/*
 * Behavioral notes (decompiler-faithful + sealed ABI):
 * - stdcall RET 0x0C: (host*, coidLo, coidHi).
 * - Invalid TFID (lo & hi == 0xFFFFFFFF) → thiscall FUN_008e5990(host, NULL).
 * - Resolve via InventoryGrid_FindItemByCoid on vehicle cargo and/or locker
 *   (locker gated by DAT_00d1b644+0xf5); skip broken (obj+0x17c bit 19).
 * - Fallback: scan character equip TFID table @ +0x5a0 (count FUN_00522000),
 *   then CVOGReaction_ResolveObjectTarget(1, lo, hi).
 * - On non-null object → FUN_008e5990(host, obj) binds craft host selection.
 * - No network; selection bind only.
 */

// Full readable reconstruction:
//   Client_UI_CraftHost_BindObjectByTfid_Inferred.cpp
