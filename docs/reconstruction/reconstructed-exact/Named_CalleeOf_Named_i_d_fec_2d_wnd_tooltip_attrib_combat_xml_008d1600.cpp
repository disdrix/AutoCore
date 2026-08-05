// =============================================================================
// Named_CalleeOf_Named_i_d_fec_2d_wnd_tooltip_attrib_combat_xml_008d1600
// -----------------------------------------------------------------------------
// Stable ID: aa_008d1600
// Callee of Named_i_d_fec_2d_wnd_tooltip_attrib_combat_xml
// Address:   0x008d1600  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_i_d_fec_2d_wnd_tooltip_attrib_combat_xml: combat/reward helper. Evidence string: "Biomek". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Human"
//   - "Biomek"
//   - "Mutant"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×9, goto×4, return×2.
//  - Notable callees: FUN_008cf8a0, FUN_008d1600.
//  - Strings: "Human"; "Biomek"; "Mutant".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_i_d_fec_2d_wnd_tooltip_attrib_combat_xml
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

void __fastcall Named_CalleeOf_Named_i_d_fec_2d_wnd_tooltip_attrib_combat_xml_008d1600(int param_1)



{

  int in_EAX;

  char *pcVar1;

  

  if (in_EAX == 0) {

    if (*(int *)(param_1 + 0x654) == 0) goto LAB_008d1686;

    pcVar1 = "Human";

LAB_008d1661:

    (**(code **)(**(int **)(param_1 + 0x654) + 0x1d8))(pcVar1,1,1);

  }

  else {

    if (in_EAX != 1) {

      if (in_EAX != 2) {

        return;

      }

      if (*(int *)(param_1 + 0x654) == 0) goto LAB_008d1686;

      pcVar1 = "Biomek";

      goto LAB_008d1661;

    }

    if (*(int *)(param_1 + 0x654) == 0) goto LAB_008d1686;

    (**(code **)(**(int **)(param_1 + 0x654) + 0x1d8))("Mutant",1,1);

  }

  if (*(int *)(param_1 + 0x654) != 0) {

    (**(code **)(**(int **)(param_1 + 0x654) + 0x34c))();

  }

LAB_008d1686:

  if ((*(int *)(param_1 + 0x658) != 0) &&

     ((**(code **)(**(int **)(param_1 + 0x658) + 0x1d8))

                (*(uint32_t /* width from decompiler */ *)(param_1 + 0x5f8 + in_EAX * 0x14),1,1),

     *(int *)(param_1 + 0x658) != 0)) {

    (**(code **)(**(int **)(param_1 + 0x658) + 0x34c))();

  }

  if (*(int *)(param_1 + 0x65c) != 0) {

    (**(code **)(**(int **)(param_1 + 0x65c) + 0x454))(0,1);

  }

  FUN_008cf8a0(param_1 + 0x660);

  return;

}
