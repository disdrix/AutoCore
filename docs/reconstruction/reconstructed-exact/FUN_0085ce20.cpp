// =============================================================================
// FUN_0085ce20 / Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0085ce20
// Address:   0x0085ce20–0x0085d571  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-08-04 (WQ8R-H)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Prefer: reconstructed-exact/Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred.cpp
// Reject: Skill_You_do_not_possess_the_Tinkering_skill_to_work_o_0085ce20 (single-string scrape)
// =============================================================================

/*
 * Behavioral notes (decompiler-faithful + sealed ABI):
 * - Entry: EAX = item*, EBX = UI widget*, [ebp+8] = char strictMode; cdecl.
 * - Gate: DAT_00d1b6d8 (char), DAT_00d1b9a8 (cursor host), non-null item/widget.
 * - Mode DAT_00d1d900 (client+0x30c0 abs): 0=RE, 4=TinkerKit, 5=Gadget, else clear+cursor.
 * - RE: broken/craft-mat/eligible/recipe/stack/skill gates → product strings; else cursor ok.
 * - Gadget: FindItemByCoid(DAT_00d1d940/944) + RTTI CVOGGadget + FUN_00513400 codes 0..3/else.
 * - Tinker: FindItemByCoid(DAT_00d1d938/93c) + RTTI CVOGTinkeringKit + FUN_00513c10 codes.
 * - Epilogue: widget vtbl+0x308(text); cursorHost vtbl+0x120; widget vtbl+0x314(x,y).
 * - Does not mutate inventory or send C2S; local UI only.
 */

// Full readable reconstruction:
//   Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred.cpp
