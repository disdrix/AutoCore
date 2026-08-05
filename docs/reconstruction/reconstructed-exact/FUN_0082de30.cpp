// =============================================================================
// FUN_0082de30
// -----------------------------------------------------------------------------
// Stable ID: aa_0082de30
// Address:   0x0082de30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0082de30 @ 0x0082de30
// Stable ID: aa_0082de30
// Embedded strings (evidence for future rename):
//   - "i_m_qbs_equip_2d_btn_left.xml"
//   - "i_m_qbs_equip_2d_btn_middle.xml"
//   - "i_m_qbs_equip_2d_btn_right.xml"
//   - "i_m_qbs_char_2d_btn_left.xml"
//   - "i_m_qbs_char_2d_btn_middle.xml"
//   - "i_m_qbs_char_2d_btn_right.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~67 non-empty decompiler lines.
//  - Control keywords: if×5, switch×1, return×1.
//  - Notable callees: FUN_0082d2b0, FUN_0082de30.
//  - Strings: "i_m_qbs_equip_2d_btn_left.xml"; "i_m_qbs_equip_2d_btn_middle.xml"; "i_m_qbs_equip_2d_btn_right.xml"; "i_m_qbs_char_2d_btn_left.xml".
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

void __fastcall FUN_0082de30(int *param_1)



{

  int iVar1;

  

  if (param_1[0x130] != 0) {

    FUN_0082d2b0();

    if (param_1[0x14e] != 0) {

      (**(code **)(*param_1 + 0xbc))(param_1[0x14e]);

    }

    param_1[0x14e] = 0;

    switch(param_1[0x14f]) {

    case 0:

      iVar1 = (**(code **)(*param_1 + 0x444))("i_m_qbs_equip_2d_btn_left.xml",0,0x3e9,0xffffffff);

      param_1[0x150] = iVar1;

      iVar1 = (**(code **)(*param_1 + 0x444))("i_m_qbs_equip_2d_btn_middle.xml",0,0x3ea,0xffffffff);

      param_1[0x151] = iVar1;

      iVar1 = (**(code **)(*param_1 + 0x444))("i_m_qbs_equip_2d_btn_right.xml",0,0x3eb,0xffffffff);

      param_1[0x152] = iVar1;

      break;

    case 1:

      iVar1 = (**(code **)(*param_1 + 0x444))("i_m_qbs_char_2d_btn_left.xml",0,0x3e9,0xffffffff);

      param_1[0x150] = iVar1;

      iVar1 = (**(code **)(*param_1 + 0x444))("i_m_qbs_char_2d_btn_middle.xml",0,0x3ea,0xffffffff);

      param_1[0x151] = iVar1;

      iVar1 = (**(code **)(*param_1 + 0x444))("i_m_qbs_char_2d_btn_right.xml",0,0x3eb,0xffffffff);

      param_1[0x152] = iVar1;

      break;

    case 2:

      iVar1 = (**(code **)(*param_1 + 0x444))("i_m_qbs_craft_2d_btn_left.xml",0,0x3e9,0xffffffff);

      param_1[0x150] = iVar1;

      iVar1 = (**(code **)(*param_1 + 0x444))("i_m_qbs_craft_2d_btn_middle.xml",0,0x3ea,0xffffffff);

      param_1[0x151] = iVar1;

      iVar1 = (**(code **)(*param_1 + 0x444))("i_m_qbs_craft_2d_btn_right.xml",0,0x3eb,0xffffffff);

      param_1[0x152] = iVar1;

      break;

    case 3:

      iVar1 = (**(code **)(*param_1 + 0x444))("i_m_qbs_quest_2d_btn_left.xml",0,0x3e9,0xffffffff);

      param_1[0x150] = iVar1;

      iVar1 = (**(code **)(*param_1 + 0x444))("i_m_qbs_quest_2d_btn_middle.xml",0,0x3ea,0xffffffff);

      param_1[0x151] = iVar1;

      iVar1 = (**(code **)(*param_1 + 0x444))("i_m_qbs_quest_2d_btn_right.xml",0,0x3eb,0xffffffff);

      param_1[0x152] = iVar1;

      break;

    case 4:

      iVar1 = (**(code **)(*param_1 + 0x444))("i_m_qbs_esc_2d_btn_left.xml",0,0x3e9,0xffffffff);

      param_1[0x150] = iVar1;

      iVar1 = (**(code **)(*param_1 + 0x444))("i_m_qbs_esc_2d_btn_middle.xml",0,0x3ea,0xffffffff);

      param_1[0x151] = iVar1;

      iVar1 = (**(code **)(*param_1 + 0x444))("i_m_qbs_esc_2d_btn_right.xml",0,0x3eb,0xffffffff);

      param_1[0x152] = iVar1;

      break;

    default:

      param_1[0x150] = 0;

      param_1[0x151] = 0;

      param_1[0x152] = 0;

    }

    if ((int *)param_1[0x150] != (int *)0x0) {

      (**(code **)(*(int *)param_1[0x150] + 0x3b4))(0);

    }

    if ((int *)param_1[0x151] != (int *)0x0) {

      (**(code **)(*(int *)param_1[0x151] + 0x3b4))(0);

    }

    if ((int *)param_1[0x152] != (int *)0x0) {

      (**(code **)(*(int *)param_1[0x152] + 0x3b4))(0);

    }

  }

  return;

}
