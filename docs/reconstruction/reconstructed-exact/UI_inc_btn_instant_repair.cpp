// =============================================================================
// UI_inc_btn_instant_repair
// -----------------------------------------------------------------------------
// Stable ID: aa_00830960
// Address:   0x00830960  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_inc_btn_instant_repair @ 0x00830960
// Stable ID: aa_00830960
// Embedded strings (evidence for future rename):
//   - "i_m_inc_2d_btn_instant_repair.xml"
//   - "i_m_inc_2d_btn_map_transfer.xml"
//   - "i_m_inc_2d_btn_repair_station.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0082d2b0, UI_inc_btn_instant_repair.
//  - Strings: "i_m_inc_2d_btn_instant_repair.xml"; "i_m_inc_2d_btn_map_transfer.xml"; "i_m_inc_2d_btn_repair_station.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_m_inc_2d_btn_instant_repair.xml"
 * Domain alias of FUN_00830960 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall UI_inc_btn_instant_repair(int *param_1)



{

  int iVar1;

  

  if (param_1[0x130] != 0) {

    FUN_0082d2b0();

    iVar1 = (**(code **)(*param_1 + 0x444))

                      ("i_m_inc_2d_btn_instant_repair.xml",0,0x11173,0xffffffff);

    param_1[0x151] = iVar1;

    iVar1 = (**(code **)(*param_1 + 0x444))("i_m_inc_2d_btn_map_transfer.xml",0,0x11172,0xffffffff);

    param_1[0x150] = iVar1;

    iVar1 = (**(code **)(*param_1 + 0x444))

                      ("i_m_inc_2d_btn_repair_station.xml",0,0x11171,0xffffffff);

    param_1[0x14f] = iVar1;

  }

  return;

}
