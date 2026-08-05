// =============================================================================
// Skill_sc_btn_ai_distance_1
// -----------------------------------------------------------------------------
// Stable ID: aa_0088aac0
// Address:   0x0088aac0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Skill_sc_btn_ai_distance_1 @ 0x0088aac0
// Stable ID: aa_0088aac0
// Embedded strings (evidence for future rename):
//   - "i_d_sc_2d_wnd_frame.xml"
//   - "i_d_sc_2d_btn_ai_state_1.xml"
//   - "i_d_sc_2d_btn_ai_state_2.xml"
//   - "i_d_sc_2d_btn_ai_state_3.xml"
//   - "i_d_sc_2d_btn_ai_distance_1.xml"
//   - "i_d_sc_2d_btn_ai_distance_2.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: do×2, if×2, while×2, return×1.
//  - Notable callees: FUN_00792600, Skill_sc_btn_ai_distance_1.
//  - Strings: "i_d_sc_2d_wnd_frame.xml"; "i_d_sc_2d_btn_ai_state_1.xml"; "i_d_sc_2d_btn_ai_state_2.xml"; "i_d_sc_2d_btn_ai_state_3.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_sc_2d_btn_ai_distance_1.xml"
 * Domain alias of FUN_0088aac0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Skill_sc_btn_ai_distance_1(int *param_1)



{

  int iVar1;

  int *piVar2;

  

  FUN_00792600();

  (**(code **)(*param_1 + 0x404))(param_1 + 0x14f,"i_d_sc_2d_wnd_frame.xml",0xffffffff);

  piVar2 = param_1 + 0x150;

  (**(code **)(*param_1 + 0x40c))(piVar2,"i_d_sc_2d_btn_ai_state_1.xml",0x9c41,0x9c42);

  (**(code **)(*param_1 + 0x40c))(param_1 + 0x151,"i_d_sc_2d_btn_ai_state_2.xml",0x9c41,0x9c43);

  (**(code **)(*param_1 + 0x40c))(param_1 + 0x152,"i_d_sc_2d_btn_ai_state_3.xml",0x9c41,0x9c44);

  iVar1 = 3;

  do {

    if (*piVar2 != 0) {

      (**(code **)(*(int *)*piVar2 + 0x3b4))(1);

    }

    piVar2 = piVar2 + 1;

    iVar1 = iVar1 + -1;

  } while (iVar1 != 0);

  piVar2 = param_1 + 0x153;

  (**(code **)(*param_1 + 0x408))(piVar2,"i_d_sc_2d_btn_ai_distance_1.xml",0x9c45);

  (**(code **)(*param_1 + 0x408))(param_1 + 0x154,"i_d_sc_2d_btn_ai_distance_2.xml",0x9c46);

  (**(code **)(*param_1 + 0x408))(param_1 + 0x155,"i_d_sc_2d_btn_ai_distance_3.xml",0x9c47);

  iVar1 = 3;

  do {

    if (*piVar2 != 0) {

      (**(code **)(*(int *)*piVar2 + 0x3b4))(1);

    }

    piVar2 = piVar2 + 1;

    iVar1 = iVar1 + -1;

  } while (iVar1 != 0);

  (**(code **)(*param_1 + 0x448))();

                    /* WARNING: Could not recover jumptable at 0x0088abe0. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(*param_1 + 0x34c))();

  return;

}
