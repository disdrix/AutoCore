// =============================================================================
// UI_macro_btn_macro_macro_number
// -----------------------------------------------------------------------------
// Stable ID: aa_0082b280
// Address:   0x0082b280  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_macro_btn_macro_macro_number @ 0x0082b280
// Stable ID: aa_0082b280
// Embedded strings (evidence for future rename):
//   - "i_d_macro_2d_btn_macro_wnd_label_macro.xml"
//   - "i_d_macro_2d_btn_macro_wnd_macro_number.xml"
//   - "i_d_macro_2d_btn_macro_btn_macro.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00792600, UI_macro_btn_macro_macro_number.
//  - Strings: "i_d_macro_2d_btn_macro_wnd_label_macro.xml"; "i_d_macro_2d_btn_macro_wnd_macro_number.xml"; "i_d_macro_2d_btn_macro_btn_macro.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_macro_2d_btn_macro_wnd_macro_number.xml"
 * Domain alias of FUN_0082b280 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall UI_macro_btn_macro_macro_number(int *param_1)



{

  int *piVar1;

  

  FUN_00792600();

  (**(code **)(*param_1 + 0x404))

            (param_1 + 0x14a,"i_d_macro_2d_btn_macro_wnd_label_macro.xml",0xea61);

  (**(code **)(*param_1 + 0x404))

            (param_1 + 0x14b,"i_d_macro_2d_btn_macro_wnd_macro_number.xml",0xea61);

  (**(code **)(*param_1 + 0x408))(param_1 + 0x149,"i_d_macro_2d_btn_macro_btn_macro.xml",60000);

  piVar1 = (int *)(**(code **)(*(int *)param_1[0x149] + 0x164))(0);

  param_1[0x147] = *piVar1;

                    /* WARNING: Could not recover jumptable at 0x0082b2f4. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(*param_1 + 0x34c))();

  return;

}
