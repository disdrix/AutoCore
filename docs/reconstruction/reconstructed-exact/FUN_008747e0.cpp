// =============================================================================
// FUN_008747e0
// -----------------------------------------------------------------------------
// Stable ID: aa_008747e0
// Address:   0x008747e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008747e0 @ 0x008747e0
// Stable ID: aa_008747e0
// Embedded strings (evidence for future rename):
//   - "i_d_arena/i_d_arena_prefs_wnd_label_rank_minimum.xml"
//   - "%s\'s Arena"
//   - "i_d_arena/i_d_arena_prefs_btn_close.xml"
//   - "i_d_arena/i_d_arena_prefs_mini_wnd_bg_texture.xml"
//   - "i_d_arena/i_d_arena_prefs_mini_wnd_label_status.xml"
//   - "i_d_arena/i_d_arena_prefs_mini_btn_cancel.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~1185 non-empty decompiler lines.
//  - Control keywords: if×110, return×1.
//  - Notable callees: FUN_007b5dd0×55, FUN_0079c860×33, FUN_00795f20×17, __RTDynamicCast×3, CDlgArenaPrefs_CreateChildWidgets, FUN_00792600, FUN_00864f20, sprintf.
//  - Strings: "i_d_arena/i_d_arena_prefs_wnd_label_rank_minimum.xml"; "%s\'s Arena"; "i_d_arena/i_d_arena_prefs_btn_close.xml"; "i_d_arena/i_d_arena_prefs_mini_wnd_bg_texture.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

Error: Decompilation failed
