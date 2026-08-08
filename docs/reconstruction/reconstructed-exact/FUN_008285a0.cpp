// =============================================================================
// FUN_008285a0  (machine-name twin)
// -----------------------------------------------------------------------------
// Stable ID: aa_008285a0
// Address:   0x008285a0  (autoassault.exe, image base 0x400000)
// Body:      0x008285a0 – 0x00828756 (0x1B7 bytes)
// Named plate: UI_QuickBarSlotButton_AssignItemObject_Inferred.cpp
// Dual: R11-026 2026-08-05
// =============================================================================
//
// This scaffold twin is retained under the Ghidra symbol. Authoritative clean
// reconstruction lives in:
//   reconstructed-exact/UI_QuickBarSlotButton_AssignItemObject_Inferred.cpp
//
// Sealed contract:
//   - item object* in EAX; button in ESI; plain ret; return 0|1
//   - payloadKind (+0x548) = 2; pSkill (+0x558) = 0
//   - item id = *( *(item+0xa8)+0x34 ) with cdq to +0x550/+0x554
//   - slot = page*10+column (+0x504/+0x500)
//   - CVOGCharacter_SetQuickBarItem then SetQuickBarSkill(-1) on DAT_00d1b6d8
//   - optional UI_QuickBarSlotButton_SetSelected(0) if bind changed && selected
//   - icon path via FUN_0085d970(item, pathBuf) — not GiveItemByCbid
//   - contrast id-based twin AssignItem @ 0x008283a0
//
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
