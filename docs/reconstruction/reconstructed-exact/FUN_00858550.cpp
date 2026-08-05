// =============================================================================
// FUN_00858550
// -----------------------------------------------------------------------------
// Stable ID: aa_00858550
// Address:   0x00858550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00858550 @ 0x00858550
// Stable ID: aa_00858550
// Embedded strings (evidence for future rename):
//   - "i_d_map_2d_icon_circle.dds"
//   - "i_d_way_2d_icon_target.dds"
//   - "i_d_way_2d_icon_convoy.dds"
//   - "i_d_map_2d_icon_spot.dds"
//   - "i_d_map_2d_icon_garage.dds"
//   - "i_d_map_2d_icon_mail.dds"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_007b1b70×21, FUN_00857ca0, FUN_00858550.
//  - Strings: "i_d_map_2d_icon_circle.dds"; "i_d_way_2d_icon_target.dds"; "i_d_way_2d_icon_convoy.dds"; "i_d_map_2d_icon_spot.dds".
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

void FUN_00858550(uint32_t /* width from decompiler */ param_1)



{

  int unaff_EDI;

  

  FUN_00857ca0(unaff_EDI);

  FUN_007b1b70(param_1);

  FUN_007b1b70("i_d_map_2d_icon_circle.dds");

  FUN_007b1b70("i_d_way_2d_icon_target.dds");

  FUN_007b1b70("i_d_way_2d_icon_convoy.dds");

  FUN_007b1b70("i_d_map_2d_icon_spot.dds");

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x5e0) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x5e4) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x5e8) = 0;

  FUN_007b1b70("i_d_map_2d_icon_garage.dds");

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x5f0) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x5f4) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x5f8) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x5fc) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x600) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x608) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x618) = 0;

  FUN_007b1b70("i_d_map_2d_icon_circle.dds");

  FUN_007b1b70("i_d_map_2d_icon_circle.dds");

  FUN_007b1b70("i_d_map_2d_icon_circle.dds");

  FUN_007b1b70("i_d_map_2d_icon_mail.dds");

  FUN_007b1b70("i_d_map_2d_icon_auction.dds");

  FUN_007b1b70("i_d_way_2d_icon_static.dds");

  FUN_007b1b70("i_d_way_2d_icon_convoy.dds");

  FUN_007b1b70("i_d_way_2d_icon_target.dds");

  FUN_007b1b70("i_d_map_2d_icon_outpost.dds");

  FUN_007b1b70("i_d_map_2d_icon_outpost.dds");

  FUN_007b1b70("i_d_map_2d_icon_outpost.dds");

  FUN_007b1b70("i_d_map_2d_icon_obelisk.dds");

  FUN_007b1b70("i_d_map_2d_icon_obelisk.dds");

  FUN_007b1b70("i_d_map_2d_icon_obelisk.dds");

  FUN_007b1b70("i_d_map_2d_icon_all.dds");

  return;

}
