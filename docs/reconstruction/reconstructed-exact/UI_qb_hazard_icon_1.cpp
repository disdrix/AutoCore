// =============================================================================
// UI_qb_hazard_icon_1
// -----------------------------------------------------------------------------
// Stable ID: aa_00825300
// Address:   0x00825300  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_qb_hazard_icon_1 @ 0x00825300
// Stable ID: aa_00825300
// Embedded strings (evidence for future rename):
//   - "i_d_qb_2d_wnd_hazard_icon_1.dds"
//   - "i_d_qb_2d_wnd_hazard_icon_2.dds"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×2, for×1, return×1.
//  - Notable callees: UI_qb_hazard_icon_1.
//  - Strings: "i_d_qb_2d_wnd_hazard_icon_1.dds"; "i_d_qb_2d_wnd_hazard_icon_2.dds".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_qb_2d_wnd_hazard_icon_1.dds"
 * Domain alias of FUN_00825300 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void UI_qb_hazard_icon_1(char param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  int unaff_EBX;

  char *pcVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ auStack_104 [65];

  

  if (*(int *)(unaff_EBX + 0x544) != 0) {

    (**(code **)(**(int **)(unaff_EBX + 0x544) + 0x58))();

    iVar2 = 8;

    pcVar3 = "i_d_qb_2d_wnd_hazard_icon_1.dds";

    puVar4 = auStack_104;

    if (param_1 == '\x01') {

      pcVar3 = "i_d_qb_2d_wnd_hazard_icon_2.dds";

    }

    for (; iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar4 = *(uint32_t /* width from decompiler */ *)pcVar3;

      pcVar3 = pcVar3 + 4;

      puVar4 = puVar4 + 1;

    }

    iVar2 = **(int **)(unaff_EBX + 0x544);

    uVar1 = (**(code **)(**(int **)(unaff_EBX + 0x544) + 0x2c8))(0);

    (**(code **)(iVar2 + 0x50))(auStack_104,uVar1);

    (**(code **)(**(int **)(unaff_EBX + 0x544) + 0x34c))();

  }

  return;

}
