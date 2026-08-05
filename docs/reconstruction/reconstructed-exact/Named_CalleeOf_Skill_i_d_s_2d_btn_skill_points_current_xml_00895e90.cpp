// =============================================================================
// Named_CalleeOf_Skill_i_d_s_2d_btn_skill_points_current_xml_00895e90
// -----------------------------------------------------------------------------
// Stable ID: aa_00895e90
// Callee of Skill_i_d_s_2d_btn_skill_points_current_xml
// Address:   0x00895e90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Skill_i_d_s_2d_btn_skill_points_current_xml: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_00895e90.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Skill_i_d_s_2d_btn_skill_points_current_xml
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

void Named_CalleeOf_Skill_i_d_s_2d_btn_skill_points_current_xml_00895e90(void)



{

  int iVar1;

  int *piVar2;

  int *unaff_EDI;

  

  piVar2 = unaff_EDI + 0x199;

  iVar1 = 0x36;

  do {

    if ((int *)*piVar2 != (int *)0x0) {

      (**(code **)(*(int *)*piVar2 + 0x440))();

      (**(code **)(*unaff_EDI + 0xbc))(*piVar2);

      *piVar2 = 0;

    }

    if (piVar2[-0x36] != 0) {

      (**(code **)(*unaff_EDI + 0xbc))(piVar2[-0x36]);

      piVar2[-0x36] = 0;

    }

    piVar2 = piVar2 + 1;

    iVar1 = iVar1 + -1;

  } while (iVar1 != 0);

  return;

}
