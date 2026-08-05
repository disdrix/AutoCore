// =============================================================================
// Named_CalleeOf_Drive_SIZE_VEHICLES_008509e0
// -----------------------------------------------------------------------------
// Stable ID: aa_008509e0
// Callee of Drive_SIZE_VEHICLES
// Address:   0x008509e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_SIZE_VEHICLES: drive/input helper. Evidence string: "i_d_map_2d_icon_spot.dds". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "i_d_map_2d_icon_spot.dds"
//   - "i_d_map_2d_icon_circle.dds"
//   - "i_d_way_2d_icon_target.dds"
//   - "i_d_way_2d_icon_convoy.dds"
//   - "i_d_map_2d_icon_garage.dds"
//   - "i_d_map_2d_icon_mail.dds"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_007b1b70×22, FUN_0084ffc0, FUN_008509e0.
//  - Strings: "i_d_map_2d_icon_spot.dds"; "i_d_map_2d_icon_circle.dds"; "i_d_way_2d_icon_target.dds"; "i_d_way_2d_icon_convoy.dds".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Drive_SIZE_VEHICLES
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Drive_SIZE_VEHICLES_008509e0(uint32_t /* width from decompiler */ param_1)



{

  int unaff_EDI;

  

  FUN_0084ffc0();

  FUN_007b1b70(param_1);

  FUN_007b1b70("i_d_map_2d_icon_spot.dds");

  FUN_007b1b70("i_d_map_2d_icon_circle.dds");

  FUN_007b1b70("i_d_way_2d_icon_target.dds");

  FUN_007b1b70("i_d_way_2d_icon_convoy.dds");

  FUN_007b1b70("i_d_map_2d_icon_spot.dds");

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x5bc) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x5c0) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x5c4) = 0;

  FUN_007b1b70("i_d_map_2d_icon_garage.dds");

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x5cc) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x5d0) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x5d4) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x5d8) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x5dc) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x5e4) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x5f4) = 0;

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
